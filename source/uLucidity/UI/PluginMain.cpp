///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: PluginMain.cpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/PluginMain.hpp"
#include "uLucidity/UI/Plugin.hpp"

namespace uLucidity {
namespace UI {

///////////////////////////////////////////////////////////////////////
///  Class: PluginMain
///////////////////////////////////////////////////////////////////////
static PluginMain thePluginMain;

} // namespace UI 
} // namespace uLucidity 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
PLATFORM_EXPORT uLucidity::UI::Plugin* ULUCIDITY_UI_PLUGIN_ACQUIRE() {
    uLucidity::UI::Plugin* thePlugin = 0;

    STDERR_LOG_DEBUG("uLucidity::UI::PluginExtend::GetThePlugin()...");
    if ((thePlugin = uLucidity::UI::PluginExtend::GetThePlugin())) {
        STDERR_LOG_DEBUG("return thePlugin...");
        return thePlugin;
    } else {
        STDERR_LOG_ERROR("...failed 0 = uLucidity::UI::PluginExtend::GetThePlugin()");
    }
    STDERR_LOG_DEBUG("return 0...");
    return 0;
}
PLATFORM_EXPORT bool ULUCIDITY_UI_PLUGIN_RELEASE(uLucidity::UI::Plugin* plugin) {
    uLucidity::UI::Plugin* thePlugin = 0;

    STDERR_LOG_DEBUG("uLucidity::UI::PluginExtend::GetThePlugin()...");
    if ((thePlugin = uLucidity::UI::PluginExtend::GetThePlugin())) {
        if (plugin == (thePlugin)) {
            STDERR_LOG_DEBUG("return true...");
        } else {
            STDERR_LOG_ERROR("...failed plugin != (thePlugin)");
        }
    } else {
        STDERR_LOG_ERROR("...failed 0 = uLucidity::UI::PluginExtend::GetThePlugin()");
    }
    STDERR_LOG_DEBUG("return false...");
    return false;
}
