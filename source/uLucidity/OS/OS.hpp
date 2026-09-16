///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: OS.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_OS_OS_HPP
#define ULUCIDITY_OS_OS_HPP

#include "uLucidity/Platform/Platform.h"

namespace uLucidity {
namespace OS {
namespace Microsoft { namespace Windows {} }
namespace Apple { namespace Osx {} }
namespace Posix { }

#if defined(WINDOWS)
// Windows
namespace OS = OS::Microsoft::Windows;
#else // defined(WINDOWS)
#if defined(MACOSX)
// MacOSX
namespace OS = OS::Apple::Osx;
#else // defined(MACOSX)
// Posix
namespace OS = OS::Posix;
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

} // namespace OS 
} // namespace uLucidity 

#endif // ULUCIDITY_OS_OS_HPP 
