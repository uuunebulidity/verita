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
#ifndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_CLIENT_MAIN_HH
#define ULUCIDITY_APPLICATION_NETWORK_SOCKETS_CLIENT_MAIN_HH

#include "uLucidity/Application/Network/Sockets/Base/Main.hh"

namespace uLucidity {
namespace Application {
namespace Network {
namespace Sockets {
namespace Client {

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
    : events_(events) {
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
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_Connect(\"" << target << "\", \"" << source << "\")))...");
        if (!(err = this->all_Connect(target, source))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_Connect(\"" << target << "\", \"" << source << "\")))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_Connect(\"" << target << "\", \"" << source << "\")))");
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

    //////////////////////////////////////////////////////////////////////////
protected:
    Events& events_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Client 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_CLIENT_MAIN_HH
