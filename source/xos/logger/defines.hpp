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
///   File: defines.hpp
///
/// Author: $author$
///   Date: 12/5/2019, 12/22/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LOGGER_DEFINES_HPP
#define XOS_LOGGER_DEFINES_HPP

#include "xos/logger/implement.hpp"

namespace xos {
namespace logger {

} /// namespace logger
} /// namespace xos

/// LOGGER...
/// ...
#if !defined(LOGGER_LEVEL)
#define LOGGER_LEVEL ::xos::logger::level
#endif /// !defined(LOGGER_LEVEL)

#if !defined(LOGGER_MESSAGE)
#define LOGGER_MESSAGE ::xos::logger::message
#endif /// !defined(LOGGER_MESSAGE)

#if !defined(LOGGER_INTERFACE)
#define LOGGER_INTERFACE ::xos::logger::implement
#endif /// !defined(LOGGER_INTERFACE)

#if !defined(LOGGER_GET_DEFAULT)
#define LOGGER_GET_DEFAULT LOGGER_INTERFACE::get_default
#endif /// !defined(LOGGER_GET_DEFAULT)

#if !defined(LOGGER_SET_LEVEL)
#define LOGGER_SET_LEVEL(logger, level) { if (logger) { logger->enable_for(level); } }
#endif /// !defined(LOGGER_SET_LEVEL)

#if !defined(LOGGER_GET_LEVEL)
#define LOGGER_GET_LEVEL(logger, level) { if (logger) { level = logger->enabled_for(); } }
#endif /// !defined(LOGGER_GET_LEVEL)
/// ...
/// LOGGER...

/// LOGGING_LEVELS
/// ...
#define LOGGING_LEVEL ::xos::logger::level::enable
#define LOGGING_LEVEL_FATAL ::xos::logger::level::fatal
#define LOGGING_LEVEL_ERROR ::xos::logger::level::error
#define LOGGING_LEVEL_WARN ::xos::logger::level::warn
#define LOGGING_LEVEL_INFO ::xos::logger::level::info
#define LOGGING_LEVEL_DEBUG ::xos::logger::level::debug
#define LOGGING_LEVEL_TRACE ::xos::logger::level::trace

#define LOGGING_LEVELS ::xos::logger::levels::enable
#define LOGGING_LEVELS_ALL ::xos::logger::levels::all
#define LOGGING_LEVELS_NONE ::xos::logger::levels::none
#define LOGGING_LEVELS_FATAL ::xos::logger::levels::fatal
#define LOGGING_LEVELS_ERROR ::xos::logger::levels::error
#define LOGGING_LEVELS_WARN ::xos::logger::levels::warn
#define LOGGING_LEVELS_INFO ::xos::logger::levels::info
#define LOGGING_LEVELS_DEBUG ::xos::logger::levels::debug
#define LOGGING_LEVELS_TRACE ::xos::logger::levels::trace

#if !defined(LOGGING_LEVELS_DEFAULT)
#if defined(LOGGING_LEVELS_DEFAULT_TRACE)
#define LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_TRACE
#elif defined(LOGGING_LEVELS_DEFAULT_DEBUG)
#define LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_DEBUG
#elif defined(LOGGING_LEVELS_DEFAULT_ERROR)
#define LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_ERROR
#endif /// defined(LOGGING_LEVELS_DEFAULT_TRACE)
#endif /// !defined(LOGGING_LEVELS_DEFAULT)

#if !defined(LOGGING_LEVELS_DEFAULT)
#if defined(TRACE_BUILD)
#define LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_TRACE
#elif defined(DEBUG_BUILD)
#define LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_DEBUG
#else /// defined(DEBUG_BUILD)
#define LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_ERROR
#endif /// defined(TRACE_BUILD)
#endif /// !defined(LOGGING_LEVELS_DEFAULT)

#if !defined(DEFAULT_LOGGING_LEVELS)
#if defined(DEFAULT_LOGGING_LEVELS_TRACE)
#define DEFAULT_LOGGING_LEVELS LOGGING_LEVELS_TRACE
#elif defined(DEFAULT_LOGGING_LEVELS_DEBUG)
#define DEFAULT_LOGGING_LEVELS LOGGING_LEVELS_DEBUG
#elif defined(DEFAULT_LOGGING_LEVELS_ERROR)
#define DEFAULT_LOGGING_LEVELS LOGGING_LEVELS_ERROR
#endif /// defined(DEFAULT_LOGGING_LEVELS_TRACE)
#endif /// !defined(DEFAULT_LOGGING_LEVELS)

#if !defined(DEFAULT_LOGGING_LEVELS)
#define DEFAULT_LOGGING_LEVELS LOGGING_LEVELS_DEFAULT
#endif /// !defined(DEFAULT_LOGGING_LEVELS)
/// ...
/// LOGGING_LEVELS

/// LOGGER_LOG_PLAIN
/// ...
#define LOGGER_LOG_PLAIN(logger_, level_, message_) { \
LOGGER_INTERFACE* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   LOGGER_MESSAGE message; \
   logger->log(level_, message << message_); } }
/// ...
/// LOGGER_LOG_PLAIN

/// LOGGER_FUNCTION
/// ...
#if !defined(__LOGGER_FUNC__)
#define __LOGGER_FUNC__ __FUNCTION__
#endif /// !defined(__LOGGER_FUNC__)

#if !defined(LOGGER_FUNCTION)
#if defined(WINDOWS)
#define LOGGER_FUNCTION ::xos::logger::trimmed::function(__LOGGER_FUNC__)
#else /// defined(WINDOWS)
#define LOGGER_FUNCTION ::xos::logger::function(__LOGGER_FUNC__)
#endif /// defined(WINDOWS)
#endif /// !defined(LOGGER_LOCATION)
/// ...
/// LOGGER_FUNCTION

/// LOGGER_LOG_FUNCTION
/// ...
#define LOGGER_LOG_FUNCTION(logger_, level_, message_) { \
LOGGER_INTERFACE* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   LOGGER_MESSAGE message; \
   logger->log(level_, LOGGER_FUNCTION, message << message_); } }
/// ...
/// LOGGER_LOG_FUNCTION

/// LOGGER_LOCATION
/// ...
#if !defined(LOGGER_LOCATION)
#define LOGGER_LOCATION ::xos::logger::location(LOGGER_FUNCTION, __FILE__, __LINE__)
#define LOGGER_LOCATION_MESSAGE(__message__) (((LOGGER_LOCATION).combined()).append(__message__))
#endif /// !defined(LOGGER_LOCATION)
/// ...
/// LOGGER_LOCATION

/// LOGGER_LOG_LOCATION
/// ...
#define LOGGER_LOG_LOCATION(logger_, level_, message_) { \
LOGGER_INTERFACE* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   LOGGER_MESSAGE message; \
   logger->log(level_, LOGGER_LOCATION, message << message_); } }

#define LOGGER_LOG_LOCATIONF(logger_, level_, format_, ...) { \
LOGGER_INTERFACE* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logf(level_, LOGGER_LOCATION, format_, ##__VA_ARGS__); } }

#define LOGGER_LOG_LOCATION_ANY_LEVEL(logger_, message_) { \
LOGGER_INTERFACE* logger = logger_; \
if ((logger)) {\
   LOGGING_LEVELS level_ = LOGGING_LEVELS_ALL; \
   LOGGER_MESSAGE message; \
   logger->log(level_, LOGGER_LOCATION, message << message_); } }

#define LOGGER_LOG_LOCATION_ANY_LEVELF(logger_, format_, ...) { \
LOGGER_INTERFACE* logger = logger_; \
if ((logger)) {\
   LOGGING_LEVELS level_ = LOGGING_LEVELS_ALL; \
   logger->logf(level_, LOGGER_LOCATION, format_, ##__VA_ARGS__); } }

#define LOGGER_IF_LOGGED_LOCATION(is_logged_, logger_, level_, message_) { \
if ((is_logged_)) { LOGGER_LOG_LOCATION(logger_, level_, message_); } }

#define LOGGER_IF_LOGGED_LOCATIONF(is_logged_, logger_, level_, format_, ...) { \
if ((is_logged_)) { LOGGER_LOG_LOCATIONF(logger_, level_, format_, ##__VA_ARGS__); } }

#define LOGGER_IS_LOGGED_LOCATION(logger_, level_, message_) { \
if ((this->is_logged())) { LOGGER_LOG_LOCATION(logger_, level_, message_); } }

#define LOGGER_IS_LOGGED_LOCATIONF(logger_, level_, format_, ...) { \
if ((this->is_logged())) { LOGGER_LOG_LOCATIONF(logger_, level_, format_,  ##__VA_ARGS__); } }
/// ...
/// LOGGER_LOG_LOCATION

#define LOGGER_LOG_ANY_LEVELFV(logger_, format_, va_) { \
LOGGER_INTERFACE* logger = logger_; \
if ((logger)) {\
   LOGGING_LEVELS level_ = LOGGING_LEVELS_ALL; \
   logger->logfv(level_, format_, va_); } }

/// LOGGER_LOG
/// ...
#if defined(PLAIN_LOGGING)
#define LOGGER_LOG LOGGER_LOG_PLAIN
#define LOGGER_LOGF LOGGER_LOG_PLAINF
#define LOGGER_LOG_ANY_LEVEL LOGGER_LOG_PLAIN_ANY_LEVEL
#define LOGGER_LOG_ANY_LEVELF LOGGER_LOG_PLAIN_ANY_LEVELF
#else /// defined(PLAIN_LOGGING)
#if defined(FUNCTION_LOGGING)
#define LOGGER_LOG LOGGER_LOG_FUNCTION
#define LOGGER_LOGF LOGGER_LOG_FUNCTIONF
#define LOGGER_LOG_ANY_LEVEL LOGGER_LOG_FUNCTION_ANY_LEVEL
#define LOGGER_LOG_ANY_LEVELF LOGGER_LOG_FUNCTION_ANY_LEVELF
#else /// defined(FUNCTION_LOGGING)
#define LOGGER_LOG LOGGER_LOG_LOCATION
#define LOGGER_LOGF LOGGER_LOG_LOCATIONF
#define LOGGER_LOG_ANY_LEVEL LOGGER_LOG_LOCATION_ANY_LEVEL
#define LOGGER_LOG_ANY_LEVELF LOGGER_LOG_LOCATION_ANY_LEVELF
#endif /// defined(FUNCTION_LOGGING)
#endif /// defined(PLAIN_LOGGING)
/// ...
/// LOGGER_LOG

/// LOGGER_IF_LOGGED
/// ...
#if defined(PLAIN_LOGGING)
#define LOGGER_IF_LOGGED LOGGER_IF_LOGGED_PLAIN
#define LOGGER_IF_LOGGEDF LOGGER_IF_LOGGED_PLAINF
#else /// defined(PLAIN_LOGGING)
#if defined(FUNCTION_LOGGING)
#define LOGGER_IF_LOGGED LOGGER_IF_LOGGED_FUNCTION
#define LOGGER_IF_LOGGEDF LOGGER_IF_LOGGED_FUNCTIONF
#else /// defined(FUNCTION_LOGGING)
#define LOGGER_IF_LOGGED LOGGER_IF_LOGGED_LOCATION
#define LOGGER_IF_LOGGEDF LOGGER_IF_LOGGED_LOCATIONF
#endif /// defined(FUNCTION_LOGGING)
#endif /// defined(PLAIN_LOGGING)
/// ...
/// LOGGER_IF_LOGGED

/// LOGGER_IS_LOGGED
/// ...
#if defined(PLAIN_LOGGING)
#define LOGGER_IS_LOGGED LOGGER_IS_LOGGED_PLAIN
#define LOGGER_IS_LOGGEDF LOGGER_IS_LOGGED_PLAINF
#else /// defined(PLAIN_LOGGING)
#if defined(FUNCTION_LOGGING)
#define LOGGER_IS_LOGGED LOGGER_IS_LOGGED_FUNCTION
#define LOGGER_IS_LOGGEDF LOGGER_IS_LOGGED_FUNCTIONF
#else /// defined(FUNCTION_LOGGING)
#define LOGGER_IS_LOGGED LOGGER_IS_LOGGED_LOCATION
#define LOGGER_IS_LOGGEDF LOGGER_IS_LOGGED_LOCATIONF
#endif /// defined(FUNCTION_LOGGING)
#endif /// defined(PLAIN_LOGGING)
/// ...
/// LOGGER_IS_LOGGED

/// LOGGER_  DEFAULT / LEVELS
/// 
#define DEFAULT_LOGGER LOGGER_GET_DEFAULT()
#define SET_LOGGING_LEVEL(level)  LOGGER_SET_LEVEL(DEFAULT_LOGGER, level)
#define GET_LOGGING_LEVEL(level)  LOGGER_GET_LEVEL(DEFAULT_LOGGER, level)
/// ...
/// LOGGER_  DEFAULT / LEVELS

/// LOGGER_LOG_ ANY / FATAL .. TRACE
/// 
#define LOGGER_LOG_ANY(__message__) LOGGER_LOG_ANY_LEVEL(DEFAULT_LOGGER, __message__)
#define LOGGER_LOG_FATAL(__message__) LOGGER_LOG(DEFAULT_LOGGER, LOGGING_LEVEL_FATAL, __message__)
#define LOGGER_LOG_ERROR(__message__) LOGGER_LOG(DEFAULT_LOGGER, LOGGING_LEVEL_ERROR, __message__)
#define LOGGER_LOG_WARN(__message__) LOGGER_LOG(DEFAULT_LOGGER, LOGGING_LEVEL_WARN, __message__)
#define LOGGER_LOG_INFO(__message__) LOGGER_LOG(DEFAULT_LOGGER, LOGGING_LEVEL_INFO, __message__)
#define LOGGER_LOG_DEBUG(__message__) LOGGER_LOG(DEFAULT_LOGGER, LOGGING_LEVEL_DEBUG, __message__)
#define LOGGER_LOG_TRACE(__message__) LOGGER_LOG(DEFAULT_LOGGER, LOGGING_LEVEL_TRACE, __message__)

#define LOGGER_LOG_ANYF(__message__, ...) LOGGER_LOG_ANY_LEVELF(DEFAULT_LOGGER, __message__, ##__VA_ARGS__)
#define LOGGER_LOG_FATALF(__message__, ...) LOGGER_LOGF(DEFAULT_LOGGER, LOGGING_LEVEL_FATAL, __message__, ##__VA_ARGS__)
#define LOGGER_LOG_ERRORF(__message__, ...) LOGGER_LOGF(DEFAULT_LOGGER, LOGGING_LEVEL_ERROR, __message__, ##__VA_ARGS__)
#define LOGGER_LOG_WARNF(__message__, ...) LOGGER_LOGF(DEFAULT_LOGGER, LOGGING_LEVEL_WARN, __message__, ##__VA_ARGS__)
#define LOGGER_LOG_INFOF(__message__, ...) LOGGER_LOGF(DEFAULT_LOGGER, LOGGING_LEVEL_INFO, __message__, ##__VA_ARGS__)
#define LOGGER_LOG_DEBUGF(__message__, ...) LOGGER_LOGF(DEFAULT_LOGGER, LOGGING_LEVEL_DEBUG, __message__, ##__VA_ARGS__)
#define LOGGER_LOG_TRACEF(__message__, ...) LOGGER_LOGF(DEFAULT_LOGGER, LOGGING_LEVEL_TRACE, __message__, ##__VA_ARGS__)

#define LOGGER_LOG_ANYFV(__format__, __va__) LOGGER_LOG_ANY_LEVELFV(DEFAULT_LOGGER, __format__, __va__)
/// ...
/// LOGGER_LOG_ ANY / FATAL .. TRACE

/// LOGGER_IF_LOGGED_ FATAL .. TRACE
/// 
#define LOGGER_IF_LOGGED_FATAL(__is_logged__, __message__) LOGGER_IF_LOGGED(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_FATAL, __message__)
#define LOGGER_IF_LOGGED_ERROR(__is_logged__, __message__) LOGGER_IF_LOGGED(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_ERROR, __message__)
#define LOGGER_IF_LOGGED_WARN(__is_logged__, __message__) LOGGER_IF_LOGGED(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_WARN, __message__)
#define LOGGER_IF_LOGGED_INFO(__is_logged__, __message__) LOGGER_IF_LOGGED(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_INFO, __message__)
#define LOGGER_IF_LOGGED_DEBUG(__is_logged__, __message__) LOGGER_IF_LOGGED(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_DEBUG, __message__)
#define LOGGER_IF_LOGGED_TRACE(__is_logged__, __message__) LOGGER_IF_LOGGED(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_TRACE, __message__)

#define LOGGER_IF_LOGGED_FATALF(__is_logged__, __message__, ...) LOGGER_IF_LOGGEDF(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_FATAL, __message__, ##__VA_ARGS__)
#define LOGGER_IF_LOGGED_ERRORF(__is_logged__, __message__, ...) LOGGER_IF_LOGGEDF(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_ERROR, __message__, ##__VA_ARGS__)
#define LOGGER_IF_LOGGED_WARNF(__is_logged__, __message__, ...) LOGGER_IF_LOGGEDF(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_WARN, __message__, ##__VA_ARGS__)
#define LOGGER_IF_LOGGED_INFOF(__is_logged__, __message__, ...) LOGGER_IF_LOGGEDF(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_INFO, __message__, ##__VA_ARGS__)
#define LOGGER_IF_LOGGED_DEBUGF(__is_logged__, __message__, ...) LOGGER_IF_LOGGEDF(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_DEBUG, __message__, ##__VA_ARGS__)
#define LOGGER_IF_LOGGED_TRACEF(__is_logged__, __message__, ...) LOGGER_IF_LOGGEDF(__is_logged__, DEFAULT_LOGGER, LOGGING_LEVEL_TRACE, __message__, ##__VA_ARGS__)

#define LOGGER_IF_LOGGED_DEBUG_TRACE(__is_debug__, __is_logged__, __message__) \
    if (__is_logged__) { if (__is_debug__) { LOGGER_IF_LOGGED_DEBUG(__is_logged__, __message__); } else { LOGGER_IF_LOGGED_TRACE(__is_logged__, __message__); } }
/// ...
/// LOGGER_IF_LOGGED_ FATAL .. TRACE

/// LOGGER_IS_LOGGED_ FATAL .. TRACE
/// 
#define LOGGER_IS_LOGGED_FATAL(__message__) LOGGER_IF_LOGGED_FATAL(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_ERROR(__message__) LOGGER_IF_LOGGED_ERROR(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_WARN(__message__) LOGGER_IF_LOGGED_WARN(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_INFO(__message__) LOGGER_IF_LOGGED_INFO(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_DEBUG(__message__) LOGGER_IF_LOGGED_DEBUG(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_TRACE(__message__) LOGGER_IF_LOGGED_TRACE(this->is_logged(), __message__)

#define LOGGER_IS_LOGGED_FATALF(__message__) LOGGER_IF_LOGGED_FATALF(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_ERRORF(__message__) LOGGER_IF_LOGGED_ERRORF(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_WARNF(__message__) LOGGER_IF_LOGGED_WARNF(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_INFOF(__message__) LOGGER_IF_LOGGED_INFOF(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_DEBUGF(__message__) LOGGER_IF_LOGGED_DEBUGF(this->is_logged(), __message__)
#define LOGGER_IS_LOGGED_TRACEF(__message__) LOGGER_IF_LOGGED_TRACEF(this->is_logged(), __message__)

#define LOGGER_IS_LOGGED_DEBUG_TRACE(__is_debug__, __message__) \
    if (__is_debug__) { LOGGER_IS_LOGGED_DEBUG(__message__); } else { LOGGER_IS_LOGGED_TRACE(__message__); }
/// ...
/// LOGGER_IS_LOGGED_ FATAL .. TRACE

/// LOGGER_LOG_MESSAGE_ FATAL .. TRACE
/// 
#define LOGGER_LOG_MESSAGE_FATAL(__message__) LOGGER_LOG_PLAIN(DEFAULT_LOGGER, LOGGING_LEVEL_FATAL, __message__)
#define LOGGER_LOG_MESSAGE_ERROR(__message__) LOGGER_LOG_PLAIN(DEFAULT_LOGGER, LOGGING_LEVEL_ERROR, __message__)
#define LOGGER_LOG_MESSAGE_WARN(__message__) LOGGER_LOG_PLAIN(DEFAULT_LOGGER, LOGGING_LEVEL_WARN, __message__)
#define LOGGER_LOG_MESSAGE_INFO(__message__) LOGGER_LOG_PLAIN(DEFAULT_LOGGER, LOGGING_LEVEL_INFO, __message__)
#define LOGGER_LOG_MESSAGE_DEBUG(__message__) LOGGER_LOG_PLAIN(DEFAULT_LOGGER, LOGGING_LEVEL_DEBUG, __message__)
#define LOGGER_LOG_MESSAGE_TRACE(__message__) LOGGER_LOG_PLAIN(DEFAULT_LOGGER, LOGGING_LEVEL_TRACE, __message__)

#endif /// ndef XOS_LOGGER_DEFINES_HPP
