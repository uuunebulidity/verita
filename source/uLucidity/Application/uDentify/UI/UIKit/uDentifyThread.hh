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
///   File: uDentifyThread.hh
///
/// Author: $author$
///   Date: 10/21/2025, 11/9/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_UDENTIFY_UI_UIKIT_UDENTIFYTHREAD_HH
#define ULUCIDITY_APPLICATION_UDENTIFY_UI_UIKIT_UDENTIFYTHREAD_HH

#include "uLucidity/UI/UIKit/UIKit.hh"

namespace uLucidity {
namespace Application {
namespace uDentify {
namespace UI {
namespace UIKit {

} /// namespace UIKit 
} /// namespace UI 
} /// namespace uDentify 
} /// namespace Application 
} /// namespace uLucidity 

///////////////////////////////////////////////////////////////////////
/// Interface: uDentifyThread
///
///    Author: $author$
///      Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@interface uDentifyThread: NSObject {
    }
    @property (assign) NSObject* view;
    @property (assign) NSObject* thread;
    @property (assign) NSString* User;
    @property (assign) NSString* Resource;
    @property (assign) NSString* Password;

    ///////////////////////////////////////////////////////////////////////
    /// start
    - (void)start:(NSObject*)view 
      User:(NSString*)User Resource:(NSString*)Resource Password:(NSString*)Password;
  
    ///////////////////////////////////////////////////////////////////////
    /// run
    - (void)run;
  
    ///////////////////////////////////////////////////////////////////////
    /// onWillStart
    - (void)onWillStart:(NSObject *)thread;

    ///////////////////////////////////////////////////////////////////////
    /// onFnished
    - (void)onFnished:(NSObject*)thread;
@end

#endif /// ndef ULUCIDITY_APPLICATION_UDENTIFY_UI_UIKIT_UDENTIFYTHREAD_HH

