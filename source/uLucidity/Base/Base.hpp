///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Base.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_BASE_BASE_HPP
#define ULUCIDITY_BASE_BASE_HPP

#include "uLucidity/Platform/Platform.h"
#include "xos/base/base.hpp"
#include <sstream>
#include <string>

#if defined(TRACE_BUILD)
#define STDERR_LOG_TRACE(_message) STDERR_LOG(_message)
#else // defined(TRACE_BUILD)
#define STDERR_LOG_TRACE(_message)
#endif // defined(TRACE_BUILD)

#if defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(_message) STDERR_LOG(_message)
#else // defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(_message)
#endif // defined(DEBUG_BUILD)

#define STDERR_LOG_ERROR(_message) STDERR_LOG(_message)

#if !defined(NO_STDERR_LOG)
#define STDERR_LOG(_message) \
{   class String: public ::std::string { public: \
        String& operator << (const char* chars) { append(chars); return *this; } \
        String& operator << (int n) { ::std::stringstream ss; ss << n; append(ss.str()); return *this; } \
    }; String msg; msg << _message; \
    fprintf(stderr, "%s %s: %s\n", __FILE__, __FUNCTION__, msg.c_str()); }
#else // !defined(NO_STDERR_LOG)
#define STDERR_LOG(_message)
#endif // !defined(NO_STDERR_LOG)

namespace uLucidity {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS ImplementBase: virtual public xos::implement {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ~ImplementBase() {}
    virtual bool is_logged() const {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Base: virtual public ImplementBase, public xos::extend {
public:
    typedef ImplementBase Implements;
    typedef xos::extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Base() {}
    virtual ~Base() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace uLucidity

#endif // ULUCIDITY_BASE_BASE_HPP 
