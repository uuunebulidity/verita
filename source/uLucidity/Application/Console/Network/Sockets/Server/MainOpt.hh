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
///   Date: 10/7/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_SERVER_MAINOPT_HH
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_SERVER_MAINOPT_HH

#include "uLucidity/Application/Console/Network/Sockets/Base/Main.hh"

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPT "accept-one"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTARG_RESULT 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTARG "{name | ddd.ddd.ddd.ddd | *}"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTUSE "accept host name, address, or any"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTVAL_S "1::"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C '1'
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTION \
   {ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTARG_REQUIRED, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTARG_RESULT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C}, \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPT "accept"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTARG_RESULT 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTARG "{name | ddd.ddd.ddd.ddd | *}"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTUSE "accept host name, address, or any"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTVAL_S "a::"
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTVAL_C 'a'
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTION \
   {ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTARG_REQUIRED, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTARG_RESULT, \
    ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTVAL_S \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTVAL_S \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTION \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTION \

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_OPTIONS_CHARS \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_CHARS \

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_OPTIONS_OPTIONS \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ARGS 0
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ARGV 0,

namespace uLucidity {
namespace Application {
namespace Console {
namespace Network {
namespace Sockets {
namespace Server {

//////////////////////////////////////////////////////////////////////////
/// class MainOptt
template <class TExtends = uLucidity::Application::Console::Network::Sockets::Base::Main, class TImplements = typename TExtends::Implements>
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
    /// on...accept_one_option...
    virtual int on_get_accept_one_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_accept_one_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_accept_one_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_accept_one_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_accept_one_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_accept_one_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_accept_one_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_accept_one_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_accept_one_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* accept_one_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTUSE;
        optarg = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...accept_option...
    virtual int on_get_accept_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_accept_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_accept_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_accept_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_accept_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_accept_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_accept_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_accept_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_accept_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* accept_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTUSE;
        optarg = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTARG;
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

        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C:
            err = this->on_accept_one_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTVAL_C:
            err = this->on_accept_option(optval, optarg, optname, optind, argc, argv, env);
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

        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C:
            chars = this->accept_option_usage(optarg, longopt);
            break;
        case ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ACCEPT_OPTVAL_C:
            chars = this->accept_option_usage(optarg, longopt);
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
        static const char_t* chars = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ARGS;
        static const char_t* _argv[] = {
            ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_SERVER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class MainOptt
typedef MainOptt<> MainOpt;

} /// namespace Server 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_SERVER_MAINOPT_HH
