// Copyright (C) 2024 Nullman.
// This file is released under the GNU Lesser General Public License 2.1
// You should've received a file titled LICENSE with this software
// If not see the web version at: https://opensource.org/license/lgpl-2-1

#ifndef DO_OR_DIE_H
#define DO_OR_DIE_H

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

void die() {
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

#endif // DO_OR_DIE_H
