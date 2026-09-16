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
///   Date: 10/6/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_SERVER_MAIN_HH
#define ULUCIDITY_APPLICATION_NETWORK_SOCKETS_SERVER_MAIN_HH

#include "uLucidity/Application/Network/Sockets/Base/Main.hh"

namespace uLucidity {
namespace Application {
namespace Network {
namespace Sockets {
namespace Server {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template 
<class TEvents = uLucidity::Application::Network::Sockets::Base::Main::Events,
 class TExtends = uLucidity::Application::Network::Sockets::Base::Main, 
 class TImplements = typename TExtends::Implements>
class exported Maint: virtual public TImplements, public TExtends {
public:
    typedef TEvents Events;
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;

    typedef typename Extends::string string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint(Events& events)
    : events_(events), AcceptOne_(false) {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
protected:

    //////////////////////////////////////////////////////////////////////////
    virtual int default_Run(string &target, const string &source) {
        int err = 0;
        const bool& AcceptOne = this->AcceptOne();
        if ((AcceptOne)) {
            LOGGER_IS_LOGGED_INFO("(!(err = this->all_AcceptOne(\"" << target << "\", \"" << source << "\")))...");
            if (!(err = this->all_AcceptOne(target, source))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_AcceptOne(\"" << target << "\", \"" << source << "\")))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_AcceptOne(\"" << target << "\", \"" << source << "\")))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = this->all_Accept(\"" << target << "\", \"" << source << "\")))...");
            if (!(err = this->all_Accept(target, source))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_Accept(\"" << target << "\", \"" << source << "\")))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_Accept(\"" << target << "\", \"" << source << "\")))");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_receive(char_t* chars, size_t length) { 
        int err = 0;
        if (!(err = events_.on_receive(chars, length))) {} else {}
        return err;
    }
    virtual int on_begin_receive(char_t* chars, size_t length) { 
        int err = 0;
        if (!(err = events_.on_begin_receive(chars, length))) {} else {}
        return err;
    }
    virtual int on_end_receive(char_t* chars, size_t length) { 
        int err = 0;
        if (!(err = events_.on_end_receive(chars, length))) {} else {}
        return err;
    }
    virtual int on_after_receive(string &target, const string &source) {
        int err = 0;
        if (!(err = events_.on_after_receive(target, source))) {} else {}
        return err;
    }
    ///////////////////////////////////////////////////////////////////////

public:
    //////////////////////////////////////////////////////////////////////////
    virtual bool& set_Accept(const bool& to = true) {
        bool& AcceptOne = this->AcceptOne();
        AcceptOne = !to;
        return AcceptOne;
    }
    virtual bool& set_AcceptOne(const bool& to = true) {
        bool& AcceptOne = this->AcceptOne();
        AcceptOne = to;
        return AcceptOne;
    }
    virtual bool& AcceptOne() const {
        return (bool&)AcceptOne_;
    }
    //////////////////////////////////////////////////////////////////////////
protected:

    //////////////////////////////////////////////////////////////////////////
protected:
    Events& events_;
    bool AcceptOne_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Server 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_SERVER_MAIN_HH
