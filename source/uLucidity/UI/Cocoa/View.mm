///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: View.mm
///
/// Author: $author$
///   Date: 11/1/2022, 10/18/2025
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/View.hh"
#include "uLucidity/UI/Cocoa/Signals.hh"
#include "uLucidity/UI/Cocoa/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: View
///////////////////////////////////////////////////////////////////////
@implementation View

    - (View*)initWithRect:(NSRect)rect
             application:(NSApplication*)application images:(Images*)images {
        _application = application;
        _images = images;
        _selectedButton = nil;

        LOG_DEBUG("[super initWithFrame:rect]...");
        if (([super initWithFrame:rect])) {

            LOG_DEBUG("[self initImages:images]]...");
            if (([self initImages:images])) {

                LOG_DEBUG("[self initButtons:rect]...");
                if (([self initButtons:rect])) {

                    LOG_DEBUG("(!((_contentB)))...");
                    if (!((_contentB))) {

                        LOG_DEBUG("((_content = [[Content alloc] initWithRect:[self contentRect:rect] application:application]))...");
                        if ((_content = [[Content alloc] initWithRect:[self contentRect:rect] application:application])) {
    
                            LOG_DEBUG("[self addSubview:_content]...");
                            [self addSubview:_content];
                        } else {
                        }
                    } else {
                    }
                    return self;
                }
            }
        } else {
            LOG_ERROR("...failed on [super initWithFrame:rect]");
        }
        return nil;
    }

    - (void) viewDidMoveToSuperview {
        LOG_DEBUG("...{");
        LOG_DEBUG("}...");
    }
    - (void) viewDidMoveToWindow {
        LOG_DEBUG("...{");
        LOG_DEBUG("}...");
    }

    - (Image*)setContentImage {
        LOG_DEBUG("((_content))...");
        if ((_content)) {

            LOG_DEBUG("((_contentImage))...");
            if ((_contentImage)) {

                LOG_DEBUG("[_content setImage:_contentImage]...");
                [_content setImage:_contentImage];
            } else {
            }
        } else {
        }
        return _contentImage;
    }

    - (View*)initImages:(Images*)images {
        if ((_images = images)) {
            _l = [_images l];
            _t = [_images t];
            _r = [_images r];
            _b = [_images b];

            _tl = [_images tl];
            _tr = [_images tr];
            _bl = [_images bl];

            _br = [_images br];
            _brr = [_images brr];
            _brs = [_images brs];
            _outBr = _brr;

            _logo = [_images logo];

            _max = [_images max];
            _maxr = [_images maxr];
            _maxs = [_images maxs];

            _min = [_images min];
            _minr = [_images minr];
            _mins = [_images mins];

            _contentImage = [_images content];

            /*/
            _sk = [_images sk];
            _skr = [_images skr];
            _sks = [_images sks];

            _sv = [_images sv];
            _svr = [_images svr];
            _svs = [_images svs];

            _sw = [_images sw];
            _swr = [_images swr];
            _sws = [_images sws];

            _op = [_images op];
            _opr = [_images opr];
            _ops = [_images ops];

            _sd = [_images sd];
            _sdr = [_images sdr];
            _sds = [_images sds];
            /*/
            return self;
        }
        return nil;
    }

    - (View*)initButtons:(NSRect)rect {

        _sp = ULUCIDITY_UI_COCOA_VIEW_SPACEING;
        _lsp = ULUCIDITY_UI_COCOA_VIEW_LSPACEING;
        _rsp = ULUCIDITY_UI_COCOA_VIEW_RSPACEING;

        if ((_logoB = [[Button alloc] initWithRect:[self logoRect:rect]
            image:_logo target:self action:@selector(logoClicked:)])) {
            [self addSubview:_logoB];
        }

        if ((_maxB = [[Button alloc] initWithRect:[self maxRect:rect]
            image:_max alternateImage:_maxs  overImage: _max
            target:self action:@selector(maxClicked:)])) {
            [self addSubview:_maxB];
        }
        if ((_minB = [[Button alloc] initWithRect:[self minRect:rect]
            image:_min alternateImage:_mins  overImage: _min
            target:self action:@selector(minClicked:)])) {
            [self addSubview:_minB];
        }

        if ((_contentB = [[Button alloc] initWithRect:[self contentRect:rect]
            image:_contentImage target:self action:@selector(contentClicked:)])) {
            [self addSubview:_contentB];
        }

        /*/
        if ((_skB = [[Button alloc] initWithRect:[self skRect:rect]
            image:_sk alternateImage:_sks  overImage: _skr
            target:self action:@selector(skClicked:)])) {
            [self addSubview:_skB];
        }
        if ((_svB = [[Button alloc] initWithRect:[self svRect:rect]
            image:_sv alternateImage:_svs  overImage: _svr
            target:self action:@selector(svClicked:)])) {
            [self addSubview:_svB];
        }
        if ((_swB = [[Button alloc] initWithRect:[self swRect:rect]
             image:_sw alternateImage:_sws  overImage: _swr
             target:self action:@selector(swClicked:)])) {
            [self addSubview:_swB];
        }

        if ((_opB = [[Button alloc] initWithRect:[self opRect:rect]
            image:_op alternateImage:_ops  overImage: _opr
            target:self action:@selector(opClicked:)])) {
            [self addSubview:_opB];
        }

        if ((_sdB = [[Button alloc] initWithRect:[self sdRect:rect]
            image:_sd alternateImage:_sds  overImage: _sdr
            target:self action:@selector(sdClicked:)])) {
            [self addSubview:_sdB];
        }

        if ((_brB = [[Button alloc] initWithRect:[self brRect:rect]
             image:_br alternateImage:_brs  overImage: _brr target:self
             pressAction:@selector(brPressed:) releaseAction:@selector(brReleased:)])) {
            [_brB setTransparent:YES];
            [_brB setEnterAction:@selector(brEntered:)];
            [_brB setExitAction:@selector(brExited:)];
            [self addSubview:_brB];
        }
        /*/
        return self;
    }

    - (View*)moveButtons:(NSRect)rect {

        if ((_logoB)) {
            [_logoB setFrame:[self logoRect:rect]];
        }
        if ((_maxB)) {
            [_maxB setFrame:[self maxRect:rect]];
        }
        if ((_minB)) {
            [_minB setFrame:[self minRect:rect]];
        }

        /*/
        if ((_skB)) {
            [_skB setFrame:[self skRect:rect]];
        }
        if ((_svB)) {
            [_svB setFrame:[self svRect:rect]];
        }
        if ((_swB)) {
            [_swB setFrame:[self swRect:rect]];
        }
        if ((_opB)) {
            [_opB setFrame:[self opRect:rect]];
        }

        if ((_sdB)) {
            [_sdB setFrame:[self sdRect:rect]];
        }

        if ((_brB)) {
            [_brB setFrame:[self brRect:rect]];
        }
        /*/
        return self;
    }

    - (View*)moveContent:(NSRect)rect {

        if ((_content)) {
            rect = [self contentRect:rect];
            [_content setFrame:rect];
            [_content frameDidResize:rect];
        }
        return self;
    }

    - (void)windowDidResize:(NSNotification*)notification {
        LOG_DEBUG("[self moveButtons:[self bounds]]...");
        [self moveButtons:[self bounds]];

        LOG_DEBUG("[self moveContent:[self bounds]]...");
        [self moveContent:[self bounds]];
    }
    - (BOOL)acceptsFirstMouse:(NSEvent*)event {
        return YES;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)selectButton:(Button*)button {
        if ((_selectedButton != button) && (_selectedButton)) {
            [_selectedButton setSelected:NO];
        }
        if ((_selectedButton != button) && (_selectedButton = button)) {
            [_selectedButton setSelected:YES];
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)logoClicked:(id)sender {
        Signals* handlers = Signals::handlers();
        NSWindow* window = [self window];
        if ((handlers) && (handlers->onLogoClicked()) && (window)) {
            LOG_DEBUG("[self onHandlersLogoClicked:sender application:_application window:window]...");
            [self onHandlersLogoClicked:sender application:_application window:window];
        } else {
            if ((window)) {
                LOG_DEBUG("[self onLogoClicked:sender application:_application window:window]...");
                [self onLogoClicked:sender application:_application window:window];
            }
        }
    }
    - (void)onHandlersLogoClicked:(id)sender 
        application:(NSApplication*)application window:(NSWindow*)window {
    }
    - (void)onLogoClicked:(id)sender 
        application:(NSApplication*)application window:(NSWindow*)window {
    }
    - (void)maxClicked:(id)sender {
        Signals* handlers = Signals::handlers();
        NSWindow* window = [self window];
        [self selectButton:_maxB];
        if ((handlers) && (handlers->onMaximizeShutdownClicked()) && (window)) {
            //[_application stop:self];
            LOG_DEBUG("[self onMaximizeShutdownClicked:sender application:_application window:window]...");
            [self onMaximizeShutdownClicked:sender application:_application window:window];
        } else {
            if ((handlers) && (handlers->onMaximizeClicked()) && (window)) {
                //[window zoom:sender];
                LOG_DEBUG("[self onMaximizeClicked:sender application:_application window:window]...");
                [self onMaximizeClicked:sender application:_application window:window];
            }
        }
    }
    - (void)onMaximizeShutdownClicked:(id)sender 
        application:(NSApplication*)application window:(NSWindow*)window {
        LOG_DEBUG("[application stop:self]...");
        [application stop:self];
    }
    - (void)onMaximizeClicked:(id)sender 
        application:(NSApplication*)application window:(NSWindow*)window {
        LOG_DEBUG("[window zoom:sender]...");
        [window zoom:sender];
    }
    - (void)minClicked:(id)sender {
        Signals* handlers = Signals::handlers();
        NSWindow* window = [self window];
        [self selectButton:_minB];
        if ((handlers) && (handlers->onMinimizeHideClicked()) && (window)) {
            [_application hide:self];
        } else {
            if ((handlers) && (handlers->onMinimizeClicked()) && (window)) {
                [window miniaturize:sender];
            }
        }
    }
    - (void)contentClicked:(id)sender {
        Signals* handlers = Signals::handlers();
        NSWindow* window = [self window];
        if ((handlers) && (handlers->onContentClicked()) && (window)) {
            LOG_DEBUG("[self onHandlersContentClicked:sender application:_application window:window]...");
            [self onHandlersContentClicked:sender application:_application window:window];
        } else {
            if ((window)) {
                LOG_DEBUG("[self onContentClicked:sender application:_application window:window]...");
                [self onContentClicked:sender application:_application window:window];
            }
        }
    }
    - (void)onHandlersContentClicked:(id)sender 
        application:(NSApplication*)application window:(NSWindow*)window {
    }
    - (void)onContentClicked:(id)sender 
        application:(NSApplication*)application window:(NSWindow*)window {
    }

    /*/
    - (void)skClicked:(id)sender {
        Signals* handlers = Signals::handlers();
        [self selectButton:_skB];
        if ((handlers) && (handlers->onuKeeperClicked())) {
        }
    }
    - (void)svClicked:(id)sender {
        Signals* handlers = Signals::handlers();
        [self selectButton:_svB];
        if ((handlers) && (handlers->onuVaultClicked())) {
        }
    }
    - (void)swClicked:(id)sender {
        Signals* handlers = Signals::handlers();
        [self selectButton:_swB];
        if ((handlers) && (handlers->onuWebClicked())) {
        }
    }
    - (void)opClicked:(id)sender {
        Signals* handlers = Signals::handlers();
        [self selectButton:_opB];
        if ((handlers) && (handlers->onOptionsClicked()) && (_content)) {
            [_content popupContextMenu];
        }
    }
    - (void)sdClicked:(id)sender {
        Signals* handlers = Signals::handlers();
        [self selectButton:_sdB];
        if ((handlers) && (handlers->onShutdownClicked()) && (_application)) {
            [_application stop:self];
        }
    }

    - (void)brPressed:(NSEvent*)event {
        Signals* handlers = Signals::handlers();
        NSWindow* window = [self window];
        if ((handlers) && (handlers->onResizePressed()) && (window)) {
        }
    }
    - (void)brReleased:(NSEvent*)event {
        Signals* handlers = Signals::handlers();
        NSWindow* window = [self window];
        if ((handlers) && (handlers->onResizeReleased()) && (window)) {
        }
    }
    - (void)brEntered:(NSEvent*)theEvent{
        if ((_br) && (_brr) && (_br != _brr)) {
            LOG_DEBUG("_outBr = _br; _br = _brr...");
            _outBr = _br; _br = _brr;
        }
    }
    - (void)brExited:(NSEvent*)theEvent{
        if ((_br) && (_outBr) && (_br != _outBr)) {
            LOG_DEBUG("br = _outBr; _outBr = _brr...");
            _br = _outBr; _outBr = _brr;
        }
    }
    /*/

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)drawRect:(NSRect)rect {
        NSRect bounds = [self bounds];
        NSBezierPath* path = nil;

        [[NSColor clearColor] set];
        NSRectFill(bounds);

        [[NSColor ULUCIDITY_UI_COCOA_VIEW_BORDER_COLOR] set];
        if ((path = [NSBezierPath bezierPathWithRoundedRect:bounds
                                  xRadius:[_tl pixelsSize].width yRadius:[_tl pixelsSize].height])) {
            [path fill];
        }

        [_logo drawInRect:[self logoRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_min drawInRect:[self minRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_max drawInRect:[self maxRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];

        /*/
        [_sw drawInRect:[self swRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_sk drawInRect:[self skRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_sv drawInRect:[self svRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_sd drawInRect:[self sdRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_op drawInRect:[self opRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        /*/

        [_l drawInRect:[self lRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_t drawInRect:[self tRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_r drawInRect:[self rRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_b drawInRect:[self bRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];

        [_bl drawInRect:[self blRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_tl drawInRect:[self tlRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
        [_tr drawInRect:[self trRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];

        [_br drawInRect:[self brRect:bounds] fromRect:NSZeroRect operation:NSCompositeSourceAtop fraction:1];
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (NSRect) lRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = 0;
            rect.origin.y = rect.size.height - [_tl pixelsSize].height - [_l pixelsSize].height;
            rect.size.width = [_l pixelsSize].width;
            rect.size.height = [_l pixelsSize].height;
        }
        return rect;
    }
    - (NSRect) tRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = [_tl pixelsSize].width;
            rect.origin.y = rect.size.height - [_t pixelsSize].height;
            rect.size.width = [_t pixelsSize].width;
            rect.size.height = [_t pixelsSize].height;
        }
        return rect;
    }
    - (NSRect) rRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = rect.size.width - [_r pixelsSize].width;
            rect.origin.y = rect.size.height - [_tr pixelsSize].height - [_r pixelsSize].height;
            rect.size.width = [_r pixelsSize].width;
            rect.size.height = [_r pixelsSize].height;
        }
        return rect;
    }
    - (NSRect) bRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = [_bl pixelsSize].width;
            rect.origin.y = 0;
            rect.size.width = [_b pixelsSize].width;
            rect.size.height = [_b pixelsSize].height;
        }
        return rect;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (NSRect) blRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = 0;
            rect.origin.y = 0;
            rect.size.width = [_bl pixelsSize].width;
            rect.size.height = [_bl pixelsSize].height;
        }
        return rect;
    }
    - (NSRect) tlRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = 0;
            rect.origin.y = rect.size.height - [_tl pixelsSize].height;
            rect.size.width = [_tl pixelsSize].width;
            rect.size.height = [_tl pixelsSize].height;
        }
        return rect;
    }
    - (NSRect) trRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = rect.size.width - [_tr pixelsSize].width;
            rect.origin.y = rect.size.height - [_tr pixelsSize].height;
            rect.size.width = [_tr pixelsSize].width;
            rect.size.height = [_tr pixelsSize].height;
        }
        return rect;
    }
    - (NSRect) brRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = rect.size.width - [_br pixelsSize].width;
            rect.origin.y = 0;
            rect.size.width = [_br pixelsSize].width;
            rect.size.height = [_br pixelsSize].height;
        }
        return rect;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (NSRect)contentRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x += [_tl pixelsSize].width;
            rect.origin.y += [_bl pixelsSize].height;
            rect.size.width -= ([_tl pixelsSize].width + [_tr pixelsSize].width);
            rect.size.height -= ([_tl pixelsSize].height + [_bl pixelsSize].height);
        }
        return rect;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (NSRect)logoRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = ([_tl pixelsSize].width);
            rect.origin.y = (rect.size.height - [_tl pixelsSize].height + ([_tl pixelsSize].height - [_logo pixelsSize].height)/2);
            rect.size.width = [_logo pixelsSize].width;
            rect.size.height = [_logo pixelsSize].height;
        }
        return rect;
    }
    - (NSRect)minRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = (rect.size.width - [_tr pixelsSize].width - [_max size].width - [_min size].width);
            rect.origin.y = (rect.size.height - [_tr pixelsSize].height + ([_tr pixelsSize].height - [_min size].height)/2);
            rect.size.width = [_min size].width;
            rect.size.height = [_min size].height;
        }
        return rect;
    }
    - (NSRect)maxRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = (rect.size.width - [_tr pixelsSize].width - [_max size].width);
            rect.origin.y = (rect.size.height - [_tr pixelsSize].height + ([_tr pixelsSize].height - [_max size].height)/2);
            rect.size.width = [_max size].width;
            rect.size.height = [_max size].height;
        }
        return rect;
    }

    /*/
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (NSRect)swRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = ([_bl pixelsSize].width + _lsp);
            rect.origin.y = ([_bl pixelsSize].height - [_sw pixelsSize].height)/2;
            rect.size.width = [_sw pixelsSize].width;
            rect.size.height = [_sw pixelsSize].height;
        }
        return rect;
    }
    - (NSRect)svRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = ([_bl pixelsSize].width + [_sw pixelsSize].width + _lsp + _sp);
            rect.origin.y = ([_bl pixelsSize].height - [_sv pixelsSize].height)/2;
            rect.size.width = [_sv pixelsSize].width;
            rect.size.height = [_sv pixelsSize].height;
        }
        return rect;
    }
    - (NSRect)skRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = ([_bl pixelsSize].width + [_sk pixelsSize].width + [_sv pixelsSize].width + _lsp + _sp*2);
            rect.origin.y = ([_bl pixelsSize].height - [_sk pixelsSize].height)/2;
            rect.size.width = [_sk pixelsSize].width;
            rect.size.height = [_sk pixelsSize].height;
        }
        return rect;
    }
    - (NSRect)opRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = (rect.size.width - [_br pixelsSize].width - [_op pixelsSize].width - _rsp);
            rect.origin.y = ([_bl pixelsSize].height - [_op pixelsSize].height)/2;
            rect.size.width = [_op pixelsSize].width;
            rect.size.height = [_op pixelsSize].height;
        }
        return rect;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (NSRect)sdRect:(NSRect)rect {
        if ((_tl) && (_tr) && (_bl) && (_br)) {
            rect.origin.x = (rect.size.width - [_sd pixelsSize].width)/2;
            rect.origin.y = ([_bl pixelsSize].height - [_sd pixelsSize].height)/2;
            rect.size.width = [_sd pixelsSize].width;
            rect.size.height = [_sd pixelsSize].height;
        }
        return rect;
    }
    /*/
@end
