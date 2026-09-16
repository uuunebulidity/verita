///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibrary.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_OS_APPLE_OSX_DLIBRARY_HPP
#define ULUCIDITY_OS_APPLE_OSX_DLIBRARY_HPP

#include "uLucidity/OS/Posix/DLibrary.hpp"

namespace uLucidity {
namespace OS {
namespace Apple {
namespace Osx {

typedef Posix::DLibraryAttachedT DLibraryAttachedT;
typedef Posix::DLibraryUnattachedT DLibraryUnattachedT;
static const DLibraryUnattachedT DLibraryUnattached = Posix::DLibraryUnattached;
typedef Posix::DLibraryImplements DLibraryImplements;
typedef Posix::DLibrary DLibrary;


} // namespace Osx 
} // namespace Apple 
} // namespace OS 
} // namespace uLucidity 

#endif // ULUCIDITY_OS_APPLE_OSX_DLIBRARY_HPP 
