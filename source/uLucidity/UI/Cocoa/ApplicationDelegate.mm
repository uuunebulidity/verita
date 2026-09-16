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
///   File: ApplicationDelegate.mm
///
/// Author: $author$
///   Date: 10/12/2025
///////////////////////////////////////////////////////////////////////
#include "uLucidity/UI/Cocoa/ApplicationDelegate.hh"
#include "uLucidity/UI/Cocoa/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: ApplicationDelegate
///
///       Author: $author$
///         Date: 10/12/2025
///////////////////////////////////////////////////////////////////////
@implementation ApplicationDelegate

    ///////////////////////////////////////////////////////////////////////
    /// applicationDidFinishLaunching
    - (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
        LOG_DEBUG("...aNotification = " << String(aNotification) << "");
    }
    
    ///////////////////////////////////////////////////////////////////////
    /// applicationDidBecomeActive
    - (void)applicationDidBecomeActive:(NSNotification *)aNotification {
        LOG_DEBUG("...aNotification = " << String(aNotification) << "");
    }

    ///////////////////////////////////////////////////////////////////////
    /// applicationWillResignActive
    - (void)applicationWillResignActive:(NSNotification *)aNotification {
        LOG_DEBUG("...aNotification = " << String(aNotification) << "");
    }

    ///////////////////////////////////////////////////////////////////////
    /// applicationDidEnterBackground
    - (void)applicationDidEnterBackground:(NSNotification *)aNotification {
        LOG_DEBUG("...aNotification = " << String(aNotification) << "");
    }

    ///////////////////////////////////////////////////////////////////////
    /// applicationWillEnterForeground
    - (void)applicationWillEnterForeground:(NSNotification *)aNotification {
        LOG_DEBUG("...aNotification = " << String(aNotification) << "");
    }

    ///////////////////////////////////////////////////////////////////////
    /// applicationWillTerminate
    - (void)applicationWillTerminate:(NSNotification *)aNotification {
        LOG_DEBUG("...aNotification = " << String(aNotification) << "");
    }
@end

