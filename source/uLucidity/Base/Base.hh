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
///   File: Base.hh
///
/// Author: $author$
///   Date: 10/5/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_BASE_HH
#define ULUCIDITY_BASE_HH

#include "uLucidity/Platform/Platform.h"
#include "uLucidity/Base/Base.hpp"
#include "xos/base/base.hpp"

#if !defined(XOS_BASE_2STRING)
#define XOS_BASE_2STRINGX(value) "" #value ""
#define XOS_BASE_2STRING(value) XOS_BASE_2STRINGX(value)
#endif /// !defined(XOS_BASE_2STRING)

namespace uLucidity {

} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_BASE_HH
