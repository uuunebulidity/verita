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
///   File: MainOpt.hh
///
/// Author: $author$
///   Date: 9/30/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAINOPT_HH
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAINOPT_HH

#include "uLucidity/Application/Console/Network/Sockets/uDentify/Base/Main.hh"

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPT "connect"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTARG_RESULT 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTARG "{name | ddd.ddd.ddd.ddd | *}"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTUSE "connect host name, address, or any"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTVAL_S "c::"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTVAL_C 'c'
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTION \
   {ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTARG_REQUIRED, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTARG_RESULT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTVAL_C}, \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPT "request"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTARG_RESULT 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTARG "[string]"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTUSE "request message"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTVAL_S "r::"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTVAL_C 'r'
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTION \
   {ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTARG_REQUIRED, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTARG_RESULT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTVAL_S \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTVAL_S \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTION \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTION \

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_OPTIONS_CHARS \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_CHARS \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_OPTIONS_OPTIONS \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_ARGS 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_ARGV 0,

namespace uLucidity {
namespace Application {
namespace Console {
namespace Network {
namespace Sockets {
namespace uDentify {
namespace Client {

//////////////////////////////////////////////////////////////////////////
/// class MainOptt
template 
<class TExtends = uLucidity::Application::Console::Network::Sockets::uDentify::Base::Maint<>, 
 class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS MainOptt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef MainOptt derives;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    MainOptt() {
    }
    virtual ~MainOptt() {
    }
private:
    MainOptt(const MainOptt &copy): extends(copy) {
    }
public:
protected:
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// on...connect_option...
    virtual int on_get_connect_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_connect_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_connect_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_connect_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_connect_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_connect_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_connect_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_connect_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_connect_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* connect_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTUSE;
        optarg = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...request_option...
    virtual int on_get_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_request_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_request_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_request_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_request_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_request_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_request_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_request_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* request_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTUSE;
        optarg = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTVAL_C:
            err = this->on_connect_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTVAL_C:
            err = this->on_request_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_CONNECT_OPTVAL_C:
            chars = this->connect_option_usage(optarg, longopt);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_REQUEST_OPTVAL_C:
            chars = this->request_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_ARGS;
        static const char_t* _argv[] = {
            ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class MainOptt
typedef MainOptt<> MainOpt;

} /// namespace Client 
} /// namespace uDentify 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_CLIENT_MAINOPT_HH
