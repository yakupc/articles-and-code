#pragma once

#include "LibraryCGlobal.h"

// Static variable declaration
LIBC_API int func();

static int VAR = 15;
int VAR2 = 15;

// both declaration and definition 
extern int VAR3 = 15;

extern int VAR4;
// when this variable is not defined where it is used, compiler will generate the following errors during link to source code.
// Release\LibraryA.dll : fatal error LNK1120: 1 unresolved externals
// Release\LibraryB.dll : fatal error LNK1120: 1 unresolved externals

LIBC_API extern int VAR5;
