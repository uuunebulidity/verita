///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibraryMain.cpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/OS/DLibraryMain.hpp"

#if defined(WINDOWS)
// Windows
#include "uLucidity/OS/Microsoft/Windows/DLibraryMain.cpp"
#else // defined(WINDOWS)
#if defined(MACOSX)
// MacOSX
#include "uLucidity/OS/Apple/Osx/DLibraryMain.cpp"
#else // defined(MACOSX)
// Posix
#include "uLucidity/OS/Posix/DLibraryMain.cpp"
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

namespace uLucidity {
namespace OS {

///////////////////////////////////////////////////////////////////////
///  Class: DLibraryMain
///////////////////////////////////////////////////////////////////////

} // namespace OS 
} // namespace uLucidity 


        

