#ifndef _STRING_INCLUDE_
#define _STRING_INCLUDE_

INTN memcmp(const VOID *, const VOID *, INTN);
UINTN strlen(const CHAR16 *);
VOID *strcpy(CHAR16 *dest, const CHAR16 *src);
VOID *strcat(CHAR16 *, const CHAR16 *);
VOID *memset(VOID *, UINTN, UINTN);
VOID *memcpy(VOID *, const VOID *, UINT64);

#endif
