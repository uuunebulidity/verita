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
///   File: uDentityWindow.mm
///
/// Author: $author$
///   Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
#include "uLucidity/Application/uDentity/UI/Cocoa/uDentityWindow.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: uDentityWindow
///
///       Author: $author$
///         Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@implementation uDentityWindow
    ///////////////////////////////////////////////////////////////////////
    /// allocView
    - (View*)allocView:(NSRect)withRect {
        NSApplication* _application = [self application];
        Images* _images = [self images];
        View* view = nil;
        LOG_DEBUG("((view = [[uDentityView alloc] initWithRect:withRect application:_application images:_images]))...");
        if ((view = [[uDentityView alloc] initWithRect:withRect application:_application images:_images])) {
            LOG_DEBUG("...((view = [[uDentityView alloc] initWithRect:withRect application:_application images:_images]))");
        } else {
            LOG_DEBUG("failed on ((view = [[uDentityView alloc] initWithRect:withRect application:_application images:_images]))");
        }
        return view;
    }
@end

