
/*
 *  expFormat.c
 *  $Id: expFormat.c,v 1.2 1999/10/31 00:27:01 bruce Exp $
 *  This module implements formatting expression functions.
 */

/*
 *  AutoGen copyright 1992-1999 Bruce Korb
 *
 *  AutoGen is free software.
 *  You may redistribute it and/or modify it under the terms of the
 *  GNU General Public License, as published by the Free Software
 *  Foundation; either version 2, or (at your option) any later version.
 *
 *  AutoGen is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with AutoGen.  See the file "COPYING".  If not,
 *  write to:  The Free Software Foundation, Inc.,
 *             59 Temple Place - Suite 330,
 *             Boston,  MA  02111-1307, USA.
 */

static const char zGpl[] =
"%2$s%1$s is free software.\n%2$s\n"
"%2$sYou may redistribute it and/or modify it under the terms of the\n"
"%2$sGNU General Public License, as published by the Free Software\n"
"%2$sFoundation; either version 2, or (at your option) any later version.\n"
"%2$s\n"
"%2$s%1$s is distributed in the hope that it will be useful,\n"
"%2$sbut WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"%2$sMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
"%2$sSee the GNU General Public License for more details.\n"
"%2$s\n"
"%2$sYou should have received a copy of the GNU General Public License\n"
"%2$salong with %1$s.  See the file \"COPYING\".  If not,\n"
"%2$swrite to:  The Free Software Foundation, Inc.,\n"
"%2$s           59 Temple Place - Suite 330,\n"
"%2$s           Boston,  MA  02111-1307, USA.";

static const char zLgpl[] =
"%2$s%1$s is free software.\n%2$s\n"
"%2$sYou may redistribute it and/or modify it under the terms of the\n"
"%2$sGNU General Public License, as published by the Free Software\n"
"%2$sFoundation; either version 2, or (at your option) any later version.\n"
"%2$s\n"
"%2$s%1$s is distributed in the hope that it will be useful,\n"
"%2$sbut WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"%2$sMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
"%2$sSee the GNU General Public License for more details.\n"
"%2$s\n"
"%2$sYou should have received a copy of the GNU General Public License\n"
"%2$salong with %1$s.  See the file \"COPYING\".  If not,\n"
"%2$swrite to:  The Free Software Foundation, Inc.,\n"
"%2$s           59 Temple Place - Suite 330,\n"
"%2$s           Boston,  MA  02111-1307, USA.\n"
"%2$s\n"
"%2$sAs a special exception, %3$s gives permission for additional\n"
"%2$suses of the text contained in the release of %1$s.\n"
"%2$s\n"
"%2$sThe exception is that, if you link the %1$s library with other\n"
"%2$sfiles to produce an executable, this does not by itself cause the\n"
"%2$sresulting executable to be covered by the GNU General Public License.\n"
"%2$sYour use of that executable is in no way restricted on account of\n"
"%2$slinking the %1$s library code into it.\n"
"%2$s\n"
"%2$sThis exception does not however invalidate any other reasons why\n"
"%2$sthe executable file might be covered by the GNU General Public License.\n"
"%2$s\n"
"%2$sThis exception applies only to the code released by %3$s under\n"
"%2$sthe name %1$s.  If you copy code from other sources under the\n"
"%2$sGeneral Public License into a copy of %1$s, as the General Public\n"
"%2$sLicense permits, the exception does not apply to the code that you add\n"
"%2$sin this way.  To avoid misleading anyone as to the status of such\n"
"%2$smodified files, you must delete this exception notice from them.\n"
"%2$s\n"
"%2$sIf you write modifications of your own for %1$s, it is your choice\n"
"%2$swhether to permit this exception to apply to your modifications.\n"
"%2$sIf you do not wish that, delete this exception notice.";

static const char zDne[] =
"%1$sDO NOT EDIT THIS FILE   (%2$s)\n"
"%1$s\n"
"%1$sIt has been AutoGen-ed  %3$s\n"
"%1$sFrom the definitions    %4$s\n"
"%1$sand the template file   %5$s";

#include <string.h>

#include "autogen.h"
#include <guile/gh.h>
#include "expGuile.h"

#ifndef HAVE_STRFTIME
#  include "compat/strftime.c"
#endif

tSCC zFmtAlloc[] = "asprintf allocation";


/*=gfunc dne
 *
 * exparg: prefix, string for starting each output line
 * doc:  Generate a "Do Not Edit" warning string.
 *      The argument is a per-line string prefix.
=*/
    SCM
ag_scm_dne( SCM prefix )
{
    char*    pzPfx;
    char*    pzRes;
    SCM      res;
    char     zTimeBuf[ 128 ];

    if (! gh_string_p( prefix ))
        return SCM_UNDEFINED;
    pzPfx = SCM_CHARS( prefix );

    {
        time_t    curTime = time( (time_t*)NULL );
        struct tm*  pTime = localtime( &curTime );
        strftime( zTimeBuf, 128, "%A %B %e, %Y at %r %Z", pTime );
    }

    pzRes = asprintf( zDne, pzPfx, pCurFp->pzName,
                      zTimeBuf, pzDefineFileName, pzTemplFileName );

    if (pzRes == (char*)NULL) {
        fprintf( stderr, zAllocErr, pzProg, -1, "Do-Not-Edit string" );
        LOAD_ABORT( pCurTemplate, pCurMacro, zFmtAlloc );
    }

    res = gh_str02scm( pzRes );
    AGFREE( (void*)pzRes );
    return res;
}


/*=gfunc error
 *
 * exparg: @message@message to display before exiting@@
 * doc:
 *
 *  The argument is a string that printed out as part of an error
 *  message.  The message is formed from the formatting string:
 *
 *  @example
 *  DEFINITIONS ERROR in %s line %d for %s:  %s\n
 *  @end example
 *
 *  The first three arguments to this format are provided by the
 *  routine and are: The name of the template file, the line within
 *  the template where the error was found, and the current output
 *  file name.
 *
 *  After displaying the message, the current output file is removed
 *  and autogen exits with the EXIT_FAILURE error code.  IF, however,
 *  the argument is the number 0 (zero), then processing continues
 *  with the next suffix.
=*/
    SCM
ag_scm_error( SCM res )
{
    tSCC      zErr[] = "DEFINITIONS ERROR in %s line %d for %s:  %s\n";
    tSCC      zBadMsg[] = "??? indecipherable error message ???";
    tCC*      pzMsg;
    tSuccess  abort = FAILURE;
    char      zNum[16];

    switch (gh_type_e( res )) {
    case GH_TYPE_BOOLEAN:
        if (SCM_FALSEP( res ))
            abort = PROBLEM;
        pzMsg = "";
        break;

    case GH_TYPE_NUMBER:
    {
        long val = gh_scm2long( res );
        if (val == 0)
            abort = PROBLEM;
        sprintf( zNum, "%d", val );
        pzMsg = zNum;
        break;
    }

    case GH_TYPE_CHAR:
        zNum[0] = gh_scm2char( res );
        if ((zNum[0] == '\0') || (zNum[0] == '0'))
            abort = PROBLEM;
        zNum[1] = NUL;
        pzMsg = zNum;
        break;

    case GH_TYPE_STRING:
        pzMsg = SCM_CHARS( res );
        while (isspace( *pzMsg )) pzMsg++;
        if (isdigit( *pzMsg ) && (strtol( pzMsg, (char**)NULL, 0 ) == 0))
            abort = PROBLEM;
        else abort = (*pzMsg != '\0');
        break;

    default:
        pzMsg = zBadMsg;
    }

    fprintf( stderr, zErr, pCurTemplate->pzFileName, pCurMacro->lineNo,
             pCurFp->pzName, pzMsg );
    longjmp( fileAbort, abort );
    /* NOTREACHED */
    return SCM_UNDEFINED;
}


/*=gfunc gpl
 *
 * exparg: prog_name, name of the program under the GPL
 * exparg: prefix, String for starting each output line
 *
 * req: 2
 *
 * doc:
 *
 *  Emit a string that contains the GNU Public License.  It
 *  takes two arguments: @code{prefix} contains the string to start
 *  each output line, and
 *  @code{prog_name} contains the name of the program the copyright is
 *  about.
 *
=*/
    SCM
ag_scm_gpl( SCM prog_name, SCM prefix )
{
    char*     pzName;
    char*     pzPfx;
    char*     pzRes;
    SCM       res;

    if (! (   gh_string_p( prog_name )
           && gh_string_p( prefix )))
        return SCM_UNDEFINED;

    pzName  = SCM_CHARS( prog_name );
    pzPfx   = SCM_CHARS( prefix );

    pzRes = asprintf( zGpl, pzName, pzPfx );

    if (pzRes == (char*)NULL) {
        fprintf( stderr, zAllocErr, pzProg, -1, "GPL string" );
        LOAD_ABORT( pCurTemplate, pCurMacro, zFmtAlloc );
    }

    res = gh_str02scm( pzRes );
    AGFREE( (void*)pzRes );
    return res;
}


/*=gfunc lgpl
 *
 * exparg: prog_name, name of the program under the LGPL
 * exparg: owner, Grantor of the LGPL
 * exparg: prefix, String for starting each output line
 * req: 3
 *
 * doc:
 *
 *  Emit a string that contains the GNU Library Public License.  It
 *  takes three arguments: @code{prefix} contains the string to start
 *  each output line.  @code{owner} contains the copyright owner.
 *  @code{prog_name} contains the name of the program the copyright is
 *  about.
 *
=*/
    SCM
ag_scm_lgpl( SCM prog_name, SCM owner, SCM prefix )
{
    char*     pzName;
    char*     pzPfx;
    char*     pzOwner;
    char*     pzRes;
    SCM       res;

    if (! (   gh_string_p( prog_name )
           && gh_string_p( owner )
           && gh_string_p( prefix )))
        return SCM_UNDEFINED;

    pzName  = SCM_CHARS( prog_name );
    pzPfx   = SCM_CHARS( prefix );
    pzOwner = SCM_CHARS( owner );

    pzRes = asprintf( zLgpl, pzName, pzPfx, pzOwner );

    if (pzRes == (char*)NULL) {
        fprintf( stderr, zAllocErr, pzProg, -1, "LGPL string" );
        LOAD_ABORT( pCurTemplate, pCurMacro, zFmtAlloc );
    }

    res = gh_str02scm( pzRes );
    AGFREE( (void*)pzRes );
    return res;
}
/* end of expFormat.c */
