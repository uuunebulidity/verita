///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: GraphicImageBase.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_GRAPHICIMAGEBASE_HPP
#define ULUCIDITY_UI_GRAPHICIMAGEBASE_HPP

#include "uLucidity/UI/ColorChannel.hpp"
#include "uLucidity/UI/GraphicImageFormat.hpp"
#include "uLucidity/UI/GraphicImageInterpolation.hpp"

namespace uLucidity {
namespace UI {

typedef ImplementBase GraphicImageInterfaceBaseImplements;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicImageInterfaceBase
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicImageInterfaceBase
: virtual public GraphicImageInterfaceBaseImplements {
public:
    typedef GraphicImageInterfaceBaseImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(GraphicImageInterfaceBase& pixel, int x, int y) {
    }
    virtual void Fill(GraphicImageInterfaceBase& pixel, int x, int y, int w, int h) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef GraphicImageInterfaceBase GraphicImageBaseImplements;
typedef Base GraphicImageBaseExtends;
///////////////////////////////////////////////////////////////////////
///  Class: GraphicImageBase
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GraphicImageBase
: virtual public GraphicImageBaseImplements, public GraphicImageBaseExtends {
public:
    typedef GraphicImageBaseImplements Implements;
    typedef GraphicImageBaseExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    GraphicImageBase(GraphicImageInterfaceBase& image): m_image(image) {
    }
    virtual ~GraphicImageBase() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(GraphicImageInterfaceBase& pixel, int x, int y) {
        pixel.Plot(m_image, x,y);
    }
    virtual void Fill(GraphicImageInterfaceBase& pixel, int x, int y, int w, int h) {
        pixel.Fill(m_image, x,y, w,h);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    GraphicImageInterfaceBase& m_image;
};

} // namespace UI
} // namespace uLucidity 


#endif // ULUCIDITY_UI_GRAPHICIMAGEBASE_HPP 
        

