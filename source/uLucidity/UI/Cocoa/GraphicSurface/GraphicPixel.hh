///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: GrpahicPixel.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_GRAPHICSURFACE_GRAPHICPIXEL_HH
#define ULUCIDITY_UI_COCOA_GRAPHICSURFACE_GRAPHICPIXEL_HH

#include "uLucidity/UI/Cocoa/Cocoa.hh"
#include "uLucidity/UI/GraphicSurface/GraphicPixel.hpp"
#include "uLucidity/UI/Cocoa/Logger.hh"

namespace uLucidity {
namespace UI {

namespace Cocoa {
namespace GraphicSurface {

class _EXPORT_CLASS GraphicPixel;

} // namespace GraphicSurface
} // namespace Cocoa

namespace Native {
namespace GraphicSurface {

typedef UI::GraphicSurface::GraphicPixelInterface GraphicPixelInterfaceImplements;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicPixelInterface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicPixelInterface
: virtual public GraphicPixelInterfaceImplements {
public:
    typedef GraphicPixelInterfaceImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator NSColor*() const {
        return nil;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GraphicPixelInterface* NativeGraphicPixelInterface() const {
        return (GraphicPixelInterface*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Cocoa::GraphicSurface::GraphicPixel* NativeGraphicPixel() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace GraphicSurface
} // namespace Native

namespace Cocoa {
namespace GraphicSurface {

typedef Native::GraphicSurface::GraphicPixelInterface GraphicPixelInterface;
typedef GraphicPixelInterface GraphicPixelImplements;
typedef UI::GraphicSurface::GraphicPixel GraphicPixelExtends;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicPixel
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicPixel
: virtual public GraphicPixelImplements, public GraphicPixelExtends {
public:
    typedef GraphicPixelImplements Implements;
    typedef GraphicPixelExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    GraphicPixel
    (ColorChannel r, ColorChannel g, ColorChannel b, ColorChannel a)
    : m_color(nil) {
        m_color = MakeColor(r,g,b,a);
    }
    GraphicPixel(ColorChannel r, ColorChannel g, ColorChannel b)
    : m_color(nil) {
        m_color = MakeColor(r,g,b);
    }
    GraphicPixel(): m_color(nil) {
    }
    virtual ~GraphicPixel() {
        if ((m_color)) {
            LOG_DEBUG("[m_color release]...");
            [m_color release];
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual NSColor* MakeColor
    (ColorChannel r, ColorChannel g, ColorChannel b, ColorChannel a) const {
        float red = ((float)r),
              green = ((float)g),
              blue = ((float)b),
              alpha = ((float)a);
        NSColor* color = nil;
        LOG_DEBUG("[NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha] retain]...");
        if ((color = [[NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha] retain])) {
            return color;
        }
        return nil;
    }
    virtual NSColor* MakeColor
    (ColorChannel r, ColorChannel g, ColorChannel b) const {
        float red = ((float)r),
              green = ((float)g),
              blue = ((float)b),
              alpha = 1;
        NSColor* color = nil;
        LOG_DEBUG("[[NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha] retain]...");
        if ((color = [[NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha] retain])) {
            return color;
        }
        return nil;
    }
    virtual operator NSColor*() const {
        return m_color;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GraphicPixel* NativeGraphicPixel() const {
        return (GraphicPixel*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    NSColor* m_color;
};

} // namespace GraphicSurface
} // namespace Cocoa 

} // namespace UI
} // namespace uLucidity 

#endif // ULUCIDITY_UI_COCOA_GRAPHICSURFACE_GRAPHICPIXEL_HH 
