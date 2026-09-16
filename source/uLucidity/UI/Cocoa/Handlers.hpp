///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Handlers.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_HANDLERS_HPP
#define ULUCIDITY_UI_COCOA_HANDLERS_HPP

#include "uLucidity/UI/Cocoa/Signals.hh"

///////////////////////////////////////////////////////////////////////
///  Class: Handlers
///////////////////////////////////////////////////////////////////////
class Handlers: virtual public Signals {
public:
    typedef Signals Implements;
    enum Exception { ExceptionOnlyOneAllowed };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Handlers(): m_forwardPluginSignalsTo(0) {
        if (!(handlersReference())) {
            handlersReference() = this;
        } else {
            throw (ExceptionOnlyOneAllowed);
        }
    }
    virtual ~Handlers() {
        if ((this == handlersReference())) {
            handlersReference() = 0;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual PluginSignals* ForwardPluginSignalsTo(PluginSignals* to) {
        m_forwardPluginSignalsTo = to;
        return m_forwardPluginSignalsTo;
    }
    virtual PluginSignals* ForwardPluginSignalsTo() const {
        return m_forwardPluginSignalsTo;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    PluginSignals* m_forwardPluginSignalsTo;
};

#endif // ULUCIDITY_UI_COCOA_HANDLERS_HPP
