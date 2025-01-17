#ifndef _MOUNTDEV_
#define _MOUNTDEV_

#include <mountmgr.h>

#if (NTDDI_VERSION >= NTDDI_WIN2K)

#define IOCTL_MOUNTDEV_QUERY_UNIQUE_ID                                      CTL_CODE(MOUNTDEVCONTROLTYPE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MOUNTDEV_QUERY_SUGGESTED_LINK_NAME  CTL_CODE(MOUNTDEVCONTROLTYPE, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MOUNTDEV_LINK_CREATED                                         CTL_CODE(MOUNTDEVCONTROLTYPE, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MOUNTDEV_LINK_DELETED                                         CTL_CODE(MOUNTDEVCONTROLTYPE, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct _MOUNTDEV_UNIQUE_ID {
  USHORT UniqueIdLength;
  UCHAR UniqueId[1];
} MOUNTDEV_UNIQUE_ID, *PMOUNTDEV_UNIQUE_ID;

typedef struct _MOUNTDEV_SUGGESTED_LINK_NAME {
  BOOLEAN UseOnlyIfThereAreNoOtherLinks;
  USHORT NameLength;
  WCHAR Name[1];
} MOUNTDEV_SUGGESTED_LINK_NAME, *PMOUNTDEV_SUGGESTED_LINK_NAME;

#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */

#if (NTDDI_VERSION >= NTDDI_WINXP)

#define IOCTL_MOUNTDEV_QUERY_STABLE_GUID                       CTL_CODE(MOUNTDEVCONTROLTYPE, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct _MOUNTDEV_STABLE_GUID {
  GUID StableGuid;
} MOUNTDEV_STABLE_GUID, *PMOUNTDEV_STABLE_GUID;

#endif /* (NTDDI_VERSION >= NTDDI_WINXP) */

/* FIXME : These definitions don't exist in the official header : */
#define IOCTL_MOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY    CTL_CODE(MOUNTDEVCONTROLTYPE, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
typedef struct _MOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY_OUTPUT {
  ULONG Size;
  USHORT OldUniqueIdOffset;
  USHORT OldUniqueIdLength;
  USHORT NewUniqueIdOffset;
  USHORT NewUniqueIdLength;
} MOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY_OUTPUT, *PMOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY_OUTPUT;


#endif /* _MOUNTDEV_ */
