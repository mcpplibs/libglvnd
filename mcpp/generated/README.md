# Generated dispatch code

Produced by upstream's generators from the Khronos XML registries in
`upstream/src/generate/xml/`. **Do not edit.** To regenerate:

```bash
cd upstream/src/generate
python3 gen_gldispatch_mapi.py gldispatch xml/gl.xml xml/gl_other.xml \
    > ../../../mcpp/generated/glapi_mapi_tmp.h
python3 gen_egl_dispatch.py header xml/egl.xml > ../../../mcpp/generated/g_egldispatchstubs.h
python3 gen_egl_dispatch.py source xml/egl.xml > ../../../mcpp/generated/g_egldispatchstubs.c
```

CI does exactly that and diffs the result, so these files cannot drift from the
registries or from upstream's generators.

## Why they are checked in

They are deterministic from a pinned `gl.xml` / `egl.xml`, so generating them
during the build would buy nothing and cost two things:

- **A Python dependency in every consumer's build.** The point of this fork is
  that `mcpp build` is the whole toolchain.
- **A race.** A dependency's `build.mcpp` actions are not ordered before that
  package's own compiles (mcpp-community/mcpp#534), and
  `glapi_mapi_tmp.h` is included by `mapi_tmp.h` at compile time.

`glapi_mapi_tmp.h` is large (91k lines) because it is one entry per GL function
across every version and extension — that is what a vendor-neutral dispatch
table is.

## What is NOT generated here

The tables for `libOpenGL`, `libGLESv1`, `libGLESv2` and `libGL`/`libGLX`.
Nothing in this index builds those libraries yet; adding one means adding its
table here and a member for it.
