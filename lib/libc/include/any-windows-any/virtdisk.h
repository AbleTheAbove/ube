/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_VIRTDISK
#define _INC_VIRTDISK

#if (_WIN32_WINNT >= 0x0601)
#ifdef __cplusplus
extern "C" {
#endif

#define VIRTDISKAPI DECLSPEC_IMPORT

#define VIRTUAL_STORAGE_TYPE_DEVICE_UNKNOWN     0
#define VIRTUAL_STORAGE_TYPE_DEVICE_ISO                      1
#define VIRTUAL_STORAGE_TYPE_DEVICE_VHD                      2
#if (_WIN32_WINNT >= 0x0A00)
#define VIRTUAL_STORAGE_TYPE_DEVICE_VHDX                     3
#endif /* _WIN32_WINNT >= 0x0A00 */

typedef enum _ATTACH_VIRTUAL_DISK_FLAG {
  ATTACH_VIRTUAL_DISK_FLAG_NONE                                           = 0x00000000,
  ATTACH_VIRTUAL_DISK_FLAG_READ_ONLY                                      = 0x00000001,
  ATTACH_VIRTUAL_DISK_FLAG_NO_DRIVE_LETTER                   = 0x00000002,
  ATTACH_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME   = 0x00000004,
  ATTACH_VIRTUAL_DISK_FLAG_NO_LOCAL_HOST                     = 0x00000008 
} ATTACH_VIRTUAL_DISK_FLAG;

typedef enum _ATTACH_VIRTUAL_DISK_VERSION {
  ATTACH_VIRTUAL_DISK_VERSION_UNSPECIFIED   = 0,
  ATTACH_VIRTUAL_DISK_VERSION_1                                       = 1 
} ATTACH_VIRTUAL_DISK_VERSION;

typedef enum _COMPACT_VIRTUAL_DISK_FLAG {
  COMPACT_VIRTUAL_DISK_FLAG_NONE   = 0x00000000 
} COMPACT_VIRTUAL_DISK_FLAG;

typedef enum _COMPACT_VIRTUAL_DISK_VERSION {
  COMPACT_VIRTUAL_DISK_VERSION_UNSPECIFIED   = 0,
  COMPACT_VIRTUAL_DISK_VERSION_1                                       = 1 
} COMPACT_VIRTUAL_DISK_VERSION;

typedef enum _CREATE_VIRTUAL_DISK_FLAG {
  CREATE_VIRTUAL_DISK_FLAG_NONE                                                              = 0x00000000,
  CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION   = 0x00000001
#if (_WIN32_WINNT >= 0x0602)
  ,
  CREATE_VIRTUAL_DISK_FLAG_PREVENT_WRITES_TO_SOURCE_DISK     = 0x2,
  CREATE_VIRTUAL_DISK_FLAG_DO_NOT_COPY_METADATA_FROM_PARENT  = 0x4
#endif /* _WIN32_WINNT >= 0x0602 */
} CREATE_VIRTUAL_DISK_FLAG;

typedef enum _CREATE_VIRTUAL_DISK_VERSION {
  CREATE_VIRTUAL_DISK_VERSION_UNSPECIFIED   = 0,
  CREATE_VIRTUAL_DISK_VERSION_1                                       = 1
#if (_WIN32_WINNT >= 0x0602)
  ,
  CREATE_VIRTUAL_DISK_VERSION_2                                       = 2
#endif /* _WIN32_WINNT >= 0x0602 */
} CREATE_VIRTUAL_DISK_VERSION;

typedef enum _DEPENDENT_DISK_FLAG {
  DEPENDENT_DISK_FLAG_NONE                                                          = 0x00000000,
  DEPENDENT_DISK_FLAG_MULT_BACKING_FILES     = 0x00000001,
  DEPENDENT_DISK_FLAG_FULLY_ALLOCATED                     = 0x00000002,
  DEPENDENT_DISK_FLAG_READ_ONLY                                        = 0x00000004,
  DEPENDENT_DISK_FLAG_REMOTE                                           = 0x00000008,
  DEPENDENT_DISK_FLAG_SYSTEM_VOLUME                       = 0x00000010,
  DEPENDENT_DISK_FLAG_SYSTEM_VOLUME_PARENT   = 0x00000020,
  DEPENDENT_DISK_FLAG_REMOVABLE                                        = 0x00000040,
  DEPENDENT_DISK_FLAG_NO_DRIVE_LETTER                     = 0x00000080,
  DEPENDENT_DISK_FLAG_PARENT                                           = 0x00000100,
  DEPENDENT_DISK_FLAG_NO_HOST_DISK                        = 0x00000200,
  DEPENDENT_DISK_FLAG_PERMANENT_LIFETIME     = 0x00000400 
} DEPENDENT_DISK_FLAG;

typedef enum _EXPAND_VIRTUAL_DISK_VERSION {
  EXPAND_VIRTUAL_DISK_VERSION_UNSPECIFIED   = 0,
  EXPAND_VIRTUAL_DISK_VERSION_1                                       = 1 
} EXPAND_VIRTUAL_DISK_VERSION;

typedef enum _DETACH_VIRTUAL_DISK_FLAG {
  DETACH_VIRTUAL_DISK_FLAG_NONE   = 0x00000000 
} DETACH_VIRTUAL_DISK_FLAG;

typedef enum _EXPAND_VIRTUAL_DISK_FLAG {
  EXPAND_VIRTUAL_DISK_FLAG_NONE   = 0x00000000 
} EXPAND_VIRTUAL_DISK_FLAG;

typedef enum _GET_STORAGE_DEPENDENCY_FLAG {
  GET_STORAGE_DEPENDENCY_FLAG_NONE                        = 0x00000000,
  GET_STORAGE_DEPENDENCY_FLAG_HOST_VOLUMES   = 0x00000001,
  GET_STORAGE_DEPENDENCY_FLAG_DISK_HANDLE    = 0x00000002 
} GET_STORAGE_DEPENDENCY_FLAG;

typedef enum _GET_VIRTUAL_DISK_INFO_VERSION {
  GET_VIRTUAL_DISK_INFO_UNSPECIFIED                                      = 0,
  GET_VIRTUAL_DISK_INFO_SIZE                                                          = 1,
  GET_VIRTUAL_DISK_INFO_IDENTIFIER                                       = 2,
  GET_VIRTUAL_DISK_INFO_PARENT_LOCATION                     = 3,
  GET_VIRTUAL_DISK_INFO_PARENT_IDENTIFIER                   = 4,
  GET_VIRTUAL_DISK_INFO_PARENT_TIMESTAMP                    = 5,
  GET_VIRTUAL_DISK_INFO_VIRTUAL_STORAGE_TYPE   = 6,
  GET_VIRTUAL_DISK_INFO_PROVIDER_SUBTYPE                    = 7
#if (_WIN32_WINNT >= 0x0602)
  ,
  GET_VIRTUAL_DISK_INFO_IS_4K_ALIGNED                                         = 8,
  GET_VIRTUAL_DISK_INFO_PHYSICAL_DISK                                         = 9,
  GET_VIRTUAL_DISK_INFO_VHD_PHYSICAL_SECTOR_SIZE    = 10,
  GET_VIRTUAL_DISK_INFO_SMALLEST_SAFE_VIRTUAL_SIZE  = 11,
  GET_VIRTUAL_DISK_INFO_FRAGMENTATION                                         = 12
#endif /* _WIN32_WINNT >= 0x0602 */
#if (_WIN32_WINNT >= 0x0603)
  ,
  GET_VIRTUAL_DISK_INFO_IS_LOADED                                                          = 13,
  GET_VIRTUAL_DISK_INFO_VIRTUAL_DISK_ID                                       = 14
#endif /* _WIN32_WINNT >= 0x0603 */
#if (_WIN32_WINNT >= 0x0A00)
  ,
  GET_VIRTUAL_DISK_INFO_CHANGE_TRACKING_STATE                    = 15
#endif /* _WIN32_WINNT >= 0x0A00 */
} GET_VIRTUAL_DISK_INFO_VERSION;

typedef enum _MIRROR_VIRTUAL_DISK_FLAG {
  MIRROR_VIRTUAL_DISK_FLAG_NONE                        = 0x00000000,
  MIRROR_VIRTUAL_DISK_FLAG_EXISTING_FILE  = 0x00000001
} MIRROR_VIRTUAL_DISK_FLAG;

typedef enum _MIRROR_VIRTUAL_DISK_VERSION {
  MIRROR_VIRTUAL_DISK_VERSION_UNSPECIFIED  = 0,
  MIRROR_VIRTUAL_DISK_VERSION_1                                      = 1
} MIRROR_VIRTUAL_DISK_VERSION;

typedef enum _MERGE_VIRTUAL_DISK_FLAG {
  MERGE_VIRTUAL_DISK_FLAG_NONE   = 0x00000000 
} MERGE_VIRTUAL_DISK_FLAG;

typedef enum _MERGE_VIRTUAL_DISK_VERSION {
  MERGE_VIRTUAL_DISK_VERSION_UNSPECIFIED   = 0,
  MERGE_VIRTUAL_DISK_VERSION_1                                       = 1
#if (_WIN32_WINNT >= 0x0602)
  ,
  MERGE_VIRTUAL_DISK_VERSION_2                                       = 2
#endif /* _WIN32_WINNT >= 0x0A00 */
} MERGE_VIRTUAL_DISK_VERSION;

typedef enum _OPEN_VIRTUAL_DISK_FLAG {
  OPEN_VIRTUAL_DISK_FLAG_NONE                      = 0x00000000,
  OPEN_VIRTUAL_DISK_FLAG_NO_PARENTS   = 0x00000001,
  OPEN_VIRTUAL_DISK_FLAG_BLANK_FILE   = 0x00000002,
  OPEN_VIRTUAL_DISK_FLAG_BOOT_DRIVE   = 0x00000004
#if (_WIN32_WINNT >= 0x0602)
  ,
  OPEN_VIRTUAL_DISK_FLAG_CACHED_IO                       = 0x00000008,
  OPEN_VIRTUAL_DISK_FLAG_CUSTOM_DIFF_CHAIN  = 0x00000010
#endif /* _WIN32_WINNT >= 0x0602 */
} OPEN_VIRTUAL_DISK_FLAG;

typedef enum _OPEN_VIRTUAL_DISK_VERSION {
  OPEN_VIRTUAL_DISK_VERSION_UNSPECIFIED   = 0,
  OPEN_VIRTUAL_DISK_VERSION_1                                       = 1
#if (_WIN32_WINNT >= 0x0602)
  ,
  OPEN_VIRTUAL_DISK_VERSION_2                                       = 2
#endif /* _WIN32_WINNT >= 0x0602 */
} OPEN_VIRTUAL_DISK_VERSION;

typedef enum _SET_VIRTUAL_DISK_INFO_VERSION {
  SET_VIRTUAL_DISK_INFO_UNSPECIFIED   = 0,
  SET_VIRTUAL_DISK_INFO_PARENT_PATH   = 1,
  SET_VIRTUAL_DISK_INFO_IDENTIFIER    = 2
#if (_WIN32_WINNT >= 0x0602)
  ,
  SET_VIRTUAL_DISK_INFO_PARENT_PATH_WITH_DEPTH  = 3,
  SET_VIRTUAL_DISK_INFO_PHYSICAL_SECTOR_SIZE    = 4
#endif /* (_WIN32_WINNT >= 0x0602) */
#if (_WIN32_WINNT >= 0x0603)
  ,
  SET_VIRTUAL_DISK_INFO_VIRTUAL_DISK_ID                      = 5
#endif /* (_WIN32_WINNT >= 0x0603) */
#if (_WIN32_WINNT >= 0x0A00)
  ,
  SET_VIRTUAL_DISK_INFO_CHANGE_TRACKING_STATE   = 6,
  SET_VIRTUAL_DISK_INFO_PARENT_LOCATOR                       = 7
#endif /* (_WIN32_WINNT >= 0x0A00) */
} SET_VIRTUAL_DISK_INFO_VERSION;

typedef enum _STORAGE_DEPENDENCY_INFO_VERSION {
  STORAGE_DEPENDENCY_INFO_VERSION_UNSPECIFIED   = 0,
  STORAGE_DEPENDENCY_INFO_VERSION_1                                       = 1,
  STORAGE_DEPENDENCY_INFO_VERSION_2                                       = 2 
} STORAGE_DEPENDENCY_INFO_VERSION;

typedef enum _VIRTUAL_DISK_ACCESS_MASK {
  VIRTUAL_DISK_ACCESS_NONE                     = 0x00000000,
  VIRTUAL_DISK_ACCESS_ATTACH_RO   = 0x00010000,
  VIRTUAL_DISK_ACCESS_ATTACH_RW   = 0x00020000,
  VIRTUAL_DISK_ACCESS_DETACH                   = 0x00040000,
  VIRTUAL_DISK_ACCESS_GET_INFO    = 0x00080000,
  VIRTUAL_DISK_ACCESS_CREATE                   = 0x00100000,
  VIRTUAL_DISK_ACCESS_METAOPS     = 0x00200000,
  VIRTUAL_DISK_ACCESS_READ                     = 0x000d0000,
  VIRTUAL_DISK_ACCESS_ALL                      = 0x003f0000,
  VIRTUAL_DISK_ACCESS_WRITABLE    = 0x00320000 
} VIRTUAL_DISK_ACCESS_MASK;

#if (_WIN32_WINNT >= 0x0602)

typedef enum _RESIZE_VIRTUAL_DISK_FLAG {
  RESIZE_VIRTUAL_DISK_FLAG_NONE                                                                                                   = 0x0,
  RESIZE_VIRTUAL_DISK_FLAG_ALLOW_UNSAFE_VIRTUAL_SIZE                                       = 0x1,
  RESIZE_VIRTUAL_DISK_FLAG_RESIZE_TO_SMALLEST_SAFE_VIRTUAL_SIZE  = 0x2
} RESIZE_VIRTUAL_DISK_FLAG;

typedef enum _RESIZE_VIRTUAL_DISK_VERSION {
  RESIZE_VIRTUAL_DISK_VERSION_UNSPECIFIED  = 0,
  RESIZE_VIRTUAL_DISK_VERSION_1                                      = 1
} RESIZE_VIRTUAL_DISK_VERSION;

#endif /* (_WIN32_WINNT >= 0x0602) */
#if (_WIN32_WINNT >= 0x0A00)

typedef enum _APPLY_SNAPSHOT_VHDSET_FLAG {
  APPLY_SNAPSHOT_VHDSET_FLAG_NONE                    = 0x00000000,
  APPLY_SNAPSHOT_VHDSET_FLAG_WRITEABLE  = 0x00000001
} APPLY_SNAPSHOT_VHDSET_FLAG, *PAPPLY_SNAPSHOT_VHDSET_FLAG;

typedef enum _APPLY_SNAPSHOT_VHDSET_VERSION {
  APPLY_SNAPSHOT_VHDSET_VERSION_UNSPECIFIED   = 0,
  APPLY_SNAPSHOT_VHDSET_VERSION_1                                       = 1
} APPLY_SNAPSHOT_VHDSET_VERSION;

typedef enum _DELETE_SNAPSHOT_VHDSET_FLAG {
  DELETE_SNAPSHOT_VHDSET_FLAG_NONE                      = 0x00000000,
  DELETE_SNAPSHOT_VHDSET_FLAG_PERSIST_RCT  = 0x00000001
} DELETE_SNAPSHOT_VHDSET_FLAG, *PDELETE_SNAPSHOT_VHDSET_FLAG;

typedef enum _DELETE_SNAPSHOT_VHDSET_VERSION {
  DELETE_SNAPSHOT_VHDSET_VERSION_UNSPECIFIED  = 0x00000000,
  DELETE_SNAPSHOT_VHDSET_VERSION_1                                      = 0x00000001
} DELETE_SNAPSHOT_VHDSET_VERSION, *PDELETE_SNAPSHOT_VHDSET_VERSION;

typedef enum _MODIFY_VHDSET_FLAG {
  MODIFY_VHDSET_FLAG_NONE  = 0x00000000
} MODIFY_VHDSET_FLAG, *PMODIFY_VHDSET_FLAG;

typedef enum _MODIFY_VHDSET_VERSION {
  MODIFY_VHDSET_UNSPECIFIED                                      = 0,
  MODIFY_VHDSET_SNAPSHOT_PATH                       = 1,
  MODIFY_VHDSET_REMOVE_SNAPSHOT                     = 2,
  MODIFY_VHDSET_DEFAULT_SNAPSHOT_PATH  = 3
} MODIFY_VHDSET_VERSION, *PMODIFY_VHDSET_VERSION;

typedef enum _QUERY_CHANGES_VIRTUAL_DISK_FLAG {
  QUERY_CHANGES_VIRTUAL_DISK_FLAG_NONE = 0x00000000
} QUERY_CHANGES_VIRTUAL_DISK_FLAG;

typedef enum _TAKE_SNAPSHOT_VHDSET_FLAG {
   TAKE_SNAPSHOT_VHDSET_FLAG_NONE  = 0x00000000
} TAKE_SNAPSHOT_VHDSET_FLAG, *PTAKE_SNAPSHOT_VHDSET_FLAG;

typedef enum _TAKE_SNAPSHOT_VHDSET_VERSION {
  TAKE_SNAPSHOT_VHDSET_VERSION_UNSPECIFIED  = 0,
   TAKE_SNAPSHOT_VHDSET_VERSION_1                        = 1
} TAKE_SNAPSHOT_VHDSET_VERSION;

#endif /* _WIN32_WINNT >= 0x0A00 */

typedef struct _VIRTUAL_STORAGE_TYPE {
  ULONG DeviceId;
  GUID  VendorId;
} VIRTUAL_STORAGE_TYPE, *PVIRTUAL_STORAGE_TYPE;

typedef struct _ATTACH_VIRTUAL_DISK_PARAMETERS {
  ATTACH_VIRTUAL_DISK_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   ULONG Reserved;
    } Version1;
  } DUMMYUNIONNAME;
} ATTACH_VIRTUAL_DISK_PARAMETERS, *PATTACH_VIRTUAL_DISK_PARAMETERS;

typedef struct _COMPACT_VIRTUAL_DISK_PARAMETERS {
  COMPACT_VIRTUAL_DISK_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   ULONG Reserved;
    } Version1;
  } DUMMYUNIONNAME;
} COMPACT_VIRTUAL_DISK_PARAMETERS, *PCOMPACT_VIRTUAL_DISK_PARAMETERS;

typedef struct _CREATE_VIRTUAL_DISK_PARAMETERS {
  CREATE_VIRTUAL_DISK_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   GUID                   UniqueId;
                   ULONGLONG MaximumSize;
                   ULONG     BlockSizeInBytes;
                   ULONG     SectorSizeInBytes;
                   PCWSTR    ParentPath;
                   PCWSTR    SourcePath;
    } Version1;
#if (_WIN32_WINNT >= 0x0602)
    struct {
                   GUID                                                          UniqueId;
                   ULONGLONG                                        MaximumSize;
                   ULONG                                                         BlockSizeInBytes;
                   ULONG                                                         SectorSizeInBytes;
                   PCWSTR                                           ParentPath;
                   PCWSTR                                           SourcePath;
                   OPEN_VIRTUAL_DISK_FLAG OpenFlags;
                   VIRTUAL_STORAGE_TYPE   ParentVirtualStorageType;
                   VIRTUAL_STORAGE_TYPE   SourceVirtualStorageType;
                   GUID                                                          ResiliencyGuid;
    } Version2;
#endif /* _WIN32_WINNT >= 0x0602 */
  } DUMMYUNIONNAME;
} CREATE_VIRTUAL_DISK_PARAMETERS, *PCREATE_VIRTUAL_DISK_PARAMETERS;

typedef struct _EXPAND_VIRTUAL_DISK_PARAMETERS {
  EXPAND_VIRTUAL_DISK_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   ULONGLONG NewSize;
    } Version1;
  } DUMMYUNIONNAME;
} EXPAND_VIRTUAL_DISK_PARAMETERS, *PEXPAND_VIRTUAL_DISK_PARAMETERS;

typedef struct _GET_VIRTUAL_DISK_INFO {
  GET_VIRTUAL_DISK_INFO_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   ULONGLONG VirtualSize;
                   ULONGLONG PhysicalSize;
                   ULONG     BlockSize;
                   ULONG     SectorSize;
    } Size;
    GUID                                           Identifier;
    struct {
                   WINBOOL  ParentResolved;
                   WCHAR ParentLocationBuffer[1];
    } ParentLocation;
    GUID                                           ParentIdentifier;
    ULONG                                          ParentTimestamp;
    VIRTUAL_STORAGE_TYPE VirtualStorageType;
    ULONG                                          ProviderSubtype;
#if (_WIN32_WINNT >= 0x0602)
    WINBOOL                                        Is4kAligned;
    WINBOOL                                        IsLoaded;
    struct {
                   ULONG LogicalSectorSize;
                   ULONG PhysicalSectorSize;
                   WINBOOL  IsRemote;
    } PhysicalDisk;
    ULONG                                          VhdPhysicalSectorSize;
    ULONGLONG                                      SmallestSafeVirtualSize;
    ULONG                                          FragmentationPercentage;
#endif /* _WIN32_WINNT >= 0x0602 */
#if (_WIN32_WINNT >= 0x0603)
    GUID                                           VirtualDiskId;
    struct {
                   WINBOOL Enabled;
                   WINBOOL NewerChanges;
                   WCHAR MostRecentId[1];
    } ChangeTrackingState;
#endif /* _WIN32_WINNT >= 0x0603 */
  } DUMMYUNIONNAME;
} GET_VIRTUAL_DISK_INFO, *PGET_VIRTUAL_DISK_INFO;

typedef struct _MERGE_VIRTUAL_DISK_PARAMETERS {
  MERGE_VIRTUAL_DISK_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   ULONG MergeDepth;
    } Version1;
#if (_WIN32_WINNT >= 0x0602)
    struct {
                   ULONG MergeSourceDepth;
                   ULONG MergeTargetDepth;
    } Version2;
#endif /* _WIN32_WINNT >= 0x0602 */
  } DUMMYUNIONNAME;
} MERGE_VIRTUAL_DISK_PARAMETERS, *PMERGE_VIRTUAL_DISK_PARAMETERS;

typedef struct _OPEN_VIRTUAL_DISK_PARAMETERS {
  OPEN_VIRTUAL_DISK_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   ULONG RWDepth;
    } Version1;
#if (_WIN32_WINNT >= 0x0602)
    struct {
                   WINBOOL GetInfoOnly;
                   WINBOOL ReadOnly;
                   GUID ResiliencyGuid;
    } Version2;
#endif /* _WIN32_WINNT >= 0x0602 */
  } DUMMYUNIONNAME;
} OPEN_VIRTUAL_DISK_PARAMETERS, *POPEN_VIRTUAL_DISK_PARAMETERS;

typedef struct _SET_VIRTUAL_DISK_INFO {
  SET_VIRTUAL_DISK_INFO_VERSION Version;
  __C89_NAMELESS union {
    PCWSTR ParentFilePath;
    GUID   UniqueIdentifier;
#if (_WIN32_WINNT >= 0x0602)
    struct {
                   ULONG  ChildDepth;
                   PCWSTR ParentFilePath;
    } ParentPathWithDepthInfo;
    ULONG  VhdPhysicalSectorSize;
    GUID   VirtualDiskId;
#endif /* _WIN32_WINNT >= 0x0602 */
#if (_WIN32_WINNT >= 0x0603)
    WINBOOL ChangeTrackingEnabled;
    struct {
                   GUID   LinkageId;
                   PCWSTR ParentFilePath;
    } ParentLocator;
#endif /* _WIN32_WINNT >= 0x0603 */
  } DUMMYUNIONNAME;
} SET_VIRTUAL_DISK_INFO, *PSET_VIRTUAL_DISK_INFO;

typedef struct _STORAGE_DEPENDENCY_INFO_TYPE_1 {
  DEPENDENT_DISK_FLAG  DependencyTypeFlags;
  ULONG                                          ProviderSpecificFlags;
  VIRTUAL_STORAGE_TYPE VirtualStorageType;
} STORAGE_DEPENDENCY_INFO_TYPE_1, *PSTORAGE_DEPENDENCY_INFO_TYPE_1;

typedef struct _STORAGE_DEPENDENCY_INFO_TYPE_2 {
  DEPENDENT_DISK_FLAG  DependencyTypeFlags;
  ULONG                                          ProviderSpecificFlags;
  VIRTUAL_STORAGE_TYPE VirtualStorageType;
  ULONG                                          AncestorLevel;
  PWSTR                                          DependencyDeviceName;
  PWSTR                                          HostVolumeName;
  PWSTR                                          DependentVolumeName;
  PWSTR                                          DependentVolumeRelativePath;
} STORAGE_DEPENDENCY_INFO_TYPE_2, *PSTORAGE_DEPENDENCY_INFO_TYPE_2;

/* Fixme: Suppress GCC errors about "error: flexible array member in union" */

typedef struct _STORAGE_DEPENDENCY_INFO {
  STORAGE_DEPENDENCY_INFO_VERSION Version;
  ULONG                                                                               NumberEntries;
  __C89_NAMELESS union {
    STORAGE_DEPENDENCY_INFO_TYPE_1 Version1Entries[1];
    STORAGE_DEPENDENCY_INFO_TYPE_2 Version2Entries[1];
  } DUMMYUNIONNAME;
} STORAGE_DEPENDENCY_INFO, *PSTORAGE_DEPENDENCY_INFO;

typedef struct _VIRTUAL_DISK_PROGRESS {
  DWORD     OperationStatus;
  ULONGLONG CurrentValue;
  ULONGLONG CompletionValue;
} VIRTUAL_DISK_PROGRESS, *PVIRTUAL_DISK_PROGRESS;

#if (_WIN32_WINNT >= 0x0602)

typedef struct _MIRROR_VIRTUAL_DISK_PARAMETERS {
  MIRROR_VIRTUAL_DISK_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   PCWSTR MirrorVirtualDiskPath;
    } Version1;
  } DUMMYUNIONNAME;
} MIRROR_VIRTUAL_DISK_PARAMETERS, *PMIRROR_VIRTUAL_DISK_PARAMETERS;

typedef struct _RESIZE_VIRTUAL_DISK_PARAMETERS {
  RESIZE_VIRTUAL_DISK_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   ULONGLONG NewSize;
    } Version1;
  } DUMMYUNIONNAME;
} RESIZE_VIRTUAL_DISK_PARAMETERS, *PRESIZE_VIRTUAL_DISK_PARAMETERS;

#endif /* _WIN32_WINNT >= 0x0602 */

#if (_WIN32_WINNT >= 0x0A00)

typedef struct _APPLY_SNAPSHOT_VHDSET_PARAMETERS {
  APPLY_SNAPSHOT_VHDSET_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   GUID  SnapshotId;
                   GUID  LeafSnapshotId;
    } Version1;
  } DUMMYUNIONNAME;
} APPLY_SNAPSHOT_VHDSET_PARAMETERS, *PAPPLY_SNAPSHOT_VHDSET_PARAMETERS;

typedef struct _DELETE_SNAPSHOT_VHDSET_PARAMETERS {
  DELETE_SNAPSHOT_VHDSET_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   GUID SnapshotId;
    } Version1;
  } DUMMYUNIONNAME;
} DELETE_SNAPSHOT_VHDSET_PARAMETERS, *PDELETE_SNAPSHOT_VHDSET_PARAMETERS;

typedef struct _MODIFY_VHDSET_PARAMETERS {
  MODIFY_VHDSET_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   GUID   SnapshotId;
                   PCWSTR SnapshotFilePath;
    } SnapshotPath;
    GUID   SnapshotId;
    PCWSTR DefaultFilePath;
  } DUMMYUNIONNAME;
} MODIFY_VHDSET_PARAMETERS, *PMODIFY_VHDSET_PARAMETERS;

typedef struct _QUERY_CHANGES_VIRTUAL_DISK_RANGE {
  ULONG64 ByteOffset;
  ULONG64 ByteLength;
  ULONG64 Reserved;
} QUERY_CHANGES_VIRTUAL_DISK_RANGE, *PQUERY_CHANGES_VIRTUAL_DISK_RANGE;

typedef struct _TAKE_SNAPSHOT_VHDSET_PARAMETERS {
  TAKE_SNAPSHOT_VHDSET_VERSION Version;
  __C89_NAMELESS union {
    struct {
                   GUID SnapshotId;
    } Version1;
  } DUMMYUNIONNAME;
} TAKE_SNAPSHOT_VHDSET_PARAMETERS, *PTAKE_SNAPSHOT_VHDSET_PARAMETERS;

#endif /* _WIN32_WINNT >= 0x0A00 */

DEFINE_GUID(VIRTUAL_STORAGE_TYPE_VENDOR_UNKNOWN,0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
DEFINE_GUID(VIRTUAL_STORAGE_TYPE_VENDOR_MICROSOFT,0xEC984AEC,0xA0F9,0x47e9,0x90,0x1F,0x71,0x41,0x5A,0x66,0x34,0x5B);

VIRTDISKAPI DWORD WINAPI AttachVirtualDisk(HANDLE VirtualDiskHandle, PSECURITY_DESCRIPTOR SecurityDescriptor, ATTACH_VIRTUAL_DISK_FLAG Flags, ULONG ProviderSpecificFlags, PATTACH_VIRTUAL_DISK_PARAMETERS Parameters, LPOVERLAPPED Overlapped);
VIRTDISKAPI DWORD WINAPI CompactVirtualDisk(HANDLE VirtualDiskHandle, COMPACT_VIRTUAL_DISK_FLAG Flags, PCOMPACT_VIRTUAL_DISK_PARAMETERS Parameters, LPOVERLAPPED Overlapped);
VIRTDISKAPI DWORD WINAPI CreateVirtualDisk(PVIRTUAL_STORAGE_TYPE VirtualStorageType, PCWSTR Path, VIRTUAL_DISK_ACCESS_MASK VirtualDiskAccessMask, PSECURITY_DESCRIPTOR SecurityDescriptor, CREATE_VIRTUAL_DISK_FLAG Flags, ULONG ProviderSpecificFlags, PCREATE_VIRTUAL_DISK_PARAMETERS Parameters, LPOVERLAPPED Overlapped, PHANDLE Handle);
VIRTDISKAPI DWORD WINAPI DetachVirtualDisk(HANDLE VirtualDiskHandle, DETACH_VIRTUAL_DISK_FLAG Flags, ULONG ProviderSpecificFlags);
VIRTDISKAPI DWORD WINAPI ExpandVirtualDisk(HANDLE VirtualDiskHandle, EXPAND_VIRTUAL_DISK_FLAG Flags, PEXPAND_VIRTUAL_DISK_PARAMETERS Parameters, LPOVERLAPPED Overlapped);
VIRTDISKAPI DWORD WINAPI GetStorageDependencyInformation(HANDLE ObjectHandle, GET_STORAGE_DEPENDENCY_FLAG Flags, ULONG StorageDependencyInfoSize, PSTORAGE_DEPENDENCY_INFO StorageDependencyInfo, PULONG SizeUsed);
VIRTDISKAPI DWORD WINAPI GetVirtualDiskInformation(HANDLE VirtualDiskHandle, PULONG VirtualDiskInfoSize, PGET_VIRTUAL_DISK_INFO VirtualDiskInfo, PULONG SizeUsed);
VIRTDISKAPI DWORD WINAPI GetVirtualDiskOperationProgress(HANDLE VirtualDiskHandle, LPOVERLAPPED Overlapped, PVIRTUAL_DISK_PROGRESS Progress);
VIRTDISKAPI DWORD WINAPI GetVirtualDiskPhysicalPath(HANDLE VirtualDiskHandle, PULONG DiskPathSizeInBytes, PWSTR DiskPath);
VIRTDISKAPI DWORD WINAPI MergeVirtualDisk(HANDLE VirtualDiskHandle, MERGE_VIRTUAL_DISK_FLAG Flags, PMERGE_VIRTUAL_DISK_PARAMETERS Parameters, LPOVERLAPPED Overlapped);
VIRTDISKAPI DWORD WINAPI OpenVirtualDisk(PVIRTUAL_STORAGE_TYPE VirtualStorageType, PCWSTR Path, VIRTUAL_DISK_ACCESS_MASK VirtualDiskAccessMask, OPEN_VIRTUAL_DISK_FLAG Flags, POPEN_VIRTUAL_DISK_PARAMETERS Parameters, PHANDLE Handle);
VIRTDISKAPI DWORD WINAPI SetVirtualDiskInformation(HANDLE VirtualDiskHandle, PSET_VIRTUAL_DISK_INFO VirtualDiskInfo);

#if (_WIN32_WINNT >= 0x0602)

VIRTDISKAPI DWORD WINAPI AddVirtualDiskParent(HANDLE VirtualDiskHandle, PCWSTR ParentPath);
VIRTDISKAPI DWORD WINAPI BreakMirrorVirtualDisk(HANDLE VirtualDiskHandle);
VIRTDISKAPI DWORD WINAPI DeleteVirtualDiskMetadata(HANDLE VirtualDiskHandle, LPGUID Item);
VIRTDISKAPI DWORD WINAPI EnumerateVirtualDiskMetadata(HANDLE VirtualDiskHandle, PULONG NumberOfItems, GUID *Items);
VIRTDISKAPI DWORD WINAPI GetVirtualDiskMetadata(HANDLE VirtualDiskHandle, LPGUID Item, PULONG MetaDataSize, PVOID MetaData);
VIRTDISKAPI DWORD WINAPI MirrorVirtualDisk(HANDLE VirtualDiskHandle, MIRROR_VIRTUAL_DISK_FLAG Flags, PMIRROR_VIRTUAL_DISK_PARAMETERS Parameters, LPOVERLAPPED Overlapped);
VIRTDISKAPI DWORD WINAPI ResizeVirtualDisk(HANDLE VirtualDiskHandle, RESIZE_VIRTUAL_DISK_FLAG Flags, PRESIZE_VIRTUAL_DISK_PARAMETERS Parameters, LPOVERLAPPED Overlapped);
VIRTDISKAPI DWORD WINAPI SetVirtualDiskMetadata(HANDLE VirtualDiskHandle, LPGUID Item, ULONG MetaDataSize, PVOID MetaData);

#endif /* _WIN32_WINNT >= 0x0602 */

#if (_WIN32_WINNT >= 0x0A00)

VIRTDISKAPI DWORD WINAPI ApplySnapshotVhdSet(HANDLE VirtualDiskHandle, const PAPPLY_SNAPSHOT_VHDSET_PARAMETERS Parameters, APPLY_SNAPSHOT_VHDSET_FLAG Flags);
VIRTDISKAPI DWORD WINAPI DeleteSnapshotVhdSet(HANDLE VirtualDiskHandle, const PDELETE_SNAPSHOT_VHDSET_PARAMETERS Parameters, DELETE_SNAPSHOT_VHDSET_FLAG Flags);
VIRTDISKAPI DWORD WINAPI ModifyVhdSet(HANDLE VirtualDiskHandle, const PMODIFY_VHDSET_PARAMETERS Parameters, MODIFY_VHDSET_FLAG Flags);
VIRTDISKAPI DWORD WINAPI QueryChangesVirtualDisk(HANDLE VirtualDiskHandle, PCWSTR ChangeTrackingId, ULONG64 ByteOffset, ULONG64 ByteLength, QUERY_CHANGES_VIRTUAL_DISK_FLAG Flags, PQUERY_CHANGES_VIRTUAL_DISK_RANGE Ranges, PULONG RangeCount, PULONG64 ProcessedLength);
VIRTDISKAPI WINAPI DWORD TakeSnapshotVhdSet(HANDLE VirtualDiskHandle, const PTAKE_SNAPSHOT_VHDSET_PARAMETERS Parameters, TAKE_SNAPSHOT_VHDSET_FLAG Flags);

#endif /* _WIN32_WINNT >= 0x0A00 */
#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /*_INC_VIRTDISK*/
