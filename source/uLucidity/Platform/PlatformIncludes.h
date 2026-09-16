/**
 **********************************************************************
 * Copyright (c) 1988-2022 $organization$
 *
 *   File: PlatformIncludes.h
 *
 * Author: $author$
 *   Date: 11/1/2022
 **********************************************************************
 */
#ifndef ULUCIDITY_PLATFORM_PLATFORMINCLUDES_H
#define ULUCIDITY_PLATFORM_PLATFORMINCLUDES_H

#include "PlatformBuild.h"

#if defined(WINDOWS)
/*
 * Windows
 * ...
 */
#if !defined(_WINDOWS_)
#define _INC_WINDOWS
#include <windows.h>
#if !defined(_WIN32_WINNT)
#if (WINVER >= 0x0500)
#define _WIN32_WINNT WINVER
#endif /* (WINVER >= 0x500) */
#endif /* !defined(_WIN32_WINNT) */
#undef _INC_WINDOWS
#undef _WINDOWS_
#else /* !defined(_WINDOWS_) */
#endif /* !defined(_WINDOWS_) */

/*
 * Winsock
 * ...
 */
#if defined(WINSOCK_2)
/*
 * Use Windows Sockets 2 API
 */
#if defined(WINSOCK_DEFINED_DEBUG)
#error defined WINSOCK_2
#endif /* defined(WINSOCK_DEFINED_DEBUG) */
#include <winsock2.h>
#include <ws2tcpip.h>
#elif defined(WINSOCK_1)
/*
 * Use Windows Sockets 1 API
 */
#if defined(WINSOCK_DEFINED_DEBUG)
#error defined WINSOCK_1
#endif /* defined(WINSOCK_DEFINED_DEBUG)
#include <winsock.h>
#else /* defined(WINSOCK_2) */
/*
 * Use Default Windows Sockets API
 * <windows.h>
 */
#endif /* defined(WINSOCK_2) */
/*
 * ...
 * Winsock
 */

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <wchar.h>
#include <time.h>
#include <fcntl.h>
#include <io.h>
/*
 * ...
 * Windows
 */
#else /* defined(WINDOWS) */
/*
 * Unix
 * ...
 */
#if defined(MACOSX)
/*
 * Mac OSX
 */
#else /* defined(MACOSX) */
/*
 * Otherwise
 */
#endif /* defined(MACOSX) */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
/*
 * ...
 * Unix
 */
#endif /* defined(WINDOWS) */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* ULUCIDITY_PLATFORM_PLATFORMINCLUDES_H */
