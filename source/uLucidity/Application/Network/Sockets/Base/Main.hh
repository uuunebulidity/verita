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
#ifndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_HH
#define ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_HH

#include "uLucidity/Application/Network/Sockets/uLucidity.hh"

#include "xos/network/sockets/os/interfaces.hpp"
#include "xos/network/sockets/os/interface.hpp"
#include "xos/network/sockets/interface.hpp"
#include "xos/network/sockets/reader.hpp"
#include "xos/network/sockets/writer.hpp"

#include "xos/network/sockets/ip/v4/endpoint.hpp"
#include "xos/network/sockets/ip/v4/tcp/transport.hpp"
#include "xos/network/sockets/ip/v4/udp/transport.hpp"

#if !defined(WINSOCK_1)
#include "xos/network/sockets/ip/v6/endpoint.hpp"
#include "xos/network/sockets/ip/v6/tcp/transport.hpp"
#include "xos/network/sockets/ip/v6/udp/transport.hpp"
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

#define ULUCIDITY_NETWORK_SOCKETS_BASE_RECEIVE_SIZE 4096
#define ULUCIDITY_NETWORK_SOCKETS_BASE_PORTNO ULUCIDITY_NETWORK_SOCKETS_UDENTIFY_PORTNO
#define ULUCIDITY_NETWORK_SOCKETS_BASE_PORT XOS_BASE_2STRING(ULUCIDITY_NETWORK_SOCKETS_BASE_PORTNO)
#define ULUCIDITY_NETWORK_SOCKETS_BASE_HOST ULUCIDITY_NETWORK_SOCKETS_UDENTIFY_HOST
#define ULUCIDITY_NETWORK_SOCKETS_BASE_ANY_HOST "*"
#define ULUCIDITY_NETWORK_SOCKETS_BASE_ACCEPT_HOST ULUCIDITY_NETWORK_SOCKETS_BASE_ANY_HOST
#define ULUCIDITY_NETWORK_SOCKETS_BASE_ENDOF_MESSAGE_TO_SEND "\r\n"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST ULUCIDITY_NETWORK_SOCKETS_BASE_ANY_HOST
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT ULUCIDITY_NETWORK_SOCKETS_BASE_PORTNO

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST ULUCIDITY_NETWORK_SOCKETS_BASE_HOST
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT

namespace uLucidity {
namespace Application {
namespace Network {
namespace Sockets {
namespace Base {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template <class TExtends = uLucidity::Application::Base::Main, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef Maint Derives, derives;

    typedef typename Extends::string string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint()
    : Run_(0),
      accept_one_(false), accept_done_(false), accept_restart_(false),
      accept_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST), 
      connect_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST),
      relay_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST),
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT),
      relay_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT),
      send_(&Derives::tcp_send),
      epoint_(&Derives::ip_v4_epoint),
      tport_(&Derives::ip_v4_tcp_tport),
      portno_(ULUCIDITY_NETWORK_SOCKETS_BASE_PORTNO),
      port_(ULUCIDITY_NETWORK_SOCKETS_BASE_PORT),
      host_(ULUCIDITY_NETWORK_SOCKETS_BASE_HOST),
      any_host_(ULUCIDITY_NETWORK_SOCKETS_BASE_ANY_HOST),
      endof_message_to_send_(ULUCIDITY_NETWORK_SOCKETS_BASE_ENDOF_MESSAGE_TO_SEND)
    {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
    //////////////////////////////////////////////////////////////////////////
    /// class Events
    class _EXPORT_CLASS Events: virtual public uLucidity::ImplementBase {
    public:
        typedef uLucidity::ImplementBase Implements;
        typedef typename Maint::string string;
        typedef typename Maint::char_t char_t;
    
        //////////////////////////////////////////////////////////////////////////
        /// constructor / destructor
        virtual ~Events() {
        }
    
        //////////////////////////////////////////////////////////////////////////
        virtual int on_receive(char_t* chars, size_t length) { 
            int err = 0;
            LOGGER_IS_LOGGED_INFO("...");
            return err;
        }
        virtual int on_begin_receive(char_t* chars, size_t length) { 
            int err = 0;
            LOGGER_IS_LOGGED_INFO("...");
            return err;
        }
        virtual int on_end_receive(char_t* chars, size_t length) { 
            int err = 0;
            LOGGER_IS_LOGGED_INFO("...");
            return err;
        }
        virtual int on_after_receive(string &target, const string &source) {
            int err = 0;
            LOGGER_IS_LOGGED_INFO("...");
            return err;
        }
    protected:
    }; /// class Events

protected:
    typedef int (Derives::*send_t)
    (xos::network::sockets::interface& s, xos::network::sockets::endpoint& ep, const char_t* chars, size_t length);
    typedef xos::network::sockets::endpoint* (Derives::*endpoint_t)();
    typedef xos::network::sockets::transport* (Derives::*transport_t)();
    typedef xos::exception endpoint_exception_t;
    typedef xos::exception transport_exception_t;

    //////////////////////////////////////////////////////////////////////////
    /// ...Run
    int (derives::*Run_)(string &target, const string &source);
    virtual int Run(string &target, const string &source) {
        int err = 0;
        if (Run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*Run_)(\"" << target << "\", \"" << source << "\")))...");
            if (!(err = (this->*Run_)(target, source))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*Run_)(\"" << target << "\", \"" << source << "\")))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*Run_)(\"" << target << "\", \"" << source << "\")))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_Run(\"" << target << "\", \"" << source << "\")))...");
            if (!(err = default_Run(target, source))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_Run(\"" << target << "\", \"" << source << "\")))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_Run(\"" << target << "\", \"" << source << "\")))");
            }
        }
        return err;
    }
    virtual int default_Run(string &target, const string &source) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_Connect(\"" << target << "\", \"" << source << "\")))...");
        if (!(err = all_Connect(target, source))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_Connect(\"" << target << "\", \"" << source << "\")))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = all_Connect(\"" << target << "\", \"" << source << "\")))");
        }
        return err;
    }
    virtual int before_Run(string &target, const string &source) {
        int err = 0;
        return err;
    }
    virtual int after_Run(string &target, const string &source) {
        int err = 0;
        return err;
    }
public:
    virtual int all_Run(string &target, const string &source) {
        int err = 0;
        if (!(err = before_Run(target, source))) {
            int err2 = 0;
            err = Run(target, source);
            if ((err2 = after_Run(target, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
protected:

    //////////////////////////////////////////////////////////////////////////
    /// ...Accept
    virtual int Accept(string &target, const string &source) {
        int err = 0;
        send_t send = 0;
        string_t old_host(host_);

        LOG_DEBUG("set_source_parameter(\"" << source << "\")...");
        set_source_parameter(source);
        
        LOG_DEBUG("set_target_parameter(\"" << target << "\")...");
        set_target_parameter(target);
        
        LOG_DEBUG("host_.assign(accept_host_)...");
        host_.assign(accept_host_);

        LOG_DEBUG("((send = (this->send_)))...");
        if ((send = (this->send_))) {
            xos::network::sockets::endpoint* ep = 0;
    
            LOG_DEBUG("((epoint_) && (ep = ((this->*epoint_)())))...");
            if ((epoint_) && (ep = ((this->*epoint_)()))) {
                xos::network::sockets::transport* tp = 0;
    
                LOG_DEBUG("((tport_) && (tp = (this->*tport_)()))...");
                if ((tport_) && (tp = (this->*tport_)())) {
                    xos::network::sockets::os::interface s;
    
                    LOG_DEBUG("((s.open(*tp)))...");
                    if ((s.open(*tp))) {
    
                        LOG_DEBUG("((s.listen(*ep)))...");
                        if ((s.listen(*ep))) {
                            string &target_parameter = target;
                            size_t endof_message_to_send_length = endof_message_to_send_.length();
                            xos::network::sockets::os::interface sk;
                            
                            LOG_DEBUG("for (bool done = false; !done; ) {...");
                            for (bool done = false; !done; done = get_accept_done()) {
                                
                                LOG_DEBUG("(!(done = !(sk.closed())))...");
                                if (!(done = !(sk.closed()))) {
                                    
                                    LOG_DEBUG("(!(done = !(s.accept(sk, *ep))))...");
                                    if (!(done = !(s.accept(sk, *ep)))) {
                                        bool endof_message_to_send_received = false;
                                        const char* chars = 0;
                                        size_t length = 0;
                                        ssize_t count = 0;
    
                                        LOG_DEBUG("...(!(done = !(s.accept(sk, *ep))))");
                                        LOG_DEBUG("(0 < (count = sk.recv(receive_chars_, " << sizeof(receive_chars_) << ", 0)))...");
                                        if (0 < (count = sk.recv(receive_chars_, sizeof(receive_chars_), 0))) {
                                            int unequal = 0;
                                            const char* to_chars = 0;
                                            size_t amount = count;
                                            string to_string;

                                            if ((endof_message_to_send_length <= count)) {
                                                to_chars = receive_chars_+count-endof_message_to_send_length;
                                                to_string.assign_chars(to_chars, endof_message_to_send_length);
                                                if (endof_message_to_send_received = !(unequal = (endof_message_to_send_.compare(to_string)))) {
                                                    amount = (count -= endof_message_to_send_length);
                                                } else {}
                                            } else {}
                                            LOG_DEBUG("(!(err = on_begin_receive(receive_chars_, " << count << ")))...");
                                            if (!(err = on_begin_receive(receive_chars_, count))) {
                                                
                                                LOG_DEBUG("...(!(" << err << " = on_begin_receive(receive_chars_, " << count << ")))");
                                                do {
                                                    if (!(endof_message_to_send_received)) {
                                                        LOG_DEBUG("(0 < (count = sk.recv(receive_chars_, " << sizeof(receive_chars_) << ", 0)))...");
                                                        if (0 < (count = sk.recv(receive_chars_, sizeof(receive_chars_), 0))) {

                                                            if ((endof_message_to_send_length <= count)) {
                                                                to_chars = receive_chars_+count-endof_message_to_send_length;
                                                                to_string.assign_chars(to_chars, endof_message_to_send_length);
                                                                if (endof_message_to_send_received = !(unequal = (endof_message_to_send_.compare(to_string)))) {
                                                                    count -= endof_message_to_send_length;
                                                                } else {}
                                                            } else {}
                                                            amount += count;
                                                            LOG_DEBUG("(!(err = on_receive(receive_chars_, " << count << ")))...");
                                                            if (!(err = on_receive(receive_chars_, count))) {
                                                                LOG_DEBUG("...(!(" << err << " = on_receive(receive_chars_, " << count << ")))");
                                                                continue;
                                                            } else {
                                                                LOG_DEBUG("...failed on (!(" << err << " = on_receive(receive_chars_, " << count << ")))");
                                                                break;
                                                            }
                                                        } else {
                                                            LOG_DEBUG("...failed on (0 < (count = sk.recv(receive_chars_, " << count << ", 0)))");
                                                        }
                                                    } else  {}
                                                    break;
                                                } while (0 < count);
                                                LOG_DEBUG("(!(err = on_end_receive(receive_chars_, " << amount << ")))...");
                                                if (!(err = on_end_receive(receive_chars_, amount))) {
                                                    string target(target_parameter), source(receive_chars_, amount);
                                                    
                                                    LOG_DEBUG("...(!(" << err << " = on_end_receive(receive_chars_, " << amount << ")))");
                                                    LOG_DEBUG("(!(err = on_after_receive(\"" << target << "\", \"" << source << "\")))...");
                                                    if (!(err = on_after_receive(target, source))) {

                                                        LOG_DEBUG("...(!(" << err << " = on_after_receive(\"" << target << "\", \"" << source << "\")))");
                                                        LOG_DEBUG("(!(err = before_send(\"" << target << "\", \"" << source << "\")))...");
                                                        if (!(err = before_send(target, source))) {
    
                                                            LOG_DEBUG("...(!(" << err << " = before_send(\"" << target << "\", \"" << source << "\")))");
                                                            LOG_DEBUG("((chars = target.has_chars(length)))...");
                                                            if ((chars = target.has_chars(length))) {
    
                                                                LOG_DEBUG("...((\"" << chars << "\" = target.has_chars(" << length << ")))");
                                                                LOG_DEBUG("(0 < (count = sk.send(\"" << chars << "\", " << length << ", 0)))...");
                                                                if (0 < (count = sk.send(chars, length, 0))) {
                                                                    LOG_DEBUG("...(0 < (" << count << " = sk.send(\"" << chars << "\", " << length << ", 0)))");
                                                                } else {
                                                                    LOG_DEBUG("...failed on (0 < (" << count << " = sk.send(\"" << chars << "\", " << length << ", 0)))");
                                                                }
                                                            } else {
                                                                LOG_DEBUG("...failed on ((chars = target.has_chars(" << length << ")))");
                                                            }
                                                        } else {
                                                            LOG_DEBUG("...failed on (!(" << err << " = before_send(\"" << target << "\", \"" << source << "\")))");
                                                        }
                                                    } else {
                                                        LOG_DEBUG("...failed on (!(" << err << " = on_after_receive(\"" << target << "\", \"" << source << "\")))");
                                                    }
                                                } else {
                                                    LOG_DEBUG("...failed on (!(" << err << " = on_begin_receive(receive_chars_, " << amount << ")))");
                                                }
                                            } else {
                                                LOG_DEBUG("...failed on (!(" << err << " = on_begin_receive(receive_chars_, " << count << ")))");
                                            }
                                        } else {
                                            LOG_DEBUG("...failed on (0 < (count = sk.recv(receive_chars_, " << count << ", 0)))");
                                        }
                                        LOG_DEBUG("sk.close()...");
                                        sk.close();
                                    } else {
                                        LOG_DEBUG("...failed on (!(done = !(s.accept(sk, *ep))))");
                                    }
                                } else {
                                    LOG_DEBUG("...failed on (!(done = !(sk.closed())))");
                                }
                            }
                            LOG_DEBUG("...} for (bool done = false; !done; )");
                        } else {
                            LOG_DEBUG("... failed on ((s.listen(*ep)))");
                        }
                        LOG_DEBUG("s.close()...");
                        s.close();
                    }
                    LOG_DEBUG("delete tp...");
                    delete tp;
                }
                LOG_DEBUG("delete ep...");
                delete ep;
            }
            LOG_DEBUG("host_.assign(old_host)...");
            host_.assign(old_host);
        } else {}        
        return err;
    }
    virtual int before_Accept(string &target, const string &source) {
        int err = 0;
        xos::network::sockets::os::interfaces& sockets = this->sockets();
        LOG_DEBUG("((sockets.startup()))...");
        if ((sockets.startup())) {
            LOG_DEBUG("...((sockets.startup()))");
        } else {
            LOG_DEBUG("...failed on ((sockets.startup()))");
        }
        return err;
    }
    virtual int after_Accept(string &target, const string &source) {
        int err = 0;
        xos::network::sockets::os::interfaces& sockets = this->sockets();
        LOG_DEBUG("((sockets.cleanup()))...");
        if ((sockets.cleanup())) {
            LOG_DEBUG("...((sockets.cleanup()))");
        } else {
            LOG_DEBUG("...failed on ((sockets.cleanup()))");
        }
        return err;
    }
    virtual int all_Accept(string &target, const string &source) {
        int err = 0;
        do {
            set_accept_done(false);
            set_accept_restart(false);
            
            if (!(err = before_Accept(target, source))) {
                int err2 = 0;
                err = Accept(target, source);
                if ((err2 = after_Accept(target, source))) {
                    if (!(err)) err = err2;
                }
            }
        } while (get_accept_restart());
        return err;
    }
    virtual int all_AcceptOne(string &target, const string &source) {
        int err = 0;
        bool old_accept_one = get_accept_one();
        set_accept_one(true);
        if (!(err = all_Accept(target, source))) {
        }
        set_accept_one(old_accept_one);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...Connect
    virtual int Connect(string &target, const string &source) {
        int err = 0;
        send_t send = 0;

        LOG_DEBUG("set_source_parameter(\"" << source << "\")...");
        set_source_parameter(source);
        
        LOG_DEBUG("set_target_parameter(\"" << target << "\")...");
        set_target_parameter(target);
        
        LOG_DEBUG("((send = (this->send_)))...");
        if ((send = (this->send_))) {
            string target(source);

            LOG_DEBUG("(!(err = before_send(\"" << target << "\", \"" << source << "\")))...");
            if (!(err = before_send(target, source))) {
                const char* chars = 0;
                size_t length = 0;

                LOG_DEBUG("((chars = target.has_chars(length)))...");
                if ((chars = target.has_chars(length))) {
                    xos::network::sockets::endpoint* ep = 0;
        
                    LOG_DEBUG("((epoint_) && (ep = ((this->*epoint_)())))...");
                    if ((epoint_) && (ep = ((this->*epoint_)()))) {
                        xos::network::sockets::transport* tp = 0;
        
                        LOG_DEBUG("((tport_) && (tp = (this->*tport_)()))...");
                        if ((tport_) && (tp = (this->*tport_)())) {
                            xos::network::sockets::os::interface s;
        
                            LOG_DEBUG("if ((s.open(*tp)))...");
                            if ((s.open(*tp))) {

                                LOG_DEBUG("(this->*send)(s, *ep, chars, length)...");
                                (this->*send)(s, *ep, chars, length);
                                LOG_DEBUG("s.close()...");
                                s.close();
                            }
                            LOG_DEBUG("delete tp...");
                            delete tp;
                        }
                        LOG_DEBUG("delete ep...");
                        delete ep;
                    }
                } else {}
            } else {}
        } else {}        
        return err;
    }
    virtual int before_Connect(string &target, const string &source) {
        int err = 0;
        xos::network::sockets::os::interfaces& sockets = this->sockets();
        LOG_DEBUG("((sockets.startup()))...");
        if ((sockets.startup())) {
            LOG_DEBUG("...((sockets.startup()))");
        } else {
            LOG_DEBUG("...failed on ((sockets.startup()))");
        }
        return err;
    }
    virtual int after_Connect(string &target, const string &source) {
        int err = 0;
        xos::network::sockets::os::interfaces& sockets = this->sockets();
        LOG_DEBUG("((sockets.cleanup()))...");
        if ((sockets.cleanup())) {
            LOG_DEBUG("...((sockets.cleanup()))");
        } else {
            LOG_DEBUG("...failed on ((sockets.cleanup()))");
        }
        return err;
    }
    virtual int all_Connect(string &target, const string &source) {
        int err = 0;
        if (!(err = before_Connect(target, source))) {
            int err2 = 0;
            err = Connect(target, source);
            if ((err2 = after_Connect(target, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    virtual int before_send(string &target, const string &source) {
        int err = 0;
        const char_t cr = ((char_t)'\r'), lf = ((char_t)'\n');
        const char* chars = 0;
        size_t length = 0;

        LOG_DEBUG("((chars = source.has_chars(length)))...");
        if ((chars = source.has_chars(length))) {

            LOG_DEBUG("...((\"" << chars << "\" = source.has_chars(" << length << ")))");
            LOG_DEBUG("for (size_t index = " << length << "; index; --index) {...");
            for (size_t index = length; index; --index) {
                char_t ch = chars[index - 1];
                if ((lf != ch) && ((cr != ch))) {

                    LOG_DEBUG("((index = " << index << " < length = " << length << "))...");
                    if ((index < length)) {

                        LOG_DEBUG("target.assign(\"" << chars << "\", " << index << ")...");
                        target.assign(chars, index);
                    } else {}
                    break;
                }
            }
        } else {
            LOG_DEBUG("...failed on ((chars = source.has_chars(" << length << ")))");
        }
        LOG_DEBUG("target.append(\"" << endof_message_to_send_ << "\")...");
        target.append(endof_message_to_send_);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int tcp_send
    (xos::network::sockets::interface& s, xos::network::sockets::endpoint& ep, const char_t* chars, size_t length) {
        int err = 0;

        LOG_DEBUG("((s.connect(ep)))...");
        if ((s.connect(ep))) {
            ssize_t count = 0;

            LOG_DEBUG("(0 < (count = s.send(\"" << chars << "\", " << length << ", 0)))...");
            if (0 < (count = s.send(chars, length, 0))) {

                LOG_DEBUG("...(0 < (" << count << " = s.send(\"" << chars << "\", " << length << ", 0)))");
                LOG_DEBUG("(0 < (count = s.recv(receive_chars_, " << sizeof(receive_chars_) << ", 0)))...");
                if (0 < (count = s.recv(receive_chars_, sizeof(receive_chars_), 0))) {
                    size_t amount = count;

                    LOG_DEBUG("(!(err = on_begin_receive(receive_chars_, " << count << ")))...");
                    if (!(err = on_begin_receive(receive_chars_, count))) {

                        LOG_DEBUG("...(!(" << err << " = on_begin_receive(receive_chars_, " << count << ")))");
                        do {
                            LOG_DEBUG("(0 < (count = s.recv(receive_chars_, " << sizeof(receive_chars_) << ", 0)))...");
                            if (0 < (count = s.recv(receive_chars_, sizeof(receive_chars_), 0))) {
                                LOG_DEBUG("(!(err = on_receive(receive_chars_, " << count << ")))...");
                                if (!(err = on_receive(receive_chars_, count))) {
                                    LOG_DEBUG("...(!(" << err << " = on_receive(receive_chars_, " << count << ")))");
                                    continue;
                                } else {
                                    LOG_DEBUG("...failed on (!(" << err << " = on_receive(receive_chars_, " << count << ")))");
                                    break;
                                }
                            } else {
                                LOG_DEBUG("...failed on (0 < (count = s.recv(receive_chars_, " << count << ", 0)))");
                            }
                            break;
                        } while (0 < count);

                        LOG_DEBUG("(!(err = on_end_receive(receive_chars_, " << amount << ")))...");
                        if (!(err = on_end_receive(receive_chars_, amount))) {
                            const string& source = this->source_parameter();
                            string& target_result = this->target_result();
                            string target(receive_chars_, amount);

                            LOG_DEBUG("target_result.assign(\"" << target << "\")...");
                            target_result.assign(target);
                            
                            LOG_DEBUG("(!(err = on_after_receive(\"" << target << "\", \"" << source << "\")))...");
                            if (!(err = on_after_receive(target, source))) {
                                LOG_DEBUG("...(!(" << err << " = on_after_receive(\"" << target << "\", \"" << source << "\")))");
                            } else {
                                LOG_DEBUG("...failed on (!(" << err << " = on_after_receive(\"" << target << "\", \"" << source << "\")))");
                            }
                            LOG_DEBUG("...(!(" << err << " = on_end_receive(receive_chars_, " << amount << ")))");
                        } else {
                            LOG_DEBUG("...failed on (!(" << err << " = on_begin_receive(receive_chars_, " << amount << ")))");
                        }
                    } else {
                        LOG_DEBUG("...failed on (!(" << err << " = on_begin_receive(receive_chars_, " << count << ")))");
                    }
                } else {
                    LOG_DEBUG("...failed on (0 < (count = s.recv(receive_chars_, " << count << ", 0)))");
                }
            } else {
                LOG_ERROR("...failed on (0 < (" << count << " = s.send(\"" << chars << "\", " << length << ", 0)))");
            }
        } else {
            const string& target_parameter = this->target_parameter();
            string& target_result = this->target_result();

            LOG_DEBUG("...failed on ((s.connect(ep)))");
            LOG_DEBUG("target_result.assign(\"" << target_parameter << "\")...");
            target_result.assign(target_parameter);
        }
        return 0;
    }
    virtual int udp_send
    (xos::network::sockets::interface& s, xos::network::sockets::endpoint& ep, const char_t* chars, size_t length) {
        ssize_t count = 0;

        LOG_DEBUG("(0 < (count = s.sendto(\"" << chars << "\", " << length << ", 0, ep)))...");
        if (0 < (count = s.sendto(chars, length, 0, ep))) {
            LOG_DEBUG("...(0 < (" << count << " = s.sendto(\"" << chars << "\", " << length << ", 0, ep)))");
        } else {
            LOG_ERROR("... failed on (0 < (" << count << " = s.sendto(\"" << chars << "\", " << length << ", 0, ep)))");
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
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
        return err;
    }
    ///////////////////////////////////////////////////////////////////////

public:
    //////////////////////////////////////////////////////////////////////////
    /// ..host / ..port
    /// ...
    /// ...host / ...port
    virtual string_t& set_host(const string_t& to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual string_t& set_host(const char_t* to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual const string_t& get_host() const {
        return this->host();
    }
    virtual string_t& host() const {
        return this->connect_host();
    }
    virtual short& set_port(const short& to) {
        this->set_accept_port(to);
        this->set_connect_port(to);
        return this->port();
    }
    virtual const short& get_port() const {
        return this->port();
    }
    virtual short& port() const {
        return this->connect_port();
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_host / ...accept_port
    virtual string_t& set_accept_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_accept_host(chars);
    }
    virtual string_t& set_accept_host(const char_t* to) {
        string_t& accept_host = this->accept_host();
        if ((to)) accept_host.assign(to);
        else accept_host.clear();
        return accept_host;
    }
    virtual const string_t& get_accept_host() const {
        return this->accept_host();
    }
    virtual string_t& accept_host() const {
        return (string_t&)accept_host_;
    }
    virtual short& set_accept_port(const short& to) {
        short& accept_port = this->accept_port();
        accept_port = to;
        return accept_port;
    }
    virtual const short& get_accept_port() const {
        return this->accept_port();
    }
    virtual short& accept_port() const {
        return (short&)accept_port_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_one / ...accept_done / ...accept_restart
    virtual bool& set_accept_one(const bool& to = true) {
        bool& accept_one = this->accept_one();
        accept_one = to;
        return accept_one;
    }
    virtual const bool& get_accept_one() const {
        return this->accept_one();
    }
    virtual bool& accept_one() const {
        return (bool&)accept_one_;
    }
    /// ...accept_done
    virtual bool& set_accept_done(const bool& to = true) {
        bool& accept_done = this->accept_done();
        accept_done = to;
        return accept_done;
    }
    virtual bool get_accept_done() const {
        bool& accept_one = this->accept_one();
        bool& accept_done = this->accept_done();
        bool& accept_restart = this->accept_restart();
        bool result = (accept_one || accept_done || accept_restart);
        return result;
    }
    virtual bool& accept_done() const {
        return (bool&)accept_done_;
    }
    virtual bool& stop_set(const bool& to) {
        bool& stop = this->stop();
        LOGGER_IS_LOGGED_INFO("(true == (stop = " << stop << "))...");
        if (true == (stop)) {
            LOGGER_IS_LOGGED_INFO("...(true == (stop = " << stop << "))");
            LOGGER_IS_LOGGED_INFO("set_accept_done(stop = " << stop << ")...");
            set_accept_done(stop);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (true == (stop = " << stop << "))");
        }
        return stop;
    }
    /// ...accept_restart
    virtual bool& set_accept_restart(const bool& to = true) {
        bool& accept_restart = this->accept_restart();
        accept_restart = to;
        return accept_restart;
    }
    virtual bool get_accept_restart() const {
        return this->accept_restart();
    }
    virtual bool& accept_restart() const {
        return (bool&)accept_restart_;
    }
    virtual bool& restart_set(const bool& to) {
        bool& restart = this->restart();
        LOGGER_IS_LOGGED_INFO("(true == (restart = " << restart << "))...");
        if (true == (restart)) {
            LOGGER_IS_LOGGED_INFO("...(true == (restart = " << restart << "))");
            LOGGER_IS_LOGGED_INFO("set_accept_done(restart = " << restart << ")...");
            set_accept_restart(restart);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (true == (restart = " << restart << "))");
        }
        return restart;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...connect_host / ...connect_port
    virtual string_t& set_connect_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_connect_host(chars);
    }
    virtual string_t& set_connect_host(const char_t* to) {
        string_t& connect_host = this->connect_host();
        if ((to)) connect_host.assign(to);
        else connect_host.clear();
        return connect_host;
    }
    virtual const string_t& get_connect_host() const {
        return this->connect_host();
    }
    virtual string_t& connect_host() const {
        return (string_t&)connect_host_;
    }
    virtual short& set_connect_port(const short& to) {
        short& connect_port = this->connect_port();
        connect_port = to;
        return connect_port;
    }
    virtual const short& get_connect_port() const {
        return this->connect_port();
    }
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...relay_host / ...relay_port
    virtual string_t& set_relay_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_relay_host(chars);
    }
    virtual string_t& set_relay_host(const char_t* to) {
        string_t& relay_host = this->relay_host();
        if ((to)) relay_host.assign(to);
        else relay_host.clear();
        return relay_host;
    }
    virtual const string_t& get_relay_host() const {
        return this->relay_host();
    }
    virtual string_t& relay_host() const {
        return (string_t&)relay_host_;
    }
    virtual short& set_relay_port(const short& to) {
        short& relay_port = this->relay_port();
        relay_port = to;
        return relay_port;
    }
    virtual const short& get_relay_port() const {
        return this->relay_port();
    }
    virtual short& relay_port() const {
        return (short&)relay_port_;
    }
    /// ...
    /// ..host / ..port
    //////////////////////////////////////////////////////////////////////////

protected:
    //////////////////////////////////////////////////////////////////////////
    /// ...ep
    xos::network::sockets::endpoint& (derives::*accept_ep_)() const;
    virtual xos::network::sockets::endpoint& accept_ep() const {
        if ((this->accept_ep_)) {
            return (this->*accept_ep_)();
        }
        return this->default_accept_ep();
    }
    virtual xos::network::sockets::endpoint& default_accept_ep() const {
        return this->accept_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& accept_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& accept_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////
    /// ...tp
    xos::network::sockets::transport& (derives::*accept_tp_)() const;
    virtual xos::network::sockets::transport& accept_tp() const {
        if ((this->accept_tp_)) {
            return (this->*accept_tp_)();
        }
        return this->default_accept_tp();
    }
    virtual xos::network::sockets::transport& default_accept_tp() const {
        return this->accept_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& accept_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& accept_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...ep
    xos::network::sockets::endpoint& (derives::*connect_ep_)() const;
    virtual xos::network::sockets::endpoint& connect_ep() const {
        if ((this->connect_ep_)) {
            return (this->*connect_ep_)();
        }
        return this->default_connect_ep();
    }
    virtual xos::network::sockets::endpoint& default_connect_ep() const {
        return this->connect_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& connect_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& connect_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////
    /// ...tp
    xos::network::sockets::transport& (derives::*connect_tp_)() const;
    virtual xos::network::sockets::transport& connect_tp() const {
        if ((this->connect_tp_)) {
            return (this->*connect_tp_)();
        }
        return this->default_connect_tp();
    }
    virtual xos::network::sockets::transport& default_connect_tp() const {
        return this->connect_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& connect_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& connect_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...iface / ...addr / ...ep/ ...tp
    /// ...
    /// ...os_iface
    virtual xos::network::sockets::os::interfaces& sockets() const {
        return (xos::network::sockets::os::interfaces&)sockets_;
    }
    virtual xos::network::sockets::os::interface& accept_os_iface() const {
        return (xos::network::sockets::os::interface&)accept_os_iface_;
    }
    virtual xos::network::sockets::os::interface& connect_os_iface() const {
        return (xos::network::sockets::os::interface&)connect_os_iface_;
    }
    virtual xos::network::sockets::os::interface& relay_os_iface() const {
        return (xos::network::sockets::os::interface&)relay_os_iface_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...iface
    virtual xos::network::sockets::interface& accept_iface() const {
        return (xos::network::sockets::interface&)accept_os_iface();
    }
    virtual xos::network::sockets::interface& connect_iface() const {
        return (xos::network::sockets::interface&)connect_os_iface();
    }
    virtual xos::network::sockets::interface& relay_iface() const {
        return (xos::network::sockets::interface&)relay_os_iface();
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...addr /  ...addrlen
    virtual xos::network::sockets::sockaddr_t& accept_addr() const {
        return (xos::network::sockets::sockaddr_t&)accept_addr_;
    }
    virtual xos::network::sockets::socklen_t& accept_addrlen() const {
        return (xos::network::sockets::socklen_t&)accept_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& connect_addr() const {
        return (xos::network::sockets::sockaddr_t&)connect_addr_;
    }
    virtual xos::network::sockets::socklen_t& connect_addrlen() const {
        return (xos::network::sockets::socklen_t&)connect_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& relay_addr() const {
        return (xos::network::sockets::sockaddr_t&)relay_addr_;
    }
    virtual xos::network::sockets::socklen_t& relay_addrlen() const {
        return (xos::network::sockets::socklen_t&)relay_addrlen_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...ep
    xos::network::sockets::endpoint& (derives::*ep_)() const;
    virtual xos::network::sockets::endpoint& ep() const {
        if ((this->ep_)) {
            return (this->*ep_)();
        }
        return this->default_ep();
    }
    virtual xos::network::sockets::endpoint& default_ep() const {
        return this->ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& ip_v4_ep() const {
        return (xos::network::sockets::endpoint&)ip_v4_ep_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& ip_v6_ep() const {
        return (xos::network::sockets::endpoint&)ip_v6_ep_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////
    /// ...tp
    xos::network::sockets::transport& (derives::*tp_)() const;
    virtual xos::network::sockets::transport& tp() const {
        if ((this->tp_)) {
            return (this->*tp_)();
        }
        return this->default_tp();
    }
    virtual xos::network::sockets::transport& default_tp() const {
        return this->ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& ip_v4_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v4_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_udp_tp_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& ip_v6_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v6_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_udp_tp_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    /// ...
    /// ...iface / ...addr / ...ep/ ...tp
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...restart / ...stop
    virtual bool& restart() const {
        return (bool&)restart_;
    }
    virtual bool& stop() const {
        return (bool&)stop_;
    }
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::sockets::transport* ip_v4_tcp_tport() {
        xos::network::sockets::transport* tp = new xos::network::sockets::ip::v4::tcp::transport();
        return tp;
    }
    virtual xos::network::sockets::transport* ip_v4_udp_tport() {
        xos::network::sockets::transport* tp = new xos::network::sockets::ip::v4::udp::transport();
        return tp;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::sockets::transport* ip_v6_tcp_tport() {
        xos::network::sockets::transport* tp = new xos::network::sockets::ip::v6::tcp::transport();
        return tp;
    }
    virtual xos::network::sockets::transport* ip_v6_udp_tport() {
        xos::network::sockets::transport* tp = new xos::network::sockets::ip::v6::udp::transport();
        return tp;
    }
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::sockets::endpoint* ip_v4_epoint() {
        const char_t* host = 0;
        ushort port = 0;
        int unequal = 0;
        try {
            if ((host = host_.has_chars()) && (0 < (port = portno_))) {
                if (!(unequal = host_.compare(any_host_))) {
                    xos::network::sockets::endpoint* ep = new xos::network::sockets::ip::v4::endpoint(port);
                    return ep;
                } else{
                    xos::network::sockets::endpoint* ep = new xos::network::sockets::ip::v4::endpoint(host, port);
                    return ep;
                }
            } else {
                if ((0 < (port = portno_))) {
                    xos::network::sockets::endpoint* ep = new xos::network::sockets::ip::v4::endpoint(port);
                    return ep;
                }
            }
        } catch(endpoint_exception_t){
            return 0;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::sockets::endpoint* ip_v6_epoint() {
        const char_t* host = 0;
        ushort port = 0;
        int unequal = 0;
        try {
            if ((host = host_.has_chars()) && (0 < (port = portno_))) {
                if (!(unequal = host_.compare(any_host_))) {
                    xos::network::sockets::endpoint* ep = new xos::network::sockets::ip::v6::endpoint(port);
                    return ep;
                } else{
                    xos::network::sockets::endpoint* ep = new xos::network::sockets::ip::v6::endpoint(host, port);
                    return ep;
                }
            } else {
                if ((0 < (port = portno_))) {
                    xos::network::sockets::endpoint* ep = new xos::network::sockets::ip::v6::endpoint(port);
                    return ep;
                }
            }
        } catch(endpoint_exception_t){
            return 0;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
public:
    virtual const string& get_target_result() const {
        const string& target_result = this->target_result();
        return target_result;
    }
protected:
    virtual string& set_target_result(const string& to) {
        string& target_result = this->target_result();
        target_result.assign(to);
        return target_result;
    }
    virtual string& target_result() const {
        return (string&)target_result_;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual string& set_target_parameter(const string& to) {
        string& target_parameter = this->target_parameter();
        target_parameter.assign(to);
        return target_parameter;
    }
    virtual string& target_parameter() const {
        return (string&)target_parameter_;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual string& set_source_parameter(const string& to) {
        string& source_parameter = this->source_parameter();
        source_parameter.assign(to);
        return source_parameter;
    }
    virtual string& source_parameter() const {
        return (string&)source_parameter_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    bool restart_, stop_;
    bool accept_one_, accept_done_, accept_restart_;
    string_t accept_host_, connect_host_, relay_host_;
    short accept_port_, connect_port_, relay_port_;
    send_t send_;
    endpoint_t epoint_;
    transport_t tport_;
    ushort portno_;
    string_t port_, host_, any_host_, endof_message_to_send_;

    xos::network::sockets::os::interfaces sockets_;
    xos::network::sockets::os::interface accept_os_iface_, connect_os_iface_, relay_os_iface_;
    xos::network::sockets::interface accept_iface_, connect_iface_, relay_iface_;

    xos::network::sockets::sockaddr_t accept_addr_, connect_addr_, relay_addr_;
    xos::network::sockets::socklen_t accept_addrlen_, connect_addrlen_, relay_addrlen_;

    xos::network::sockets::ip::v4::endpoint ip_v4_ep_;
    xos::network::sockets::ip::v4::tcp::transport ip_v4_tcp_tp_;
    xos::network::sockets::ip::v4::udp::transport ip_v4_udp_tp_;

#if !defined(WINSOCK_1)
    xos::network::sockets::ip::v6::endpoint ip_v6_ep_;
    xos::network::sockets::ip::v6::tcp::transport ip_v6_tcp_tp_;
    xos::network::sockets::ip::v6::udp::transport ip_v6_udp_tp_;
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    string source_parameter_, target_parameter_, target_result_;
    char_t receive_chars_[ULUCIDITY_NETWORK_SOCKETS_BASE_RECEIVE_SIZE];
}; /// class Maint
typedef Maint<> Main;

} /// namespace Base 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_HH
