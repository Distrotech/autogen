[= AutoGen5 Template -*- Mode: C -*-

h=options.h

# Automated Options copyright 1992-2007 Bruce Korb
# Time-stamp:      "2008-11-01 16:47:39 bkorb"
# ID:  $Id: options_h.tpl,v 4.43 2008/11/02 18:51:00 bkorb Exp $
#
##  This file is part of AutoOpts, a companion to AutoGen.
##  AutoOpts is free software.
##  AutoOpts is copyright (c) 1992-2008 by Bruce Korb - all rights reserved
##  AutoOpts is copyright (c) 1992-2008 by Bruce Korb - all rights reserved
##
##  AutoOpts is available under any one of two licenses.  The license
##  in use must be one of these two and the choice is under the control
##  of the user of the license.
##
##   The GNU Lesser General Public License, version 3 or later
##      See the files "COPYING.lgplv3" and "COPYING.gplv3"
##
##   The Modified Berkeley Software Distribution License
##      See the file "COPYING.mbsd"
##
##  These files have the following md5sums:
##
##  239588c55c22c60ffe159946a760a33e pkg/libopts/COPYING.gplv3
##  fa82ca978890795162346e661b47161a pkg/libopts/COPYING.lgplv3
##  66a5cedaf62c4b2637025f049f9b826f pkg/libopts/COPYING.mbsd

=][=

(dne " *  " "/*  ")

=]
 *
 *  This file defines all the global structures and special values
 *  used in the automated option processing library.
 *
 *  Automated Options copyright 1992-[=`date +Y`=] Bruce Korb
 *
[=(lgpl "AutoOpts" "Bruce Korb" " *  ")=]
 */
[=(make-header-guard "autoopts")=]
#include <sys/types.h>
#include <stdio.h>

#if defined(HAVE_STDINT_H)
# include <stdint.h>
#elif defined(HAVE_INTTYPES_H)
# include <inttypes.h>
#endif /* HAVE_STDINT/INTTYPES_H */

#if defined(HAVE_LIMITS_H)
# include <limits.h>
#elif defined(HAVE_SYS_LIMITS_H)
# include <sys/limits.h>
#endif /* HAVE_LIMITS/SYS_LIMITS_H */

#if defined(HAVE_SYSEXITS_H)
#  include <sysexits.h>
#endif /* HAVE_SYSEXITS_H */

#ifndef EX_USAGE
#  define EX_USAGE              64
#endif

/*
 *  PUBLIC DEFINES
 *
 *  The following defines may be used in applications that need to test the
 *  state of an option.  To test against these masks and values, a pointer
 *  to an option descriptor must be obtained.  There are two ways:
 *
 *  1. inside an option processing procedure, it is the second argument,
 *  conventionally "tOptDesc* pOD".
 *
 *  2.  Outside of an option procedure (or to reference a different option
 *  descriptor), use either "&DESC( opt_name )" or "&pfx_DESC( opt_name )".
 *
 *  See the relevant generated header file to determine which and what
 *  values for "opt_name" are available.
 */
[=

 ;;;
 ;;; These "vers" values are manipulated by the contents of ../VERSION
 ;;;

(shellf "
sed 's/@AO_TEMPLATE_VERSION@/%s/' opthead.tpl > XXXX
mv -f XXXX opthead.tpl"
 (get "vers-curr"))

=]
#define  OPTIONS_STRUCT_VERSION  [=  vers-curr    =]
#define  OPTIONS_VERSION_STRING  "[= vers-sovers  =]"
#define  OPTIONS_MINIMUM_VERSION [=  vers-min     =]
#define  OPTIONS_MIN_VER_STRING  "[= vers-min-str =]"

typedef enum {
    OPARG_TYPE_NONE             = 0,
    OPARG_TYPE_STRING           = 1,    /* default type/ vanilla string      */
    OPARG_TYPE_ENUMERATION      = 2,    /* opt arg is an enum (keyword list) */
    OPARG_TYPE_BOOLEAN          = 3,    /* opt arg is boolean-valued         */
    OPARG_TYPE_MEMBERSHIP       = 4,    /* opt arg sets set membership bits  */
    OPARG_TYPE_NUMERIC          = 5,    /* opt arg has numeric value         */
    OPARG_TYPE_HIERARCHY        = 6,    /* option arg is hierarchical value  */
    OPARG_TYPE_FILE             = 7,    /* option arg names a file           */
    OPARG_TYPE_TIME             = 8     /* opt arg is a time duration        */
} teOptArgType;

typedef struct optionValue {
    teOptArgType        valType;
    char*               pzName;
    union {
        char            strVal[1];      /* OPARG_TYPE_STRING      */
        unsigned int    enumVal;        /* OPARG_TYPE_ENUMERATION */
        unsigned int    boolVal;        /* OPARG_TYPE_BOOLEAN     */
        unsigned long   setVal;         /* OPARG_TYPE_MEMBERSHIP  */
        long            longVal;        /* OPARG_TYPE_NUMERIC     */
        void*           nestVal;        /* OPARG_TYPE_HIERARCHY   */
    } v;
} tOptionValue;

typedef enum {
    FTYPE_MODE_MAY_EXIST        = 0x00,
    FTYPE_MODE_MUST_EXIST       = 0x01,
    FTYPE_MODE_MUST_NOT_EXIST   = 0x02,
    FTYPE_MODE_EXIST_MASK       = 0x03,
    FTYPE_MODE_NO_OPEN          = 0x00,
    FTYPE_MODE_OPEN_FD          = 0x10,
    FTYPE_MODE_FOPEN_FP         = 0x20,
    FTYPE_MODE_OPEN_MASK        = 0x30
} teOptFileType;

typedef union {
    int             file_flags;
    char const *    file_mode;
} tuFileMode;

/*
 *  Bits in the fOptState option descriptor field.
 */
[= `
autogen opt-state.def || die "Cannot regen opt-state.h"
sed -e '1,/typedef.*_bits_t/d' \
    -e 's/NO_BITS /INIT/' \
    -e 's/_BIT / /' \
    -e 's/_MASK     /_MASK /' \
    -e '/ SET_OPT_STATE(/,$d' opt-state.h
rm  -f opt-state.[ch]
` =]

#ifdef NO_OPTIONAL_OPT_ARGS
# undef  OPTST_ARG_OPTIONAL
# define OPTST_ARG_OPTIONAL   0
#endif

#define OPTST_PERSISTENT_MASK (~OPTST_MUTABLE_MASK)

#define SELECTED_OPT(_od)     ((_od)->fOptState  & OPTST_SELECTED_MASK)
#define UNUSED_OPT(  _od)     (((_od)->fOptState & OPTST_SET_MASK) == 0)
#define DISABLED_OPT(_od)     ((_od)->fOptState  & OPTST_DISABLED)
#define OPTION_STATE(_od)     ((_od)->fOptState)
#define OPTST_SET_ARGTYPE(_n) ((_n) << OPTST_ARG_TYPE_1_ID)
#define OPTST_GET_ARGTYPE(_f) (((_f)&OPTST_ARG_TYPE_MASK)>>OPTST_ARG_TYPE_1_ID)

/*
 *  PRIVATE INTERFACES
 *
 *  The following values are used in the generated code to communicate
 *  with the option library procedures.  They are not for public use
 *  and may be subject to change.
 */

/*
 *  Define the processing state flags
 */
[= `

autogen proc-state.def || die 'Cannot regen proc-state.h'
sed -e '1,/typedef.*_bits_t/d' \
    -e 's/NO_BITS /NONE/' \
    -e 's/_BIT / /' \
    -e 's/_MASK    /_MASK/' \
    -e '/^ *OPTPROC_NXLAT_[A-Z_]* *)/q' proc-state.h
rm  -f proc-state.[ch]

` =]

#define STMTS(s)  do { s; } while (0)

/*
 *  The following must be #defined instead of typedef-ed
 *  because "static const" cannot both be applied to a type,
 *  tho each individually can...so they all are
 */
#define tSCC        static char const
#define tCC         char const
#define tAoSC       static char
#define tAoUC       unsigned char
#define tAoUI       unsigned int
#define tAoUL       unsigned long
#define tAoUS       unsigned short

/*
 *  It is so disgusting that there must be so many ways
 *  of specifying TRUE and FALSE.
 */
typedef enum { AG_FALSE = 0, AG_TRUE } ag_bool;

/*
 *  Define a structure that describes each option and
 *  a pointer to the procedure that handles it.
 *  The argument is the count of this flag previously seen.
 */
typedef struct options  tOptions;
typedef struct optDesc  tOptDesc;
typedef struct optNames tOptNames;
#define OPTPROC_EMIT_USAGE      ((tOptions *)0x01UL)
#define OPTPROC_EMIT_SHELL      ((tOptions *)0x02UL)
#define OPTPROC_RETURN_VALNAME  ((tOptions *)0x03UL)
#define OPTPROC_EMIT_LIMIT      ((tOptions *)0x0FUL)

/*
 *  The option procedures do the special processing for each
 *  option flag that needs it.
 */
typedef void (tOptProc)(tOptions*  pOpts, tOptDesc* pOptDesc);
typedef tOptProc*  tpOptProc;

/*
 *  The usage procedure will never return.  It calls "exit(2)"
 *  with the "exitCode" argument passed to it.
 */
typedef void (tUsageProc)(tOptions* pOpts, int exitCode);
typedef tUsageProc* tpUsageProc;

/*
 *  Special definitions.  "NOLIMIT" is the 'max' value to use when
 *  a flag may appear multiple times without limit.  "NO_EQUIVALENT"
 *  is an illegal value for 'optIndex' (option description index).
 */
#define NOLIMIT          USHRT_MAX
#define OPTION_LIMIT     SHRT_MAX
#define NO_EQUIVALENT    (OPTION_LIMIT+1)

/*
 *  Special values for optValue.  It must not be generatable from the
 *  computation "optIndex +96".  Since "optIndex" is limited to 100, ...
 */
#define NUMBER_OPTION    '#'

typedef struct argList tArgList;
#define MIN_ARG_ALLOC_CT   6
#define INCR_ARG_ALLOC_CT  8
struct argList {
    int             useCt;
    int             allocCt;
    tCC*            apzArgs[ MIN_ARG_ALLOC_CT ];
};

typedef union {
    char const *    argString;
    uintptr_t       argEnum;
    uintptr_t       argIntptr;
    long            argInt;
    unsigned long   argUint;
    unsigned int    argBool;
    FILE*           argFp;
    int             argFd;
} optArgBucket_t;

/*
 *  Descriptor structure for each option.
 *  Only the fields marked "PUBLIC" are for public use.
 */
struct optDesc {
    tAoUS const     optIndex;         /* PUBLIC */
    tAoUS const     optValue;         /* PUBLIC */
    tAoUS           optActualIndex;   /* PUBLIC */
    tAoUS           optActualValue;   /* PUBLIC */

    tAoUS const     optEquivIndex;    /* PUBLIC */
    tAoUS const     optMinCt;
    tAoUS const     optMaxCt;
    tAoUS           optOccCt;         /* PUBLIC */

    tAoUI           fOptState;        /* PUBLIC */
    tAoUI           reserved;
    optArgBucket_t  optArg;           /* PUBLIC */
#   define          pzLastArg   optArg.argString
    void*           optCookie;        /* PUBLIC */

    int const * const   pOptMust;
    int const * const   pOptCant;
    tpOptProc   const   pOptProc;
    char const* const   pzText;

    char const* const   pz_NAME;
    char const* const   pz_Name;
    char const* const   pz_DisableName;
    char const* const   pz_DisablePfx;
};

/*
 *  Some options need special processing, so we store their
 *  indexes in a known place:
 */
typedef struct optSpecIndex tOptSpecIndex;
struct optSpecIndex {
    const tAoUS         more_help;
    const tAoUS         save_opts;
    const tAoUS         number_option;
    const tAoUS         default_opt;
};

/*
 *  The procedure generated for translating option text
 */
typedef void (tOptionXlateProc)(void);

struct options {
    int const           structVersion;
    int                 origArgCt;
    char**              origArgVect;
    unsigned int        fOptSet;
    unsigned int        curOptIdx;
    char*               pzCurOpt;

    char const*         pzProgPath;         /* PUBLIC */
    char const*         pzProgName;         /* PUBLIC */
    char const* const   pzPROGNAME;         /* PUBLIC */
    char const* const   pzRcName;           /* PUBLIC */
    char const* const   pzCopyright;        /* PUBLIC */
    char const* const   pzCopyNotice;       /* PUBLIC */
    char const* const   pzFullVersion;      /* PUBLIC */
    char const* const* const papzHomeList;
    char const* const   pzUsageTitle;
    char const* const   pzExplain;
    char const* const   pzDetail;
    tOptDesc*   const   pOptDesc;           /* PUBLIC */
    char const* const   pzBugAddr;          /* PUBLIC */

    void*               pExtensions;
    void*               pSavedState;

    tpUsageProc         pUsageProc;
    tOptionXlateProc*   pTransProc;

    tOptSpecIndex       specOptIdx;
    int const           optCt;
    int const           presetOptCt;
    char const *        pzFullUsage;
    char const *        pzShortUsage;
    /* PUBLIC: */
    optArgBucket_t const * const originalOptArgArray;
    void * const * const originalOptArgCookie;
};

/*
 *  Versions where in various fields first appear:
 *  ($AO_CURRENT * 4096 + $AO_REVISION, but $AO_REVISION must be zero)
 */
#define originalOptArgArray_STRUCT_VERSION  131072 /* AO_CURRENT = 32 */
#define HAS_originalOptArgArray(_opt) \
    ((_opt)->structVersion >= originalOptArgArray_STRUCT_VERSION)

/*
 *  "token list" structure returned by "string_tokenize()"
 */
typedef struct {
    unsigned long   tkn_ct;
    unsigned char*  tkn_list[1];
} token_list_t;

/*
 *  Hide the interface - it pollutes a POSIX claim, but leave it for
 *  anyone #include-ing this header
 */
#define strneqvcmp      option_strneqvcmp
#define streqvcmp       option_streqvcmp
#define streqvmap       option_streqvmap
#define strequate       option_strequate
#define strtransform    option_strtransform

/*
 *  This is an output only structure used by text_mmap and text_munmap.
 *  Clients must not alter the contents and must provide it to both
 *  the text_mmap and text_munmap procedures.  BE ADVISED: if you are
 *  mapping the file with PROT_WRITE the NUL byte at the end MIGHT NOT
 *  BE WRITABLE.  In any event, that byte is not be written back
 *  to the source file.  ALSO: if "txt_data" is valid and "txt_errno"
 *  is not zero, then there *may* not be a terminating NUL.
 */
typedef struct {
    void*       txt_data;      /* text file data   */
    size_t      txt_size;      /* actual file size */
    size_t      txt_full_size; /* mmaped mem size  */
    int         txt_fd;        /* file descriptor  */
    int         txt_zero_fd;   /* fd for /dev/zero */
    int         txt_errno;     /* warning code     */
    int         txt_prot;      /* "prot" flags     */
    int         txt_flags;     /* mapping type     */
    int         txt_alloc;     /* if we malloced memory */
} tmap_info_t;

#define TEXT_MMAP_FAILED_ADDR(a)  ((void*)(a) ==  (void*)MAP_FAILED)

#ifdef  __cplusplus
extern "C" {
#define CPLUSPLUS_CLOSER }
#else
#define CPLUSPLUS_CLOSER
#endif

/*
 *  The following routines may be coded into AutoOpts client code:
 */[=
 (define if-text   "")
 (define note-text "")
 (define end-text  "")
 (define note-fmt
    "\n *\n * the %s function is available only if %s is%s defined")

 (out-push-new)
 (out-suspend "priv")   =][=

FOR export_func         =][=

  IF

  (if (exist? "ifndef")
      (begin
        (set! if-text    (string-append "\n#ifndef " (get "ifndef")))
        (set! note-text  (sprintf note-fmt (get "name") (get "ifndef") " not"))
        (set! end-text   (sprintf "#endif /* %s */\n" (get "ifndef")))
      )

  (if (exist? "ifdef")
      (begin
        (set! if-text    (string-append "\n#ifdef " (get "ifdef")))
        (set! note-text  (sprintf note-fmt (get "name") (get "ifdef") ""))
        (set! end-text   (sprintf "#endif /* %s */\n" (get "ifdef")))
      )

  (begin
        (set! if-text    "")
        (set! note-text  "")
        (set! end-text   "")
  )  ))

 (not (exist? "private")) =]

/* From: [=srcfile=] line [=linenum=]
 *
 * [=name=] - [=what=][=
    IF (exist? "arg") =]
 *
 * Arguments:[=
       FOR arg
=]
 *   [=(sprintf "%-12s " (get "arg-name"))=][=arg-desc=][=
      ENDFOR arg  =][=
    ENDIF =][=

    IF (exist? "ret-type") =]
 *
 * Returns: [=ret-type=] - [=ret-desc=][=

    ENDIF  =][=(. note-text)=]
 *
[=(prefix " *  " (get "doc"))=]
 */[=

  ENDIF =][=

  (if (exist? "private") (out-resume "priv"))

  if-text

=]
extern [= ?% ret-type "%s" "void"  =] [=name=]([=
   IF (not (exist? "arg"))
          =]void[=
   ELSE   =][=(join ", " (stack "arg.arg-type")) =][=
   ENDIF  =]);
[=

  (if (exist? "ifndef")
      (sprintf "\n#endif /* %s */" (get "ifndef"))
  (if (exist? "ifdef")
      (sprintf "\n#endif /* %s */"  (get "ifdef"))  ))

  (if (exist? "private") (out-suspend "priv"))
  end-text

=][=

ENDFOR export-func

=]
/*  AutoOpts PRIVATE FUNCTIONS:  */
tOptProc optionStackArg, optionUnstackArg, optionBooleanVal, optionNumericVal;
[= (out-resume "priv") (out-pop #t) =]
CPLUSPLUS_CLOSER
#endif /* [=(. header-guard)=] */
/*
 * Local Variables:
 * c-file-style: "stroustrup"
 * indent-tabs-mode: nil
 * End:
 * [=(out-name)=] ends here */[=
## optexport.tpl ends here  =]
