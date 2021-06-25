/// @file
/// @brief Contains #add_last_arg_to_command_ macro.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#ifndef add_last_arg_to_command_
/// @cond
#define __add_last_arg_to_command1_args__(command, last_arg, arg1) command(arg1, last_arg)
#define __add_last_arg_to_command2_args__(command, last_arg, arg1, arg2) command(arg1, arg2, last_arg)
#define __add_last_arg_to_command3_args__(command, last_arg, arg1, arg2, arg3) command(arg1, arg2, arg3, last_arg)
#define __add_last_arg_to_command4_args__(command, last_arg, arg1, arg2, arg3, arg4) command(arg1, arg2, arg3, arg4, last_arg)
#define __add_last_arg_to_command5_args__(command, last_arg, arg1, arg2, arg3, arg4, arg5) command(arg1, arg2, arg3, arg4, arg5, last_arg)
#define __add_last_arg_to_command6_args__(command, last_arg, arg1, arg2, arg3, arg4, arg5, arg6) command(arg1, arg2, arg3, arg4, arg5, arg6, last_arg)
#define __add_last_arg_to_command7_args__(command, last_arg, arg1, arg2, arg3, arg4, arg5, arg6, arg7) command(arg1, arg2, arg3, arg4, arg5, arg6, arg7, last_arg)
#define __add_last_arg_to_command8_args__(command, last_arg, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) command(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, last_arg)
#define __add_last_arg_to_command9_args__(command, last_arg, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) command(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, last_arg)
#define __add_last_arg_to_command10_args__(command, last_arg, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) command(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, last_arg)
#define __get_add_last_arg_to_command_maximum_args__(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, ...) arg11
#define __add_last_arg_to_command_chooser__(command, last_arg, ...) __get_add_last_arg_to_command_maximum_args__(__VA_ARGS__, __add_last_arg_to_command10_args__, __add_last_arg_to_command9_args__, __add_last_arg_to_command8_args__, __add_last_arg_to_command7_args__, __add_last_arg_to_command6_args__, __add_last_arg_to_command5_args__, __add_last_arg_to_command4_args__, __add_last_arg_to_command3_args__, __add_last_arg_to_command2_args__, __add_last_arg_to_command1_args__, )
/// @endcond

/// @brief Adds last argument to a command with variadic arguments.
/// @param command The variadic arguments command.
/// @param last_arg The last argument to add to variadic arguments
/// @param ... Variadic arguments.
/// @par Library
/// xtd.core
/// @ingroup xtd_core
/// @remarks This macro is use specificaly for add current stack frame to but not only.
/// @warning The variadic arguments is limited to maximum 10 arguments.
/// @see #assert_ or #cassert_ mecro for example of use.
#define add_last_arg_to_command_(command, last_arg, ...) \
  __add_last_arg_to_command_chooser__(command, last_arg, __VA_ARGS__)(command, last_arg, __VA_ARGS__)
#endif
