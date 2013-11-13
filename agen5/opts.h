/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (opts.h)
 *
 *  It has been AutoGen-ed  November 13, 2013 at 07:04:42 PM by AutoGen 5.18.1
 *  From the definitions    opts.def
 *  and the template file   options
 *
 * Generated from AutoOpts 40:1:15 templates.
 *
 *  AutoOpts is a copyrighted work.  This header file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the autogen author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The autogen program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 1992-2013 Bruce Korb, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the GNU General Public License,
 *  version 3 or later <http://gnu.org/licenses/gpl.html>
 *
 *  autogen is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  autogen is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/** \file opts.h
 *  \addtogroup autogen
 *  @{
 */
/**
 *  This file contains the programmatic interface to the Automated
 *  Options generated for the autogen program.
 *  These macros are documented in the AutoGen info file in the
 *  "AutoOpts" chapter.  Please refer to that doc for usage help.
 */
#ifndef AUTOOPTS_OPTS_H_GUARD
#define AUTOOPTS_OPTS_H_GUARD 1
#include "config.h"
#include <autoopts/options.h>
#include <stdarg.h>

/**
 *  Ensure that the library used for compiling this generated header is at
 *  least as new as the version current when the header template was released
 *  (not counting patch version increments).  Also ensure that the oldest
 *  tolerable version is at least as old as what was current when the header
 *  template was released.
 */
#define AO_TEMPLATE_VERSION 163841
#if (AO_TEMPLATE_VERSION < OPTIONS_MINIMUM_VERSION) \
 || (AO_TEMPLATE_VERSION > OPTIONS_STRUCT_VERSION)
# error option template version mismatches autoopts/options.h header
  Choke Me.
#endif

/**
 *  Enumeration of each option type for autogen
 */
typedef enum {
    INDEX_OPT_TEMPL_DIRS     =  1,
    INDEX_OPT_OVERRIDE_TPL   =  2,
    INDEX_OPT_LIB_TEMPLATE   =  3,
    INDEX_OPT_DEFINITIONS    =  4,
    INDEX_OPT_SHELL          =  5,
    INDEX_OPT_NO_FMEMOPEN    =  6,
    INDEX_OPT_EQUATE         =  7,
    INDEX_OPT_BASE_NAME      =  9,
    INDEX_OPT_SOURCE_TIME    = 10,
    INDEX_OPT_WRITABLE       = 11,
    INDEX_OPT_LOOP_LIMIT     = 13,
    INDEX_OPT_TIMEOUT        = 14,
    INDEX_OPT_TRACE          = 15,
    INDEX_OPT_TRACE_OUT      = 16,
    INDEX_OPT_SHOW_DEFS      = 17,
    INDEX_OPT_USED_DEFINES   = 18,
    INDEX_OPT_CORE           = 19,
    INDEX_OPT_SKIP_SUFFIX    = 21,
    INDEX_OPT_SELECT_SUFFIX  = 22,
    INDEX_OPT_DEFINE         = 23,
    INDEX_OPT_UNDEFINE       = 24,
    INDEX_OPT_MAKE_DEP       = 26,
    INDEX_OPT_RESET_OPTION   = 28,
    INDEX_OPT_VERSION        = 29,
    INDEX_OPT_HELP           = 30,
    INDEX_OPT_MORE_HELP      = 31,
    INDEX_OPT_USAGE          = 32,
    INDEX_OPT_SAVE_OPTS      = 33,
    INDEX_OPT_LOAD_OPTS      = 34
} teOptIndex;
/** count of all options for autogen */
#define OPTION_CT    35
/** autogen version */
#define AUTOGEN_VERSION       "5.18.1"
/** Full autogen version text */
#define AUTOGEN_FULL_VERSION  "autogen (GNU AutoGen) 5.18.1"

/**
 *  Interface defines for all options.  Replace "n" with the UPPER_CASED
 *  option name (as in the teOptIndex enumeration above).
 *  e.g. HAVE_OPT(INPUT_SELECT)
 */
#define         DESC(n) (autogenOptions.pOptDesc[INDEX_OPT_## n])
/** 'true' if an option has been specified in any way */
#define     HAVE_OPT(n) (! UNUSED_OPT(& DESC(n)))
/** The string argument to an option. The argument type must be \"string\". */
#define      OPT_ARG(n) (DESC(n).optArg.argString)
/** Mask the option state revealing how an option was specified.
 *  It will be one and only one of \a OPTST_SET, \a OPTST_PRESET,
 * \a OPTST_DEFINED, \a OPTST_RESET or zero.
 */
#define    STATE_OPT(n) (DESC(n).fOptState & OPTST_SET_MASK)
/** Count of option's occurrances *on the command line*. */
#define    COUNT_OPT(n) (DESC(n).optOccCt)
/** mask of \a OPTST_SET and \a OPTST_DEFINED. */
#define    ISSEL_OPT(n) (SELECTED_OPT(&DESC(n)))
/** 'true' if \a HAVE_OPT would yield 'false'. */
#define ISUNUSED_OPT(n) (UNUSED_OPT(& DESC(n)))
/** 'true' if OPTST_DISABLED bit not set. */
#define  ENABLED_OPT(n) (! DISABLED_OPT(& DESC(n)))
/** number of stacked option arguments.
 *  Valid only for stacked option arguments. */
#define  STACKCT_OPT(n) (((tArgList*)(DESC(n).optCookie))->useCt)
/** stacked argument vector.
 *  Valid only for stacked option arguments. */
#define STACKLST_OPT(n) (((tArgList*)(DESC(n).optCookie))->apzArgs)
/** Reset an option. */
#define    CLEAR_OPT(n) STMTS( \
                DESC(n).fOptState &= OPTST_PERSISTENT_MASK;   \
                if ((DESC(n).fOptState & OPTST_INITENABLED) == 0) \
                    DESC(n).fOptState |= OPTST_DISABLED; \
                DESC(n).optCookie = NULL )
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 *  Enumeration of autogen exit codes
 */
typedef enum {
    AUTOGEN_EXIT_SUCCESS         = 0,
    AUTOGEN_EXIT_OPTION_ERROR    = 1,
    AUTOGEN_EXIT_BAD_TEMPLATE    = 2,
    AUTOGEN_EXIT_BAD_DEFINITIONS = 3,
    AUTOGEN_EXIT_LOAD_ERROR      = 4,
    AUTOGEN_EXIT_SIGNAL          = 128,
    AUTOGEN_EXIT_USAGE_ERROR     = 64,
    AUTOGEN_EXIT_NO_CONFIG_INPUT = 66,
    AUTOGEN_EXIT_LIBOPTS_FAILURE = 70
}   autogen_exit_code_t;
/**
 *  Interface defines for specific options.
 * @{
 */
#define VALUE_OPT_TEMPL_DIRS     'L'

#define SET_OPT_TEMPL_DIRS(a)   STMTS( \
        DESC(TEMPL_DIRS).optActualIndex = 1; \
        DESC(TEMPL_DIRS).optActualValue = VALUE_OPT_TEMPL_DIRS; \
        DESC(TEMPL_DIRS).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(TEMPL_DIRS).fOptState |= OPTST_SET; \
        DESC(TEMPL_DIRS).optArg.argString = (a); \
        (*(DESC(TEMPL_DIRS).pOptProc))(&autogenOptions, \
                autogenOptions.pOptDesc + 1); )
#define VALUE_OPT_OVERRIDE_TPL   'T'
#define VALUE_OPT_LIB_TEMPLATE   'l'
#define VALUE_OPT_DEFINITIONS    0x1001

#define SET_OPT_DEFINITIONS(a)   STMTS( \
        DESC(DEFINITIONS).optActualIndex = 4; \
        DESC(DEFINITIONS).optActualValue = VALUE_OPT_DEFINITIONS; \
        DESC(DEFINITIONS).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(DEFINITIONS).fOptState |= OPTST_SET; \
        DESC(DEFINITIONS).optArg.argString = (a) )
#define DISABLE_OPT_DEFINITIONS   STMTS( \
        DESC(DEFINITIONS).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(DEFINITIONS).fOptState |= OPTST_SET | OPTST_DISABLED; \
        DESC(DEFINITIONS).optArg.argString = NULL )
#define VALUE_OPT_SHELL          0x1002
#define VALUE_OPT_NO_FMEMOPEN    'm'
#define VALUE_OPT_EQUATE         0x1003
#define VALUE_OPT_BASE_NAME      'b'
#define VALUE_OPT_SOURCE_TIME    0x1004
#define VALUE_OPT_WRITABLE       0x1005

#define SET_OPT_WRITABLE   STMTS( \
        DESC(WRITABLE).optActualIndex = 11; \
        DESC(WRITABLE).optActualValue = VALUE_OPT_WRITABLE; \
        DESC(WRITABLE).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(WRITABLE).fOptState |= OPTST_SET )
#define DISABLE_OPT_WRITABLE   STMTS( \
        DESC(WRITABLE).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(WRITABLE).fOptState |= OPTST_SET | OPTST_DISABLED; \
        DESC(WRITABLE).optArg.argString = NULL )
#define VALUE_OPT_LOOP_LIMIT     0x1006

#define OPT_VALUE_LOOP_LIMIT     (DESC(LOOP_LIMIT).optArg.argInt)
#define VALUE_OPT_TIMEOUT        't'
#ifdef SHELL_ENABLED
#define OPT_VALUE_TIMEOUT        (DESC(TIMEOUT).optArg.argInt)
#endif /* SHELL_ENABLED */
#define VALUE_OPT_TRACE          0x1007

typedef enum {
    TRACE_NOTHING,         TRACE_DEBUG_MESSAGE,   TRACE_SERVER_SHELL,
    TRACE_TEMPLATES,       TRACE_BLOCK_MACROS,    TRACE_EXPRESSIONS,
    TRACE_EVERYTHING
} te_Trace;
#define OPT_TRACE_VAL2STR(_v)    optionKeywordName(&DESC(TRACE), (_v))
#define OPT_VALUE_TRACE          (DESC(TRACE).optArg.argEnum)
#define VALUE_OPT_TRACE_OUT      0x1008
#define VALUE_OPT_SHOW_DEFS      0x1009
#define VALUE_OPT_USED_DEFINES   0x100A
#define VALUE_OPT_CORE           'C'
#define VALUE_OPT_SKIP_SUFFIX    's'
#define VALUE_OPT_SELECT_SUFFIX  'o'
#define VALUE_OPT_DEFINE         'D'

#define SET_OPT_DEFINE(a)   STMTS( \
        DESC(DEFINE).optActualIndex = 23; \
        DESC(DEFINE).optActualValue = VALUE_OPT_DEFINE; \
        DESC(DEFINE).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(DEFINE).fOptState |= OPTST_SET; \
        DESC(DEFINE).optArg.argString = (a); \
        (*(DESC(DEFINE).pOptProc))(&autogenOptions, \
                autogenOptions.pOptDesc + 23); )
#define VALUE_OPT_UNDEFINE       'U'

#define SET_OPT_UNDEFINE(a)   STMTS( \
        DESC(DEFINE).optActualIndex = 24; \
        DESC(DEFINE).optActualValue = VALUE_OPT_UNDEFINE; \
        DESC(DEFINE).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(DEFINE).fOptState |= OPTST_SET | OPTST_EQUIVALENCE; \
        DESC(DEFINE).optArg.argString = (a); \
        (*(DESC(UNDEFINE).pOptProc))(&autogenOptions, \
                autogenOptions.pOptDesc + INDEX_OPT_DEFINE); )
#define VALUE_OPT_MAKE_DEP       'M'

#define SET_OPT_MAKE_DEP(a)   STMTS( \
        DESC(MAKE_DEP).optActualIndex = 26; \
        DESC(MAKE_DEP).optActualValue = VALUE_OPT_MAKE_DEP; \
        DESC(MAKE_DEP).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(MAKE_DEP).fOptState |= OPTST_SET; \
        DESC(MAKE_DEP).optArg.argString = (a); \
        (*(DESC(MAKE_DEP).pOptProc))(&autogenOptions, \
                autogenOptions.pOptDesc + 26); )
/** option flag (value) for " (get "val-name") " option */
#define VALUE_OPT_HELP          '?'
/** option flag (value) for " (get "val-name") " option */
#define VALUE_OPT_MORE_HELP     '!'
/** option flag (value) for " (get "val-name") " option */
#define VALUE_OPT_RESET_OPTION  'R'
/** option flag (value) for " (get "val-name") " option */
#define VALUE_OPT_VERSION       'v'
/** option flag (value) for " (get "val-name") " option */
#define VALUE_OPT_USAGE         'u'
/** option flag (value) for " (get "val-name") " option */
#define VALUE_OPT_SAVE_OPTS     '>'
/** option flag (value) for " (get "val-name") " option */
#define VALUE_OPT_LOAD_OPTS     '<'
#define SET_OPT_SAVE_OPTS(a)   STMTS( \
        DESC(SAVE_OPTS).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(SAVE_OPTS).fOptState |= OPTST_SET; \
        DESC(SAVE_OPTS).optArg.argString = (char const*)(a))
/*
 *  Interface defines not associated with particular options
 */
#define ERRSKIP_OPTERR  STMTS(autogenOptions.fOptSet &= ~OPTPROC_ERRSTOP)
#define ERRSTOP_OPTERR  STMTS(autogenOptions.fOptSet |= OPTPROC_ERRSTOP)
#define RESTART_OPT(n)  STMTS( \
                autogenOptions.curOptIdx = (n); \
                autogenOptions.pzCurOpt  = NULL )
#define START_OPT       RESTART_OPT(1)
#define USAGE(c)        (*autogenOptions.pUsageProc)(&autogenOptions, c)

#ifdef  __cplusplus
extern "C" {
#endif
/*
 *  global exported definitions
 */
extern char const * tpl_fname;
extern bool      trace_is_to_pipe;


/* * * * * *
 *
 *  Declare the autogen option descriptor.
 */
extern tOptions autogenOptions;
# define OPT_NO_XLAT_CFG_NAMES
# define OPT_NO_XLAT_OPT_NAMES

# define OPT_XLAT_CFG_NAMES
# define OPT_XLAT_OPT_NAMES

# ifndef _
#   define _(_s)  _s
# endif
#ifndef  noreturn
# define noreturn
#endif

extern noreturn void vusage_message(char const * fmt, va_list ap);
extern noreturn void usage_message(char const * fmt, ...);
#ifdef  __cplusplus
}
#endif
#endif /* AUTOOPTS_OPTS_H_GUARD */

/** @} */
/* opts.h ends here */
