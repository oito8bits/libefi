#include <libefi.h>

VOID *bmalloc(UINTN size, EFI_MEMORY_TYPE type)
{
  VOID *buffer;
  EFI_STATUS status;

  status = BS->AllocatePool(type, size, &buffer);

  if(status != EFI_SUCCESS)
    return NULL;

  return buffer;
}

VOID bfree(VOID *buffer)
{
  BS->FreePool(buffer);
}
