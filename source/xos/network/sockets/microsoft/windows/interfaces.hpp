///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
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
///   File: interfaces.hpp
///
/// Author: $author$
///   Date: 9/12/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKETS_MICROSOFT_WINDOWS_INTERFACES_HPP
#define XOS_NETWORK_SOCKETS_MICROSOFT_WINDOWS_INTERFACES_HPP

#include "xos/network/sockets/interfaces.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace microsoft {
namespace windows {

/// class interfacest
template <class TExtends = sockets::interfaces, class TImplements = typename TExtends::implements>
class exported interfacest: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef interfacest derives; 
    
    /// constructors / destructor
    interfacest() {
    }
    virtual ~interfacest() {
    }
private:
    interfacest(const interfacest& copy): extends(copy) {
    }
}; /// class interfacest
typedef interfacest<> interfaces;

} /// namespace windows
} /// namespace microsoft
} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// ndef XOS_NETWORK_SOCKETS_MICROSOFT_WINDOWS_INTERFACES_HPP
