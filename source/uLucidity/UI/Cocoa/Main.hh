///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Main.hh
///
/// Author: $author$
///   Date: 11/1/2022, 10/9/2025
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_MAIN_HH
#define ULUCIDITY_UI_COCOA_MAIN_HH

#include "uLucidity/UI/Cocoa/ApplicationDelegate.hh"
#include "uLucidity/UI/Cocoa/Window.hh"
#include "uLucidity/UI/Cocoa/View.hh"
#include "uLucidity/UI/PluginLibrary.hpp"
#include "uLucidity/UI/Plugin.hpp"
#include "uLucidity/OS/DLibrary.hpp"

///////////////////////////////////////////////////////////////////////
/// Protocol: Main
///////////////////////////////////////////////////////////////////////
@protocol Main
    - (int)run:(int)argc argv:(char**)argv env:(char**)env;
    - (void)destroy;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: Main
///////////////////////////////////////////////////////////////////////
@interface Main: NSObject <Main> {
    }
    @property (assign) NSApplication* application;
    @property (assign) Images* images;
    @property (assign) Window* window;
    @property (assign) NSSize minWindowSize;
    @property (assign) NSSize maxWindowSize;
    @property (assign) uLucidity::UI::PluginLibrary* pluginLibrary;
    @property (assign) uLucidity::UI::Plugin* plugin;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (id<Main>)init:(NSApplication*)application;
    - (Window*)createWindow:(NSRect)contentRect;
    - (Window*)allocWindow:(NSRect)contentRect;
    - (NSRect)contentRect;
    - (int)runApplication:(NSApplication*)application;
    - (int)run:(int)argc argv:(char**)argv env:(char**)env;
    - (void)destroy;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: MainCreator
///////////////////////////////////////////////////////////////////////
@interface MainCreator: NSObject {
    }
    + (id<Main>)create:(NSApplication*)application;
@end

#endif // ULUCIDITY_UI_COCOA_MAIN_HH 
