///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: GraphicImage.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_GRAPHICIMAGE_HPP
#define ULUCIDITY_UI_GRAPHICIMAGE_HPP

#include "uLucidity/UI/GraphicImageBase.hpp"

namespace uLucidity {
namespace UI {

typedef GraphicImageInterfaceBase GraphicImageInterfaceImplements;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicImageInterface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicImageInterface
: virtual public GraphicImageInterfaceImplements {
public:
    typedef GraphicImageInterfaceImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(GraphicImageInterface& image, int x, int y) {
    }
    virtual void Fill(GraphicImageInterface& image, int x, int y, int w, int h) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(int x, int y) {
    }
    virtual void Fill(int x, int y, int w, int h) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GraphicImageInterface* SetAsImage(GraphicImageInterface* image) {
        GraphicImageInterface* prevImage = 0;
        if (image) {
            prevImage = image->SetAsImage();
        } else {
            prevImage = Image();
        }
        return prevImage;
    }
    virtual GraphicImageInterface* SetAsImage() {
        GraphicImageInterface* prevImage = Image();
        return prevImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GraphicImageInterface* SelectImage(GraphicImageInterface* image) {
        GraphicImageInterface* prevImage = Image();
        SetImage(image);
        return prevImage;
    }
    virtual GraphicImageInterface* SetImage(GraphicImageInterface* image) {
        GraphicImageInterface* prevImage = 0;
        return prevImage;
    }
    virtual GraphicImageInterface* Image() const {
        GraphicImageInterface* image = 0;
        return image;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef GraphicImageInterface GraphicBaseImageImplements;
typedef Base GraphicBaseImageExtends;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicBaseImage
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicBaseImage
: virtual public GraphicBaseImageImplements, public GraphicBaseImageExtends {
public:
    typedef GraphicBaseImageImplements Implements;
    typedef GraphicBaseImageExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    GraphicBaseImage(GraphicImageInterface& image): m_image(image) {
    }
    virtual ~GraphicBaseImage() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(GraphicImageInterface& image, int x, int y) {
        image.Plot(x,y);
    }
    virtual void Fill(GraphicImageInterface& image, int x, int y, int w, int h) {
        image.Fill(x,y, w,h);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(int x, int y) {
        m_image.Plot(x,y);
    }
    virtual void Fill(int x, int y, int w, int h) {
        m_image.Fill(x,y, w,h);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    GraphicImageInterface& m_image;
};

typedef GraphicImageInterface GraphicImageImplements;
typedef Base GraphicImageExtends;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicImage
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicImage
: virtual public GraphicImageImplements, public GraphicImageExtends {
public:
    typedef GraphicImageImplements Implements;
    typedef GraphicImageExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    GraphicImage(GraphicImageInterface* image = 0): m_image(image) {
    }
    virtual ~GraphicImage() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GraphicImageInterface* SetImage(GraphicImageInterface* image) {
        GraphicImageInterface* prevImage = m_image;
        m_image = image;
        return prevImage;
    }
    virtual GraphicImageInterface* Image() const {
        GraphicImageInterface* image = m_image;
        return image;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(GraphicImageInterface& image, int x, int y) {
        image.Plot(x,y);
    }
    virtual void Fill(GraphicImageInterface& image, int x, int y, int w, int h) {
        image.Fill(x,y, w,h);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(int x, int y) {
        GraphicImageInterface* image = 0;
        if ((image = Image())) {
            image->Plot(x, y);
        }
    }
    virtual void Fill(int x, int y, int w, int h) {
        GraphicImageInterface* image = 0;
        if ((image = Image())) {
            image->Fill(x,y, w,h);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    GraphicImageInterface* m_image;
};

} // namespace UI
} // namespace uLucidity 

#endif // ULUCIDITY_UI_GRAPHICIMAGE_HPP 
