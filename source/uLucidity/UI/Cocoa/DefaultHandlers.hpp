///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DefaultHandlers.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_DEFAULTHANDLERS_HPP
#define ULUCIDITY_UI_COCOA_DEFAULTHANDLERS_HPP

#include "uLucidity/UI/Cocoa/Handlers.hpp"

///////////////////////////////////////////////////////////////////////
///  Class: DefaultHandlers
///////////////////////////////////////////////////////////////////////
class DefaultHandlers: public Handlers {
public:
    typedef Handlers Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMenuItemHide() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemHide()...");
            return to->onMenuItemHide();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    virtual bool onMenuItemShutdown() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemShutdown()...");
            return to->onMenuItemShutdown();
        }
        LOG_DEBUG("return true...");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMinimizeClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMinimizeClicked()...");
            return to->onMinimizeClicked();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    virtual bool onMinimizeHideClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMinimizeHideClicked()...");
            return to->onMinimizeHideClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMaximizeClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMaximizeClicked()...");
            return to->onMaximizeClicked();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    virtual bool onMaximizeShutdownClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMaximizeShutdownClicked()...");
            return to->onMaximizeShutdownClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    /*/
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onOptionsClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onOptionsClicked()...");
            return to->onOptionsClicked();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    virtual bool onShutdownClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onShutdownClicked()...");
            return to->onShutdownClicked();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    /*/
};

#endif // ULUCIDITY_UI_COCOA_DEFAULTHANDLERS_HPP 
