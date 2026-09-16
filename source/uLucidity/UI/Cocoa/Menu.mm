///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Menu.mm
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/Menu.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: Menu
///////////////////////////////////////////////////////////////////////
@implementation Menu

    - (Menu*)initWithTitle:(NSString*)title application:(NSApplication*)application {
        _application = application;
        _window = nil;

        if (([super initWithTitle:title])) {
            MenuItem* item = nil;
            NSMenu* menu = nil;

            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_HIDE
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_HIDEK
                 target:self action:@selector(onMenuItemHide:) enabled:YES])) {
                [self addItem:item];
            }

            [self addItem:[NSMenuItem separatorItem]];

            /*/
            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEBK
                 target:self action:@selector(onMenuItem:) enabled:YES])) {
                [self addItem:item];

                if ((menu = [[NSMenu alloc] initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB])) {
                    [item setSubmenu: menu];

                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_SAVE
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_SAVEK
                         target:self action:@selector(onMenuItemuWebSave:) enabled:YES])) {
                        [menu addItem:item];
                    }
                    [menu addItem:[NSMenuItem separatorItem]];
                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_GOTO
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_GOTOK
                         target:self action:@selector(onMenuItemuWebGoto:) enabled:YES])) {
                        [menu addItem:item];
                    }
                    [menu addItem:[NSMenuItem separatorItem]];
                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_BACKUP
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_BACKUPK
                         target:self action:@selector(onMenuItemuWebBackup:) enabled:YES])) {
                        [menu addItem:item];
                    }
                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_RESTORE
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_RESTOREK
                         target:self action:@selector(onMenuItemuWebSave:) enabled:YES])) {
                        [menu addItem:item];
                    }
                }
            }
            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULTK
                 target:self action:@selector(onMenuItem:) enabled:YES])) {
                [self addItem:item];

                if ((menu = [[NSMenu alloc] initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT])) {
                    [item setSubmenu: menu];

                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_ADD
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_ADDK
                         target:self action:@selector(onMenuItemuVaultAdd:) enabled:YES])) {
                        [menu addItem:item];
                    }
                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_EXTRACT
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_EXTRACT
                         target:self action:@selector(onMenuItemuVaultExtract:) enabled:YES])) {
                        [menu addItem:item];
                    }
                    [menu addItem:[NSMenuItem separatorItem]];
                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_BACKUP
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_BACKUPK
                         target:self action:@selector(onMenuItemuVaultBackup:) enabled:YES])) {
                        [menu addItem:item];
                    }
                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_RESTORE
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_RESTOREK
                         target:self action:@selector(onMenuItemuVaultRestore:) enabled:YES])) {
                        [menu addItem:item];
                    }
                }
            }
            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPERK
                 target:self action:@selector(onMenuItem:) enabled:YES])) {
                [self addItem:item];

                if ((menu = [[NSMenu alloc] initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER])) {
                    [item setSubmenu: menu];

                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER_BACKUP
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER_BACKUPK
                         target:self action:@selector(onMenuItemuKeeperBackup:) enabled:YES])) {
                        [menu addItem:item];
                    }
                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER_RESTORE
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER_RESTOREK
                         target:self action:@selector(onMenuItemuKeeperRestore:) enabled:YES])) {
                        [menu addItem:item];
                    }
                }
            }
            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_VIEWK
                 target:self action:@selector(onMenuItem:) enabled:YES])) {
                [self addItem:item];

                if ((menu = [[NSMenu alloc] initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW])) {
                    [item setSubmenu: menu];

                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_WEB
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_WEBK
                         target:self action:@selector(onMenuItemViewuWeb:) enabled:YES])) {
                        [menu addItem:item];
                    }
                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_VAULT
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_VAIULTK
                         target:self action:@selector(onMenuItemViewuVault:) enabled:YES])) {
                        [menu addItem:item];
                    }
                    if ((item = [[MenuItem alloc]
                         initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_KEEPER
                         keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_KEEPERK
                         target:self action:@selector(onMenuItemViewuKeeper:) enabled:YES])) {
                        [menu addItem:item];
                    }
                }
            }

            [self addItem:[NSMenuItem separatorItem]];

            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_STOP
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_STOPK
                 target:self action:@selector(onMenuItemStop:) enabled:YES])) {
                [self addItem:item];
            }

            [self addItem:[NSMenuItem separatorItem]];

            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_HELP
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_HELPK
                 target:self action:@selector(onMenuItemHelp:) enabled:YES])) {
                [self addItem:item];
            }
            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_ABOUT
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_ABOUTK
                 target:self action:@selector(onMenuItemAbout:) enabled:YES])) {
                [self addItem:item];
            }

            [self addItem:[NSMenuItem separatorItem]];

            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_LOCK
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_LOCKK
                 target:self action:@selector(onMenuItemLock:) enabled:YES])) {
                [self addItem:item];
            }
            /*/
            if ((item = [[MenuItem alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_ITEM_SHUTSOWN
                 keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_ITEM_SHUTSOWNK
                 target:self action:@selector(onMenuItemShutdown:) enabled:YES])) {
                [self addItem:item];
            }
            return self;
        }
        return nil;
    }

    /*/
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    -(void)onMenuItemuWebSave:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuWebSave())) {
        }
    }
    -(void)onMenuItemuWebGoto:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuWebGoto())) {
        }
    }
    -(void)onMenuItemuWebBackup:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuWebBackup())) {
        }
    }
    -(void)onMenuItemuWebRestore:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuWebRestore())) {
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    -(void)onMenuItemuVaultAdd:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuVaultAdd())) {
        }
    }
    -(void)onMenuItemuVaultExtract:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuVaultExtract())) {
        }
    }
    -(void)onMenuItemuVaultBackup:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuVaultBackup())) {
        }
    }
    -(void)onMenuItemuVaultRestore:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuVaultRestore())) {
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    -(void)onMenuItemuKeeperBackup:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuKeeperBackup())) {
        }
    }
    -(void)onMenuItemuKeeperRestore:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemuKeeperRestore())) {
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    -(void)onMenuItemViewuWeb:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemViewuWeb())) {
        }
    }
    -(void)onMenuItemViewuVault:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemViewuVault())) {
        }
    }
    -(void)onMenuItemViewuKeeper:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemViewuKeeper())) {
        }
    }
    /*/

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    -(void)onMenuItemHide:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemHide()) && (_window)) {
            [_window miniaturize:sender];
        }
    }
    /*/
    -(void)onMenuItemStop:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemStop())) {
        }
    }
    -(void)onMenuItemHelp:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemHelp())) {
        }
    }
    -(void)onMenuItemAbout:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemAbout())) {
        }
    }
    -(void)onMenuItemLock:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemLock())) {
        }
    }
    /*/
    -(void)onMenuItemShutdown:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItemShutdown()) && (_application)) {
            [_application stop:self];
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    -(void)onMenuItem:(id)sender {
        Signals* handlers = Signals::handlers();
        if ((handlers) && (handlers->onMenuItem())) {
        }
    }
@end
        

