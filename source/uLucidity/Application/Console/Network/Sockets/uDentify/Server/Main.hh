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
///   Date: 10/1/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_HH
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_HH

#include "uLucidity/Network/Sockets/Server.hh"
#include "uLucidity/Application/Console/Network/Sockets/uDentify/Server/MainOpt.hh"
#include "uLucidity/Protocol/Json/Server/Main.hh"

namespace uLucidity {
namespace Application {
namespace Console {
namespace Network {
namespace Sockets {
namespace uDentify {
namespace Server {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template 
<class TEvents = uLucidity::Network::Sockets::Server::Events,
 class TExtends = uLucidity::Application::Console::Network::Sockets::uDentify::Server::MainOptt<>, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Maint: virtual public TEvents, virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef Maint Derives, derives;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint()
    : request_(ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_DEFAULT_REQUEST),
      response_(ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_DEFAULT_RESPONSE),
      server_(*this) {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
protected:
    typedef uLucidity::Network::Sockets::Server::string string;
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
    /// ...server_run
    virtual int server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string request_(this->request_), response_(this->response_);
        XOS_LOG_INFO("(!(err = server_.all_Run(request_ = \"" << request_ << "\", response_ = \"" << response_ << "\")))...");
        if (!(err = server_.all_Run(request_, response_))) {
            XOS_LOG_INFO("...(!(" << err << " = server_.all_Run(request_ = \"" << request_ << "\", response_ = \"" << response_ << "\")))");
        } else {
            XOS_LOG_INFO("...failed on (!(err" << err << " = server_.all_Run(request_ = \"" << request_ << "\", response_ = \"" << response_ << "\")))");
        }
        return err;
    }
    virtual int set_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::server_run;
        return err;
    }
    virtual int server_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int server_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_accept_one_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        server_.set_accept_one(true);
        if (!(err = set_server_run(argc, argv, env))) {
            if (!(err = server_run_set(argc, argv, env))) {
            } else {}
        } else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_accept_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        server_.set_accept_one(false);
        if (!(err = set_server_run(argc, argv, env))) {
            if (!(err = server_run_set(argc, argv, env))) {
            } else {}
        } else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_receive(char_t* chars, size_t length) { 
        int err = 0;
        request_.append(chars, length);
        return err;
    }
    virtual int on_begin_receive(char_t* chars, size_t length) { 
        int err = 0;
        request_.assign(chars, length);
        return err;
    }
    virtual int on_end_receive(char_t* chars, size_t length) { 
        int err = 0;
        this->outln(chars, length);
        return err;
    }
    virtual int on_after_receive(string &target, const string &source) {
        int err = 0;
        XOS_LOG_INFO("(!(err = main_.all_Run(\"" << target << "\", \"" << source << "\")))...");
        if (!(err = main_.all_Run(target, source))) {
            XOS_LOG_INFO("...(!(" << err << " = main_.all_Run(\"" << target << "\", \"" << source << "\")))");
        } else {
            XOS_LOG_INFO("...failed on (!(" << err << " = main_.all_Run(\"" << target << "\", \"" << source << "\")))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t request_, response_;
    uLucidity::Network::Sockets::Server server_;
    uLucidity::Protocol::Json::Server::Main main_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Server 
} /// namespace uDentify 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_HH
