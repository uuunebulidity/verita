///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Content.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_CONTENT_HH
#define ULUCIDITY_UI_COCOA_CONTENT_HH

#include "uLucidity/UI/Cocoa/Menu.hh"
#include "uLucidity/UI/Cocoa/GraphicSurface/GraphicContext.hh"

#define ULUCIDITY_UI_COCOA_CONTENT_COLOR blackColor

typedef uLucidity::UI::Cocoa::GraphicSurface::GraphicContext GraphicContext;

///////////////////////////////////////////////////////////////////////
/// Interface: Content
///////////////////////////////////////////////////////////////////////
@interface Content: NSView {
    }
    @property (assign) NSApplication* application;
    @property (assign) Menu* contextMenu;
    @property (assign) Signals* handlers;
    @property (assign) GraphicContext* gc;
    @property (assign) NSImage* image;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (Content*)initWithRect:(NSRect)rect application:(NSApplication*)application;
    - (void)popupContextMenu;
    - (void)frameDidResize:(NSRect)rect;
    - (void)setImage:(NSImage*)image;
@end

#endif // ULUCIDITY_UI_COCOA_CONTENT_HH
