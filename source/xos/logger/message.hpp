///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: message.hpp
///
/// Author: $author$
///   Date: 12/5/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LOGGER_MESSAGE_HPP
#define XOS_LOGGER_MESSAGE_HPP

#include "xos/logger/location.hpp"

namespace xos {
namespace logger {

/// class messaget
template 
<typename TChar = char, class TString = stringt<TChar>,
 class TExtends = TString, class TImplements = implement>

class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    messaget(const char* chars, size_t length): extends(chars, length) {
    }
    messaget(const char* chars): extends(chars) {
    }
    messaget(const messaget& copy): extends(copy) {
    }
    messaget() {
    }
    virtual ~messaget() {
    }

    /// operator <<
    virtual messaget& operator << (const extends& str) { 
        this->append(str); 
        return *this; 
    }
    virtual messaget& operator << (const char_t* chars) { 
        this->append(chars); 
        return *this; 
    }
    virtual messaget& operator << (const signed& value) {
        this->append_signed(value);
        return *this; 
    }
}; /// class messaget
typedef messaget<> message;

} /// namespace logger
} /// namespace xos

#endif /// ndef XOS_LOGGER_MESSAGE_HPP
