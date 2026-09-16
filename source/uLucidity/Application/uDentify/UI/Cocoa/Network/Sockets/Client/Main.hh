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
///   Date: 10/22/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_UDENTIFY_UI_COCOA_NETWORK_SOCKETS_CLIENT_MAIN_HH
#define ULUCIDITY_APPLICATION_UDENTIFY_UI_COCOA_NETWORK_SOCKETS_CLIENT_MAIN_HH

#include "uLucidity/Application/Network/Sockets/Client/Main.hh"
#include "uLucidity/Application/Console/Network/Sockets/Protocol/Client/Main.hh"
#include "uLucidity/Application/Client/Main.hh"

namespace uLucidity {
namespace Application {
namespace uDentify {
namespace UI {
namespace Cocoa {
namespace Network {
namespace Sockets {
namespace Client {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template 
<class TEvents = uLucidity::Application::Network::Sockets::Base::Main::Events,
 class TMain = uLucidity::Application::Network::Sockets::Client::Main, 
 class TProtocolMain = uLucidity::Application::Console::Network::Sockets::Protocol::Client::Main, 
 class TExtends = uLucidity::Application::Client::Main, 
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
        const string& target_result =  protocol_main_.set_udentify_password_unknown();
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
    ///////////////////////////////////////////////////////////////////////
    virtual int on_after_receive(string &target, const string &source) {
        int err = 0;
        const string& target_result =  protocol_main_.set_udentify_password_unknown();
        if (!(err = protocol_main_.all_process_response_to_request(target, source))) {} else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual const xos::string& get_target_result(xos::string& result) {
        const string& target_result =  protocol_main_.get_udentify_password_known();
        result.assign(target_result);
        return result;
    }
    /*/
    //////////////////////////////////////////////////////////////////////////
    virtual const string& get_target_result() {
        xos::lock lock(mutex_);
        const string& target_result =  protocol_main_.get_udentify_password_known();
        return target_result;
    }
    /*/
    //////////////////////////////////////////////////////////////////////////
protected:

    //////////////////////////////////////////////////////////////////////////
protected:
    Main main_;
    ProtocolMain protocol_main_;
    //xos::mt::os::mutex mutex_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Client 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Cocoa 
} /// namespace UI 
} /// namespace uDentify 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_UDENTIFY_UI_COCOA_NETWORK_SOCKETS_CLIENT_MAIN_HH
