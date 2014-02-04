###Problem Statement:
Selection problem. Given an array (say A), find the ith order statistic of the input array.
e.g: Given array, find the ith smallest element.

###Motivation:
Its one of the very fundametal problems that comes all the time in CS. For e.g Slection problem most often act as the subproblem in solving very complex problem like nearest neighbor problem, shortest path problem etc..

### Naive Solution (Sorting the input, return ith element): `Run time: O(n log n)`

One of the straight forward approach to handle this selection problems is to sort the given array and return ith element.
Since any comparison-based sorting algorithm can never be faster than <code>O(n log n)</code>, this selection problem would also end up with the same time complexity <code>O(n log n)</code>.

But you know what?. Slection problem is more fundametal than sorting. So, can we do better?. Yes. see better solution for more details.


### Better Solution (Randamized selection): `Run time: O(n) "on Average"`

Here we going to solve selection problem in <code>O(n)</code> time. The first time when I hear this it was un-belivable. How could this be posibly solved with time <code>O(n)</code>, the same time needed just to scan or read the complete input. Another cool thing is, this algorithm is "in-place" i.e it doesn't require any extra memory space. Its is one of the coolest algorithm I ever learnt.

Here we are going to use "Partition sub-routine" that we used in quick sort and piggyback on it. See course lecture for explanation.

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
