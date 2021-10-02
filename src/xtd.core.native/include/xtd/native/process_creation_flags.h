
/// @file
/// @brief Contains process creation flags.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

#if !defined (DEBUG_PROCESS)
/// @brief The calling thread starts and debugs the new process and all child processes created by the new process. It can receive all related debug events using the WaitForDebugEvent function.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DEBUG_PROCESS = 0x00000001;
/// @brief The calling thread starts and debugs the new process. It can receive all related debug events using the WaitForDebugEvent function.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DEBUG_ONLY_THIS_PROCESS = 0x00000002;
/// @brief The primary thread of the new process is created in a suspended state, and does not run until the ResumeThread function is called.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_SUSPENDED = 0x00000004;
/// @brief For console processes, the new process does not inherit its parent's console (the default). The new process can call the AllocConsole function at a later time to create a console. For more information, see Creation of a Console.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DETACHED_PROCESS = 0x00000008;
/// @brief The new process has a new console, instead of inheriting its parent's console (the default). For more information, see Creation of a Console.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_NEW_CONSOLE = 0x00000010;
/// @brief The new process is the root process of a new process group. The process group includes all processes that are descendants of this root process. The process identifier of the new process group is the same as the process identifier, which is returned in the lpProcessInformation parameter. Process groups are used by the GenerateConsoleCtrlEvent function to enable sending a CTRL+BREAK signal to a group of console processes.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_NEW_PROCESS_GROUP = 0x00000200;
/// @brief If this flag is set, the environment block pointed to by lpEnvironment uses Unicode characters. Otherwise, the environment block uses ANSI characters.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_UNICODE_ENVIRONMENT = 0x00000400;
/// @brief This flag is valid only when starting a 16-bit Windows-based application. If set, the new process runs in a private Virtual DOS Machine (VDM). By default, all 16-bit Windows-based applications run as threads in a single, shared VDM. The advantage of running separately is that a crash only terminates the single VDM; any other programs running in distinct VDMs continue to function normally. Also, 16-bit Windows-based applications that are run in separate VDMs have separate input queues. That means that if one application stops responding momentarily, applications in separate VDMs continue to receive input. The disadvantage of running separately is that it takes significantly more memory to do so. You should use this flag only if the user requests that 16-bit applications should run in their own VDM.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_SEPARATE_WOW_VDM = 0x00000800;
/// @brief The flag is valid only when starting a 16-bit Windows-based application. If the
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_SHARED_WOW_VDM = 0x00001000;
/// @brief The process inherits its parent's affinity. If the parent process has threads in more than one processor group, the new process inherits the group-relative affinity of an arbitrary group in use by the parent.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t INHERIT_PARENT_AFFINITY = 0x00010000;
/// @brief The process is to be run as a protected process. The system restricts access to protected processes and the threads of protected processes. For more information on how processes can interact with protect
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_PROTECTED_PROCESS = 0x00040000;
/// @brief The process is created with extended startup information; the lpStartupInfo parameter specifies a STARTUPINFOEX structure.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t EXTENDED_STARTUPINFO_PRESENT = 0x00080000;
/// @brief This flag allows secure processes, that run in the Virtualization-Based Security environment, to launch.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_SECURE_PROCESS = 0x00400000;
/// @brief The child processes of a process associated with a job are not associated with the job.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_BREAKAWAY_FROM_JOB = 0x01000000;
/// @brief Allows the caller to execute a child process that bypasses the process restrictions that would normally be applied automatically to the process.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_PRESERVE_CODE_AUTHZ_LEVEL = 0x02000000;
/// @brief The new process does not inherit the error mode of the calling process. Instead, the new process gets the default error mode.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_DEFAULT_ERROR_MODE = 0x04000000;
/// @brief The process is a console application that is being run without a console window. Therefore, the console handle for the application is not set.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pcf
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CREATE_NO_WINDOW = 0x08000000;
#endif
