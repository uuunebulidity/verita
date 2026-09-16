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
///   Date: 9/30/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_HH
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_HH

#include "uLucidity/Network/Sockets/Client.hh"
#include "uLucidity/Application/Console/Network/Sockets/uDentify/Client/MainOpt.hh"

namespace uLucidity {
namespace Application {
namespace Console {
namespace Network {
namespace Sockets {
namespace uDentify {
namespace Client {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template 
<class TEvents = uLucidity::Network::Sockets::Client::Events,
 class TExtends = uLucidity::Application::Console::Network::Sockets::uDentify::Client::MainOptt<>, 
 class TImplements = typename TExtends::implements>
class _EXPORT_CLASS Maint: virtual public TEvents, virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef Maint derives;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint()
    : request_("{\"password\":{\"user\":\"user\",\"resource\":\"resource\",\"password\":\"password\"}}"),
      response_("{\"password\":\"unknown\"}"),
      client_(*this) {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): extends(copy) {
    }
public:
protected:
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            XOS_LOG_INFO("(!(err = (this->*run_)(argc, argv, env)))...");
            if (!(err = (this->*run_)(argc, argv, env))) {
                XOS_LOG_INFO("...(!(" << err << " = (this->*run_)(argc, argv, env)))");
            } else {
                XOS_LOG_INFO("...failed on (!(" << err << " = (this->*run_)(argc, argv, env)))");
            }
        } else {
            XOS_LOG_INFO("(!(err = extends::run(argc, argv, env)))...");
            if (!(err = extends::run(argc, argv, env))) {
                XOS_LOG_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
            } else {
                XOS_LOG_INFO("...failed on (!(err" << err << " = extends::run(argc, argv, env)))");
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...client_run
    virtual int client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        uLucidity::Network::Sockets::Client::string request_(this->request_), response_(this->response_);
        XOS_LOG_INFO("(!(err = client_.all_Run(response_ = \"" << response_ << "\", request_ = \"" << request_ << "\")))...");
        if (!(err = client_.all_Run(response_, request_))) {
            XOS_LOG_INFO("...(!(" << err << " = client_.all_Run(response_ = \"" << response_ << "\", request_ = \"" << request_ << "\")))");
        } else {
            XOS_LOG_INFO("...failed on (!(err" << err << " = client_.all_Run(response_ = \"" << response_ << "\", request_ = \"" << request_ << "\")))");
        }
        return err;
    }
    virtual int set_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::client_run;
        return err;
    }
    virtual int client_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int client_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_connect_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_client_run(argc, argv, env))) {
            if (!(err = client_run_set(argc, argv, env))) {
            } else {}
        } else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_receive(char_t* chars, size_t length) { 
        int err = 0;
        response_.append(chars, length);
        return err;
    }
    virtual int on_begin_receive(char_t* chars, size_t length) { 
        int err = 0;
        response_.assign(chars, length);
        return err;
    }
    virtual int on_end_receive(char_t* chars, size_t length) { 
        int err = 0;
        this->outln(chars, length);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t request_, response_;
    uLucidity::Network::Sockets::Client client_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Client 
} /// namespace uDentify 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_HH
