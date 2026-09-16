///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Images.mm
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/Images.hh"
#include "uLucidity/UI/Cocoa/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: Images
///////////////////////////////////////////////////////////////////////
@implementation Images

    - (Images*)init:(NSApplication*)application {
        if (([super init])) {
            _application = application;

            if (([self initNames])) {

                if (([self loadImages])) {
                    return self;
                }
            }
        }
        return nil;
    }

    - (Images*)initNames {
        _tlName = @ULUCIDITY_UI_COCOA_IMAGE_TOP_LEFT;
        _trName = @ULUCIDITY_UI_COCOA_IMAGE_TOP_RIGHT;
        _blName = @ULUCIDITY_UI_COCOA_IMAGE_BOTTOM_LEFT;

        _brName = @ULUCIDITY_UI_COCOA_IMAGE_BOTTOM_RIGHT;
        _brrName = @ULUCIDITY_UI_COCOA_IMAGE_BOTTOM_RIGHTR;
        _brsName = @ULUCIDITY_UI_COCOA_IMAGE_BOTTOM_RIGHTS;

        _lName = @ULUCIDITY_UI_COCOA_IMAGE_LEFT;
        _tName = @ULUCIDITY_UI_COCOA_IMAGE_TOP;
        _rName = @ULUCIDITY_UI_COCOA_IMAGE_RIGHT;
        _bName = @ULUCIDITY_UI_COCOA_IMAGE_BOTTOM;

        _logoName = @ULUCIDITY_UI_COCOA_IMAGE_TOP_LOGO;
        _contentName = @ULUCIDITY_UI_COCOA_IMAGE_CONTENT;

        _resName = @ULUCIDITY_UI_COCOA_IMAGE_RES;
        _resrName = @ULUCIDITY_UI_COCOA_IMAGE_RESR;
        _ressName = @ULUCIDITY_UI_COCOA_IMAGE_RESS;

        _maxName = @ULUCIDITY_UI_COCOA_IMAGE_MAX;
        _maxrName = @ULUCIDITY_UI_COCOA_IMAGE_MAXR;
        _maxsName = @ULUCIDITY_UI_COCOA_IMAGE_MAXS;

        _minName = @ULUCIDITY_UI_COCOA_IMAGE_MIN;
        _minrName = @ULUCIDITY_UI_COCOA_IMAGE_MINR;
        _minsName = @ULUCIDITY_UI_COCOA_IMAGE_MINS;

        /*/
        _skName = @ULUCIDITY_UI_COCOA_IMAGE_U_KEEPER;
        _skrName = @ULUCIDITY_UI_COCOA_IMAGE_U_KEEPERR;
        _sksName = @ULUCIDITY_UI_COCOA_IMAGE_U_KEEPERS;

        _svName = @ULUCIDITY_UI_COCOA_IMAGE_U_VAULT;
        _svrName = @ULUCIDITY_UI_COCOA_IMAGE_U_VAULTR;
        _svsName = @ULUCIDITY_UI_COCOA_IMAGE_U_VAULTS;

        _swName = @ULUCIDITY_UI_COCOA_IMAGE_U_WEB;
        _swrName = @ULUCIDITY_UI_COCOA_IMAGE_U_WEBR;
        _swsName = @ULUCIDITY_UI_COCOA_IMAGE_U_WEBS;

        _opName = @ULUCIDITY_UI_COCOA_IMAGE_OPTIONS;
        _oprName = @ULUCIDITY_UI_COCOA_IMAGE_OPTIONSR;
        _opsName = @ULUCIDITY_UI_COCOA_IMAGE_OPTIONSS;

        _sdName = @ULUCIDITY_UI_COCOA_IMAGE_SHUTDOWN;
        _sdrName = @ULUCIDITY_UI_COCOA_IMAGE_SHUTDOWNR;
        _sdsName = @ULUCIDITY_UI_COCOA_IMAGE_SHUTDOWNS;
        /*/
        return self;
    }

    - (Images*)loadImages {
        _l = [self loadImage:[self lName]];
        _t = [self loadImage:[self tName]];
        _r = [self loadImage:[self rName]];
        _b = [self loadImage:[self bName]];

        _tl = [self loadImage:[self tlName]];
        _tr = [self loadImage:[self trName]];
        _bl = [self loadImage:[self blName]];

        _br = [self loadImage:[self brName]];
        _brr = [self loadImage:[self brrName]];
        _brs = [self loadImage:[self brsName]];

        _logo = [self loadImage:[self logoName]];
        _content = [self loadImage:[self contentName]];

        _res = [self loadImage:[self resName]];
        _resr = [self loadImage:[self resrName]];
        _ress = [self loadImage:[self ressName]];

        _max = [self loadImage:[self maxName]];
        _maxr = [self loadImage:[self maxrName]];
        _maxs = [self loadImage:[self maxsName]];

        _min = [self loadImage:[self minName]];
        _minr = [self loadImage:[self minrName]];
        _mins = [self loadImage:[self minsName]];

        /*/
        _sk = [self loadImage:[self skName]];
        _skr = [self loadImage:[self skrName]];
        _sks = [self loadImage:[self sksName]];

        _sv = [self loadImage:[self svName]];
        _svr = [self loadImage:[self svrName]];
        _svs = [self loadImage:[self svsName]];

        _sw = [self loadImage:[self swName]];
        _swr = [self loadImage:[self swrName]];
        _sws = [self loadImage:[self swsName]];

        _op = [self loadImage:[self opName]];
        _opr = [self loadImage:[self oprName]];
        _ops = [self loadImage:[self opsName]];

        _sd = [self loadImage:[self sdName]];
        _sdr = [self loadImage:[self sdrName]];
        _sds = [self loadImage:[self sdsName]];
        /*/
        return self;
    }

    - (Image*)loadImage:(NSString*)named {
        Image* image = nil;

        if ((named)) {
            const char* chars = [named cStringUsingEncoding:NSUTF8StringEncoding];

            if ((image = [[Image alloc] initWithContentsOfFile:named])) {
                unsigned w = 0, h = 0;
                if ((w = [image pixelsSize].width) && (h = [image pixelsSize].height)) {
                    LOG_DEBUG("...[...:named = \"" << String(chars) << "\"] w = " << w << ", h = " << h << "");
                } else {
                    [image release];
                    image = nil;
                }
            } else {
                LOG_ERROR("...failed on [[Image alloc] initWithContentsOfFile:named = \"" << String(chars) << "\"]");
            }
        }
        return image;
    }
@end
