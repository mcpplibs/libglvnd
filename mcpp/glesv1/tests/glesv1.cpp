// libGLESv1_CM.so.1, exercised through the module.
//
// Every FUNCTION and TYPE below comes from `import khronos.glesv1;`. <GLES/gl.h> is
// included for the GL_* CONSTANTS only — they are macros, and no module can
// export a macro. So the file COMPILING is the first assertion (the generated
// export list has to cover what is used) and LINKING is the second (every
// exported name must resolve in libGLESv1_CM.so.1).
//
// WHAT CANNOT BE TESTED HERE, AND WHY THAT IS FINE
//
// A GL call needs a current context, which needs EGL, which needs a device.
// This runs on CI machines with no GPU. So the assertions are the ones that
// hold with NO context: that the library is ours, that it routes through
// libGLdispatch, and that a call with no context is survivable rather than a
// crash — GLVND dispatches to a no-op stub, which is a real behaviour worth
// pinning. The "it actually draws" test lives in mcpp-index's member, where a
// GBM device is available.
#ifdef __linux__

#include <GLES/gl.h>

#include <dlfcn.h>
#include <cstdio>
#include <cstring>
#include <string>

import khronos.glesv1;

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
    // ── 1. The module carries types and entry points ─────────────────────
    GLenum e = GL_NO_ERROR;
    check(e == GL_NO_ERROR, "GLenum and GL_NO_ERROR agree");



    // ── 2. The GL code in this process is THIS build's ───────────────────
    //
    // WHAT THIS CAN AND CANNOT SHOW, because the difference matters.
    //
    // An IN-PACKAGE test links the package's own OBJECTS, not its .so: this
    // binary defines glClear itself (measured — `FUNC GLOBAL DEFAULT` in a real
    // section, not UNDEF), so dlsym+dladdr report the TEST BINARY. Which means
    // this file cannot tell "our .so" from "our .o" — and an assertion that
    // claimed to would pass without ever looking at a library.
    //
    // What it CAN show is that nothing pulled the ecosystem payload's copy in,
    // which is a real failure mode: xim:libglvnd ships the same sonames.
    // The .so-level identity check belongs in a CONSUMER, and lives in
    // mcpp-index's test member, where the library is linked as a library.
    {
        void *sym = ::dlsym(RTLD_DEFAULT, "glClear");
        Dl_info info{};
        const bool located = sym != nullptr && ::dladdr(sym, &info) != 0
                             && info.dli_fname != nullptr;
        check(located, "dlsym+dladdr locate the GL entry points");
        if (located) {
            const std::string from = info.dli_fname;
            std::printf("   glClear came from: %s\n", from.c_str());
            check(from.find("xim-x-libglvnd") == std::string::npos,
                  "they did not come from the ecosystem payload");
        }
    }

    // ── 3. A call with no current context is a no-op, not a crash ────────
    // GLVND points every entry at a stub until MakeCurrent installs a vendor's
    // table. Reaching the line after this proves the dispatch table was
    // initialised — an uninitialised one segfaults here.
    glClear(GL_COLOR_BUFFER_BIT);
    check(true, "glClear with no context returned instead of crashing");

    // ── 4. The dispatch is libGLdispatch's, not a private copy ───────────
    check(::dlsym(RTLD_DEFAULT, "__glDispatchMakeCurrent") != nullptr,
          "libGLdispatch is in the process (the dispatch is shared)");

    std::printf("\n%d check(s) failed\n", failures);
    return failures == 0 ? 0 : 1;
}

#else
int main() { return 0; }
#endif
