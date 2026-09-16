///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibrary.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_OS_POSIX_DLIBRARY_HPP
#define ULUCIDITY_OS_POSIX_DLIBRARY_HPP

#include "uLucidity/Base/Base.hpp"
#include <dlfcn.h>

#define ULUCIDITY_OS_DLIBRARY_SYMBOL_(identifier) "" #identifier ""
#define ULUCIDITY_OS_DLIBRARY_SYMBOL(identifier) ULUCIDITY_OS_DLIBRARY_SYMBOL_(identifier)

namespace uLucidity {
namespace OS {
namespace Posix {

typedef void* DLibraryAttachedT;
typedef int DLibraryUnattachedT;
static const DLibraryUnattachedT DLibraryUnattached = 0;

typedef ImplementBase DLibraryImplements;
typedef Base DLibraryExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS DLibrary
: virtual public DLibraryImplements, public DLibraryExtends {
public:
    typedef DLibraryImplements Implements;
    typedef DLibraryExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    DLibrary(): m_attachedTo((DLibraryAttachedT)DLibraryUnattached) {
    }
    virtual ~DLibrary() {
        Closed();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open
    (const char* fileName, bool resolve = true, bool global = false) {
        DLibraryAttachedT detached = (DLibraryAttachedT)DLibraryUnattached;
        if ((detached = OpenAttached(fileName, resolve, global))) {
            return true;
        }
        return false;
    }
    virtual bool Close() {
        DLibraryAttachedT detached = (DLibraryAttachedT)DLibraryUnattached;
        if ((detached = this->Detach())) {
            if ((CloseDetached(detached))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Closed() {
        DLibraryAttachedT detached = (DLibraryAttachedT)DLibraryUnattached;
        if ((detached = this->AttachedTo())) {
            if ((Close())) {
                return true;
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void* GetAddress(const char* symbol) const {
        DLibraryAttachedT detached = (DLibraryAttachedT)DLibraryUnattached;
        if ((detached = this->AttachedTo())) {
            void* address = 0;
            LOG_STDERR_DEBUGF("dlsym(detached, symbol = \"%s\")...\n", symbol);
            if ((address = dlsym(detached, symbol))) {
                return address;
            } else {
                LOG_STDERR_ERRORF("...failed 0 = dlsym(detached, symbol = \"%s\")\n", symbol);
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual DLibraryAttachedT OpenAttached
    (const char* fileName, bool resolve = true, bool global = false) {
        DLibraryAttachedT detached = (DLibraryAttachedT)DLibraryUnattached;
        if ((detached = OpenDetached(fileName, resolve, global))) {
            Attach(detached);
            return detached;
        }
        return (DLibraryAttachedT)DLibraryUnattached;
    }
    virtual DLibraryAttachedT OpenDetached
    (const char* fileName, bool resolve = true, bool global = false) const {
        if ((fileName)) {
            DLibraryAttachedT detached = (DLibraryAttachedT)DLibraryUnattached;
            int mode = ((resolve)?(RTLD_NOW):(RTLD_LAZY))
                       | ((global)?(RTLD_GLOBAL):(RTLD_LOCAL));

            LOG_STDERR_DEBUGF("dlopen(fileName, mode)...\n");
            if ((detached = dlopen(fileName, mode))) {
                return detached;
            } else {
                char *err = dlerror();
                LOG_STDERR_ERRORF("...failed err = \"%s\" on dlopen(fileName, mode)\n", err);
            }
        }
        return (DLibraryAttachedT)DLibraryUnattached;
    }
    virtual bool CloseDetached(DLibraryAttachedT detached) const {
        if ((DLibraryAttachedT)DLibraryUnattached != (detached)) {
            int err = 0;

            LOG_STDERR_DEBUGF("dlclose(detached)...\n");
            if ((err = dlclose(detached))) {
                char *err = dlerror();
                LOG_STDERR_DEBUGF("...failed err = %s on dlclose(detached)\n", err);
            } else {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual DLibraryAttachedT Attach(DLibraryAttachedT detached) {
        m_attachedTo = detached;
        return m_attachedTo;
    }
    virtual DLibraryAttachedT Detach() {
        DLibraryAttachedT detached = m_attachedTo;
        m_attachedTo = (DLibraryAttachedT)DLibraryUnattached;
        return detached;
    }
    virtual DLibraryAttachedT AttachedTo() const {
        return m_attachedTo;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    DLibraryAttachedT m_attachedTo;
};

} // namespace Posix
} // namespace OS 
} // namespace uLucidity 

#endif // ULUCIDITY_OS_POSIX_DLIBRARY_HPP 
