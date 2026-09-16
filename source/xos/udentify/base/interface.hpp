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
#ifndef XOS_UDENTIFY_BASE_INTERFACE_HPP
#define XOS_UDENTIFY_BASE_INTERFACE_HPP

#include "xos/base/logger.hpp"
#include "xos/base/logged.hpp"
#include "xos/base/string.hpp"

namespace xos {
namespace udentify {
namespace base {

/// class interfacet
template <class TImplements = xos::loggedt<> >
class exported interfacet: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef interfacet derives;

    typedef char char_t;
    typedef stringt<char_t> string_t;
    
    /// constructor / destructor
    virtual ~interfacet() {
    }

    /// ...default_user
    virtual string_t& set_default_user(const string_t& to) = 0;
    virtual string_t& default_user() const = 0;

    /// ...default_resource
    virtual string_t& set_default_resource(const string_t& to) = 0;
    virtual string_t& default_resource() const = 0;

    /// ...default_password
    virtual string_t& set_default_password(const string_t& to) = 0;
    virtual string_t& default_password() const = 0;

    /// ...unknown_user
    virtual string_t& set_unknown_user(const string_t& to) = 0;
    virtual string_t& unknown_user() const = 0;

    /// ...unknown_resource
    virtual string_t& set_unknown_resource(const string_t& to) = 0;
    virtual string_t& unknown_resource() const = 0;

    /// ...unknown_password
    virtual string_t& set_unknown_password(const string_t& to) = 0;
    virtual string_t& unknown_password() const = 0;

protected:
}; /// class interfacet
typedef interfacet<> interface;

namespace extended {
/// class interfacet
template <class TExtends = xos::extended::loggedt<> , class TImplements = xos::udentify::base::interfacet<> >
class exported interfacet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef interfacet derives;

    typedef typename implements::char_t char_t;
    typedef typename implements::string_t string_t;
    
    enum { 
        exception_none, 
        exception_unexpected, 
        exception_exist, 
        exception_not_exist 
    }; /// enum

    /// constructor / destructor
    interfacet():
        default_user_("user"), 
        default_resource_("resource"), 
        default_password_("password"),
        unknown_user_("unknown"), 
        unknown_resource_(unknown_user_), 
        unknown_password_(unknown_user_){
    }
    virtual ~interfacet() {
    }
private:
    interfacet(const interfacet &copy): extends(copy) {
        throw exception(exception_unexpected);
    }
public:

    /// ...default_user
    virtual string_t& set_default_user(const string_t& to) {
        string_t& default_user = this->default_user();
        default_user.assign(to);
        return default_user;
    }
    virtual string_t& default_user() const {
        return (string_t&)default_user_;
    }

    /// ...default_resource
    virtual string_t& set_default_resource(const string_t& to) {
        string_t& default_resource = this->default_resource();
        default_resource.assign(to);
        return default_resource;
    }
    virtual string_t& default_resource() const {
        return (string_t&)default_resource_;
    }

    /// ...default_password
    virtual string_t& set_default_password(const string_t& to) {
        string_t& default_password = this->default_password();
        default_password.assign(to);
        return default_password;
    }
    virtual string_t& default_password() const {
        return (string_t&)default_password_;
    }

    /// ...unknown_user
    virtual string_t& set_unknown_user(const string_t& to) {
        string_t& unknown_user = this->unknown_user();
        unknown_user.assign(to);
        return unknown_user;
    }
    virtual string_t& unknown_user() const {
        return (string_t&)unknown_user_;
    }

    /// ...unknown_resource
    virtual string_t& set_unknown_resource(const string_t& to) {
        string_t& unknown_resource = this->unknown_resource();
        unknown_resource.assign(to);
        return unknown_resource;
    }
    virtual string_t& unknown_resource() const {
        return (string_t&)unknown_resource_;
    }

    /// ...unknown_password
    virtual string_t& set_unknown_password(const string_t& to) {
        string_t& unknown_password = this->unknown_password();
        unknown_password.assign(to);
        return unknown_password;
    }
    virtual string_t& unknown_password() const {
        return (string_t&)unknown_password_;
    }

protected:
    string_t default_user_, default_resource_, default_password_,
             unknown_user_, unknown_resource_, unknown_password_;
}; /// class interfacet
typedef interfacet<> interface;
} /// namespace extended 

} /// namespace base 
} /// namespace udentify 
} /// namespace xos 

#endif /// ndef XOS_UDENTIFY_BASE_INTERFACE_HPP
