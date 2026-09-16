///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibraryMain.cpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/OS/Posix/DLibraryMain.hpp"

namespace uLucidity {
namespace OS {
namespace Posix {

///////////////////////////////////////////////////////////////////////
///  Class: DLibraryMain
///////////////////////////////////////////////////////////////////////

} // namespace Posix 
} // namespace OS 
} // namespace uLucidity 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void _init(void) {
    uLucidity::DLibraryMain* theDLibraryMain = 0;

    STDERR_LOG_DEBUG("uLucidity::DLibraryMain::GetTheDLibraryMain()...");
    if ((theDLibraryMain = uLucidity::DLibraryMain::GetTheDLibraryMain())) {

        STDERR_LOG_DEBUG("theDLibraryMain->Init()...");
        if (!(theDLibraryMain->Init())) {
            STDERR_LOG_ERROR("...failed on theDLibraryMain->Init()");
        }
    } else {
        STDERR_LOG_ERROR("...failed 0 = uLucidity::DLibraryMain::GetTheDLibraryMain()");
    }
}
void _fini(void) {
    uLucidity::DLibraryMain* theDLibraryMain = 0;

    STDERR_LOG_DEBUG("...");
    if ((theDLibraryMain = uLucidity::DLibraryMain::GetTheDLibraryMain())) {

        STDERR_LOG_DEBUG("theDLibraryMain->Fini()...");
        if (!(theDLibraryMain->Fini())) {
            STDERR_LOG_ERROR("...failed on theDLibraryMain->Fini()");
        }
    } else {
        STDERR_LOG_ERROR("...failed 0 = uLucidity::DLibraryMain::GetTheDLibraryMain()");
    }
}

