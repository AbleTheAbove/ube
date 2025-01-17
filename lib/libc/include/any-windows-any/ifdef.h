/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_IFDEF
#define _INC_IFDEF

#include <ipifcons.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IF_MAX_STRING_SIZE 256
#define IF_MAX_PHYS_ADDRESS_LENGTH 32

typedef UINT32 NET_IF_COMPARTMENT_ID, *PNET_IF_COMPARTMENT_ID;

typedef ULONG NET_IFINDEX, *PNET_IFINDEX;
typedef UINT16 NET_IFTYPE, *PNET_IFTYPE;
typedef NET_IFINDEX IF_INDEX, *PIF_INDEX;

typedef GUID NET_IF_NETWORK_GUID;

typedef enum _IF_OPER_STATUS {
  IfOperStatusUp                                         = 1,
  IfOperStatusDown,
  IfOperStatusTesting,
  IfOperStatusUnknown,
  IfOperStatusDormant,
  IfOperStatusNotPresent,
  IfOperStatusLowerLayerDown 
} IF_OPER_STATUS;

typedef enum _NET_IF_OPER_STATUS {
  NET_IF_OPER_STATUS_UP                                          = 1,
  NET_IF_OPER_STATUS_DOWN,
  NET_IF_OPER_STATUS_TESTING,
  NET_IF_OPER_STATUS_UNKNOWN,
  NET_IF_OPER_STATUS_DORMANT,
  NET_IF_OPER_STATUS_NOT_PRESENT,
  NET_IF_OPER_STATUS_LOWER_LAYER_DOWN
} NET_IF_OPER_STATUS, *PNET_IF_OPER_STATUS;

typedef enum _NET_IF_ADMIN_STATUS {
  NET_IF_ADMIN_STATUS_UP                     = 1,
  NET_IF_ADMIN_STATUS_DOWN,
  NET_IF_ADMIN_STATUS_TESTING 
} NET_IF_ADMIN_STATUS, *PNET_IF_ADMIN_STATUS;

typedef enum _NET_IF_MEDIA_CONNECT_STATE {
  MediaConnectStateUnknown,
  MediaConnectStateConnected,
  MediaConnectStateDisconnected 
} NET_IF_MEDIA_CONNECT_STATE, *PNET_IF_MEDIA_CONNECT_STATE;

typedef enum _NET_IF_ACCESS_TYPE {
  NET_IF_ACCESS_LOOPBACK                                         = 1,
  NET_IF_ACCESS_BROADCAST,
  NET_IF_ACCESS_POINT_TO_POINT,
  NET_IF_ACCESS_POINT_TO_MULTI_POINT,
  NET_IF_ACCESS_MAXIMUM 
} NET_IF_ACCESS_TYPE, *PNET_IF_ACCESS_TYPE;

typedef enum _NET_IF_CONNECTION_TYPE {
  NET_IF_CONNECTION_DEDICATED   = 1,
  NET_IF_CONNECTION_PASSIVE,
  NET_IF_CONNECTION_DEMAND,
  NET_IF_CONNECTION_MAXIMUM 
} NET_IF_CONNECTION_TYPE, *PNET_IF_CONNECTION_TYPE;

typedef enum _NET_IF_DIRECTION_TYPE {
  NET_IF_DIRECTION_SENDRECEIVE,
  NET_IF_DIRECTION_SENDONLY,
  NET_IF_DIRECTION_RECEIVEONLY,
  NET_IF_DIRECTION_MAXIMUM 
} NET_IF_DIRECTION_TYPE, *PNET_IF_DIRECTION_TYPE;

typedef enum _NET_IF_MEDIA_DUPLEX_STATE {
  MediaDuplexStateUnknown,
  MediaDuplexStateHalf,
  MediaDuplexStateFull 
} NET_IF_MEDIA_DUPLEX_STATE, *PNET_IF_MEDIA_DUPLEX_STATE;

typedef enum _TUNNEL_TYPE {
  TUNNEL_TYPE_NONE                   = 0,
  TUNNEL_TYPE_OTHER     = 1,
  TUNNEL_TYPE_DIRECT    = 2,
  TUNNEL_TYPE_6TO4                   = 11,
  TUNNEL_TYPE_ISATAP    = 13,
  TUNNEL_TYPE_TEREDO    = 14,
  TUNNEL_TYPE_IPHTTPS   = 15
} TUNNEL_TYPE, *PTUNNEL_TYPE;

typedef union _NET_LUID {
  ULONG64 Value;
  __C89_NAMELESS struct { /* bitfield with 64 bit types. */
    ULONG64 Reserved  :24;
    ULONG64 NetLuidIndex  :24;
    ULONG64 IfType  :16;
  } Info;
} NET_LUID, *PNET_LUID;

typedef NET_LUID IF_LUID, *PIF_LUID;

typedef struct _IF_COUNTED_STRING_LH {
    USHORT Length;
    WCHAR  String[IF_MAX_STRING_SIZE + 1];
} IF_COUNTED_STRING_LH, *PIF_COUNTED_STRING_LH;
typedef IF_COUNTED_STRING_LH IF_COUNTED_STRING;
typedef IF_COUNTED_STRING *PIF_COUNTED_STRING;

typedef struct _IF_PHYSICAL_ADDRESS_LH {
    USHORT Length;
    UCHAR  Address[IF_MAX_PHYS_ADDRESS_LENGTH];
} IF_PHYSICAL_ADDRESS_LH, *PIF_PHYSICAL_ADDRESS_LH;
typedef IF_PHYSICAL_ADDRESS_LH IF_PHYSICAL_ADDRESS;
typedef IF_PHYSICAL_ADDRESS *PIF_PHYSICAL_ADDRESS;

#ifdef __cplusplus
}
#endif

#endif /* _INC_IFDEF */

