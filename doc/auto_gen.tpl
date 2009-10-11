[= AutoGen5 template

##  Documentation template
##
## Author:            Bruce Korb <bkorb@gnu.org>
## Time-stamp:        "2008-12-27 16:50:28 bkorb"
##
##  This file is part of AutoGen.
##  AutoGen copyright (c) 1992-2009 by Bruce Korb - all rights reserved
##
##  AutoGen is free software: you can redistribute it and/or modify it
##  under the terms of the GNU General Public License as published by the
##  Free Software Foundation, either version 3 of the License, or
##  (at your option) any later version.
##
##  AutoGen is distributed in the hope that it will be useful, but
##  WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
##  See the GNU General Public License for more details.
##
##  You should have received a copy of the GNU General Public License along
##  with this program.  If not, see <http://www.gnu.org/licenses/>.
## ---------------------------------------------------------------------
## $Id$
## ---------------------------------------------------------------------

texi=autogen.texi

# Set up some global Scheme variables
#
(setenv "SHELL" "/bin/sh")

(make-tmp-dir)

(define texi-file-source (shell "
    exec 2> ${tmp_dir}/ag-texi.log
    set -x
    if [ -f autogen-texi.txt ]
    then
      echo autogen-texi.txt
    elif [ -f ${top_srcdir}/doc/autogen-texi.txt ]
    then
      echo ${top_srcdir}/doc/autogen-texi.txt
    else
      die Cannot locate original autogen-texi.txt file
    fi" ))

(define texi-escape-encode (lambda (in-str)
   (string-substitute in-str
      '("@"   "{"   "}")
      '("@@"  "@{"  "@}")
)  ))

(define temp-txt  "")
(define text-tag  "")
(define func-name "")
(define func-str  "")
(define func-name "")
(define func-str  "")

=][= # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

\=]
\input texinfo
@ignore
\internalpagesizes{46\baselineskip}{6in}{-.25in}{-.25in}{\bindingoffset}{36pt}%
@end ignore
@c %**start of header
@setfilename [=(base-name)=].info
@settitle AutoGen - [= prog-title =]
@setchapternewpage off
@syncodeindex pg cp
@c %**end of header
@copying
This manual is for GNU AutoGen version [= `
  UPDATED=\`date '+%B %Y'\`
  echo ${AG_REVISION}, updated ${UPDATED}` =].

Copyright @copyright{} [= copyright.date =] by Bruce Korb.

@quotation
Permission is granted to copy, distribute and/or modify this document
under the terms of the GNU Free Documentation License, Version 1.2 or
any later version published by the Free Software Foundation; with no
Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
@end quotation
@end copying

@ignore
[=(set-writable) (dne "")=]

Plus bits and pieces gathered from all over the source/build
directories:
[= ` for f in ${DOC_DEPENDS} ; do echo "    $f" ; done ` =]

@end ignore

@dircategory GNU programming tools
@direntry
* AutoGen: (autogen).         [= prog-title =]
@end direntry

@ifinfo
@ifnothtml
This file documents [= package =] Version [=`echo ${AG_REVISION}`=].

AutoGen copyright @copyright{} [= copyright.date =] Bruce Korb
AutoOpts copyright @copyright{} [= copyright.date =] Bruce Korb
snprintfv copyright @copyright{} 1999-2000 Gary V. Vaughan

[=(gpl "AutoGen" "")=]

@ignore
Permission is granted to process this file through TeX and print the
results, provided the printed document carries copying permission
notice identical to this one except for the removal of this paragraph.
@end ignore
@end ifnothtml
@end ifinfo

@finalout
@titlepage
@title AutoGen - [= prog-title =]
@subtitle For version [=`
  echo ${AG_REVISION}, ${UPDATED} `=]
@author Bruce Korb
@author @email{[= (texi-escape-encode "bkorb@gnu.org") =]}

@page
@vskip 0pt plus 1filll
AutoGen copyright @copyright{} [= copyright.date =] Bruce Korb
@sp 2
This is the second edition of the GNU AutoGen documentation,
@sp 2
Published by Bruce Korb, 910 Redwood Dr., Santa Cruz, CA  95060

[=(gpl "AutoGen" "")=]

@insertcopying
@end titlepage

@ifinfo

@node Top, Introduction, , (dir)
@top The Automated Program Generator
@comment  node-name,  next,  previous,  up

This file documents AutoGen version [=`
  echo ${AG_REVISION}`=].  It is a tool designed
for generating program files that contain repetitive text with varied
substitutions.  This document is very long because it is intended as a
reference document.  For a quick start example, @xref{Example Usage}.

The AutoGen distribution includes the basic generator engine and
several add-on libraries and programs.  Of the most general interest
would be Automated Option processing, @xref{AutoOpts}, which also
includes stand-alone support for configuration file parsing, @xref{Features}.
Please see the ``Add-on packages for AutoGen'' section for additional
programs and libraries associated with AutoGen.

This edition documents version [=`echo ${AG_REVISION}, ${UPDATED}.`=]
[=

INVOKE  get-text tag = main

=]
[=
FOR directive =][=
  (if (exist? "dummy")
      (string-downcase! (sprintf "@samp{#%s}, " (get "name")))) =][=
ENDFOR directive=] and @samp{#if}.
Note that when ignoring the @code{#if} directive, all intervening
text through its matching @code{#endif} is also ignored,
including the @code{#else} clause.

The AutoGen directives that affect the processing of
definitions are:

@table @code[=
FOR directive "\n" =][=
  IF (exist? "text") =]
@item #[=% name (string-downcase! "%s") =][= % arg " %s" =]
@cindex #[=% name (string-downcase! "%s") =]
@cindex [=% name (string-downcase! "%s") =] directive
[= id-file =]
[=text     =][=
  ENDIF    =][=
ENDFOR directive=]
@end table
[=

INVOKE   get-text tag = COMMENTS

=]
@node    Full Syntax
@section Finite State Machine Grammar

The preprocessing directives and comments are not part of the grammar.  They
are handled by the scanner/lexer.  The following was extracted directly from
the generated defParse-fsm.c source file.  The "EVT:" is the token seen,
the "STATE:" is the current state and the entries in this table describe
the next state and the action to take.  Invalid transitions were removed
from the table.

@ignore
Extracted from $top_srcdir/agen5/defParse.y
@end ignore
@example
[= `

if test -z "$top_srcdir" || test ! -d "$top_srcdir"
then top_srcdir=.. ; fi
f=${top_srcdir}/agen5/defParse-fsm.c
test -f ${f} || die missing generated file: $f
sed -n -e '/^dp_trans_table/,/^};$/p' ${f} | \
  sed '/ \&dp_do_invalid /d;/^ *}/d;s/@/@@/g;s/{/@{/g;s/}/@}/g'

` =]
@end example
[=

INVOKE  get-text tag = TEMPLATE

=]
@ignore

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@end ignore
@page
@node AutoGen Functions
@section AutoGen Scheme Functions

AutoGen uses Guile to interpret Scheme expressions within AutoGen
macros.  All of the normal Guile functions are available, plus several
extensions (@pxref{Common Functions}) have been added to
augment the repertoire of string manipulation functions and
manage the state of AutoGen processing.

This section describes those functions that are specific to AutoGen.
Please take note that these AutoGen specific functions are not loaded
and thus not made available until after the command line options have
been processed and the AutoGen definitions have been loaded.  They may,
of course, be used in Scheme functions that get defined at those times,
but they cannot be invoked.

@menu[=

FOR gfunc    =][=
  (if (not (exist? "name"))
      (error "NO NAME"))          =][=

  IF (not (exist? "general_use")) =][=
    INVOKE emit-menu-entry        =][=
  ENDIF      =][=

ENDFOR gfunc =]
* SCM autogen-version::     @file{autogen-version} - ``[= version =]''
* SCM c-file-line-fmt::     format file info as, ``@code{#line nn "file"}''
@end menu

[=
FOR gfunc =][=
  IF (not (exist? "general_use")) =][=
    INVOKE emit-scm-func          =][=
  ENDIF general_use               =][=
ENDFOR gfunc
=]
@ignore
Generated [= (tpl-file-line) =].
@end ignore

@node SCM autogen-version
@subsection @file{autogen-version} - autogen version number
@findex autogen-version

This is a symbol defining the current AutoGen version number string.
It was first defined in AutoGen-5.2.14.
It is currently ``[= version =]''.

@node SCM c-file-line-fmt
@subsection format file info as, ``@code{#line nn "file"}''
@findex c-file-line-fmt

This is a symbol that can easily be used with the functions
@xref{SCM tpl-file-line}, and @xref{SCM def-file-line}.
These will emit C program @code{#line} directives pointing to template
and definitions text, respectively.
@ignore

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@end ignore
@page
@node Common Functions
@section Common Scheme Functions

This section describes a number of general purpose functions that make
the kind of string processing that AutoGen does a little easier.
Unlike the AutoGen specific functions (@pxref{AutoGen Functions}),
these functions are available for direct use during definition load time.
The equality test (@pxref{SCM =}) is ``overloaded'' to do string equivalence
comparisons.  If you are looking for inequality, the Scheme/Lisp way
of spelling that is, ``(not (= ...))''.

@menu[=

FOR gfunc                   =][=

  IF (exist? "general_use") =][=
    INVOKE emit-menu-entry  =][=
  ENDIF                     =][=

ENDFOR gfunc

=]
@end menu

[=

FOR gfunc =][=
  IF (exist? "general_use") =][=
    INVOKE emit-scm-func    =][=
  ENDIF general_use         =][=
ENDFOR gfunc

=][=

INVOKE  get-text tag = MACROS

=]
@menu
* AGMacro syntax::   AutoGen Macro Syntax[=
FOR macfunc =][=
  IF (exist? "desc") =][=
    (sprintf "\n* %-18s %s - %s"
       (string-append  (get "name") "::" )
       (string-upcase! (get "name"))
       (get "what") ) =][=
  ENDIF =][=
ENDFOR macfunc=]
@end menu
@node AGMacro syntax
@subsection AutoGen Macro Syntax
@cindex macro syntax

The general syntax is:

@example
[ @{ <native-macro-name> | <user-defined-name> @} ] [ <arg> ... ]
@end example

@noindent
The syntax for @code{<arg>} depends on the particular macro,
but is generally a full expression (@pxref{expression syntax}).
Here are the exceptions to that general rule:

@enumerate
@item
@code{INVOKE} macros, implicit or explicit, must be followed by
a list of name/string value pairs.  The string values are
@i{simple expressions}, as described above.

That is, the @code{INVOKE} syntax is one of these two:
@example
<user-macro-name> [ <name> [ = <expression> ] ... ]

INVOKE <name-expression> [ <name> [ = <expression> ] ... ]
@end example

@item
AutoGen FOR macros must be in one of three forms:

@example
FOR <name> [ <separator-string> ]

FOR <name> (...Scheme expression list)

FOR <name> IN <string-entry> [ ... ]
@end example
@noindent
where:
@table @samp
@item <name>
must be a simple name.
@item <separator-string>
is inserted between copies of the enclosed block.  Do not try to use ``IN''
as your separator string.  It won't work.
@item <string-entry>
is an entry in a list of strings.  ``@code{<name>}'' is assigned
each value from the ``@code{IN}'' list before expanding the @code{FOR} block.
@item (...Scheme expression list)
is expected to contain one or more of the @code{for-from},
@code{for-to}, @code{for-by}, and @code{for-sep} functions.
(@xref{FOR}, and @ref{AutoGen Functions})
@end table

The first two forms iterate over the @code{FOR} block if @code{<name>}
is found in the AutoGen values.  The last form will create the AutoGen
value named @code{<name>}.

@item
AutoGen @code{DEFINE} macros must be followed by a simple name.
Anything after that is ignored.  Consequently, that ``comment space''
may be used to document any named values the macro expects to have
set up as arguments.  @xref{DEFINE}.

@item
The AutoGen @code{COMMENT}, @code{ELSE}, @code{ESAC} and the @code{END*}
macros take no arguments and ignore everything after the macro name
(e.g. see @ref{COMMENT})
@end enumerate[=


#  FOR each defined function,
      this code will insert the extracted documentation =][=

FOR macfunc =][=
  IF (exist? "desc") =]

@node [=name=]
@subsection [=% name (string-upcase! "%s") =] - [=what=]
[= id-file =]
@findex [=% name (string-upcase! "%s") =][=
  (if (exist? "cindex")
      (string-append "\n@cindex "
         (join "\n@cindex " (stack "cindex")) ))  =]

[=desc=][=
  ENDIF desc exists =][=
ENDFOR macfunc=]
[=

INVOKE  get-text tag = augmenting

=]
@ignore

Invocation section from [= `

f=../agen5/autogen.texi
[ -f $f ] || f=${top_srcdir}/agen5/autogen.texi

cat <<_EOF_
${f}

@end ignore
@page

_EOF_

cat ${f}` =]
[=

INVOKE  get-text tag = installation     =][=
INCLUDE "auto-opts.tpl"

=]
@page
@node Add-Ons
@chapter Add-on packages for AutoGen

This chapter includes several programs that either work closely
with AutoGen (extracting definitions or providing special formatting
functions), or leverage off of AutoGen technology.  There is also
a formatting library that helps make AutoGen possible.

AutoOpts ought to appear in this list as well, but since it is
the primary reason why many people would even look into AutoGen
at all, I decided to leave it in the list of chapters.

@menu
* AutoFSM::                        Automated Finite State Machine
* AutoXDR::                        Combined RPC Marshalling
* AutoEvents::                     Automated Event Management
[=`cat  ${ADDON_MENU}`=]
@end menu
[=

INVOKE  get-text tag = autofsm

=][= `

echo

for f in ${ADDON_TEXI}
do
   echo '@page'
   echo '@ignore'
   echo '* * * * * * * * * * * * * * * * *'
   echo "Copy of text from $f"
   echo '@end ignore'
   cat $f
done

` =]
[=

INVOKE  get-text tag = Future

=]
@page
@node Future
@chapter Some ideas for the future.
@cindex futures

Here are some things that might happen in the distant future.

@itemize @bullet
@item
Fix up current tools that contain
miserably complex perl, shell, sed, awk and m4 scripts
to instead use this tool.
@end itemize
@node Copying This Manual
@appendix Copying This Manual

You may copy this manual under the terms of the FDL
(@url{http://gnu.org/licenses/fdl.texi,the GNU Free Documentation License}).

[=`sed '1,/^@appendixsec/d' fdl.texi`=]

@page
@node Concept Index
@unnumbered Concept Index

@printindex cp
@page
@node Function Index
@unnumbered Function Index

@printindex fn
@page
@contents
@bye
[= `chmod -r 555 ${tmp_dir} ; echo TEMP DIR IS ${tmp_dir} >/dev/tty` =][=

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

=][=

DEFINE id-file =]
@ignore
Generated [= (tpl-file-line) =].
Extracted from [=srcfile=] line [=linenum=].
@end ignore[=

ENDDEF  id-file

# # # # # # # # # # # # # # # # # # # # =][=

DEFINE get-text     =][=

(set! text-tag
   (string-append "@ignore\n%s == "
      (string-upcase! (get "tag")) " == %s or the surrounding 'ignore's\n"
      "Extraction from autogen.texi\n"
      "@end ignore" ))

(extract texi-file-source text-tag) =][=

ENDDEF get-text

# # # # # # # # # # # # # # # # # # # # =][=

DEFINE set-func-name =][=

  (set! func-name (shell (sprintf "echo '%s' |
    sed -e 's/-p$/?/' -e 's/-x$/!/' -e 's/-to-/->/'"
    (string-tr! (get "name") "A-Z_^" "a-z--") )) )

  (set! func-str
      (if (exist? "string") (get "string") func-name)) =][=

ENDDEF

# # # # # # # # # # # # # # # # # # # # =][=

DEFINE emit-scm-func     =][=

  INVOKE  set-func-name  =]
@node SCM [= (. func-str)=]
@subsection [= (string-append "@file{" func-name "} - " (get "what")) =]
@findex [= (. func-name) =][=
% string "\n@findex %s"  =]
[=     id-file           =]
Usage:  ([= (. func-str) =][=

    FOR exparg           =] [=

      arg_optional  "[ " =][=arg_name=][= arg_list " ..." =][=
      arg_optional  " ]" =][=

    ENDFOR   exparg      =])
@*
[= string (string-append func-name ":  ") =][=
   (shell (string-append
          "(sed \"s/^\\`'//\" <<\\_EODoc_\n"
          (if (exist? "doc") (get "doc") "This function is not documented.")
          "\n_EODoc_\n)" ))=]
[=
    IF (exist? "exparg") =]
Arguments:[=
      FOR exparg         =]
@*
[=arg_name=] - [=

    arg_optional "Optional - " =][=
        IF (exist? "arg_desc") =][=arg_desc=][=
        ELSE             =]Undocumented[=
        ENDIF            =][=

      ENDFOR exparg      =][=

    ELSE
    =]
This Scheme function takes no arguments.[=
    ENDIF                =]
[=

ENDDEF

# # # # # # # # # # # # # # # # # # # # =][=

DEFINE emit-menu-entry   =][=

   INVOKE set-func-name  =][=
   (sprintf "\n* SCM %-20s @file{%s} - %s"  (string-append func-str "::")
            func-name (get "what"))
   =][=
ENDDEF  emit-menu-entry

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

=][= #

;; Local Variables:
;; indent-tabs-mode: nil
;; mode: texinfo
;; End:

=]
