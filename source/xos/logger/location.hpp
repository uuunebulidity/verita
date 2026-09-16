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
///   File: location.hpp
///
/// Author: $author$
///   Date: 12/5/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LOGGER_LOCATION_HPP
#define XOS_LOGGER_LOCATION_HPP

#include "xos/logger/function.hpp"

namespace xos {
namespace logger {

/// class locationt
template 
<typename TChar = char, class TString = stringt<TChar>,
 class TExtends = TString, class TImplements = implement>

class exported locationt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef locationt derives;

    typedef typename extends::derives string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    locationt(const logger::function& function, const char_t* file_name, size_t line_number)
    : extends(function), file_name_(file_name), line_number_(line_number) {
    }
    locationt(const char_t* function_name, const char_t* file_name, size_t line_number)
    : extends(function_name), file_name_(file_name), line_number_(line_number) {
    }
    locationt(const locationt& copy)
    : extends(copy), file_name_(copy.file_name_), line_number_(copy.line_number_) {
    }
    locationt() {
    }
    virtual ~locationt() {
    }

    /// ...name / ...number / combined
    virtual string_t function_name() const { 
        return *this; 
    }
    virtual string_t file_name() const { 
        return file_name_; 
    }
    virtual string_t line_number() const {
        size_to_string line(line_number_);
        return line;
    }
    virtual string_t combined() const {
        string_t combined(file_name());
        combined.append("[");
        combined.append(line_number());
        combined.append("] ");
        combined.append(function_name());
        combined.append(" ");
        return combined;
    }

protected:
    string_t file_name_;
    size_t line_number_;
}; /// class locationt
typedef locationt<> location;

} /// namespace logger
} /// namespace xos

#endif /// ndef XOS_LOGGER_LOCATION_HPP
