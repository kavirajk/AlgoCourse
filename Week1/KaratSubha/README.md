###Problem Statement:
Multiplication of two n-digit integer.(So simple right??).

###Motivation:
Why study karatsubha algorithm after all?. The secret is it is faster than the one we learned in grade school.

### Naive Solution (grade school): `Run time: O(n^2)`

<pre>
   5678
 x 1234
----------
  22712
 17034
11356
5678
----------
7006652

</pre>

### Better Solution ([Karatsubha](http://en.wikipedia.org/wiki/Karatsuba_algorithm)): `Run time: O(nlogn)`

<pre>
Let X and Y be two n-digit integers
According to karatsubha,
X = 10^n/2*A + B
Y = 10^n/2*C + D
X * Y = 10^n(AC) + 10^n/2(bc+ad) + bd
E.g:
X = 5678
Y = 1234
then A=56, B=78, C=12, D=34 (Divide)
</pre>

###Benchmark:
