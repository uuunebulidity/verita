///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   File: level.hpp
///
/// Author: $author$
///   Date: 12/5/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LOGGER_LEVEL_HPP
#define XOS_LOGGER_LEVEL_HPP

#include "xos/base/locked.hpp"
#include "xos/base/logged.hpp"

namespace xos {
namespace logger {

/// class levelt
template <class TExtends = extend, class TImplements = implement>
class exported levelt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef levelt derives;

    /// enum enable
    typedef unsigned enable;
    enum {
        none  = 0,

        fatal = 1,
        error = (fatal << 1),
        warn  = (error << 1),
        info  = (warn << 1),
        debug = (info << 1),
        trace = (debug << 1),

        next  = (trace << 1),
        all   = (next - 1),
        last  = (next >> 1),
        first = (fatal)
    };

    /// constructor / destructor
    levelt(enable _enable): enable_(_enable) {
    }
    levelt(const levelt& copy): enable_(copy.enable_) {
    }
    levelt(): enable_(none) {
    }
    virtual ~levelt() {
    }

    /// operator =
    virtual levelt& operator = (enable _enable) {
        enable_ = _enable;
        return *this;
    }
    virtual operator enable() const {
        return enable_;
    }

protected:
    enable enable_;
}; /// class levelt
typedef levelt<> level;

} /// namespace logger
} /// namespace xos

#endif /// ndef XOS_LOGGER_LEVEL_HPP
