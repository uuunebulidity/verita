/**
 **********************************************************************
 * Copyright (c) 1988-2022 $organization$
 *
 *   File: Platform.h
 *
 * Author: $author$
 *   Date: 11/1/2022
 **********************************************************************
 */
#ifndef ULUCIDITY_PLATFORM_PLATFORM_H
#define ULUCIDITY_PLATFORM_PLATFORM_H

#include "PlatformBuild.h"
#include "PlatformCompiler.h"
#include "PlatformIncludes.h"
#include "PlatformDefines.h"
#include "PlatformTypes.h"

#if !defined(NO_LOG_STDERR)
#if defined(DEBUG_BUILD)
#define LOG_STDERR_DEBUGF(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#else /* defined(DEBUG_BUILD)  */
#define LOG_STDERR_DEBUGF(format, ...)
#endif /* defined(DEBUG_BUILD)  */
#define LOG_STDERR_ERRORF(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#else /* !defined(NO_LOG_STDERR) */
#define LOG_STDERR_DEBUGF(format, ...)
#define LOG_STDERR_ERRORF(format, ...)
#endif /* !defined(NO_LOG_STDERR) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* ULUCIDITY_PLATFORM_PLATFORM_H */
