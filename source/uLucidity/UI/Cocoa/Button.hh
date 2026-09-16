///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Button.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_BUTTON_HH
#define ULUCIDITY_UI_COCOA_BUTTON_HH

#include "uLucidity/UI/Cocoa/Cocoa.hh"

///////////////////////////////////////////////////////////////////////
/// Interface: Button
///////////////////////////////////////////////////////////////////////
@interface Button: NSButton {
    }
    @property (assign) NSImage* normalImage;
    @property (assign) NSImage* overImage;
    @property (assign) NSImage* selectedImage;
    @property (assign) BOOL over;
    @property (assign) BOOL selected;
    @property (assign) NSTrackingArea* trackingArea;
    @property (assign) SEL pressAction;
    @property (assign) SEL releaseAction;
    @property (assign) SEL enterAction;
    @property (assign) SEL exitAction;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (Button*)initWithRect:(NSRect)rect image:(NSImage*)image
               target:(NSObject*)target action:(SEL)action;

    - (Button*)initWithRect:(NSRect)rect image:(NSImage*)image
           target:(NSObject*)target pressAction:(SEL)pressAction
           releaseAction:(SEL)releaseAction;

    - (Button*)initWithRect:(NSRect)rect
           image:(NSImage*)image alternateImage:(NSImage*)alternateImage
           overImage:(NSImage*)overImage target:(NSObject*)target action:(SEL)action;

    - (Button*)initWithRect:(NSRect)rect
           image:(NSImage*)image alternateImage:(NSImage*)alternateImage
           overImage:(NSImage*)overImage target:(NSObject*)target
           pressAction:(SEL)pressAction releaseAction:(SEL)releaseAction;
@end

#endif // ULUCIDITY_UI_COCOA_BUTTON_HH
