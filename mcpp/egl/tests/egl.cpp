// libEGL, exercised through the module.
//
// This file includes <EGL/egl.h> for the EGL_* CONSTANTS — they are macros and
// no module can export them — but every FUNCTION and TYPE it uses comes from
// `import egl;`. If an entry point were missing from the export list this would
// not link; if the module named something upstream does not, it would not
// compile.
//
// What it proves beyond "the symbols exist":
//
//   * eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS) makes the dispatch layer
//     enumerate vendors. It needs no display and no GPU, and it is the
//     cheapest call that actually runs libEGL's initialisation path.
//   * eglGetProcAddress returns a real pointer for a core entry point, which
//     goes through GLdispatch — so the two libraries are wired to each other,
//     not merely both present.

#ifdef __linux__

#include <EGL/egl.h>   // the EGL_* macros only

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

import egl;

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
    // EGLDisplay, EGLint, eglQueryString … all arrive through `import egl;`.
    EGLDisplay none = EGL_NO_DISPLAY;
    check(none == EGL_NO_DISPLAY, "EGLDisplay and EGL_NO_DISPLAY agree");

    // ── 2. The library initialises and enumerates vendors ────────────────
    const char *client_exts = eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS);
    check(client_exts != nullptr,
          "eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS) answers");
    if (client_exts != nullptr) {
        std::printf("   client extensions: %.70s%s\n",
                    client_exts, std::strlen(client_exts) > 70 ? "…" : "");
        // EGL_EXT_client_extensions is what makes the no-display query legal
        // in the first place; a dispatch that loaded no vendor still reports
        // it, so this is about the dispatch, not about the driver.
        check(std::strstr(client_exts, "EGL_EXT_") != nullptr,
              "it lists at least one EGL_EXT_ client extension");
    }

    // ── 3. eglGetProcAddress reaches GLdispatch ──────────────────────────
    // Resolving a CORE entry point exercises the path from libEGL into
    // libGLdispatch; if the two were not linked this returns null.
    void (*p)() = eglGetProcAddress("eglInitialize");
    check(p != nullptr, "eglGetProcAddress(\"eglInitialize\") resolves");

    // ── 4. The vendor search path is the ecosystem's, not the host's ─────
    // The package compiles in an EMPTY DEFAULT_EGL_VENDOR_CONFIG_DIRS on
    // purpose, so a vendor is only ever found through the environment. Report
    // it rather than assert: on a machine whose ecosystem predates the
    // discovery row there is nothing to find, and that is not this package's
    // defect.
    const char *dirs = std::getenv("__EGL_VENDOR_LIBRARY_DIRS");
    if (dirs != nullptr) {
        std::printf("   __EGL_VENDOR_LIBRARY_DIRS = %s\n", dirs);
    } else {
        std::puts("   __EGL_VENDOR_LIBRARY_DIRS unset — no vendor will be found; "
                  "the ecosystem declares it (xim-pkgindex#713)");
    }

    std::printf("\n%d check(s) failed\n", failures);
    return failures == 0 ? 0 : 1;
}

#else

int main() { return 0; }

#endif
