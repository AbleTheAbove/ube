/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <winapifamily.h>
#include <devpropdef.h>

DEFINE_DEVPROPKEY(PROCESSOR_NUMBER_PKEY,0x5724c81d,0xd5af,0x4c1f,0xa1,0x03,0xa0,0x6e,0x28,0xf2,0x04,0xc6,1);

DEFINE_GUID(GUID_DEVICE_BATTERY,0x72631e54,0x78A4,0x11d0,0xbc,0xf7,0x00,0xaa,0x00,0xb7,0xb3,0x2a);
DEFINE_GUID(GUID_DEVICE_APPLICATIONLAUNCH_BUTTON,0x629758ee,0x986e,0x4d9e,0x8e,0x47,0xde,0x27,0xf8,0xab,0x05,0x4d);
DEFINE_GUID(GUID_DEVICE_SYS_BUTTON,0x4AFA3D53,0x74A7,0x11d0,0xbe,0x5e,0x00,0xA0,0xC9,0x06,0x28,0x57);
DEFINE_GUID(GUID_DEVICE_LID,0x4AFA3D52,0x74A7,0x11d0,0xbe,0x5e,0x00,0xA0,0xC9,0x06,0x28,0x57);
DEFINE_GUID(GUID_DEVICE_THERMAL_ZONE,0x4AFA3D51,0x74A7,0x11d0,0xbe,0x5e,0x00,0xA0,0xC9,0x06,0x28,0x57);
DEFINE_GUID(GUID_DEVICE_PROCESSOR,0x97fadb10,0x4e33,0x40ae,0x35,0x9c,0x8b,0xef,0x02,0x9d,0xbd,0xd0);
DEFINE_GUID(GUID_DEVICE_MEMORY,0x3fd0f03d,0x92e0,0x45fb,0xb7,0x5c,0x5e,0xd8,0xff,0xb0,0x10,0x21);
DEFINE_GUID(GUID_DEVICE_ACPI_TIME,0x97f99bf6,0x4497,0x4f18,0xbb,0x22,0x4b,0x9f,0xb2,0xfb,0xef,0x9c);
DEFINE_GUID(GUID_DEVICE_MESSAGE_INDICATOR,0xcd48a365,0xfa94,0x4ce2,0xa2,0x32,0xa1,0xb7,0x64,0xe5,0xd8,0xb4);
DEFINE_GUID(GUID_CLASS_INPUT,0x4d1e55b2,0xf16f,0x11cf,0x88,0xcb,0x00,0x11,0x11,0x00,0x00,0x30);

#ifndef _POCLASS_
#define _POCLASS_

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define BATTERY_UNKNOWN_CAPACITY 0xffffffff
#define UNKNOWN_CAPACITY BATTERY_UNKNOWN_CAPACITY

#define BATTERY_SET_CHARGE_SUPPORTED 0x1
#define BATTERY_SET_DISCHARGE_SUPPORTED  0x2
#define BATTERY_SET_CHARGINGSOURCE_SUPPORTED 0x4
#define BATTERY_SET_RESUME_SUPPORTED 0x4
#define BATTERY_SEALED 0x10000000
#define BATTERY_IS_SHORT_TERM 0x20000000
#define BATTERY_CAPACITY_RELATIVE 0x40000000
#define BATTERY_SYSTEM_BATTERY 0x80000000

#define BATTERY_UNKNOWN_TIME 0xffffffff

#define BATTERY_UNKNOWN_CURRENT 0xffffffff
#define UNKNOWN_CURRENT BATTERY_UNKNOWN_CURRENT

#define BATTERY_UNKNOWN_VOLTAGE 0xffffffff
#define BATTERY_UNKNOWN_RATE 0x80000000
#define UNKNOWN_RATE BATTERY_UNKNOWN_RATE
#define UNKNOWN_VOLTAGE BATTERY_UNKNOWN_VOLTAGE

#define BATTERY_POWER_ON_LINE 0x1
#define BATTERY_DISCHARGING 0x2
#define BATTERY_CHARGING 0x4
#define BATTERY_CRITICAL 0x8

#define BATTERY_TAG_INVALID 0

#define ACTIVE_COOLING 0x0
#define PASSIVE_COOLING 0x1

#define SYS_BUTTON_POWER 0x1
#define SYS_BUTTON_SLEEP 0x2
#define SYS_BUTTON_LID   0x4
#define SYS_BUTTON_WAKE  0x80000000

#define SYS_BUTTON_LID_STATE_MASK 0x30000
#define SYS_BUTTON_LID_OPEN 0x10000
#define SYS_BUTTON_LID_CLOSED 0x20000
#define SYS_BUTTON_LID_INITIAL 0x40000
#define SYS_BUTTON_LID_CHANGED 0x80000

#define PROCESSOR_PCC_COMMAND_GET_AVERAGE_FREQUENCY 0x0
#define PROCESSOR_PCC_COMMAND_SET_DESIRED_FREQUENCY 0x1

#define ACPI_TIME_ADJUST_DAYLIGHT 0x1
#define ACPI_TIME_IN_DAYLIGHT 0x2
#define ACPI_TIME_ZONE_UNKNOWN 0x7FF

#define PROCESSOR_PCC_INTERFACE_STANDARD_VERSION 1

#define THERMAL_COOLING_INTERFACE_VERSION 1

#define THERMAL_DEVICE_INTERFACE_VERSION 1

#define MAX_BATTERY_STRING_SIZE 128
#define MAX_ACTIVE_COOLING_LEVELS 10

#define IOCTL_SET_SYS_MESSAGE_INDICATOR CTL_CODE(FILE_DEVICE_BATTERY,0x70,METHOD_BUFFERED,FILE_WRITE_ACCESS)

#define IOCTL_SET_WAKE_ALARM_VALUE CTL_CODE(FILE_DEVICE_BATTERY,0x80,METHOD_BUFFERED,FILE_WRITE_ACCESS)
#define IOCTL_SET_WAKE_ALARM_POLICY CTL_CODE(FILE_DEVICE_BATTERY,0x81,METHOD_BUFFERED,FILE_WRITE_ACCESS)
#define IOCTL_GET_WAKE_ALARM_VALUE CTL_CODE(FILE_DEVICE_BATTERY,0x82,METHOD_BUFFERED,FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_GET_WAKE_ALARM_POLICY CTL_CODE(FILE_DEVICE_BATTERY,0x83,METHOD_BUFFERED,FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_ACPI_GET_REAL_TIME CTL_CODE(FILE_DEVICE_BATTERY,0x84,METHOD_BUFFERED,FILE_READ_DATA)
#define IOCTL_ACPI_SET_REAL_TIME CTL_CODE(FILE_DEVICE_BATTERY,0x85,METHOD_BUFFERED,FILE_WRITE_ACCESS)

#define IOCTL_BATTERY_QUERY_TAG CTL_CODE(FILE_DEVICE_BATTERY,0x10,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_BATTERY_QUERY_INFORMATION CTL_CODE(FILE_DEVICE_BATTERY,0x11,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_BATTERY_SET_INFORMATION CTL_CODE(FILE_DEVICE_BATTERY,0x12,METHOD_BUFFERED,FILE_WRITE_ACCESS)
#define IOCTL_BATTERY_QUERY_STATUS CTL_CODE(FILE_DEVICE_BATTERY,0x13,METHOD_BUFFERED,FILE_READ_ACCESS)

#define IOCTL_THERMAL_QUERY_INFORMATION CTL_CODE(FILE_DEVICE_BATTERY,0x20,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_THERMAL_SET_COOLING_POLICY CTL_CODE(FILE_DEVICE_BATTERY,0x21,METHOD_BUFFERED,FILE_WRITE_ACCESS)
#define IOCTL_RUN_ACTIVE_COOLING_METHOD CTL_CODE(FILE_DEVICE_BATTERY,0x22,METHOD_BUFFERED,FILE_WRITE_ACCESS)
#define IOCTL_THERMAL_SET_PASSIVE_LIMIT CTL_CODE(FILE_DEVICE_BATTERY,0x23,METHOD_BUFFERED,FILE_WRITE_ACCESS)
#define IOCTL_THERMAL_READ_TEMPERATURE CTL_CODE(FILE_DEVICE_BATTERY,0x24,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_QUERY_LID CTL_CODE(FILE_DEVICE_BATTERY,0x30,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_NOTIFY_SWITCH_EVENT CTL_CODE(FILE_DEVICE_BATTERY,0x40,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_GET_SYS_BUTTON_CAPS CTL_CODE(FILE_DEVICE_BATTERY,0x50,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_GET_SYS_BUTTON_EVENT CTL_CODE(FILE_DEVICE_BATTERY,0x51,METHOD_BUFFERED,FILE_READ_ACCESS)

#define IOCTL_GET_PROCESSOR_OBJ_INFO \
                     CTL_CODE(FILE_DEVICE_BATTERY,0x60,METHOD_BUFFERED,FILE_READ_ACCESS)

typedef enum {
  BatteryInformation, BatteryGranularityInformation, BatteryTemperature, BatteryEstimatedTime,
  BatteryDeviceName, BatteryManufactureDate, BatteryManufactureName, BatteryUniqueID,
  BatterySerialNumber
} BATTERY_QUERY_INFORMATION_LEVEL;

typedef enum {
  BatteryCriticalBias, BatteryCharge, BatteryDischarge, BatteryChargingSource
} BATTERY_SET_INFORMATION_LEVEL;

typedef enum _BATTERY_CHARGING_SOURCE_TYPE {
  BatteryChargingSourceType_None, BatteryChargingSourceType_AC,
  BatteryChargingSourceType_USB, BatteryChargingSourceType_Wireless
} BATTERY_CHARGING_SOURCE_TYPE, *PBATTERY_CHARGING_SOURCE_TYPE;

typedef struct _BATTERY_QUERY_INFORMATION {
  ULONG BatteryTag;
  BATTERY_QUERY_INFORMATION_LEVEL InformationLevel;
  ULONG AtRate;
} BATTERY_QUERY_INFORMATION, *PBATTERY_QUERY_INFORMATION;

typedef struct _BATTERY_INFORMATION {
  ULONG Capabilities;
  UCHAR Technology;
  UCHAR Reserved[3];
  UCHAR Chemistry[4];
  ULONG DesignedCapacity;
  ULONG FullChargedCapacity;
  ULONG DefaultAlert1;
  ULONG DefaultAlert2;
  ULONG CriticalBias;
  ULONG CycleCount;
} BATTERY_INFORMATION, *PBATTERY_INFORMATION;

typedef struct _BATTERY_CHARGING_SOURCE {
  BATTERY_CHARGING_SOURCE_TYPE Type;
  ULONG MaxCurrent;
} BATTERY_CHARGING_SOURCE, *PBATTERY_CHARGING_SOURCE;

typedef struct _BATTERY_SET_INFORMATION {
  ULONG BatteryTag;
  BATTERY_SET_INFORMATION_LEVEL InformationLevel;
  UCHAR Buffer[1];
} BATTERY_SET_INFORMATION, *PBATTERY_SET_INFORMATION;

typedef struct _BATTERY_WAIT_STATUS {
  ULONG BatteryTag;
  ULONG Timeout;
  ULONG PowerState;
  ULONG LowCapacity;
  ULONG HighCapacity;
} BATTERY_WAIT_STATUS, *PBATTERY_WAIT_STATUS;

typedef struct _BATTERY_STATUS {
  ULONG PowerState;
  ULONG Capacity;
  ULONG Voltage;
  LONG Rate;
} BATTERY_STATUS, *PBATTERY_STATUS;

typedef struct _BATTERY_MANUFACTURE_DATE {
  UCHAR Day;
  UCHAR Month;
  USHORT Year;
} BATTERY_MANUFACTURE_DATE, *PBATTERY_MANUFACTURE_DATE;

typedef struct _THERMAL_INFORMATION {
  ULONG ThermalStamp;
  ULONG ThermalConstant1;
  ULONG ThermalConstant2;
  KAFFINITY Processors;
  ULONG SamplingPeriod;
  ULONG CurrentTemperature;
  ULONG PassiveTripPoint;
  ULONG CriticalTripPoint;
  UCHAR ActiveTripPointCount;
  ULONG ActiveTripPoint[MAX_ACTIVE_COOLING_LEVELS];
} THERMAL_INFORMATION, *PTHERMAL_INFORMATION;

typedef struct _THERMAL_WAIT_READ {
  ULONG Timeout;
  ULONG LowTemperature;
  ULONG HighTemperature;
} THERMAL_WAIT_READ, *PTHERMAL_WAIT_READ;

typedef struct {
  ULONG PhysicalID;
  ULONG PBlkAddress;
  UCHAR PBlkLength;
} PROCESSOR_OBJECT_INFO, *PPROCESSOR_OBJECT_INFO;

typedef struct {
  ULONG PhysicalID;
  ULONG PBlkAddress;
  UCHAR PBlkLength;
  ULONG InitialApicId;
} PROCESSOR_OBJECT_INFO_EX, *PPROCESSOR_OBJECT_INFO_EX;

#ifndef _WINDOWS_

#include "pshpack1.h"

typedef struct _PCC_HEADER {
  ULONG Signature;
  USHORT HeaderLength;
  UCHAR MajorVersion;
  UCHAR MinorVersion;
  union {
    __MINGW_EXTENSION struct {
                   ULONG SciDoorbell : 1;
                   ULONG Reserved : 31;
    };
    ULONG AsULong;
  } SupportedFeatures;
  union {
    __MINGW_EXTENSION struct {
                   USHORT CommandCode : 8;
                   USHORT ReservedZ : 7;
                   USHORT SciDoorbell : 1;
    };
    USHORT AsUShort;
  } Command;
  union {
    __MINGW_EXTENSION struct {
                   USHORT CommandComplete : 1;
                   USHORT SciReceived : 1;
                   USHORT Error : 1;
                   USHORT Reserved : 13;
    };
    USHORT AsUShort;
  } Status;
  ULONG Latency;
  ULONG MinimumCommandInterval;
  ULONG MaximumCommandInterval;
  ULONG NominalFrequency;
  ULONG MinimumFrequency;
  ULONG MinimumUnthrottledFrequency;
} PCC_HEADER, *PPCC_HEADER;

typedef struct _PCC_INPUT_BUFFER {
  UCHAR ControlEnabled;
  __MINGW_EXTENSION union {
    struct {
                   UCHAR ReservedZ[3];
    } GetAverageFrequency;
    struct {
                   UCHAR DesiredFrequency;
                   UCHAR ReservedZ[2];
    } SetDesiredFrequency;
  };
} PCC_INPUT_BUFFER, *PPCC_INPUT_BUFFER;

typedef union _PCC_OUTPUT_BUFFER {
  struct {
    UCHAR AverageFrequency;
    UCHAR FrequencyLimit;
    UCHAR Reserved[2];
  } GetAverageFrequency;
  struct {
    UCHAR Reserved[4];
  } SetDesiredFrequency;
} PCC_OUTPUT_BUFFER, *PPCC_OUTPUT_BUFFER;

#include "poppack.h"

typedef VOID (*PPROCESSOR_PCC_DOORBELL_CALLBACK)(ULONG Status, ULONG_PTR Context);
typedef NTSTATUS (*PPROCESSOR_PCC_RING_DOORBELL)(UCHAR Command, PPROCESSOR_PCC_DOORBELL_CALLBACK Callback, ULONG_PTR Context);

typedef struct _PROCESSOR_PCC_INTERFACE_STANDARD {
  USHORT Size;
  USHORT Version;
  PVOID Context;
  PINTERFACE_REFERENCE InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PPROCESSOR_PCC_RING_DOORBELL PccRingDoorbell;
  PPCC_HEADER PccHeader;
  ULONG PccHeaderLength;
} PROCESSOR_PCC_INTERFACE_STANDARD, *PPROCESSOR_PCC_INTERFACE_STANDARD;

typedef VOID (*PDEVICE_ACTIVE_COOLING)(PVOID Context, BOOLEAN Engaged);
typedef VOID (*PDEVICE_PASSIVE_COOLING)(PVOID Context, ULONG Percentage);

typedef struct _THERMAL_COOLING_INTERFACE {
  USHORT Size;
  USHORT Version;
  PVOID Context;
  PINTERFACE_REFERENCE InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  ULONG Flags;
  PDEVICE_ACTIVE_COOLING ActiveCooling;
  PDEVICE_PASSIVE_COOLING PassiveCooling;
} THERMAL_COOLING_INTERFACE, *PTHERMAL_COOLING_INTERFACE;

typedef THERMAL_COOLING_INTERFACE THERMAL_DEVICE_INTERFACE;
typedef THERMAL_COOLING_INTERFACE *PTHERMAL_DEVICE_INTERFACE;

typedef enum _THERMAL_DEVICE_INTERFACE_FLAGS {
  ThermalDeviceFlagActiveCooling = 1,
  ThermalDeviceFlagPassiveCooling = 2
} THERMAL_DEVICE_INTERFACE_FLAGS, *PTHERMAL_DEVICE_INTERFACE_FLAGS;

#endif // _WINDOWS_

typedef struct _WAKE_ALARM_INFORMATION {
  ULONG TimerIdentifier;
  ULONG Timeout;
} WAKE_ALARM_INFORMATION, *PWAKE_ALARM_INFORMATION;

typedef struct _ACPI_REAL_TIME {
  UINT16 Year;
  UINT8 Month;
  UINT8 Day;
  UINT8 Hour;
  UINT8 Minute;
  UINT8 Second;
  UINT8 Valid;
  UINT16 Milliseconds;
  INT16 TimeZone;
  UINT8 DayLight;
  UINT8 Reserved1[3];
} ACPI_REAL_TIME, *PACPI_REAL_TIME;

#endif /* WINAPI_PARTITION_DESKTOP.  */

#endif

