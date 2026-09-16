///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: ThePlugin.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_THEPLUGIN_HPP
#define ULUCIDITY_UI_THEPLUGIN_HPP

#include "uLucidity/UI/Plugin.hpp"

#if !defined(LOG_TRACE)
#define LOG_TRACE STDERR_LOG_TRACE
#endif // !defined(LOG_TRACE)

#if !defined(LOG_DEBUG)
#define LOG_DEBUG STDERR_LOG_DEBUG
#endif // !defined(LOG_DEBUG)

#if !defined(LOG_ERROR)
#define LOG_ERROR STDERR_LOG_ERROR
#endif // !defined(LOG_DEBUG)

#define ULUCIDITY_2STRING_(id) "" #id ""
#define ULUCIDITY_2STRING(id) ULUCIDITY_2STRING_(id)

#define ULUCIDITY_UI_THEPLUGIN_CONTENT_BACKGROUD_COLOR_RED 0xFF
#define ULUCIDITY_UI_THEPLUGIN_CONTENT_BACKGROUD_COLOR_GREEN 0xFF
#define ULUCIDITY_UI_THEPLUGIN_CONTENT_BACKGROUD_COLOR_BLUE 0xEE

#define ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_WIDTH 288
#define ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_HEIGHT 128
#define ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_DEPTH 32
#define ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_BASE ULUCIDITY_UI_CONTENT_IMAGE_BASE
#define ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_EXTENSION "bgra"
#define ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_FILENAME \
    ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_BASE \
    "-" ULUCIDITY_2STRING(ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_WIDTH) \
    "-" ULUCIDITY_2STRING(ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_HEIGHT)  \
    "-" ULUCIDITY_2STRING(ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_DEPTH) \
    "." ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_EXTENSION

namespace uLucidity {
namespace UI {

typedef PluginExtendImplements ThePluginImplements;
typedef PluginExtend ThePluginExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ThePlugin
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS ThePlugin
: virtual public ThePluginImplements, public ThePluginExtends {
public:
    typedef ThePluginImplements Implements;
    typedef ThePluginExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ThePlugin()
    : m_imFilename(ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_FILENAME),
      m_imWidth(ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_WIDTH),
      m_imHeight(ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_HEIGHT),
      m_imPixelSize(ULUCIDITY_UI_THEPLUGIN_BGRA_IMAGE_DEPTH/8),
      m_imRowSize(m_imWidth*m_imPixelSize),
      m_imFormat(GraphicImageFormatRGBA),
      m_imInterpolation(GraphicImageInterpolationDefault),
      m_imSize(m_imRowSize*m_imHeight),
      m_imData(0),
      m_failedOnLoadInage(false), 
      m_noFillContentRectangle(false)
    {
    }
    virtual ~ThePlugin() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool InitPlugin() {
        if (!LoadBGRAImage()) {
            m_failedOnLoadInage = onFailedLoadInage();
        }        
        return true;
    }
    virtual bool FiniPlugin() {
        FreeImage();
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void* LoadRGBAImage() {
        if ((m_imSize) && (m_imFilename)) {
            LOG_DEBUG("m_imData = new byte_t[" << m_imSize << "]...");
            if ((m_imData = new byte_t[m_imSize])) {
                size_t count = 0;
                FILE* f = 0;
                LOG_DEBUG("fopen(m_imFilename = \"" << m_imFilename << "\", \"rb\")...");
                if ((f = fopen(m_imFilename, "rb"))) {
                    LOG_DEBUG("fread(m_imData, 1,m_imSize, f)...");
                    count = fread(m_imData, 1,m_imSize, f);
                    LOG_DEBUG("..." << count << " = fread(m_imData, 1,m_imSize, f)");
                    fclose(f);
                } else {
                    LOG_ERROR("...failed on fopen(m_imFilename = \"" << m_imFilename << "\", \"rb\")");
                }
                if (count == m_imSize) {
                    return m_imData;
                } else {
                    LOG_ERROR("...count < m_imSize");
                }
                LOG_DEBUG("delete m_imData...");
                delete m_imData;
                m_imData = 0;
            }
        }
        return m_imData;
    }
    virtual void* LoadBGRAImage() {
        if ((LoadRGBAImage())) {
            byte_t *b = ((byte_t*)m_imData), t = 0;
            for (size_t i = 0; i < m_imSize; i += 4, b += 4) {
                t = b[0]; b[0] = b[2]; b[2] = t;
            }
        }
        return m_imData;
    }
    virtual void FreeImage() {
        if ((m_imData)) {
            LOG_DEBUG("delete m_imData...");
            delete m_imData;
            m_imData = 0;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMenuItemHide() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemHide()...");
            return to->onMenuItemHide();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    virtual bool onMenuItemShutdown() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMenuItemShutdown()...");
            return to->onMenuItemShutdown();
        }
        LOG_DEBUG("return true...");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onMinimizeClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMinimizeClicked()...");
            return to->onMinimizeClicked();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    virtual bool onMinimizeHideClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMinimizeHideClicked()...");
            return to->onMinimizeHideClicked();
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onMaximizeClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMaximizeClicked()...");
            return to->onMaximizeClicked();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    virtual bool onMaximizeShutdownClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onMaximizeShutdownClicked()...");
            return to->onMaximizeShutdownClicked();
        }
        LOG_DEBUG("return true...");
        return true;
    }

    /*/
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onOptionsClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onOptionsClicked()...");
            return to->onOptionsClicked();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    virtual bool onShutdownClicked() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onShutdownClicked()...");
            return to->onShutdownClicked();
        }
        LOG_DEBUG("return true...");
        return true;
    }
    /*/

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onContentMouseDown(int x, int y, MouseButton button) {
        PluginSignals* to = ForwardPluginSignalsTo();
        LOG_DEBUG("...x = " << x << ", y = " << y << "");
        if ((to)) {
            LOG_DEBUG("return to->onContentMouseDown(x,y, button)...");
            return to->onContentMouseDown(x,y, button);
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onContentMouseUp(int x, int y, MouseButton button) {
        PluginSignals* to = ForwardPluginSignalsTo();
        LOG_DEBUG("...x = " << x << ", y = " << y << "");
        if ((to)) {
            LOG_DEBUG("return to->onContentMouseUp(x,y, button)...");
            return to->onContentMouseUp(x,y, button);
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onContentMouseUpMenu() {
        PluginSignals* to = ForwardPluginSignalsTo();
        if ((to)) {
            LOG_DEBUG("return to->onContentMouseUpMenu()...");
            return to->onContentMouseUpMenu();
        }
        LOG_DEBUG("return true...");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool onContentResize(int width, int height) {
        PluginSignals* to = ForwardPluginSignalsTo();
        LOG_DEBUG("...width = " << width << ", height = " << height << "");
        if ((to)) {
            LOG_DEBUG("return to->onContentResize(width, height)...");
            return to->onContentResize(width, height);
        }
        LOG_DEBUG("return false...");
        return false;
    }
    virtual bool onContentDraw
    (GraphicContext& gc, int width, int height,
     int invalidX, int invalidY, int invalidWidth, int invalidHeight) {
        PluginSignals* to = ForwardPluginSignalsTo();
        LOG_DEBUG("...invalidWidth = " << invalidWidth << ", invalidHeight = " << invalidHeight << "");
        if ((to)) {
            LOG_DEBUG("return to->onContentDraw(gc, width, height, invalidX,invalidY, invalidWidth,invalidHeight)...");
            return to->onContentDraw(gc, width, height, invalidX,invalidY, invalidWidth,invalidHeight);
        }
        if (!(m_noFillContentRectangle) || (m_imData)) {
            GraphicSurface::GraphicPixelInterface* color = 0;
            ColorChannel //r(0xFF), g(0xFF), b(0xEE);
                r(ULUCIDITY_UI_THEPLUGIN_CONTENT_BACKGROUD_COLOR_RED),
                g(ULUCIDITY_UI_THEPLUGIN_CONTENT_BACKGROUD_COLOR_GREEN),
                b(ULUCIDITY_UI_THEPLUGIN_CONTENT_BACKGROUD_COLOR_BLUE);
            if ((color = gc.AllocateColor(r,g,b))) {
                gc.FillRectangle(0,0, width,height, *color);
                gc.FreeColor(color);
            }
        }
        if ((m_imData)) {
            int imBorder = 20;
            gc.DrawImage
            (imBorder,imBorder, width-imBorder*2, height-imBorder*2,
             m_imWidth,m_imHeight, m_imRowSize, m_imPixelSize,
             m_imData, m_imFormat, m_imInterpolation);
        }
        LOG_DEBUG("return true...");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetFailedOnLoadImage(bool to = true) {
        m_failedOnLoadInage = to;
        return m_failedOnLoadInage;
    }
    virtual bool FailedOnLoadImage() {
        return m_failedOnLoadInage;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetNoFillContentRectangle(bool to = true) {
        m_noFillContentRectangle = to;
        return m_noFillContentRectangle;
    }
    virtual bool NoFillContentRectangle() {
        return m_noFillContentRectangle;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char* m_imFilename;
    int m_imWidth, m_imHeight, m_imPixelSize, m_imRowSize;
    GraphicImageFormat m_imFormat;
    GraphicImageInterpolation m_imInterpolation;
    size_t m_imSize;
    void* m_imData;
    bool m_failedOnLoadInage, m_noFillContentRectangle;
};

} // namespace UI 
} // namespace uLucidity 

#endif // ULUCIDITY_UI_THEPLUGIN_HPP 
