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
///   File: Client.hh
///
/// Author: $author$
///   Date: 9/29/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_NETWORK_SOCKETS_CLIENT_HH
#define ULUCIDITY_NETWORK_SOCKETS_CLIENT_HH

#include "uLucidity/Network/Sockets/Base.hh"

namespace uLucidity {
namespace Network {
namespace Sockets {

//////////////////////////////////////////////////////////////////////////
/// class Clientt
template <class TExtends = uLucidity::Network::Sockets::Base, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Clientt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Clientt Derives;

    typedef typename Extends::string string;
    typedef typename Extends::Events Events;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Clientt(Events &events): events_(events) {
    }
    virtual ~Clientt() {
    }
private:
    Clientt(const Clientt &copy) {
    }
public:

    //////////////////////////////////////////////////////////////////////////
protected:
    typedef typename Extends::string_t string_t;
    typedef typename Extends::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    virtual int default_Run(string &target, const string &source) {
        int err = 0;
        LOG_INFO("(!(err = this->all_Connect(\"" << target << "\", \"" << source << "\")))...");
        if (!(err = this->all_Connect(target, source))) {
            LOG_INFO("...(!(err = this->all_Connect(\"" << target << "\", \"" << source << "\")))");
        } else {
            LOG_INFO("...failed on (!(err = this->all_Connect(\"" << target << "\", \"" << source << "\")))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_receive(char_t* chars, size_t length) { 
        int err = 0;
        err = events_.on_receive(chars, length);
        return err;
    }
    virtual int on_begin_receive(char_t* chars, size_t length) { 
        int err = 0;
        err = events_.on_begin_receive(chars, length);
        return err;
    }
    virtual int on_end_receive(char_t* chars, size_t length) { 
        int err = 0;
        err = events_.on_end_receive(chars, length);
        return err;
    }
    virtual int on_after_receive(string &target, const string &source) {
        int err = 0;
        LOG_INFO("...");
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
protected:
    Events &events_;
}; /// class Clientt
typedef Clientt<> Client;

} /// namespace Sockets 
} /// namespace Network 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_NETWORK_SOCKETS_CLIENT_HH
