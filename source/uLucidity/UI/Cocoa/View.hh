///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: View.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_VIEW_HH
#define ULUCIDITY_UI_COCOA_VIEW_HH

#include "uLucidity/UI/Cocoa/Images.hh"
#include "uLucidity/UI/Cocoa/Content.hh"
#include "uLucidity/UI/Cocoa/Button.hh"

#define ULUCIDITY_UI_COCOA_VIEW_BORDER_COLOR blackColor
#define ULUCIDITY_UI_COCOA_VIEW_SPACEING 4
#define ULUCIDITY_UI_COCOA_VIEW_LSPACEING 10
#define ULUCIDITY_UI_COCOA_VIEW_RSPACEING 20

///////////////////////////////////////////////////////////////////////
/// Interface: View
///////////////////////////////////////////////////////////////////////
@interface View: NSView {
    }
    @property (assign) NSApplication* application;
    @property (assign) Images* images;
    @property (assign) Content* content;

    @property (assign) NSImage* l;
    @property (assign) NSImage* t;
    @property (assign) NSImage* r;
    @property (assign) NSImage* b;

    @property (assign) NSImage* tl;
    @property (assign) NSImage* tr;
    @property (assign) NSImage* bl;

    @property (assign) NSImage* br;
    @property (assign) NSImage* brr;
    @property (assign) NSImage* brs;
    @property (assign) NSImage* outBr;
    @property (assign) Button* brB;

    @property (assign) NSImage* logo;
    @property (assign) Button* logoB;

    @property (assign) NSImage* max;
    @property (assign) NSImage* maxr;
    @property (assign) NSImage* maxs;
    @property (assign) Button* maxB;

    @property (assign) NSImage* min;
    @property (assign) NSImage* minr;
    @property (assign) NSImage* mins;
    @property (assign) Button* minB;

    @property (assign) NSImage* contentImage;
    @property (assign) Button* contentB;

    /*/
    @property (assign) NSImage* sk;
    @property (assign) NSImage* skr;
    @property (assign) NSImage* sks;
    @property (assign) Button* skB;
    @property (assign) NSImage* sv;
    @property (assign) NSImage* svr;
    @property (assign) NSImage* svs;
    @property (assign) Button* svB;
    @property (assign) NSImage* sw;
    @property (assign) NSImage* swr;
    @property (assign) NSImage* sws;
    @property (assign) Button* swB;

    @property (assign) NSImage* op;
    @property (assign) NSImage* opr;
    @property (assign) NSImage* ops;
    @property (assign) Button* opB;

    @property (assign) NSImage* sd;
    @property (assign) NSImage* sdr;
    @property (assign) NSImage* sds;
    @property (assign) Button* sdB;
    /*/

    @property (assign) Button* selectedButton;

    @property (assign) int sp;
    @property (assign) int lsp;
    @property (assign) int rsp;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (View*)initWithRect:(NSRect)rect
             application:(NSApplication*)application images:(Images*)images;
    - (void)drawRect:(NSRect)rect;
    - (Image*)setContentImage;
@end

#endif // ULUCIDITY_UI_COCOA_VIEW_HH 
