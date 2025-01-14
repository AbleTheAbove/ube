/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _ROUTPROT_H_
#define _ROUTPROT_H_

#include "stm.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RF_ROUTING 0x00000001
#define RF_DEMAND_UPDATE_ROUTES 0x00000004
#define RF_ADD_ALL_INTERFACES 0x00000010
#define RF_MULTICAST 0x00000020
#define RF_POWER 0x00000040

#if MPR50
#define MS_ROUTER_VERSION 0x00000500
#else
#error Router version not defined
#endif

  typedef enum _ROUTING_PROTOCOL_EVENTS {
    ROUTER_STOPPED,SAVE_GLOBAL_CONFIG_INFO,SAVE_INTERFACE_CONFIG_INFO,UPDATE_COMPLETE
  } ROUTING_PROTOCOL_EVENTS;

  typedef enum _NET_INTERFACE_TYPE {
    PERMANENT,DEMAND_DIAL,LOCAL_WORKSTATION_DIAL,REMOTE_WORKSTATION_DIAL
  } NET_INTERFACE_TYPE;

#define IR_PROMISCUOUS 0
#define IR_PROMISCUOUS_MULTICAST 1

  typedef struct _SUPPORT_FUNCTIONS {
    __C89_NAMELESS union {
                   ULONGLONG _Align8;
                   __C89_NAMELESS struct {
	DWORD dwVersion;
	DWORD dwReserved;
                   };
    };
    DWORD (WINAPI *DemandDialRequest)(DWORD ProtocolId,DWORD InterfaceIndex);
    DWORD (WINAPI *SetInterfaceReceiveType)(DWORD ProtocolId,DWORD InterfaceIndex,DWORD InterfaceReceiveType,WINBOOL bActivate);
    DWORD (WINAPI *ValidateRoute)(DWORD ProtocolId,PVOID RouteInfo,PVOID DestAddress);
    DWORD (WINAPI *MIBEntryCreate)(DWORD dwRoutingPid,DWORD dwEntrySize,LPVOID lpEntry);
    DWORD (WINAPI *MIBEntryDelete)(DWORD dwRoutingPid,DWORD dwEntrySize,LPVOID lpEntry);
    DWORD (WINAPI *MIBEntrySet)(DWORD dwRoutingPid,DWORD dwEntrySize,LPVOID lpEntry);
    DWORD (WINAPI *MIBEntryGet)(DWORD dwRoutingPid,DWORD dwInEntrySize,LPVOID lpInEntry,LPDWORD lpOutEntrySize,LPVOID lpOutEntry);
    DWORD (WINAPI *MIBEntryGetFirst)(DWORD dwRoutingPid,DWORD dwInEntrySize,LPVOID lpInEntry,LPDWORD lpOutEntrySize,LPVOID lpOutEntry);
    DWORD (WINAPI *MIBEntryGetNext)(DWORD dwRoutingPid,DWORD dwInEntrySize,LPVOID lpInEntry,LPDWORD lpOutEntrySize,LPVOID lpOutEntry);
    DWORD (WINAPI *GetRouterId)(VOID);
    WINBOOL (WINAPI *HasMulticastBoundary)(DWORD dwIfIndex,DWORD dwGroupAddress);
  } SUPPORT_FUNCTIONS,*PSUPPORT_FUNCTIONS;

#define PROTO_IP_OTHER 1
#define PROTO_IP_LOCAL 2
#define PROTO_IP_NETMGMT 3
#define PROTO_IP_ICMP 4
#define PROTO_IP_EGP 5
#define PROTO_IP_GGP 6
#define PROTO_IP_HELLO 7
#define PROTO_IP_RIP 8
#define PROTO_IP_IS_IS 9
#define PROTO_IP_ES_IS 10
#define PROTO_IP_CISCO 11
#define PROTO_IP_BBN 12
#define PROTO_IP_OSPF 13
#define PROTO_IP_BGP 14

#define PROTO_IP_MSDP 9
#define PROTO_IP_IGMP 10
#define PROTO_IP_BGMP 11

#define PROTO_IP_VRRP 112
#define PROTO_IP_BOOTP 9999
#define PROTO_IP_NT_AUTOSTATIC 10002
#define PROTO_IP_DNS_PROXY 10003
#define PROTO_IP_DHCP_ALLOCATOR 10004
#define PROTO_IP_NAT 10005
#define PROTO_IP_NT_STATIC 10006
#define PROTO_IP_NT_STATIC_NON_DOD 10007
#define PROTO_IP_DIFFSERV 10008
#define PROTO_IP_MGM 10009
#define PROTO_IP_ALG 10010
#define PROTO_IP_H323 10011
#define PROTO_IP_FTP 10012
#define PROTO_IP_DTP 10013

#define PROTOCOL_ID(Type,VendorId,ProtocolId) (((Type & 0x03)<<30)|((VendorId & 0x3FFF)<<16)|(ProtocolId & 0xFFFF))

#define TYPE_FROM_PROTO_ID(X) (((X) >> 30) & 0x03)
#define VENDOR_FROM_PROTO_ID(X) (((X) >> 16) & 0x3FFF)
#define PROTO_FROM_PROTO_ID(X) ((X) & 0xFFFF)

#define PROTO_TYPE_UCAST 0
#define PROTO_TYPE_MCAST 1
#define PROTO_TYPE_MS0 2
#define PROTO_TYPE_MS1 3

#define PROTO_VENDOR_MS0 0x0000
#define PROTO_VENDOR_MS1 0x137
#define PROTO_VENDOR_MS2 0x3FFF

#define MS_IP_BOOTP PROTOCOL_ID(PROTO_TYPE_UCAST,PROTO_VENDOR_MS0,PROTO_IP_BOOTP)
#define MS_IP_RIP PROTOCOL_ID(PROTO_TYPE_UCAST,PROTO_VENDOR_MS0,PROTO_IP_RIP)
#define MS_IP_OSPF PROTOCOL_ID(PROTO_TYPE_UCAST,PROTO_VENDOR_MS0,PROTO_IP_OSPF)
#define MS_IP_BGP PROTOCOL_ID(PROTO_TYPE_UCAST,PROTO_VENDOR_MS1,PROTO_IP_BGP)
#define MS_IP_IGMP PROTOCOL_ID(PROTO_TYPE_MCAST,PROTO_VENDOR_MS1,PROTO_IP_IGMP)
#define MS_IP_BGMP PROTOCOL_ID(PROTO_TYPE_MCAST,PROTO_VENDOR_MS1,PROTO_IP_BGMP)
#define MS_IP_MSDP PROTOCOL_ID(PROTO_TYPE_MCAST,PROTO_VENDOR_MS1,PROTO_IP_MSDP)
#define MS_IP_DNS_PROXY PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_DNS_PROXY)
#define MS_IP_DHCP_ALLOCATOR PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_DHCP_ALLOCATOR)
#define MS_IP_NAT PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_NAT)
#define MS_IP_DIFFSERV PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_DIFFSERV)
#define MS_IP_MGM PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_MGM)
#define MS_IP_VRRP PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_VRRP)
#define MS_IP_DTP PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_DTP)
#define MS_IP_H323 PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_H323)
#define MS_IP_FTP PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_FTP)
#define MS_IP_ALG PROTOCOL_ID(PROTO_TYPE_MS0,PROTO_VENDOR_MS1,PROTO_IP_ALG)

#define IPX_PROTOCOL_BASE 0x0001ffff
#define IPX_PROTOCOL_RIP IPX_PROTOCOL_BASE + 1
#define IPX_PROTOCOL_SAP IPX_PROTOCOL_BASE + 2
#define IPX_PROTOCOL_NLSP IPX_PROTOCOL_BASE + 3

  typedef struct _UPDATE_COMPLETE_MESSAGE {
    ULONG InterfaceIndex;
    ULONG UpdateType;
    ULONG UpdateStatus;
  } UPDATE_COMPLETE_MESSAGE,*PUPDATE_COMPLETE_MESSAGE;

  typedef union _MESSAGE {
    UPDATE_COMPLETE_MESSAGE UpdateCompleteMessage;
    DWORD InterfaceIndex;
  } MESSAGE,*PMESSAGE;

#define RIS_INTERFACE_ADDRESS_CHANGE 0
#define RIS_INTERFACE_ENABLED 1
#define RIS_INTERFACE_DISABLED 2
#define RIS_INTERFACE_MEDIA_PRESENT 3
#define RIS_INTERFACE_MEDIA_ABSENT 4

  typedef struct IPX_ADAPTER_BINDING_INFO {
    ULONG AdapterIndex;
    UCHAR Network[4];
    UCHAR LocalNode[6];
    UCHAR RemoteNode[6];
    ULONG MaxPacketSize;
    ULONG LinkSpeed;
  } IPX_ADAPTER_BINDING_INFO,*PIPX_ADAPTER_BINDING_INFO;

  typedef struct IP_LOCAL_BINDING {
    DWORD Address;
    DWORD Mask;
  } IP_LOCAL_BINDING,*PIP_LOCAL_BINDING;

  typedef struct IP_ADAPTER_BINDING_INFO {
    ULONG AddressCount;
    DWORD RemoteAddress;
    ULONG Mtu;
    ULONGLONG Speed;
    IP_LOCAL_BINDING Address[0];
  } IP_ADAPTER_BINDING_INFO,*PIP_ADAPTER_BINDING_INFO;

#define SIZEOF_IP_BINDING(X) (FIELD_OFFSET(IP_ADAPTER_BINDING_INFO,Address[0]) + ((X) *sizeof(IP_LOCAL_BINDING)))

  typedef DWORD (WINAPI *PSTART_PROTOCOL)(HANDLE NotificationEvent,PSUPPORT_FUNCTIONS SupportFunctions,LPVOID GlobalInfo,ULONG StructureVersion,ULONG StructureSize,ULONG StructureCount);
  typedef DWORD (WINAPI *PSTART_COMPLETE)(VOID);
  typedef DWORD (WINAPI *PSTOP_PROTOCOL)(VOID);
  typedef DWORD (WINAPI *PADD_INTERFACE)(LPWSTR InterfaceName,ULONG InterfaceIndex,NET_INTERFACE_TYPE InterfaceType,DWORD MediaType,WORD AccessType,WORD ConnectionType,PVOID InterfaceInfo,ULONG StructureVersion,ULONG StructureSize,ULONG StructureCount);
  typedef DWORD (WINAPI *PDELETE_INTERFACE)(ULONG InterfaceIndex);
  typedef DWORD (WINAPI *PGET_EVENT_MESSAGE)(ROUTING_PROTOCOL_EVENTS *Event,MESSAGE *Result);
  typedef DWORD (WINAPI *PGET_INTERFACE_INFO)(ULONG InterfaceIndex,PVOID InterfaceInfo,PULONG BufferSize,PULONG StructureVersion,PULONG StructureSize,PULONG StructureCount);
  typedef DWORD (WINAPI *PSET_INTERFACE_INFO)(ULONG InterfaceIndex,PVOID InterfaceInfo,ULONG StructureVersion,ULONG StructureSize,ULONG StructureCount);
  typedef DWORD (WINAPI *PINTERFACE_STATUS)(ULONG InterfaceIndex,WINBOOL InterfaceActive,DWORD StatusType,PVOID StatusInfo);
  typedef DWORD (WINAPI *PQUERY_POWER)(DWORD PowerType);
  typedef DWORD (WINAPI *PSET_POWER)(DWORD PowerType);
  typedef DWORD (WINAPI *PGET_GLOBAL_INFO)(PVOID GlobalInfo,PULONG BufferSize,PULONG StructureVersion,PULONG StructureSize,PULONG StructureCount);
  typedef DWORD (WINAPI *PSET_GLOBAL_INFO)(PVOID GlobalInfo,ULONG StructureVersion,ULONG StructureSize,ULONG StructureCount);
  typedef DWORD (WINAPI *PDO_UPDATE_ROUTES)(ULONG InterfaceIndex);
  typedef DWORD (WINAPI *PMIB_CREATE)(ULONG InputDataSize,PVOID InputData);
  typedef DWORD (WINAPI *PMIB_DELETE)(ULONG InputDataSize,PVOID InputData);
  typedef DWORD (WINAPI *PMIB_GET)(ULONG InputDataSize,PVOID InputData,PULONG OutputDataSize,PVOID OutputData);
  typedef DWORD (WINAPI *PMIB_SET)(ULONG InputDataSize,PVOID InputData);
  typedef DWORD (WINAPI *PMIB_GET_FIRST)(ULONG InputDataSize,PVOID InputData,PULONG OutputDataSize,PVOID OutputData);
  typedef DWORD (WINAPI *PMIB_GET_NEXT)(ULONG InputDataSize,PVOID InputData,PULONG OutputDataSize,PVOID OutputData);
  typedef DWORD (WINAPI *PMIB_SET_TRAP_INFO)(HANDLE Event,ULONG InputDataSize,PVOID InputData,PULONG OutputDataSize,PVOID OutputData);
  typedef DWORD (WINAPI *PMIB_GET_TRAP_INFO)(ULONG InputDataSize,PVOID InputData,PULONG OutputDataSize,PVOID OutputData);
  typedef DWORD (WINAPI *PCONNECT_CLIENT)(ULONG InterfaceIndex,PVOID ClientAddress);
  typedef DWORD (WINAPI *PDISCONNECT_CLIENT)(ULONG InterfaceIndex,PVOID ClientAddress);

#define MRINFO_TUNNEL_FLAG 0x01
#define MRINFO_PIM_FLAG 0x04
#define MRINFO_DOWN_FLAG 0x10
#define MRINFO_DISABLED_FLAG 0x20
#define MRINFO_QUERIER_FLAG 0x40
#define MRINFO_LEAF_FLAG 0x80

  typedef DWORD (WINAPI *PGET_NEIGHBORS)(DWORD InterfaceIndex,PDWORD NeighborList,PDWORD NeighborListSize,PBYTE InterfaceFlags);

#define MFE_NO_ERROR 0
#define MFE_REACHED_CORE 1

#define MFE_OIF_PRUNED 5

#define MFE_PRUNED_UPSTREAM 4
#define MFE_OLD_ROUTER 11

#define MFE_NOT_FORWARDING 2
#define MFE_WRONG_IF 3
#define MFE_BOUNDARY_REACHED 6
#define MFE_NO_MULTICAST 7
#define MFE_IIF 8
#define MFE_NO_ROUTE 9
#define MFE_NOT_LAST_HOP 10
#define MFE_PROHIBITED 12
#define MFE_NO_SPACE 13

  typedef DWORD (WINAPI *PGET_MFE_STATUS)(DWORD InterfaceIndex,DWORD GroupAddress,DWORD SourceAddress,PBYTE StatusCode);

  typedef struct _MPR50_ROUTING_CHARACTERISTICS {
    DWORD dwVersion;
    DWORD dwProtocolId;
    DWORD fSupportedFunctionality;
    PSTART_PROTOCOL pfnStartProtocol;
    PSTART_COMPLETE pfnStartComplete;
    PSTOP_PROTOCOL pfnStopProtocol;
    PGET_GLOBAL_INFO pfnGetGlobalInfo;
    PSET_GLOBAL_INFO pfnSetGlobalInfo;
    PQUERY_POWER pfnQueryPower;
    PSET_POWER pfnSetPower;
    PADD_INTERFACE pfnAddInterface;
    PDELETE_INTERFACE pfnDeleteInterface;
    PINTERFACE_STATUS pfnInterfaceStatus;
    PGET_INTERFACE_INFO pfnGetInterfaceInfo;
    PSET_INTERFACE_INFO pfnSetInterfaceInfo;
    PGET_EVENT_MESSAGE pfnGetEventMessage;
    PDO_UPDATE_ROUTES pfnUpdateRoutes;
    PCONNECT_CLIENT pfnConnectClient;
    PDISCONNECT_CLIENT pfnDisconnectClient;
    PGET_NEIGHBORS pfnGetNeighbors;
    PGET_MFE_STATUS pfnGetMfeStatus;
    PMIB_CREATE pfnMibCreateEntry;
    PMIB_DELETE pfnMibDeleteEntry;
    PMIB_GET pfnMibGetEntry;
    PMIB_SET pfnMibSetEntry;
    PMIB_GET_FIRST pfnMibGetFirstEntry;
    PMIB_GET_NEXT pfnMibGetNextEntry;
    PMIB_SET_TRAP_INFO pfnMibSetTrapInfo;
    PMIB_GET_TRAP_INFO pfnMibGetTrapInfo;
  } MPR50_ROUTING_CHARACTERISTICS;

#if MPR50
  typedef MPR50_ROUTING_CHARACTERISTICS MPR_ROUTING_CHARACTERISTICS;
#endif

  typedef MPR_ROUTING_CHARACTERISTICS *PMPR_ROUTING_CHARACTERISTICS;

#define REGISTER_PROTOCOL_ENTRY_POINT RegisterProtocol
#define REGISTER_PROTOCOL_ENTRY_POINT_STRING "RegisterProtocol"

  typedef DWORD (WINAPI *PREGISTER_PROTOCOL) (PMPR_ROUTING_CHARACTERISTICS pRoutingChar,PMPR_SERVICE_CHARACTERISTICS pServiceChar);

#ifdef __cplusplus
}
#endif
#endif
