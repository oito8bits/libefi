#ifndef _LIBEFI_INCLUDE_
#define _LIBEFI_INCLUDE_

#include <efi.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern EFI_SYSTEM_TABLE *ST;
extern EFI_HANDLE IH;
extern EFI_BOOT_SERVICES *BS;
extern EFI_RUNTIME_SERVICES *RS;

VOID init_lib(EFI_HANDLE, EFI_SYSTEM_TABLE *);

#endif
