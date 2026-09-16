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
///   Date: 10/7/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_HH
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_HH

#include "uLucidity/Application/Console/Network/Sockets/Client/MainOpt.hh"
#include "xos/io/format/json/libjson/to_node.hpp"

namespace uLucidity {
namespace Application {
namespace Console {
namespace Network {
namespace Sockets {
namespace Client {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template 
<class TJsonNodeEvents = xos::io::format::json::node_events,
 class TSocketsMainEvents = uLucidity::Application::Network::Sockets::Base::Main::Events,
 class TSocketsMain  = uLucidity::Application::Network::Sockets::Client::Main,
 class TExtends = uLucidity::Application::Console::Network::Sockets::Client::MainOpt, 
 class TImplements = typename TExtends::Implements>
class exported Maint: virtual public TJsonNodeEvents, virtual public TImplements, public TExtends {
public:
    typedef TJsonNodeEvents JsonNodeEvents;
    typedef TSocketsMainEvents SocketsMainEvents;
    typedef TSocketsMain SocketsMain;
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;

    typedef typename Extends::string string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::string_t::char_t char_t;
    
    typedef xos::io::format::json::libjson::to_node to_json_node_t;
    typedef xos::io::format::json::node json_node_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint(): json_node_events_(*this), main_events_(*this), main_(main_events_) {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
protected:
    //////////////////////////////////////////////////////////////////////////
    /// class MainEvents
    class _EXPORT_CLASS MainEvents: virtual public SocketsMainEvents {
    public:
        typedef SocketsMainEvents Implements;
        typedef typename Derives::string string;
        typedef typename Derives::char_t char_t;
    
        //////////////////////////////////////////////////////////////////////////
        /// constructor / destructor
        MainEvents(Derives &main): main_(main) {
        }
        virtual ~MainEvents() {
        }
        //////////////////////////////////////////////////////////////////////////
        virtual int on_receive(char_t* chars, size_t length) { 
            int err = 0;
            err = main_.on_receive(chars, length);
            return err;
        }
        virtual int on_begin_receive(char_t* chars, size_t length) { 
            int err = 0;
            err = main_.on_begin_receive(chars, length);
            return err;
        }
        virtual int on_end_receive(char_t* chars, size_t length) { 
            int err = 0;
            err = main_.on_end_receive(chars, length);
            return err;
        }
        virtual int on_after_receive(string &target, const string &source) {
            int err = 0;
            err = main_.on_after_receive(target, source);
            return err;
        }
    protected:
        Derives& main_;
    }; /// class Events

    //////////////////////////////////////////////////////////////////////////
    /// ...named...
    virtual JsonNodeEvents& on_begin_named_node(const xos::io::format::json::node& node) {
        int err = 0;
        int unequal = 0;
        const xos::io::format::json::node::string_t node_string = node.get_string();
        const string_t& nameof_udentify_user = this->nameof_udentify_user();

        LOGGER_IS_LOGGED_INFO("!(unequal = nameof_udentify_user.compare(node_string = \"" << node_string << "\"))...");
        if (!(unequal = nameof_udentify_user.compare(node_string))) {
            LOGGER_IS_LOGGED_INFO("...!(unequal = nameof_udentify_user.compare(node_string = \"" << node_string << "\"))");
            LOGGER_IS_LOGGED_INFO("!(err = set_user_on_string_node(node))...");
            if (!(err = set_user_on_string_node(node))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = set_user_on_string_node(node))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = set_user_on_string_node(node))");
            }
        } else {
            const string_t& nameof_udentify_resource = this->nameof_udentify_resource();
    
            LOGGER_IS_LOGGED_INFO("!(unequal = nameof_udentify_resource.compare(node_string = \"" << node_string << "\"))...");
            if (!(unequal = nameof_udentify_resource.compare(node_string))) {
                LOGGER_IS_LOGGED_INFO("...!(unequal = nameof_udentify_resource.compare(node_string = \"" << node_string << "\"))");
                LOGGER_IS_LOGGED_INFO("!(err = set_resource_on_string_node(node))...");
                if (!(err = set_resource_on_string_node(node))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = set_resource_on_string_node(node))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = set_resource_on_string_node(node))");
                }
            } else {
                const string_t& nameof_udentify_password = this->nameof_udentify_password();
        
                LOGGER_IS_LOGGED_INFO("!(unequal = nameof_udentify_password.compare(node_string = \"" << node_string << "\"))...");
                if (!(unequal = nameof_udentify_password.compare(node_string))) {
                    LOGGER_IS_LOGGED_INFO("...!(unequal = nameof_udentify_password.compare(node_string = \"" << node_string << "\"))");
                    LOGGER_IS_LOGGED_INFO("!(err = set_password_on_string_node(node))...");
                    if (!(err = set_password_on_string_node(node))) {
                        LOGGER_IS_LOGGED_INFO("...!(" << err << " = set_password_on_string_node(node))");
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = set_password_on_string_node(node))");
                    }
                } else {
                }
            }
        }
        return json_node_events_this();
    }
    virtual JsonNodeEvents& on_end_named_node(const xos::io::format::json::node& node) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = unset_on_string_node(node))...");
        if (!(err = unset_on_string_node(node))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = unset_on_string_node(node))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = unset_on_string_node(node))");
        }
        return json_node_events_this();
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...on...string...    
    int (Derives::*on_string_node_)(const xos::io::format::json::node& node);
    virtual JsonNodeEvents& on_string_node(const xos::io::format::json::node& node) {
        JsonNodeEvents* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = json_node_events_forwarded_to())) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_string_node(node)...");
            forwarded_to->on_string_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_string_node(node)");
        } else {
            int err = 0;
            if (on_string_node_) {
                if (!(err = (this->*on_string_node_)(node))) {
                } else {
                }
            } else {
                if (!(err = default_on_string_node(node))) {
                } else {
                }
            }
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return json_node_events_this();
    }
    virtual int default_on_string_node(const xos::io::format::json::node& node) {
        int err = 0;
        const xos::io::format::json::node::string_t& node_string = node.get_string();
        const xos::io::format::json::node::char_t* chars = 0;
        size_t length = 0;
        LOGGER_IS_LOGGED_INFO("(chars = node_string.has_chars(length))...");
        if ((chars = node_string.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = node_string.has_chars(" << length << "))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = node_string.has_chars(" << length << "))");
        }
        return err;
    }
    virtual int user_on_string_node(const xos::io::format::json::node& node) {
        int err = 0;
        const xos::io::format::json::node::string_t& node_string = node.get_string();
        const xos::io::format::json::node::char_t* chars = 0;
        size_t length = 0;
        LOGGER_IS_LOGGED_INFO("(chars = node_string.has_chars(length))...");
        if ((chars = node_string.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = node_string.has_chars(" << length << "))");
            LOGGER_IS_LOGGED_INFO("this->set_udentify_user(\"" << chars << "\")...");
            this->set_udentify_user(chars);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = node_string.has_chars(" << length << "))");
        }
        return err;
    }
    virtual int resource_on_string_node(const xos::io::format::json::node& node) {
        int err = 0;
        const xos::io::format::json::node::string_t& node_string = node.get_string();
        const xos::io::format::json::node::char_t* chars = 0;
        size_t length = 0;
        LOGGER_IS_LOGGED_INFO("(chars = node_string.has_chars(length))...");
        if ((chars = node_string.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = node_string.has_chars(" << length << "))");
            LOGGER_IS_LOGGED_INFO("this->set_udentify_resource(\"" << chars << "\")...");
            this->set_udentify_resource(chars);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = node_string.has_chars(" << length << "))");
        }
        return err;
    }
    virtual int password_on_string_node(const xos::io::format::json::node& node) {
        int err = 0;
        const xos::io::format::json::node::string_t& node_string = node.get_string();
        const xos::io::format::json::node::char_t* chars = 0;
        size_t length = 0;
        LOGGER_IS_LOGGED_INFO("(chars = node_string.has_chars(length))...");
        if ((chars = node_string.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = node_string.has_chars(" << length << "))");
            LOGGER_IS_LOGGED_INFO("this->set_udentify_password(\"" << chars << "\")...");
            this->set_udentify_password(chars);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = node_string.has_chars(" << length << "))");
        }
        return err;
    }
    virtual int unset_on_string_node(const xos::io::format::json::node& node) {
        int err = 0;
        on_string_node_ = 0;
        return err;
    }
    virtual int set_user_on_string_node(const xos::io::format::json::node& node) {
        int err = 0;
        on_string_node_ = &Derives::user_on_string_node;
        return err;
    }
    virtual int set_resource_on_string_node(const xos::io::format::json::node& node) {
        int err = 0;
        on_string_node_ = &Derives::resource_on_string_node;
        return err;
    }
    virtual int set_password_on_string_node(const xos::io::format::json::node& node) {
        int err = 0;
        on_string_node_ = &Derives::password_on_string_node;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...process_json_node_request
    virtual int process_json_node_response_to_request(string_t& response, const string_t& request, const json_node_t& json_node) {
        int err = 0;
        JsonNodeEvents& json_node_events = this_json_node_events();

        LOGGER_IS_LOGGED_INFO("json_node.to(json_node_events)...");
        json_node.to(json_node_events);
        LOGGER_IS_LOGGED_INFO("...json_node.to(json_node_events)");
        return err;
    }
    virtual int before_process_json_node_response_to_request(string_t& response, const string_t& request, const json_node_t& json_node) {
        int err = 0;
        return err;
    }
    virtual int after_process_json_node_response_to_request(string_t& response, const string_t& request, const json_node_t& json_node) {
        int err = 0;
        const string_t& password = this->udentify_password();
        const char_t* chars = 0; size_t length = 0;
        
        LOGGER_IS_LOGGED_INFO("((chars = password.has_chars(length)))...");
        if ((chars = password.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = password.has_chars(" << length << ")))");
            LOGGER_IS_LOGGED_INFO("response.assign(\"" << password << "\")...");
            response.assign(password);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = password.has_chars(" << length << ")))");
        }
        return err;
    }
    virtual int all_process_json_node_response_to_request(string_t& response, const string_t& request, const json_node_t& json_node) {
        int err = 0;
        if (!(err = before_process_json_node_response_to_request(response, request, json_node))) {
            int err2 = 0;
            err = process_json_node_response_to_request(response, request, json_node);
            if ((err2 = after_process_json_node_response_to_request(response, request, json_node))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...json_node_events
    virtual JsonNodeEvents* json_node_events_forwarded_to() {
        return (JsonNodeEvents*)(this->forwarded_to(this));
    }
    virtual JsonNodeEvents& json_node_events_this() const {
        return (JsonNodeEvents&)(*this);
    }
    /// ...json_node_events
    virtual JsonNodeEvents& this_json_node_events() const {
        return (JsonNodeEvents&)json_node_events_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...process_response_to_unknown_request
    virtual int process_response_to_unknown_request(string_t& response, const string_t& request) {
        int err = 0;
        to_json_node_t to_json_node;
        json_node_t json_node;
        
        LOGGER_IS_LOGGED_INFO("to_json_node.to(json_node, \"" << response << "\")...");
        to_json_node.to(json_node, response);
        LOGGER_IS_LOGGED_INFO("...to_json_node.to(json_node, \"" << response << "\")");
        LOGGER_IS_LOGGED_INFO("!(err = all_process_json_node_response_to_request(\"" << response << "\", \"" << request << "\", json_node))...");
        if (!(err = all_process_json_node_response_to_request(response, request, json_node))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_json_node_response_to_request(\"" << response << "\", \"" << request << "\", json_node))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_json_node_response_to_request(\"" << response << "\", \"" << request << "\", json_node))");
        }
        return err;
    }
    virtual int before_process_response_to_unknown_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_unknown_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_unknown_request(string_t& response, const string_t& request) {
        int err = 0;
        if (!(err = before_process_response_to_unknown_request(response, request))) {
            int err2 = 0;
            err = process_response_to_unknown_request(response, request);
            if ((err2 = after_process_response_to_unknown_request(response, request))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...process_response_to_request
    virtual int process_response_to_request(string_t& response, const string_t& request) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_process_response_to_unknown_request(\"" << response << "\", \"" << request << "\")))...");
        if (!(err = all_process_response_to_unknown_request(response, request))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_process_response_to_unknown_request(\"" << response << "\", \"" << request << "\")))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_process_response_to_unknown_request(\"" << response << "\", \"" << request << "\")))");
        }
        return err;
    }
    virtual int before_process_response_to_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_request(string_t& response, const string_t& request) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_request(string_t& response, const string_t& request) {
        int err = 0;
        if (!(err = before_process_response_to_request(response, request))) {
            int err2 = 0;
            err = process_response_to_request(response, request);
            if ((err2 = after_process_response_to_request(response, request))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    /// on...receive
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
        LOGGER_IS_LOGGED_INFO("(!(err = all_process_response_to_request(\"" << target << "\", \"" << source << "\")))...");
        if (!(err = all_process_response_to_request(target, source))) {
            const char_t* chars = 0; size_t length = 0;
            
            LOGGER_IS_LOGGED_INFO("((chars = target.has_chars(length)))...");
            if ((chars = target.has_chars(length))) {
                LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = target.has_chars(" << length << ")))");

                LOGGER_IS_LOGGED_INFO("this->outln(\"" << chars << "\", " << length << ")...");
                this->outln(chars, length);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on ((chars = target.has_chars(" << length << ")))");
            }
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_process_response_to_request(\"" << target << "\", \"" << source << "\")))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_process_response_to_request(\"" << target << "\", \"" << source << "\")))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...connect_option...
    virtual int on_connect_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_main_run(argc, argv, env))) {
            if (!(err = this->main_run_set(argc, argv, env))) {} else {}
        } else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual uLucidity::Application::Network::Sockets::Base::Main& main() const {
        return (uLucidity::Application::Network::Sockets::Base::Main&)main_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    JsonNodeEvents& json_node_events_;
    MainEvents main_events_;
    SocketsMain main_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Client 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_HH
