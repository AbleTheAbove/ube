/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_BTHDEF
#define _INC_BTHDEF

#include <_mingw_unicode.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ULONGLONG according to google */
__MINGW_EXTENSION typedef ULONGLONG BTH_ADDR;
/* ULONG according to google */
typedef ULONG BTH_COD;

/*http://www.koders.com/delphi/fidD54082EB25FCAB99B74E5FDB4F3937EFB567FE9A.aspx*/
/* The following parts are under LGPL */

DEFINE_GUID(GUID_BTHPORT_DEVICE_INTERFACE,0x0850302A,0xB344,0x4fda,0x9B,0xE9,0x90,0x57,0x6B,0x8D,0x46,0xF0);
DEFINE_GUID(GUID_BLUETOOTH_RADIO_IN_RANGE,0xEA3B5B82,0x26EE,0x450E,0xB0,0xD8,0xD2,0x6F,0xE3,0x0A,0x38,0x69);
DEFINE_GUID(GUID_BLUETOOTH_RADIO_OUT_OF_RANGE,0xE28867C9,0xC2AA,0x4CED,0xB9,0x69,0x45,0x70,0x86,0x60,0x37,0xC4);
DEFINE_GUID(GUID_BLUETOOTH_PIN_REQUEST,0xBD198B7C,0x24AB,0x4B9A,0x8C,0x0D,0xA8,0xEA,0x83,0x49,0xAA,0x16);
DEFINE_GUID(GUID_BLUETOOTH_L2CAP_EVENT,0x7EAE4030,0xB709,0x4AA8,0xAC,0x55,0xE9,0x53,0x82,0x9C,0x9D,0xAA);
DEFINE_GUID(GUID_BLUETOOTH_HCI_EVENT,0xFC240062,0x1541,0x49BE,0xB4,0x63,0x84,0xC4,0xDC,0xD7,0xBF,0x7F);
DEFINE_GUID(BLUETOOTH_BASE_UUID,0x00000000,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(SDP_PROTOCOL_UUID,0x00000001,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(UDP_PROTOCOL_UUID,0x00000002,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(RFCOMM_PROTOCOL_UUID,0x00000003,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(TCP_PROTOCOL_UUID,0x00000004,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(TCSBIN_PROTOCOL_UUID,0x00000005,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(TCSAT_PROTOCOL_UUID,0x00000006,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(OBEX_PROTOCOL_UUID,0x00000008,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(IP_PROTOCOL_UUID,0x00000009,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(FTP_PROTOCOL_UUID,0x0000000A,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HTTP_PROTOCOL_UUID,0x0000000C,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(WSP_PROTOCOL_UUID,0x0000000E,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(BNEP_PROTOCOL_UUID,0x0000000F,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(UPNP_PROTOCOL_UUID,0x00000010,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HCCC_PROTOCOL_UUID,0x00000012,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HCDC_PROTOCOL_UUID,0x00000014,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HN_PROTOCOL_UUID,0x00000016,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(AVCTP_PROTOCOL_UUID,0x00000017,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(AVDTP_PROTOCOL_UUID,0x00000019,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(CMPT_PROTOCOL_UUID,0x0000001B,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(UDI_C_PLANE_PROTOCOL_UUID,0x0000001D,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(L2CAP_PROTOCOL_UUID,0x00000100,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);

#define SDP_PROTOCOL_UUID16     0x0001
#define UDP_PROTOCOL_UUID16     0x0002
#define RFCOMM_PROTOCOL_UUID16  0x0003
#define TCP_PROTOCOL_UUID16     0x0004
#define TCSBIN_PROTOCOL_UUID16  0x0005
#define TCSAT_PROTOCOL_UUID16   0x0006
#define OBEX_PROTOCOL_UUID16    0x0008
#define IP_PROTOCOL_UUID16                   0x0009
#define FTP_PROTOCOL_UUID16     0x000A
#define HTTP_PROTOCOL_UUID16    0x000C
#define WSP_PROTOCOL_UUID16     0x000E
#define BNEP_PROTOCOL_UUID16    0x000F
#define UPNP_PROTOCOL_UUID16    0x0010
#define HID_PROTOCOL_UUID16     0x0011
#define HCCC_PROTOCOL_UUID16    0x0012
#define HCDC_PROTOCOL_UUID16    0x0014
#define HCN_PROTOCOL_UUID16     0x0016
#define AVCTP_PROTOCOL_UUID16   0x0017
#define AVDTP_PROTOCOL_UUID16   0x0019
#define CMPT_PROTOCOL_UUID16    0x001B
#define UDI_C_PLANE_PROTOCOL_UUID16 0x001D
#define L2CAP_PROTOCOL_UUID16   0x0100

DEFINE_GUID(ServiceDiscoveryServerServiceClassID_UUID,0x00001000,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(BrowseGroupDescriptorServiceClassID_UUID,0x00001001,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(PublicBrowseGroupServiceClass_UUID,0x00001002,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(SerialPortServiceClass_UUID,0x00001101,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(LANAccessUsingPPPServiceClass_UUID,0x00001102,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(DialupNetworkingServiceClass_UUID,0x00001103,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(IrMCSyncServiceClass_UUID,0x00001104,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(OBEXObjectPushServiceClass_UUID,0x00001105,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(OBEXFileTransferServiceClass_UUID,0x00001106,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(IrMCSyncCommandServiceClass_UUID,0x00001107,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HeadsetServiceClass_UUID,0x00001108,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(CordlessTelephonyServiceClass_UUID,0x00001109,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(AudioSourceServiceClass_UUID,0x0000110A,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(AudioSinkServiceClass_UUID,0x0000110B,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(AVRemoteControlTargetServiceClass_UUID,0x0000110C,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(AdvancedAudioDistributionServiceClass_UUID,0x0000110D,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(AVRemoteControlServiceClass_UUID,0x0000110E,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(VideoConferencingServiceClass_UUID,0x0000110F,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(IntercomServiceClass_UUID,0x00001110,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(FaxServiceClass_UUID,0x00001111,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HeadsetAudioGatewayServiceClass_UUID,0x00001112,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(WAPServiceClass_UUID,0x00001113,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(WAPClientServiceClass_UUID,0x00001114,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(PANUServiceClass_UUID,0x00001115,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(NAPServiceClass_UUID,0x00001116,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(GNServiceClass_UUID,0x00001117,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(DirectPrintingServiceClass_UUID,0x00001118,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(ReferencePrintingServiceClass_UUID,0x00001119,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(ImagingServiceClass_UUID,0x0000111A,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(ImagingResponderServiceClass_UUID,0x0000111B,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(ImagingAutomaticArchiveServiceClass_UUID,0x0000111C,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(ImagingReferenceObjectsServiceClass_UUID,0x0000111D,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HandsfreeServiceClass_UUID,0x0000111E,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HandsfreeAudioGatewayServiceClass_UUID,0x0000111F,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(DirectPrintingReferenceObjectsServiceClass_UUID,0x00001120,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(ReflectedUIServiceClass_UUID,0x00001121,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(BasicPringingServiceClass_UUID,0x00001122,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(PrintingStatusServiceClass_UUID,0x00001123,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HumanInterfaceDeviceServiceClass_UUID,0x00001124,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HardcopyCableReplacementServiceClass_UUID,0x00001125,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HCRPrintServiceClass_UUID,0x00001126,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(HCRScanServiceClass_UUID,0x00001127,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(CommonISDNAccessServiceClass_UUID,0x00001128,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(VideoConferencingGWServiceClass_UUID,0x00001129,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(UDIMTServiceClass_UUID,0x0000112A,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(UDITAServiceClass_UUID,0x0000112B,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(AudioVideoServiceClass_UUID,0x0000112C,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(PnPInformationServiceClass_UUID,0x00001200,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(GenericNetworkingServiceClass_UUID,0x00001201,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(GenericFileTransferServiceClass_UUID,0x00001202,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(GenericAudioServiceClass_UUID,0x00001203,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);
DEFINE_GUID(GenericTelephonyServiceClass_UUID,0x00001204,0x0000,0x1000,0x80,0x00,0x00,0x80,0x5F,0x9B,0x34,0xFB);

#define ServiceDiscoveryServerServiceClassID_UUID16 0x1000
#define BrowseGroupDescriptorServiceClassID_UUID16 0x1001
#define PublicBrowseGroupServiceClassID_UUID16 0x1002
#define SerialPortServiceClassID_UUID16 0x1101
#define LANAccessUsingPPPServiceClassID_UUID16 0x1102
#define DialupNetworkingServiceClassID_UUID16 0x1103
#define IrMCSyncServiceClassID_UUID16 0x1104
#define OBEXObjectPushServiceClassID_UUID16 0x1105
#define OBEXFileTransferServiceClassID_UUID16 0x1106
#define IrMcSyncCommandServiceClassID_UUID16 0x1107
#define HeadsetServiceClassID_UUID16 0x1108
#define CordlessServiceClassID_UUID16 0x1109
#define AudioSourceServiceClassID_UUID16 0x110A
#define AudioSinkSourceServiceClassID_UUID16 0x110B
#define AVRemoteControlTargetServiceClassID_UUID16 0x110C
#define AdvancedAudioDistributionServiceClassID_UUID16 0x110D
#define AVRemoteControlServiceClassID_UUID16 0x110E
#define VideoConferencingServiceClassID_UUID16 0x110F
#define IntercomServiceClassID_UUID16 0x1110
#define FaxServiceClassID_UUID16 0x1111
#define HeadsetAudioGatewayServiceClassID_UUID16 0x1112
#define WAPServiceClassID_UUID16 0x1113
#define WAPClientServiceClassID_UUID16 0x1114
#define PANUServiceClassID_UUID16 0x1115
#define NAPServiceClassID_UUID16 0x1116
#define GNServiceClassID_UUID16 0x1117
#define DirectPrintingServiceClassID_UUID16 0x1118
#define ReferencePrintingServiceClassID_UUID16 0x1119
#define ImagingServiceClassID_UUID16 0x111A
#define ImagingResponderServiceClassID_UUID16 0x111B
#define ImagingAutomaticArchiveServiceClassID_UUID16 0x111C
#define ImagingReferenceObjectsServiceClassID_UUID16 0x111D
#define HandsfreeServiceClassID_UUID16 0x111E
#define HandsfreeAudioGatewayServiceClassID_UUID16 0x111F
#define DirectPrintingReferenceObjectsServiceClassID_UUID16 0x1120
#define ReflectsUIServiceClassID_UUID16 0x1121
#define BasicPrintingServiceClassID_UUID16 0x1122
#define PrintingStatusServiceClassID_UUID16 0x1123
#define HumanInterfaceDeviceServiceClassID_UUID16 0x1124
#define HardcopyCableReplacementServiceClassID_UUID16 0x1125
#define HCRPrintServiceClassID_UUID16 0x1126
#define HCRScanServiceClassID_UUID16 0x1127
#define CommonISDNAccessServiceClass_UUID16 0x1128
#define VideoConferencingGWServiceClass_UUID16 0x1129
#define UDIMTServiceClass_UUID16 0x112A
#define UDITAServiceClass_UUID16 0x112B
#define AudioVideoServiceClass_UUID16 0x112C

#define PnPInformationServiceClassID_UUID16 0x1200
#define GenericNetworkingServiceClassID_UUID16 0x1201
#define GenericFileTransferServiceClassID_UUID16 0x1202
#define GenericAudioServiceClassID_UUID16 0x1203
#define GenericTelephonyServiceClassID_UUID16 0x1204

#define BTH_MAX_NAME_SIZE 248
#define BTH_MAX_PIN_SIZE 16
#define BTH_LINK_KEY_LENGTH 16

#define BTH_MFG_ERICSSON 0
#define BTH_MFG_NOKIA 1
#define BTH_MFG_INTEL 2
#define BTH_MFG_IBM 3
#define BTH_MFG_TOSHIBA 4
#define BTH_MFG_3COM 5
#define BTH_MFG_MICROSOFT 6
#define BTH_MFG_LUCENT 7
#define BTH_MFG_MOTOROLA 8
#define BTH_MFG_INFINEON 9
#define BTH_MFG_CSR 10
#define BTH_MFG_SILICONWAVE 11
#define BTH_MFG_DIGIANSWER 12
#define BTH_MFG_TI 13
#define BTH_MFG_PARTHUS 14
#define BTH_MFG_BROADCOM 15
#define BTH_MFG_MITEL 16
#define BTH_MFG_WIDCOMM 17
#define BTH_MFG_ZEEVO 18
#define BTH_MFG_ATMEL 19
#define BTH_MFG_MITSIBUSHI 20
#define BTH_MFG_RTX_TELECOM 21
#define BTH_MFG_KC_TECHNOLOGY 22
#define BTH_MFG_NEWLOGIC 23
#define BTH_MFG_TRANSILICA 24
#define BTH_MFG_ROHDE_SCHWARZ 25
#define BTH_MFG_TTPCOM 26
#define BTH_MFG_SIGNIA 27
#define BTH_MFG_CONEXANT 28
#define BTH_MFG_QUALCOMM 29
#define BTH_MFG_INVENTEL 30
#define BTH_MFG_AVM_BERLIN 31
#define BTH_MFG_BANDSPEED 32
#define BTH_MFG_MANSELLA 33
#define BTH_MFG_NEC 34
#define BTH_MFG_WAVEPLUS_TECHNOLOGY_CO 35
#define BTH_MFG_ALCATEL 36
#define BTH_MFG_PHILIPS_SEMICONDUCTOR 37
#define BTH_MFG_C_TECHNOLOGIES 38
#define BTH_MFG_OPEN_INTERFACE 39
#define BTH_MFG_RF_MICRO_DEVICES 40
#define BTH_MFG_HITACHI 41
#define BTH_MFG_SYMBOL_TECHNOLOGIES 42
#define BTH_MFG_TENOVIS 43
#define BTH_MFG_MACRONIX_INTERNATIONAL 44
#define BTH_MFG_INTERNAL_USE 65535

#define BTH_ADDR_NULL 0ULL

#define NAP_MASK 0xFFFF00000000ULL
#define SAP_MASK 0x0000FFFFFFFFULL
#define NAP_BIT_OFFSET 32
#define SAP_BIT_OFFSET 0

#define GET_NAP(X) (((X)&NAP_MASK)>>NAP_BIT_OFFSET)
#define GET_SAP(X) (((X)&SAP_MASK)>>SAP_BIT_OFFSET)
#define SET_NAP(X) ((X)<<NAP_BIT_OFFSET)
#define SET_SAP(X) ((X)<<SAP_BIT_OFFSET)
#define SET_NAP_SAP(X,Y) (SET_NAP(X)|SET_SAP(Y))

#define COD_FORMAT_BIT_OFFSET 0
#define COD_MINOR_BIT_OFFSET  2
#define COD_MAJOR_BIT_OFFSET  8
#define COD_SERVICE_BIT_OFFSET 13

#define COD_FORMAT_MASK 0x000003
#define COD_MINOR_MASK  0x0000FC
#define COD_MAJOR_MASK  0x001F00
#define COD_SERVICE_MASK 0xFFE0000

#define GET_COD_FORMAT(X) (((X) & COD_FORMAT_MASK) >> COD_FORMAT_BIT_OFFSET)
#define GET_COD_MINOR(X) (((X) & COD_MINOR_MASK) >> COD_MINOR_BIT_OFFSET)
#define GET_COD_MAJOR(X) (((X) & COD_MAJOR_MASK) >> COD_MAJOR_BIT_OFFSET)
#define GET_COD_SERVICE(X) (((X) & COD_SERVICE_MASK) >> COD_SERVICE_BIT_OFFSET)

#define SET_COD_MINOR(X,Y) (((X) & ~(COD_MINOR_MASK)) | ((Y) << COD_MINOR_BIT_OFFSET))
#define SET_COD_MAJOR(X,Y) (((X) & ~(COD_MAJOR_MASK)) | ((Y) << COD_MAJOR_BIT_OFFSET))
#define SET_COD_SERVICE(X,Y) (((X) & ~(COD_SERVICE_MASK)) | ((Y) << COD_SERVICE_BIT_OFFSET))

#define COD_VERSION 0

#define COD_SERVICE_LIMITED 0x0001
#define COD_SERVICE_POSITIONING 0x0008
#define COD_SERVICE_NETWORKING 0x0010
#define COD_SERVICE_RENDERING 0x0020
#define COD_SERVICE_CAPTURING 0x0040
#define COD_SERVICE_OBJECT_XFER 0x0080
#define COD_SERVICE_AUDIO 0x0100
#define COD_SERVICE_TELEPHONY 0x0200
#define COD_SERVICE_INFORMATION 0x0400

#define COD_SERVICE_VALID_MASK (COD_SERVICE_LIMITED|COD_SERVICE_POSITIONING|COD_SERVICE_NETWORKING|COD_SERVICE_RENDERING|COD_SERVICE_CAPTURING|COD_SERVICE_OBJECT_XFER|COD_SERVICE_AUDIO|COD_SERVICE_TELEPHONY|COD_SERVICE_INFORMATION)

#define COD_SERVICE_MAX_COUNT 9

#define COD_MAJOR_MISCELLANEOUS 0x00
#define COD_MAJOR_COMPUTER 0x01
#define COD_MAJOR_PHONE 0x02
#define COD_MAJOR_LAN_ACCESS 0x03
#define COD_MAJOR_AUDIO 0x04
#define COD_MAJOR_PERIPHERAL 0x05
#define COD_MAJOR_IMAGING 0x06
#define COD_MAJOR_UNCLASSIFIED 0x1F

#define COD_COMPUTER_MINOR_UNCLASSIFIED 0x00
#define COD_COMPUTER_MINOR_DESKTOP 0x01
#define COD_COMPUTER_MINOR_SERVER 0x02
#define COD_COMPUTER_MINOR_LAPTOP 0x03
#define COD_COMPUTER_MINOR_HANDHELD 0x04
#define COD_COMPUTER_MINOR_PALM 0x05
#define COD_COMPUTER_MINOR_WEARABLE 0x06

#define COD_PHONE_MINOR_UNCLASSIFIED 0x00
#define COD_PHONE_MINOR_CELLULAR 0x01
#define COD_PHONE_MINOR_CORDLESS 0x02
#define COD_PHONE_MINOR_SMART 0x03
#define COD_PHONE_MINOR_WIRED_MODEM 0x04

#define COD_AUDIO_MINOR_UNCLASSIFIED 0x00
#define COD_AUDIO_MINOR_HEADSET 0x01
#define COD_AUDIO_MINOR_HANDS_FREE 0x02
#define COD_AUDIO_MINOR_HEADSET_HANDS_FREE 0x03
#define COD_AUDIO_MINOR_MICROPHONE 0x04
#define COD_AUDIO_MINOR_LOUDSPEAKER 0x05
#define COD_AUDIO_MINOR_HEADPHONES 0x06
#define COD_AUDIO_MINOR_PORTABLE_AUDIO 0x07
#define COD_AUDIO_MINOR_CAR_AUDIO 0x08
#define COD_AUDIO_MINOR_SET_TOP_BOX 0x09
#define COD_AUDIO_MINOR_HIFI_AUDIO 0x0A
#define COD_AUDIO_MINOR_VCR 0x0B
#define COD_AUDIO_MINOR_VIDEO_CAMERA 0x0C
#define COD_AUDIO_MINOR_CAMCORDER 0x0D
#define COD_AUDIO_MINOR_VIDEO_MONITOR 0x0E
#define COD_AUDIO_MINOR_VIDEO_DISPLAY_LOUDSPEAKER 0x0F
#define COD_AUDIO_MINOR_VIDEO_DISPLAY_CONFERENCING 0x10
/* #define COD_AUDIO_MINOR_RESERVED 0x11 */
#define COD_AUDIO_MINOR_GAMING_TOY 0x12

#define COD_PERIPHERAL_MINOR_KEYBOARD_MASK 0x10
#define COD_PERIPHERAL_MINOR_POINTER_MASK 0x20

#define COD_PERIPHERAL_MINOR_NO_CATEGORY 0x00
#define COD_PERIPHERAL_MINOR_JOYSTICK 0x01
#define COD_PERIPHERAL_MINOR_GAMEPAD 0x02
#define COD_PERIPHERAL_MINOR_REMOTE_CONTROL 0x03
#define COD_PERIPHERAL_MINOR_SENSING 0x04

#define COD_IMAGING_MINOR_DISPLAY_MASK 0x04
#define COD_IMAGING_MINOR_CAMERA_MASK 0x08
#define COD_IMAGING_MINOR_SCANNER_MASK 0x10
#define COD_IMAGING_MINOR_PRINTER_MASK 0x20

#define COD_LAN_ACCESS_BIT_OFFSET 5
#define COD_LAN_MINOR_MASK 0x0000001C
#define COD_LAN_ACCESS_MASK 0x000000E0

#define GET_COD_LAN_MINOR(X) (((X) & COD_LAN_MINOR_MASK) >> COD_MINOR_BIT_OFFSET)
#define GET_COD_LAN_ACCESS(X) (((X) & COD_LAN_ACCESS_MASK) >> COD_LAN_ACCESS_BIT_OFFSET)

#define COD_LAN_MINOR_UNCLASSIFIED 0x00

#define COD_LAN_ACCESS_0_USED 0x00
#define COD_LAN_ACCESS_17_USED 0x01
#define COD_LAN_ACCESS_33_USED 0x02
#define COD_LAN_ACCESS_50_USED 0x03
#define COD_LAN_ACCESS_67_USED 0x04
#define COD_LAN_ACCESS_83_USED 0x05
#define COD_LAN_ACCESS_99_USED 0x06
#define COD_LAN_ACCESS_FULL 0x07

#define LAP_GIAC_VALUE 0x009E8B00

#define LAP_LIAC_VALUE 0x009E8B00
#define BTH_ADDR_IAC_FIRST 0x9E8B00
#define BTH_ADDR_IAC_LAST 0x9E8B3
#define BTH_ADDR_LIAC 0x9E8B00
#define BTH_ADDR_GIAC 0x9E8B33

typedef UCHAR BTHSTATUS, *PBTHSTATUS;

#define BTH_ERROR(X) ((X) != BTH_ERROR_SUCCESS)
#define BTH_SUCCESS(X) ((X) === BTH_ERROR_SUCCESS)

#define BTH_ERROR_SUCCESS 0x00
#define BTH_ERROR_UNKNOWN_HCI_COMMAND 0x01
#define BTH_ERROR_NO_CONNECTION 0x02
#define BTH_ERROR_HARDWARE_FAILURE 0x03
#define BTH_ERROR_PAGE_TIMEOUT 0x04
#define BTH_ERROR_AUTHENTICATION_FAILURE 0x05
#define BTH_ERROR_KEY_MISSING 0x06
#define BTH_ERROR_MEMORY_FULL 0x07
#define BTH_ERROR_CONNECTION_TIMEOUT 0x08
#define BTH_ERROR_MAX_NUMBER_OF_CONNECTIONS 0x09
#define BTH_ERROR_MAX_NUMBER_OF_SCO_CONNECTIONS 0x0A
#define BTH_ERROR_ACL_CONNECTION_ALREADY_EXISTS 0x0B
#define BTH_ERROR_COMMAND_DISALLOWED 0x0C
#define TH_ERROR_COMMAND_DISALLOWED 0x0D
#define BTH_ERROR_HOST_REJECTED_SECURITY_REASONS 0x0E
#define BTH_ERROR_HOST_REJECTED_PERSONAL_DEVICE 0x0F
#define BTH_ERROR_HOST_TIMEOUT 0x10
#define BTH_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER 0x11
#define BTH_ERROR_INVALID_HCI_PARAMETER 0x12
#define BTH_ERROR_REMOTE_USER_ENDED_CONNECTION 0x13
#define BTH_ERROR_REMOTE_LOW_RESOURCES 0x14
#define BTH_ERROR_REMOTE_POWERING_OFF 0x15
#define BTH_ERROR_LOCAL_HOST_TERMINATED_CONNECTION 0x16
#define BTH_ERROR_REPEATED_ATTEMPTS 0x17
#define BTH_ERROR_PAIRING_NOT_ALLOWED 0x18
#define BTH_ERROR_UKNOWN_LMP_PDU 0x19
#define BTH_ERROR_UNSUPPORTED_REMOTE_FEATURE 0x1A
#define BTH_ERROR_SCO_OFFSET_REJECTED 0x1B
#define BTH_ERROR_SCO_INTERVAL_REJECTED 0x1C
#define BTH_ERROR_SCO_AIRMODE_REJECTED 0x1D
#define BTH_ERROR_INVALID_LMP_PARAMETERS 0x1E
#define BTH_ERROR_UNSPECIFIED_ERROR 0x1F
#define BTH_ERROR_UNSUPPORTED_LMP_PARM_VALUE 0x20
#define BTH_ERROR_ROLE_CHANGE_NOT_ALLOWED 0x21
#define BTH_ERROR_LMP_RESPONSE_TIMEOUT 0x22
#define BTH_ERROR_LMP_TRANSACTION_COLLISION 0x23
#define BTH_ERROR_LMP_PDU_NOT_ALLOWED 0x24
#define BTH_ERROR_ENCRYPTION_MODE_NOT_ACCEPTABLE 0x25
#define BTH_ERROR_UNIT_KEY_NOT_USED 0x26
#define BTH_ERROR_QOS_IS_NOT_SUPPORTED 0x27
#define BTH_ERROR_INSTANT_PASSED 0x28
#define BTH_ERROR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED 0x29
#define BTH_ERROR_UNSPECIFIED 0xFF

#define L2CAP_MIN_MTU 48
#define L2CAP_MAX_MTU 0xFFFF
#define L2CAP_DEFAULT_MTU 672

#define MAX_L2CAP_PING_DATA_LENGTH 44
#define MAX_L2CAP_INFO_DATA_LENGTH 44

#define BDIF_ADDRESS 0x00000001
#define BDIF_COD 0x00000002
#define BDIF_NAME 0x00000004
#define BDIF_PAIRED 0x00000008
#define BDIF_PERSONAL 0x00000010
#define BDIF_CONNECTED 0x00000020
#define BDIF_VALID_FLAGS (BDIF_ADDRESS|BDIF_COD|BDIF_NAME|BDIF_PAIRED|BDIF_PERSONAL|BDIF_CONNECTED)

typedef struct _BTH_DEVICE_INFO {
  ULONG    flags;
  BTH_ADDR address;
  BTH_COD  classOfDevice;
  CHAR     name[BTH_MAX_NAME_SIZE];
} BTH_DEVICE_INFO, *PBTH_DEVICE_INFO;

typedef struct _BTH_RADIO_IN_RANGE {
  BTH_DEVICE_INFO deviceInfo;
  ULONG                        previousDeviceFlags;
} BTH_RADIO_IN_RANGE, *PBTH_RADIO_IN_RANGE;

typedef struct _BTH_L2CAP_EVENT_INFO {
  BTH_ADDR bthAddress;
  USHORT   psm;
  UCHAR    connected;
  UCHAR    initiated;
} BTH_L2CAP_EVENT_INFO, *PBTH_L2CAP_EVENT_INFO;

#define HCI_CONNNECTION_TYPE_ACL 1
#define HCI_CONNNECTION_TYPE_SCO 2

typedef struct _BTH_HCI_EVENT_INFO {
  BTH_ADDR bthAddress;
  UCHAR    connectionType;
  UCHAR    connected;
} BTH_HCI_EVENT_INFO, *PBTH_HCI_EVENT_INFO;

#define MAX_UUIDS_IN_QUERY 12
#define BTH_VID_DEFAULT_VALUE 0xFFFF

#define SDP_ERROR_INVALID_SDP_VERSION 0x0001
#define SDP_ERROR_INVALID_RECORD_HANDLE 0x0002
#define SDP_ERROR_INVALID_REQUEST_SYNTAX 0x0003
#define SDP_ERROR_INVALID_PDU_SIZE 0x0004
#define SDP_ERROR_INVALID_CONTINUATION_STATE 0x0005
#define SDP_ERROR_INSUFFICIENT_RESOURCES 0x0006

#define SDP_ERROR_SUCCESS 0x0000
#define SDP_ERROR_SERVER_INVALID_RESPONSE 0x0100
#define SDP_ERROR_SERVER_RESPONSE_DID_NOT_PARSE 0x0200
#define SDP_ERROR_SERVER_BAD_FORMAT 0x0300
#define SDP_ERROR_COULD_NOT_SEND_CONTINUE 0x0400
#define SDP_ERROR_RESPONSE_TOO_LARGE 0x0500

#define SDP_ATTRIB_RECORD_HANDLE 0x0000
#define SDP_ATTRIB_CLASS_ID_LIST 0x0001
#define SDP_ATTRIB_RECORD_STATE 0x0002
#define SDP_ATTRIB_SERVICE_ID 0x0003
#define SDP_ATTRIB_PROTOCOL_DESCRIPTOR_LIST 0x0004
#define SDP_ATTRIB_BROWSE_GROUP_LIST 0x0005
#define SDP_ATTRIB_LANG_BASE_ATTRIB_ID_LIST 0x0006
#define SDP_ATTRIB_INFO_TIME_TO_LIVE 0x0007
#define SDP_ATTRIB_AVAILABILITY 0x0008
#define SDP_ATTRIB_PROFILE_DESCRIPTOR_LIST 0x0009
#define SDP_ATTRIB_DOCUMENTATION_URL 0x000A
#define SDP_ATTRIB_CLIENT_EXECUTABLE_URL 0x000B
#define SDP_ATTRIB_ICON_URL 0x000C
#define SDP_ATTRIB_ADDITIONAL_PROTOCOL_DESCRIPTOR_LIST 0x000D

#define SDP_ATTRIB_PROFILE_SPECIFIC 0x0200

#define LANG_BASE_LANGUAGE_INDEX 0x0000
#define LANG_BASE_ENCODING_INDEX 0x0001
#define LANG_BASE_OFFSET_INDEX 0x0002
#define LANG_DEFAULT_ID 0x0100

#define STRING_NAME_OFFSET 0x0000
#define STRING_DESCRIPTION_OFFSET 0x0001
#define STRING_PROVIDER_NAME_OFFSET 0x0002

#define SDP_ATTRIB_SDP_VERSION_NUMBER_LIST 0x0200
#define SDP_ATTRIB_SDP_DATABASE_STATE 0x0201

#define SDP_ATTRIB_BROWSE_GROUP_ID 0x0200

#define SDP_ATTRIB_CORDLESS_EXTERNAL_NETWORK 0x0301

#define SDP_ATTRIB_FAX_CLASS_1_SUPPORT 0x0302
#define SDP_ATTRIB_FAX_CLASS_2_0_SUPPORT 0x0303
#define SDP_ATTRIB_FAX_CLASS_2_SUPPORT 0x0304
#define SDP_ATTRIB_FAX_AUDIO_FEEDBACK_SUPPORT 0x0305

#define SDP_ATTRIB_HEADSET_REMOTE_AUDIO_VOLUME_CONTROL 0x0302

#define SDP_ATTRIB_LAN_LPSUBNET 0x0200

#define SDP_ATTRIB_OBJECT_PUSH_SUPPORTED_FORMATS_LIST 0x0303
#define SDP_ATTRIB_SYNCH_SUPPORTED_DATA_STORES_LIST 0x0301

#define SDP_ATTRIB_SERVICE_VERSION 0x0300

#define SDP_ATTRIB_PAN_NETWORK_ADDRESS 0x0306
#define SDP_ATTRIB_PAN_WAP_GATEWAY 0x0307
#define SDP_ATTRIB_PAN_HOME_PAGE_URL 0x0308
#define SDP_ATTRIB_PAN_WAP_STACK_TYPE 0x0309
#define SDP_ATTRIB_PAN_SECURITY_DESCRIPTION 0x030A
#define SDP_ATTRIB_PAN_NET_ACCESS_TYPE 0x030B
#define SDP_ATTRIB_PAN_MAX_NET_ACCESS_RATE 0x030C

#define SDP_ATTRIB_IMAGING_SUPPORTED_CAPABILITIES 0x0310
#define SDP_ATTRIB_IMAGING_SUPPORTED_FEATURES 0x0311
#define SDP_ATTRIB_IMAGING_SUPPORTED_FUNCTIONS 0x0312
#define SDP_ATTRIB_IMAGING_TOTAL_DATA_CAPACITY 0x0313

#define SDP_ATTRIB_DI_SPECIFICATION_ID 0x0200
#define SDP_ATTRIB_DI_VENDOR_ID 0x0201
#define SDP_ATTRIB_DI_PRODUCT_ID 0x0202
#define SDP_ATTRIB_DI_VERSION 0x0203
#define SDP_ATTRIB_DI_PRIMARY_RECORD 0x0204
#define SDP_ATTRIB_DI_VENDOR_ID_SOURCE 0x0205

#define SDP_ATTRIB_HID_DEVICE_RELEASE_NUMBER 0x0200
#define SDP_ATTRIB_HID_PARSER_VERSION 0x0201
#define SDP_ATTRIB_HID_DEVICE_SUBCLASS 0x0202
#define SDP_ATTRIB_HID_COUNTRY_CODE 0x0203
#define SDP_ATTRIB_HID_VIRTUAL_CABLE 0x0204
#define SDP_ATTRIB_HID_RECONNECT_INITIATE 0x0205
#define SDP_ATTRIB_HID_DESCRIPTOR_LIST 0x0206
#define SDP_ATTRIB_HID_LANG_ID_BASE_LIST 0x0207
#define SDP_ATTRIB_HID_SDP_DISABLE 0x0208
#define SDP_ATTRIB_HID_BATTERY_POWER 0x0209
#define SDP_ATTRIB_HID_REMOTE_WAKE 0x020A
#define SDP_ATTRIB_HID_REPORT_LIST 0x020B
#define SDP_ATTRIB_HID_SUPERVISION_TIMEOUT 0x020C
#define SDP_ATTRIB_HID_NORMALLY_CONNECTABLE 0x020D
#define SDP_ATTRIB_HID_BOOT_DEVICE 0x020E

#define CORDLESS_EXTERNAL_NETWORK_PSTN 0x01
#define CORDLESS_EXTERNAL_NETWORK_ISDN 0x02
#define CORDLESS_EXTERNAL_NETWORK_GSM 0x03
#define CORDLESS_EXTERNAL_NETWORK_CDMA 0x04
#define CORDLESS_EXTERNAL_NETWORK_ANALOG_CELLULAR 0x05
#define CORDLESS_EXTERNAL_NETWORK_PACKET_SWITCHED 0x06
#define CORDLESS_EXTERNAL_NETWORK_OTHER 0x07

#define OBJECT_PUSH_FORMAT_VCARD_2_1 0x01
#define OBJECT_PUSH_FORMAT_VCARD_3_0 0x02
#define OBJECT_PUSH_FORMAT_VCAL_1_0 0x03
#define OBJECT_PUSH_FORMAT_ICAL_2_0 0x04
#define OBJECT_PUSH_FORMAT_VNOTE 0x05
#define OBJECT_PUSH_FORMAT_VMESSAGE 0x06
#define OBJECT_PUSH_FORMAT_ANY 0xFF

#define SYNCH_DATA_STORE_PHONEBOOK 0x01
#define SYNCH_DATA_STORE_CALENDAR 0x03
#define SYNCH_DATA_STORE_NOTES 0x05
#define SYNCH_DATA_STORE_MESSAGES 0x06

#define DI_VENDOR_ID_SOURCE_BLUETOOTH_SIG 0x0001
#define DI_VENDOR_ID_SOURCE_USB_IF 0x0002

#define PSM_SDP 0x0001
#define PSM_RFCOMM 0x0003
#define PSM_TCS_BIN 0x0005
#define PSM_TCS_BIN_CORDLESS 0x0007
#define PSM_BNEP 0x0000
#define PSM_HID_CONTROL 0x0011
#define PSM_HID_INTERRUPT 0x0013
#define PSM_AVCTP 0x0017
#define PSM_AVDTP 0x0019
#define PSM_UDI_C_PLANE 0x001D

#define STR_ADDR_FMTA "(%02x:%02x:%02x:%02x:%02x:%02x)"
#define STR_ADDR_FMTW L"(%02x:%02x:%02x:%02x:%02x:%02x)"

#define STR_ADDR_SHORT_FMTA "%04x%08x"
#define STR_ADDR_SHORT_FMTW L"%04x%08x"

#define STR_ADDR_FMT __MINGW_NAME_AW(STR_ADDR_FMT)
#define STR_ADDR_SHORT_FMT __MINGW_NAME_AW(STR_ADDR_SHORT_FMT)

#define GET_BITS(X,Y,Z) (((X)>>(Y))&Z)
#define GET_BIT(X,Y) GET_BITS(X,Y,0x1)

#define LMP_3_SLOT_PACKETS(X) GET_BIT(X, 1)
#define LMP_ENCRYPTION(X) GET_BIT(X, 2)
#define LMP_SLOT_OFFSET(X) GET_BIT(X, 3)
#define LMP_TIMING_ACCURACY(X) GET_BIT(X, 4)
#define LMP_SWITCH(X) GET_BIT(X, 5)
#define LMP_HOLD_MODE(X) GET_BIT(X, 6)
#define LMP_SNIFF_MODE(X) GET_BIT(X, 7)
#define LMP_PARK_MODE(X) GET_BIT(X, 8)
#define LMP_RSSI(X) GET_BIT(X, 9)
#define LMP_CHANNEL_QUALITY_DRIVEN_MODE(X) GET_BIT(X, 10)
#define LMP_SCO_LINK(X) GET_BIT(X, 11)
#define LMP_HV2_PACKETS(X) GET_BIT(X, 12)
#define LMP_HV3_PACKETS(X) GET_BIT(X, 13)
#define LMP_MU_LAW_LOG(X) GET_BIT(X, 14)
#define LMP_A_LAW_LOG(X) GET_BIT(X, 15)
#define LMP_CVSD(X) GET_BIT(X, 16)
#define LMP_PAGING_SCHEME(X) GET_BIT(X, 17)
#define LMP_POWER_CONTROL(X) GET_BIT(X, 18)
#define LMP_TRANSPARENT_SCO_DATA(X) GET_BIT(X, 19)
#define LMP_FLOW_CONTROL_LAG(X) GET_BITS(X, 20, 0x3)

#ifdef __cplusplus
}
#endif
#endif /*_INC_BTHDEF*/
