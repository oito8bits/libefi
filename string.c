#include <libefi.h>

INTN memcmp(const VOID *buf1, const VOID *buf2, INTN count)
{
  const UINT8 *p = buf1;
  const UINT8 *q = buf2;

  while(count--)
  { 
    if(*p++ != *q++)
      return p[-1] < q[-1] ? -1 : 1;  
  } 
    
  return 0;
}

VOID *memcpy(VOID *dest, const VOID *src, UINT64 n)
{
  UINT8 *p = dest;
  const UINT8 *q = src;

  while(n--)
    *p++ = *q++;;

  return dest;
}

UINTN strlen(const CHAR16 *str)
{
  const CHAR16 *p = str - 1;

  while(*++p);

  return p - str;
}

INTN strcmp(const CHAR16 *s1, const CHAR16 *s2)
{
  UINTN s1_len = strlen(s1);
  UINTN s2_len = strlen(s2);
  if(s1_len < s2_len)
    return -1;
  else if (s1_len > s2_len)
    return 1;

  return memcmp(s1, s2, s1_len * sizeof(CHAR16));
}

INTN strncmp(const CHAR16 *s1, const CHAR16 *s2, UINTN n)
{
  return memcmp(s1, s2, n * sizeof(CHAR16));
}

VOID *strcpy(CHAR16 *dest, const CHAR16 *src)
{
  return memcpy(dest, src, (strlen(src) + 1) * sizeof(CHAR16));
}

VOID *strcat(CHAR16 *dest, const CHAR16 *src)
{
  strcpy(dest + strlen(dest), src);

  return dest;
}

VOID *strrev(CHAR16 *str)
{
  CHAR16 *p, *q, c;

  p = str;
  q = str + strlen(str) - 1;
  while(q > p)
  {
    c = *q;
    *q-- = *p;
    *p++ = c;
  }

  return str;
}

VOID *memset(VOID *s, UINTN c, UINTN size)
{
  UINT8 *p = s;
  while(size-- > 0)
    *p++ = c;

  return s;
}
