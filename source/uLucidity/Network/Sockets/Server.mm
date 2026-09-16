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
///   File: Server.mm
///
/// Author: $author$
///   Date: 9/29/2025
//////////////////////////////////////////////////////////////////////////
#include "uLucidity/Network/Sockets/Server.hh"

#ifndef ULUCIDITY_NETWORK_SOCKETS_SERVER_INSTANCE
/// #define ULUCIDITY_NETWORK_SOCKETS_SERVER_INSTANCE 
#else /// ndef ULUCIDITY_NETWORK_SOCKETS_SERVER_INSTANCE 
#endif /// ndef ULUCIDITY_NETWORK_SOCKETS_SERVER_INSTANCE 

namespace uLucidity {
namespace Network {
namespace Sockets {

/// class Servert
#ifdef ULUCIDITY_NETWORK_SOCKETS_SERVER_INSTANCE
static Server the_Server;
#endif /// def ULUCIDITY_NETWORK_SOCKETS_SERVER_INSTANCE 

} /// namespace Sockets 
} /// namespace Network 
} /// namespace uLucidity 
