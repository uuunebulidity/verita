///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: PluginLibrary.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_PLUGINLIBRARY_HPP
#define ULUCIDITY_UI_PLUGINLIBRARY_HPP

#include "uLucidity/UI/Plugin.hpp"
#include "uLucidity/OS/DLibrary.hpp"

#define ULUCIDITY_UI_PLUGIN_ACQUIRE_SYMBOL \
    ULUCIDITY_OS_DLIBRARY_SYMBOL(ULUCIDITY_UI_PLUGIN_ACQUIRE)

#define ULUCIDITY_UI_PLUGIN_RELEASE_SYMBOL \
    ULUCIDITY_OS_DLIBRARY_SYMBOL(ULUCIDITY_UI_PLUGIN_RELEASE)

namespace uLucidity {
namespace UI {

typedef OS::DLibraryImplements PluginLibraryImplements;
typedef OS::DLibrary PluginLibraryExtends;
///////////////////////////////////////////////////////////////////////
///  Class: PluginLibrary
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS PluginLibrary
: virtual public PluginLibraryImplements, public PluginLibraryExtends {
public:
    typedef PluginLibraryImplements Implements;
    typedef PluginLibraryExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    PluginLibrary(): m_acquire(0), m_release(0) {
    }
    virtual ~PluginLibrary() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Plugin* AcquirePlugin() {
        if (!(m_acquire)) {
            m_acquire = ((ULUCIDITY_UI_PLUGIN_ACQUIRE_T*)
                        GetAddress(ULUCIDITY_UI_PLUGIN_ACQUIRE_SYMBOL));
        }
        if ((m_acquire)) {
            Plugin* plugin = 0;
            if ((plugin = m_acquire())) {
                if ((plugin->InitPlugin())) {
                    if ((plugin->FailedOnLoadImage())) {
                        return OnFailedLoadImage(plugin);
                    } else {
                        return plugin;
                    }
                }
                ReleasePlugin(plugin);
            }
        }
        return 0;
    }
    virtual bool ReleasePlugin(Plugin* plugin) {
        if ((plugin)) {
            if (!(m_release)) {
                m_release = ((ULUCIDITY_UI_PLUGIN_RELEASE_T*)
                            GetAddress(ULUCIDITY_UI_PLUGIN_RELEASE_SYMBOL));
            }
            plugin->FiniPlugin();
            if ((m_release)) {
                if ((m_release(plugin))) {
                    return true;
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Plugin* OnFailedLoadImage(Plugin* plugin) {
        if ((plugin)) {
            plugin->SetNoFillContentRectangle();
        }
        return plugin;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Close() {
        m_acquire = 0;
        m_release = 0;
        return Extends::Close();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    ULUCIDITY_UI_PLUGIN_ACQUIRE_T* m_acquire;
    ULUCIDITY_UI_PLUGIN_RELEASE_T* m_release;
};

} // namespace UI 
} // namespace uLucidity 

#endif // ULUCIDITY_UI_PLUGINLIBRARY_HPP 
