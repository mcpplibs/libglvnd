#include "egldispatchstubs.h"
#include "g_egldispatchstubs.h"
#include <stddef.h>

PUBLIC EGLBoolean EGLAPIENTRY eglBindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglBindTexImage)(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglBindTexImage _ptr_eglBindTexImage = (_pfn_eglBindTexImage) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglBindTexImage);
    if(_ptr_eglBindTexImage != NULL) {
        _ret = _ptr_eglBindTexImage(dpy, surface, buffer);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglChooseConfig(EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglChooseConfig)(EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglChooseConfig _ptr_eglChooseConfig = (_pfn_eglChooseConfig) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglChooseConfig);
    if(_ptr_eglChooseConfig != NULL) {
        _ret = _ptr_eglChooseConfig(dpy, attrib_list, configs, config_size, num_config);
    }
    return _ret;
}
PUBLIC EGLint EGLAPIENTRY eglClientWaitSync(EGLDisplay dpy, EGLSync sync, EGLint flags, EGLTime timeout)
{
    typedef EGLint EGLAPIENTRY (* _pfn_eglClientWaitSync)(EGLDisplay dpy, EGLSync sync, EGLint flags, EGLTime timeout);
    EGLint _ret = 0;
    _pfn_eglClientWaitSync _ptr_eglClientWaitSync = (_pfn_eglClientWaitSync) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglClientWaitSync);
    if(_ptr_eglClientWaitSync != NULL) {
        _ret = _ptr_eglClientWaitSync(dpy, sync, flags, timeout);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglCopyBuffers(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglCopyBuffers)(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglCopyBuffers _ptr_eglCopyBuffers = (_pfn_eglCopyBuffers) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCopyBuffers);
    if(_ptr_eglCopyBuffers != NULL) {
        _ret = _ptr_eglCopyBuffers(dpy, surface, target);
    }
    return _ret;
}
PUBLIC EGLContext EGLAPIENTRY eglCreateContext(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list)
{
    typedef EGLContext EGLAPIENTRY (* _pfn_eglCreateContext)(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list);
    EGLContext _ret = EGL_NO_CONTEXT;
    _pfn_eglCreateContext _ptr_eglCreateContext = (_pfn_eglCreateContext) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreateContext);
    if(_ptr_eglCreateContext != NULL) {
        _ret = _ptr_eglCreateContext(dpy, config, share_context, attrib_list);
    }
    return _ret;
}
PUBLIC EGLImage EGLAPIENTRY eglCreateImage(EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLAttrib *attrib_list)
{
    typedef EGLImage EGLAPIENTRY (* _pfn_eglCreateImage)(EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLAttrib *attrib_list);
    EGLImage _ret = 0;
    _pfn_eglCreateImage _ptr_eglCreateImage = (_pfn_eglCreateImage) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreateImage);
    if(_ptr_eglCreateImage != NULL) {
        _ret = _ptr_eglCreateImage(dpy, ctx, target, buffer, attrib_list);
    }
    return _ret;
}
PUBLIC EGLSurface EGLAPIENTRY eglCreatePbufferFromClientBuffer(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint *attrib_list)
{
    typedef EGLSurface EGLAPIENTRY (* _pfn_eglCreatePbufferFromClientBuffer)(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint *attrib_list);
    EGLSurface _ret = EGL_NO_SURFACE;
    _pfn_eglCreatePbufferFromClientBuffer _ptr_eglCreatePbufferFromClientBuffer = (_pfn_eglCreatePbufferFromClientBuffer) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreatePbufferFromClientBuffer);
    if(_ptr_eglCreatePbufferFromClientBuffer != NULL) {
        _ret = _ptr_eglCreatePbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list);
    }
    return _ret;
}
PUBLIC EGLSurface EGLAPIENTRY eglCreatePbufferSurface(EGLDisplay dpy, EGLConfig config, const EGLint *attrib_list)
{
    typedef EGLSurface EGLAPIENTRY (* _pfn_eglCreatePbufferSurface)(EGLDisplay dpy, EGLConfig config, const EGLint *attrib_list);
    EGLSurface _ret = EGL_NO_SURFACE;
    _pfn_eglCreatePbufferSurface _ptr_eglCreatePbufferSurface = (_pfn_eglCreatePbufferSurface) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreatePbufferSurface);
    if(_ptr_eglCreatePbufferSurface != NULL) {
        _ret = _ptr_eglCreatePbufferSurface(dpy, config, attrib_list);
    }
    return _ret;
}
PUBLIC EGLSurface EGLAPIENTRY eglCreatePixmapSurface(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint *attrib_list)
{
    typedef EGLSurface EGLAPIENTRY (* _pfn_eglCreatePixmapSurface)(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint *attrib_list);
    EGLSurface _ret = EGL_NO_SURFACE;
    _pfn_eglCreatePixmapSurface _ptr_eglCreatePixmapSurface = (_pfn_eglCreatePixmapSurface) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreatePixmapSurface);
    if(_ptr_eglCreatePixmapSurface != NULL) {
        _ret = _ptr_eglCreatePixmapSurface(dpy, config, pixmap, attrib_list);
    }
    return _ret;
}
PUBLIC EGLSurface EGLAPIENTRY eglCreatePlatformPixmapSurface(EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLAttrib *attrib_list)
{
    typedef EGLSurface EGLAPIENTRY (* _pfn_eglCreatePlatformPixmapSurface)(EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLAttrib *attrib_list);
    EGLSurface _ret = EGL_NO_SURFACE;
    _pfn_eglCreatePlatformPixmapSurface _ptr_eglCreatePlatformPixmapSurface = (_pfn_eglCreatePlatformPixmapSurface) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreatePlatformPixmapSurface);
    if(_ptr_eglCreatePlatformPixmapSurface != NULL) {
        _ret = _ptr_eglCreatePlatformPixmapSurface(dpy, config, native_pixmap, attrib_list);
    }
    return _ret;
}
static EGLSurface EGLAPIENTRY eglCreatePlatformPixmapSurfaceEXT(EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLint *attrib_list)
{
    typedef EGLSurface EGLAPIENTRY (* _pfn_eglCreatePlatformPixmapSurfaceEXT)(EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLint *attrib_list);
    EGLSurface _ret = EGL_NO_SURFACE;
    _pfn_eglCreatePlatformPixmapSurfaceEXT _ptr_eglCreatePlatformPixmapSurfaceEXT = (_pfn_eglCreatePlatformPixmapSurfaceEXT) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreatePlatformPixmapSurfaceEXT);
    if(_ptr_eglCreatePlatformPixmapSurfaceEXT != NULL) {
        _ret = _ptr_eglCreatePlatformPixmapSurfaceEXT(dpy, config, native_pixmap, attrib_list);
    }
    return _ret;
}
PUBLIC EGLSurface EGLAPIENTRY eglCreatePlatformWindowSurface(EGLDisplay dpy, EGLConfig config, void *native_window, const EGLAttrib *attrib_list)
{
    typedef EGLSurface EGLAPIENTRY (* _pfn_eglCreatePlatformWindowSurface)(EGLDisplay dpy, EGLConfig config, void *native_window, const EGLAttrib *attrib_list);
    EGLSurface _ret = EGL_NO_SURFACE;
    _pfn_eglCreatePlatformWindowSurface _ptr_eglCreatePlatformWindowSurface = (_pfn_eglCreatePlatformWindowSurface) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreatePlatformWindowSurface);
    if(_ptr_eglCreatePlatformWindowSurface != NULL) {
        _ret = _ptr_eglCreatePlatformWindowSurface(dpy, config, native_window, attrib_list);
    }
    return _ret;
}
static EGLSurface EGLAPIENTRY eglCreatePlatformWindowSurfaceEXT(EGLDisplay dpy, EGLConfig config, void *native_window, const EGLint *attrib_list)
{
    typedef EGLSurface EGLAPIENTRY (* _pfn_eglCreatePlatformWindowSurfaceEXT)(EGLDisplay dpy, EGLConfig config, void *native_window, const EGLint *attrib_list);
    EGLSurface _ret = EGL_NO_SURFACE;
    _pfn_eglCreatePlatformWindowSurfaceEXT _ptr_eglCreatePlatformWindowSurfaceEXT = (_pfn_eglCreatePlatformWindowSurfaceEXT) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreatePlatformWindowSurfaceEXT);
    if(_ptr_eglCreatePlatformWindowSurfaceEXT != NULL) {
        _ret = _ptr_eglCreatePlatformWindowSurfaceEXT(dpy, config, native_window, attrib_list);
    }
    return _ret;
}
PUBLIC EGLSync EGLAPIENTRY eglCreateSync(EGLDisplay dpy, EGLenum type, const EGLAttrib *attrib_list)
{
    typedef EGLSync EGLAPIENTRY (* _pfn_eglCreateSync)(EGLDisplay dpy, EGLenum type, const EGLAttrib *attrib_list);
    EGLSync _ret = 0;
    _pfn_eglCreateSync _ptr_eglCreateSync = (_pfn_eglCreateSync) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreateSync);
    if(_ptr_eglCreateSync != NULL) {
        _ret = _ptr_eglCreateSync(dpy, type, attrib_list);
    }
    return _ret;
}
PUBLIC EGLSurface EGLAPIENTRY eglCreateWindowSurface(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list)
{
    typedef EGLSurface EGLAPIENTRY (* _pfn_eglCreateWindowSurface)(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list);
    EGLSurface _ret = EGL_NO_SURFACE;
    _pfn_eglCreateWindowSurface _ptr_eglCreateWindowSurface = (_pfn_eglCreateWindowSurface) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglCreateWindowSurface);
    if(_ptr_eglCreateWindowSurface != NULL) {
        _ret = _ptr_eglCreateWindowSurface(dpy, config, win, attrib_list);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglDestroyContext(EGLDisplay dpy, EGLContext ctx)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglDestroyContext)(EGLDisplay dpy, EGLContext ctx);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglDestroyContext _ptr_eglDestroyContext = (_pfn_eglDestroyContext) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglDestroyContext);
    if(_ptr_eglDestroyContext != NULL) {
        _ret = _ptr_eglDestroyContext(dpy, ctx);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglDestroyImage(EGLDisplay dpy, EGLImage image)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglDestroyImage)(EGLDisplay dpy, EGLImage image);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglDestroyImage _ptr_eglDestroyImage = (_pfn_eglDestroyImage) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglDestroyImage);
    if(_ptr_eglDestroyImage != NULL) {
        _ret = _ptr_eglDestroyImage(dpy, image);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglDestroySurface(EGLDisplay dpy, EGLSurface surface)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglDestroySurface)(EGLDisplay dpy, EGLSurface surface);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglDestroySurface _ptr_eglDestroySurface = (_pfn_eglDestroySurface) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglDestroySurface);
    if(_ptr_eglDestroySurface != NULL) {
        _ret = _ptr_eglDestroySurface(dpy, surface);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglDestroySync(EGLDisplay dpy, EGLSync sync)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglDestroySync)(EGLDisplay dpy, EGLSync sync);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglDestroySync _ptr_eglDestroySync = (_pfn_eglDestroySync) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglDestroySync);
    if(_ptr_eglDestroySync != NULL) {
        _ret = _ptr_eglDestroySync(dpy, sync);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglGetConfigAttrib(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglGetConfigAttrib)(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglGetConfigAttrib _ptr_eglGetConfigAttrib = (_pfn_eglGetConfigAttrib) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglGetConfigAttrib);
    if(_ptr_eglGetConfigAttrib != NULL) {
        _ret = _ptr_eglGetConfigAttrib(dpy, config, attribute, value);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglGetConfigs(EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglGetConfigs)(EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglGetConfigs _ptr_eglGetConfigs = (_pfn_eglGetConfigs) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglGetConfigs);
    if(_ptr_eglGetConfigs != NULL) {
        _ret = _ptr_eglGetConfigs(dpy, configs, config_size, num_config);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglGetSyncAttrib(EGLDisplay dpy, EGLSync sync, EGLint attribute, EGLAttrib *value)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglGetSyncAttrib)(EGLDisplay dpy, EGLSync sync, EGLint attribute, EGLAttrib *value);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglGetSyncAttrib _ptr_eglGetSyncAttrib = (_pfn_eglGetSyncAttrib) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglGetSyncAttrib);
    if(_ptr_eglGetSyncAttrib != NULL) {
        _ret = _ptr_eglGetSyncAttrib(dpy, sync, attribute, value);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglInitialize(EGLDisplay dpy, EGLint *major, EGLint *minor)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglInitialize)(EGLDisplay dpy, EGLint *major, EGLint *minor);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglInitialize _ptr_eglInitialize = (_pfn_eglInitialize) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglInitialize);
    if(_ptr_eglInitialize != NULL) {
        _ret = _ptr_eglInitialize(dpy, major, minor);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglQueryContext(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglQueryContext)(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglQueryContext _ptr_eglQueryContext = (_pfn_eglQueryContext) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglQueryContext);
    if(_ptr_eglQueryContext != NULL) {
        _ret = _ptr_eglQueryContext(dpy, ctx, attribute, value);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglQuerySurface(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglQuerySurface)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglQuerySurface _ptr_eglQuerySurface = (_pfn_eglQuerySurface) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglQuerySurface);
    if(_ptr_eglQuerySurface != NULL) {
        _ret = _ptr_eglQuerySurface(dpy, surface, attribute, value);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglReleaseTexImage)(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglReleaseTexImage _ptr_eglReleaseTexImage = (_pfn_eglReleaseTexImage) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglReleaseTexImage);
    if(_ptr_eglReleaseTexImage != NULL) {
        _ret = _ptr_eglReleaseTexImage(dpy, surface, buffer);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglSurfaceAttrib(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglSurfaceAttrib)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglSurfaceAttrib _ptr_eglSurfaceAttrib = (_pfn_eglSurfaceAttrib) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglSurfaceAttrib);
    if(_ptr_eglSurfaceAttrib != NULL) {
        _ret = _ptr_eglSurfaceAttrib(dpy, surface, attribute, value);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglSwapBuffers(EGLDisplay dpy, EGLSurface surface)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglSwapBuffers _ptr_eglSwapBuffers = (_pfn_eglSwapBuffers) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglSwapBuffers);
    if(_ptr_eglSwapBuffers != NULL) {
        _ret = _ptr_eglSwapBuffers(dpy, surface);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglSwapInterval(EGLDisplay dpy, EGLint interval)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglSwapInterval)(EGLDisplay dpy, EGLint interval);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglSwapInterval _ptr_eglSwapInterval = (_pfn_eglSwapInterval) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglSwapInterval);
    if(_ptr_eglSwapInterval != NULL) {
        _ret = _ptr_eglSwapInterval(dpy, interval);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglTerminate(EGLDisplay dpy)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglTerminate)(EGLDisplay dpy);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglTerminate _ptr_eglTerminate = (_pfn_eglTerminate) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglTerminate);
    if(_ptr_eglTerminate != NULL) {
        _ret = _ptr_eglTerminate(dpy);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglWaitClient(void)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglWaitClient)(void);
    EGLBoolean _ret = EGL_TRUE;
    _pfn_eglWaitClient _ptr_eglWaitClient = (_pfn_eglWaitClient) __eglDispatchFetchByCurrent(__EGL_DISPATCH_eglWaitClient);
    if(_ptr_eglWaitClient != NULL) {
        _ret = _ptr_eglWaitClient();
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglWaitGL(void)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglWaitGL)(void);
    EGLBoolean _ret = EGL_TRUE;
    _pfn_eglWaitGL _ptr_eglWaitGL = (_pfn_eglWaitGL) __eglDispatchFetchByCurrent(__EGL_DISPATCH_eglWaitGL);
    if(_ptr_eglWaitGL != NULL) {
        _ret = _ptr_eglWaitGL();
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglWaitNative(EGLint engine)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglWaitNative)(EGLint engine);
    EGLBoolean _ret = EGL_TRUE;
    _pfn_eglWaitNative _ptr_eglWaitNative = (_pfn_eglWaitNative) __eglDispatchFetchByCurrent(__EGL_DISPATCH_eglWaitNative);
    if(_ptr_eglWaitNative != NULL) {
        _ret = _ptr_eglWaitNative(engine);
    }
    return _ret;
}
PUBLIC EGLBoolean EGLAPIENTRY eglWaitSync(EGLDisplay dpy, EGLSync sync, EGLint flags)
{
    typedef EGLBoolean EGLAPIENTRY (* _pfn_eglWaitSync)(EGLDisplay dpy, EGLSync sync, EGLint flags);
    EGLBoolean _ret = EGL_FALSE;
    _pfn_eglWaitSync _ptr_eglWaitSync = (_pfn_eglWaitSync) __eglDispatchFetchByDisplay(dpy, __EGL_DISPATCH_eglWaitSync);
    if(_ptr_eglWaitSync != NULL) {
        _ret = _ptr_eglWaitSync(dpy, sync, flags);
    }
    return _ret;
}

const char * const __EGL_DISPATCH_FUNC_NAMES[__EGL_DISPATCH_COUNT + 1] = {
    "eglBindAPI",
    "eglBindTexImage",
    "eglChooseConfig",
    "eglClientWaitSync",
    "eglCopyBuffers",
    "eglCreateContext",
    "eglCreateImage",
    "eglCreatePbufferFromClientBuffer",
    "eglCreatePbufferSurface",
    "eglCreatePixmapSurface",
    "eglCreatePlatformPixmapSurface",
    "eglCreatePlatformPixmapSurfaceEXT",
    "eglCreatePlatformWindowSurface",
    "eglCreatePlatformWindowSurfaceEXT",
    "eglCreateSync",
    "eglCreateWindowSurface",
    "eglDebugMessageControlKHR",
    "eglDestroyContext",
    "eglDestroyImage",
    "eglDestroySurface",
    "eglDestroySync",
    "eglGetConfigAttrib",
    "eglGetConfigs",
    "eglGetCurrentContext",
    "eglGetCurrentDisplay",
    "eglGetCurrentSurface",
    "eglGetDisplay",
    "eglGetError",
    "eglGetPlatformDisplay",
    "eglGetPlatformDisplayEXT",
    "eglGetProcAddress",
    "eglGetSyncAttrib",
    "eglInitialize",
    "eglLabelObjectKHR",
    "eglMakeCurrent",
    "eglQueryAPI",
    "eglQueryContext",
    "eglQueryDebugKHR",
    "eglQueryDevicesEXT",
    "eglQueryDisplayAttribEXT",
    "eglQueryDisplayAttribKHR",
    "eglQueryDisplayAttribNV",
    "eglQueryString",
    "eglQuerySurface",
    "eglReleaseTexImage",
    "eglReleaseThread",
    "eglSurfaceAttrib",
    "eglSwapBuffers",
    "eglSwapInterval",
    "eglTerminate",
    "eglWaitClient",
    "eglWaitGL",
    "eglWaitNative",
    "eglWaitSync",
    NULL
};
const __eglMustCastToProperFunctionPointerType __EGL_DISPATCH_FUNCS[__EGL_DISPATCH_COUNT + 1] = {
    (__eglMustCastToProperFunctionPointerType) eglBindAPI,
    (__eglMustCastToProperFunctionPointerType) eglBindTexImage,
    (__eglMustCastToProperFunctionPointerType) eglChooseConfig,
    (__eglMustCastToProperFunctionPointerType) eglClientWaitSync,
    (__eglMustCastToProperFunctionPointerType) eglCopyBuffers,
    (__eglMustCastToProperFunctionPointerType) eglCreateContext,
    (__eglMustCastToProperFunctionPointerType) eglCreateImage,
    (__eglMustCastToProperFunctionPointerType) eglCreatePbufferFromClientBuffer,
    (__eglMustCastToProperFunctionPointerType) eglCreatePbufferSurface,
    (__eglMustCastToProperFunctionPointerType) eglCreatePixmapSurface,
    (__eglMustCastToProperFunctionPointerType) eglCreatePlatformPixmapSurface,
    (__eglMustCastToProperFunctionPointerType) eglCreatePlatformPixmapSurfaceEXT,
    (__eglMustCastToProperFunctionPointerType) eglCreatePlatformWindowSurface,
    (__eglMustCastToProperFunctionPointerType) eglCreatePlatformWindowSurfaceEXT,
    (__eglMustCastToProperFunctionPointerType) eglCreateSync,
    (__eglMustCastToProperFunctionPointerType) eglCreateWindowSurface,
    (__eglMustCastToProperFunctionPointerType) eglDebugMessageControlKHR,
    (__eglMustCastToProperFunctionPointerType) eglDestroyContext,
    (__eglMustCastToProperFunctionPointerType) eglDestroyImage,
    (__eglMustCastToProperFunctionPointerType) eglDestroySurface,
    (__eglMustCastToProperFunctionPointerType) eglDestroySync,
    (__eglMustCastToProperFunctionPointerType) eglGetConfigAttrib,
    (__eglMustCastToProperFunctionPointerType) eglGetConfigs,
    (__eglMustCastToProperFunctionPointerType) eglGetCurrentContext,
    (__eglMustCastToProperFunctionPointerType) eglGetCurrentDisplay,
    (__eglMustCastToProperFunctionPointerType) eglGetCurrentSurface,
    (__eglMustCastToProperFunctionPointerType) eglGetDisplay,
    (__eglMustCastToProperFunctionPointerType) eglGetError,
    (__eglMustCastToProperFunctionPointerType) eglGetPlatformDisplay,
    (__eglMustCastToProperFunctionPointerType) eglGetPlatformDisplayEXT,
    (__eglMustCastToProperFunctionPointerType) eglGetProcAddress,
    (__eglMustCastToProperFunctionPointerType) eglGetSyncAttrib,
    (__eglMustCastToProperFunctionPointerType) eglInitialize,
    (__eglMustCastToProperFunctionPointerType) eglLabelObjectKHR,
    (__eglMustCastToProperFunctionPointerType) eglMakeCurrent,
    (__eglMustCastToProperFunctionPointerType) eglQueryAPI,
    (__eglMustCastToProperFunctionPointerType) eglQueryContext,
    (__eglMustCastToProperFunctionPointerType) eglQueryDebugKHR,
    (__eglMustCastToProperFunctionPointerType) eglQueryDevicesEXT,
    (__eglMustCastToProperFunctionPointerType) eglQueryDisplayAttribEXT,
    (__eglMustCastToProperFunctionPointerType) eglQueryDisplayAttribKHR,
    (__eglMustCastToProperFunctionPointerType) eglQueryDisplayAttribNV,
    (__eglMustCastToProperFunctionPointerType) eglQueryString,
    (__eglMustCastToProperFunctionPointerType) eglQuerySurface,
    (__eglMustCastToProperFunctionPointerType) eglReleaseTexImage,
    (__eglMustCastToProperFunctionPointerType) eglReleaseThread,
    (__eglMustCastToProperFunctionPointerType) eglSurfaceAttrib,
    (__eglMustCastToProperFunctionPointerType) eglSwapBuffers,
    (__eglMustCastToProperFunctionPointerType) eglSwapInterval,
    (__eglMustCastToProperFunctionPointerType) eglTerminate,
    (__eglMustCastToProperFunctionPointerType) eglWaitClient,
    (__eglMustCastToProperFunctionPointerType) eglWaitGL,
    (__eglMustCastToProperFunctionPointerType) eglWaitNative,
    (__eglMustCastToProperFunctionPointerType) eglWaitSync,
    NULL
};
