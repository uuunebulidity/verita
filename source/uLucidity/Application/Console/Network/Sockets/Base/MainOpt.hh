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
///   Date: 10/5/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_BASE_MAINOPT_HH
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_BASE_MAINOPT_HH

#include "uLucidity/Application/Console/Protocol/Base/Main.hh"

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPT "host"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTARG_RESULT 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTARG "{name | ddd.ddd.ddd.ddd | *}"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTUSE "host name, address, or any"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTVAL_S "o::"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTVAL_C 'o'
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTION \
   {ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTARG_REQUIRED, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTARG_RESULT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTVAL_C}, \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPT "port"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTARG_RESULT 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTARG "{0..2^16-1}"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTUSE "port number"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTVAL_S "p::"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTVAL_C 'p'
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTION \
   {ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTARG_REQUIRED, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTARG_RESULT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTVAL_C}, \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPT "request"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTARG_RESULT 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTARG "[string]"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTUSE "request sent/received"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTVAL_S "r::"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTVAL_C 'r'
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTION \
   {ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTARG_REQUIRED, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTARG_RESULT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTVAL_C}, \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPT "response"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTARG_RESULT 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTARG "[string]"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTUSE "response received/sent"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTVAL_S "s::"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTVAL_C 's'
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTION \
   {ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTARG_REQUIRED, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTARG_RESULT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTVAL_S \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTVAL_S \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTVAL_S \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTVAL_S \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTION \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTION \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTION \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTION \

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_CHARS \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_OPTIONS \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_ARGS 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_ARGV 0,

namespace uLucidity {
namespace Application {
namespace Console {
namespace Network {
namespace Sockets {
namespace Base {

//////////////////////////////////////////////////////////////////////////
/// class MainOptt
template <class TExtends = uLucidity::Application::Console::Protocol::Base::Main, class TImplements = typename TExtends::Implements>
class exported MainOptt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef MainOptt Derives;

    typedef typename Extends::string string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::string_t::char_t char_t;
    
    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    MainOptt() {
    }
    virtual ~MainOptt() {
    }
private:
    MainOptt(const MainOptt &copy): Extends(copy) {
    }
public:
protected:

    //////////////////////////////////////////////////////////////////////////
    /// on...host_option...
    virtual int on_get_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_host_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_host_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_host_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_host_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTUSE;
        optarg = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...port_option...
    virtual int on_get_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_port_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_port_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_port_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_port_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTUSE;
        optarg = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTARG;
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
        const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTUSE;
        optarg = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...response_option...
    virtual int on_get_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_response_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_response_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_response_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_response_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_response_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_response_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_response_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* response_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTUSE;
        optarg = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTARG;
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

        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTVAL_C:
            err = this->on_request_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTVAL_C:
            err = this->on_response_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = Extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_HOST_OPTVAL_C:
            chars = this->host_option_usage(optarg, longopt);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_PORT_OPTVAL_C:
            chars = this->port_option_usage(optarg, longopt);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_REQUEST_OPTVAL_C:
            chars = this->request_option_usage(optarg, longopt);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_RESPONSE_OPTVAL_C:
            chars = this->response_option_usage(optarg, longopt);
            break;

        default:
            chars = Extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class MainOptt
typedef MainOptt<> MainOpt;

} /// namespace Base 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_BASE_MAINOPT_HH
