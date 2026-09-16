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
///   File: uDentifyMain.mm
///
/// Author: $author$
///   Date: 10/22/2025
//////////////////////////////////////////////////////////////////////////
#include "uLucidity/Application/uDentify/UI/Cocoa/uDentifyMain.hh"
#include "uLucidity/Application/uDentify/UI/Cocoa/uDentifyWindow.hh"

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
/// Implentation: uDentifyMain
///
///       Author: $author$
///         Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@implementation uDentifyMain

    ///////////////////////////////////////////////////////////////////////
    /// allocWindow
    - (Window*)allocWindow:(NSRect)contentRect {
        NSApplication* _application = [super application];
        Images* _images = [super images];
        Window* window = nil;

        LOG_DEBUG("[[uDentifyWindow alloc] initWithRect:contentRect application:_application images:_images]...");
        if ((window = [[uDentifyWindow alloc] initWithRect:contentRect application:_application images:_images])) {
            LOG_DEBUG("..." << String(window) << " = [[uDentifyWindow alloc] initWithRect:contentRect application:_application images:_images]");
        } else {
            LOG_ERROR("...failed " << String(window) << " = [[uDentifyWindow alloc] initWithRect:contentRect application:_application images:_images]");
        }
        return window;
    }

    ///////////////////////////////////////////////////////////////////////
    /// loadPlugin / unloadPlugin
    - (uLucidity::UI::PluginLibrary*)loadPlugin {
        uLucidity::UI::PluginLibrary* pluginLibrary = nil;

        LOG_DEBUG("((pluginLibrary = [super loadPlugin]))...");
        if ((pluginLibrary = [super loadPlugin])) {
            LOG_DEBUG("...((" << String(pluginLibrary) << " = [super loadPlugin]))");
        } else {LOG_DEBUG("...failed on ((" << String(pluginLibrary) << " = [super loadPlugin]))");}
        return pluginLibrary;
    }
    - (void)unloadPlugin {
        LOG_DEBUG("[super unloadPlugin]...");
        [super unloadPlugin];
        LOG_DEBUG("...[super unloadPlugin]");
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: uDentifyMainCreator
///////////////////////////////////////////////////////////////////////
@implementation uDentifyMainCreator
    ///////////////////////////////////////////////////////////////////////
    /// create
    + (id<Main>)create:(NSApplication*)application {
        id<Main> main = nil;
    
        LOG_DEBUG("[[uDentifyMain alloc] init:application = " << String(application) << "]...");
        if ((main = [[uDentifyMain alloc] init:application])) {
            LOG_DEBUG("..." << String(main) << " = [[Main alloc] init:application = " << String(application) << "]");
        } else {
            LOG_ERROR("...failed " << String(main) << " = [[Main alloc] init:application = " << String(application) << "]");
        }
        return main;
    }
@end
