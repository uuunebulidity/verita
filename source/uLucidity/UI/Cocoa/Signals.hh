///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Signals.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_SIGNALS_HH
#define ULUCIDITY_UI_COCOA_SIGNALS_HH

#include "uLucidity/UI/Cocoa/Logger.hh"
#include "uLucidity/UI/PluginSignals.hpp"

///////////////////////////////////////////////////////////////////////
///  Class: Signals
///////////////////////////////////////////////////////////////////////
class Signals: virtual public uLucidity::UI::PluginSignals {
public:
    typedef uLucidity::UI::PluginSignals Extends;
    typedef uLucidity::UI::MouseButton MouseButton;
    typedef uLucidity::UI::GraphicContext GraphicContext;

    /*/
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMenuItemuWebSave() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuWebSave()...");
            return to->onMenuItemuWebSave();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemuWebGoto() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuWebGoto()...");
            return to->onMenuItemuWebGoto();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemuWebBackup() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuWebBackup()...");
            return to->onMenuItemuWebBackup();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemuWebRestore() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuWebRestore()...");
            return to->onMenuItemuWebRestore();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMenuItemuVaultAdd() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuVaultAdd()...");
            return to->onMenuItemuVaultAdd();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemuVaultExtract() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuVaultExtract()...");
            return to->onMenuItemuVaultExtract();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemuVaultBackup() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuVaultBackup()...");
            return to->onMenuItemuVaultBackup();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemuVaultRestore() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuVaultRestore()...");
            return to->onMenuItemuVaultRestore();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMenuItemuKeeperBackup() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuKeeperBackup()...");
            return to->onMenuItemuKeeperBackup();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemuKeeperRestore() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemuKeeperRestore()...");
            return to->onMenuItemuKeeperRestore();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMenuItemViewuWeb() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemViewuWeb()...");
            return to->onMenuItemViewuWeb();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemViewuVault() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemViewuVault()...");
            return to->onMenuItemViewuVault();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemViewuKeeper() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemViewuKeeper()...");
            return to->onMenuItemViewuKeeper();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    /*/
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMenuItemHide() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemHide()...");
            return to->onMenuItemHide();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    /*/
    virtual bool onMenuItemStop() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemStop()...");
            return to->onMenuItemStop();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemHelp() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemHelp()...");
            return to->onMenuItemHelp();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemAbout() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemAbout()...");
            return to->onMenuItemAbout();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMenuItemLock() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemLock()...");
            return to->onMenuItemLock();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    /*/
    virtual bool onMenuItemShutdown() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemShutdown()...");
            return to->onMenuItemShutdown();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMenuItem() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItem()...");
            return to->onMenuItem();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    /*/

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onuKeeperClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onuKeeperClicked()...");
            return to->onuKeeperClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onuVaultClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onuVaultClicked()...");
            return to->onuVaultClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onuWebClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onuWebClicked()...");
            return to->onuWebClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onOptionsClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onOptionsClicked()...");
            return to->onOptionsClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    /*/
    

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onLogoClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onLogoClicked()...");
            return to->onLogoClicked();
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
        LOG_DEBUG("return false...");
        return false;
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
    virtual bool onMinimizeClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMinimizeClicked()...");
            return to->onMinimizeClicked();
        }
        LOG_DEBUG("return false...");
        return false;
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
    virtual bool onRestoreClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onRestoreClicked()...");
            return to->onRestoreClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onContentClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onContentClicked()...");
            return to->onContentClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onShutdownClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onShutdownClicked()...");
            return to->onShutdownClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onResizePressed() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onResizePressed()...");
            return to->onResizePressed();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onResizeReleased() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onResizeReleased()...");
            return to->onResizeReleased();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onContentMouseDown(int x, int y, MouseButton button) {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onContentMouseDown(x,y, button)...");
            return to->onContentMouseDown(x,y, button);
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onContentMouseUp(int x, int y, MouseButton button) {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onContentMouseUp(x,y, button)...");
            return to->onContentMouseUp(x,y, button);
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onContentMouseUpMenu() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onContentMouseUpMenu()...");
            return to->onContentMouseUpMenu();
        }
        LOG_DEBUG("return false...");
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onContentResize(int width, int height) {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onContentResize(width, height)...");
            return to->onContentResize(width, height);
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onContentDraw
    (GraphicContext& gc, int width, int height,
     int invalidX, int invalidY, int invalidWidth, int invalidHeight) {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onContentDraw(gc, width, height, invalidX,invalidY, invalidWidth,invalidHeight)...");
            return to->onContentDraw(gc, width, height, invalidX,invalidY, invalidWidth,invalidHeight);
        }
        LOG_DEBUG("return false...");
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Signals* forwardTo(Signals* to) {
        return 0;
    }
    virtual Signals* forwardTo() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static Signals* handlers() {
        return handlersReference();
    }
protected:
    static Signals*& handlersReference() {
        static Signals* handlers = 0;
        return handlers;
    }
};

#endif // ULUCIDITY_UI_COCOA_SIGNALS_HH
