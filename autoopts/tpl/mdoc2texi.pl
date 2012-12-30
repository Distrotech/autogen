#! /usr/bin/perl

use strict;

my ($optlist,$oldoptlist);
my ($literal);
my ($line);
my ($count,$tableitemcount);
my ($progName);
my (@words, $retval,$columnline);
my ($extArg);
my (%anchor, $aCount);

$aCount = 0;
$optlist = 0;       ### 1 = bullet, 2 = enum, 3 = tag, 4 = item/column
$oldoptlist = 0;
$extArg = 0;

###
#
# We don't know what order we'll see .Sx
#
# Whenever we find one, we look it up.
# If it doesn't exist we assign it an anchor name.
# Regardless, we "return" the anchor name, as we're either going
# to define the anchor point using '@anchor{anchor-1}' or reference
# the anchor using something like '@xref{anchor-1,,whatever}'
#
###

while ($line = <STDIN>)
{
    if ($line !~ /^\./)
    {
        print $line;
        print ".br\n"
            if ($literal);              # $literal is never 'true'...
        next;
    }

    next
        if ($line =~ /^\.\\"/);

    $line = ParseMacro($line);
    print($line)
        if (defined $line);
}

sub Anchor ($)
{
    my $string = shift;

    # Look up the provided string.
    # If it's not there, bump $aCount and "add" the anchor.
    # Return the anchor.

    if (!exists $anchor{$string})
    {
        ++$aCount;
        $anchor{$string} = "anchor-$aCount";
    }

    return $anchor{$string};
}

sub Handle_An
{
    # We should eventually support -nosplit and -split.
    # Usage: .An <author name> ...
    #   .An "Joe Author"                Joe Author
    #   .An "Joe Author"                Joe Author,
    #   .An "Joe Author" Aq user@site   Joe Author <user@site>
    #   .An "Joe Author" ) ) ,          Joe Author)),

    do {
        if ($words[0] =~ /^"/)
        {
            print parseQuote(\@words);
        }
        else
        {
            print "$words[0]";
        }
        shift @words;
    } while scalar(@words);
    print "@*";
}

sub Handle_Bl
{
    # Must end with a .El.  May be nested, including inside displays.
    #
    # .Bl {-hang | -ohang | -tag | -diag | -inset} [-width <string>] \
    #    [-offset <string>]
    # .Bl -colimn [-offset <string>] <string1> <string2> ...
    # .Bl {-item | -enum [-nested] | -bullet | -hyphen | -dash} \
    #    [-offset <string>] [-compact]
    # "-offset indent" uses a standard indent.
    # -compact suppresses insertion of vertical space before the list and
    # between the list items.

    if ($words[0] eq '-bullet')
    {
        if (!$optlist)
        {
            $optlist = 1;       # bullet
            $retval .= "\@itemize \@bullet\n" ;
            print "$retval";
            return 1;
        }
        else
        {
            $retval .= "\@itemize \@minus\n";
            print $retval;
            $oldoptlist = 1;
            return 1;
        }
    }
    if ($words[0] eq '-enum')
    {
        if (!$optlist)
        {
            $optlist = 2;       # enum
            $retval .= "\@enumerate\n" ;
            print "$retval";
            return 1;
        }
        else
        {
            $retval .= "\@enumerate\n";
            print $retval;
            $oldoptlist = 2;
            return 1;
        }
    }
    if ($words[0] eq '-tag')
    {
        $optlist = 3;           # tag
        $retval .= "\@table \@samp\n";
        print "$retval";
        return 1;
    }
    if ($words[0] eq '-column')
    {
        $optlist = 4;           # column
        $retval = "\@multitable \@columnfractions ";#\.20 \.20 \.20\n";
        #print $retval;
        $columnline = "\@headitem ";
        #print $retval;
        foreach(@words)
        {
            if (!/^"./ && !/-column/ && !/indent/ && !/-offset/)
            {
                $_ =~ s/\"//g;

                $retval .= "\.20 ";
                if (!$count)
                {
                    $columnline .= $_;
                }
                else
                {
                    $columnline .= " \@tab ".$_;
                }
                $count++;
            }
        }
        print $retval."\n";
        print $columnline;
        return 1;
    }

    return 0;
}

sub Handle_It
{
    # .It Li "sntp ntpserver.somewhere"

    if ($optlist == 3)                  # tag
    {
        $retval .= "\@item ".$words[0]."\n";
        print $retval;
        return 1;
    }
    elsif ($optlist == 4 )              # column/Item list
    {
        if (!$tableitemcount)
        {
            $tableitemcount = 1;
            return 1;
        }
        else
        {
            foreach(@words)
            {
                if (/^Li$/)
                {
                    print "\n\@item ";
                    return 0;
                }
                elsif (/^Ta$/)  # separate columns
                {
                    print "\n\@tab ";
                    return 0;
                }
                else
                {
                    print $_;
                    return 0;
                }
            }
            return 1;
        }
    }
    else
    {
        print "\@item\n";
    }
    return 0;
}

sub Handle_El
{
    if ($oldoptlist)
    {
        if ($oldoptlist == 1)
        {
            $oldoptlist = 0;
            $retval .= "\@end itemize\n";
            print $retval;
        }
        elsif ($oldoptlist == 2)
        {
            $oldoptlist = 0;
            $retval .= "\@end enumerate\n";
            print $retval;
        }
    }
    else
    {
        if ($optlist == 1)
        {
            $oldoptlist = 0;
            $retval .= "\@end itemize\n";
            print $retval;
        }
        elsif ($optlist == 2)
        {
            $oldoptlist = 0;
            $retval .= "\@end enumerate\n";
            print $retval;
        }
        elsif ($optlist == 3)
        {
            $oldoptlist = 0;
            $retval .= "\@end table\n";
            print $retval;
        }
        elsif ($optlist == 4)
        {
            $count = 0;
            $columnline = '';
            $oldoptlist = 0;
            $optlist = 0;
            $tableitemcount = 0;
            $retval .= "\n\@end multitable\n";
            print $retval;
        }
        else
        {
            die "optlist <$optlist> was not expected.";
        }
        $optlist = 0;
    }
}

sub Handle_Em
{
    # Usage: .Em stuff
    #   .Em word                <italic>word</italic>
    #   .Em or Ap ing           <italic>or</italic>'ing
    #

    parseQuote(\@words) if ($words[0] =~ /^"/);

    print '@emph{';
    do {
        print shift @words;
    } while (@words > 0 && $words[0] !~ /^[[:punct:]]$/);
    print "}";

    while ($_ = shift @words)
    {
        print;
    }

    print "\n";
}

sub Handle_ArCmFlIc
{
    # .Ar wants an italic code font, texi uses @kbd for that.
    # .Cm is .Fl but no '-'.
    # Usage: .Fl <argument> ...
    #
    #   .Fl          -
    #   .Fl cfv      -cfv
    #   .Fl cfv .    -cfv.
    #   .Cm cfv .    cfv.
    #   .Fl s v t    -s -v -t
    #   .Fl - ,      --,
    #   .Fl xyz ) ,  -xyz),
    #   .Fl |        - |
    #   .Ic "do while {...}"    do while {...}
    #
    my ($dash, $didOne, $font, $spacing);

    s/^\.//;

    $dash = (/^Fl$/) ? "-" : "";
    $font = (/^Ar$/) ? "\@kbd{" : "\@code{";
    $didOne = 0;
    $spacing = 1;

    do {
        if ($words[0] eq '|')
        {
            print " " if $didOne && $spacing;
            print '@code{', $dash, '} ' if ($dash ne "");
            print "$words[0]";
        }
        elsif ($words[0] eq '-')
        {
            print " " if $didOne && $spacing;
            print '@code{', $dash, $words[0], '}';
        }
        elsif ($words[0] =~ /^"/)
        {
            print " " if $didOne && $spacing;
            print '@code{';
            print $dash if ($dash ne "");       # Do we need this?
            parseQuote(\@words);
            print $words[0];
            print '}';
        }
        elsif ($words[0] eq 'Ar')               # Argument
        {
            $font = '@kbd{';                    # slanted tty
        }
        elsif ($words[0] eq 'Ic')               # Interactive/internal command
        {
            $font = '@code{';
        }
        elsif ($words[0] eq 'Xc')
        {
            $spacing = 1;
        }
        elsif ($words[0] eq 'Xo')
        {
            $spacing = 0;
        }
        elsif ($words[0] =~ /^[[:punct:]]$/)
        {
            # print " " if $didOne && $spacing;
            print $words[0];
        }
        else            # Should be empty or a word
        {
            print " " if $didOne && $spacing;
            print '@code{';
            print $dash if ($dash ne "");       # Do we need this?
            print $words[0];
            print '}';
        }
        shift @words;
        $didOne = 1;
    } while scalar(@words);
    print " ";
}

sub Handle_Fn
{
    # Usage: .Fn <function> [<parameter>] ...
    #   .Fn getchar             <code>getchar</code>()
    #   .Fn strlen ) ,          <code>strlen</code>()),
    #   .Fn align "char *pt" ,  <code>align</code(<slant>char *pt<slant>),
    #
    my ($didArg, $isOpen);

    print '@code{', $words[0], "}(";
    $isOpen = 1;
    shift;

    $didArg = 0;
    while ($_ = shift @words)
    {
        if ($words[0] =~ /^"/) {
            # assert $isOpen == 1
            print '@code{, }' if ($didArg);
            parseQuote(\@words);
            print '@emph{', $words[0], "}";
            $didArg = 1;
        } else {
            print ")" if ($isOpen);
            $isOpen = 0;
            print $words[0];
        }
    }

    print "\n";
}

sub Handle_Nm
{
    # Usage: .Nm [<argument>] ...
    #
    #   .Nm groff_mdoc  groff_mdoc
    #   .Nm \-mdoc      -mdoc
    #   .Nm foo ) ) ,   foo)),
    #   .Nm :           groff_mdoc:
    #
    if (!defined $progName)
    {
        if (defined $ENV{AG_DEF_PROG_NAME})
        {
            $progName = $ENV{AG_DEF_PROG_NAME};
        }
        else
        {
            $progName = "XXX Program Name";
        }
    }

    if ($words[0] =~ /^[\\\w]/)
    {
        $progName = shift @words;
    }
    print '@code{', $progName, '}';

    # Anything after this should be punctuation

    while ($_ = shift @words)
    {
        print;
    }
    print "\n";
}

sub Handle_Op
{
    # Usage: .Op [<option>] ...
    #   .Op                                     []
    #   .Op Fl k                                [-k]
    #   .Op Fl k ) .                            [-k]).
    #   .Op Fl c Ar objfil Op Ar corfil ,       [ -c objfil [corfil]],
    #   .Op word1 word2                         [word1 word2]
    #
    # If we decide to support Oo and Oc this almost becomes recursive,
    # but we can handle that with separate Handle_Oo and Handle_Oc
    # routines.

    my ($op);

    print '[';
    $op = 1;
    do {
        if ($op && $words[0] =~ /^(Ar|Cm|Fl|Ic)$/)
        {
                $_ = shift @words;
                Handle_ArCmFlIc();
        }
        elsif ($words[0] =~ /^[[:punct:]]$/)
        {
                print ']' if ($op);
                $op = 0;
                print shift @words;
        }
        else
        {
                print shift @words;
        }
    } while (@words > 0);
    print ']' if ($op);
    print "\n";                 # HMS: We may not want these in many places...
}

sub Handle_Pa
{
    # Usage: .Pa [<pathname>] ...
    #   .Pa                     ~
    #   .Pa /usr/share          /usr/share
    #   .Pa /tmp/fooXXXXX ) .   /tmp/fooXXXXX).
    #
    my ($pa_path);
    if (@words == 0)
    {
        $pa_path = "~";
    }
    else
    {
        $pa_path = shift @words;
    }

    print '@file{',"$pa_path","}";
    while ($_ = shift @words) {
        print;
    }
    print "\n";
}

sub Handle_Q
{
    # Usage: .Ql ...
    #   .Aq ...                 Angle bracket: <...>
    #   .Bq ...                 bracket: [...]
    #   .Brq ...                braces: {...}
    #   .Dq ...                 double quote: <lq><lq>...<rq><rq>
    #   .Eq XX YY ...           Enclose String: XX...YY
    #   .Pq XX ...              parenthesis: (...)
    #   .Ql ...                 Quoted literal: <lq>...<rq> or <tt>...<tt>
    #   .Qq ...                 Straight 2ble quote: "..."
    #   .Sq ...                 Single quote: <lq>...<rq>
    #

    my ($lq, $rq, $wc);
    $wc = 0;

    # print STDERR "Handle_Q: <", join(' ', @words), ">\n";     # XXX

    s/^\.//;

    if    (/^Aq$/)      { $lq = "<"; $rq = ">"; }
    elsif (/^Bq$/)      { $lq = "["; $rq = "]"; }
    elsif (/^Brq$/)     { $lq = "{"; $rq = "}"; }
    elsif (/^Dq$/)      { $lq = '@quotedblleft{}'; $rq = '@quotedblright{}'; }
    elsif (/^Eq$/)      { $lq = shift @words; $rq = shift @words; }
    elsif (/^Pq$/)      { $lq = "("; $rq = ")"; }
    elsif (/^Ql$/)      { $lq = '@quoteleft{}'; $rq = '@quoteright{}'; }
    elsif (/^Qq$/)      { $lq = '"'; $rq = '"'; }
    elsif (/^Sq$/)      { $lq = '@quoteleft{}'; $rq = '@quoteright{}'; }

    print "$lq";
    while (@words > 0 && $words[0] !~ /^[[:punct:]]$/) {
        print " " if ($wc);
        print shift @words;
        ++$wc;
    }
    print "$rq";
    while ($_ = shift @words)
    {
        print;
    }
    print "\n";
}

sub Handle_Sec
{
    # Usage: .Sh
    # Usage: .Ss
    #   .Sh word(s)
    #
    # Might be a quoted string.
    #
    # Drops an anchor.
    my ($a, $sh);

    $sh =~ /Sh/;

    parseQuote(\@words) if ($words[0] =~ /^"/);

    $a = $words[0];

    print '@node ', "$a\n";
    print '@', $sh ? "sub" : "", "section $a\n";
    print "@anchor{$a}\n";
}

sub Handle_Sx
{
    # Usage: .Sx <section reference> ...
    #   .Sh word(s)
    #
    # Might be a quoted string.
    #
    # References an anchor

    my ($a);

    parseQuote(\@words) if ($words[0] =~ /^"/);

    $a = $words[0];

    print '@ref{',"$a","}";
}

sub Handle_Ux
{
    # Usage: .Ux ...
    #   .Ux                     UNIX
    #   .Ux FOO                 FOO
    #
    my ($ux_name);
    if (@words == 0)
    {
        $ux_name = "UNIX";
    }
    else
    {
        $ux_name = shift @words;
    }

    print '@sc{',"$ux_name","}";
    while ($_ = shift @words)
    {
        print;
    }
    print "\n";
}

sub Handle_Xr
{
    # Usage: .Xr <man page name> [<section>] ...
    #   .Xr mdoc        mdoc
    #   .Xr mdoc ,      mdoc,
    #   .Xr mdoc 7      mdoc(7)
    #   .Xr xinit 1x ;  xinit(1x);
    #
    # Emitting things like @uref{/man.cgi/1/ls,,ls} would be OK,
    # but we'd have to allow for changing /man.cgi/ (at least).
    # I'm OK with:
    #   @code{mdoc}
    #   @code{mdoc},
    #   @code{mdoc(7)}
    #   @code{xinit(1x);
    #
    my ($xr_cmd, $xr_sec, $xr_punc);
    if (@words == 1)
    {
        $xr_cmd = $words[0];
    }
    elsif (@words == 2)
    {
        $xr_cmd = shift @words;
        if ($words[0] =~ /[[:punct:]]/)
        {
            $xr_punc = shift @words;
        }
        else
        {
            $xr_sec = shift @words;
        }
    }
    elsif (@words == 3)
    {
        $xr_cmd = shift @words;
        $xr_sec = shift @words;
        $xr_punc = shift @words;
    }
    else
    {
    }

    # HMS: do we really want 'defined' in the following tests?
    print '@code{',"$xr_cmd"    if (defined $xr_cmd);
    print "($xr_sec)"           if (defined $xr_sec);
    print "}"                   if (defined $xr_cmd);
    print "$xr_punc"            if (defined $xr_punc);
    print "\n";
}

sub parseQuote # ref to array of words
{
    my ($waref) = @_;   # word array reference
    my ($string);

    # Passing in "foo" will lose...

    $string = shift @{$waref};

    until ($string =~ /\"$/) {
        $string .= " ".shift @{$waref};
    }

    $string =~ s/^\"(.*)\"$/$1/;

    unshift @{$waref}, $string;
}

sub ParseMacro #line
{
    my ($line) = @_;

    @words = split(/\s+/, $line);
    $retval = '';

    # print('@words = ', scalar(@words), ': ', join(' ', @words), "\n");

    while ($_ = shift @words)
    {
        if    (/^\.An$/)                { Handle_An(); }
        elsif (/^\.Aq/)                 { Handle_Q(); }
        elsif (/^\.Ar$/)                { Handle_ArCmFlIc(); }
        elsif (/^\.Bl$/)                { last if (Handle_Bl()); }
        elsif (/^\.Bq/)                 { Handle_Q(); }
        elsif (/^\.Brq/)                { Handle_Q(); }
        elsif (/^\.Cm$/)                { Handle_ArCmFlIc(); }
        elsif (/^\.Dq/)                 { Handle_Q(); }
        elsif (/^\.El$/)                { Handle_El(); }
        elsif (/^\.Em$/)                { Handle_Em(); }
        elsif (/^\.Eq/)                 { Handle_Q(); }
        elsif (/^\.Fl$/)                { Handle_ArCmFlIc(); }
        elsif (/^\.Fn$/)                { Handle_Fn(); }
        elsif (/^\.Ic$/)                { Handle_ArCmFlIc(); }
        elsif ($optlist && /^\.It$/)    { last if (Handle_It()); }
        elsif (/^\.Nm$/)                { Handle_Nm(); }
        elsif (/^\.Op$/)                { Handle_Op(); }
        elsif (/^\.Pa$/)                { Handle_Pa(); }
        elsif (/^\.Pp$/)                { print "\n";  }
        elsif (/^\.Pq/)                 { Handle_Q(); }
        elsif (/^\.Ql/)                 { Handle_Q(); }
        elsif (/^\.Qq/)                 { Handle_Q(); }
        elsif (/^\.Sh/)                 { Handle_Sec(); } # Section Header
        elsif (/^\.Sq/)                 { Handle_Q(); }
        elsif (/^\.Ss/)                 { Handle_Sec(); } # Sub Section
        elsif (/^\.Sx/)                 { Handle_Sx(); } # Section xref
        elsif (/^\.Ux/)                 { Handle_Ux(); }
        elsif (/^\.Xc/)                 { $extArg = 0; }
        elsif (/^\.Xo/)                 { $extArg = 1; }
        elsif (/^\.Xr/)                 { Handle_Xr(); }
        else                            { print $_,"\n"; }
    }
}
