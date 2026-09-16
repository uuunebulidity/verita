///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: Logger.hh
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_COCOA_LOGGER_HH
#define ULUCIDITY_UI_COCOA_LOGGER_HH

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

typedef unsigned char Byte;

typedef std::basic_string<char> StringExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class String: public StringExtends {
public:
    typedef StringExtends Extends;
    typedef char char_t;
    typedef Byte byte_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    String(const void *in) {
        this->append("0x");
        this->appendx(&in, sizeof(in));
    }
    String(const char *in): Extends(in) {}
    String(const String &copy): Extends(copy) {}
    String() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    String& appendx(const void *in, size_t length, bool upper_case = false) {
        const byte_t* bytes = (const byte_t*)(in);
        if ((bytes) && (length)) {
            char_t x[2];
            byte_t b;
            for (; 0 < length; --length) {
                b = (*bytes++);
                x[0] = dtox(b >> 4, upper_case);
                x[1] = dtox(b & 15, upper_case);
                append(x, 2);
            }
        }
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t dtox(byte_t d, bool upper_case = false) const {
        char a = (upper_case)?('A'):('a');
        char_t x = (char_t)(0);
        if ((0 <= d) && (9 >= d))
            x = (char_t)(('0') +  d);
        else
        if ((10 <= d) && (15 >= d))
            x = (char_t)((a) + (d - 10));
        return x;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

#if !defined(DEBUG_BUILD)
#define LOG_DEBUG(args) 
#else // !defined(DEBUG_BUILD)
#define LOG_DEBUG(args) LOG_ERROR(args)
#endif // !defined(DEBUG_BUILD)
#define LOG_ERROR(args) \
    Logger() << __FILE__ << " " << __FUNCTION__ << ": " << args << "\n"

static std::ostream& Logger() {
    return std::cerr;
}

#endif // ULUCIDITY_UI_COCOA_LOGGER_HH 
