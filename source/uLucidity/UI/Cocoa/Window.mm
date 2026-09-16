///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Window.mm
///
/// Author: $author$
///   Date: 11/1/2022, 10/9/2025
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/Window.hh"
#include "uLucidity/UI/Cocoa/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: Window
///////////////////////////////////////////////////////////////////////
@implementation Window

    - (Window*)initWithRect:(NSRect)rect
               application:(NSApplication*)application images:(Images*)images {
        NSRect viewRect = NSMakeRect(0,0, rect.size.width,rect.size.height);
        NSWindowStyleMask style = ULUCIDITY_UI_COCOA_WINDOW_STYLE;
        NSBackingStoreType backing = (NSBackingStoreType)ULUCIDITY_UI_COCOA_WINDOW_BACKING;
        BOOL defer = ULUCIDITY_UI_COCOA_WINDOW_DEFER;
        id superId = nil;

        _application = application;
        _images = images;
        _view = nil;

        LOG_DEBUG("[super initWithContentRect:rect styleMask:style backing:backing defer:defer]...");
        if ((superId = [super initWithContentRect:rect styleMask:style backing:backing defer:defer])) {

            //LOG_DEBUG("[[View alloc] initWithRect:viewRect application:application images:_images]...");
            //if ((_view = [[View alloc] initWithRect:viewRect application:application images:_images])) {
            LOG_DEBUG("((_view = [self allocView:viewRect]))...");
            if ((_view = [self allocView:viewRect])) {

                LOG_DEBUG("[self = " << String(self) << " setContentView:_view = " << String(_view) << "]...");
                [self setContentView:_view];

                [[NSNotificationCenter defaultCenter]
                  addObserver:_view selector:@selector(windowDidResize:)
                  name:NSWindowDidResizeNotification object:self];
            } else {
            }

            [self centerInScreen];
            [self setAlphaValue:1];
            [self setOpaque:NO];
            [self setBackgroundColor:[NSColor clearColor]];
            [self setHasShadow:YES];
            [self setMovableByWindowBackground:YES];
            [self makeKeyAndOrderFront:self];
            [self setDelegate:self];
            return self;
        } else {
            LOG_ERROR("...failed " << String(superId) << " = [super initWithContentRect:rect styleMask:style backing:backing defer:defer]");
        }
        return nil;
    }

    - (View*)allocView:(NSRect)withRect {
        View* view = nil;
        LOG_DEBUG("((view = [[View alloc] initWithRect:withRect application:_application images:_images]))...");
        if ((view = [[View alloc] initWithRect:withRect application:_application images:_images])) {
            LOG_DEBUG("...((view = [[View alloc] initWithRect:withRect application:_application images:_images]))");
        } else {
            LOG_DEBUG("failed on ((view = [[View alloc] initWithRect:withRect application:_application images:_images]))");
        }
        return view;
    }

    - (Window*)setNotResizeable {
        LOG_DEBUG("[self setStyleMask:[self styleMask] & ~NSWindowStyleMaskResizable]...");
        [self setStyleMask:[self styleMask] & ~NSWindowStyleMaskResizable];
    }

    - (Image*)setContentImage {
        if ((_view)) {
            return [_view setContentImage];
        }
        return nil;
    }

    - (void)windowWillClose:(NSNotification*)notification {
        NSApplication* application = 0;

        LOG_DEBUG("[self = " << String(self) << " application]...");
        if ((application = [self application])) {

            LOG_DEBUG("[application = " << String(application) << " stop:self = " << String(self) << "]...");
            [application stop:self];
        }
    }

    - (void)centerInScreen {
        NSRect rect = [self frame],
               screenRect = NSMakeRect(0,0, 0,0);
        NSScreen* screen = nil;

        if ((screen = [self screen])) {
            screenRect = [screen frame];

            if ((rect.size.width <= screenRect.size.width)) {
                rect.origin.x = (screenRect.size.width - rect.size.width)/2;
            } else {
                rect.origin.x = 0;
            }
            if ((rect.size.height <= screenRect.size.height)) {
                rect.origin.y = (screenRect.size.height - rect.size.height)/2;
            } else {
                rect.origin.y = screenRect.size.height;
            }
            [self setFrameOrigin:rect.origin];
        } else {
        }
    }

    - (BOOL)canBecomeKeyWindow {
        return YES;
    }
    - (BOOL)canBecomeMainWindow {
        return YES;
    }
@end
