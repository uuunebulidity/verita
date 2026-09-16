///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Image.mm
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/Image.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: Image
///////////////////////////////////////////////////////////////////////
@implementation Image

- (Image*)initWithContentsOfFile:(NSString*)fileName {
    NSArray *reps = nil;
    NSImageRep *rep = nil;

    if (([super initWithContentsOfFile:fileName])) {
        _pixelsSize = [self size];
        if ((reps  = [self representations])) {
            if ((rep = [reps objectAtIndex:0])) {
                _pixelsSize.width = [rep pixelsWide];
                _pixelsSize.height = [rep pixelsHigh];
            }
        }
        return self;
    }
    return nil;
}
@end
