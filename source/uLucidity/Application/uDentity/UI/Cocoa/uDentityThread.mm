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
///   File: uDentityThread.mm
///
/// Author: $author$
///   Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
#include "uLucidity/Application/uDentity/UI/Cocoa/uDentityThread.hh"
#include "uLucidity/Application/uDentity/UI/Cocoa/uDentityView.hh"
#include "uLucidity/Application/uDentity/UI/Cocoa/Network/Sockets/Server/Main.hh"

namespace uLucidity {
namespace Application {
namespace uDentity {
namespace UI {
namespace Cocoa {
namespace Network {
namespace Sockets {
namespace Server {

Main the_main;

} /// namespace Server 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Cocoa 
} /// namespace UI 
} /// namespace uDentity 
} /// namespace Application 
} /// namespace uLucidity 

///////////////////////////////////////////////////////////////////////
/// Implentation: uDentityThread
///
///       Author: $author$
///         Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@implementation uDentityThread

    ///////////////////////////////////////////////////////////////////////
    /// start
    - (void)start:(NSObject *)view {
        NSThread *thread = nil;
        
        /// Create and start a new thread to perform the run task
        LOG_DEBUG("((thread = [[NSThread alloc] initWithTarget:self selector:@selector(run) object:nil]))...");
        if ((thread = [[NSThread alloc] initWithTarget:self selector:@selector(run) object:nil])) {

            LOG_DEBUG("_view = " << String(view) << "...");
            _view = view;
            LOG_DEBUG("_thread = " << String(thread) << "...");
            _thread = thread;
            LOG_DEBUG("[thread start]...");
            [thread start];
        } else {
            LOG_DEBUG("...failed on ((" << String(thread) << " = [[NSThread alloc] initWithTarget:self selector:@selector(run) object:nil]))");
        }
        /// In modern Objective-C, you don't typically need to manually release the thread,
        /// as ARC handles memory management.
    }

    ///////////////////////////////////////////////////////////////////////
    /// run
    - (void)run {
        /// This method runs on the secondary thread
        int err = 0;
    
        LOG_DEBUG("(!(err = uLucidity::Application::uDentity::UI::Cocoa::Network::Sockets::Server::the_main.run()))...");
        if (!(err = uLucidity::Application::uDentity::UI::Cocoa::Network::Sockets::Server::the_main.run())) {
            LOG_DEBUG("...(!(" << err << " = uLucidity::Application::uDentity::UI::Cocoa::Network::Sockets::Server::the_main.run()))");
        } else {
            LOG_DEBUG("...failed on (!(" << err << " = uLucidity::Application::uDentity::UI::Cocoa::Network::Sockets::Server::the_main.run()))");
        }
        /// Update the UI on the main thread using performSelectorOnMainThread
        LOG_DEBUG("[self performSelectorOnMainThread:@selector(onFnished:) withObject:" << String(_thread) << " waitUntilDone:NO]...");
        [self performSelectorOnMainThread:@selector(onFnished:) withObject:_thread waitUntilDone:NO];
    }

    ///////////////////////////////////////////////////////////////////////
    /// onFnished
    - (void)onFnished:(NSObject *)thread {
        /// This method runs on the main thread
        /// Here you would typically update your UI elements.
        NSObject* view = nil;

        LOG_DEBUG("((view = " << String(_view) << "))...");
        if ((view = _view)) {
            LOG_DEBUG("[view performSelectorOnMainThread:@selector(onThreadFnished:) withObject:" << String(thread) << " waitUntilDone:NO];...");
            [view performSelectorOnMainThread:@selector(onThreadFnished:) withObject:thread waitUntilDone:NO];
        } else {
            LOG_DEBUG("...failed on ((view = " << String(_view) << "))");
        }
    }
@end
