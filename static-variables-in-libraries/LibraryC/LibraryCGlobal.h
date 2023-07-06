#pragma once


#ifdef LIBC_EXPORTS
#define LIBC_API __declspec(dllexport)
#else
#define LIBC_API __declspec(dllimport)
#endif

