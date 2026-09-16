///////////////////////////////////////////////////////////////////////
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
///   File: uDentityMain.hh
///
/// Author: $author$
///   Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
#ifndef _ULUCIDITY_APPLICATION_UDENTITY_UI_COCOA_UDENTITYMAIN_HH
#define _ULUCIDITY_APPLICATION_UDENTITY_UI_COCOA_UDENTITYMAIN_HH

#include "uLucidity/UI/Cocoa/Main.hh"

///////////////////////////////////////////////////////////////////////
/// Interface: uDentityMain
///
///    Author: $author$
///      Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@interface uDentityMain: Main {
    }
@end

///////////////////////////////////////////////////////////////////////
/// Interface: uDentityMainCreator
///////////////////////////////////////////////////////////////////////
@interface uDentityMainCreator: NSObject {
    }
    ///////////////////////////////////////////////////////////////////////
    /// create
    + (id<Main>)create:(NSApplication*)application;
@end
  
#endif // _ULUCIDITY_APPLICATION_UDENTITY_UI_COCOA_UDENTITYMAIN_HH 

