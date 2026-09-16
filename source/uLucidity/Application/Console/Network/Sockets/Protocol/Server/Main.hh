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
#ifndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_PROTOCOL_SERVER_MAIN_HH
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_PROTOCOL_SERVER_MAIN_HH

#include "uLucidity/Application/Console/Network/Sockets/Server/MainOpt.hh"
#include "xos/udentify/server/interface.hpp"
#include "xos/io/format/json/libjson/to_node.hpp"

namespace uLucidity {
namespace Application {
namespace Console {
namespace Network {
namespace Sockets {
namespace Protocol {
namespace Server {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template 
<class TJsonNodeEvents = xos::io::format::json::node_events,
 class TSocketsMainEvents = uLucidity::Application::Network::Sockets::Base::Main::Events,
 class TSocketsMain  = uLucidity::Application::Network::Sockets::Server::Main,
 class TExtends = uLucidity::Application::Console::Network::Sockets::Server::MainOpt, 
 class TImplements = typename TExtends::Implements>
class exported Maint
: virtual public TJsonNodeEvents, virtual public TImplements, public TExtends {
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
    typedef xos::udentify::server::interface udentify_interface_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint()
    : json_node_events_(*this) {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
protected:

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
    /// ...prepare_response_to_json_node_request
    virtual int prepare_response_to_json_node_request(string_t& response, const string_t& request, const json_node_t& json_node) {
        int err = 0;
        JsonNodeEvents& json_node_events = this_json_node_events();

        LOGGER_IS_LOGGED_INFO("json_node.to(json_node_events)...");
        json_node.to(json_node_events);
        LOGGER_IS_LOGGED_INFO("...json_node.to(json_node_events)");
        return err;
    }
    virtual int before_prepare_response_to_json_node_request(string_t& response, const string_t& request, const json_node_t& json_node) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_json_node_request(string_t& response, const string_t& request, const json_node_t& json_node) {
        int err = 0;
        udentify_interface_t* udentify_interface = 0;
        
        LOGGER_IS_LOGGED_INFO("(udentify_interface = udentify_interface_t::the_interface())...");
        if ((udentify_interface = udentify_interface_t::the_interface())) {
            const string_t& udentity_path = this->udentity_path();
            const string_t& default_user = this->default_udentify_user();
            const string_t& default_resource = this->default_udentify_resource();
            const string_t& default_password = this->default_udentify_password();
            const string_t& user = this->udentify_user();
            const string_t& resource = this->udentify_resource();
            const string_t& password = this->udentify_password();
            string_t saved_password, result;

            LOGGER_IS_LOGGED_INFO("...(udentify_interface = udentify_interface_t::the_interface())");
            LOGGER_IS_LOGGED_INFO("(0 < (" << default_user.length() << "))...");
            if ((0 < (default_user.length()))) {
                LOGGER_IS_LOGGED_INFO("udentify_interface->set_default_user(\"" << default_user << "\")...");
                udentify_interface->set_default_user(default_user);
            }
            LOGGER_IS_LOGGED_INFO("(0 < (" << default_resource.length() << "))...");
            if ((0 < (default_resource.length()))) {
                LOGGER_IS_LOGGED_INFO("udentify_interface->set_default_resource(\"" << default_resource << "\")...");
                udentify_interface->set_default_resource(default_resource);
            }
            LOGGER_IS_LOGGED_INFO("(0 < (" << default_password.length() << "))...");
            if ((0 < (default_password.length()))) {
                LOGGER_IS_LOGGED_INFO("udentify_interface->set_default_password(\"" << default_password << "\")...");
                udentify_interface->set_default_password(default_password);
            }
            LOGGER_IS_LOGGED_INFO("(0 < (" << udentity_path.length() << "))...");
            if ((0 < (udentity_path.length()))) {
                LOGGER_IS_LOGGED_INFO("udentify_interface->set_udentity_path(\"" << udentity_path << "\")...");
                udentify_interface->set_udentity_path(udentity_path);
            }
            LOGGER_IS_LOGGED_INFO("udentify_interface->password(result, user, resource, password)...");
            udentify_interface->password(result, user, resource, password);
            LOGGER_IS_LOGGED_INFO("...udentify_interface->password(result, user, resource, password)");
            LOGGER_IS_LOGGED_INFO("saved_password.assign(\"" << this->udentify_password() << "\")...");
            saved_password.assign(password);
            LOGGER_IS_LOGGED_INFO("(0 < (result.length()))...");
            if (0 < (result.length())) {
                LOGGER_IS_LOGGED_INFO("...(0 < (result.length()))");
                LOGGER_IS_LOGGED_INFO("this->set_udentify_password(\"" << result << "\")...");
                this->set_udentify_password(result);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (0 < (result.length()))");
                LOGGER_IS_LOGGED_INFO("this->set_udentify_password(\"" << default_password << "\")...");
                this->set_udentify_password(default_password);
            }
            LOGGER_IS_LOGGED_INFO("this->set_udentify_response_message()...");
            this->set_udentify_response_message();
            LOGGER_IS_LOGGED_INFO("response.assign(\"" << (this->udentify_response_message()) << "\")...");
            response.assign(this->udentify_response_message());
            LOGGER_IS_LOGGED_INFO("this->set_udentify_password(\"" << saved_password << "\")...");
            this->set_udentify_password(saved_password);
            return err;
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (udentify_interface = udentify_interface_t::the_interface())");
        }
        LOGGER_IS_LOGGED_INFO("this->set_udentify_response_message()...");
        this->set_udentify_response_message();
        LOGGER_IS_LOGGED_INFO("...this->set_udentify_response_message()");
        return err;
    }
    virtual int all_prepare_response_to_json_node_request(string_t& response, const string_t& request, const json_node_t& json_node) {
        int err = 0;
        if (!(err = before_prepare_response_to_json_node_request(response, request, json_node))) {
            int err2 = 0;
            err = prepare_response_to_json_node_request(response, request, json_node);
            if ((err2 = after_prepare_response_to_json_node_request(response, request, json_node))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
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
    /// ...prepare_response_to_unknown_request
    virtual int prepare_response_to_unknown_request(string_t& response, const string_t& request) {
        int err = 0;
        to_json_node_t to_json_node;
        json_node_t json_node;
        
        LOGGER_IS_LOGGED_INFO("to_json_node.to(json_node, \"" << request << "\")...");
        to_json_node.to(json_node, request);
        LOGGER_IS_LOGGED_INFO("...to_json_node.to(json_node, \"" << request << "\")");
        LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_json_node_request(\"" << response << "\", \"" << request << "\", json_node))...");
        if (!(err = all_prepare_response_to_json_node_request(response, request, json_node))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_json_node_request(\"" << response << "\", \"" << request << "\", json_node))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_json_node_request(\"" << response << "\", \"" << request << "\", json_node))");
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
public:
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

    //////////////////////////////////////////////////////////////////////////
protected:
    JsonNodeEvents& json_node_events_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Server 
} /// namespace Protocol 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_PROTOCOL_SERVER_MAIN_HH

