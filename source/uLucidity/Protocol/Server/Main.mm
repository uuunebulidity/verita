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
///   Date: 10/4/2025
//////////////////////////////////////////////////////////////////////////
#include "uLucidity/Protocol/Server/Main.hh"

#ifndef ULUCIDITY_PROTOCOL_SERVER_MAIN_INSTANCE
/// #define ULUCIDITY_PROTOCOL_SERVER_MAIN_INSTANCE 
#else /// ndef ULUCIDITY_PROTOCOL_SERVER_MAIN_INSTANCE 
#endif /// ndef ULUCIDITY_PROTOCOL_SERVER_MAIN_INSTANCE 

namespace uLucidity {
namespace Protocol {
namespace Server {

/// class Maint
#ifdef ULUCIDITY_PROTOCOL_SERVER_MAIN_INSTANCE
static Main the_Main;
#endif /// def ULUCIDITY_PROTOCOL_SERVER_MAIN_INSTANCE 

} /// namespace Server 
} /// namespace Protocol 
} /// namespace uLucidity 
