///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: GraphicContext.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_GRAPHICSURFACE_GRAPHICCONTEXT_HPP
#define ULUCIDITY_UI_GRAPHICSURFACE_GRAPHICCONTEXT_HPP

#include "uLucidity/UI/GraphicSurface/GraphicPixel.hpp"

namespace uLucidity {
namespace UI {

namespace Native {
namespace GraphicSurface {
class _EXPORT_CLASS GraphicContextInterface;
} // namespace GraphicSurface
} // namespace Native

namespace GraphicSurface {

typedef ImplementBase GraphicContextInterfaceImplements;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicContextInterface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicContextInterface
: virtual public GraphicContextInterfaceImplements {
public:
    typedef GraphicContextInterfaceImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void FillRectangle
    (int x, int y, int w, int h, const GraphicPixelInterface& color) {
    }
    virtual void FillRectangle(int x, int y, int w, int h) {
        const GraphicPixelInterface* foregroundColor = Foreground();
        if ((foregroundColor)) {
            FillRectangle(x,y, w,h, *foregroundColor);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawImage
    (int x, int y, int w, int h, int imageWidth, int imageHeight,
     int imageRowSize, int imagePixelSize, const void* imageData,
     GraphicImageFormat imageFormat, GraphicImageInterpolation imageInterpolation) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void SetForeground
    (const GraphicPixelInterface*& oldColor, const GraphicPixelInterface& toColor) {
    }
    virtual const GraphicPixelInterface* Foreground() const {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void SetBackground
    (const GraphicPixelInterface*& oldColor, const GraphicPixelInterface& toColor) {
    }
    virtual const GraphicPixelInterface* Background() const {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GraphicPixelInterface* AllocateColor
    (ColorChannel r, ColorChannel g, ColorChannel b, ColorChannel a) {
        return 0;
    }
    virtual GraphicPixelInterface* AllocateColor
    (ColorChannel r, ColorChannel g, ColorChannel b) {
        return 0;
    }
    virtual bool FreeColor(GraphicPixelInterface* color) {
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef GraphicContextInterface GraphicContextImplements;
typedef Base GraphicContextExtends;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicContext
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicContext
: virtual public GraphicContextImplements, public GraphicContextExtends {
public:
    typedef GraphicContextImplements Implements;
    typedef GraphicContextExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    GraphicContext(): m_foregroundColor(0), m_backgroundColor(0) {
    }
    virtual ~GraphicContext() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void SetForeground
    (const GraphicPixelInterface*& oldColor, const GraphicPixelInterface& toColor) {
        oldColor = m_foregroundColor;
        m_foregroundColor = &toColor;
    }
    virtual const GraphicPixelInterface* Foreground() const {
        return m_foregroundColor;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void SetBackground
    (const GraphicPixelInterface*& oldColor, const GraphicPixelInterface& toColor) {
        oldColor = m_backgroundColor;
        m_backgroundColor = &toColor;
    }
    virtual const GraphicPixelInterface* Background() const {
        return m_backgroundColor;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const GraphicPixelInterface *m_foregroundColor, *m_backgroundColor;
};

} // namespace GraphicSurface
} // namespace UI 
} // namespace uLucidity 

#endif // ULUCIDITY_UI_GRAPHICSURFACE_GRAPHICCONTEXT_HPP 
