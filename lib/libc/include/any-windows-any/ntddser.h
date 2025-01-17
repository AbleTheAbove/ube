/*
 * ntddser.h
 *
 * Serial port driver interface
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

#ifndef _NTDDSER_
#define _NTDDSER_

#ifdef __cplusplus
extern "C" {
#endif

/* GUIDs */

DEFINE_GUID(GUID_DEVINTERFACE_COMPORT,
  0x86e0d1e0, 0x8089, 0x11d0, 0x9c, 0xe4, 0x08, 0x00, 0x3e, 0x30, 0x1f, 0x73);

#define GUID_CLASS_COMPORT GUID_DEVINTERFACE_COMPORT

DEFINE_GUID(GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR,
  0x4D36E978, 0xE325, 0x11CE, 0xBF, 0xC1, 0x08, 0x00, 0x2B, 0xE1, 0x03, 0x18);

#define GUID_SERENUM_BUS_ENUMERATOR GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR

#define IOCTL_SERIAL_CLEAR_STATS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 36, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_CLR_DTR \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_CLR_RTS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 13, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_CONFIG_SIZE \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 32, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_BAUD_RATE \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 20, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_CHARS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 22, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_COMMSTATUS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 27, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_DTRRTS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 30, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_HANDFLOW \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 24, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_LINE_CONTROL \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 21, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_MODEM_CONTROL \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 37, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_MODEMSTATUS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 26, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_PROPERTIES \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 29, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_STATS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 35, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_TIMEOUTS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 8, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_GET_WAIT_MASK \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 16, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_IMMEDIATE_CHAR \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_LSRMST_INSERT \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 31, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_PURGE \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 19, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_RESET_DEVICE \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 11, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_BAUD_RATE \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_BREAK_ON \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_BREAK_OFF \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_CHARS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 23, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_DTR \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 9, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_FIFO_CONTROL \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 39, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_HANDFLOW \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 25, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_LINE_CONTROL \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_MODEM_CONTROL \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 38, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_QUEUE_SIZE \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_RTS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_TIMEOUTS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_WAIT_MASK \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 17, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_XOFF \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 14, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_SET_XON \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_WAIT_ON_MASK \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 18, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_XOFF_COUNTER \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 28, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_SERIAL_INTERNAL_BASIC_SETTINGS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_INTERNAL_CANCEL_WAIT_WAKE \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_INTERNAL_DO_WAIT_WAKE \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERIAL_INTERNAL_RESTORE_SETTINGS \
  CTL_CODE (FILE_DEVICE_SERIAL_PORT, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_SERENUM_PORT_DESC \
  CTL_CODE (FILE_DEVICE_SERENUM, 130, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERENUM_GET_PORT_NAME \
  CTL_CODE (FILE_DEVICE_SERENUM, 131, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_INTERNAL_SERENUM_REMOVE_SELF \
  CTL_CODE (FILE_DEVICE_SERENUM, 129, METHOD_NEITHER, FILE_ANY_ACCESS)


typedef struct _SERIAL_BAUD_RATE {
  ULONG  BaudRate;
} SERIAL_BAUD_RATE, *PSERIAL_BAUD_RATE;

/* SERIAL_BAUD_RATE.BaudRate constants */
#define SERIAL_BAUD_075                                                          0x00000001
#define SERIAL_BAUD_110                                                          0x00000002
#define SERIAL_BAUD_134_5                                           0x00000004
#define SERIAL_BAUD_150                                                          0x00000008
#define SERIAL_BAUD_300                                                          0x00000010
#define SERIAL_BAUD_600                                                          0x00000020
#define SERIAL_BAUD_1200                                                         0x00000040
#define SERIAL_BAUD_1800                                                         0x00000080
#define SERIAL_BAUD_2400                                                         0x00000100
#define SERIAL_BAUD_4800                                                         0x00000200
#define SERIAL_BAUD_7200                                                         0x00000400
#define SERIAL_BAUD_9600                                                         0x00000800
#define SERIAL_BAUD_14400                                           0x00001000
#define SERIAL_BAUD_19200                                           0x00002000
#define SERIAL_BAUD_38400                                           0x00004000
#define SERIAL_BAUD_56K                                                          0x00008000
#define SERIAL_BAUD_128K                                                         0x00010000
#define SERIAL_BAUD_115200                                          0x00020000
#define SERIAL_BAUD_57600                                           0x00040000
#define SERIAL_BAUD_USER                                                         0x10000000

typedef struct _SERIAL_CHARS {
  UCHAR  EofChar;
  UCHAR  ErrorChar;
  UCHAR  BreakChar;
  UCHAR  EventChar;
  UCHAR  XonChar;
  UCHAR  XoffChar;
} SERIAL_CHARS, *PSERIAL_CHARS;

typedef struct _SERIAL_STATUS {
  ULONG  Errors;
  ULONG  HoldReasons;
  ULONG  AmountInInQueue;
  ULONG  AmountInOutQueue;
  BOOLEAN  EofReceived;
  BOOLEAN  WaitForImmediate;
} SERIAL_STATUS, *PSERIAL_STATUS;

typedef struct _SERIAL_HANDFLOW {
	ULONG  ControlHandShake;
	ULONG  FlowReplace;
	LONG  XonLimit;
	LONG  XoffLimit;
} SERIAL_HANDFLOW, *PSERIAL_HANDFLOW;

#define SERIAL_DTR_MASK                                                          0x00000003
#define SERIAL_DTR_CONTROL                                          0x00000001
#define SERIAL_DTR_HANDSHAKE                                        0x00000002
#define SERIAL_CTS_HANDSHAKE                                        0x00000008
#define SERIAL_DSR_HANDSHAKE                                        0x00000010
#define SERIAL_DCD_HANDSHAKE                                        0x00000020
#define SERIAL_OUT_HANDSHAKEMASK                       0x00000038
#define SERIAL_DSR_SENSITIVITY                                      0x00000040
#define SERIAL_ERROR_ABORT                                          0x80000000
#define SERIAL_CONTROL_INVALID                                      0x7fffff84
#define SERIAL_AUTO_TRANSMIT                                        0x00000001
#define SERIAL_AUTO_RECEIVE                                         0x00000002
#define SERIAL_ERROR_CHAR                                           0x00000004
#define SERIAL_NULL_STRIPPING                                       0x00000008
#define SERIAL_BREAK_CHAR                                           0x00000010
#define SERIAL_RTS_MASK                                                          0x000000c0
#define SERIAL_RTS_CONTROL                                          0x00000040
#define SERIAL_RTS_HANDSHAKE                                        0x00000080
#define SERIAL_TRANSMIT_TOGGLE                                      0x000000c0
#define SERIAL_XOFF_CONTINUE                                        0x80000000
#define SERIAL_FLOW_INVALID                                         0x7fffff20

typedef struct _SERIAL_LINE_CONTROL {
  UCHAR  StopBits;
  UCHAR  Parity;
  UCHAR  WordLength;
} SERIAL_LINE_CONTROL, *PSERIAL_LINE_CONTROL;

/* SERIAL_LINE_CONTROL.StopBits constants */
#define STOP_BIT_1                                                                            0x00
#define STOP_BITS_1_5                                                            0x01
#define STOP_BITS_2                                                              0x02

/* SERIAL_LINE_CONTROL.Parity constants */
#define NO_PARITY                                                                             0x00
#define ODD_PARITY                                                                            0x01
#define EVEN_PARITY                                                              0x02
#define MARK_PARITY                                                              0x03
#define SPACE_PARITY                                                             0x04

/* IOCTL_SERIAL_(GET_MODEM_CONTROL, SET_MODEM_CONTROL) flags */
#define SERIAL_IOC_MCR_DTR                                          0x00000001
#define SERIAL_IOC_MCR_RTS                                          0x00000002
#define SERIAL_IOC_MCR_OUT1                                         0x00000004
#define SERIAL_IOC_MCR_OUT2                                         0x00000008
#define SERIAL_IOC_MCR_LOOP                                         0x00000010

typedef struct _SERIAL_COMMPROP {
  USHORT  PacketLength;
  USHORT  PacketVersion;
  ULONG  ServiceMask;
  ULONG  Reserved1;
  ULONG  MaxTxQueue;
  ULONG  MaxRxQueue;
  ULONG  MaxBaud;
  ULONG  ProvSubType;
  ULONG  ProvCapabilities;
  ULONG  SettableParams;
  ULONG  SettableBaud;
  USHORT  SettableData;
  USHORT  SettableStopParity;
  ULONG  CurrentTxQueue;
  ULONG  CurrentRxQueue;
  ULONG  ProvSpec1;
  ULONG  ProvSpec2;
  WCHAR  ProvChar[1];
} SERIAL_COMMPROP, *PSERIAL_COMMPROP;

/* SERIAL_COMMPROP.SettableParams flags */
#define SERIAL_SP_PARITY                                                         0x0001
#define SERIAL_SP_BAUD                                                           0x0002
#define SERIAL_SP_DATABITS                                          0x0004
#define SERIAL_SP_STOPBITS                                          0x0008
#define SERIAL_SP_HANDSHAKING                                       0x0010
#define SERIAL_SP_PARITY_CHECK                                      0x0020
#define SERIAL_SP_CARRIER_DETECT                       0x0040

/* SERIAL_COMMPROP.ProvCapabilities flags */
#define SERIAL_PCF_DTRDSR                                           0x00000001
#define SERIAL_PCF_RTSCTS                                           0x00000002
#define SERIAL_PCF_CD                                                            0x00000004
#define SERIAL_PCF_PARITY_CHECK                        0x00000008
#define SERIAL_PCF_XONXOFF                                          0x00000010
#define SERIAL_PCF_SETXCHAR                                         0x00000020
#define SERIAL_PCF_TOTALTIMEOUTS                       0x00000040
#define SERIAL_PCF_INTTIMEOUTS                                      0x00000080
#define SERIAL_PCF_SPECIALCHARS                        0x00000100
#define SERIAL_PCF_16BITMODE                                        0x00000200

/* SERIAL_COMMPROP.SettableData flags */
#define SERIAL_DATABITS_5                                           0x0001
#define SERIAL_DATABITS_6                                           0x0002
#define SERIAL_DATABITS_7                                           0x0004
#define SERIAL_DATABITS_8                                           0x0008
#define SERIAL_DATABITS_16                                          0x0010
#define SERIAL_DATABITS_16X                                         0x0020

/* SERIAL_COMMPROP.SettableStopParity flags */
#define SERIAL_STOPBITS_10                                          0x0001
#define SERIAL_STOPBITS_15                                          0x0002
#define SERIAL_STOPBITS_20                                          0x0004
#define SERIAL_PARITY_NONE                                          0x0100
#define SERIAL_PARITY_ODD                                           0x0200
#define SERIAL_PARITY_EVEN                                          0x0400
#define SERIAL_PARITY_MARK                                          0x0800
#define SERIAL_PARITY_SPACE                                         0x1000

typedef struct _SERIALPERF_STATS {
  ULONG  ReceivedCount;
  ULONG  TransmittedCount;
  ULONG  FrameErrorCount;
  ULONG  SerialOverrunErrorCount;
  ULONG  BufferOverrunErrorCount;
  ULONG  ParityErrorCount;
} SERIALPERF_STATS, *PSERIALPERF_STATS;

typedef struct _SERIAL_TIMEOUTS {
  ULONG  ReadIntervalTimeout;
  ULONG  ReadTotalTimeoutMultiplier;
  ULONG  ReadTotalTimeoutConstant;
  ULONG  WriteTotalTimeoutMultiplier;
  ULONG  WriteTotalTimeoutConstant;
} SERIAL_TIMEOUTS, *PSERIAL_TIMEOUTS;

/* IOCTL_SERIAL_(GET_WAIT_MASK, SET_WAIT_MASK, WAIT_ON_MASK) flags */
#define SERIAL_EV_RXCHAR                                                         0x0001
#define SERIAL_EV_RXFLAG                                                         0x0002
#define SERIAL_EV_TXEMPTY                                           0x0004
#define SERIAL_EV_CTS                                                            0x0008
#define SERIAL_EV_DSR                                                            0x0010
#define SERIAL_EV_RLSD                                                           0x0020
#define SERIAL_EV_BREAK                                                          0x0040
#define SERIAL_EV_ERR                                                            0x0080
#define SERIAL_EV_RING                                                           0x0100
#define SERIAL_EV_PERR                                                           0x0200
#define SERIAL_EV_RX80FULL                                          0x0400
#define SERIAL_EV_EVENT1                                                         0x0800
#define SERIAL_EV_EVENT2                                                         0x1000

/* IOCTL_SERIAL_LSRMST_INSERT constants */
#define SERIAL_LSRMST_LSR_DATA                                      0x01
#define SERIAL_LSRMST_LSR_NODATA                       0x02
#define SERIAL_LSRMST_MST                                           0x03
#define SERIAL_LSRMST_ESCAPE                                        0x00

/* IOCTL_SERIAL_PURGE constants */
#define SERIAL_PURGE_TXABORT                                        0x00000001
#define SERIAL_PURGE_RXABORT                                        0x00000002
#define SERIAL_PURGE_TXCLEAR                                        0x00000004
#define SERIAL_PURGE_RXCLEAR                                        0x00000008

/* IOCTL_SERIAL_SET_FIFO_CONTROL constants */
#define SERIAL_IOC_FCR_FIFO_ENABLE                     0x00000001
#define SERIAL_IOC_FCR_RCVR_RESET                      0x00000002
#define SERIAL_IOC_FCR_XMIT_RESET                      0x00000004
#define SERIAL_IOC_FCR_DMA_MODE                        0x00000008
#define SERIAL_IOC_FCR_RES1                                         0x00000010
#define SERIAL_IOC_FCR_RES2                                         0x00000020
#define SERIAL_IOC_FCR_RCVR_TRIGGER_LSB   0x00000040
#define SERIAL_IOC_FCR_RCVR_TRIGGER_MSB   0x00000080

typedef struct _SERIAL_QUEUE_SIZE {
  ULONG  InSize;
  ULONG  OutSize;
} SERIAL_QUEUE_SIZE, *PSERIAL_QUEUE_SIZE;

typedef struct _SERIAL_XOFF_COUNTER {
	ULONG  Timeout;
	LONG  Counter;
	UCHAR  XoffChar;
} SERIAL_XOFF_COUNTER, *PSERIAL_XOFF_COUNTER;

typedef struct _SERIAL_BASIC_SETTINGS {
	SERIAL_TIMEOUTS  Timeouts;
	SERIAL_HANDFLOW  HandFlow;
	ULONG  RxFifo;
	ULONG  TxFifo;
} SERIAL_BASIC_SETTINGS, *PSERIAL_BASIC_SETTINGS;

typedef struct _SERENUM_PORT_DESC {
	ULONG  Size;
	PVOID  PortHandle;
	PHYSICAL_ADDRESS  PortAddress;
	USHORT  Reserved[1];
} SERENUM_PORT_DESC, *PSERENUM_PORT_DESC;

typedef UCHAR
(NTAPI*PSERENUM_READPORT)(
  PVOID  SerPortAddress);

typedef VOID
(NTAPI*PSERENUM_WRITEPORT)(
  PVOID  SerPortAddress,
  UCHAR  Value);

typedef enum _SERENUM_PORTION {
  SerenumFirstHalf,
  SerenumSecondHalf,
  SerenumWhole
} SERENUM_PORTION;

typedef struct _SERENUM_PORT_PARAMETERS {
  ULONG  Size;
  PSERENUM_READPORT  ReadAccessor;
  PSERENUM_WRITEPORT  WriteAccessor;
  PVOID  SerPortAddress;
  PVOID  HardwareHandle;
  SERENUM_PORTION  Portion;
  USHORT  NumberAxis;
  USHORT  Reserved[3];
} SERENUM_PORT_PARAMETERS, *PSERENUM_PORT_PARAMETERS;

#define SERIAL_ERROR_BREAK                                          0x00000001
#define SERIAL_ERROR_FRAMING                                        0x00000002
#define SERIAL_ERROR_OVERRUN                                        0x00000004
#define SERIAL_ERROR_QUEUEOVERRUN                      0x00000008
#define SERIAL_ERROR_PARITY                                         0x00000010

#define SERIAL_SP_UNSPECIFIED                                       0x00000000
#define SERIAL_SP_RS232                                                          0x00000001
#define SERIAL_SP_PARALLEL                                          0x00000002
#define SERIAL_SP_RS422                                                          0x00000003
#define SERIAL_SP_RS423                                                          0x00000004
#define SERIAL_SP_RS449                                                          0x00000005
#define SERIAL_SP_MODEM                                                          0X00000006
#define SERIAL_SP_FAX                                                            0x00000021
#define SERIAL_SP_SCANNER                                           0x00000022
#define SERIAL_SP_BRIDGE                                                         0x00000100
#define SERIAL_SP_LAT                                                            0x00000101
#define SERIAL_SP_TELNET                                                         0x00000102
#define SERIAL_SP_X25                                                            0x00000103
#define SERIAL_SP_SERIALCOMM                                        0x00000001

#define SERIAL_TX_WAITING_FOR_CTS                      0x00000001
#define SERIAL_TX_WAITING_FOR_DSR                      0x00000002
#define SERIAL_TX_WAITING_FOR_DCD                      0x00000004
#define SERIAL_TX_WAITING_FOR_XON                      0x00000008
#define SERIAL_TX_WAITING_XOFF_SENT                    0x00000010
#define SERIAL_TX_WAITING_ON_BREAK                     0x00000020
#define SERIAL_RX_WAITING_FOR_DSR                      0x00000040

#define SERIAL_DTR_STATE                                                         0x00000001
#define SERIAL_RTS_STATE                                                         0x00000002
#define SERIAL_CTS_STATE                                                         0x00000010
#define SERIAL_DSR_STATE                                                         0x00000020
#define SERIAL_RI_STATE                                                          0x00000040
#define SERIAL_DCD_STATE                                                         0x00000080

typedef struct _SERIALCONFIG {
  ULONG  Size;
  USHORT  Version;
  ULONG  SubType;
  ULONG  ProvOffset;
  ULONG  ProviderSize;
  WCHAR  ProviderData[1];
} SERIALCONFIG,*PSERIALCONFIG;

#ifdef __cplusplus
}
#endif

#endif /* _NTDDSER_ */
