//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
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
///   File: Main.hh
///
/// Author: $author$
///   Date: 10/4/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_PROTOCOL_BASE_MAIN_HH
#define ULUCIDITY_PROTOCOL_BASE_MAIN_HH

#include "uLucidity/Base/Base.hpp"
#include "xos/io/logger.hpp"

namespace uLucidity {
namespace Protocol {
namespace Base {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template <class TExtends = uLucidity::Base, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;

    typedef xos::base::string string;
    typedef xos::base::string string_t;
    typedef xos::base::string::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint() {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
protected:

    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_request
    virtual int prepare_response_to_request(string& response, const string& request) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_request(string& response, const string& request) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_request(string& response, const string& request) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_request(string& response, const string& request) {
        int err = 0;
        if (!(err = before_prepare_response_to_request(response, request))) {
            int err2 = 0;
            err = prepare_response_to_request(response, request);
            if ((err2 = after_prepare_response_to_request(response, request))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ...Run
    virtual int Run(string &target, const string &source) {
        int err = 0;
        LOG_DEBUG("(!(err = all_prepare_response_to_request(\"" << target << "\", \"" << source << "\")))...");
        if (!(err = all_prepare_response_to_request(target, source))) {
            LOG_DEBUG("...(!(" << err << " = all_prepare_response_to_request(\"" << target << "\", \"" << source << "\")))");
        } else {
            LOG_DEBUG("...failed on (!(" << err << " = all_prepare_response_to_request(\"" << target << "\", \"" << source << "\")))");
        }
        return err;
    }
    virtual int before_Run(string &target, const string &source) {
        int err = 0;
        return err;
    }
    virtual int after_Run(string &target, const string &source) {
        int err = 0;
        return err;
    }
public:
    virtual int all_Run(string &target, const string &source) {
        int err = 0;
        if (!(err = before_Run(target, source))) {
            int err2 = 0;
            err = Run(target, source);
            if ((err2 = after_Run(target, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class Maint
typedef Maint<> Main;

} /// namespace Base 
} /// namespace Protocol 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_PROTOCOL_BASE_MAIN_HH
