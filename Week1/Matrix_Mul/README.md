###Problem Statement:
Multiplication of two matrix say A and B of dimension n x n.

###Motivation:
Matrix multiplication is one of the very fundametal problem in computer science. Processors use it for "processing cycles" all the time. Even it is used in predicting the weather conditions([Check out](http://www.ias.ac.in/resonance/Volumes/18/04/0368-0377.pdf))

### Naive Solution (brute force): `Run time: O(n^3)`
<pre>
for(int i=0;i &lt n;++i)
  for(int j=0;j &lt n;++j)
    for(int k=0;k &lt n;++k)
      c[i][j]+=a[i][k]*b[k][j];

</pre>
### Better Solution ([StrassenAlgorithm](http://en.wikipedia.org/wiki/Strassen_algorithm)): `Run time: O(n^2.8)`
We use the divide and conquer approach to 

###Benchmark:
<pre>
bash-4.2$ g++ naive.cc -o naive
bash-4.2$ time ./naive

real    0m0.721s
user    0m0.621s
sys     0m0.006s

bash-4.2$ g++ inversions_dc.cc -o dc
bash-4.2$ time ./dc

real    0m0.038s
user    0m0.026s
sys     0m0.006s
</pre>
