///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Content.mm
///
/// Author: $author$
///   Date: 11/1/2022, 10/18/2025
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/Content.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: Content
///////////////////////////////////////////////////////////////////////
@implementation Content

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (Content*)initWithRect:(NSRect)rect application:(NSApplication*)application {
        _application = application;
        _contextMenu = nil;
        _handlers = nil;
        _gc = nil;
        _image = nil;

        LOG_DEBUG("(([super initWithFrame:rect]))...");
        if (([super initWithFrame:rect])) {

            LOG_DEBUG("((_contextMenu = [[Menu alloc]...");
            if ((_contextMenu = [[Menu alloc]
                 initWithTitle:@ULUCIDITY_UI_COCOA_MENU_TITLE
                 application: application])) {

                _handlers = Signals::handlers();
                _gc = new GraphicContext(self);
                return self;
            }
        }
        return nil;
    }
    - (void)popupContextMenu {
        if ((_contextMenu)) {
            NSSize size = [self bounds].size,
                   menuSize = [_contextMenu size];
            NSPoint location = NSMakePoint(0,0);
            if ((menuSize.width < size.width)) {
                location.x = size.width - menuSize.width;
            }
            [_contextMenu setWindow:[self window]];
            [_contextMenu popUpMenuPositioningItem:nil atLocation:location inView:self];
        }
    }
    - (void)frameDidResize:(NSRect)rect {
        if ((_image)) {
            LOG_DEBUG("[[self layer] setContents:_image]...");
            [[self layer] setContents:_image];
        } else {
            if ((_handlers)) {
                rect = [self bounds];
                LOG_DEBUG("_handlers->onContentResize(rect.size.width, rect.size.height)...");
                _handlers->onContentResize(rect.size.width, rect.size.height);
            }
        }
    }
    - (void)setImage:(NSImage*)image {
      if ((_image = (image))) {
          LOG_DEBUG("[self setWantsLayer:YES]...");
          [self setWantsLayer:YES];
          LOG_DEBUG("[[self layer] setContents:_image]...");
          [[self layer] setContents:_image];
      }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)mouseDown:(NSEvent*)event {
        NSEventType eventType = [event type];
        LOG_DEBUG("eventType = " << eventType << "...");
        if ((_handlers)) {
            NSPoint p = [self locationInWindow:event];
            LOG_DEBUG("_handlers->onContentMouseDown(p.x, p.y, uLucidity::UI::MouseButtonLeft)...");
            _handlers->onContentMouseDown(p.x, p.y, uLucidity::UI::MouseButtonLeft);
        }
    }
    - (void)mouseUp:(NSEvent*)event {
        NSEventType eventType = [event type];
        LOG_DEBUG("eventType = " << eventType << "...");
        if ((_handlers)) {
            NSPoint p = [self locationInWindow:event];
            LOG_DEBUG("_handlers->onContentMouseUp(p.x, p.y, uLucidity::UI::MouseButtonLeft)...");
            _handlers->onContentMouseUp(p.x, p.y, uLucidity::UI::MouseButtonLeft);
        }
    }
    - (void)rightMouseDown:(NSEvent*)event {
        NSEventType eventType = [event type];
        LOG_DEBUG("eventType = " << eventType << "...");
        if ((_handlers)) {
            NSPoint p = [self locationInWindow:event];
            LOG_DEBUG("_handlers->onContentMouseDown(p.x, p.y, uLucidity::UI::MouseButtonRight)...");
            _handlers->onContentMouseDown(p.x, p.y, uLucidity::UI::MouseButtonRight);
        }
    }
    - (void)rightMouseUp:(NSEvent*)event {
        NSEventType eventType = [event type];
        LOG_DEBUG("eventType = " << eventType << "...");
        if ((_handlers)) {
            NSPoint p = [self locationInWindow:event];
            LOG_DEBUG("_handlers->onContentMouseUp(p.x, p.y, uLucidity::UI::MouseButtonRight)...");
            _handlers->onContentMouseUp(p.x, p.y, uLucidity::UI::MouseButtonRight);
            if ((_contextMenu) && (_handlers->onContentMouseUpMenu())) {
                [_contextMenu setWindow:[self window]];
                LOG_DEBUG("[NSMenu popUpContextMenu:_contextMenu withEvent:event forView:self]...");
                [NSMenu popUpContextMenu:_contextMenu withEvent:event forView:self];
            }
        }
    }
    - (NSPoint)locationInWindow:(NSEvent*)event {
        NSPoint p = [self convertPoint:[event locationInWindow] fromView:nil];
        NSRect r = [self bounds];
        p.y = r.size.height - p.y;
        return p;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)drawRect:(NSRect)rect {
        /*uLucidity::UI::GraphicSurface::GraphicPixelInterface* color = 0;
        uLucidity::UI::ColorChannel r(0), g(128), b(0);
        if ((color = _gc->AllocateColor(r,g,b))) {
            _gc->FillRectangle(0,0, bounds.size.width,bounds.size.height, *color);
            _gc->FreeColor(color);
        }*/
        if (!(_image)) {
            NSRect bounds = [self bounds];
            bool dontDraw = false;

            if ((_handlers) && (_gc)) {
                LOG_DEBUG("_handlers->onContentDraw(*_gc, bounds.size.width, bounds.size.height, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height)...");
                dontDraw = _handlers->onContentDraw(*_gc, bounds.size.width, bounds.size.height, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
            }
            if (!(dontDraw)) {
                [[NSColor ULUCIDITY_UI_COCOA_CONTENT_COLOR] set];
                NSRectFill(bounds);
            }
        }
    }
@end
