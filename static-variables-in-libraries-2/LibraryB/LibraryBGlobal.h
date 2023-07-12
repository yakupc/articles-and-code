#pragma once

#ifdef LIBB_EXPORTS
#define LIBB_API __declspec(dllexport)
#else
#define LIBB_API __declspec(dllimport)
#endif