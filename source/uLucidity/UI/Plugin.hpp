///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Plugin.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_PLUGIN_HPP
#define ULUCIDITY_UI_PLUGIN_HPP

#include "uLucidity/UI/PluginSignals.hpp"

#define ULUCIDITY_UI_CONTENT_IMAGE_BASE "uDentityContentImage"
#define ULUCIDITY_UI_CONTENT_IMAGE_EXTENSION "png"
#define ULUCIDITY_UI_CONTENT_IMAGE_FILENAME \
    ULUCIDITY_UI_CONTENT_IMAGE_BASE \
    "." ULUCIDITY_UI_CONTENT_IMAGE_EXTENSION

#define ULUCIDITY_UI_PLUGIN_ACQUIRE uLucidityUIPluginAcquire
#define ULUCIDITY_UI_PLUGIN_RELEASE uLucidityUIPluginRelease

namespace uLucidity {
namespace UI {

typedef PluginSignals PluginImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Plugin
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Plugin: virtual public PluginImplements {
public:
    typedef PluginImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool InitPlugin() {
        return true;
    }
    virtual bool FiniPlugin() {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetFailedOnLoadImage(bool to = true) {
        return true;
    }
    virtual bool FailedOnLoadImage() {
        return true;
    }
    virtual bool SetNoFillContentRectangle(bool to = true) {
        return true;
    }
    virtual bool NoFillContentRectangle() {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef Plugin PluginExtendImplements;
typedef Base PluginExtendExtends;
///////////////////////////////////////////////////////////////////////
///  Class: PluginExtend
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS PluginExtend
: virtual public PluginExtendImplements, public PluginExtendExtends {
public:
    typedef PluginExtendImplements Implements;
    typedef PluginExtendExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    PluginExtend() {
        Plugin*& thePlugin = ThePlugin();
        if (!(thePlugin)) {
            thePlugin = this;
        }
    }
    virtual ~PluginExtend() {
        Plugin*& thePlugin = ThePlugin();
        if (this == (thePlugin)) {
            thePlugin = 0;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static Plugin* GetThePlugin() {
        Plugin* thePlugin = ThePlugin();
        return thePlugin;
    }
protected:
    static Plugin*& ThePlugin() {
        static Plugin* thePlugin = 0;
        return thePlugin;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace UI
} // namespace uLucidity 

extern "C" {
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef PLATFORM_EXPORT uLucidity::UI::Plugin* ULUCIDITY_UI_PLUGIN_ACQUIRE_T();
typedef PLATFORM_EXPORT bool ULUCIDITY_UI_PLUGIN_RELEASE_T(uLucidity::UI::Plugin* plugin);
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
PLATFORM_EXPORT uLucidity::UI::Plugin* ULUCIDITY_UI_PLUGIN_ACQUIRE();
PLATFORM_EXPORT bool ULUCIDITY_UI_PLUGIN_RELEASE(uLucidity::UI::Plugin* plugin);
} // extern "C"

#endif // ULUCIDITY_UI_PLUGIN_HPP
