/**
 **********************************************************************
 * Copyright (c) 1988-2022 $organization$
 *
 *   File: PlatformDefines.h
 *
 * Author: $author$
 *   Date: 11/1/2022
 **********************************************************************
 */
#ifndef ULUCIDITY_PLATFORM_PLATFORMDEFINES_H
#define ULUCIDITY_PLATFORM_PLATFORMDEFINES_H

#include "PlatformBuild.h"

#if defined(WINDOWS)
/*
 * Windows
 * ...
 */
#if !defined(__GNUC__)
/*
 * Visual C++
 * ...
 */
/*
 * ...
 * Visual C++
 */
#else /* !defined(__GNUC__) */
/*
 * Gcc
 * ...
 */
#if defined(CPLATFORM_DEFINED_DEBUG)
#warning Compiler other than Visual C++ (Gcc) being used
#endif /* defined(CPLATFORM_DEFINED_DEBUG) */
/*
 * ...
 * Gcc
 */
#endif /* !defined(__GNUC__) */

#if defined(UNICODE)
#define TCHAR_NOT_CHAR
#endif /* defined(UNICODE) */

#define PLATFORM_EXPORT __declspec(dllexport)
#define PLATFORM_IMPORT __declspec(dllimport)

#define FOREIGN_DIRECTORY_SEPARATOR_CHAR '/'
#define PLATFORM_DIRECTORY_SEPARATOR_CHAR '\\'
#define PLATFORM_VOLUME_SEPARATOR_CHAR ':'
/*
 * ...
 * Windows
 */
#else /* defined(WINDOWS) */
/*
 * Unix
 * ...
 */
#if defined(__GNUC__)
/*
 * Gcc
 * ...
 */
/*
 * ...
 * Gcc
 */
#else /* defined(__GNUC__) */
#error Compiler other than Gcc not supported
#endif /* defined(__GNUC__) */

#define PLATFORM_EXPORT
#define PLATFORM_IMPORT

#if defined(unix)
#define PLATFORM_unix unix
#undef unix
#endif /* defined(unix) */

#if defined(MACOSX)
/*
 * MacOSX
 * ...
 */
#if !defined(PLATFORM_HAS_NO_EXECVPE)
#define PLATFORM_HAS_NO_EXECVPE
#endif /* !defined(PLATFORM_HAS_NO_EXECVPE) */
/*
 * ...
 * MacOSX
 */
#endif /* defined(MACOSX) */

#define FOREIGN_DIRECTORY_SEPARATOR_CHAR '\\'
#define PLATFORM_DIRECTORY_SEPARATOR_CHAR '/'
#define PLATFORM_VOLUME_SEPARATOR_CHAR 0
/*
 * ...
 * Unix
 */
#endif /* defined(WINDOWS) */

#if defined(__MSC__)
/*
 * Visual C++
 * ...
 */
#define PACKED_STRUCT
/*
 * ...
 * Visual C++
 */
#else /* defined(__MSC__) */
#if defined(__GNUC__)
/*
 * Gcc
 * ...
 */
#define PACKED_STRUCT __attribute__ ((packed))
/*
 * ...
 * Gcc
 */
#else /* defined(__GNUC__) */
#error Compiler not supported
#endif /* defined(__GNUC__) */

#define _In_
#define _In_opt_
#define _Out_
#define _Out_opt_
#define _Inout_
#define _Inout_opt_
#define WINAPI

#endif /* defined(__MSC__) */

/*
 * Generic
 * ...
 */
#define UNDEFINED -1

#define NULL_POINTER_VALUE ((void*)(0))

#define INVALID_HANDLE INVALID_HANDLE_VALUE
#define NULL_HANDLE NULL_HANDLE_VALUE
#define NULL_ATOM NULL_ATOM_VALUE
#define NULL_POINTER NULL_POINTER_VALUE

#define NULL_BYTE 0
#define NULL_CHAR 0
#define NULL_TCHAR 0
#define NULL_WCHAR 0

#define ULUCIDITY_PLATFORM_PLATFORM_IMPORT PLATFORM_IMPORT
#define ULUCIDITY_PLATFORM_PLATFORM_EXPORT PLATFORM_EXPORT

#define PLATFORM_EXTENSION_SEPARATOR "."
#define FOREIGN_EXTENSION_SEPARATOR PLATFORM_EXTENSION_SEPARATOR

#define PLATFORM_EXTENSION_SEPARATOR_CHAR '.'
#define FOREIGN_EXTENSION_SEPARATOR_CHAR PLATFORM_EXTENSION_SEPARATOR_CHAR
/*
 * ...
 * Generic
 */

#if defined(__cplusplus)
#define EXPORT_CLASS PLATFORM_EXPORT
#define _EXPORT_CLASS PLATFORM_EXPORT
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* ULUCIDITY_PLATFORM_PLATFORMDEFINES_H */
