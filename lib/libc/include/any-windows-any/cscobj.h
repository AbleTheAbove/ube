/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CSCOBJ
#define _INC_CSCOBJ
#if (_WIN32_WINNT >= 0x0600)
#ifdef __cplusplus
extern "C" {
#endif

typedef enum _OFFLINEFILES_CACHING_MODE {
  OFFLINEFILES_CACHING_MODE_NONE                                        = 0,
  OFFLINEFILES_CACHING_MODE_NOCACHING                      = 1,
  OFFLINEFILES_CACHING_MODE_MANUAL                                      = 2,
  OFFLINEFILES_CACHING_MODE_AUTO_DOC                       = 3,
  OFFLINEFILES_CACHING_MODE_AUTO_PROGANDDOC   = 4 
} OFFLINEFILES_CACHING_MODE;

typedef enum _OFFLINEFILES_COMPARE {
  OFFLINEFILES_COMPARE_EQ    = 0,
  OFFLINEFILES_COMPARE_NEQ   = 1,
  OFFLINEFILES_COMPARE_LT    = 2,
  OFFLINEFILES_COMPARE_GT    = 3,
  OFFLINEFILES_COMPARE_LTE   = 4,
  OFFLINEFILES_COMPARE_GTE   = 5 
} OFFLINEFILES_COMPARE;

typedef enum _OFFLINEFILES_CONNECT_STATE {
  OFFLINEFILES_CONNECT_STATE_UNKNOWN                                                              = 0,
  OFFLINEFILES_CONNECT_STATE_OFFLINE                                                              = 1,
  OFFLINEFILES_CONNECT_STATE_ONLINE                                                                            = 2,
  OFFLINEFILES_CONNECT_STATE_TRANSPARENTLY_CACHED                       = 3,
  OFFLINEFILES_CONNECT_STATE_PARTLY_TRANSPARENTLY_CACHED   = 4 
} OFFLINEFILES_CONNECT_STATE;

typedef enum _OFFLINEFILES_EVENTS {
  OFFLINEFILES_EVENT_CACHEMOVED                                                          = 0,
  OFFLINEFILES_EVENT_CACHEISFULL                                                         = 1,
  OFFLINEFILES_EVENT_CACHEISCORRUPTED                                       = 2,
  OFFLINEFILES_EVENT_ENABLED                                                             = 3,
  OFFLINEFILES_EVENT_ENCRYPTIONCHANGED                                      = 4,
  OFFLINEFILES_EVENT_SYNCBEGIN                                                           = 5,
  OFFLINEFILES_EVENT_SYNCFILERESULT                                         = 6,
  OFFLINEFILES_EVENT_SYNCCONFLICTRECADDED                      = 7,
  OFFLINEFILES_EVENT_SYNCCONFLICTRECUPDATED                    = 8,
  OFFLINEFILES_EVENT_SYNCCONFLICTRECREMOVED                    = 9,
  OFFLINEFILES_EVENT_SYNCEND                                                             = 10,
  OFFLINEFILES_EVENT_BACKGROUNDSYNCBEGIN                       = 11,
  OFFLINEFILES_EVENT_BACKGROUNDSYNCEND                                      = 12,
  OFFLINEFILES_EVENT_NETTRANSPORTARRIVED                       = 13,
  OFFLINEFILES_EVENT_NONETTRANSPORTS                                        = 14,
  OFFLINEFILES_EVENT_ITEMDISCONNECTED                                       = 15,
  OFFLINEFILES_EVENT_ITEMRECONNECTED                                        = 16,
  OFFLINEFILES_EVENT_ITEMAVAILABLEOFFLINE                      = 17,
  OFFLINEFILES_EVENT_ITEMNOTAVAILABLEOFFLINE                   = 18,
  OFFLINEFILES_EVENT_ITEMPINNED                                                          = 19,
  OFFLINEFILES_EVENT_ITEMNOTPINNED                                          = 20,
  OFFLINEFILES_EVENT_ITEMMODIFIED                                           = 21,
  OFFLINEFILES_EVENT_ITEMADDEDTOCACHE                                       = 22,
  OFFLINEFILES_EVENT_ITEMDELETEDFROMCACHE                      = 23,
  OFFLINEFILES_EVENT_ITEMRENAMED                                                         = 24,
  OFFLINEFILES_EVENT_DATALOST                                                            = 25,
  OFFLINEFILES_EVENT_PING                                                                             = 26,
  OFFLINEFILES_EVENT_ITEMRECONNECTBEGIN                        = 27,
  OFFLINEFILES_EVENT_ITEMRECONNECTEND                                       = 28,
  OFFLINEFILES_EVENT_CACHEEVICTBEGIN                                        = 29,
  OFFLINEFILES_EVENT_CACHEEVICTEND                                          = 30,
  OFFLINEFILES_EVENT_POLICYCHANGEDETECTED                      = 31,
  OFFLINEFILES_EVENT_PREFERENCECHANGEDETECTED     = 32,
  OFFLINEFILES_EVENT_SETTINGSCHANGESAPPLIED                    = 33,
  OFFLINEFILES_EVENT_TRANSPARENTCACHEITEMNOTIFY   = 34,
  OFFLINEFILES_EVENT_PREFETCHFILEBEGIN                                      = 35,
  OFFLINEFILES_EVENT_PREFETCHFILEEND                                        = 36 
} OFFLINEFILES_EVENTS;

typedef enum _OFFLINEFILES_ITEM_COPY {
  OFFLINEFILES_ITEM_COPY_LOCAL                   = 0,
  OFFLINEFILES_ITEM_COPY_REMOTE     = 1,
  OFFLINEFILES_ITEM_COPY_ORIGINAL   = 2 
} OFFLINEFILES_ITEM_COPY;

typedef enum _OFFLINEFILES_ITEM_TIME {
  OFFLINEFILES_ITEM_TIME_CREATION     = 0,
  OFFLINEFILES_ITEM_TIME_LASTACCESS   = 1,
  OFFLINEFILES_ITEM_TIME_LASTWRITE    = 2 
} OFFLINEFILES_ITEM_TIME;

typedef enum _OFFLINEFILES_ITEM_TYPE {
  OFFLINEFILES_ITEM_TYPE_FILE                     = 0,
  OFFLINEFILES_ITEM_TYPE_DIRECTORY   = 1,
  OFFLINEFILES_ITEM_TYPE_SHARE                    = 2,
  OFFLINEFILES_ITEM_TYPE_SERVER                   = 3 
} OFFLINEFILES_ITEM_TYPE;

typedef enum _OFFLINEFILES_OFFLINE_REASON {
  OFFLINEFILES_OFFLINE_REASON_UNKNOWN                                           = 0,
  OFFLINEFILES_OFFLINE_REASON_NOT_APPLICABLE                       = 1,
  OFFLINEFILES_OFFLINE_REASON_CONNECTION_FORCED                    = 2,
  OFFLINEFILES_OFFLINE_REASON_CONNECTION_SLOW                      = 3,
  OFFLINEFILES_OFFLINE_REASON_CONNECTION_ERROR                     = 4,
  OFFLINEFILES_OFFLINE_REASON_ITEM_VERSION_CONFLICT   = 5,
  OFFLINEFILES_OFFLINE_REASON_ITEM_SUSPENDED                       = 6 
} OFFLINEFILES_OFFLINE_REASON;

typedef enum _OFFLINEFILES_OP_RESPONSE {
  OFFLINEFILES_OP_CONTINUE   = 0,
  OFFLINEFILES_OP_RETRY                   = 1,
  OFFLINEFILES_OP_ABORT                   = 2 
} OFFLINEFILES_OP_RESPONSE;

typedef enum _OFFLINEFILES_PATHFILTER_MATCH {
  OFFLINEFILES_PATHFILTER_SELF                                         = 0,
  OFFLINEFILES_PATHFILTER_CHILD                                        = 1,
  OFFLINEFILES_PATHFILTER_DESCENDENT                      = 2,
  OFFLINEFILES_PATHFILTER_SELFORCHILD                     = 3,
  OFFLINEFILES_PATHFILTER_SELFORDESCENDENT   = 4 
} OFFLINEFILES_PATHFILTER_MATCH;

typedef enum _OFFLINEFILES_SETTING_VALUE_TYPE {
  OFFLINEFILES_SETTING_VALUE_UI4                                                           = 0,
  OFFLINEFILES_SETTING_VALUE_BSTR                                                          = 1,
  OFFLINEFILES_SETTING_VALUE_BSTR_DBLNULTERM                     = 2,
  OFFLINEFILES_SETTING_VALUE_2DIM_ARRAY_BSTR_UI4    = 3,
  OFFLINEFILES_SETTING_VALUE_2DIM_ARRAY_BSTR_BSTR   = 4 
} OFFLINEFILES_SETTING_VALUE_TYPE;

typedef enum _OFFLINEFILES_SYNC_CONFLICT_RESOLVE {
  OFFLINEFILES_SYNC_CONFLICT_RESOLVE_NONE                                       = 0,
  OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPLOCAL                     = 1,
  OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPREMOTE                    = 2,
  OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPALLCHANGES   = 3,
  OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPLATEST                    = 4,
  OFFLINEFILES_SYNC_CONFLICT_RESOLVE_LOG                                        = 5,
  OFFLINEFILES_SYNC_CONFLICT_RESOLVE_SKIP                                       = 6,
  OFFLINEFILES_SYNC_CONFLICT_ABORT                                                           = 7 
} OFFLINEFILES_SYNC_CONFLICT_RESOLVE;

typedef enum _OFFLINEFILES_SYNC_OPERATION {
  OFFLINEFILES_SYNC_OPERATION_CREATE_COPY_ON_SERVER   = 0,
  OFFLINEFILES_SYNC_OPERATION_CREATE_COPY_ON_CLIENT   = 1,
  OFFLINEFILES_SYNC_OPERATION_SYNC_TO_SERVER                       = 2,
  OFFLINEFILES_SYNC_OPERATION_SYNC_TO_CLIENT                       = 3,
  OFFLINEFILES_SYNC_OPERATION_DELETE_SERVER_COPY                   = 4,
  OFFLINEFILES_SYNC_OPERATION_DELETE_CLIENT_COPY                   = 5,
  OFFLINEFILES_SYNC_OPERATION_PIN                                                            = 6,
  OFFLINEFILES_SYNC_OPERATION_PREPARE                                           = 7 
} OFFLINEFILES_SYNC_OPERATION;

typedef enum _OFFLINEFILES_SYNC_STATE {
  OFFLINEFILES_SYNC_STATE_Stable                                                                                                                                          = 0,
  OFFLINEFILES_SYNC_STATE_FileOnClient_DirOnServer                                                                                 = 1,
  OFFLINEFILES_SYNC_STATE_FileOnClient_NoServerCopy                                                                                = 2,
  OFFLINEFILES_SYNC_STATE_DirOnClient_FileOnServer                                                                                 = 3,
  OFFLINEFILES_SYNC_STATE_DirOnClient_FileChangedOnServer                                                             = 4,
  OFFLINEFILES_SYNC_STATE_DirOnClient_NoServerCopy                                                                                 = 5,
  OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_NoServerCopy                                                            = 6,
  OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileChangedOnServer                                        = 7,
  OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirChangedOnServer                                         = 8,
  OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileOnServer                                                            = 9,
  OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirOnServer                                                             = 10,
  OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DeletedOnServer                                                         = 11,
  OFFLINEFILES_SYNC_STATE_FileChangedOnClient_ChangedOnServer                                                         = 12,
  OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirOnServer                                                             = 13,
  OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirChangedOnServer                                         = 14,
  OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DeletedOnServer                                                         = 15,
  OFFLINEFILES_SYNC_STATE_FileSparseOnClient_ChangedOnServer                                                          = 16,
  OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DeletedOnServer                                                          = 17,
  OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DirOnServer                                                              = 18,
  OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DirChangedOnServer                                          = 19,
  OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_NoServerCopy                                                             = 20,
  OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DirOnServer                                                              = 21,
  OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileOnServer                                                             = 22,
  OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileChangedOnServer                                         = 23,
  OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DirChangedOnServer                                          = 24,
  OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DeletedOnServer                                                          = 25,
  OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileOnServer                                                             = 26,
  OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileChangedOnServer                                         = 27,
  OFFLINEFILES_SYNC_STATE_DirChangedOnClient_ChangedOnServer                                                          = 28,
  OFFLINEFILES_SYNC_STATE_DirChangedOnClient_DeletedOnServer                                                          = 29,
  OFFLINEFILES_SYNC_STATE_NoClientCopy_FileOnServer                                                                                = 30,
  OFFLINEFILES_SYNC_STATE_NoClientCopy_DirOnServer                                                                                 = 31,
  OFFLINEFILES_SYNC_STATE_NoClientCopy_FileChangedOnServer                                                            = 32,
  OFFLINEFILES_SYNC_STATE_NoClientCopy_DirChangedOnServer                                                             = 33,
  OFFLINEFILES_SYNC_STATE_DeletedOnClient_FileOnServer                                                                             = 34,
  OFFLINEFILES_SYNC_STATE_DeletedOnClient_DirOnServer                                                                              = 35,
  OFFLINEFILES_SYNC_STATE_DeletedOnClient_FileChangedOnServer                                                         = 36,
  OFFLINEFILES_SYNC_STATE_DeletedOnClient_DirChangedOnServer                                                          = 37,
  OFFLINEFILES_SYNC_STATE_FileSparseOnClient                                                                                                    = 38,
  OFFLINEFILES_SYNC_STATE_FileChangedOnClient                                                                                                   = 39,
  OFFLINEFILES_SYNC_STATE_FileRenamedOnClient                                                                                                   = 40,
  OFFLINEFILES_SYNC_STATE_DirSparseOnClient                                                                                                                  = 41,
  OFFLINEFILES_SYNC_STATE_DirChangedOnClient                                                                                                    = 42,
  OFFLINEFILES_SYNC_STATE_DirRenamedOnClient                                                                                                    = 43,
  OFFLINEFILES_SYNC_STATE_FileChangedOnServer                                                                                                   = 44,
  OFFLINEFILES_SYNC_STATE_FileRenamedOnServer                                                                                                   = 45,
  OFFLINEFILES_SYNC_STATE_FileDeletedOnServer                                                                                                   = 46,
  OFFLINEFILES_SYNC_STATE_DirChangedOnServer                                                                                                    = 47,
  OFFLINEFILES_SYNC_STATE_DirRenamedOnServer                                                                                                    = 48,
  OFFLINEFILES_SYNC_STATE_DirDeletedOnServer                                                                                                    = 49,
  OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_FileOnServer                       = 50,
  OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_FileChangedOnServer   = 51,
  OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_DirOnServer                        = 52,
  OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_DirChangedOnServer    = 53 
} OFFLINEFILES_SYNC_STATE;

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_CSCOBJ*/

