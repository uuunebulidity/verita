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
///   File: uDentifyView.mm
///
/// Author: $author$
///   Date: 10/22/2025
//////////////////////////////////////////////////////////////////////////
#include "uLucidity/Application/uDentify/UI/Cocoa/uDentifyView.hh"

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
/// Implentation: uDentifyView
///
///       Author: $author$
///         Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@implementation uDentifyView
    ///////////////////////////////////////////////////////////////////////
    /// initWithRect
    - (View*)initWithRect:(NSRect)rect
             application:(NSApplication*)application images:(Images*)images {
        View* view = nil;
        
        LOG_DEBUG("_thread = nil...");
        _thread = nil;

        LOG_DEBUG("_threadWillStart = nil...");
        _threadWillStart = nil;

        LOG_DEBUG("((view = [super initWithRect:rect application:application images:images]))...");
        if ((view = [super initWithRect:rect application:application images:images])) {
            uDentifyThread* thread = nil;

            LOG_DEBUG("...((view = " << String(view) << " = [super initWithRect:rect application:application images:images]))");
            LOG_DEBUG("((_thread = (thread = [[uDentifyThread alloc] init])))...");
            if ((_thread = (thread = [[uDentifyThread alloc] init]))) {

                LOG_DEBUG("...((_thread = (thread = " << String(thread) << " = [[uDentifyThread alloc] init])))");
                /*/
                LOG_DEBUG("[thread start:view]...");
                [thread start:view];
                /*/
            } else {
                LOG_DEBUG("...failed on ((_thread = (" << String(thread) << " = [[uDentifyThread alloc] init])))");
            }
        } else {
            LOG_DEBUG("...failed on ((view = " << String(view) << " = [super initWithRect:rect application:application images:images]))");
        }
        return view;
    }

    ///////////////////////////////////////////////////////////////////////
    /// onMaximizeClicked
    - (void)onMaximizeClicked:(id)sender 
            application:(NSApplication*)application window:(NSWindow*)window {

        LOG_DEBUG("[application stop:self]...");
        [application stop:self];
    }

    ///////////////////////////////////////////////////////////////////////
    /// onContentClicked
    - (void)onContentClicked:(id)sender 
            application:(NSApplication*)application window:(NSWindow*)window {
        uDentifyThread* thread = nil;
    
        LOG_DEBUG("!(thread = (_threadWillStart = " << String(_threadWillStart) << ")))...");
        if (!(thread = (_threadWillStart))) {
            LOG_DEBUG("...(!(" << String(thread) << " = (_threadWillStart = " << String(_threadWillStart) << ")))");

            LOG_DEBUG("((thread = (_thread = " << String(_thread) << ")))...");
            if ((thread = (_thread))) {

                LOG_DEBUG("...((thread = (_thread = " << String(_thread) << ")))");
                LOG_DEBUG("[thread start:self]...");
                [thread start:self];
            } else {
                LOG_DEBUG("...failed on ((thread = (_thread = " << String(_thread) << ")))");
            }
        } else {
            LOG_DEBUG("...failed on (!(" << String(thread) << " = (_threadWillStart = " << String(_threadWillStart) << ")))");
        }
    }

    ///////////////////////////////////////////////////////////////////////
    /// onThreadWillStart
    - (void)onThreadWillStart:(NSThread*)thread {
        NSApplication* application = nil;
    
        LOG_DEBUG("((_threadWillStart = (_thread = " << String(_thread) << ")))...");
        if ((_threadWillStart = (_thread))) {
            LOG_DEBUG("...((_threadWillStart = (_thread = " << String(_thread) << ")))");
        } else {
            LOG_DEBUG("...failed on ((_threadWillStart = (_thread = " << String(_thread) << ")))");
        }
        LOG_DEBUG("((application = [self application]))...");
        if ((application = [self application])) {
    
            LOG_DEBUG("...((" << String(application) << " = [self application]))");
            /*/
            LOG_DEBUG("[application terminate:self]...");
            [application terminate:self];
            /*/
        } else {
            LOG_DEBUG("...failed on ((" << String(application) << " = [self application]))");
        }
    }

    ///////////////////////////////////////////////////////////////////////
    /// onThreadFnished
    - (void)onThreadFnished:(NSThread*)thread {
        NSApplication* application = nil;

        LOG_DEBUG("((_thread = " << String(_thread) << "))...");
        if ((_thread)) {
            LOG_DEBUG("...((_thread = " << String(_thread) << "))");
        } else {
            LOG_DEBUG("...failed on ((_thread = " << String(_thread) << "))");
        }
        LOG_DEBUG("((application = [self application]))...");
        if ((application = [self application])) {

            LOG_DEBUG("...((" << String(application) << " = [self application]))");
            /*/
            LOG_DEBUG("[application terminate:self]...");
            [application terminate:self];
            /*/
        } else {
            LOG_DEBUG("...failed on ((" << String(application) << " = [self application]))");
        }
        LOG_DEBUG("_threadWillStart = nil...");
        _threadWillStart = nil;
    }

    ///////////////////////////////////////////////////////////////////////
    /// onThreadResult
    - (void)onThreadResult:(NSString*)result {

        LOG_DEBUG("((result))...");
        if ((result)) {
            const char* chars = 0;
            LOG_DEBUG("((chars = [result UTF8String]))...");
            if ((chars = [result UTF8String])) {
                LOG_DEBUG("...((\"" << chars << "\" = [result UTF8String]))");
            } else {
                LOG_DEBUG("...failed on ((" << String(chars) << " = [result UTF8String]))");
            }
            LOG_DEBUG("...((" << String(result) << "))");
        } else {
            LOG_DEBUG("...failed on ((" << String(result) << "))");
        }
    }
@end
