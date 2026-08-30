#ifndef G_EGLDISPATCH_STUBS_H
#define G_EGLDISPATCH_STUBS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "glvnd/libeglabi.h"

enum {
    __EGL_DISPATCH_eglBindAPI,
    __EGL_DISPATCH_eglBindTexImage,
    __EGL_DISPATCH_eglChooseConfig,
    __EGL_DISPATCH_eglClientWaitSync,
    __EGL_DISPATCH_eglCopyBuffers,
    __EGL_DISPATCH_eglCreateContext,
    __EGL_DISPATCH_eglCreateImage,
    __EGL_DISPATCH_eglCreatePbufferFromClientBuffer,
    __EGL_DISPATCH_eglCreatePbufferSurface,
    __EGL_DISPATCH_eglCreatePixmapSurface,
    __EGL_DISPATCH_eglCreatePlatformPixmapSurface,
    __EGL_DISPATCH_eglCreatePlatformPixmapSurfaceEXT,
    __EGL_DISPATCH_eglCreatePlatformWindowSurface,
    __EGL_DISPATCH_eglCreatePlatformWindowSurfaceEXT,
    __EGL_DISPATCH_eglCreateSync,
    __EGL_DISPATCH_eglCreateWindowSurface,
    __EGL_DISPATCH_eglDebugMessageControlKHR,
    __EGL_DISPATCH_eglDestroyContext,
    __EGL_DISPATCH_eglDestroyImage,
    __EGL_DISPATCH_eglDestroySurface,
    __EGL_DISPATCH_eglDestroySync,
    __EGL_DISPATCH_eglGetConfigAttrib,
    __EGL_DISPATCH_eglGetConfigs,
    __EGL_DISPATCH_eglGetCurrentContext,
    __EGL_DISPATCH_eglGetCurrentDisplay,
    __EGL_DISPATCH_eglGetCurrentSurface,
    __EGL_DISPATCH_eglGetDisplay,
    __EGL_DISPATCH_eglGetError,
    __EGL_DISPATCH_eglGetPlatformDisplay,
    __EGL_DISPATCH_eglGetPlatformDisplayEXT,
    __EGL_DISPATCH_eglGetProcAddress,
    __EGL_DISPATCH_eglGetSyncAttrib,
    __EGL_DISPATCH_eglInitialize,
    __EGL_DISPATCH_eglLabelObjectKHR,
    __EGL_DISPATCH_eglMakeCurrent,
    __EGL_DISPATCH_eglQueryAPI,
    __EGL_DISPATCH_eglQueryContext,
    __EGL_DISPATCH_eglQueryDebugKHR,
    __EGL_DISPATCH_eglQueryDevicesEXT,
    __EGL_DISPATCH_eglQueryDisplayAttribEXT,
    __EGL_DISPATCH_eglQueryDisplayAttribKHR,
    __EGL_DISPATCH_eglQueryDisplayAttribNV,
    __EGL_DISPATCH_eglQueryString,
    __EGL_DISPATCH_eglQuerySurface,
    __EGL_DISPATCH_eglReleaseTexImage,
    __EGL_DISPATCH_eglReleaseThread,
    __EGL_DISPATCH_eglSurfaceAttrib,
    __EGL_DISPATCH_eglSwapBuffers,
    __EGL_DISPATCH_eglSwapInterval,
    __EGL_DISPATCH_eglTerminate,
    __EGL_DISPATCH_eglWaitClient,
    __EGL_DISPATCH_eglWaitGL,
    __EGL_DISPATCH_eglWaitNative,
    __EGL_DISPATCH_eglWaitSync,
    __EGL_DISPATCH_COUNT
};
EGLint EGLAPIENTRY eglDebugMessageControlKHR(EGLDEBUGPROCKHR callback, const EGLAttrib *attrib_list);
EGLDisplay EGLAPIENTRY eglGetPlatformDisplayEXT(EGLenum platform, void *native_display, const EGLint *attrib_list);
EGLint EGLAPIENTRY eglLabelObjectKHR(EGLDisplay display, EGLenum objectType, EGLObjectKHR object, EGLLabelKHR label);
EGLBoolean EGLAPIENTRY eglQueryDebugKHR(EGLint attribute, EGLAttrib *value);
EGLBoolean EGLAPIENTRY eglQueryDevicesEXT(EGLint max_devices, EGLDeviceEXT *devices, EGLint *num_devices);
EGLBoolean EGLAPIENTRY eglQueryDisplayAttribEXT(EGLDisplay dpy, EGLint attribute, EGLAttrib *value);
EGLBoolean EGLAPIENTRY eglQueryDisplayAttribKHR(EGLDisplay dpy, EGLint name, EGLAttrib *value);
EGLBoolean EGLAPIENTRY eglQueryDisplayAttribNV(EGLDisplay dpy, EGLint attribute, EGLAttrib *value);

#ifdef __cplusplus
}
#endif
#endif // G_EGLDISPATCH_STUBS_H
