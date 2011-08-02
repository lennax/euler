#!/usr/bin/env perl -w
# answer given: 173
# answer is rejected
# 1 aug 2011: answer 171
# 1 Jan 1900 was a Monday
# but 20th century started the year after

use strict;

my %months = qw(
                 January 31 February 28 March 31
                 April 30 May 31 June 30
                 July 31 August 31 September 30
                 October 31 November 30 December 31
             );

my @months = qw(
                 31 28 31 30 31 30
                 31 31 30 31 30 31
             );

#print $months[0], "\n";
#print $months {January}, "\n";

my $start_date = 19000101;
my ($offset, $sunday_count );

# determine number of days since 1 January 1900

#for my $year ( 1900 .. 2000 ) {
for my $year (1900 .. 2000) {
	for my $mo ( 0 .. 11 ) {
		if ( $mo == 1 && isLeap($year) ) {
			$offset += 29;				
		} else {
			$offset += $months[$mo]; 
		}
#		print "offset: $offset \n";
#		print "mod: ", $offset%7, "\n";
		my $weekday = $offset%7; 
		if ($year > 1900 && $weekday == 6) {
			$sunday_count++;
		}
	}
}
print "Sundays on the first of the month: $sunday_count\n";
# for february, is it a leap year?

# use mod 7 to determine day of week (6 should be Sunday)
foreach my $i ( 0 .. 7) {
#	print $i%7;
#	print "\n";
}



my @test_years = ( 1000, 1995, 1996, 2000);
foreach my $year ( @test_years) {
#	print "$year\t";
#	print isLeap($year), "\n";
}

sub isLeap2 {
    my ($date) = @_;
    my $year = substr $date, 0, 4;
    if ($year%4) {
        return 0;
    }
    else {
        if ($year%100) {
# non-multiples of 100 true
            return 1;
        } else {
            if ($year%400) {
                return 0;
            } else { return 1; } # multiples of 400 true
        }
    }
}

sub isLeap {
    my ($date) = @_;
    my $year = substr $date, 0, 4;
    unless ($year%4) { # multiples of 4 true
        unless ($year%100) { # most multiples of 100 false
            unless ($year%400) { # multiples of 400 true
                return 1;
            } else { return 0; }
        } else { return 1; } # non-multiples of 100 true
    } else { return 0; } # non-multiples of 4 false
}

sub monthEnd {
#	my ($date) = @_;

}
