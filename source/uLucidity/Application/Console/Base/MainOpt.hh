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
///   File: MainOpt.hh
///
/// Author: $author$
///   Date: 10/5/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_CONSOLE_BASE_MAINOPT_HH
#define ULUCIDITY_APPLICATION_CONSOLE_BASE_MAINOPT_HH

#include "xos/app/console/main.hpp"

namespace uLucidity {
namespace Application {
namespace Console {

typedef int xos_main_opt_argument_t;
enum {
    XOS_MAIN_OPT_ARGUMENT_NONE     = XOS_CONSOLE_MAIN_OPT_ARGUMENT_NONE,
    XOS_MAIN_OPT_ARGUMENT_REQUIRED = XOS_CONSOLE_MAIN_OPT_ARGUMENT_REQUIRED,
    XOS_MAIN_OPT_ARGUMENT_OPTIONAL = XOS_CONSOLE_MAIN_OPT_ARGUMENT_OPTIONAL
};

typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};

typedef int opt_argument_t;
enum {
    OPT_ARGUMENT_NONE     = MAIN_OPT_ARGUMENT_NONE,
    OPT_ARGUMENT_REQUIRED = MAIN_OPT_ARGUMENT_REQUIRED,
    OPT_ARGUMENT_OPTIONAL = MAIN_OPT_ARGUMENT_OPTIONAL
};

namespace Base {

//////////////////////////////////////////////////////////////////////////
/// class MainOptt
template <class TExtends = xos::app::console::maint<>, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS MainOptt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef MainOptt Derives;

    typedef typename Extends::string_t string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::string_t::char_t char_t;
    
    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    MainOptt() {
    }
    virtual ~MainOptt() {
    }
private:
    MainOptt(const MainOptt &copy): Extends(copy) {
    }
public:

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class MainOptt
typedef MainOptt<> MainOpt;

} /// namespace Base 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_BASE_MAINOPT_HH
