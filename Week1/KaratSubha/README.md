###Problem Statement:
Multiplication of two n-digit integer.(So simple right??).

###Motivation:
Why study karatsubha algorithm after all?. The secret is it is faster than the one we learned in grade school.

### Naive Solution (grade school): <code>Run time: O(n<sup>2</sup>) </code>

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

### Better Solution ([Karatsubha](http://en.wikipedia.org/wiki/Karatsuba_algorithm)): <code>Run time: O(n<sup>1.585</sup>)</code>

<pre>
Let X and Y be two n-digit integers
According to karatsubha,
X = 10<sup>n/2</sup> * A + B
Y = 10<sup>n/2</sup> * C + D
X * Y = 10<sup>n</sup> (AC) + 10<sup>n/2</sup> (bc+ad) + bd
E.g:
X = 5678
Y = 1234
then A=56, B=78, C=12, D=34 (Divide)
</pre>

###Benchmark:
<pre>
bash$ g++ naive.cc -o naive
bash$ time ./naive

real    0m0.471s
user    0m0.341s
sys     0m0.129s

bash$ g++ KaratSubha.cc -o karat
bash$ time ./karat

real    0m0.210s
user    0m0.108s
sys     0m0.101s
</pre>
