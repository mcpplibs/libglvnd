// libEGL, exercised through the module.
//
// This file includes <EGL/egl.h> for the EGL_* CONSTANTS — they are macros and
// no module can export them — but every FUNCTION and TYPE it uses comes from
// `import khronos.egl;`. If an entry point were missing from the export list this would
// not link; if the module named something upstream does not, it would not
// compile.
//
// ─────────────────────────────────────────────────────────────────────────
// EVERY ASSERTION HERE HOLDS WITH ZERO VENDORS INSTALLED, and that constraint
// is the whole design of this file.
//
// libEGL is a DISPATCH: without a vendor driver it can answer questions about
// itself and nothing else. An earlier version of this test asserted that
// `eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS)` lists an `EGL_EXT_`
// extension, which passed on a developer machine and failed on a clean runner
// — because upstream returns the empty string outright when no vendor is
// found:
//
//     if (glvnd_list_is_empty(__eglLoadVendors())) {
//         return "";
//     }                                        // libegl.c:928
//
// That assertion was measuring whether the MACHINE had a GPU driver, not
// whether this package built libEGL correctly. Anything vendor-dependent below
// is reported rather than asserted, or asserted only once its precondition is
// visibly met.
#ifdef __linux__

#include <EGL/egl.h>   // the EGL_* macros only

#include <cstdio>
#include <cstdlib>
#include <cstring>

import khronos.egl;

namespace {

int failures = 0;

void check(bool ok, const char *what)
{
    std::printf("%-58s %s\n", what, ok ? "ok" : "FAILED");
    if (!ok) ++failures;
}

} // namespace

int main()
{
    // ── 1. The module carries the API ────────────────────────────────────
    // EGLDisplay, EGLint, eglQueryString … all arrive through `import khronos.egl;`.
    // Reaching this line means the export list covers what the file uses.
    EGLDisplay none = EGL_NO_DISPLAY;
    check(none == EGL_NO_DISPLAY, "EGLDisplay and EGL_NO_DISPLAY agree");

    // ── 2. It is GLVND's libEGL, and it is this build ────────────────────
    // EGL_VERSION on EGL_NO_DISPLAY is answered by libglvnd itself, before any
    // vendor is consulted — upstream returns a literal `"1.5 libglvnd"`. So it
    // is both a liveness check and an IDENTITY check: a different libEGL.so.1
    // (the ecosystem payload's, the host's) would answer differently or not at
    // all. Same job as the dladdr assertion in compat.libdrm's test, and it
    // matters for the same reason — soname reuse means only one libEGL.so.1 is
    // ever mapped and nothing warns about the other.
    const char *version = eglQueryString(EGL_NO_DISPLAY, EGL_VERSION);
    check(version != nullptr && std::strcmp(version, "1.5 libglvnd") == 0,
          "eglQueryString(EGL_NO_DISPLAY, EGL_VERSION) is libglvnd's");
    std::printf("   EGL_VERSION: %s\n", version ? version : "(null)");

    // ── 3. Vendor enumeration runs, whether or not it finds anything ─────
    // Non-null is the assertion: it means __eglLoadVendors() completed. The
    // CONTENT is a property of the machine — empty when no vendor was found.
    const char *client_exts = eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS);
    check(client_exts != nullptr,
          "eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS) answers");

    // ── 4. The error path works ──────────────────────────────────────────
    // EGL_VENDOR without a display is invalid, and libglvnd must report
    // EGL_BAD_DISPLAY rather than crash or silently answer. This exercises
    // __eglReportError and the thread-local error state — a real chunk of the
    // library, and it needs no driver.
    const char *bad = eglQueryString(EGL_NO_DISPLAY, EGL_VENDOR);
    check(bad == nullptr, "an invalid no-display query returns null");
    check(eglGetError() == EGL_BAD_DISPLAY,
          "…and leaves EGL_BAD_DISPLAY in the thread's error state");

    // ── 5. eglGetProcAddress reaches GLdispatch ──────────────────────────
    // Resolving a CORE entry point exercises the path from libEGL into
    // libGLdispatch; if the two were not linked this returns null.
    check(eglGetProcAddress("eglInitialize") != nullptr,
          "eglGetProcAddress(\"eglInitialize\") resolves");
    check(eglGetProcAddress("eglNoSuchFunctionEXT") == nullptr,
          "…and a name that does not exist resolves to null");

    // ── 6. What the environment supplies, reported ───────────────────────
    // The package compiles in an EMPTY DEFAULT_EGL_VENDOR_CONFIG_DIRS on
    // purpose, so a vendor is only ever found through the environment, and
    // `xim:mesa` is what declares it (xim-pkgindex#713). None of this is
    // asserted: a runner with no GPU stack is not a defect in this package.
    // But when a vendor IS present, the extension string must look like one —
    // that check is attributable either way.
    std::puts("");
    const char *dirs = std::getenv("__EGL_VENDOR_LIBRARY_DIRS");
    std::printf("   __EGL_VENDOR_LIBRARY_DIRS = %s\n",
                dirs ? dirs : "(unset — the ecosystem declares it)");

    if (client_exts != nullptr && client_exts[0] != '\0') {
        std::printf("   client extensions: %.90s%s\n",
                    client_exts, std::strlen(client_exts) > 90 ? "…" : "");
        check(std::strstr(client_exts, "EGL_EXT_client_extensions") != nullptr,
              "a vendor was found, so the client extension list is populated");
    } else {
        std::puts("   client extensions: (none — no vendor driver on this "
                  "machine; the dispatch itself is fine)");
    }

    std::printf("\n%d check(s) failed\n", failures);
    return failures == 0 ? 0 : 1;
}

#else

int main() { return 0; }

#endif
