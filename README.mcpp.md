# mcpplibs/libglvnd

[libglvnd](https://gitlab.freedesktop.org/glvnd/libglvnd) v1.7.0 with mcpp build
support. One package reaches
[mcpp-index](https://github.com/mcpplibs/mcpp-index):

| member | output | published as |
|---|---|---|
| `mcpp/egl` | `libEGL.so.1` + `import khronos.egl;` | `freedesktop.egl` |
| `mcpp/gldispatch` | `libGLdispatch.so.0` | internal — a path dependency of `mcpp/egl` |

```bash
mcpp build --workspace
```

`gldispatch` is a member rather than a second index entry on purpose. It is a
SONAME, and being the *one* dispatch point in a process is GLVND's whole reason
to exist; two index entries would let a consumer name both and resolve two
package instances, each building its own `libGLdispatch.so.0`. Soname reuse
means only one is ever mapped, so nothing would report the duplicate. It becomes
a published entry the day something other than libEGL needs it — `libGL` and
`libGLX` would.

## The module adds no API

`import khronos.egl;` replaces `#include <EGL/egl.h>` and changes nothing else — every
exported name is upstream's, spelled upstream's way, so code written against
the C header ports by swapping one line. The export list is **generated from
the header**, so a version bump cannot quietly drop a name.

Unlike wayland's, this module needed no forwarders: EGL's entry points are
declared `EGLAPI … EGLAPIENTRY` with external linkage, not `static inline`, so
`using ::name;` reaches all of them.

The `EGL_*` **constants** are macros, and no module can export a macro. Include
`<EGL/egl.h>` next to the import when you need `EGL_NO_DISPLAY`; it is the same
header the module was generated from. Extension tokens like
`EGL_PLATFORM_GBM_KHR` live in `<EGL/eglext.h>` for the same reason —
`eglGetPlatformDisplay` itself is EGL 1.5 core and IS exported.

## Where the vendors come from

libglvnd is a *dispatch*: `libEGL.so.1` dlopens the real driver named by a JSON
file. Upstream compiles in `<prefix>/share/glvnd/egl_vendor.d` as the search
path, which is right on a distribution and wrong the moment the payload is
relocated — the same shape as libgbm's compiled-in backend path.

This fork compiles in an **empty** default on purpose. The mechanism to supply
the real one is libglvnd's own `__EGL_VENDOR_LIBRARY_DIRS`, and the job belongs
to the environment: `xim:mesa` declares it through the graphics discovery layer
(openxlings/xim-pkgindex#713) and mcpp carries subos declarations into the
processes it launches. An empty fallback means a missing declaration shows up as
"no vendor found" instead of as silently loading the *host's* driver into a
sandboxed process.

## Layout

```
upstream/            libglvnd v1.7.0, verbatim — never touched
mcpp/
  generated/         the dispatch tables, checked in — see its README
  gldispatch/        libGLdispatch, + build.mcpp for the per-arch stubs
  egl/               libEGL + the egl module, + its test
mcpp.toml            the workspace root
```

**No generator runs at build time.** Upstream drives ~1000 lines of Python over
a 2.7 MB `gl.xml`; that output is deterministic from a pinned registry, so it is
checked in and CI regenerates and diffs it. `mcpp build` is the whole toolchain.

**The per-architecture choice lives in `build.mcpp`, not in the manifest.**
GLdispatch's entry stubs are per-arch *and* per-thread-storage-model, and the
files carry no guards of their own — upstream picks them with
`gl_dispatch_type`. `mcpp/gldispatch/build.mcpp` makes the same choice from
`mcpp::target_arch()`, so aarch64 and ppc64 work by construction instead of
needing an edit.

## Not built here

`libGL`, `libGLX`, `libOpenGL`, `libGLESv1`, `libGLESv2`. Nothing in the index
needs them yet; each is a member plus its dispatch table in `mcpp/generated/`.
