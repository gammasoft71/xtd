
/// @file
/// @brief Contains console special key constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal used only"
#endif
/// @endcond

#include <cstdint>

#if !defined(FILE_ATTRIBUTE_READONLY)
/// @brief The file is read-only.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_READONLY = 0x0001;
/// @brief The file is hidden, and thus is not included in an ordinary directory listing.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_HIDDEN = 0x0002;
/// @brief The file is a system file. The file is part of the operating system or is used exclusively by the operating system.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_SYSTEM = 0x0004;
/// @brief The file is a directory.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_DIRECTORY = 0x0010;
/// @brief The file's archive status. Applications use this attribute to mark files for backup or removal.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_ARCHIVE = 0x0020;
/// @brief Reserved for future use.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_DEVICE = 0x0040;
/// @brief The file is normal and has no other attributes set. This attribute is valid only if used alone.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_NORMAL = 0x0080;
/// @brief The file is temporary. File systems attempt to keep all of the data in memory for quicker access rather than flushing the data back to mass storage. A temporary file should be deleted by the application as soon as it is no longer needed.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_TEMPORARY = 0x0100;
/// @brief The file is a sparse file. Sparse files are typically large files whose data are mostly zeros.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_SPARSE_FILE = 0x0200;
/// @brief The file contains a reparse point, which is a block of user-defined data associated with a file or a directory.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_REPARSE_POINT = 0x0400;
/// @brief The file is compressed.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_COMPRESSED = 0x0800;
/// @brief The file is offline. The data of the file is not immediately available.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_OFFLINE = 0x1000;
/// @brief The file will not be indexed by the operating system's content indexing service.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_NOT_CONTENT_INDEXED = 0x2000;
/// @brief The file or directory is encrypted. For a file, this means that all data in the file is encrypted. For a directory, this means that encryption is the default for newly created files and directories.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_ENCRYPTED = 0x4000;
/// @brief The directory or user data stream is configured with integrity (only supported on ReFS volumes). It is not included in an ordinary directory listing. The integrity setting persists with the file if it's renamed. If a file is copied the destination file will have integrity set if either the source file or destination directory have integrity set.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_INTEGRITY_STREAM = 0x00008000;
/// @brief This value is reserved for system use.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_VIRTUAL = 0x00010000;
/// @brief The user data stream not to be read by the background data integrity scanner (AKA scrubber). When set on a directory it only provides inheritance. This flag is only supported on Storage Spaces and ReFS volumes. It is not included in an ordinary directory listing.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_NO_SCRUB_DATA = 0x00020000;
/// @brief (Not documented).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_EA = 0x00040000;
/// @brief (Not documented).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_PINNED = 0x00080000;
/// @brief (Not documented).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_UNPINNED = 0x00100000;
/// @brief This attribute only appears in directory enumeration classes (FILE_DIRECTORY_INFORMATION, FILE_BOTH_DIR_INFORMATION, etc.). When this attribute is set, it means that the file or directory has no physical representation on the local system; the item is virtual. Opening the item will be more expensive than normal, e.g. it will cause at least some of it to be fetched from a remote store.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_RECALL_ON_OPEN = 0x00040000;
/// @brief When this attribute is set, it means that the file or directory is not fully present locally. For a file that means that not all of its data is on local storage (e.g. it may be sparse with some data still in remote storage). For a directory it means that some of the directory contents are being virtualized from another location. Reading the file / enumerating the directory will be more expensive than normal, e.g. it will cause at least some of the file/directory content to be fetched from a remote store. Only kernel-mode callers can set this bit.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native file_attributes
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS = 0x00400000;
#endif
