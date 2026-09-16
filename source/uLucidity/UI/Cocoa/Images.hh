///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Images.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_IMAGES_HH
#define ULUCIDITY_UI_COCOA_IMAGES_HH

#include "uLucidity/UI/Cocoa/Image.hh"

#define ULUCIDITY_UI_COCOA_IMAGE_TOP_LOGO      "toplogo.png"
#define ULUCIDITY_UI_COCOA_IMAGE_CONTENT      "content.png"

#define ULUCIDITY_UI_COCOA_IMAGE_TOP_LEFT      "topleft_n.png"
#define ULUCIDITY_UI_COCOA_IMAGE_TOP_RIGHT     "topright_n.png"
#define ULUCIDITY_UI_COCOA_IMAGE_BOTTOM_LEFT   "bottomleft_n.png"

#define ULUCIDITY_UI_COCOA_IMAGE_BOTTOM_RIGHT  "bottomright_n.png"
#define ULUCIDITY_UI_COCOA_IMAGE_BOTTOM_RIGHTR "bottomright_nr.png"
#define ULUCIDITY_UI_COCOA_IMAGE_BOTTOM_RIGHTS "bottomright_ns.png"

#define ULUCIDITY_UI_COCOA_IMAGE_LEFT   "left.png"
#define ULUCIDITY_UI_COCOA_IMAGE_TOP    "top.png"
#define ULUCIDITY_UI_COCOA_IMAGE_RIGHT  "right.png"
#define ULUCIDITY_UI_COCOA_IMAGE_BOTTOM "bottom.png"

///
/// There are three images per button.  The one that ends in "r" is the
/// roll-over version.  The one that ends in "s" is the selected version.  A few
/// of the buttons do not have three states (shutdown, min, max and restore).
///

#define ULUCIDITY_UI_COCOA_IMAGE_MAX    "sysmax.png"
#define ULUCIDITY_UI_COCOA_IMAGE_MAXR    "sysmaxr.png"
#define ULUCIDITY_UI_COCOA_IMAGE_MAXS    "sysmaxs.png"

#define ULUCIDITY_UI_COCOA_IMAGE_MIN    "sysmin.png"
#define ULUCIDITY_UI_COCOA_IMAGE_MINR    "sysminr.png"
#define ULUCIDITY_UI_COCOA_IMAGE_MINS    "sysmins.png"

#define ULUCIDITY_UI_COCOA_IMAGE_RES    "sysres.png"
#define ULUCIDITY_UI_COCOA_IMAGE_RESR    "sysresr.png"
#define ULUCIDITY_UI_COCOA_IMAGE_RESS    "sysress.png"

/*/
#define ULUCIDITY_UI_COCOA_IMAGE_U_KEEPER "ukeeper.png"
#define ULUCIDITY_UI_COCOA_IMAGE_U_KEEPERR "ukeeperr.png"
#define ULUCIDITY_UI_COCOA_IMAGE_U_KEEPERS "ukeepers.png"

#define ULUCIDITY_UI_COCOA_IMAGE_U_VAULT  "uvault.png"
#define ULUCIDITY_UI_COCOA_IMAGE_U_VAULTR  "uvaultr.png"
#define ULUCIDITY_UI_COCOA_IMAGE_U_VAULTS  "uvaults.png"

#define ULUCIDITY_UI_COCOA_IMAGE_U_WEB    "uweb.png"
#define ULUCIDITY_UI_COCOA_IMAGE_U_WEBR    "uwebr.png"
#define ULUCIDITY_UI_COCOA_IMAGE_U_WEBS    "uwebs.png"

#define ULUCIDITY_UI_COCOA_IMAGE_OPTIONS    "options.png"
#define ULUCIDITY_UI_COCOA_IMAGE_OPTIONSR    "optionsr.png"
#define ULUCIDITY_UI_COCOA_IMAGE_OPTIONSS    "optionss.png"

#define ULUCIDITY_UI_COCOA_IMAGE_SHUTDOWN      "shutdown.png"
#define ULUCIDITY_UI_COCOA_IMAGE_SHUTDOWNR     "shutdownr.png"
#define ULUCIDITY_UI_COCOA_IMAGE_SHUTDOWNS     "shutdowns.png"
/*/

///////////////////////////////////////////////////////////////////////
/// Interface: Images
///////////////////////////////////////////////////////////////////////
@interface Images: NSObject {
  }
    @property (assign) NSApplication* application;

    @property (assign) NSString* lName;
    @property (assign) NSString* tName;
    @property (assign) NSString* rName;
    @property (assign) NSString* bName;

    @property (assign) NSString* tlName;
    @property (assign) NSString* trName;
    @property (assign) NSString* blName;
    @property (assign) NSString* brName;
    @property (assign) NSString* brrName;
    @property (assign) NSString* brsName;

    @property (assign) NSString* logoName;
    @property (assign) NSString* contentName;

    @property (assign) NSString* resName;
    @property (assign) NSString* resrName;
    @property (assign) NSString* ressName;

    @property (assign) NSString* maxName;
    @property (assign) NSString* maxrName;
    @property (assign) NSString* maxsName;

    @property (assign) NSString* minName;
    @property (assign) NSString* minrName;
    @property (assign) NSString* minsName;

    /*/
    @property (assign) NSString* skName;
    @property (assign) NSString* skrName;
    @property (assign) NSString* sksName;

    @property (assign) NSString* svName;
    @property (assign) NSString* svrName;
    @property (assign) NSString* svsName;

    @property (assign) NSString* swName;
    @property (assign) NSString* swrName;
    @property (assign) NSString* swsName;

    @property (assign) NSString* opName;
    @property (assign) NSString* oprName;
    @property (assign) NSString* opsName;

    @property (assign) NSString* sdName;
    @property (assign) NSString* sdrName;
    @property (assign) NSString* sdsName;
    /*/

    @property (assign) Image* l;
    @property (assign) Image* t;
    @property (assign) Image* r;
    @property (assign) Image* b;

    @property (assign) Image* tl;
    @property (assign) Image* tr;
    @property (assign) Image* bl;

    @property (assign) Image* br;
    @property (assign) Image* brr;
    @property (assign) Image* brs;

    @property (assign) Image* logo;
    @property (assign) Image* content;

    @property (assign) Image* max;
    @property (assign) Image* maxr;
    @property (assign) Image* maxs;

    @property (assign) Image* min;
    @property (assign) Image* minr;
    @property (assign) Image* mins;

    @property (assign) Image* res;
    @property (assign) Image* resr;
    @property (assign) Image* ress;

    /*/
    @property (assign) Image* sk;
    @property (assign) Image* skr;
    @property (assign) Image* sks;

    @property (assign) Image* sv;
    @property (assign) Image* svr;
    @property (assign) Image* svs;

    @property (assign) Image* sw;
    @property (assign) Image* swr;
    @property (assign) Image* sws;

    @property (assign) Image* op;
    @property (assign) Image* opr;
    @property (assign) Image* ops;

    @property (assign) Image* sd;
    @property (assign) Image* sdr;
    @property (assign) Image* sds;
    /*/

    - (Images*)init:(NSApplication*)application;
@end

#endif // ULUCIDITY_UI_COCOA_IMAGES_HH 
