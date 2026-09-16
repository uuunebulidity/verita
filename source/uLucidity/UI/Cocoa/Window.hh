///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Window.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_WINDOW_HH
#define ULUCIDITY_UI_COCOA_WINDOW_HH

#include "uLucidity/UI/Cocoa/View.hh"

#define ULUCIDITY_UI_COCOA_WINDOW_MIN_WIDTH 372
#define ULUCIDITY_UI_COCOA_WINDOW_MAX_WIDTH ULUCIDITY_UI_COCOA_WINDOW_MIN_WIDTH
#define ULUCIDITY_UI_COCOA_WINDOW_MIN_HEIGHT 212
#define ULUCIDITY_UI_COCOA_WINDOW_MAX_HEIGHT ULUCIDITY_UI_COCOA_WINDOW_MIN_HEIGHT
#define ULUCIDITY_UI_COCOA_WINDOW_DEFER NO
#define ULUCIDITY_UI_COCOA_WINDOW_BACKING DefaultDesktopWindowBacking
#define ULUCIDITY_UI_COCOA_WINDOW_STYLE \
    (NSBorderlessWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask)

#define ULUCIDITY_UI_COCOA_MENU_QUIT_LABEL "Quit "
#define ULUCIDITY_UI_COCOA_MENU_QUIT_KEY "q"

///////////////////////////////////////////////////////////////////////
/// Interface: Window
///////////////////////////////////////////////////////////////////////
@interface Window: NSWindow <NSWindowDelegate> {
    }
    @property (assign) NSApplication* application;
    @property (assign) Images* images;
    @property (assign) View* view;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (Window*)initWithRect:(NSRect)rect
               application:(NSApplication*)application images:(Images*)images;
    - (Window*)setNotResizeable;
    - (Image*)setContentImage;
@end

#endif // ULUCIDITY_UI_COCOA_WINDOW_HH 
