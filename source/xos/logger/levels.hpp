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
///   File: levels.hpp
///
/// Author: $author$
///   Date: 12/5/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LOGGER_LEVELS_HPP
#define XOS_LOGGER_LEVELS_HPP

#include "xos/logger/level.hpp"

namespace xos {
namespace logger {

/// class levelst
template <class TExtends = extend, class TImplements = implement>
class exported levelst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef levelst derives;

    /// enum enable
    typedef unsigned enable;
    enum {
        none  = 0,

        fatal = 1,
        error = (((fatal + 1) << 1) - 1),
        warn  = (((error + 1) << 1) - 1),
        info  = (((warn + 1) << 1) - 1),
        debug = (((info + 1) << 1) - 1),
        trace = (((debug + 1) << 1) - 1),

        all = trace,
        last = trace,
        next = (((trace + 1) << 1) - 1),
        first = fatal
    };

    /// constructor / destructor
    levelst(enable _enable): enable_(_enable) {
    }
    levelst(const levelst& copy): enable_(copy.enable_) {
    }
    levelst(): enable_(none) {
    }
    virtual ~levelst() {
    }

    /// operator =
    virtual levelst& operator = (enable _enable) {
        enable_ = _enable;
        return *this;
    }
    virtual operator enable() const {
        return enable_;
    }
    virtual enable enabled() const {
        return enable_;
    }

protected:
    enable enable_;
}; /// class levelst
typedef levelst<> levels;

} /// namespace logger
} /// namespace xos

#endif /// ndef XOS_LOGGER_LEVELS_HPP
