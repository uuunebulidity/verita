///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: main.mm
///
/// Author: $author$
///   Date: 11/1/2022, 10/9/2025
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/Main.hh"
#include "uLucidity/UI/Cocoa/Logger.hh"

#define ULUCIDITY_UI_PLUGIN_PREFIX "lib"
#define ULUCIDITY_UI_PLUGIN_SUFFIX ".dylib"
#define ULUCIDITY_UI_PLUGIN_NAME "uDentityPlugin"

///////////////////////////////////////////////////////////////////////
/// Implentation: Main
///////////////////////////////////////////////////////////////////////
@implementation Main
    - (id<Main>)init:(NSApplication*)application {
        _application = application;
        _pluginLibrary = nil;
        _plugin = nil;
        _images = nil;
        _window = nil;
        _minWindowSize = NSMakeSize
        (ULUCIDITY_UI_COCOA_WINDOW_MIN_WIDTH,
         ULUCIDITY_UI_COCOA_WINDOW_MIN_HEIGHT);
        _maxWindowSize = NSMakeSize
        (ULUCIDITY_UI_COCOA_WINDOW_MAX_WIDTH,
         ULUCIDITY_UI_COCOA_WINDOW_MAX_HEIGHT);
        [self loadPlugin];
        return self;
    }
    - (void)destroy {
        [self unloadPlugin];
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (uLucidity::UI::PluginLibrary*)loadPlugin {
        const char *pluginPrefix = ULUCIDITY_UI_PLUGIN_PREFIX,
                   *pluginSuffux = ULUCIDITY_UI_PLUGIN_SUFFIX,
                   *pluginName = ULUCIDITY_UI_PLUGIN_NAME,
                   *pluginChars = 0;
        if ((pluginPrefix) && (pluginSuffux) && (pluginName)) {
            ::std::string name(pluginPrefix);
            name.append(pluginName);
            name.append(pluginSuffux);
            if ((pluginChars = name.c_str())) {

                LOG_DEBUG("new uLucidity::UI::PluginLibrary()...");
                if ((_pluginLibrary = new uLucidity::UI::PluginLibrary())) {

                    LOG_DEBUG("_pluginLibrary->Open(pluginChars)...");
                    if ((_pluginLibrary->Open(pluginChars))) {

                        LOG_DEBUG("_pluginLibrary->AcquirePlugin()...");
                        if ((_plugin = _pluginLibrary->AcquirePlugin())) {
                            [self forwardPluginSignals];
                            return _pluginLibrary;
                        }
                        LOG_DEBUG("_pluginLibrary->Close()...");
                        _pluginLibrary->Close();
                    }
                    LOG_DEBUG("delete _pluginLibrary...");
                    delete _pluginLibrary;
                    _pluginLibrary = nil;
                }
            }
        }
        return _pluginLibrary;
    }
    - (void)unloadPlugin {
        if ((_pluginLibrary)) {
            if ((_plugin)) {
                [self reversePluginSignals];
                LOG_DEBUG("_pluginLibrary->ReleasePlugin(_plugin)...");
                if (!(_pluginLibrary->ReleasePlugin(_plugin))) {
                }
                _plugin = nil;
            }
            LOG_DEBUG("_pluginLibrary->Close()...");
            _pluginLibrary->Close();

            LOG_DEBUG("delete _pluginLibrary...");
            delete _pluginLibrary;
            _pluginLibrary = nil;
        }
    }
    - (void)forwardPluginSignals {
        if ((_plugin)) {
            Signals* handlers = 0;
            if ((handlers = Signals::handlers())) {
                LOG_DEBUG("handlers->ForwardPluginSignalsTo(_plugin)...");
                handlers->ForwardPluginSignalsTo(_plugin);
            }
        }
    }
    - (void)reversePluginSignals {
        if ((_plugin)) {
            Signals* handlers = 0;
            if ((handlers = Signals::handlers())) {
                LOG_DEBUG("handlers->ForwardPluginSignalsTo(0)...");
                handlers->ForwardPluginSignalsTo(0);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (Window*)createWindow:(NSRect)contentRect {
        Window* window = nil;
        NSArray* screens = nil;
        NSScreen* screen = nil;
        NSRect screenRect;

        LOG_DEBUG("[[Images alloc] init:_application]...");
        if ((_images = [[Images alloc] init:_application])) {

            if ((screens = [NSScreen screens])) {
                if ((screen = [screens objectAtIndex:0])) {
                    screenRect = [screen visibleFrame];

                    contentRect.size.width = ([[_images tl] pixelsSize].width + [[_images t] pixelsSize].width + [[_images tr] pixelsSize].width);
                    if (screenRect.size.width < contentRect.size.width) {
                        contentRect.size.width = screenRect.size.width;
                    }
                    contentRect.size.height = ([[_images tl] pixelsSize].height + [[_images l] pixelsSize].height + [[_images bl] pixelsSize].height);
                    if (screenRect.size.height < contentRect.size.height) {
                        contentRect.size.height = screenRect.size.height;
                    }
                }
            }
            LOG_DEBUG("((window = [self allocWindow:contentRect]))...");
            if ((window = [self allocWindow:contentRect])) {
                LOG_DEBUG("...((" << String(window) << " = [self allocWindow:contentRect]))");
                [window setMinSize:_minWindowSize];
                [window setMaxSize:_maxWindowSize];
                if ((_plugin)) {
                    if ((_plugin->FailedOnLoadImage())) {
                        if ((_plugin->NoFillContentRectangle())) {
                            LOG_DEBUG("[window setContentImage]...");
                            [window setContentImage];
                        }
                    }
                } else {
                    LOG_DEBUG("[window setContentImage]...");
                    [window setContentImage];
                }
                LOG_DEBUG("[window setNotResizeable]...");
                [window setNotResizeable];
            } else {
                LOG_ERROR("...failed on ((" << String(window) << " = [self allocWindow:contentRect]))");
            }
        } else {
        }
        return window;
    }
    - (Window*)allocWindow:(NSRect)contentRect {
        Window* window = nil;
        LOG_DEBUG("[[Window alloc] initWithRect:contentRect application:_application images:_images]...");
        if ((window = [[Window alloc] initWithRect:contentRect application:_application images:_images])) {
            LOG_DEBUG("..." << String(window) << " = [[Window alloc] initWithRect:contentRect application:_application images:_images]");
        } else {
            LOG_ERROR("...failed " << String(window) << " = [[Window alloc] initWithRect:contentRect application:_application images:_images]");
        }
        return window;
    }
    - (NSRect)contentRect {
        return NSMakeRect
        (0,0, _minWindowSize.width,_minWindowSize.height);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (NSMenu*)createMenu:(NSApplication*)application {
        NSMenu *menubar = nil, *appMenu = nil;
        NSMenuItem *appMenuItem = nil, *quitMenuItem = nil;
        NSString *appName = nil, *quitTitle = nil;

        if ((appName = [[NSProcessInfo processInfo] processName])) {
            if ((quitTitle = [@ULUCIDITY_UI_COCOA_MENU_QUIT_LABEL stringByAppendingString:appName])) {
                if ((quitMenuItem = [[[NSMenuItem alloc] initWithTitle:quitTitle action:@selector(terminate:) keyEquivalent:@ULUCIDITY_UI_COCOA_MENU_QUIT_KEY] autorelease])) {
                    if ((appMenu = [[[NSMenu alloc] init] autorelease])) {
                        [appMenu addItem:quitMenuItem];

                        if ((appMenuItem = [[[NSMenuItem alloc] init] autorelease])) {
                            [appMenuItem setSubmenu:appMenu];

                            if ((menubar = [[[NSMenu alloc] init] autorelease])) {
                                [menubar addItem:appMenuItem];
                                [application setActivationPolicy:NSApplicationActivationPolicyRegular];
                                [application activateIgnoringOtherApps:NO];
                                [application setMainMenu:menubar];
                                return menubar;
                            }
                        }
                    }
                }
            }
        }
        return nil;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (int)runApplication:(NSApplication*)application {
        int err = 0;
        LOG_DEBUG("[application activateIgnoringOtherApps:YES]...");
        [application activateIgnoringOtherApps:YES];
        LOG_DEBUG("[application = " << String(application) << " run]...");
        [application run];
        LOG_DEBUG("...[application = " << String(application) << " run]");
        return err;
    }
    - (int)run:(int)argc argv:(char**)argv env:(char**)env {
        NSRect contentRect = [self contentRect];
        int err = 0;

        LOG_DEBUG("[self createWindow:contentRect]...");
        if ((_window = [self createWindow:contentRect])) {
            LOG_DEBUG("..." << String(_window) << " = [self createWindow:contentRect]");

            LOG_DEBUG("[self createMenu:_application]...");
            [self createMenu:_application];

            LOG_DEBUG("[self runApplication:_application]...");
            err = [self runApplication:_application];
            LOG_DEBUG("..." << err << " = [self runApplication:_application]");
        } else {
            LOG_ERROR("...failed " << String(_window) << " = [self createWindow:contentRect]");
        }
        return err;
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: MainCreator
///////////////////////////////////////////////////////////////////////
@implementation MainCreator
+ (id<Main>)create:(NSApplication*)application {
    id<Main> main = nil;

    LOG_DEBUG("[[Main alloc] init:application = " << String(application) << "]...");
    if ((main = [[Main alloc] init:application])) {
        LOG_DEBUG("..." << String(main) << " = [[Main alloc] init:application = " << String(application) << "]");
    } else {
        LOG_ERROR("...failed " << String(main) << " = [[Main alloc] init:application = " << String(application) << "]");
    }
    return main;
}
@end

/*
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main(int argc, char **argv, char **env) {
    typedef String string;
    int err = 1;
    NSAutoreleasePool *autoreleasePool = nil;
    NSApplication* sharedApplication = nil;
    id<Main> main = nil;

    LOG_DEBUG("[[AutoreleasePool alloc] init]...");
    if ((autoreleasePool = [[NSAutoreleasePool alloc] init])) {
        LOG_DEBUG("..." << string(autoreleasePool) << " = [[NSAutoreleasePool alloc] init]");

        LOG_DEBUG("[NSApplication sharedApplication]...");
        if ((sharedApplication = [NSApplication sharedApplication])) {
            LOG_DEBUG("..." << string(sharedApplication) << " = [NSApplication sharedApplication]");

            LOG_DEBUG("[maincreator create:sharedApplication]...");
            if ((main = [MainCreator create:sharedApplication])) {
                LOG_DEBUG("..." << string(main) << " = [MainCreator create:sharedApplication]");

                LOG_DEBUG("[main run:argc argv:argv env:env]...");
                err = [main run:argc argv:argv env:env];
                LOG_DEBUG("..." << err << " = [main run:argc argv:argv env:env]");

                LOG_DEBUG("[main = " << string(main) << " destroy]...");
                [main destroy];
            } else {
                LOG_ERROR("...failed " << string(main) << " = [MainCreator create:sharedApplication]");
            }
        } else {
            LOG_ERROR("...failed" << string(sharedApplication) << " = [NSApplication sharedApplication]");
        }
        LOG_DEBUG("[autoreleasePool = " << string(autoreleasePool) << " release]...");
        [autoreleasePool release];
    } else {
        LOG_ERROR("...failed " << string(autoreleasePool) << " = [[NSAutoreleasePool alloc] init]");
    }
    return err;
}
*/