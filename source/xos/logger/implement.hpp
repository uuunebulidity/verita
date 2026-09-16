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
///   File: implement.hpp
///
/// Author: $author$
///   Date: 12/5/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LOGGER_IMPLEMENT_HPP
#define XOS_LOGGER_IMPLEMENT_HPP

#include "xos/logger/message.hpp"

#if !defined(XOS_LOGGER_LEVELS_DEFAULT)
#if defined(TRACE_BUILD)
#define XOS_LOGGER_LEVELS_DEFAULT ::xos::logger::levels::trace
#elif defined(DEBUG_BUILD)
#define XOS_LOGGER_LEVELS_DEFAULT ::xos::logger::levels::debug
#else /// defined(DEBUG_BUILD)
#define XOS_LOGGER_LEVELS_DEFAULT ::xos::logger::levels::error
#endif /// defined(TRACE_BUILD)
#endif /// !defined(XOS_LOGGER_LEVELS_DEFAULT)

namespace xos {
namespace logger {

/// class implementt
template 
<class TMessage = message, class TLock = lock, 
 class TLocked = locked, class TImplements = locked>

class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives;

    typedef TLock lock_t;
    typedef TLocked locked_t;
    
    typedef TMessage message_t;
    typedef typename message_t::string_t string_t;
    typedef typename message_t::char_t char_t;
    typedef typename message_t::end_char_t end_char_t;
    enum { end_char = message_t::end_char };

    /// log...
    virtual void log
    (const levels& _levels, const location& _location, const message& _message) {
        lock_t lock(*this);
        if ((this->is_enabled_for(_levels))) {
            this->log(_location);
            this->log(_message.c_str());
            this->logln();
        }
    }
    virtual void logf
    (const levels& _levels, const location& _location, const char* format, ...) {
        lock_t lock(*this);
        if ((this->is_enabled_for(_levels))) {
            this->log(_location);
            if ((format)) {
                va_list va;
                va_start(va, format);
                this->logfv(format, va);
                va_end(va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const levels& _levels, const location& _location, const char* format, va_list va) {
        lock_t lock(*this);
        if ((this->is_enabled_for(_levels))) {
            this->log(_location);
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const levels& _levels, const location& _location,
     const message& _message, const char* format, va_list va) {
        lock_t lock(*this);
        if ((this->is_enabled_for(_levels))) {
            this->log(_location);
            this->log(_message.c_str());
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }
    virtual void log
    (const levels& _levels, const message& _message) {
        lock_t lock(*this);
        if ((this->is_enabled_for(_levels))) {
            this->log(_message.c_str());
            this->logln();
        }
    }
    virtual void logf
    (const levels& _levels, const char* format, ...) {
        lock_t lock(*this);
        if ((this->is_enabled_for(_levels))) {
            if ((format)) {
                va_list va;
                va_start(va, format);
                this->logfv(format, va);
                va_end(va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const levels& _levels, const char* format, va_list va) {
        lock_t lock(*this);
        if ((this->is_enabled_for(_levels))) {
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const levels& _levels, const message& _message, const char* format, va_list va) {
        lock_t lock(*this);
        if ((this->is_enabled_for(_levels))) {
            this->log(_message.c_str());
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }
    virtual ssize_t vlogf(const levels& _levels, const char* format, va_list va) {
        ssize_t count = 0;
        lock_t lock(*this);
        if ((this->is_enabled_for(_levels))) {
            if ((format)) {
                count = this->logfv(format, va);
            }
        }
        return count;
    }

    /// enable...
    virtual void enable_for(const levels& _levels) {
    }
    virtual levels enabled_for() const { 
        return enabled_for_default(); 
    }
    virtual bool is_enabled_for(const levels& _levels) const { 
        level::enable enabled = _levels, enabled_for = this->enabled_for();
        bool is_enabled_for = ((level::all == enabled_for) || ((enabled_for & enabled) == enabled));
        return is_enabled_for;
    }
    virtual levels enabled_for_default() const { 
        return levels(XOS_LOGGER_LEVELS_DEFAULT); 
    }

    /// ...default
    static implementt* set_default(implementt* to) {
        implementt* old_logger = the_default();
        the_default() = to;
        return old_logger;
    }
    static implementt* get_default() {
        return the_default();
    }
protected:
    static implementt*& the_default() {
        static implementt* the_default = 0;
        return the_default;
    }

protected:
    /// log...
    virtual ssize_t log(const location& _location) {
        ssize_t count = logl
        (_location.file_name().chars(),
         "[", _location.line_number().chars(), "]",
         " ", _location.function_name().chars(), " ", NULL);
        return count;
    }
    virtual ssize_t logl(const char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        if ((chars)) {
            count = logv(chars, va);
        }
        va_end(va);
        return count;
    }
    virtual ssize_t logv(const char_t* chars, va_list va) {
        ssize_t count = 0;
        ssize_t amount = 0;
        for (count = 0; chars; count += amount) {
            if (0 > (amount = log(chars)))
                return amount;
            chars = va_arg(va, const char_t*);
        }
        return count;
    }
    virtual ssize_t logfv(const char_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t log(const char_t* chars) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t log_flush() {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t logln() {
        ssize_t count = log("\n");
        log_flush();
        return count;
    }

}; /// class implementt
typedef implementt<> implement;

/// ...default
implement* set_default(implement* to);
implement* get_default();

/// class instancet
template <class TExtends = extend, class TImplements = implement>
class exported instancet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef instancet derives;

    typedef typename implements::message_t message_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    /// constructor / destructor
    instancet(levels enabled_for)
    : old_default_(implements::the_default()), 
      enabled_for_(enabled_for) {
        implements::the_default() = this;
    }
    instancet()
    : old_default_(implements::the_default()), 
      enabled_for_(implements::enabled_for_default()) {
        implements::the_default() = this;
    }
    virtual ~instancet() {
        if (implements::the_default() == this) {
            implements::the_default() = old_default_;
        }
    }
private:
    instancet(const instancet& copy): extends(copy) {
        throw exception(exception_unexpected);
    }

public:
    /// enable...
    virtual void enable_for(const levels& _levels) {
        enabled_for_ = _levels;
    }
    virtual levels enabled_for() const {
        return enabled_for_;
    }

protected:
    implements* old_default_;
    levels enabled_for_;
}; /// class instancet
typedef instancet<> instance;

} /// namespace logger
} /// namespace xos

#endif /// ndef XOS_LOGGER_IMPLEMENT_HPP
