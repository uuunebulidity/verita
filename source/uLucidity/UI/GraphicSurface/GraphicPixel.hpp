///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: GraphicPixel.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_GRAPHICSURFACE_GRAPHICPIXEL_HPP
#define ULUCIDITY_UI_GRAPHICSURFACE_GRAPHICPIXEL_HPP

#include "uLucidity/UI/GraphicImage.hpp"

namespace uLucidity {
namespace UI {

namespace Native {
namespace GraphicSurface {
class _EXPORT_CLASS GraphicPixelInterface;
} // namespace GraphicSurface
} // namespace Native

namespace GraphicSurface {

typedef ImplementBase GraphicPixelInterfaceImplements;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicPixelInterface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicPixelInterface
: virtual public GraphicPixelInterfaceImplements {
public:
    typedef GraphicPixelInterfaceImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Native::GraphicSurface::GraphicPixelInterface*
    NativeGraphicPixelInterface() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef GraphicPixelInterface GraphicPixelImplements;
typedef Base GraphicPixelExtends;
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
    GraphicPixel(ColorChannel r, ColorChannel g, ColorChannel b, ColorChannel a) {
    }
    GraphicPixel(ColorChannel r, ColorChannel g, ColorChannel b) {
    }
    GraphicPixel() {
    }
    virtual ~GraphicPixel() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace GraphicSurface
} // namespace UI 
} // namespace uLucidity 

#endif // ULUCIDITY_UI_GRAPHICSURFACE_GRAPHICPIXEL_HPP
