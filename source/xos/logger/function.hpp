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
///   File: function.hpp
///
/// Author: $author$
///   Date: 12/5/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LOGGER_FUNCTION_HPP
#define XOS_LOGGER_FUNCTION_HPP

#include "xos/logger/levels.hpp"
#include "xos/base/to_string.hpp"

namespace xos {
namespace logger {

/// class functiont
template 
<typename TChar = char, class TString = stringt<TChar>,
 class TExtends = TString, class TImplements = implement>

class exported functiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef functiont derives;

    typedef TString string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    functiont(const char_t* chars, size_t length): extends(chars, length) {
     }
    functiont(const char_t* chars): extends(chars) {
    }
    functiont(const functiont& copy): extends(copy) {
    }
    functiont() {
    }
    virtual ~functiont() {
    }

    /// trim
    virtual functiont& trim() {
        const char_t* chars = 0;
        size_t length = 0;
        if ((chars = this->has_chars(length))) {
            const char_t *lt = 0, *gt = 0, *e = chars + length;
            for (const char_t *i = chars; length; --length, ++i) {
                switch (*i) {
                    case '<':
                        if (!(lt)) {
                            lt = i;
                        }
                        break;
                    case '>':
                        gt = i;
                        break;
                }
            }
            if ((lt) && (gt) && (lt < gt)) {
                string_t name(chars, ((lt - chars) + 1));
                name.append("...");
                name.append(gt, ((e - gt) + 1));
                this->assign(name);
            }
        }
        return *this;
    }
protected:
}; /// class functiont
typedef functiont<> function;

namespace trimmed {
/// class functiont
template 
<typename TChar = char, class TString = stringt<TChar>,
class TExtends = logger::functiont<TChar, TString>, class TImplements = typename TExtends::implements>

class exported functiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef functiont derives;

    typedef TString string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    functiont(const char_t* chars, size_t length): extends(chars, length) {
        this->trim();
    }
    functiont(const char_t* chars): extends(chars) {
        this->trim();
    }
    functiont(const functiont& copy): extends(copy) {
    }
    functiont() {
    }
    virtual ~functiont() {
    }
}; /// class functiont
typedef functiont<> function;
} /// namespace trimmed

} /// namespace logger
} /// namespace xos

#endif /// ndef XOS_LOGGER_FUNCTION_HPP
