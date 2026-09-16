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
///   File: Base.hh
///
/// Author: $author$
///   Date: 9/29/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_NETWORK_SOCKETS_BASE_HH
#define ULUCIDITY_NETWORK_SOCKETS_BASE_HH

#include "uLucidity/Base/Base.hpp"
#include "xos/network/os/sockets.hpp"
#include "xos/network/os/socket.hpp"
#include "xos/network/ip/v6/udp/transport.hpp"
#include "xos/network/ip/v6/tcp/transport.hpp"
#include "xos/network/ip/v6/endpoint.hpp"
#include "xos/network/ip/v4/udp/transport.hpp"
#include "xos/network/ip/v4/tcp/transport.hpp"
#include "xos/network/ip/v4/endpoint.hpp"
#include "xos/network/local/stream/transport.hpp"
#include "xos/network/local/dgram/transport.hpp"
#include "xos/network/local/endpoint.hpp"

#define ULUCIDITY_NETWORK_SOCKETS_UDENTIFY_HOST "udentify"
#define ULUCIDITY_NETWORK_SOCKETS_UDENTIFY_PORTNO 8484

#define ULUCIDITY_NETWORK_SOCKETS_BASE_RECEIVE_SIZE 4096
#define ULUCIDITY_NETWORK_SOCKETS_BASE_PORTNO ULUCIDITY_NETWORK_SOCKETS_UDENTIFY_PORTNO
#define ULUCIDITY_NETWORK_SOCKETS_BASE_PORT XOS_BASE_2STRING(ULUCIDITY_NETWORK_SOCKETS_BASE_PORTNO)
#define ULUCIDITY_NETWORK_SOCKETS_BASE_HOST ULUCIDITY_NETWORK_SOCKETS_UDENTIFY_HOST
#define ULUCIDITY_NETWORK_SOCKETS_BASE_ANY_HOST "*"
#define ULUCIDITY_NETWORK_SOCKETS_BASE_ACCEPT_HOST ULUCIDITY_NETWORK_SOCKETS_BASE_ANY_HOST
#define ULUCIDITY_NETWORK_SOCKETS_BASE_ENDOF_MESSAGE_TO_SEND "\r\n"

namespace uLucidity {
namespace Network {
namespace Sockets {

//////////////////////////////////////////////////////////////////////////
/// class Baset
template <class TExtends = uLucidity::Base, class TImplements = uLucidity::ImplementBase>
class _EXPORT_CLASS Baset: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Baset Derives;

    typedef xos::base::string string;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Baset()
    : accept_one_(false),
      run_(0),
      send_(&Derives::tcp_send),
      ep_(&Derives::ip_v4_ep),
      tp_(&Derives::ip_v4_tcp_tp),
      portno_(ULUCIDITY_NETWORK_SOCKETS_BASE_PORTNO),
      port_(ULUCIDITY_NETWORK_SOCKETS_BASE_PORT),
      host_(ULUCIDITY_NETWORK_SOCKETS_BASE_HOST),
      accept_host_(ULUCIDITY_NETWORK_SOCKETS_BASE_ACCEPT_HOST),
      any_host_(ULUCIDITY_NETWORK_SOCKETS_BASE_ANY_HOST),
      endof_message_to_send_(ULUCIDITY_NETWORK_SOCKETS_BASE_ENDOF_MESSAGE_TO_SEND) {
    }
    virtual ~Baset() {
    }
private:
    Baset(const Baset &copy) {
    }
public:

    ///////////////////////////////////////////////////////////////////////
protected:
    typedef xos::base::string string_t;
    typedef xos::base::string::char_t char_t;
    typedef int (Derives::*run_t)(string &target, const string &source);
    typedef int (Derives::*send_t)(xos::network::socket& s, xos::network::endpoint& ep, const char_t* chars, size_t length);
    typedef int (Derives::*listen_t)(xos::network::socket& s, xos::network::endpoint& ep);
    typedef xos::network::endpoint* (Derives::*endpoint_t)();
    typedef xos::network::transport* (Derives::*transport_t)();
    typedef xos::network::endpoint_exception_t endpoint_exception_t;

public:
    //////////////////////////////////////////////////////////////////////////
    /// class Events
    class _EXPORT_CLASS Events: virtual public uLucidity::ImplementBase {
    public:
        typedef uLucidity::ImplementBase Implements;
        typedef typename Baset::string string;
        typedef typename Baset::char_t char_t;
    
        //////////////////////////////////////////////////////////////////////////
        /// constructor / destructor
        virtual ~Events() {
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
            LOG_INFO("...");
            return err;
        }
    }; /// class Events

protected:
    //////////////////////////////////////////////////////////////////////////
    /// ...Run
    virtual int Run(string &target, const string &source) {
        int err = 0;
        if (run_) {
            LOG_INFO("(!(err = (this->*run_)(target, source)))...");
            if (!(err = (this->*run_)(target, source))) {
                LOG_INFO("...(!(" << err << " = (this->*run_)(target, source)))");
            } else {
                LOG_INFO("...failed on (!(" << err << " = (this->*run_)(target, source)))");
            }
        } else {
            LOG_INFO("(!(err = default_Run(target, source)))...");
            if (!(err = default_Run(target, source))) {
                LOG_INFO("...(!(" << err << " = default_Run(target, source)))");
            } else {
                LOG_INFO("...failed on(!(" << err << " = default_Run(target, source)))");
            }
        }
        return err;
    }
    virtual int default_Run(string &target, const string &source) {
        int err = 0;
        LOG_INFO("...in");
        LOG_INFO("out...");
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

        LOG_DEBUG("host_.assign(accept_host_)...");
        host_.assign(accept_host_);

        LOG_DEBUG("((send = (this->send_)))...");
        if ((send = (this->send_))) {
            xos::network::endpoint* ep = 0;
    
            LOG_DEBUG("((ep_) && (ep = ((this->*ep_)())))...");
            if ((ep_) && (ep = ((this->*ep_)()))) {
                xos::network::transport* tp = 0;
    
                LOG_DEBUG("((tp_) && (tp = (this->*tp_)()))...");
                if ((tp_) && (tp = (this->*tp_)())) {
                    xos::network::os::socket s;
    
                    LOG_DEBUG("((s.open(*tp)))...");
                    if ((s.open(*tp))) {
    
                        LOG_DEBUG("((s.listen(*ep)))...");
                        if ((s.listen(*ep))) {
                            size_t endof_message_to_send_length = endof_message_to_send_.length();
                            xos::network::os::socket sk;
                            
                            LOG_DEBUG("for (bool done = false; !done; ) {...");
                            for (bool done = false; !done; done = accept_one_) {
                                
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
                                            const char* to_chars = 0;
                                            size_t amount = count;

                                            if ((endof_message_to_send_length <= count)) {
                                                to_chars = receive_chars_+count-endof_message_to_send_length;
                                                if (endof_message_to_send_received = !(0 != (endof_message_to_send_.compare(to_chars, endof_message_to_send_length)))) {
                                                    amount = (count -= endof_message_to_send_length);
                                                } else {}
                                            } else {}
                                            LOG_DEBUG("(!(err = on_begin_receive(receive_chars_, " << count << ")))...");
                                            if (!(err = on_begin_receive(receive_chars_, count))) {
                                                string target(source);
                                                
                                                LOG_DEBUG("...(!(" << err << " = on_begin_receive(receive_chars_, " << count << ")))");
                                                do {
                                                    if (!(endof_message_to_send_received)) {
                                                        LOG_DEBUG("(0 < (count = sk.recv(receive_chars_, " << sizeof(receive_chars_) << ", 0)))...");
                                                        if (0 < (count = sk.recv(receive_chars_, sizeof(receive_chars_), 0))) {

                                                            if ((endof_message_to_send_length <= count)) {
                                                                to_chars = receive_chars_+count-endof_message_to_send_length;
                                                                if (endof_message_to_send_received = !(0 != (endof_message_to_send_.compare(to_chars, endof_message_to_send_length)))) {
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
                                                    string source(receive_chars_, amount);
                                                    
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
        LOG_DEBUG("((xos::network::os::sockets::startup()))...");
        if ((xos::network::os::sockets::startup())) {
            LOG_DEBUG("...((xos::network::os::sockets::startup()))");
        } else {
            LOG_DEBUG("...failed on ((xos::network::os::sockets::startup()))");
        }
        return err;
    }
    virtual int after_Accept(string &target, const string &source) {
        int err = 0;
        LOG_DEBUG("((xos::network::os::sockets::cleanup()))...");
        if ((xos::network::os::sockets::cleanup())) {
            LOG_DEBUG("...((xos::network::os::sockets::cleanup()))");
        } else {
            LOG_DEBUG("...failed on ((xos::network::os::sockets::cleanup()))");
        }
        return err;
    }
    virtual int all_Accept(string &target, const string &source) {
        int err = 0;
        if (!(err = before_Accept(target, source))) {
            int err2 = 0;
            err = Accept(target, source);
            if ((err2 = after_Accept(target, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int all_AcceptOne(string &target, const string &source) {
        int err = 0;
        bool old_accept_one = accept_one_;
        accept_one_ = true;
        if (!(err = before_Accept(target, source))) {
            int err2 = 0;
            err = Accept(target, source);
            if ((err2 = after_Accept(target, source))) {
                if (!(err)) err = err2;
            }
        }
        accept_one_ = old_accept_one;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...Connect
    virtual int Connect(string &target, const string &source) {
        int err = 0;
        send_t send = 0;

        LOG_DEBUG("((send = (this->send_)))...");
        if ((send = (this->send_))) {
            string target(source);

            LOG_DEBUG("(!(err = before_send(target, \"" << source << "\")))...");
            if (!(err = before_send(target, source))) {
                const char* chars = 0;
                size_t length = 0;

                LOG_DEBUG("((chars = target.has_chars(length)))...");
                if ((chars = target.has_chars(length))) {
                    xos::network::endpoint* ep = 0;
        
                    LOG_DEBUG("((ep_) && (ep = ((this->*ep_)())))...");
                    if ((ep_) && (ep = ((this->*ep_)()))) {
                        xos::network::transport* tp = 0;
        
                        LOG_DEBUG("((tp_) && (tp = (this->*tp_)()))...");
                        if ((tp_) && (tp = (this->*tp_)())) {
                            xos::network::os::socket s;
        
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
        LOG_DEBUG("((xos::network::os::sockets::startup()))...");
        if ((xos::network::os::sockets::startup())) {
            LOG_DEBUG("...((xos::network::os::sockets::startup()))");
        } else {
            LOG_DEBUG("...failed on ((xos::network::os::sockets::startup()))");
        }
        return err;
    }
    virtual int after_Connect(string &target, const string &source) {
        int err = 0;
        LOG_DEBUG("((xos::network::os::sockets::cleanup()))...");
        if ((xos::network::os::sockets::cleanup())) {
            LOG_DEBUG("...((xos::network::os::sockets::cleanup()))");
        } else {
            LOG_DEBUG("...failed on ((xos::network::os::sockets::cleanup()))");
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
    ///////////////////////////////////////////////////////////////////////
    virtual int tcp_send
    (xos::network::socket& s, xos::network::endpoint& ep, const char_t* chars, size_t length) {
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
            LOG_DEBUG("...failed on ((s.connect(ep)))");
        }
        return 0;
    }
    virtual int udp_send
    (xos::network::socket& s, xos::network::endpoint& ep, const char_t* chars, size_t length) {
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
    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::transport* ip_v4_tcp_tp() {
        xos::network::transport* tp = new xos::network::ip::v4::tcp::transport();
        return tp;
    }
    virtual xos::network::transport* ip_v4_udp_tp() {
        xos::network::transport* tp = new xos::network::ip::v4::udp::transport();
        return tp;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::transport* ip_v6_tcp_tp() {
        xos::network::transport* tp = new xos::network::ip::v6::tcp::transport();
        return tp;
    }
    virtual xos::network::transport* ip_v6_udp_tp() {
        xos::network::transport* tp = new xos::network::ip::v6::udp::transport();
        return tp;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::endpoint* ip_v4_ep() {
        const char_t* host = 0;
        ushort port = 0;
        int unequal = 0;
        try {
            if ((host = host_.has_chars()) && (0 < (port = portno_))) {
                if (!(unequal = host_.compare(any_host_))) {
                    xos::network::endpoint* ep = new xos::network::ip::v4::endpoint(port);
                    return ep;
                } else{
                    xos::network::endpoint* ep = new xos::network::ip::v4::endpoint(host, port);
                    return ep;
                }
            } else {
                if ((0 < (port = portno_))) {
                    xos::network::endpoint* ep = new xos::network::ip::v4::endpoint(port);
                    return ep;
                }
            }
        } catch(endpoint_exception_t){
            return 0;
        }
        return 0;
    }
    virtual xos::network::endpoint* ip_v6_ep() {
        const char_t* host = 0;
        ushort port = 0;
        int unequal = 0;
        try {
            if ((host = host_.has_chars()) && (0 < (port = portno_))) {
                if (!(unequal = host_.compare(any_host_))) {
                    xos::network::endpoint* ep = new xos::network::ip::v6::endpoint(port);
                    return ep;
                } else{
                    xos::network::endpoint* ep = new xos::network::ip::v6::endpoint(host, port);
                    return ep;
                }
            } else {
                if ((0 < (port = portno_))) {
                    xos::network::endpoint* ep = new xos::network::ip::v6::endpoint(port);
                    return ep;
                }
            }
        } catch(endpoint_exception_t){
            return 0;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_host(const char_t* to) {
        host_.assign(to);
    }
    virtual void set_port(const char_t* to) {
        std::stringstream ss(to);
        int no;
        ss >> no;
        if (0 < (no)) {
            portno_ = no;
            port_.assign(to);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_transport_tcp() {
        send_ = &Derives::tcp_send;
        ///listen_ = &Derives::server_tcp_listen;
        if ((&Derives::ip_v4_ep == ep_)) {
            tp_ = &Derives::ip_v4_tcp_tp;
        } else {
            if ((&Derives::ip_v6_ep == ep_)) {
                tp_ = &Derives::ip_v6_tcp_tp;
            } else {
            }
        }
    }
    virtual void set_transport_udp() {
        send_ = &Derives::udp_send;
        ///listen_ = &Derives::server_udp_listen;
        if ((&Derives::ip_v4_ep == ep_)) {
            tp_ = &Derives::ip_v4_udp_tp;
        } else {
            if ((&Derives::ip_v6_ep == ep_)) {
                tp_ = &Derives::ip_v6_udp_tp;
            } else {
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_family_ip_v4() {
        ep_ = &Derives::ip_v4_ep;
        if ((is_stream_tp())) {
            tp_ = &Derives::ip_v4_tcp_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &Derives::ip_v4_udp_tp;
            } else {
            }
        }
    }
    virtual void set_family_ip_v6() {
        ep_ = &Derives::ip_v6_ep;
        if ((is_stream_tp())) {
            tp_ = &Derives::ip_v6_tcp_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &Derives::ip_v6_udp_tp;
            } else {
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_stream_tp() const {
        if ((&Derives::ip_v4_tcp_tp == tp_)
            || (&Derives::ip_v6_tcp_tp == tp_)
            /*|| (&Derives::local_stream_tp == tp_)*/) {
            return true;
        }
        return false;
    }
    virtual bool is_dgram_tp() const {
        if ((&Derives::ip_v4_udp_tp == tp_)
            || (&Derives::ip_v6_udp_tp == tp_)
            /*|| (&Derives::local_dgram_tp == tp_)*/) {
            return true;
        }
        return false;
    }
public:
    virtual bool& set_accept_one(const bool& to = true) {
        bool& accept_one = this->accept_one();
        accept_one = to;
        return accept_one;
    }
    virtual bool& accept_one() const {
        return (bool&)accept_one_;
    }

    //////////////////////////////////////////////////////////////////////////
protected:
    bool accept_one_;
    run_t run_;
    send_t send_;
    listen_t listen_;
    endpoint_t ep_;
    transport_t tp_;
    ushort portno_;
    string_t port_, host_, accept_host_, any_host_, endof_message_to_send_;
    char_t receive_chars_[ULUCIDITY_NETWORK_SOCKETS_BASE_RECEIVE_SIZE];
}; /// class Baset
typedef Baset<> Base;

} /// namespace Sockets 
} /// namespace Network 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_NETWORK_SOCKETS_BASE_HH
