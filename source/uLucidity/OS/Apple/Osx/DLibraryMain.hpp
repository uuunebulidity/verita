///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibraryMain.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_OS_APPLE_OSX_DLIBRARYMAIN_HPP
#define ULUCIDITY_OS_APPLE_OSX_DLIBRARYMAIN_HPP

#include "uLucidity/OS/Posix/DLibraryMain.hpp"

namespace uLucidity {
namespace OS {
namespace Apple {
namespace Osx {

typedef Posix::DLibraryMainImplements DLibraryMainImplements;
typedef Posix::DLibraryMain DLibraryMainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: DLibraryMain
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS DLibraryMain
: virtual public DLibraryMainImplements, public DLibraryMainExtends {
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

} // namespace Osx 
} // namespace Apple 
} // namespace OS 
} // namespace uLucidity 

#endif // ULUCIDITY_OS_APPLE_OSX_DLIBRARYMAIN_HPP 
