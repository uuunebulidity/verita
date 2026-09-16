///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibrary.cpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/OS/DLibrary.hpp"

#if defined(WINDOWS)
// Windows
#include "uLucidity/OS/Microsoft/Windows/DLibrary.cpp"
#else // defined(WINDOWS)
#if defined(MACOSX)
// MacOSX
#include "uLucidity/OS/Apple/Osx/DLibrary.cpp"
#else // defined(MACOSX)
// Posix
#include "uLucidity/OS/Posix/DLibrary.cpp"
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

namespace uLucidity {
namespace OS {

} // namespace OS 
} // namespace uLucidity 
