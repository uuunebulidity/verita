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
///   File: uDentityView.mm
///
/// Author: $author$
///   Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
#include "uLucidity/Application/uDentity/UI/Cocoa/uDentityView.hh"
//#include "uLucidity/Application/uDentity/UI/Cocoa/uDentityThread.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: uDentityView
///
///       Author: $author$
///         Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@implementation uDentityView
    ///////////////////////////////////////////////////////////////////////
    /// initWithRect
    - (View*)initWithRect:(NSRect)rect
             application:(NSApplication*)application images:(Images*)images {
        View* view = nil;
        
        LOG_DEBUG("((view = [super initWithRect:rect application:application images:images]))...");
        if ((view = [super initWithRect:rect application:application images:images])) {
            uDentityThread* thread = nil;

            LOG_DEBUG("...((view = " << String(view) << " = [super initWithRect:rect application:application images:images]))");
            LOG_DEBUG("((thread = [[uDentityThread alloc] init]))...");
            if ((thread = [[uDentityThread alloc] init])) {

                LOG_DEBUG("...((thread = " << String(thread) << " = [[uDentityThread alloc] init]))");
                LOG_DEBUG("[thread start:view]...");
                [thread start:view];
            } else {
                LOG_DEBUG("...failed on ((" << String(thread) << " = [[uDentityThread alloc] init]))");
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
    /// onThreadFnished
    - (void)onThreadFnished:(uDentityThread*)thread {
        NSApplication* application = nil;

        LOG_DEBUG("((thread = " << String(thread) << "))...");
        if ((thread)) {
            LOG_DEBUG("...((thread = " << String(thread) << "))");
        } else {
            LOG_DEBUG("failed on ((thread = " << String(thread) << "))");
        }
        LOG_DEBUG("((application = [self application]))...");
        if ((application = [self application])) {

            LOG_DEBUG("[application terminate:self]...");
            [application terminate:self];
        } else {
            LOG_DEBUG("failed on ((" << String(application) << " = [self application]))");
        }
    }
@end

