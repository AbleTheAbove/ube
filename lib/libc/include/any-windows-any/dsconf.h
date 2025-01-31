/*
 * Copyright (C) 2003 Robert Reif
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_DSCONF_H
#define __WINE_DSCONF_H

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/*****************************************************************************
 * Predeclare the interfaces
 */
DEFINE_GUID(CLSID_DirectSoundPrivate,                        0x11ab3ec0,0x25ec,0x11d1,0xa4,0xd8,0x00,0xc0,0x4f,0xc2,0x8a,0xca);

DEFINE_GUID(DSPROPSETID_DirectSoundDevice,                   0x84624f82,0x25ec,0x11d1,0xa4,0xd8,0x00,0xc0,0x4f,0xc2,0x8a,0xca);

typedef enum
{
                     DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A = 1,
                     DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1                    = 2,
                     DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1                      = 3,
                     DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W = 4,
                     DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A                    = 5,
                     DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W                    = 6,
                     DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A                      = 7,
                     DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W                      = 8,
} DSPROPERTY_DIRECTSOUNDDEVICE;

#ifdef UNICODE
#define DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING  DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W
#define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION                     DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W
#define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE                       DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W
#else
#define DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING  DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A
#define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION                     DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A
#define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE                       DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A
#endif

typedef enum
{
                     DIRECTSOUNDDEVICE_TYPE_EMULATED,
                     DIRECTSOUNDDEVICE_TYPE_VXD,
                     DIRECTSOUNDDEVICE_TYPE_WDM
} DIRECTSOUNDDEVICE_TYPE;

typedef enum
{
                     DIRECTSOUNDDEVICE_DATAFLOW_RENDER,
                     DIRECTSOUNDDEVICE_DATAFLOW_CAPTURE
} DIRECTSOUNDDEVICE_DATAFLOW;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA
{
                     LPSTR                                                                               DeviceName;
                     DIRECTSOUNDDEVICE_DATAFLOW                   DataFlow;
                     GUID                                                                                DeviceId;
} DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA
{
                     LPWSTR                                                                              DeviceName;
                     DIRECTSOUNDDEVICE_DATAFLOW                   DataFlow;
                     GUID                                                                                DeviceId;
} DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA;

#ifdef UNICODE
#define DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_DATA     DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA
#define PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_DATA    PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA
#else
#define DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_DATA     DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA
#define PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_DATA    PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA
#endif

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA
{
                     GUID                                                                                DeviceId;
                     CHAR                                                                                DescriptionA[0x100];
                     WCHAR                                                                               DescriptionW[0x100];
                     CHAR                                                                                ModuleA[MAX_PATH];
                     WCHAR                                                                               ModuleW[MAX_PATH];
                     DIRECTSOUNDDEVICE_TYPE                       Type;
                     DIRECTSOUNDDEVICE_DATAFLOW                   DataFlow;
                     ULONG                                                                               WaveDeviceId;
                     ULONG                                                                               Devnode;
} DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA
{
                     DIRECTSOUNDDEVICE_TYPE                       Type;
                     DIRECTSOUNDDEVICE_DATAFLOW                   DataFlow;
                     GUID                                                                                DeviceId;
                     LPSTR                                                                               Description;
                     LPSTR                                                                               Module;
                     LPSTR                                                                               Interface;
                     ULONG                                                                               WaveDeviceId;
} DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA
{
                     DIRECTSOUNDDEVICE_TYPE                       Type;
                     DIRECTSOUNDDEVICE_DATAFLOW                   DataFlow;
                     GUID                                                                                DeviceId;
                     LPWSTR                                                                              Description;
                     LPWSTR                                                                              Module;
                     LPWSTR                                                                              Interface;
                     ULONG                                                                               WaveDeviceId;
} DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA;

#ifdef UNICODE
#define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA   DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA
#define PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA  PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA
#else
#define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA   DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA
#define PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA  PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA
#endif

typedef WINBOOL (CALLBACK *LPFNDIRECTSOUNDDEVICEENUMERATECALLBACK1)(PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA, LPVOID);
typedef WINBOOL (CALLBACK *LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKA)(PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA, LPVOID);
typedef WINBOOL (CALLBACK *LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKW)(PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA, LPVOID);

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1_DATA
{
                     LPFNDIRECTSOUNDDEVICEENUMERATECALLBACK1 Callback;
                     LPVOID                                                                                                   Context;
} DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA
{
                     LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKA Callback;
                     LPVOID                                                                                                   Context;
} DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA
{
                     LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKW Callback;
                     LPVOID                                                                                                   Context;
} DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA;

#ifdef UNICODE
#define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA     DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA
#define PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA    PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA
#else
#define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA     DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA
#define PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA    PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif /* __WINE_DSCONF_H */
