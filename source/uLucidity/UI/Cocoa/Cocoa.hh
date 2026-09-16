///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Cocoa.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_COCOA_HH
#define ULUCIDITY_UI_COCOA_COCOA_HH

#include <Foundation/Foundation.h>
#include <Cocoa/Cocoa.h>

typedef NSUInteger NSWindowStyleMask;
enum {
    DefaultDesktopWindowMask
    = NSTitledWindowMask | NSClosableWindowMask
    | NSMiniaturizableWindowMask | NSResizableWindowMask
};
enum {
    DefaultDesktopWindowBacking = NSBackingStoreBuffered
};

#endif // ULUCIDITY_UI_COCOA_COCOA_HH
