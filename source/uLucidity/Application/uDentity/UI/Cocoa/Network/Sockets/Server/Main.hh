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
///   Date: 10/10/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_UDENTITY_UI_COCOA_NETWORK_SOCKETS_SERVER_MAIN_HH
#define ULUCIDITY_APPLICATION_UDENTITY_UI_COCOA_NETWORK_SOCKETS_SERVER_MAIN_HH

#include "uLucidity/Application/Network/Sockets/Server/Main.hh"
#include "uLucidity/Application/Console/Network/Sockets/Protocol/Server/Main.hh"
#include "uLucidity/Application/Server/Main.hh"

namespace uLucidity {
namespace Application {
namespace uDentity {
namespace UI {
namespace Cocoa {
namespace Network {
namespace Sockets {
namespace Server {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template 
<class TEvents = uLucidity::Application::Network::Sockets::Base::Main::Events,
 class TMain = uLucidity::Application::Network::Sockets::Server::Main, 
 class TProtocolMain = uLucidity::Application::Console::Network::Sockets::Protocol::Server::Main, 
 class TExtends = uLucidity::Application::Server::Main, 
 class TImplements = typename TExtends::Implements>
class exported Maint: virtual public TEvents, virtual public TImplements, public TExtends {
public:
    typedef TEvents Events;
    typedef TMain Main;
    typedef TProtocolMain ProtocolMain;
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;

    typedef typename Extends::string string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint(): main_(*this) {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
    //////////////////////////////////////////////////////////////////////////
    /// run
    virtual int run() {
        int err = 0;
        const string_t& request = this->request();
        string_t& response = this->response();

        LOGGER_IS_LOGGED_INFO("(!(err = main_.all_Run(\"" << response << "\", \"" << request << "\")))...");
        if (!(err = main_.all_Run(response, request))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = main_.all_Run(\"" << response << "\", \"" << request << "\")))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = main_.all_Run(\"" << response << "\", \"" << request << "\")))");
        }
        return err;
    }
protected:
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_unknown_request
    virtual int prepare_response_to_unknown_request(string_t& response, const string_t& request) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("response.assign(\"" << this->unknown_request() << "\")...");
        response.assign(this->unknown_request());

        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_response_to_request(\"" << response << "\", \"" << request << "\")))...");
        if (!(err = protocol_main_.all_prepare_response_to_request(response, request))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_response_to_request(\"" << response << "\", \"" << request << "\")))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_prepare_response_to_request(\"" << response << "\", \"" << request << "\")))");
        }
        return err;
    }
    virtual int before_prepare_response_to_unknown_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_unknown_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_unknown_request(string_t& response, const string_t& request) {
        int err = 0;
        if (!(err = before_prepare_response_to_unknown_request(response, request))) {
            int err2 = 0;
            err = prepare_response_to_unknown_request(response, request);
            if ((err2 = after_prepare_response_to_unknown_request(response, request))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_hello_request
    virtual int prepare_response_to_hello_request(string_t& response, const string_t& request) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("response.assign(\"" << this->hello_response() << "\")...");
        response.assign(this->hello_response());
        return err;
    }
    virtual int before_prepare_response_to_hello_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_hello_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_hello_request(string_t& response, const string_t& request) {
        int err = 0;
        if (!(err = before_prepare_response_to_hello_request(response, request))) {
            int err2 = 0;
            err = prepare_response_to_hello_request(response, request);
            if ((err2 = after_prepare_response_to_hello_request(response, request))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_restart_request
    virtual int prepare_response_to_restart_request(string_t& response, const string_t& request) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("response.assign(\"" << this->restart_response() << "\")...");
        response.assign(this->restart_response());
        
        LOGGER_IS_LOGGED_INFO("main_.set_accept_restart()...");
        main_.set_accept_restart();
        return err;
    }
    virtual int before_prepare_response_to_restart_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_restart_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_restart_request(string_t& response, const string_t& request) {
        int err = 0;
        if (!(err = before_prepare_response_to_restart_request(response, request))) {
            int err2 = 0;
            err = prepare_response_to_restart_request(response, request);
            if ((err2 = after_prepare_response_to_restart_request(response, request))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_stop_request
    virtual int prepare_response_to_stop_request(string_t& response, const string_t& request) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("response.assign(\"" << this->stop_response() << "\")...");
        response.assign(this->stop_response());

        LOGGER_IS_LOGGED_INFO("main_.set_accept_done()...");
        main_.set_accept_done();
        return err;
    }
    virtual int before_prepare_response_to_stop_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_stop_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_stop_request(string_t& response, const string_t& request) {
        int err = 0;
        if (!(err = before_prepare_response_to_stop_request(response, request))) {
            int err2 = 0;
            err = prepare_response_to_stop_request(response, request);
            if ((err2 = after_prepare_response_to_stop_request(response, request))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_request
    virtual int prepare_response_to_request(string_t& response, const string_t& request) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_response_to_unknown_request(\"" << response << "\", \"" << request << "\")))...");
        if (!(err = all_prepare_response_to_unknown_request(response, request))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_response_to_unknown_request(\"" << response << "\", \"" << request << "\")))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_prepare_response_to_unknown_request(\"" << response << "\", \"" << request << "\")))");
        }
        return err;
    }
    virtual int before_prepare_response_to_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_request(string_t& response, const string_t& request) {
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
    virtual int on_receive(char_t* chars, size_t length) { 
        int err = 0;
        return err;
    }
    virtual int on_begin_receive(char_t* chars, size_t length) { 
        int err = 0;
        return err;
    }
    virtual int on_end_receive(char_t* chars, size_t length) { 
        int err = 0;
        return err;
    }
    virtual int on_after_receive(string &target, const string &source) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_response_to_request(\"" << target << "\", \"" << source << "\")))...");
        if (!(err = all_prepare_response_to_request(target, source))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_response_to_request(\"" << target << "\", \"" << source << "\")))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_prepare_response_to_request(\"" << target << "\", \"" << source << "\")))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    Main main_;
    ProtocolMain protocol_main_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Server 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Cocoa 
} /// namespace UI 
} /// namespace uDentity 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_UDENTITY_UI_COCOA_NETWORK_SOCKETS_SERVER_MAIN_HH

