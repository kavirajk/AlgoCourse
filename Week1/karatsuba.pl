#!/usr/bin/perl -w
use strict;
my $n1=<STDIN>;
my $n2=<STDIN>;
chomp($n1);
chomp($n2);
my $product=karatsuba($n1,$n2);
print $product,"\n";
sub karatsuba {
    (my $num1,my $num2)=@_;
    if($num1<10 || $num2<10){
	return $num1*$num2;
    }
    my $l=($num1<$num2)?length($num1):length($num2);
    if($l%2) {
	$l--;
    }

    my $b=int $num1%(10**($l/2));
    my $a=int ($num1-$b)/(10**($l/2));

    my $d=int $num2%(10**($l/2));
    my $c=int ($num2-$d)/(10**($l/2));

    my $ac=karatsuba($a,$c);
    my $bd=karatsuba($b,$d);
    my $a_b__c_d=karatsuba($a+$b,$c+$d);
    my $ad_bc=$a_b__c_d-$ac-$bd;

    my $result=((10**$l)*$ac)+((10**($l/2))*$ad_bc)+$bd;
    return $result;
}
