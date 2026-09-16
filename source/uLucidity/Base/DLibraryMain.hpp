///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibraryMain.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_BASE_DLIBRARYMAIN_HPP
#define ULUCIDITY_BASE_DLIBRARYMAIN_HPP

#include "uLucidity/Base/Base.hpp"

namespace uLucidity {

typedef ImplementBase DLibraryMainImplements;
///////////////////////////////////////////////////////////////////////
///  Class: DLibraryMain
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS DLibraryMain: virtual public DLibraryMainImplements {
public:
    typedef DLibraryMainImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init() { return true; }
    virtual bool Fini() { return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static DLibraryMain* GetTheDLibraryMain() {
        static DLibraryMain* theDLibraryMain = TheDLibraryMain();
        return theDLibraryMain;
    }
protected:
    static DLibraryMain*& TheDLibraryMain() {
        static DLibraryMain* theDLibraryMain = 0;
        return theDLibraryMain;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef DLibraryMain DLibraryMainExtendImplements;
typedef Base DLibraryMainExtendExtends;
///////////////////////////////////////////////////////////////////////
///  Class: DLibraryMainExtend
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS DLibraryMainExtend:
virtual public DLibraryMainExtendImplements, public DLibraryMainExtendExtends {
public:
    typedef DLibraryMainExtendImplements Implements;
    typedef DLibraryMainExtendExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    DLibraryMainExtend() {
        DLibraryMain*& theDLibraryMain = TheDLibraryMain();
        if (!(theDLibraryMain)) {
            STDERR_LOG_DEBUG("theDLibraryMain = this...");
            theDLibraryMain = this;
        }
    }
    virtual ~DLibraryMainExtend() {
        DLibraryMain*& theDLibraryMain = TheDLibraryMain();
        if (this == (theDLibraryMain)) {
            STDERR_LOG_DEBUG("theDLibraryMain = 0...");
            theDLibraryMain = 0;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace uLucidity

#endif // ULUCIDITY_BASE_DLIBRARYMAIN_HPP 
