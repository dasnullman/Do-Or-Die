# Do-Or-Die
A C repository to implement the OR directive, as well as a simple Die() function.

# THIS REPOSITORY WILL NOT BE SUPPORTED
# USE AT YOUR OWN RISK

Do or die will include Windows if it's found you haven't and are on a Windows system
To prevent this define DO_OR_DIE_DONT_INCLUDE_WINDOWS

Do or die will automatically replace the or keyword if it's defined
To prevent this and instead have it define OR, define DO_OR_DIE_DONT_REPLACE_OR_KEYWORD

The die() function will automatically call ExitProcess(0) on Windows and exit(0) on POSIX (assumed) systems
If you are on neither of these systems, or you wish to have a different exit code, define DO_OR_DIE_CUSTOM_DIE_HANDLER

Sample definition for DO_OR_DIE_CUSTOM_DIE_HANDLER:
```c
#define DO_OR_DIE_CUSTOM_DIE_HANDLER exit(1)
```

Usage of DO_OR_DIE_CUSTOM_DIE_HANDLER in source code for reference

```c
#ifdef DO_OR_DIE_CUSTOM_DIE_HANDLER
	DO_OR_DIE_CUSTOM_DIE_HANDLER;
	return;
#endif
```
