[= AutoGen5 template -*- Mode: M4 -*-

null

#  Maintainer:        Bruce Korb <bkorb@gnu.org>
#  Created:           Tue Nov 24 01:07:30 1998
#  Last Modified:     $Date: 2005/10/29 00:13:27 $
#             by: bkorb
#
# This template uses the following definitions:
#
# 1.  group  - defines a prefix for the names.  The default is "ac".
# 2.  test   - an autoconf test to perform:
# 2.a  name  - name of the test
# 2.b  type  - "run", "link" or "compile"
# 2.c  check - short display name for user entertainment
# 2.d  code  - the test code to compile, link and/or run.
# 2.e  doc   - useful explanitory text
# 2.f  require - if there are conftest prerequisites
# 2.g  author  - [optional] name of test's author

(setenv "SHELL" "/bin/sh")

=][=

INCLUDE "confmacs.tpl"  =][=

(if (exist? "output-file")
    (begin
      (define ofile (get "output-file"))
      (define separate-macros #f)
      (shellf "echo sending output to %s >&2" ofile)
    )

    (begin
      (define ofile
         (string-append (string-downcase! (get "group")) "_macros.m4") )
      (define separate-macros #t)
)   )
(out-switch ofile)
(define ofile-list ofile)
(define do-all-name (string-append
        "INVOKE_" (string-upcase! (get "group")) "_MACROS" ))

(dne "dnl " "dnl ")             =][=

IF (exist? "do-first")          =]
dnl
dnl do always before generated macros:
dnl
AC_DEFUN([[= (. do-all-name) =]_FIRST],[
[if test X${[= (. do-all-name) =]_FIRST_done} != Xyes ; then]
[= (prefix "  " (join "\n" (stack "do-first"))) =]
[  [= (. do-all-name) =]_FIRST_done=yes
fi]])
[= (if (exist? "do-always") "\n\n") =][=

ENDIF do-first                  =][=

IF (exist? "do-always")         =]
dnl
dnl do always after generated macros:
dnl
AC_DEFUN([[= (. do-all-name) =]_LAST],[
[if test X${[= (. do-all-name) =]_LAST_done} != Xyes ; then]
[= (prefix "  " (join "\n" (stack "do-always"))) =]
[  [= (. do-all-name) =]_LAST_done=yes
fi]])
[=
ENDIF do-always                 =]
dnl
dnl @synopsis  [=(. do-all-name)=]
dnl
dnl  This macro will invoke the AutoConf macros specified in [=(def-file)=]
dnl  that have not been disabled with "omit-invocation".
dnl[=

(if (not separate-macros) (out-push-new)) =]
AC_DEFUN([[=(. do-all-name)=]],[[=

(if (exist? "do-first")
    (string-append "\n  " do-all-name "_FIRST")) =][=

FOR test        =][=
  preamble      =][=
  (if separate-macros
     (begin
        (set! ofile (string-append (string-downcase mac-name) ".m4" ))
        (out-push-new ofile)
        (set! ofile-list (string-append ofile-list "\n" ofile))
     )
     (out-suspend "main-macro")
  )             =][=

  emit-macro    =]
[=(if separate-macros (out-pop) (out-resume "main-macro"))    =][=

  IF (not (exist? "omit-invocation")) =]
  # Check to see if [=check=].
  [=(. mac-name)=]
[=ENDIF         =][=
ENDFOR test     =][=
(if (not separate-macros)
    (out-pop #t)) =][=
(if (exist? "do-always")
    (string-append "\n  " do-all-name "_LAST"))
=]
]) # end AC_DEFUN of [=(. do-all-name)=][=

# end conftest.tpl     =]
