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
///   Date: 10/5/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_BASE_MAIN_HH
#define ULUCIDITY_APPLICATION_BASE_MAIN_HH

#include "uLucidity/Base/Base.hh"
#include "xos/base/string.hpp"
#include "xos/base/logger.hpp"

#if defined(APPLEIOS)
#else /// defined(APPLEIOS)
#define LOG_ANY   LOGGER_LOG_ANY  
#define LOG_FATAL LOGGER_LOG_FATAL
#define LOG_ERROR LOGGER_LOG_ERROR
#define LOG_WARN  LOGGER_LOG_WARN 
#define LOG_INFO  LOGGER_LOG_INFO 
#define LOG_DEBUG LOGGER_LOG_DEBUG
#define LOG_TRACE LOGGER_LOG_TRACE
#endif /// defined(APPLEIOS)

namespace uLucidity {
namespace Application {
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
    Maint()
    : unknown_request_("{\"system\":{\"request\":\"unknown\"}}"),
      unknown_response_("{\"system\":{\"response\":\"unknown\"}}"),

      udentify_request_message_(unknown_request_), 
      udentify_response_message_(unknown_request_),
      
      request_("request"), response_("response") {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
protected:

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& udentify_request_message() const {
        return (string_t&)udentify_request_message_;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual string_t& udentify_response_message() const {
        return (string_t&)udentify_response_message_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...request...
    virtual string_t& request_message() const {
        return udentify_request_message();
    }
    /// ...response...
    virtual string_t& response_message() const {
        return udentify_response_message();
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...hello_request
    virtual string_t& set_system_hello_request() {
        return set_to_hello_request();
    }
    virtual string_t& set_to_hello_request() {
        const string_t &hello_request = this->hello_request();
        string_t &request = this->request_message();
        request.assign(hello_request);
        return request;
    }
    virtual string_t& hello_request() const {
        return (string_t&)hello_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hello_response
    virtual string_t& hello_response() const {
        return (string_t&)hello_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...restart_request
    virtual string_t& set_system_restart_request() {
        return set_to_restart_request();
    }
    virtual string_t& set_to_restart_request() {
        const string_t &restart_request = this->restart_request();
        string_t &request = this->request_message();
        request.assign(restart_request);
        return request;
    }
    virtual string_t& restart_request() const {
        return (string_t&)restart_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...restart_response
    virtual string_t& restart_response() const {
        return (string_t&)restart_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...start_request
    virtual string_t& set_system_start_request() {
        return set_to_start_request();
    }
    virtual string_t& set_to_start_request() {
        const string_t &start_request = this->start_request();
        string_t &request = this->request_message();
        request.assign(start_request);
        return request;
    }
    virtual string_t& start_request() const {
        return (string_t&)restart_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...start_response
    virtual string_t& start_response() const {
        return (string_t&)restart_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...stop_request
    virtual string_t& set_system_stop_request() {
        return set_to_stop_request();
    }
    virtual string_t& set_to_stop_request() {
        const string_t &stop_request = this->stop_request();
        string_t &request = this->request_message();
        request.assign(stop_request);
        return request;
    }
    virtual string_t& stop_request() const {
        return (string_t&)stop_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...stop_response
    virtual string_t& stop_response() const {
        return (string_t&)stop_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...unknown_request
    virtual string_t& set_system_unknown_request() {
        return set_to_unknown_request();
    }
    virtual string_t& set_to_unknown_request() {
        const string_t &unknown_request = this->unknown_request();
        string_t &request = this->request_message();
        request.assign(unknown_request);
        return request;
    }
    virtual string_t& unknown_request() const {
        return (string_t&)unknown_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...unknown_response
    virtual string_t& set_system_unknown_response() {
        return set_to_unknown_response();
    }
    virtual string_t& set_to_unknown_response() {
        const string_t &unknown_response = this->unknown_response();
        string_t &response = this->response_message();
        response.assign(unknown_response);
        return response;
    }
    virtual string_t& unknown_response() const {
        return (string_t&)unknown_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_request(const string_t& to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& request() const {
        return (string_t&)request_;
    }
    virtual string_t& set_response(const string_t& to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& response() const {
        return (string_t&)response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t udentify_request_message_, udentify_response_message_, 
         
             hello_request_, hello_response_,
             restart_request_, restart_response_,
             stop_request_, stop_response_,
             unknown_request_, unknown_response_,
         
             request_, response_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Base 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_BASE_MAIN_HH

