/* DirectMusic Error Codes
 *
 * Copyright (C) 2003-2004 Rok Mandeljc
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_DMUSIC_ERROR_H
#define __WINE_DMUSIC_ERROR_H

/*****************************************************************************
 * Error code handling
 */
#define FACILITY_DIRECTMUSIC 0x878
#define DMUS_ERRBASE 0x1000

#ifndef MAKE_HRESULT
#define MAKE_HRESULT(sev,fac,code) \
    ((HRESULT) (((ULONG)(sev)<<31) | ((ULONG)(fac)<<16) | ((ULONG)(code))) )
#endif

#define MAKE_DMHRESULTSUCCESS(code)  MAKE_HRESULT(0, FACILITY_DIRECTMUSIC, (DMUS_ERRBASE + (code)))
#define MAKE_DMHRESULTERROR(code)    MAKE_HRESULT(1, FACILITY_DIRECTMUSIC, (DMUS_ERRBASE + (code)))

/*****************************************************************************
 * Error codes
 */

#define DMUS_S_PARTIALLOAD                                                           MAKE_DMHRESULTSUCCESS(0x091)
#define DMUS_S_PARTIALDOWNLOAD                                          MAKE_DMHRESULTSUCCESS(0x092)
#define DMUS_S_REQUEUE                                                                            MAKE_DMHRESULTSUCCESS(0x200)
#define DMUS_S_FREE                                                                               MAKE_DMHRESULTSUCCESS(0x201)
#define DMUS_S_END                                                                                MAKE_DMHRESULTSUCCESS(0x202)
#define DMUS_S_STRING_TRUNCATED                                         MAKE_DMHRESULTSUCCESS(0x210)
#define DMUS_S_LAST_TOOL                                                             MAKE_DMHRESULTSUCCESS(0x211)
#define DMUS_S_OVER_CHORD                                                            MAKE_DMHRESULTSUCCESS(0x212)
#define DMUS_S_UP_OCTAVE                                                             MAKE_DMHRESULTSUCCESS(0x213)
#define DMUS_S_DOWN_OCTAVE                                                           MAKE_DMHRESULTSUCCESS(0x214)
#define DMUS_S_NOBUFFERCONTROL                                          MAKE_DMHRESULTSUCCESS(0x215)
#define DMUS_S_GARBAGE_COLLECTED                                        MAKE_DMHRESULTSUCCESS(0x216)

#define DMUS_E_DRIVER_FAILED                                                         MAKE_DMHRESULTERROR(0x0101)
#define DMUS_E_PORTS_OPEN                                                            MAKE_DMHRESULTERROR(0x0102)
#define DMUS_E_DEVICE_IN_USE                                                         MAKE_DMHRESULTERROR(0x0103)
#define DMUS_E_INSUFFICIENTBUFFER                                       MAKE_DMHRESULTERROR(0x0104)
#define DMUS_E_BUFFERNOTSET                                                          MAKE_DMHRESULTERROR(0x0105)
#define DMUS_E_BUFFERNOTAVAILABLE                                       MAKE_DMHRESULTERROR(0x0106)
#define DMUS_E_NOTADLSCOL                                                            MAKE_DMHRESULTERROR(0x0108)
#define DMUS_E_INVALIDOFFSET                                                         MAKE_DMHRESULTERROR(0x0109)
#define DMUS_E_ALREADY_LOADED                                           MAKE_DMHRESULTERROR(0x0111)
#define DMUS_E_INVALIDPOS                                                            MAKE_DMHRESULTERROR(0x0113)
#define DMUS_E_INVALIDPATCH                                                          MAKE_DMHRESULTERROR(0x0114)
#define DMUS_E_CANNOTSEEK                                                            MAKE_DMHRESULTERROR(0x0115)
#define DMUS_E_CANNOTWRITE                                                           MAKE_DMHRESULTERROR(0x0116)
#define DMUS_E_CHUNKNOTFOUND                                                         MAKE_DMHRESULTERROR(0x0117)
#define DMUS_E_INVALID_DOWNLOADID                                       MAKE_DMHRESULTERROR(0x0119)
#define DMUS_E_NOT_DOWNLOADED_TO_PORT                      MAKE_DMHRESULTERROR(0x0120)
#define DMUS_E_ALREADY_DOWNLOADED                                       MAKE_DMHRESULTERROR(0x0121)
#define DMUS_E_UNKNOWN_PROPERTY                                         MAKE_DMHRESULTERROR(0x0122)
#define DMUS_E_SET_UNSUPPORTED                                          MAKE_DMHRESULTERROR(0x0123)
#define DMUS_E_GET_UNSUPPORTED                                          MAKE_DMHRESULTERROR(0x0124)
#define DMUS_E_NOTMONO                                                                            MAKE_DMHRESULTERROR(0x0125)
#define DMUS_E_BADARTICULATION                                          MAKE_DMHRESULTERROR(0x0126)
#define DMUS_E_BADINSTRUMENT                                                         MAKE_DMHRESULTERROR(0x0127)
#define DMUS_E_BADWAVELINK                                                           MAKE_DMHRESULTERROR(0x0128)
#define DMUS_E_NOARTICULATION                                           MAKE_DMHRESULTERROR(0x0129)
#define DMUS_E_NOTPCM                                                                             MAKE_DMHRESULTERROR(0x012A)
#define DMUS_E_BADWAVE                                                                            MAKE_DMHRESULTERROR(0x012B)
#define DMUS_E_BADOFFSETTABLE                                           MAKE_DMHRESULTERROR(0x012C)
#define DMUS_E_UNKNOWNDOWNLOAD                                          MAKE_DMHRESULTERROR(0x012D)
#define DMUS_E_NOSYNTHSINK                                                           MAKE_DMHRESULTERROR(0x012E)
#define DMUS_E_ALREADYOPEN                                                           MAKE_DMHRESULTERROR(0x012F)
#define DMUS_E_ALREADYCLOSED                                                         MAKE_DMHRESULTERROR(0x0130)
#define DMUS_E_SYNTHNOTCONFIGURED                                       MAKE_DMHRESULTERROR(0x0131)
#define DMUS_E_SYNTHACTIVE                                                           MAKE_DMHRESULTERROR(0x0132)
#define DMUS_E_CANNOTREAD                                                            MAKE_DMHRESULTERROR(0x0133)
#define DMUS_E_DMUSIC_RELEASED                                          MAKE_DMHRESULTERROR(0x0134)
#define DMUS_E_BUFFER_EMPTY                                                          MAKE_DMHRESULTERROR(0x0135)
#define DMUS_E_BUFFER_FULL                                                           MAKE_DMHRESULTERROR(0x0136)
#define DMUS_E_PORT_NOT_CAPTURE                                         MAKE_DMHRESULTERROR(0x0137)
#define DMUS_E_PORT_NOT_RENDER                                          MAKE_DMHRESULTERROR(0x0138)
#define DMUS_E_DSOUND_NOT_SET                                           MAKE_DMHRESULTERROR(0x0139)
#define DMUS_E_ALREADY_ACTIVATED                                        MAKE_DMHRESULTERROR(0x013A)
#define DMUS_E_INVALIDBUFFER                                                         MAKE_DMHRESULTERROR(0x013B)
#define DMUS_E_WAVEFORMATNOTSUPPORTED                      MAKE_DMHRESULTERROR(0x013C)
#define DMUS_E_SYNTHINACTIVE                                                         MAKE_DMHRESULTERROR(0x013D)
#define DMUS_E_DSOUND_ALREADY_SET                                       MAKE_DMHRESULTERROR(0x013E)
#define DMUS_E_INVALID_EVENT                                                         MAKE_DMHRESULTERROR(0x013F)
#define DMUS_E_UNSUPPORTED_STREAM                                       MAKE_DMHRESULTERROR(0x0150)
#define DMUS_E_ALREADY_INITED                                           MAKE_DMHRESULTERROR(0x0151)
#define DMUS_E_INVALID_BAND                                                          MAKE_DMHRESULTERROR(0x0152)
#define DMUS_E_TRACK_HDR_NOT_FIRST_CK                      MAKE_DMHRESULTERROR(0x0155)
#define DMUS_E_TOOL_HDR_NOT_FIRST_CK                       MAKE_DMHRESULTERROR(0x0156)
#define DMUS_E_INVALID_TRACK_HDR                                        MAKE_DMHRESULTERROR(0x0157)
#define DMUS_E_INVALID_TOOL_HDR                                         MAKE_DMHRESULTERROR(0x0158)
#define DMUS_E_ALL_TOOLS_FAILED                                         MAKE_DMHRESULTERROR(0x0159)
#define DMUS_E_ALL_TRACKS_FAILED                                        MAKE_DMHRESULTERROR(0x0160)
#define DMUS_E_NOT_FOUND                                                             MAKE_DMHRESULTERROR(0x0161)
#define DMUS_E_NOT_INIT                                                              MAKE_DMHRESULTERROR(0x0162)
#define DMUS_E_TYPE_DISABLED                                                         MAKE_DMHRESULTERROR(0x0163)
#define DMUS_E_TYPE_UNSUPPORTED                                         MAKE_DMHRESULTERROR(0x0164)
#define DMUS_E_TIME_PAST                                                             MAKE_DMHRESULTERROR(0x0165)
#define DMUS_E_TRACK_NOT_FOUND                                          MAKE_DMHRESULTERROR(0x0166)
#define DMUS_E_TRACK_NO_CLOCKTIME_SUPPORT     MAKE_DMHRESULTERROR(0x0167)
#define DMUS_E_NO_MASTER_CLOCK                                          MAKE_DMHRESULTERROR(0x0170)
#define DMUS_E_LOADER_NOCLASSID                                         MAKE_DMHRESULTERROR(0x0180)
#define DMUS_E_LOADER_BADPATH                                           MAKE_DMHRESULTERROR(0x0181)
#define DMUS_E_LOADER_FAILEDOPEN                                        MAKE_DMHRESULTERROR(0x0182)
#define DMUS_E_LOADER_FORMATNOTSUPPORTED                   MAKE_DMHRESULTERROR(0x0183)
#define DMUS_E_LOADER_FAILEDCREATE                                      MAKE_DMHRESULTERROR(0x0184)
#define DMUS_E_LOADER_OBJECTNOTFOUND                       MAKE_DMHRESULTERROR(0x0185)
#define DMUS_E_LOADER_NOFILENAME                                        MAKE_DMHRESULTERROR(0x0186)
#define DMUS_E_INVALIDFILE                                                           MAKE_DMHRESULTERROR(0x0200)
#define DMUS_E_ALREADY_EXISTS                                           MAKE_DMHRESULTERROR(0x0201)
#define DMUS_E_OUT_OF_RANGE                                                          MAKE_DMHRESULTERROR(0x0202)
#define DMUS_E_SEGMENT_INIT_FAILED                                      MAKE_DMHRESULTERROR(0x0203)
#define DMUS_E_ALREADY_SENT                                                          MAKE_DMHRESULTERROR(0x0204)
#define DMUS_E_CANNOT_FREE                                                           MAKE_DMHRESULTERROR(0x0205)
#define DMUS_E_CANNOT_OPEN_PORT                                         MAKE_DMHRESULTERROR(0x0206)
#define DMUS_E_CANNOT_CONVERT                                           MAKE_DMHRESULTERROR(0x0207)
#define DMUS_E_DESCEND_CHUNK_FAIL                                       MAKE_DMHRESULTERROR(0x0210)
#define DMUS_E_NOT_LOADED                                                            MAKE_DMHRESULTERROR(0x0211)
#define DMUS_E_SCRIPT_LANGUAGE_INCOMPATIBLE   MAKE_DMHRESULTERROR(0x0213)
#define DMUS_E_SCRIPT_UNSUPPORTED_VARTYPE     MAKE_DMHRESULTERROR(0x0214)
#define DMUS_E_SCRIPT_ERROR_IN_SCRIPT                      MAKE_DMHRESULTERROR(0x0215)
#define DMUS_E_SCRIPT_CANTLOAD_OLEAUT32                    MAKE_DMHRESULTERROR(0x0216)
#define DMUS_E_SCRIPT_LOADSCRIPT_ERROR                     MAKE_DMHRESULTERROR(0x0217)
#define DMUS_E_SCRIPT_INVALID_FILE                                      MAKE_DMHRESULTERROR(0x0218)
#define DMUS_E_INVALID_SCRIPTTRACK                                      MAKE_DMHRESULTERROR(0x0219)
#define DMUS_E_SCRIPT_VARIABLE_NOT_FOUND                   MAKE_DMHRESULTERROR(0x021A)
#define DMUS_E_SCRIPT_ROUTINE_NOT_FOUND                    MAKE_DMHRESULTERROR(0x021B)
#define DMUS_E_SCRIPT_CONTENT_READONLY                     MAKE_DMHRESULTERROR(0x021C)
#define DMUS_E_SCRIPT_NOT_A_REFERENCE                      MAKE_DMHRESULTERROR(0x021D)
#define DMUS_E_SCRIPT_VALUE_NOT_SUPPORTED     MAKE_DMHRESULTERROR(0x021E)
#define DMUS_E_INVALID_SEGMENTTRIGGERTRACK    MAKE_DMHRESULTERROR(0x0220)
#define DMUS_E_INVALID_LYRICSTRACK                                      MAKE_DMHRESULTERROR(0x0221)
#define DMUS_E_INVALID_PARAMCONTROLTRACK                   MAKE_DMHRESULTERROR(0x0222)
#define DMUS_E_AUDIOVBSCRIPT_SYNTAXERROR                   MAKE_DMHRESULTERROR(0x0223)
#define DMUS_E_AUDIOVBSCRIPT_RUNTIMEERROR     MAKE_DMHRESULTERROR(0x0224)
#define DMUS_E_AUDIOVBSCRIPT_OPERATIONFAILURE MAKE_DMHRESULTERROR(0x0225)
#define DMUS_E_AUDIOPATHS_NOT_VALID                        MAKE_DMHRESULTERROR(0x0226)
#define DMUS_E_AUDIOPATHS_IN_USE                                        MAKE_DMHRESULTERROR(0x0227)
#define DMUS_E_NO_AUDIOPATH_CONFIG                                      MAKE_DMHRESULTERROR(0x0228)
#define DMUS_E_AUDIOPATH_INACTIVE                                       MAKE_DMHRESULTERROR(0x0229)
#define DMUS_E_AUDIOPATH_NOBUFFER                                       MAKE_DMHRESULTERROR(0x022A)
#define DMUS_E_AUDIOPATH_NOPORT                                         MAKE_DMHRESULTERROR(0x022B)
#define DMUS_E_NO_AUDIOPATH                                                          MAKE_DMHRESULTERROR(0x022C)
#define DMUS_E_INVALIDCHUNK                                                          MAKE_DMHRESULTERROR(0x022D)
#define DMUS_E_AUDIOPATH_NOGLOBALFXBUFFER     MAKE_DMHRESULTERROR(0x022E)
#define DMUS_E_INVALID_CONTAINER_OBJECT                    MAKE_DMHRESULTERROR(0x022F)

#endif /* __WINE_DMUSIC_ERROR_H */
