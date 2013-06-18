/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (opts.c)
 *
 *  It has been AutoGen-ed  June 18, 2013 at 09:43:38 PM by AutoGen 5.17.4
 *  From the definitions    ./opts.def
 *  and the template file   options
 *
 * Generated from AutoOpts 39:0:14 templates.
 *
 *  AutoOpts is a copyrighted work.  This source file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the getdefs author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The getdefs program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 1999-2012 Bruce Korb, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the GNU General Public License,
 *  version 3 or later <http://gnu.org/licenses/gpl.html>
 *
 *  getdefs is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  getdefs is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/** \file opts.c
 *  \addtogroup getdefs
 *  @{
 */

#ifndef __doxygen__
#define OPTION_CODE_COMPILE 1
#include "opts.h"
#include <sys/types.h>

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef  __cplusplus
extern "C" {
#endif
extern FILE * option_usage_fp;
#define zCopyright      (getdefs_opt_strs+0)
#define zLicenseDescrip (getdefs_opt_strs+268)


#ifndef NULL
#  define NULL 0
#endif

/**
 *  static const strings for getdefs options
 */
static char const getdefs_opt_strs[2640] =
/*     0 */ "getdefs (GNU AutoGen) 1.5\n"
            "Copyright (C) 1999-2012 Bruce Korb, all rights reserved.\n"
            "This is free software. It is licensed for use, modification and\n"
            "redistribution under the terms of the GNU General Public License,\n"
            "version 3 or later <http://gnu.org/licenses/gpl.html>\n\0"
/*   268 */ "getdefs is free software: you can redistribute it and/or modify it under\n"
            "the terms of the GNU General Public License as published by the Free\n"
            "Software Foundation, either version 3 of the License, or (at your option)\n"
            "any later version.\n\n"
            "getdefs is distributed in the hope that it will be useful, but WITHOUT ANY\n"
            "WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS\n"
            "FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more\n"
            "details.\n\n"
            "You should have received a copy of the GNU General Public License along\n"
            "with this program.  If not, see <http://www.gnu.org/licenses/>.\n\0"
/*   871 */ "Specify which definitions are of interest and what to say about them:\0"
/*   941 */ "Regexp to look for after the \"/*=\"\0"
/*   976 */ "DEFS_TO_GET\0"
/*   988 */ "defs-to-get\0"
/*  1000 */ "subblock definition names\0"
/*  1026 */ "SUBBLOCK\0"
/*  1035 */ "subblock\0"
/*  1044 */ "attribute with list of values\0"
/*  1074 */ "LISTATTR\0"
/*  1083 */ "listattr\0"
/*  1092 */ "specify how to number the definitions:\0"
/*  1131 */ "Alphabetize or use named file\0"
/*  1161 */ "ORDERING\0"
/*  1170 */ "no-ordering\0"
/*  1182 */ "no\0"
/*  1185 */ "The first index to apply to groups\0"
/*  1220 */ "FIRST_INDEX\0"
/*  1232 */ "first-index\0"
/*  1244 */ "Definition insertion options:\0"
/*  1274 */ "Insert source file names into defs\0"
/*  1309 */ "FILELIST\0"
/*  1318 */ "filelist\0"
/*  1327 */ "Global assignments\0"
/*  1346 */ "ASSIGN\0"
/*  1353 */ "assign\0"
/*  1360 */ "Assignments common to all blocks\0"
/*  1393 */ "COMMON_ASSIGN\0"
/*  1407 */ "common-assign\0"
/*  1421 */ "File(s) to copy into definitions\0"
/*  1454 */ "COPY\0"
/*  1459 */ "copy\0"
/*  1464 */ "Insert source file name into each def\0"
/*  1502 */ "SRCFILE\0"
/*  1510 */ "srcfile\0"
/*  1518 */ "Insert source line number into each def\0"
/*  1558 */ "LINENUM\0"
/*  1566 */ "linenum\0"
/*  1574 */ "specify which files to search for markers:\0"
/*  1617 */ "Input file to search for defs\0"
/*  1647 */ "INPUT\0"
/*  1653 */ "input\0"
/*  1659 */ "Definition output disposition options::\0"
/*  1699 */ "Output file to open\0"
/*  1719 */ "OUTPUT\0"
/*  1726 */ "output\0"
/*  1733 */ "Invoke AutoGen with defs\0"
/*  1758 */ "AUTOGEN\0"
/*  1766 */ "no-autogen\0"
/*  1777 */ "Template Name\0"
/*  1791 */ "TEMPLATE\0"
/*  1800 */ "template\0"
/*  1809 */ "AutoGen Argument\0"
/*  1826 */ "AGARG\0"
/*  1832 */ "agarg\0"
/*  1838 */ "Base name for output file(s)\0"
/*  1867 */ "BASE_NAME\0"
/*  1877 */ "base-name\0"
/*  1887 */ "display extended usage information and exit\0"
/*  1931 */ "help\0"
/*  1936 */ "extended usage information passed thru pager\0"
/*  1981 */ "more-help\0"
/*  1991 */ "output version information and exit\0"
/*  2027 */ "version\0"
/*  2035 */ "save the option state to a config file\0"
/*  2074 */ "save-opts\0"
/*  2084 */ "load options from a config file\0"
/*  2116 */ "LOAD_OPTS\0"
/*  2126 */ "no-load-opts\0"
/*  2139 */ "GETDEFS\0"
/*  2147 */ "getdefs (GNU AutoGen) - AutoGen Definition Extraction Tool - Ver. 1.5\n"
            "Usage:  %s [ <option-name>[{=| }<val>] ]...\n\0"
/*  2262 */ "/dev/null\0"
/*  2272 */ ".getdefsrc\0"
/*  2283 */ "autogen-users@lists.sourceforge.net\0"
/*  2319 */ "If no 'input' argument is provided or is set to simply \"-\", and if 'stdin'\n"
            "is not a 'tty', then the list of input files will be read from 'stdin'.\n\0"
/*  2467 */ "This program extracts AutoGen definitions from a list of source files.\n"
            "Definitions are delimited by '/*=<entry-type> <entry-name>\\n' and '=*/\\n'.\n\0"
/*  2614 */ "getdefs (GNU AutoGen) 1.5";

/**
 *  def-selection option description:
 */
/** def-selection option separation text */
#define DEF_SELECTION_DESC      (getdefs_opt_strs+871)
#define DEF_SELECTION_FLAGS     (OPTST_DOCUMENT | OPTST_NO_INIT)

/**
 *  defs_to_get option description:
 */
/** Descriptive text for the defs_to_get option */
#define DEFS_TO_GET_DESC      (getdefs_opt_strs+941)
/** Upper-cased name for the defs_to_get option */
#define DEFS_TO_GET_NAME      (getdefs_opt_strs+976)
/** Name string for the defs_to_get option */
#define DEFS_TO_GET_name      (getdefs_opt_strs+988)
/** Compiled in flag settings for the defs_to_get option */
#define DEFS_TO_GET_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  subblock option description:
 */
/** Descriptive text for the subblock option */
#define SUBBLOCK_DESC      (getdefs_opt_strs+1000)
/** Upper-cased name for the subblock option */
#define SUBBLOCK_NAME      (getdefs_opt_strs+1026)
/** Name string for the subblock option */
#define SUBBLOCK_name      (getdefs_opt_strs+1035)
/** Compiled in flag settings for the subblock option */
#define SUBBLOCK_FLAGS     (OPTST_DISABLED | OPTST_STACKED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  listattr option description:
 */
/** Descriptive text for the listattr option */
#define LISTATTR_DESC      (getdefs_opt_strs+1044)
/** Upper-cased name for the listattr option */
#define LISTATTR_NAME      (getdefs_opt_strs+1074)
/** Name string for the listattr option */
#define LISTATTR_name      (getdefs_opt_strs+1083)
/** Compiled in flag settings for the listattr option */
#define LISTATTR_FLAGS     (OPTST_DISABLED | OPTST_STACKED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  enumerating option description:
 */
/** enumerating option separation text */
#define ENUMERATING_DESC      (getdefs_opt_strs+1092)
#define ENUMERATING_FLAGS     (OPTST_DOCUMENT | OPTST_NO_INIT)

/**
 *  ordering option description:
 */
/** Descriptive text for the ordering option */
#define ORDERING_DESC      (getdefs_opt_strs+1131)
/** Upper-cased name for the ordering option */
#define ORDERING_NAME      (getdefs_opt_strs+1161)
/** disablement name for the ordering option */
#define NOT_ORDERING_name  (getdefs_opt_strs+1170)
/** disablement prefix for the ordering option */
#define NOT_ORDERING_PFX   (getdefs_opt_strs+1182)
/** Name string for the ordering option */
#define ORDERING_name      (NOT_ORDERING_name + 3)
/** Compiled in flag settings for the ordering option */
#define ORDERING_FLAGS     (OPTST_INITENABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | OPTST_ARG_OPTIONAL)

/**
 *  first_index option description:
 */
/** Descriptive text for the first_index option */
#define FIRST_INDEX_DESC      (getdefs_opt_strs+1185)
/** Upper-cased name for the first_index option */
#define FIRST_INDEX_NAME      (getdefs_opt_strs+1220)
/** Name string for the first_index option */
#define FIRST_INDEX_name      (getdefs_opt_strs+1232)
/** The compiled in default value for the first_index option argument */
#define FIRST_INDEX_DFT_ARG   ((char const*)0)
/** Compiled in flag settings for the first_index option */
#define FIRST_INDEX_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/**
 *  doc_insert option description:
 */
/** doc_insert option separation text */
#define DOC_INSERT_DESC      (getdefs_opt_strs+1244)
#define DOC_INSERT_FLAGS     (OPTST_DOCUMENT | OPTST_NO_INIT)

/**
 *  filelist option description:
 */
/** Descriptive text for the filelist option */
#define FILELIST_DESC      (getdefs_opt_strs+1274)
/** Upper-cased name for the filelist option */
#define FILELIST_NAME      (getdefs_opt_strs+1309)
/** Name string for the filelist option */
#define FILELIST_name      (getdefs_opt_strs+1318)
/** Compiled in flag settings for the filelist option */
#define FILELIST_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | OPTST_ARG_OPTIONAL)

/**
 *  assign option description:
 */
/** Descriptive text for the assign option */
#define ASSIGN_DESC      (getdefs_opt_strs+1327)
/** Upper-cased name for the assign option */
#define ASSIGN_NAME      (getdefs_opt_strs+1346)
/** Name string for the assign option */
#define ASSIGN_name      (getdefs_opt_strs+1353)
/** Compiled in flag settings for the assign option */
#define ASSIGN_FLAGS     (OPTST_DISABLED | OPTST_STACKED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  common_assign option description:
 */
/** Descriptive text for the common_assign option */
#define COMMON_ASSIGN_DESC      (getdefs_opt_strs+1360)
/** Upper-cased name for the common_assign option */
#define COMMON_ASSIGN_NAME      (getdefs_opt_strs+1393)
/** Name string for the common_assign option */
#define COMMON_ASSIGN_name      (getdefs_opt_strs+1407)
/** Compiled in flag settings for the common_assign option */
#define COMMON_ASSIGN_FLAGS     (OPTST_DISABLED | OPTST_STACKED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  copy option description:
 */
/** Descriptive text for the copy option */
#define COPY_DESC      (getdefs_opt_strs+1421)
/** Upper-cased name for the copy option */
#define COPY_NAME      (getdefs_opt_strs+1454)
/** Name string for the copy option */
#define COPY_name      (getdefs_opt_strs+1459)
/** Compiled in flag settings for the copy option */
#define COPY_FLAGS     (OPTST_DISABLED | OPTST_STACKED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  srcfile option description:
 */
/** Descriptive text for the srcfile option */
#define SRCFILE_DESC      (getdefs_opt_strs+1464)
/** Upper-cased name for the srcfile option */
#define SRCFILE_NAME      (getdefs_opt_strs+1502)
/** Name string for the srcfile option */
#define SRCFILE_name      (getdefs_opt_strs+1510)
/** Compiled in flag settings for the srcfile option */
#define SRCFILE_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | OPTST_ARG_OPTIONAL)

/**
 *  linenum option description:
 */
/** Descriptive text for the linenum option */
#define LINENUM_DESC      (getdefs_opt_strs+1518)
/** Upper-cased name for the linenum option */
#define LINENUM_NAME      (getdefs_opt_strs+1558)
/** Name string for the linenum option */
#define LINENUM_name      (getdefs_opt_strs+1566)
/** Compiled in flag settings for the linenum option */
#define LINENUM_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | OPTST_ARG_OPTIONAL)

/**
 *  input-files option description:
 */
/** input-files option separation text */
#define INPUT_FILES_DESC      (getdefs_opt_strs+1574)
#define INPUT_FILES_FLAGS     (OPTST_DOCUMENT | OPTST_NO_INIT)

/**
 *  input option description:
 */
/** Descriptive text for the input option */
#define INPUT_DESC      (getdefs_opt_strs+1617)
/** Upper-cased name for the input option */
#define INPUT_NAME      (getdefs_opt_strs+1647)
/** Name string for the input option */
#define INPUT_name      (getdefs_opt_strs+1653)
/** Compiled in flag settings for the input option */
#define INPUT_FLAGS     (OPTST_DISABLED | OPTST_STACKED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  doc_output option description:
 */
/** doc_output option separation text */
#define DOC_OUTPUT_DESC      (getdefs_opt_strs+1659)
#define DOC_OUTPUT_FLAGS     (OPTST_DOCUMENT | OPTST_NO_INIT)

/**
 *  output option description:
 */
/** Descriptive text for the output option */
#define OUTPUT_DESC      (getdefs_opt_strs+1699)
/** Upper-cased name for the output option */
#define OUTPUT_NAME      (getdefs_opt_strs+1719)
/** Name string for the output option */
#define OUTPUT_name      (getdefs_opt_strs+1726)
/** Compiled in flag settings for the output option */
#define OUTPUT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  autogen option description:
 */
/** Descriptive text for the autogen option */
#define AUTOGEN_DESC      (getdefs_opt_strs+1733)
/** Upper-cased name for the autogen option */
#define AUTOGEN_NAME      (getdefs_opt_strs+1758)
/** disablement name for the autogen option */
#define NOT_AUTOGEN_name  (getdefs_opt_strs+1766)
/** disablement prefix for the autogen option */
#define NOT_AUTOGEN_PFX   (getdefs_opt_strs+1182)
/** Name string for the autogen option */
#define AUTOGEN_name      (NOT_AUTOGEN_name + 3)
/** Compiled in flag settings for the autogen option */
#define AUTOGEN_FLAGS     (OPTST_INITENABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | OPTST_ARG_OPTIONAL)

/**
 *  template option description:
 */
/** Descriptive text for the template option */
#define TEMPLATE_DESC      (getdefs_opt_strs+1777)
/** Upper-cased name for the template option */
#define TEMPLATE_NAME      (getdefs_opt_strs+1791)
/** Name string for the template option */
#define TEMPLATE_name      (getdefs_opt_strs+1800)
/** Compiled in flag settings for the template option */
#define TEMPLATE_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  agarg option description with
 *  "Must also have options" and "Incompatible options":
 */
/** Descriptive text for the agarg option */
#define AGARG_DESC      (getdefs_opt_strs+1809)
/** Upper-cased name for the agarg option */
#define AGARG_NAME      (getdefs_opt_strs+1826)
/** Name string for the agarg option */
#define AGARG_name      (getdefs_opt_strs+1832)
/** Other options that appear in conjunction with the agarg option */
static int const aAgargCantList[] = {
    INDEX_OPT_OUTPUT, NO_EQUIVALENT };
/** Compiled in flag settings for the agarg option */
#define AGARG_FLAGS     (OPTST_DISABLED | OPTST_STACKED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  base_name option description with
 *  "Must also have options" and "Incompatible options":
 */
/** Descriptive text for the base_name option */
#define BASE_NAME_DESC      (getdefs_opt_strs+1838)
/** Upper-cased name for the base_name option */
#define BASE_NAME_NAME      (getdefs_opt_strs+1867)
/** Name string for the base_name option */
#define BASE_NAME_name      (getdefs_opt_strs+1877)
/** Other options that appear in conjunction with the base_name option */
static int const aBase_NameCantList[] = {
    INDEX_OPT_OUTPUT, NO_EQUIVALENT };
/** Compiled in flag settings for the base_name option */
#define BASE_NAME_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  Help/More_Help/Version option descriptions:
 */
#define HELP_DESC       (getdefs_opt_strs+1887)
#define HELP_name       (getdefs_opt_strs+1931)
#ifdef HAVE_WORKING_FORK
#define MORE_HELP_DESC  (getdefs_opt_strs+1936)
#define MORE_HELP_name  (getdefs_opt_strs+1981)
#define MORE_HELP_FLAGS (OPTST_IMM | OPTST_NO_INIT)
#else
#define MORE_HELP_DESC  HELP_DESC
#define MORE_HELP_name  HELP_name
#define MORE_HELP_FLAGS (OPTST_OMITTED | OPTST_NO_INIT)
#endif
#ifdef NO_OPTIONAL_OPT_ARGS
#  define VER_FLAGS     (OPTST_IMM | OPTST_NO_INIT)
#else
#  define VER_FLAGS     (OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | \
                         OPTST_ARG_OPTIONAL | OPTST_IMM | OPTST_NO_INIT)
#endif
#define VER_DESC        (getdefs_opt_strs+1991)
#define VER_name        (getdefs_opt_strs+2027)
#define SAVE_OPTS_DESC  (getdefs_opt_strs+2035)
#define SAVE_OPTS_name  (getdefs_opt_strs+2074)
#define LOAD_OPTS_DESC     (getdefs_opt_strs+2084)
#define LOAD_OPTS_NAME     (getdefs_opt_strs+2116)
#define NO_LOAD_OPTS_name  (getdefs_opt_strs+2126)
#define LOAD_OPTS_pfx      (getdefs_opt_strs+1182)
#define LOAD_OPTS_name     (NO_LOAD_OPTS_name + 3)
/**
 *  Declare option callback procedures
 */
extern tOptProc
    optionBooleanVal,   optionNestedVal,    optionNumericVal,
    optionPagedUsage,   optionPrintVersion, optionResetOpt,
    optionStackArg,     optionTimeDate,     optionTimeVal,
    optionUnstackArg,   optionVendorOption;
static tOptProc
    doUsageOpt;
#define VER_PROC        optionPrintVersion

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 *  Define the getdefs Option Descriptions.
 * This is an array of OPTION_CT entries, one for each
 * option that the getdefs program responds to.
 */
static tOptDesc optDesc[OPTION_CT] = {
  {  /* entry idx, value */ 0, 0,
     /* equiv idx, value */ 0, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 0, 0,
     /* opt state flags  */ DEF_SELECTION_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ DEF_SELECTION_DESC, NULL, NULL,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 1, VALUE_OPT_DEFS_TO_GET,
     /* equiv idx, value */ 1, VALUE_OPT_DEFS_TO_GET,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ DEFS_TO_GET_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --defs_to_get */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ DEFS_TO_GET_DESC, DEFS_TO_GET_NAME, DEFS_TO_GET_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 2, VALUE_OPT_SUBBLOCK,
     /* equiv idx, value */ 2, VALUE_OPT_SUBBLOCK,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ SUBBLOCK_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --subblock */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionStackArg,
     /* desc, NAME, name */ SUBBLOCK_DESC, SUBBLOCK_NAME, SUBBLOCK_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 3, VALUE_OPT_LISTATTR,
     /* equiv idx, value */ 3, VALUE_OPT_LISTATTR,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ LISTATTR_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --listattr */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionStackArg,
     /* desc, NAME, name */ LISTATTR_DESC, LISTATTR_NAME, LISTATTR_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 0, 0,
     /* equiv idx, value */ 0, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 0, 0,
     /* opt state flags  */ ENUMERATING_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ ENUMERATING_DESC, NULL, NULL,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 5, VALUE_OPT_ORDERING,
     /* equiv idx, value */ 5, VALUE_OPT_ORDERING,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ ORDERING_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --ordering */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ ORDERING_DESC, ORDERING_NAME, ORDERING_name,
     /* disablement strs */ NOT_ORDERING_name, NOT_ORDERING_PFX },

  {  /* entry idx, value */ 6, VALUE_OPT_FIRST_INDEX,
     /* equiv idx, value */ 6, VALUE_OPT_FIRST_INDEX,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ FIRST_INDEX_FLAGS, 0,
     /* last opt argumnt */ { FIRST_INDEX_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionNumericVal,
     /* desc, NAME, name */ FIRST_INDEX_DESC, FIRST_INDEX_NAME, FIRST_INDEX_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 0, 0,
     /* equiv idx, value */ 0, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 0, 0,
     /* opt state flags  */ DOC_INSERT_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ DOC_INSERT_DESC, NULL, NULL,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 8, VALUE_OPT_FILELIST,
     /* equiv idx, value */ 8, VALUE_OPT_FILELIST,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ FILELIST_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --filelist */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ FILELIST_DESC, FILELIST_NAME, FILELIST_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 9, VALUE_OPT_ASSIGN,
     /* equiv idx, value */ 9, VALUE_OPT_ASSIGN,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ ASSIGN_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --assign */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionStackArg,
     /* desc, NAME, name */ ASSIGN_DESC, ASSIGN_NAME, ASSIGN_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 10, VALUE_OPT_COMMON_ASSIGN,
     /* equiv idx, value */ 10, VALUE_OPT_COMMON_ASSIGN,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ COMMON_ASSIGN_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --common_assign */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionStackArg,
     /* desc, NAME, name */ COMMON_ASSIGN_DESC, COMMON_ASSIGN_NAME, COMMON_ASSIGN_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 11, VALUE_OPT_COPY,
     /* equiv idx, value */ 11, VALUE_OPT_COPY,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ COPY_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --copy */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionStackArg,
     /* desc, NAME, name */ COPY_DESC, COPY_NAME, COPY_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 12, VALUE_OPT_SRCFILE,
     /* equiv idx, value */ 12, VALUE_OPT_SRCFILE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ SRCFILE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --srcfile */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ SRCFILE_DESC, SRCFILE_NAME, SRCFILE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 13, VALUE_OPT_LINENUM,
     /* equiv idx, value */ 13, VALUE_OPT_LINENUM,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LINENUM_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --linenum */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ LINENUM_DESC, LINENUM_NAME, LINENUM_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 0, 0,
     /* equiv idx, value */ 0, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 0, 0,
     /* opt state flags  */ INPUT_FILES_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ INPUT_FILES_DESC, NULL, NULL,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 15, VALUE_OPT_INPUT,
     /* equiv idx, value */ 15, VALUE_OPT_INPUT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ INPUT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --input */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionStackArg,
     /* desc, NAME, name */ INPUT_DESC, INPUT_NAME, INPUT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 0, 0,
     /* equiv idx, value */ 0, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 0, 0,
     /* opt state flags  */ DOC_OUTPUT_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ DOC_OUTPUT_DESC, NULL, NULL,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 17, VALUE_OPT_OUTPUT,
     /* equiv idx, value */ NOLIMIT, NOLIMIT,
     /* equivalenced to  */ INDEX_OPT_AUTOGEN,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OUTPUT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --output */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ OUTPUT_DESC, OUTPUT_NAME, OUTPUT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 18, VALUE_OPT_AUTOGEN,
     /* equiv idx, value */ NO_EQUIVALENT, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ AUTOGEN_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --autogen */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ AUTOGEN_DESC, AUTOGEN_NAME, AUTOGEN_name,
     /* disablement strs */ NOT_AUTOGEN_name, NOT_AUTOGEN_PFX },

  {  /* entry idx, value */ 19, VALUE_OPT_TEMPLATE,
     /* equiv idx, value */ 19, VALUE_OPT_TEMPLATE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ TEMPLATE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --template */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ TEMPLATE_DESC, TEMPLATE_NAME, TEMPLATE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 20, VALUE_OPT_AGARG,
     /* equiv idx, value */ 20, VALUE_OPT_AGARG,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ AGARG_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --agarg */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, aAgargCantList,
     /* option proc      */ optionStackArg,
     /* desc, NAME, name */ AGARG_DESC, AGARG_NAME, AGARG_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 21, VALUE_OPT_BASE_NAME,
     /* equiv idx, value */ 21, VALUE_OPT_BASE_NAME,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ BASE_NAME_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --base_name */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, aBase_NameCantList,
     /* option proc      */ NULL,
     /* desc, NAME, name */ BASE_NAME_DESC, BASE_NAME_NAME, BASE_NAME_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_VERSION, VALUE_OPT_VERSION,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_VERSION,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ VER_FLAGS, AOUSE_VERSION,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ VER_PROC,
     /* desc, NAME, name */ VER_DESC, NULL, VER_name,
     /* disablement strs */ NULL, NULL },



  {  /* entry idx, value */ INDEX_OPT_HELP, VALUE_OPT_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_IMM | OPTST_NO_INIT, AOUSE_HELP,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doUsageOpt,
     /* desc, NAME, name */ HELP_DESC, NULL, HELP_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_MORE_HELP, VALUE_OPT_MORE_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_MORE_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ MORE_HELP_FLAGS, AOUSE_MORE_HELP,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL,  NULL,
     /* option proc      */ optionPagedUsage,
     /* desc, NAME, name */ MORE_HELP_DESC, NULL, MORE_HELP_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_SAVE_OPTS, VALUE_OPT_SAVE_OPTS,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_SAVE_OPTS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_SET_ARGTYPE(OPARG_TYPE_STRING)
                          | OPTST_ARG_OPTIONAL | OPTST_NO_INIT, AOUSE_SAVE_OPTS,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL,  NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ SAVE_OPTS_DESC, NULL, SAVE_OPTS_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_LOAD_OPTS, VALUE_OPT_LOAD_OPTS,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_LOAD_OPTS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ OPTST_SET_ARGTYPE(OPARG_TYPE_STRING)
			  | OPTST_DISABLE_IMM, AOUSE_LOAD_OPTS,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionLoadOpt,
     /* desc, NAME, name */ LOAD_OPTS_DESC, LOAD_OPTS_NAME, LOAD_OPTS_name,
     /* disablement strs */ NO_LOAD_OPTS_name, LOAD_OPTS_pfx }
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/** Reference to the upper cased version of getdefs. */
#define zPROGNAME       (getdefs_opt_strs+2139)
/** Reference to the title line for getdefs usage. */
#define zUsageTitle     (getdefs_opt_strs+2147)
/** getdefs configuration file name. */
#define zRcName         (getdefs_opt_strs+2272)
/** Directories to search for getdefs config files. */
static char const * const apzHomeList[2] = {
    getdefs_opt_strs+2262,
    NULL };
/** The getdefs program bug email address. */
#define zBugsAddr       (getdefs_opt_strs+2283)
/** Clarification/explanation of what getdefs does. */
#define zExplain        (getdefs_opt_strs+2319)
/** Extra detail explaining what getdefs does. */
#define zDetail         (getdefs_opt_strs+2467)
/** The full version string for getdefs. */
#define zFullVersion    (getdefs_opt_strs+2614)
/* extracted from optcode.tlib near line 371 */

#define OPTPROC_BASE OPTPROC_NONE
#define translate_option_strings NULL

#define getdefs_full_usage (NULL)
#define getdefs_short_usage (NULL)

#endif /* not defined __doxygen__ */

/*
 *  Create the static procedure(s) declared above.
 */
/**
 * The callout function that invokes the optionUsage function.
 *
 * @param[in] pOptions the AutoOpts option description structure
 * @param[in] pOptDesc the descriptor for the "help" (usage) option.
 * @noreturn
 */
static void
doUsageOpt(tOptions * pOptions, tOptDesc * pOptDesc)
{
    optionUsage(&getdefsOptions, GETDEFS_EXIT_SUCCESS);
    /* NOTREACHED */
    (void)pOptDesc;
    (void)pOptions;
}
/* extracted from optmain.tlib near line 1254 */

/**
 * The directory containing the data associated with getdefs.
 */
#ifndef  PKGDATADIR
# define PKGDATADIR ""
#endif

/**
 * Information about the person or institution that packaged getdefs
 * for the current distribution.
 */
#ifndef  WITH_PACKAGER
# define getdefs_packager_info NULL
#else
/** Packager information for getdefs. */
static char const getdefs_packager_info[] =
    "Packaged by " WITH_PACKAGER

# ifdef WITH_PACKAGER_VERSION
        " ("WITH_PACKAGER_VERSION")"
# endif

# ifdef WITH_PACKAGER_BUG_REPORTS
    "\nReport getdefs bugs to " WITH_PACKAGER_BUG_REPORTS
# endif
    "\n";
#endif
#ifndef __doxygen__

#endif /* __doxygen__ */
/**
 * The option definitions for getdefs.  The one structure that
 * binds them all.
 */
tOptions getdefsOptions = {
    OPTIONS_STRUCT_VERSION,
    0, NULL,                    /* original argc + argv    */
    ( OPTPROC_BASE
    + OPTPROC_ERRSTOP
    + OPTPROC_NO_REQ_OPT
    + OPTPROC_NEGATIONS
    + OPTPROC_NO_ARGS ),
    0, NULL,                    /* current option index, current option */
    NULL,         NULL,         zPROGNAME,
    zRcName,      zCopyright,   zLicenseDescrip,
    zFullVersion, apzHomeList,  zUsageTitle,
    zExplain,     zDetail,      optDesc,
    zBugsAddr,                  /* address to send bugs to */
    NULL, NULL,                 /* extensions/saved state  */
    optionUsage, /* usage procedure */
    translate_option_strings,   /* translation procedure */
    /*
     *  Indexes to special options
     */
    { INDEX_OPT_MORE_HELP, /* more-help option index */
      INDEX_OPT_SAVE_OPTS, /* save option index */
      NO_EQUIVALENT, /* '-#' option index */
      15 /* index of default opt */
    },
    27 /* full option count */, 22 /* user option count */,
    getdefs_full_usage, getdefs_short_usage,
    NULL, NULL,
    PKGDATADIR, getdefs_packager_info
};

#ifdef  __cplusplus
}
#endif
/** @} */
/* opts.c ends here */
