#!/usr/bin/perl -w
$n1=<STDIN>;
$n2=<STDIN>;
chomp($n1);
chomp($n2);
$product=karatsuba($n1,$n2);
print $product;
sub karatsuba {
    $num1=shift;
    $num2=shift;
    print "num1: $num1, num2: $num2\n";
    if($num1<10 || $num2<10){
	return $num1*$num2;
    }
    $l=($num1<$num2)?length($num1):length($num2);
    if($l%2) {
	$l--;
    }
    $a=int $num1/(10**($l/2));
    $b=int $num1%(10**($l/2));
    $c=int $num2/(10**($l/2));
    $d=int $num2%(10**($l/2));
    $ac=karatsuba($a,$c);
    $bd=karatsuba($b,$d);
    $a_b__c_d=karatsuba($a+$b,$c+$d);
    print "imp: $a_b__c_d\n";
    $ad_bc=$a_b__c_d-$ac-$bd;

    print"ac: $ac, bd: $bd, ab_bc: $ad_bc\n";
    return ((10**$l)*$ac)+((10**($l/2))*$ad_bc)+$bd;

}
