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
///   File: uDentifyMain_main.mm
///
/// Author: $author$
///   Date: 10/23/2025
//////////////////////////////////////////////////////////////////////////
#include "uLucidity/Application/uDentify/UI/Cocoa/uDentifyMain_main.hh"

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
/// main
int main(int argc, char **argv, char **env) {
    typedef String string;
    int err = 1;
    NSAutoreleasePool *autoreleasePool = nil;
    NSApplication* sharedApplication = nil;
    ApplicationDelegate* applicationDelegate = nil;
    id<Main> main = nil;

    LOG_DEBUG("[[AutoreleasePool alloc] init]...");
    if ((autoreleasePool = [[NSAutoreleasePool alloc] init])) {
        LOG_DEBUG("..." << string(autoreleasePool) << " = [[NSAutoreleasePool alloc] init]");

        LOG_DEBUG("[NSApplication sharedApplication]...");
        if ((sharedApplication = [NSApplication sharedApplication])) {
            LOG_DEBUG("..." << string(sharedApplication) << " = [NSApplication sharedApplication]");

            LOG_DEBUG("((applicationDelegate = [[ApplicationDelegate alloc] init]))...");
            if ((applicationDelegate = [[ApplicationDelegate alloc] init])) {
                LOG_DEBUG("[sharedApplication setDelegate:applicationDelegate]...");
                [sharedApplication setDelegate:applicationDelegate];
            } else {
                LOG_DEBUG("...failed on ((applicationDelegate = [[ApplicationDelegate alloc] init]))");
            }
            LOG_DEBUG("[uDentifyMainCreator create:sharedApplication]...");
            if ((main = [uDentifyMainCreator create:sharedApplication])) {
                LOG_DEBUG("..." << string(main) << " = [uDentifyMainCreator create:sharedApplication]");

                LOG_DEBUG("[main run:argc argv:argv env:env]...");
                err = [main run:argc argv:argv env:env];
                LOG_DEBUG("..." << err << " = [main run:argc argv:argv env:env]");

                LOG_DEBUG("[main = " << string(main) << " destroy]...");
                [main destroy];
            } else {
                LOG_ERROR("...failed " << string(main) << " = [MainCreator create:sharedApplication]");
            }
        } else {
            LOG_ERROR("...failed" << string(sharedApplication) << " = [NSApplication sharedApplication]");
        }
        LOG_DEBUG("[autoreleasePool = " << string(autoreleasePool) << " release]...");
        [autoreleasePool release];
    } else {
        LOG_ERROR("...failed " << string(autoreleasePool) << " = [[NSAutoreleasePool alloc] init]");
    }
    return err;
}
