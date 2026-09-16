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
///   File: uDentityView.hh
///
/// Author: $author$
///   Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
#ifndef _ULUCIDITY_APPLICATION_UDENTITY_UI_COCOA_UDENTITYVIEW_HH
#define _ULUCIDITY_APPLICATION_UDENTITY_UI_COCOA_UDENTITYVIEW_HH

#include "uLucidity/UI/Cocoa/View.hh"
#include "uLucidity/Application/uDentity/UI/Cocoa/uDentityThread.hh"

///////////////////////////////////////////////////////////////////////
/// Interface: uDentityView
///
///    Author: $author$
///      Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@interface uDentityView: View {
    }
    ///////////////////////////////////////////////////////////////////////
    /// initWithRect
    - (View*)initWithRect:(NSRect)rect
             application:(NSApplication*)application images:(Images*)images;

    ///////////////////////////////////////////////////////////////////////
    /// onMaximizeClicked
    - (void)onMaximizeClicked:(id)sender 
            application:(NSApplication*)application window:(NSWindow*)window;

    ///////////////////////////////////////////////////////////////////////
    /// onThreadFnished
    - (void)onThreadFnished:(uDentityThread*)thread;
@end
#endif // _ULUCIDITY_APPLICATION_UDENTITY_UI_COCOA_UDENTITYVIEW_HH 

