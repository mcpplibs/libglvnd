// egl — libEGL, as a C++23 module.
//
// A module wrapper and nothing more: every name below is upstream's, spelled
// upstream's way. `import khronos.egl;` replaces `#include <EGL/egl.h>` and changes
// nothing else, so code written against the C header ports by swapping one
// line.
//
// GENERATED from upstream/include/EGL/egl.h, so a version bump cannot quietly
// drop a name. Unlike wayland's, this list needs no forwarders: EGL's entry
// points are declared EGLAPI/EGLAPIENTRY with external linkage, not
// `static inline`, so `using ::name;` reaches all of them.
//
// WHAT IS NOT HERE
//
// * The EGL_* CONSTANTS. They are macros, and a module cannot export a macro —
//   `export` names entities. `#include <EGL/egl.h>` alongside the import when
//   you need EGL_NO_DISPLAY or EGL_TRUE; it is the same header this module was
//   generated from, so nothing disagrees.
// * EXTENSIONS. `eglGetPlatformDisplay` is EGL 1.5 core and IS here, but the
//   platform tokens it takes (EGL_PLATFORM_GBM_KHR and friends) live in
//   <EGL/eglext.h> and are macros besides. A consumer doing GBM includes that
//   header for the token and calls the function through this module.
module;

#include <EGL/egl.h>

export module khronos.egl;

export {

// -- types --
using ::EGLAttrib;
using ::EGLBoolean;
using ::EGLClientBuffer;
using ::EGLConfig;
using ::EGLContext;
using ::EGLDisplay;
using ::EGLImage;
using ::EGLSurface;
using ::EGLSync;
using ::EGLTime;
using ::EGLenum;

// -- entry points --
using ::eglBindAPI;
using ::eglBindTexImage;
using ::eglChooseConfig;
using ::eglClientWaitSync;
using ::eglCopyBuffers;
using ::eglCreateContext;
using ::eglCreateImage;
using ::eglCreatePbufferFromClientBuffer;
using ::eglCreatePbufferSurface;
using ::eglCreatePixmapSurface;
using ::eglCreatePlatformPixmapSurface;
using ::eglCreatePlatformWindowSurface;
using ::eglCreateSync;
using ::eglCreateWindowSurface;
using ::eglDestroyContext;
using ::eglDestroyImage;
using ::eglDestroySurface;
using ::eglDestroySync;
using ::eglGetConfigAttrib;
using ::eglGetConfigs;
using ::eglGetCurrentContext;
using ::eglGetCurrentDisplay;
using ::eglGetCurrentSurface;
using ::eglGetDisplay;
using ::eglGetError;
using ::eglGetPlatformDisplay;
using ::eglGetProcAddress;
using ::eglGetSyncAttrib;
using ::eglInitialize;
using ::eglMakeCurrent;
using ::eglQueryAPI;
using ::eglQueryContext;
using ::eglQueryString;
using ::eglQuerySurface;
using ::eglReleaseTexImage;
using ::eglReleaseThread;
using ::eglSurfaceAttrib;
using ::eglSwapBuffers;
using ::eglSwapInterval;
using ::eglTerminate;
using ::eglWaitClient;
using ::eglWaitGL;
using ::eglWaitNative;
using ::eglWaitSync;
}
