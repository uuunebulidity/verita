///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibraryMain.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_OS_DLIBRARYMAIN_HPP
#define ULUCIDITY_OS_DLIBRARYMAIN_HPP

#include "uLucidity/Base/DLibraryMain.hpp"
#include "uLucidity/OS/OS.hpp"

#if defined(WINDOWS)
// Windows
#include "uLucidity/OS/Microsoft/Windows/DLibraryMain.hpp"
#else // defined(WINDOWS)
#if defined(MACOSX)
// MacOSX
#include "uLucidity/OS/Apple/Osx/DLibraryMain.hpp"
#else // defined(MACOSX)
// Posix
#include "uLucidity/OS/Posix/DLibraryMain.hpp"
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

namespace uLucidity {
namespace OS {

typedef OS::DLibraryMainImplements DLibraryMainImplements;
typedef OS::DLibraryMain DLibraryMainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: DLibraryMain
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS DLibraryMain:
virtual public DLibraryMainImplements, public DLibraryMainExtends {
public:
    typedef DLibraryMainImplements Implements;
    typedef DLibraryMainExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    DLibraryMain() {
    }
    virtual ~DLibraryMain() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace OS 
} // namespace uLucidity 

#endif // ULUCIDITY_OS_DLIBRARYMAIN_HPP 
