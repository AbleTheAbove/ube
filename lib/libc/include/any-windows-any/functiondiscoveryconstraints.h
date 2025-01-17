/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_FUNCTIONDISCOVERYCONSTRAINTS
#define _INC_FUNCTIONDISCOVERYCONSTRAINTS
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

#define FD_CONSTRAINTVALUE_RECURSESUBCATEGORY_TRUE L"TRUE"
#define FD_CONSTRAINTVALUE_VISIBILITY_ALL L"1"
#define FD_CONSTRAINTVALUE_VISIBILITY_DEFAULT L"0"
#define FD_QUERYCONSTRAINT_COMCLSCONTEXT L"COMClsContext"
#define FD_CONSTRAINTVALUE_COMCLSCONTEXT_INPROC_SERVER L"1"
#define FD_CONSTRAINTVALUE_COMCLSCONTEXT_LOCAL_SERVER L"4"
#define FD_QUERYCONSTRAINT_PROVIDERINSTANCEID L"ProviderInstanceID"
#define FD_QUERYCONSTRAINT_RECURSESUBCATEGORY L"RecurseSubcategory"
#define FD_QUERYCONSTRAINT_SUBCATEGORY L"Subcategory"
#define FD_QUERYCONSTRAINT_VISIBILITY L"Visibility"
#define FD_QUERYCONSTRAINT_ROUTINGSCOPE L"RoutingScope"
#define FD_CONSTRAINTVALUE_ROUTINGSCOPE_ALL (L"All")
#define FD_CONSTRAINTVALUE_ROUTINGSCOPE_DIRECT (L"Direct")
#define PROVIDERWNET_QUERYCONSTRAINT_PROPERTIES L"Properties"
#define PROVIDERWNET_QUERYCONSTRAINT_RESOURCETYPE L"ResourceType"
#define PROVIDERWNET_QUERYCONSTRAINT_TYPE L"Type"
#define WNET_CONSTRAINTVALUE_PROPERTIES_ALL L"All"
#define WNET_CONSTRAINTVALUE_PROPERTIES_LIMITED L"Limited"
#define WNET_CONSTRAINTVALUE_TYPE_ALL L"All"
#define WNET_CONSTRAINTVALUE_TYPE_DOMAIN L"Domain"
#define WNET_CONSTRAINTVALUE_RESOURCETYPE_DISK L"Disk"
#define WNET_CONSTRAINTVALUE_RESOURCETYPE_DISKORPRINTER L"DiskOrPrinter"
#define WNET_CONSTRAINTVALUE_RESOURCETYPE_PRINTER L"Printer"
#define PNP_CONSTRAINTVALUE_NOTPRESENT L"TRUE"
#define PNP_CONSTRAINTVALUE_NOTIFICATIONSONLY L"TRUE"
#define PROVIDERPNP_QUERYCONSTRAINT_INTERFACECLASS L"InterfaceClass"
#define PROVIDERPNP_QUERYCONSTRAINT_NOTIFICATIONSONLY L"NotifyOnly"
#define PROVIDERPNP_QUERYCONSTRAINT_NOTPRESENT L"NotPresent"
#define PROVIDERSSDP_QUERYCONSTRAINT_TYPE L"Type"
#define SSDP_CONSTRAINTVALUE_TYPE_ALL L"ssdp:all"
#define SSDP_CONSTRAINTVALUE_TYPE_ROOT L"upnp:rootdevice"
#define SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX L"urn:schemas-upnp-org:device:"
#define SSDP_CONSTRAINTVALUE_TYPE_SVC_PREFIX L"urn:schemas-upnp-org:service:"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_IGD L"urn:schemas-upnp-org:device:InternetGatewayDevice:1"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_LANDEVICE L"urn:schemas-upnp-org:device:LANDevice:1"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_LIGHTING L"urn:schemas-upnp-org:device:Lighting:1"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_LUXMETER L"urn:schemas-upnp-org:device:Luxmeter:1"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_MDARNDR L"urn:schemas-upnp-org:device:MediaRenderer:1"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_MDASRVR L"urn:schemas-upnp-org:device:MediaServer:1"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_POWERDEVICE L"urn:schemas-upnp-org:device:PowerDevice:1"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_REMINDER L"urn:schemas-upnp-org:device:Reminder:1"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_WANDEVICE L"urn:schemas-upnp-org:device:WANDevice:1"
#define SSDP_CONSTRAINTVALUE_TYPE_DEV_WANCONNDEVICE L"urn:schemas-upnp-org:device:WANConnectionDevice:1"
#define SSDP_CONSTRAINTVALUE_TYPE_SVC_DIMMING L"urn:schemas-upnp-org:service:DimmingService:1"
#define SSDP_CONSTRAINTVALUE_TYPE_SVC_SCANNER L"urn:schemas-upnp-org:service:Scanner:1"
#define PROVIDERWSD_QUERYCONSTRAINT_DIRECTEDADDRESS L"RemoteAddress"
#define PROVIDERWSD_QUERYCONSTRAINT_SCOPE L"Scope"
#define PROVIDERWSD_QUERYCONSTRAINT_TYPE L"Type"
#define PROVIDERWSD_QUERYCONSTRAINT_SSL_CERT_FOR_CLIENT_AUTH L"SSLClientAuthCert"
#define PROVIDERWSD_QUERYCONSTRAINT_SECURITY_REQUIREMENTS L"SecurityRequirements"
#define WSD_CONSTRAINTVALUE_REQUIRE_SECURECHANNEL (L"1")
#define WSD_CONSTRAINTVALUE_REQUIRE_SECURECHANNEL_AND_COMPACTSIGNATURE (L"2")

typedef enum tagPropertyConstraint {
  QC_EQUALS                                         = 0,
  QC_NOTEQUAL                                       = 1,
  QC_LESSTHAN                                       = 2,
  QC_LESSTHANOREQUAL                   = 3,
  QC_GREATERTHAN                       = 4,
  QC_GREATERTHANOREQUAL   = 5,
  QC_STARTSWITH                        = 6,
  QC_EXISTS                                         = 7,
  QC_DOESNOTEXIST                      = 8,
  QC_CONTAINS                                       = 8 
} PropertyConstraint;

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_FUNCTIONDISCOVERYCONSTRAINTS*/
