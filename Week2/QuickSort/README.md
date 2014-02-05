###Problem Statement:
Sort the given array(say A) in an increasing order. Such that for all i<j, A[i] < A[j]

###Motivation:
Sorting is one of the most fundamental problem in computer science. 

### Naive Solution (brute force): <code>Run time: O(n<sup>2</sup>)</code>


### Better Solution (Quick Sort): <code>Run time: O(nlogn) "on Average"</code>

Uses divide and conquer approach. Partioning of an array based on the pivot element is the key idea here. 

###Benchmark:
<pre>
bash-4.2$ g++ naive.cc -o naive
bash-4.2$ g++ quicksort.cc -o qsort

bash-4.2$ time ./naive

real    2m4.070s
user    1m35.734s
sys     0m0.318s

bash-4.2$ time ./qsort 

real    0m0.122s
user    0m0.081s
sys     0m0.016s
</pre>
