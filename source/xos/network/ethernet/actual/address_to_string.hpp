//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2024 $organization$
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
///   File: address_to_string.hpp
///
/// Author: $author$
///   Date: 10/13/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_TO_STRING_HPP
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_TO_STRING_HPP

#include "xos/network/ethernet/actual/address.hpp"
#include "xos/base/string.hpp"
#include "xos/base/logger.hpp"

namespace xos {
namespace network {
namespace ethernet {
namespace actual {

/// class address_to_stringt
template 
<class TAddress = xos::network::ethernet::actual::address, class TString = xos::string, 
 class TImplement = xos::logged, class TExtends = TString, class TImplements = TImplement>
 class exported address_to_stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef address_to_stringt derives;

     typedef TAddress address_t;
     typedef TString string_t;
     typedef typename string_t::char_t char_t;
 
    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    address_to_stringt(const derives &copy): extends(copy), is_logged_(false) {
    }
    address_to_stringt(const extends &copy): extends(copy), is_logged_(false) {
    }
    address_to_stringt(const address_t& from, const bool& is_logged): is_logged_(is_logged) {
        assign(from);
    }
    address_to_stringt(const address_t& from): is_logged_(false) {
        assign(from);
    }
    address_to_stringt(): is_logged_(false) {
    }
    virtual ~address_to_stringt() {
    }

    //////////////////////////////////////////////////////////////////////////
    using extends::assign;
    virtual derives& assign(const address_t& from) {
        size_t length = 0;

        this->clear();
        LOGGER_IS_LOGGED_INFO("(0 < (length = from.size()))...");
        if (0 < (length = from.size())) {
            const uint8_t *byte = 0;

            LOGGER_IS_LOGGED_INFO("...(0 < (" << length << " = from.size()))");
            for (byte = &from.element(); 0 < length; --length, ++byte) {
                LOGGER_IS_LOGGED_INFO("...this->appendX(" << (unsigned)(*byte) << ", 1)");
                this->appendX(byte, 1);
                if ((1 < length)) {
                    LOGGER_IS_LOGGED_INFO("...this->append(\":\")");
                    this->append(":");
                } else {
                }
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (0 < (" << length << " = from.size()))");
        }
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ...is_logged
    virtual bool set_is_logged(bool to = true) {
        is_logged_ = to;
        return is_logged_;
    }
    virtual bool is_logged() const {
        return is_logged_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    bool is_logged_;
}; /// class address_to_stringt
typedef address_to_stringt<> address_to_string;

} /// namespace actual 
} /// namespace ethernet 
} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_TO_STRING_HPP

