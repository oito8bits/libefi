#ifndef _LIBEFI_INCLUDE_
#define _LIBEFI_INCLUDE_

#include <efi.h>
#include <stdarg.h>

extern EFI_SYSTEM_TABLE *ST;
extern EFI_HANDLE IH;
extern EFI_BOOT_SERVICES *BS;
extern EFI_RUNTIME_SERVICES *RS;

VOID init_lib(EFI_HANDLE, EFI_SYSTEM_TABLE *);

// Console functions.
VOID puts(const CHAR16 *);
VOID putchar(CHAR16);
INTN printf(const CHAR16 *, ...);

// String functions.
INTN memcmp(const VOID *, const VOID *, INTN);
UINTN strlen(const CHAR16 *);
VOID *memset(VOID *, UINTN, UINTN);

// Stdlib functions.
VOID uitoh(CHAR16 *, UINT64);
VOID itos(CHAR16 *, INTN);

// Pool functions.
VOID *bmalloc(UINTN, EFI_MEMORY_TYPE);
VOID bfree(VOID *);

// Mem functions.
VOID *memcpy(VOID *, const VOID *, UINT64);

#endif
