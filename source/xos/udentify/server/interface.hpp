//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2023 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: interface.hpp
///
/// Author: $author$
///   Date: 10/30/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_UDENTIFY_SERVER_INTERFACE_HPP
#define XOS_UDENTIFY_SERVER_INTERFACE_HPP

#include "xos/udentify/base/interface.hpp"

namespace xos {
namespace udentify {
namespace server {

/// class interfacet
template <class TImplements = xos::udentify::base::interfacet<> >
class exported interfacet: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef interfacet derives;

    typedef typename implements::char_t char_t;
    typedef typename implements::string_t string_t;
    
    /// constructor / destructor
    virtual ~interfacet() {
    }

    /// password
    virtual const string_t& password
    (string_t& result, const string_t& user, const string_t& resource, const string_t& password) {
        return result;
    }

    /// set_udentity_path
    virtual const string_t& set_udentity_path(const string_t& to) {
        return to;
    }

    /// the_interface
    static derives* the_interface() {
        derives* the_interface = the_interface_instance();
        return the_interface;
    }
protected:
    /// the_interface_instance
    static derives*& the_interface_instance() {
        static derives* the_interface_instance = 0;
        return the_interface_instance;
    }

protected:
}; /// class interfacet
typedef interfacet<> interface;

namespace extended {
/// class interfacet
template 
<class TExtends = xos::udentify::base::extended::interfacet<> , 
 class TImplements = xos::udentify::server::interfacet<> >
class exported interfacet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef interfacet derives;

    typedef typename implements::char_t char_t;
    typedef typename implements::string_t string_t;
    
    enum { 
        exception_none       = extends::exception_none, 
        exception_unexpected = extends::exception_unexpected, 
        exception_exist      = extends::exception_exist, 
        exception_not_exist  = extends::exception_not_exist 
    }; /// enum

    typedef typename implements::derives implements_interface;
    
    /// constructor / destructor
    interfacet() {
        implements_interface*& the_interface_instance = implements_interface::the_interface_instance();
        if ((the_interface_instance)) {
            throw (exception_exist);
        } else {
            the_interface_instance = this;
        }
    }
    virtual ~interfacet() {
        implements_interface*& the_interface_instance = implements_interface::the_interface_instance();
        if ((the_interface_instance)) {
            if ((the_interface_instance != this)) {
                throw (exception_unexpected);
            } else {
                the_interface_instance = 0;
            }
        } else {
            throw (exception_not_exist);
        }
    }
private:
    interfacet(const interfacet &copy): extends(copy) {
        throw exception(exception_unexpected);
    }
public:

    /// password
    virtual const string_t& password
    (string_t& result, const string_t& user, const string_t& resource, const string_t& password) {
        int unequal = 0;
        const string_t& default_user = this->default_user();

        LOGGER_IS_LOGGED_INFO("!(unequal = \"" << default_user << "\".compare(\"" << user << "\"))...");
        if (!(unequal = default_user.compare(user))) {
            const string_t& default_resource = this->default_resource();

            LOGGER_IS_LOGGED_INFO("...!(" << unequal << " = \"" << default_user << "\".compare(\"" << user << "\"))");
            LOGGER_IS_LOGGED_INFO("!(unequal = \"" << default_resource << "\".compare(\"" << resource << "\"))...");
            if (!(unequal = default_resource.compare(resource))) {
                const string_t& default_password = this->default_password();

                LOGGER_IS_LOGGED_INFO("...!(" << unequal << " = \"" << default_resource << "\".compare(\"" << resource << "\"))");
                LOGGER_IS_LOGGED_INFO("!(unequal = \"" << default_password << "\".compare(\"" << password << "\"))...");
                if (!(unequal = default_password.compare(password))) {
                    const string_t& unknown_password = this->unknown_password();
    
                    LOGGER_IS_LOGGED_INFO("...!(" << unequal << " = \"" << default_password << "\".compare(\"" << password << "\"))");
                    LOGGER_IS_LOGGED_INFO("result.assign(\"" << unknown_password << "\")...");
                    result.assign(unknown_password);
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on !(" << unequal << " = \"" << default_password << "\".compare(\"" << password << "\"))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << unequal << " = \"" << default_resource << "\".compare(\"" << resource << "\"))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << unequal << " = \"" << default_user << "\".compare(\"" << user << "\"))");
        }
        return result;
    }

protected:
}; /// class interfacet
typedef interfacet<> interface;
} /// namespace extended 

} /// namespace server 
} /// namespace udentify 
} /// namespace xos 

#endif /// ndef XOS_UDENTIFY_SERVER_INTERFACE_HPP
