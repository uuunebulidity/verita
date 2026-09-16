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
///   File: uDentityMain.mm
///
/// Author: $author$
///   Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
#include "uLucidity/Application/uDentity/UI/Cocoa/uDentityMain.hh"
#include "uLucidity/Application/uDentity/UI/Cocoa/uDentityWindow.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: uDentityMain
///
///       Author: $author$
///         Date: 10/9/2025
///////////////////////////////////////////////////////////////////////
@implementation uDentityMain

    ///////////////////////////////////////////////////////////////////////
    /// allocWindow
    - (Window*)allocWindow:(NSRect)contentRect {
        NSApplication* _application = [super application];
        Images* _images = [super images];
        Window* window = nil;

        LOG_DEBUG("[[uDentityWindow alloc] initWithRect:contentRect application:_application images:_images]...");
        if ((window = [[uDentityWindow alloc] initWithRect:contentRect application:_application images:_images])) {
            LOG_DEBUG("..." << String(window) << " = [[uDentityWindow alloc] initWithRect:contentRect application:_application images:_images]");
        } else {
            LOG_ERROR("...failed " << String(window) << " = [[uDentityWindow alloc] initWithRect:contentRect application:_application images:_images]");
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
/// Implentation: uDentityMainCreator
///////////////////////////////////////////////////////////////////////
@implementation uDentityMainCreator
    ///////////////////////////////////////////////////////////////////////
    /// create
    + (id<Main>)create:(NSApplication*)application {
        id<Main> main = nil;
    
        LOG_DEBUG("[[uDentityMain alloc] init:application = " << String(application) << "]...");
        if ((main = [[uDentityMain alloc] init:application])) {
            LOG_DEBUG("..." << String(main) << " = [[Main alloc] init:application = " << String(application) << "]");
        } else {
            LOG_ERROR("...failed " << String(main) << " = [[Main alloc] init:application = " << String(application) << "]");
        }
        return main;
    }
@end
