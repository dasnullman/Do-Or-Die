// Copyright (C) 2024-2025 Nullman.
// This file is released under the GNU Lesser General Public License 2.1
// You should've received a file titled LICENSE with this software
// If not see the web version at: https://opensource.org/license/lgpl-2-1

#ifndef DO_OR_DIE_H
#define DO_OR_DIE_H

#if defined(_MSC_VER) && _MSC_VER > 1400
#pragma once // Doesn't matter on GCC, but header guards are slower on MSVC++. 
#endif 

#if defined(__cplusplus)
extern "C" {
#endif

#ifdef __GNUC__
#define FORCE_INLINE __attribute__((always_inline)) inline
#endif

#ifdef _MSC_VER
#define FORCE_INLINE __forceinline
#endif

#ifdef __clang__
#define FORCE_INLINE __attribute__((always_inline)) inline
#endif

#include <stdio.h>

#if !defined(_INC_WINDOWS) && !defined(DO_OR_DIE_DONT_INCLUDE_WINDOWS) && defined(_WIN32)
#include <Windows.h>
#endif // !INC_WINDOWS && !DO_OR_DIE_DONT_INCLUDE_WINDOWS && _WIN32

#define DONOTHING() (void)0

#ifndef DO_OR_DIE_DONT_REPLACE_OR_KEYWORD

#ifdef or
#undef or
#endif // or

#define or ? DONOTHING() : 


#else // DO_OR_DIE_DONT_REPLACE_OR_KEYWORD

#define OR ? DONOTHING() :

#endif // DO_OR_DIE_DONT_REPLACE_OR_KEYWORD

static inline void die() {
#ifdef DO_OR_DIE_CUSTOM_DIE_HANDLER
	DO_OR_DIE_CUSTOM_DIE_HANDLER;
	return;
#endif
	
#ifdef _WIN32

	ExitProcess(0);
	
#else // _WIN32
// Assume this is a posix system

	exit(0);

#endif // _WIN32
}

#if defined(__cplusplus)
}
#endif

#endif // DO_OR_DIE_H

