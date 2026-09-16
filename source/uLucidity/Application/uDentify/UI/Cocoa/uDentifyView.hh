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
///   File: uDentifyView.hh
///
/// Author: $author$
///   Date: 10/22/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_UDENTIFY_UI_COCOA_UDENTIFYVIEW_HH
#define ULUCIDITY_APPLICATION_UDENTIFY_UI_COCOA_UDENTIFYVIEW_HH

#include "uLucidity/UI/Cocoa/View.hh"
#include "uLucidity/Application/uDentify/UI/Cocoa/uDentifyThread.hh"

namespace uLucidity {
namespace Application {
namespace uDentify {
namespace UI {
namespace Cocoa {

} /// namespace Cocoa 
} /// namespace UI 
} /// namespace uDentify 
} /// namespace Application 
} /// namespace uLucidity 

///////////////////////////////////////////////////////////////////////
/// Interface: uDentifyView
///
///    Author: $author$
///      Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@interface uDentifyView: View {
    }
    @property (assign) uDentifyThread* thread;
    @property (assign) uDentifyThread* threadWillStart;

    ///////////////////////////////////////////////////////////////////////
    /// initWithRect
    - (View*)initWithRect:(NSRect)rect
             application:(NSApplication*)application images:(Images*)images;

    ///////////////////////////////////////////////////////////////////////
    /// onMaximizeClicked
    - (void)onMaximizeClicked:(id)sender 
            application:(NSApplication*)application window:(NSWindow*)window;

    ///////////////////////////////////////////////////////////////////////
    /// onContentClicked
    - (void)onContentClicked:(id)sender 
            application:(NSApplication*)application window:(NSWindow*)window;

    ///////////////////////////////////////////////////////////////////////
    /// onThreadWillStart
    - (void)onThreadWillStart:(NSThread*)thread;

    ///////////////////////////////////////////////////////////////////////
    /// onThreadFnished
    - (void)onThreadFnished:(NSThread*)thread;

    ///////////////////////////////////////////////////////////////////////
    /// onThreadResult
    - (void)onThreadResult:(NSString*)result;
@end

#endif /// ndef ULUCIDITY_APPLICATION_UDENTIFY_UI_COCOA_UDENTIFYVIEW_HH
