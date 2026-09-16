///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Button.mm
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/Button.hh"
#include "uLucidity/UI/Cocoa/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: Button
///////////////////////////////////////////////////////////////////////
@implementation Button

    - (Button*)initWithRect:(NSRect)rect image:(NSImage*)image
               target:(NSObject*)target action:(SEL)action {

        if (([self initWithRect:rect
             image:image alternateImage:image
             overImage:image target:target action:action])) {
            return self;
        }
        return nil;
    }
    - (Button*)initWithRect:(NSRect)rect image:(NSImage*)image
               target:(NSObject*)target pressAction:(SEL)pressAction
               releaseAction:(SEL)releaseAction {

        if (([self initWithRect:rect
             image:image alternateImage:image
             overImage:image target:target action:nil])) {
            _pressAction = pressAction;
            _releaseAction = releaseAction;
            return self;
        }
        return nil;
    }
    - (Button*)initWithRect:(NSRect)rect
               image:(NSImage*)image alternateImage:(NSImage*)alternateImage
               overImage:(NSImage*)overImage target:(NSObject*)target action:(SEL)action {
        _normalImage = image;
        _overImage = overImage;
        _selectedImage = alternateImage;
        _over = NO;
        _selected = NO;
        _trackingArea = nil;
        _pressAction = nil;
        _releaseAction = nil;
        _enterAction = nil;
        _exitAction = nil;

        if (([super initWithFrame:rect])) {
            [self setButtonType:NSMomentaryChangeButton];
            [self setImagePosition:NSImageOnly];
            [self setImageScaling:NSImageScaleAxesIndependently];
            [self setImage:image];
            [self setAlternateImage:alternateImage];
            [self setTransparent:NO];
            [self setBordered:NO];
            [self setTarget:target];
            [self setAction:action];
            if ((overImage) && (overImage != alternateImage) && (overImage != image)) {
                NSTrackingAreaOptions trackingOptions
                = NSTrackingMouseEnteredAndExited | NSTrackingActiveAlways;

                rect.origin = NSMakePoint(0,0);
                if ((_trackingArea = [[NSTrackingArea alloc]
                     initWithRect:rect options:trackingOptions owner:self userInfo:nil])) {
                    [self addTrackingArea:_trackingArea];
                }
            }
            return self;
        }
        return nil;
    }
    - (Button*)initWithRect:(NSRect)rect
               image:(NSImage*)image alternateImage:(NSImage*)alternateImage
               overImage:(NSImage*)overImage target:(NSObject*)target
               pressAction:(SEL)pressAction releaseAction:(SEL)releaseAction {

        if (([self initWithRect:rect
             image:image alternateImage:alternateImage
             overImage:overImage target:target action:nil])) {
            _pressAction = pressAction;
            _releaseAction = releaseAction;
            return self;
        }
        return nil;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (BOOL)setSelected:(BOOL)isSelected {
        if ((isSelected) && (!_selected)) {
            LOG_DEBUG("_selected = YES...");
            _selected = isSelected;
            if ((_over) && (_overImage) && (_overImage != [self image])) {
                LOG_DEBUG("[self setImage:_overImage]...");
                [self setImage:_overImage];
            } else {
                if ((_selectedImage) && (_selectedImage != [self image])) {
                    LOG_DEBUG("[self setImage:_selectedImage]...");
                    [self setImage:_selectedImage];
                }
            }
        } else {
            if ((!isSelected) && (_selected)) {
                LOG_DEBUG("_selected = NO...");
                _selected = isSelected;
                if ((_over) && (_overImage) && (_overImage != [self image])) {
                    LOG_DEBUG("[self setImage:_overImage]...");
                    [self setImage:_overImage];
                } else {
                    if ((_normalImage) && (_normalImage != [self image])) {
                        LOG_DEBUG("[self setImage:_normalImage]...");
                        [self setImage:_normalImage];
                    }
                }
            } else {
            }
        }
        return _selected;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)mouseDown:(NSEvent*)event {
        NSObject* target = [self target];
        if ((target) && (_pressAction) && (_releaseAction)) {
            LOG_DEBUG("[target performSelector:_pressAction withObject:event]...");
            [target performSelector:_pressAction withObject:event];
        } else {
            [super mouseDown:event];
        }
    }
    - (void)mouseUp:(NSEvent*)event {
        NSObject* target = [self target];
        if ((target) && (_pressAction) && (_releaseAction)) {
            LOG_DEBUG("[target performSelector:_releaseAction withObject:event]...");
            [target performSelector:_releaseAction withObject:event];
        } else {
        }
    }

    - (void)mouseEntered:(NSEvent*)event{
        NSObject* target = nil;
        _over = YES;
        if ((_overImage) && (_overImage != ([self image]))) {
            LOG_DEBUG("[self setImage:_overImage]...");
            [self setImage:_overImage];
        }
        if ((_enterAction) && (target = [self target])) {
            LOG_DEBUG("[target performSelector:_enterAction withObject:event]...");
            [target performSelector:_enterAction withObject:event];
        }
    }
    - (void)mouseExited:(NSEvent*)event{
        NSObject* target = nil;
        _over = NO;
        if ((_selected)) {
            if ((_selectedImage) && (_selectedImage != [self image])) {
                LOG_DEBUG("[self setImage:_selectedImage]...");
                [self setImage:_selectedImage];
            }
        } else {
            if ((_normalImage) && (_normalImage != [self image])) {
                LOG_DEBUG("[self setImage:_normalImage]...");
                [self setImage:_normalImage];
            }
        }
        if ((_exitAction) && (target = [self target])) {
            LOG_DEBUG("[target performSelector:_exitAction withObject:event]...");
            [target performSelector:_exitAction withObject:event];
        }
    }
@end
