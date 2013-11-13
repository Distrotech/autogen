/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (directive.c)
 *
 *  It has been AutoGen-ed  November 13, 2013 at 07:04:42 PM by AutoGen 5.18.1
 *  From the definitions    directive.def
 *  and the template file   str2enum
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name ``Bruce Korb'' nor the name of any other
 *    contributor may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * str2enum IS PROVIDED BY Bruce Korb ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Bruce Korb OR ANY OTHER CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "directive.h"
#include <ctype.h>
#include <string.h>
/** \file directive.c
 * Code for string to enumeration values and back again.
 * @addtogroup autogen
 * @{
 */

/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf directive.gp  */
/* Computed positions: -k'2,4' */



# if 0 /* gperf build options: */
// %struct-type
// %language=ANSI-C
// %includes
// %global-table
// %omit-struct-type
// %readonly-tables
// %compare-strncmp
//
// %define slot-name               dir_name
// %define hash-function-name      directive_hash
// %define lookup-function-name    find_directive_name
// %define word-array-name         directive_table
// %define initializer-suffix      ,DIR_COUNT
//
# endif

#include "directive.h"
typedef struct {
    char const *    dir_name;
    directive_enum_t dir_id;
} directive_map_t;
#include <string.h>

/* maximum key range = 34, duplicates = 0 */

static unsigned int
directive_hash (register const char *str, register unsigned int len)
{
  static const unsigned char asso_values[] =
    {
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 10, 37, 37,
      20,  0,  5,  5, 20, 15, 37, 37,  5,  5,
       0,  5,  5, 37,  5,  0, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
      37, 37, 37, 37, 37, 37
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
      case 2:
        hval += asso_values[(unsigned char)str[1]];
        break;
    }
  return hval;
}

static const directive_map_t directive_table[] =
  {
    {"",DIR_COUNT}, {"",DIR_COUNT}, {"",DIR_COUNT},
    {"let",      DIR_LET},
    {"",DIR_COUNT},
    {"undef",    DIR_UNDEF},
    {"assert",   DIR_ASSERT},
    {"if",       DIR_IF},
    {"endshell", DIR_ENDSHELL},
    {"else",     DIR_ELSE},
    {"ifdef",    DIR_IFDEF},
    {"endmac",   DIR_ENDMAC},
    {"include",  DIR_INCLUDE},
    {"",DIR_COUNT},
    {"elif",     DIR_ELIF},
    {"error",    DIR_ERROR},
    {"pragma",   DIR_PRAGMA},
    {"",DIR_COUNT}, {"",DIR_COUNT},
    {"line",     DIR_LINE},
    {"endif",    DIR_ENDIF},
    {"define",   DIR_DEFINE},
    {"",DIR_COUNT}, {"",DIR_COUNT}, {"",DIR_COUNT},
    {"ident",    DIR_IDENT},
    {"option",   DIR_OPTION},
    {"",DIR_COUNT}, {"",DIR_COUNT}, {"",DIR_COUNT},
    {"shell",    DIR_SHELL},
    {"ifndef",   DIR_IFNDEF},
    {"",DIR_COUNT}, {"",DIR_COUNT}, {"",DIR_COUNT},
    {"",DIR_COUNT},
    {"macdef",   DIR_MACDEF}
  };

static inline const directive_map_t *
find_directive_name (register const char *str, register unsigned int len)
{
  if (len <= 8 && len >= 2)
    {
      register int key = (int)directive_hash (str, len);

      if (key <= 36 && key >= 0)
        {
          register const char *s = directive_table[key].dir_name;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return &directive_table[key];
        }
    }
  return 0;
}

/**
 * Convert a command (keyword) to a directive_enum_t enumeration value.
 * The length of the command is computed by calling \a strspn()
 * on the input argument.
 *
 * @param[in] str   a string that should start with a known key word.
 * @returns the enumeration value.
 * If not found, that value is DIR_INVALID.
 */
directive_enum_t
find_directive(char const * str)
{
    directive_map_t const * map;
    static char const accept[] =
        "acdefghilmnoprstu";
    unsigned int clen = strspn(str, accept);

    if (isalnum((unsigned char)str[clen]))
        return DIR_INVALID;
    map = find_directive_name(str, (unsigned int)clen);
    return (map == NULL) ? DIR_INVALID : map->dir_id;
}

/**
 * Convert an directive_enum_t value into a string.
 *
 * @param[in] id  the enumeration value
 * @returns the associated string, or "* UNDEFINED *" if \a id
 * is out of range.
 */
char const *
directive_name(directive_enum_t id)
{
    static char const undef[] = "* UNDEFINED *";
    static char const * const nm_table[] = {
        [DIR_ASSERT  ] = "assert",
        [DIR_DEFINE  ] = "define",
        [DIR_ELIF    ] = "elif",
        [DIR_ELSE    ] = "else",
        [DIR_ENDIF   ] = "endif",
        [DIR_ENDMAC  ] = "endmac",
        [DIR_ENDSHELL] = "endshell",
        [DIR_ERROR   ] = "error",
        [DIR_IDENT   ] = "ident",
        [DIR_IF      ] = "if",
        [DIR_IFDEF   ] = "ifdef",
        [DIR_IFNDEF  ] = "ifndef",
        [DIR_INCLUDE ] = "include",
        [DIR_LET     ] = "let",
        [DIR_LINE    ] = "line",
        [DIR_MACDEF  ] = "macdef",
        [DIR_OPTION  ] = "option",
        [DIR_PRAGMA  ] = "pragma",
        [DIR_SHELL   ] = "shell",
        [DIR_UNDEF   ] = "undef" };
    char const * res = undef;
    if (id < DIR_COUNT) {
        res = nm_table[id];
        if (res == NULL)
            res = undef;
    }
    return res;
}


/**
 * Dispatch a directive function, based on the keyword.
 *
 * @param[in] str  a string that should start with a known key word.
 * @returns char *, returned by the dispatched function.
 */
char *
doDir_directive_disp(char const * str,
	char * scan_next)
{
    static doDir_hdl_t * const dispatch[22] = {
        [DIR_ASSERT  ] = doDir_assert,
        [DIR_DEFINE  ] = doDir_define,
        [DIR_ELIF    ] = doDir_elif,
        [DIR_ELSE    ] = doDir_else,
        [DIR_ENDIF   ] = doDir_endif,
        [DIR_ENDMAC  ] = doDir_endmac,
        [DIR_ENDSHELL] = doDir_endshell,
        [DIR_ERROR   ] = doDir_error,
        [DIR_IDENT   ] = doDir_ident,
        [DIR_IF      ] = doDir_if,
        [DIR_IFDEF   ] = doDir_ifdef,
        [DIR_IFNDEF  ] = doDir_ifndef,
        [DIR_INCLUDE ] = doDir_include,
        [DIR_LET     ] = doDir_let,
        [DIR_LINE    ] = doDir_line,
        [DIR_MACDEF  ] = doDir_macdef,
        [DIR_OPTION  ] = doDir_option,
        [DIR_PRAGMA  ] = doDir_pragma,
        [DIR_SHELL   ] = doDir_shell,
        [DIR_UNDEF   ] = doDir_undef,
        [DIR_INVALID ] = doDir_invalid };
    static unsigned int keywd_len[] = {
        [DIR_ASSERT  ] = 6,
        [DIR_DEFINE  ] = 6,
        [DIR_ELIF    ] = 4,
        [DIR_ELSE    ] = 4,
        [DIR_ENDIF   ] = 5,
        [DIR_ENDMAC  ] = 6,
        [DIR_ENDSHELL] = 8,
        [DIR_ERROR   ] = 5,
        [DIR_IDENT   ] = 5,
        [DIR_IF      ] = 2,
        [DIR_IFDEF   ] = 5,
        [DIR_IFNDEF  ] = 6,
        [DIR_INCLUDE ] = 7,
        [DIR_LET     ] = 3,
        [DIR_LINE    ] = 4,
        [DIR_MACDEF  ] = 6,
        [DIR_OPTION  ] = 6,
        [DIR_PRAGMA  ] = 6,
        [DIR_SHELL   ] = 5,
        [DIR_UNDEF   ] = 5 };
    directive_enum_t id = find_directive(str);
    unsigned int klen = keywd_len[id];
    doDir_hdl_t * disp = dispatch[id];
    if (disp == NULL)
        disp = dispatch[DIR_INVALID];
    return disp(id, str + klen, scan_next);
}

/** @} */
/* end of directive.c */
