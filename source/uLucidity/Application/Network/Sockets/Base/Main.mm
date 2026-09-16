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
///   File: Main.mm
///
/// Author: $author$
///   Date: 10/5/2025
//////////////////////////////////////////////////////////////////////////
#include "uLucidity/Application/Network/Sockets/Base/Main.hh"

#ifdef XOS_CONSOLE_MAIN_MAIN
#include "xos/console/main_main.cpp"
#ifndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE
#define ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE
#else /// ndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 
#endif /// ndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 
#else /// def XOS_CONSOLE_MAIN_MAIN 
#endif /// def XOS_CONSOLE_MAIN_MAIN 

#ifndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE
/// #define ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 
#else /// ndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 
#endif /// ndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 

namespace uLucidity {
namespace Application {
namespace Network {
namespace Sockets {
namespace Base {

/// class Maint
#ifdef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE
static Main the_Main;
#endif /// def ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 

} /// namespace Base 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Application 
} /// namespace uLucidity 
