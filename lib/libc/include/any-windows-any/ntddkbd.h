/*
 * ntddkbd.h
 *
 * Keyboard IOCTL interface
 *
 * This file is part of the w32api package.
 *
 * Contributors:
 *   Created by Casper S. Hornstrup <chorns@users.sourceforge.net>
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define DD_KEYBOARD_DEVICE_NAME                        "\\Device\\KeyboardClass"
#define DD_KEYBOARD_DEVICE_NAME_U                      L"\\Device\\KeyboardClass"

#define IOCTL_KEYBOARD_QUERY_ATTRIBUTES \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0000, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_QUERY_INDICATORS \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0010, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0020, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_QUERY_TYPEMATIC \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0008, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_SET_TYPEMATIC \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0001, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_SET_INDICATORS \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0002, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_INSERT_DATA \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0040, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_QUERY_IME_STATUS \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0400, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_SET_IME_STATUS \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0401, METHOD_BUFFERED, FILE_ANY_ACCESS)

DEFINE_GUID(GUID_DEVINTERFACE_KEYBOARD, \
  0x884b96c3, 0x56ef, 0x11d1, 0xbc, 0x8c, 0x00, 0xa0, 0xc9, 0x14, 0x05, 0xdd);

#define GUID_CLASS_KEYBOARD GUID_DEVINTERFACE_KEYBOARD /* Obsolete */

#define KEYBOARD_ERROR_VALUE_BASE                      10000

/* KEYBOARD_INPUT_DATA.MakeCode constants */
#define KEYBOARD_OVERRUN_MAKE_CODE     0xFF

/* KEYBOARD_INPUT_DATA.Flags constants */
#define KEY_MAKE                                                              0
#define KEY_BREAK                                                             1
#define KEY_E0                                                                             2
#define KEY_E1                                                                             4
#define KEY_TERMSRV_SET_LED                                      8
#define KEY_TERMSRV_SHADOW                                       0x10
#define KEY_TERMSRV_VKPACKET                        0x20

#define KEYBOARD_LED_INJECTED     0x8000
#define KEYBOARD_SHADOW                        0x4000
#define KEYBOARD_KANA_LOCK_ON     8
#define KEYBOARD_CAPS_LOCK_ON     4
#define KEYBOARD_NUM_LOCK_ON                   2
#define KEYBOARD_SCROLL_LOCK_ON   1

typedef struct _KEYBOARD_INPUT_DATA {
  USHORT UnitId;
  USHORT MakeCode;
  USHORT Flags;
  USHORT Reserved;
  ULONG ExtraInformation;
} KEYBOARD_INPUT_DATA, *PKEYBOARD_INPUT_DATA;


typedef struct _KEYBOARD_TYPEMATIC_PARAMETERS {
  USHORT UnitId;
  USHORT Rate;
  USHORT Delay;
} KEYBOARD_TYPEMATIC_PARAMETERS, *PKEYBOARD_TYPEMATIC_PARAMETERS;

typedef struct _KEYBOARD_ID {
  UCHAR Type;
  UCHAR Subtype;
} KEYBOARD_ID, *PKEYBOARD_ID;

#define ENHANCED_KEYBOARD(Id) ((Id).Type == 2 || (Id).Type == 4 || FAREAST_KEYBOARD(Id))
#define FAREAST_KEYBOARD(Id) ((Id).Type == 7 || (Id).Type == 8)

typedef struct _KEYBOARD_INDICATOR_PARAMETERS {
  USHORT UnitId;
  USHORT LedFlags;
} KEYBOARD_INDICATOR_PARAMETERS, *PKEYBOARD_INDICATOR_PARAMETERS;

typedef struct _INDICATOR_LIST {
  USHORT MakeCode;
  USHORT IndicatorFlags;
} INDICATOR_LIST, *PINDICATOR_LIST;

typedef struct _KEYBOARD_INDICATOR_TRANSLATION {
  USHORT NumberOfIndicatorKeys;
  INDICATOR_LIST IndicatorList[1];
} KEYBOARD_INDICATOR_TRANSLATION, *PKEYBOARD_INDICATOR_TRANSLATION;

typedef struct _KEYBOARD_ATTRIBUTES {
  KEYBOARD_ID KeyboardIdentifier;
  USHORT KeyboardMode;
  USHORT NumberOfFunctionKeys;
  USHORT NumberOfIndicators;
  USHORT NumberOfKeysTotal;
  ULONG InputDataQueueLength;
  KEYBOARD_TYPEMATIC_PARAMETERS KeyRepeatMinimum;
  KEYBOARD_TYPEMATIC_PARAMETERS KeyRepeatMaximum;
} KEYBOARD_ATTRIBUTES, *PKEYBOARD_ATTRIBUTES;

typedef struct _KEYBOARD_UNIT_ID_PARAMETER {
  USHORT UnitId;
} KEYBOARD_UNIT_ID_PARAMETER, *PKEYBOARD_UNIT_ID_PARAMETER;

typedef struct _KEYBOARD_IME_STATUS {
  USHORT UnitId;
  ULONG ImeOpen;
  ULONG ImeConvMode;
} KEYBOARD_IME_STATUS, *PKEYBOARD_IME_STATUS;

#ifdef __cplusplus
}
#endif
