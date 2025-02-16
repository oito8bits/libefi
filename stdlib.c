#include <libefi.h>

VOID *malloc(UINTN size)
{
  VOID *buffer;
  EFI_STATUS status;

  status = BS->AllocatePool(EfiRuntimeServicesData, size, &buffer);

  if(status != EFI_SUCCESS)
    return NULL;

  return buffer;
}

VOID free(VOID *buffer)
{
  BS->FreePool(buffer);
}

VOID uitoh(CHAR16 *dest, UINT64 number)
{
  INT8 i = 60;
  BOOLEAN left_zero = 1;
  CHAR16 c;

  if(number == 0)
  {
    *dest++ = '0';
    *dest = '\0';
    return;
  }

  while(i != -4)
  {
    c = (number >> i) & 0xf;
    if(!(c) && left_zero)
    {
      i -= 4;
      continue;
    }
    else
      left_zero = 0;

    if(c >= 0 && c <= 9)
      c += L'0';
    else
      c += 0x37;

    *dest++ = c;
    i -= 4;
  }

  *dest = L'\0';
}

VOID itos(CHAR16 *dest, INTN number)
{
  CHAR16 *p = dest;
  UINT8 is_negative = 0;

  if(number < 0)
  {
    number = -number;
    is_negative = 1;
  }

  do
  {
    *p++ = number % 10 + L'0';
    number /= 10;
  } 
  while (number);
  
  if(is_negative)
    *p++ = L'-';

  *p = L'\0';
  strrev(dest);
}

