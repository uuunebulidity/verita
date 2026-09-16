///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: MenuItem.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_MENUITEM_HH
#define ULUCIDITY_UI_COCOA_MENUITEM_HH

#include "uLucidity/UI/Cocoa/Cocoa.hh"
#include "uLucidity/UI/Cocoa/Signals.hh"

///////////////////////////////////////////////////////////////////////
/// Interface: MenuItem
///////////////////////////////////////////////////////////////////////
@interface MenuItem: NSMenuItem {
    }
    - (MenuItem*)initWithTitle:(NSString*)title
                 keyEquivalent:(NSString*)keyEquivalent
                 target:(NSObject*)target action:(SEL)action enabled:(BOOL)enabled;
@end
#endif // ULUCIDITY_UI_COCOA_MENUITEM_HH 
        

