///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: GrpahicContext.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_GRAPHICSURFACE_GRAPHICCONTEXT_HH
#define ULUCIDITY_UI_COCOA_GRAPHICSURFACE_GRAPHICCONTEXT_HH

#include "uLucidity/UI/Cocoa/GraphicSurface/GraphicPixel.hh"
#include "uLucidity/UI/GraphicSurface/GraphicContext.hpp"
#include "uLucidity/UI/Cocoa/Logger.hh"

namespace uLucidity {
namespace UI {

namespace Native {
namespace GraphicSurface {
typedef UI::GraphicSurface::GraphicContextInterface GraphicContextInterfaceImplements;
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
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace GraphicSurface
} // namespace Native

namespace Cocoa {
namespace GraphicSurface {

typedef Native::GraphicSurface::GraphicContextInterface GraphicContextInterface;
typedef GraphicContextInterface GraphicContextImplements;
typedef UI::GraphicSurface::GraphicContext GraphicContextExtends;
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
    GraphicContext(NSView* view = 0): m_view(view) {
    }
    virtual ~GraphicContext() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawImage
    (int x, int y, int w, int h, int imageWidth, int imageHeight,
     int imageRowSize, int imagePixelSize, const void* imageData,
     GraphicImageFormat imageFormat, GraphicImageInterpolation imageInterpolation) {
        if ((m_view) && (0 < w) && (0 < h)) {
            CGContextRef context = NULL;

            if ((context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort])) {
                NSRect rect = [m_view bounds];
                CGImageRef cgImage = NULL;

                LOG_DEBUG("CGImageCreateFromData()...");
                if ((cgImage = CGImageCreateFromData
                     (imageWidth, imageHeight, imageRowSize,
                      imagePixelSize, imageData, imageFormat))) {
                    CGFloat xScale = 1.0, yScale = 1.0,
                            yPos = (h <= rect.size.height)
                            ?(rect.size.height-y-h):(0.0);
                    CGInterpolationQuality interpolationQuality = kCGInterpolationDefault;

                    rect = NSMakeRect(x,yPos, w,h);

                    CGContextSaveGState(context);
                    CGContextSetShouldAntialias(context, false);
                    CGContextSetInterpolationQuality(context, interpolationQuality);
                    CGContextScaleCTM(context, xScale,yScale);
                    CGContextDrawImage(context, rect, cgImage);
                    CGContextRestoreGState(context);

                    LOG_DEBUG("CGImageRelease(cgImage)...");
                    CGImageRelease(cgImage);
                }
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void FillRectangle
    (int x, int y, int w, int h, const GraphicPixelInterface& color) {
        if ((m_view) && (0 < w) && (0 < h)) {
            NSRect rect = [m_view bounds];
            y = ((int)rect.size.height)-y-h;
            [((NSColor*)color) set];
            NSRectFill(NSMakeRect(x,y, w,h));
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void FillRectangle
    (int x, int y, int w, int h,
     const UI::GraphicSurface::GraphicPixelInterface& color) {
        const Native::GraphicSurface::GraphicPixelInterface* nativeColor = 0;
        if ((nativeColor = color.NativeGraphicPixelInterface())) {
            FillRectangle(x,y, w,h, *nativeColor);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual UI::GraphicSurface::GraphicPixelInterface* AllocateColor
    (ColorChannel r, ColorChannel g, ColorChannel b, ColorChannel a) {
        GraphicPixel* color = 0;
        if ((color = new GraphicPixel(r,g,b,a))) {
            return color;
        }
        return 0;
    }
    virtual UI::GraphicSurface::GraphicPixelInterface* AllocateColor
    (ColorChannel r, ColorChannel g, ColorChannel b) {
        GraphicPixel* color = 0;
        if ((color = new GraphicPixel(r,g,b))) {
            return color;
        }
        return 0;
    }
    virtual bool FreeColor(UI::GraphicSurface::GraphicPixelInterface* color) {
        if ((color)) {
            GraphicPixelInterface* nativeColorInterface = 0;
            if ((nativeColorInterface = color->NativeGraphicPixelInterface())) {
                GraphicPixel* nativeColor = 0;
                if ((nativeColor = nativeColorInterface->NativeGraphicPixel())) {
                    delete nativeColor;
                    return true;
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CGImageRef CGImageCreateFromData
    (int imageWidth, int imageHeight,int imageRowSize, int imagePixelSize,
     const void* imageData, GraphicImageFormat imageFormat) const {
        switch(imageFormat) {
        case GraphicImageFormatRGBA:
            if ((imageWidth*imagePixelSize) == imageRowSize) {
                switch(imagePixelSize) {
                case 4:
                    LOG_DEBUG("CGImageCreateFromDataRGBA32()...");
                    return CGImageCreateFromDataRGBA32
                    (imageWidth, imageHeight, imageData);
                    break;
                }
            }
            break;
        }
        return NULL;
    }
    virtual CGImageRef CGImageCreateFromDataRGBA32
    (int imageWidth, int imageHeight, const void* imageData) const {
        CGImageRef cgImage = NULL;

        if ((imageData) && (imageWidth) && (imageHeight)) {
            CGColorSpaceRef cgColorSpace = NULL;

            LOG_DEBUG("CGColorSpaceCreateDeviceRGB()...");
            if ((cgColorSpace = CGColorSpaceCreateDeviceRGB())) {
                CGDataProviderRef cgDataProvider = NULL;

                LOG_DEBUG("CGDataProviderCreateWithData()...");
                if ((cgDataProvider = CGDataProviderCreateWithData
                     (NULL, imageData, imageWidth * imageHeight * 4, NULL))) {

                    LOG_DEBUG("CGImageCreate()...");
                    cgImage = CGImageCreate
                    (imageWidth, imageHeight, 8,32, imageWidth*4,
                     cgColorSpace, kCGImageAlphaNoneSkipLast,
                     cgDataProvider, NULL, false, kCGRenderingIntentDefault);

                    LOG_DEBUG("CGDataProviderRelease(cgDataProvider)...");
                    CGDataProviderRelease(cgDataProvider);
                }
                LOG_DEBUG("CGColorSpaceRelease(cgColorSpace)...");
                CGColorSpaceRelease(cgColorSpace);
            }
        }
        return cgImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    NSView* m_view;
};

} // namespace GraphicSurface
} // namespace Cocoa 
} // namespace UI 
} // namespace uLucidity 

#endif // ULUCIDITY_UI_COCOA_GRAPHICSURFACE_GRAPHICCONTEXT_HH 
