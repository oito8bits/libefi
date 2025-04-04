#ifndef _LIBEFI_INCLUDE_
#define _LIBEFI_INCLUDE_

#include <efi.h>
#include <stdarg.h>

extern EFI_SYSTEM_TABLE *ST;
extern EFI_HANDLE IH;
extern EFI_BOOT_SERVICES *BS;
extern EFI_RUNTIME_SERVICES *RS;

VOID init_lib(EFI_HANDLE, EFI_SYSTEM_TABLE *);

// Stdio functions.
VOID puts(const CHAR16 *);
VOID putchar(CHAR16);
INTN printf(const CHAR16 *, ...);

// String functions.
INTN memcmp(const VOID *, const VOID *, INTN);
UINTN strlen(const CHAR16 *);
INTN strcmp(const CHAR16 *, const CHAR16 *);
INTN strncmp(const CHAR16 *, const CHAR16 *, UINTN);
VOID *strcpy(CHAR16 *, const CHAR16 *);
VOID *strcat(CHAR16 *, const CHAR16 *);
VOID *strrev(CHAR16 *str);
VOID *memset(VOID *, UINTN, UINTN);
VOID *memcpy(VOID *, const VOID *, UINT64);

// Stdlib functions.
VOID *malloc(UINTN);
VOID free(VOID *);
VOID uitoh(CHAR16 *, UINT64);
VOID itos(CHAR16 *, INTN);

#endif
