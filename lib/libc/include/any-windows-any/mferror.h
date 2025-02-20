/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _MFERROR_H
#define _MFERROR_H

#define STATUS_SEVERITY(hr) (((hr) >> 30) & 0x3)
#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)

#define FACILITY_MF_WIN32  0x7
#define FACILITY_MF                     0xd

#define STATUS_SEVERITY_SUCCESS                     0x0
#define STATUS_SEVERITY_INFORMATIONAL  0x1
#define STATUS_SEVERITY_WARNING                     0x2
#define STATUS_SEVERITY_ERROR                       0x3

#define MF_E_PLATFORM_NOT_INITIALIZED  _HRESULT_TYPEDEF_(0xc00d36b0)
#define MF_E_BUFFERTOOSMALL                                      _HRESULT_TYPEDEF_(0xc00d36b1)
#define MF_E_INVALIDREQUEST                                      _HRESULT_TYPEDEF_(0xc00d36b2)
#define MF_E_INVALIDSTREAMNUMBER                    _HRESULT_TYPEDEF_(0xc00d36b3)
#define MF_E_INVALIDMEDIATYPE                       _HRESULT_TYPEDEF_(0xc00d36b4)
#define MF_E_NOTACCEPTING                                        _HRESULT_TYPEDEF_(0xc00d36b5)
#define MF_E_NOT_INITIALIZED                        _HRESULT_TYPEDEF_(0xc00d36b6)
#define MF_E_UNSUPPORTED_REPRESENTATION  _HRESULT_TYPEDEF_(0xc00d36b7)
#define MF_E_NO_MORE_TYPES                                       _HRESULT_TYPEDEF_(0xc00d36b9)
#define MF_E_UNSUPPORTED_SERVICE                    _HRESULT_TYPEDEF_(0xc00d36ba)
#define MF_E_UNEXPECTED                                          _HRESULT_TYPEDEF_(0xc00d36bb)
#define MF_E_INVALIDNAME                                         _HRESULT_TYPEDEF_(0xc00d36bc)
#define MF_E_INVALIDTYPE                                         _HRESULT_TYPEDEF_(0xc00d36bd)
#define MF_E_INVALID_FILE_FORMAT                    _HRESULT_TYPEDEF_(0xc00d36be)
#define MF_E_INVALIDINDEX                                        _HRESULT_TYPEDEF_(0xc00d36bf)
#define MF_E_INVALID_TIMESTAMP                      _HRESULT_TYPEDEF_(0xc00d36c0)
#define MF_E_UNSUPPORTED_SCHEME                     _HRESULT_TYPEDEF_(0xc00d36c3)
#define MF_E_UNSUPPORTED_BYTESTREAM_TYPE  _HRESULT_TYPEDEF_(0xc00d36c4)
#define MF_E_UNSUPPORTED_TIME_FORMAT   _HRESULT_TYPEDEF_(0xc00d36c5)
#define MF_E_NO_SAMPLE_TIMESTAMP                    _HRESULT_TYPEDEF_(0xc00d36c8)
#define MF_E_NO_SAMPLE_DURATION                     _HRESULT_TYPEDEF_(0xc00d36c9)
#define MF_E_INVALID_STREAM_DATA                    _HRESULT_TYPEDEF_(0xc00d36cb)
#define MF_E_RT_UNAVAILABLE                                      _HRESULT_TYPEDEF_(0xc00d36cf)
#define MF_E_UNSUPPORTED_RATE                       _HRESULT_TYPEDEF_(0xc00d36d0)
#define MF_E_THINNING_UNSUPPORTED                   _HRESULT_TYPEDEF_(0xc00d36d1)
#define MF_E_REVERSE_UNSUPPORTED                    _HRESULT_TYPEDEF_(0xc00d36d2)
#define MF_E_UNSUPPORTED_RATE_TRANSITION  _HRESULT_TYPEDEF_(0xc00d36d3)
#define MF_E_RATE_CHANGE_PREEMPTED     _HRESULT_TYPEDEF_(0xc00d36d4)
#define MF_E_NOT_FOUND                                           _HRESULT_TYPEDEF_(0xc00d36d5)
#define MF_E_NOT_AVAILABLE                                       _HRESULT_TYPEDEF_(0xc00d36d6)
#define MF_E_NO_CLOCK                                                         _HRESULT_TYPEDEF_(0xc00d36d7)
#define MF_S_MULTIPLE_BEGIN                                      _HRESULT_TYPEDEF_(0x000d36d8)
#define MF_E_MULTIPLE_BEGIN                                      _HRESULT_TYPEDEF_(0xc00d36d9)
#define MF_E_MULTIPLE_SUBSCRIBERS                   _HRESULT_TYPEDEF_(0xc00d36da)
#define MF_E_TIMER_ORPHANED                                      _HRESULT_TYPEDEF_(0xc00d36db)
#define MF_E_STATE_TRANSITION_PENDING                   _HRESULT_TYPEDEF_(0xc00d36dc)
#define MF_E_UNSUPPORTED_STATE_TRANSITION  _HRESULT_TYPEDEF_(0xc00d36dd)
#define MF_E_UNRECOVERABLE_ERROR_OCCURRED  _HRESULT_TYPEDEF_(0xc00d36de)
#define MF_E_SAMPLE_HAS_TOO_MANY_BUFFERS   _HRESULT_TYPEDEF_(0xc00d36df)
#define MF_E_SAMPLE_NOT_WRITABLE                    _HRESULT_TYPEDEF_(0xc00d36e0)
#define MF_E_INVALID_KEY                                         _HRESULT_TYPEDEF_(0xc00d36e2)
#define MF_E_BAD_STARTUP_VERSION                    _HRESULT_TYPEDEF_(0xc00d36e3)
#define MF_E_UNSUPPORTED_CAPTION                    _HRESULT_TYPEDEF_(0xc00d36e4)
#define MF_E_INVALID_POSITION                       _HRESULT_TYPEDEF_(0xc00d36e5)
#define MF_E_ATTRIBUTENOTFOUND                      _HRESULT_TYPEDEF_(0xc00d36e6)
#define MF_E_PROPERTY_TYPE_NOT_ALLOWED _HRESULT_TYPEDEF_(0xc00d36e7)

#define MF_E_TOPO_INVALID_OPTIONAL_NODE    _HRESULT_TYPEDEF_(0xc00d520e)
#define MF_E_TOPO_CANNOT_FIND_DECRYPTOR    _HRESULT_TYPEDEF_(0xc00d5211)
#define MF_E_TOPO_CODEC_NOT_FOUND                   _HRESULT_TYPEDEF_(0xc00d5212)
#define MF_E_TOPO_CANNOT_CONNECT                    _HRESULT_TYPEDEF_(0xc00d5213)
#define MF_E_TOPO_UNSUPPORTED                       _HRESULT_TYPEDEF_(0xc00d5214)
#define MF_E_TOPO_INVALID_TIME_ATTRIBUTES  _HRESULT_TYPEDEF_(0xc00d5215)
#define MF_E_TOPO_LOOPS_IN_TOPOLOGY    _HRESULT_TYPEDEF_(0xC00d5216)
#define MF_E_TOPO_MISSING_PRESENTATION_DESCRIPTOR  _HRESULT_TYPEDEF_(0xc00d5217)
#define MF_E_TOPO_MISSING_STREAM_DESCRIPTOR                     _HRESULT_TYPEDEF_(0xc00d5218)
#define MF_E_TOPO_STREAM_DESCRIPTOR_NOT_SELECTED   _HRESULT_TYPEDEF_(0xc00d5219)
#define MF_E_TOPO_MISSING_SOURCE                    _HRESULT_TYPEDEF_(0xc00d521a)
#define MF_E_TOPO_SINK_ACTIVATES_UNSUPPORTED                    _HRESULT_TYPEDEF_(0xc00d521b)
#define MF_E_TRANSFORM_TYPE_NOT_SET                   _HRESULT_TYPEDEF_(0xc00d6d60)
#define MF_E_TRANSFORM_STREAM_CHANGE     _HRESULT_TYPEDEF_(0xc00d6d61)
#define MF_E_TRANSFORM_INPUT_REMAINING   _HRESULT_TYPEDEF_(0xc00d6d62)
#define MF_E_TRANSFORM_PROFILE_MISSING   _HRESULT_TYPEDEF_(0xc00d6d63)
#define MF_E_TRANSFORM_PROFILE_INVALID_OR_CORRUPT  _HRESULT_TYPEDEF_(0xc00d6d64)
#define MF_E_TRANSFORM_PROFILE_TRUNCATED                        _HRESULT_TYPEDEF_(0xc00d6d65)
#define MF_E_TRANSFORM_PROPERTY_PID_NOT_RECOGNIZED _HRESULT_TYPEDEF_(0xc00d6d66)
#define MF_E_TRANSFORM_PROPERTY_VARIANT_TYPE_WRONG _HRESULT_TYPEDEF_(0xc00d6d67)
#define MF_E_TRANSFORM_PROPERTY_NOT_WRITEABLE                   _HRESULT_TYPEDEF_(0xc00d6d68)
#define MF_E_TRANSFORM_PROPERTY_ARRAY_VALUE_WRONG_NUM_DIM  _HRESULT_TYPEDEF_(0xc00d6d69)
#define MF_E_TRANSFORM_PROPERTY_VALUE_SIZE_WRONG   _HRESULT_TYPEDEF_(0xc00d6d6a)
#define MF_E_TRANSFORM_PROPERTY_VALUE_OUT_OF_RANGE _HRESULT_TYPEDEF_(0xc00d6d6b)
#define MF_E_TRANSFORM_PROPERTY_VALUE_INCOMPATIBLE _HRESULT_TYPEDEF_(0xc00d6d6c)
#define MF_E_TRANSFORM_NOT_POSSIBLE_FOR_CURRENT_OUTPUT_MEDIATYPE                    _HRESULT_TYPEDEF_(0xc00d6d6d)
#define MF_E_TRANSFORM_NOT_POSSIBLE_FOR_CURRENT_INPUT_MEDIATYPE                     _HRESULT_TYPEDEF_(0xc00d6d6e)
#define MF_E_TRANSFORM_NOT_POSSIBLE_FOR_CURRENT_MEDIATYPE_COMBINATION  _HRESULT_TYPEDEF_(0xc00d6d6f)
#define MF_E_TRANSFORM_CONFLICTS_WITH_OTHER_CURRENTLY_ENABLED_FEATURES _HRESULT_TYPEDEF_(0xc00d6d70)
#define MF_E_TRANSFORM_NEED_MORE_INPUT                                                                                                  _HRESULT_TYPEDEF_(0xc00d6d72)
#define MF_E_TRANSFORM_NOT_POSSIBLE_FOR_CURRENT_SPKR_CONFIG                                      _HRESULT_TYPEDEF_(0xc00d6d73)
#define MF_E_TRANSFORM_CANNOT_CHANGE_MEDIATYPE_WHILE_PROCESSING                     _HRESULT_TYPEDEF_(0xc00d6d74)
#define MF_S_TRANSFORM_DO_NOT_PROPAGATE_EVENT                    _HRESULT_TYPEDEF_(0x000d6d75)
#define MF_E_UNSUPPORTED_D3D_TYPE                                                          _HRESULT_TYPEDEF_(0xc00d6d76)
#define MF_E_TRANSFORM_ASYNC_LOCKED                                           _HRESULT_TYPEDEF_(0xc00d6d77)
#define MF_E_TRANSFORM_CANNOT_INITIALIZE_ACM_DRIVER _HRESULT_TYPEDEF_(0xc00d6d78)

#endif /* _MFERROR_H */
