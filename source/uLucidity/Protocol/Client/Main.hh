//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
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
///   File: Main.hh
///
/// Author: $author$
///   Date: 10/4/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_PROTOCOL_CLIENT_MAIN_HH
#define ULUCIDITY_PROTOCOL_CLIENT_MAIN_HH

#include "uLucidity/Protocol/Base/Main.hh"

namespace uLucidity {
namespace Protocol {
namespace Client {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template <class TExtends = uLucidity::Protocol::Base::Maint<>, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;

    typedef typename Extends::string string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint() {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class Maint
typedef Maint<> Main;

} /// namespace Client 
} /// namespace Protocol 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_PROTOCOL_CLIENT_MAIN_HH
