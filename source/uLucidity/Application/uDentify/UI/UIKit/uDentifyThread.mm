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
///   File: uDentifyThread.mm
///
/// Author: $author$
///   Date: 10/21/2025, 10/26/2025
//////////////////////////////////////////////////////////////////////////
#include "uLucidity/Application/uDentify/UI/UIKit/uDentifyThread.hh"
#include "uLucidity/Application/uDentify/UI/UIKit/Network/Sockets/Client/Main.hh"

namespace uLucidity {
namespace Application {
namespace uDentify {
namespace UI {
namespace UIKit {
namespace Network {
namespace Sockets {
namespace Client {

Main the_main;

} /// namespace Client 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace UIKit 
} /// namespace UI 
} /// namespace uDentify 
} /// namespace Application 
} /// namespace uLucidity 

///////////////////////////////////////////////////////////////////////
/// Implentation: uDentifyThread
///
///       Author: $author$
///         Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@implementation uDentifyThread

    ///////////////////////////////////////////////////////////////////////
    /// start
    - (void)start:(NSObject *)view 
        User:(NSString*)User Resource:(NSString*)Resource Password:(NSString*)Password {
        NSThread *thread = nil;
        
        /// Create and start a new thread to perform the run task
        LOG_DEBUG("((thread = [[NSThread alloc] initWithTarget:self selector:@selector(run) object:nil]))...");
        if ((thread = [[NSThread alloc] initWithTarget:self selector:@selector(run) object:nil])) {

            LOG_DEBUG("_view = " << String(view) << "...");
            _view = view;

            LOG_DEBUG("_thread = " << String(thread) << "...");
            _thread = thread;
            
            LOG_DEBUG("_User = " << String(User) << "...");
            _User = User;
            
            LOG_DEBUG("_Resource = " << String(Resource) << "...");
            _Resource = Resource;
            
            LOG_DEBUG("_Password = " << String(Password) << "...");
            _Password = Password;

            LOG_DEBUG("[self onWillStart:thread]...");
            [self onWillStart:thread];

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
        const char *userChars = [self.User UTF8String], 
                   *resourceChars = [self.Resource UTF8String], 
                   *passwordChars = [self.Password UTF8String];
    
        LOG_DEBUG("(!(err = uLucidity::Application::uDentify::UI::UIKit::Network::Sockets::Client::the_main.run()))...");
        if (!(err = uLucidity::Application::uDentify::UI::UIKit::Network::Sockets::Client::the_main.run(userChars, resourceChars, passwordChars))) {
            LOG_DEBUG("...(!(" << err << " = uLucidity::Application::uDentify::UI::UIKit::Network::Sockets::Client::the_main.run()))");
        } else {
            LOG_DEBUG("...failed on (!(" << err << " = uLucidity::Application::uDentify::UI::UIKit::Network::Sockets::Client::the_main.run()))");
        }
        /// Update the UI on the main thread using performSelectorOnMainThread
        LOG_DEBUG("[self performSelectorOnMainThread:@selector(onFnished:) withObject:" << String(_thread) << " waitUntilDone:NO]...");
        [self performSelectorOnMainThread:@selector(onFnished:) withObject:_thread waitUntilDone:NO];
    }

    ///////////////////////////////////////////////////////////////////////
    /// onWillStart
    - (void)onWillStart:(NSObject *)thread {
        /// This method runs on the main thread
        /// Here you would typically update your UI elements.
        NSObject* view = nil;
    
        LOG_DEBUG("((view = " << String(_view) << "))...");
        if ((view = _view)) {
            LOG_DEBUG("[view performSelectorOnMainThread:@selector(onThreadWillStart:) withObject:" << String(thread) << " waitUntilDone:NO];...");
            [view performSelectorOnMainThread:@selector(onThreadWillStart:) withObject:thread waitUntilDone:NO];
        } else {
            LOG_DEBUG("...failed on ((view = " << String(_view) << "))");
        }
    }

    ///////////////////////////////////////////////////////////////////////
    /// onFnished
    - (void)onFnished:(NSObject *)thread {
        /// This method runs on the main thread
        /// Here you would typically update your UI elements.
        size_t length = 0;
        const char* chars = 0; 
        NSObject* view = nil;
        xos::string target_result;

        LOG_DEBUG("((chars = uLucidity::Application::uDentify::UI::UIKit::Network::Sockets::Client::the_main.get_target_result().has_chars(length)))...");
        if ((chars = uLucidity::Application::uDentify::UI::UIKit::Network::Sockets::Client::the_main.get_target_result(target_result).has_chars(length))) {
            LOG_DEBUG("...((\"" << chars << "\" = uLucidity::Application::uDentify::UI::UIKit::Network::Sockets::Client::the_main.get_target_result().has_chars(" << length << ")))");
            NSString* result = nil;

            if ((result = [[NSString alloc] initWithData:[NSData dataWithBytes:chars length:length] encoding:NSASCIIStringEncoding])) {
                LOG_DEBUG("((view = " << String(_view) << "))...");
                if ((view = _view)) {
                    LOG_DEBUG("[view performSelectorOnMainThread:@selector(onThreadResult:) withObject:" << String(result) << " waitUntilDone:NO];...");
                    [view performSelectorOnMainThread:@selector(onThreadResult:) withObject:result waitUntilDone:NO];
                } else {
                    LOG_DEBUG("...failed on ((view = " << String(_view) << "))");
                }
            } else {}
        } else {
            LOG_DEBUG("...failed on ((chars = uLucidity::Application::uDentify::UI::UIKit::Network::Sockets::Client::the_main.get_target_result().has_chars(" << length << ")))");
        }
        LOG_DEBUG("((view = " << String(_view) << "))...");
        if ((view = _view)) {
            LOG_DEBUG("[view performSelectorOnMainThread:@selector(onThreadFnished:) withObject:" << String(thread) << " waitUntilDone:NO];...");
            [view performSelectorOnMainThread:@selector(onThreadFnished:) withObject:thread waitUntilDone:NO];
        } else {
            LOG_DEBUG("...failed on ((view = " << String(_view) << "))");
        }
    }
@end
