[+: -*- Mode: nroff -*-

  AutoGen5 template mdoc

## agman-file.tpl -- Template for file mdoc pages
##
##  This file is part of AutoOpts, a companion to AutoGen.
##  AutoOpts is free software.
##  AutoOpts is Copyright (C) 1992-2013 by Bruce Korb - all rights reserved
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
##  43b91e8ca915626ed3818ffb1b71248b COPYING.gplv3
##  06a1a2e4760c90ea5e1dad8dfaac4d39 COPYING.lgplv3
##  66a5cedaf62c4b2637025f049f9b826f COPYING.mbsd

# Produce an mdoc page for section 5 - configuration file formats.
#
:+][+:

(define head-line (lambda() (string-append
   ".Dd "   (shell "date '+%B %e %Y' | sed 's/  */ /g'")
   "\n.Dt " UP-PROG-NAME " " man-sect " " section-name
   "\n.Os " (shell "uname -sr") "\n") ))

(define man-page #f)

:+][+:

INCLUDE "cmd-doc.tlib"

:+]
.Sh NAME
.Nm [+: prog-name         :+]
.Nd [+: prog-title        :+]
[+: INVOKE build-doc      :+][+:

(out-move (string-append (get "prog-name") "."
          man-sect))      :+][+:#

.\" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
.\"  S Y N O P S I S
.\" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = :+][+:

DEFINE mk-synopsis                          :+][+:
  (out-push-new file-name)                 \:+]
.Sh SYNOPSIS
.Sy [+: file-path :+]
.Pp [+:

FOR explain   "\n.Pp\n"                     :+][+:
  explain                                   :+][+:
ENDFOR                                      :+][+:

(out-pop)                                   :+][+:

ENDDEF mk-synopsis

agmdoc-file.tpl ends here  :+]
