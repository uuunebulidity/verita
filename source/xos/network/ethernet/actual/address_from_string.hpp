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
///   File: address_from_string.hpp
///
/// Author: $author$
///   Date: 10/13/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_FROM_STRING_HPP
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_FROM_STRING_HPP

#include "xos/network/ethernet/actual/address.hpp"
#include "xos/base/string.hpp"
#include "xos/base/logger.hpp"

namespace xos {
namespace network {
namespace ethernet {
namespace actual {

/// class address_from_stringt
template 
<class TAddress = xos::network::ethernet::actual::address, class TString = xos::string, 
 class TImplement = xos::logged, class TExtends = TAddress, class TImplements = TImplement>
class exported address_from_stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef address_from_stringt derives;

    typedef TAddress address_t;
    typedef TString string_t;
    typedef typename string_t::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    address_from_stringt(const derives &copy): extends(copy), is_logged_(false) {
    }
    address_from_stringt(const address_t &copy): extends(copy), is_logged_(false) {
    }
    address_from_stringt(const string_t& from, const bool& is_logged): is_logged_(is_logged) {
        assign(from);
    }
    address_from_stringt(const string_t& from): is_logged_(false) {
        assign(from);
    }
    address_from_stringt(): is_logged_(false) {
    }
    virtual ~address_from_stringt() {
    }

    //////////////////////////////////////////////////////////////////////////
    using extends::assign;
    virtual derives& assign(const string_t& from) {
        const char_t* chars = 0; size_t length = 0; 

        this->clear();
        if ((chars = from.has_chars(length))) {
            uint8_t& element = this->element(); size_t size = this->size();
            uint8_t byte = 0; size_t bytes = 0;
            int8_t nibble = 0; size_t nibbles = 0;
            char_t c = 0;

            for (bytes = 0, nibbles = 0; 0 < length; --length, ++chars) {
                if ((0 <= (nibble = char_to_nibble(c = *chars)))) {
                    if ((nibbles & 1)) {
                        byte = ((byte << 4) | (nibble & 15));
                        if ((size > bytes)) {
                            (&element)[bytes] = byte;
                        } else {
                            this->clear();
                            break;
                        }
                        byte = 0;
                        ++bytes;
                    } else {
                        byte = (nibble & 15);
                    }
                    ++nibbles;
                } else {
                    if ((nibbles & 1)) {
                        if (!(is_byte_separator(c))) {
                            this->clear();
                            break;
                        } else {
                        }
                    } else {
                    }
                }
            }
        } else {
        }
        return *this;
    }
    virtual int8_t char_to_nibble(const char_t& c) const {
        int8_t nibble = 0;
        if (('0' <= c) && ('9' >= c)) {
            nibble = (int8_t)(c - '0');
        } else {
            if (('A' <= c) && ('F' >= c)) {
                nibble = (int8_t)(c - 'A' + 10);
            } else {
                if (('a' <= c) && ('f' >= c)) {
                    nibble = (int8_t)(c - 'a' + 10);
                } else {
                    nibble = -1;
                    if (!(is_byte_separator(c))) {
                        LOGGER_IS_LOGGED_INFO("...invalid char '" << char_to_string(c) << "'");
                    } else {
                    }
                }
            }
        }
        return nibble;
    }
    virtual bool is_byte_separator(const char_t& c) const {
        bool is_true = ((':' == c));
        return is_true;
    }
    //////////////////////////////////////////////////////////////////////////

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
}; /// class address_from_stringt
typedef address_from_stringt<> address_from_string;

} /// namespace actual 
} /// namespace ethernet 
} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_FROM_STRING_HPP
