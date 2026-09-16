///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibrary.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_OS_DLIBRARY_HPP
#define ULUCIDITY_OS_DLIBRARY_HPP

#include "uLucidity/OS/OS.hpp"

#if defined(WINDOWS)
// Windows
#include "uLucidity/OS/Microsoft/Windows/DLibrary.hpp"
#else // defined(WINDOWS)
#if defined(MACOSX)
// MacOSX
#include "uLucidity/OS/Apple/Osx/DLibrary.hpp"
#else // defined(MACOSX)
// Posix
#include "uLucidity/OS/Posix/DLibrary.hpp"
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

namespace uLucidity {
namespace OS {

typedef OS::DLibraryAttachedT DLibraryAttachedT;
typedef OS::DLibraryUnattachedT DLibraryUnattachedT;
typedef OS::DLibraryImplements DLibraryImplements;
typedef OS::DLibrary DLibrary;
static const DLibraryUnattachedT DLibraryUnattached = OS::DLibraryUnattached;

} // namespace OS
} // namespace uLucidity 

#endif // ULUCIDITY_OS_DLIBRARY_HPP 

