///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Menu.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_MENU_HH
#define ULUCIDITY_UI_COCOA_MENU_HH

#include "uLucidity/UI/Cocoa/MenuItem.hh"

#define ULUCIDITY_UI_COCOA_MENU_TITLE "uLucidityUI"

#define ULUCIDITY_UI_COCOA_MENU_ITEM_HIDE "Hide uDentity"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_HIDEK ""

/*/
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEB "uWeb"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEBK "w"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_SAVE "Save changes..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_SAVEK "a"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_GOTO "Goto URL..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_GOTOK "g"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_BACKUP "Backup uWeb..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_BACKUPK "b"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_RESTORE "Restore uWeb..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_WEB_RESTOREK "r"

#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT "uVault"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULTK "s"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_ADD "Add File(s)..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_ADDK "d"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_EXTRACT "Extract..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_EXTRACTK "x"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_BACKUP "Backup uVault..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_BACKUPK "k"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_RESTORE "Restore uVault..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VAULT_RESTOREK "o"

#define ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER "uKeeper"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPERK "k"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER_BACKUP "Backup uKeeper..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER_BACKUPK "a"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER_RESTORE "Restore uKeeper..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_KEEPER_RESTOREK "t"

#define ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW "View"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VIEWK "v"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_WEB "uWeb"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_WEBK "s"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_VAULT "uVault"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_VAIULTK "v"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_KEEPER "uKeeper"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_VIEW_KEEPERK "k"

#define ULUCIDITY_UI_COCOA_MENU_ITEM_STOP "Stop remembering passowrd..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_STOPK "w"

#define ULUCIDITY_UI_COCOA_MENU_ITEM_HELP "Help..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_HELPK ""
#define ULUCIDITY_UI_COCOA_MENU_ITEM_ABOUT "About uDentity..."
#define ULUCIDITY_UI_COCOA_MENU_ITEM_ABOUTK ""

#define ULUCIDITY_UI_COCOA_MENU_ITEM_LOCK "Lock uDentity"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_LOCKK "l"
/*/
#define ULUCIDITY_UI_COCOA_MENU_ITEM_SHUTSOWN "Shutdown uDentity"
#define ULUCIDITY_UI_COCOA_MENU_ITEM_SHUTSOWNK ""

///////////////////////////////////////////////////////////////////////
/// Interface: Menu
///////////////////////////////////////////////////////////////////////
@interface Menu: NSMenu {
    }
    @property (assign) NSApplication* application;
    @property (assign) NSWindow* window;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (Menu*)initWithTitle:(NSString*)title application:(NSApplication*)application;
@end

#endif // ULUCIDITY_UI_COCOA_MENU_HH 
        

