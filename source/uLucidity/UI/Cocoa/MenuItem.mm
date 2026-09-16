///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: MenuItem.mm
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/Menu.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: MenuItem
///////////////////////////////////////////////////////////////////////
@implementation MenuItem

    - (MenuItem*)initWithTitle:(NSString*)title
                 keyEquivalent:(NSString*)keyEquivalent
                 target:(NSObject*)target action:(SEL)action enabled:(BOOL)enabled {

        if (([super initWithTitle:title action:action keyEquivalent:keyEquivalent])) {
            [self setTarget:target];
            [self setEnabled:enabled];
            return self;
        }
        return nil;
    }
@end
        

