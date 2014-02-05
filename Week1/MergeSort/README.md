###Problem Statement:
Sort the given array in ascending order. Such that for all i<j, A[i] < A[j]

###Motivation:
Sorting is one of the most fundamental problem in computer science. Merge sort is 
better than naive sorting technique like insertion, selection or bubble sort.

### Naive Solution (brute force): <code>Run time: O(n<sup>2</sup>)</code>


### Better Solution (Merge Sort): <code>Run time: O(nlogn)</code>

Uses divide and conquer 

###Benchmark:
<pre>
bash-4.2$ g++ naive.cc -o naive
bash-4.2$ time ./naive

real    0m1.104s
user    0m0.961s
sys     0m0.018s

bash-4.2$ g++ mSort.cc -o merge
bash-4.2$ time ./merge 

real    0m0.047s
user    0m0.034s
sys     0m0.005s
</pre>
