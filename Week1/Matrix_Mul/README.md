###Problem Statement:
Multiplication of two matrix say A and B of dimension n x n.

###Motivation:
Matrix multiplication is one of the very fundametal problem in computer science. Processors use it for "processing cycles" all the time. Even it is used in predicting the weather conditions([Check out](http://www.ias.ac.in/resonance/Volumes/18/04/0368-0377.pdf))

### Naive Solution (brute force): <code>Run time: O(n<sup>3</sup>)</code>
<pre>
for(int i=0;i &lt; n;++i)
  for(int j=0;j &lt; n;++j)
    for(int k=0;k &lt; n;++k)
      c[i][j]+=a[i][k]*b[k][j];

</pre>
### Better Solution ([StrassenAlgorithm](http://en.wikipedia.org/wiki/Strassen_algorithm)): <code>Run time: O(n^2.8)</code>
We use the divide and conquer approach to multiply two matrix of dimensions n x n. Strassen Algorithm is very clear and
totally non-obvious algorithm in solving this problem with better runtime than the naive one.

###Benchmark:
<pre>

</pre>
