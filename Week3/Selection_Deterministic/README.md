###Problem Statement:
Selection problem. Given an array (say A), find the ith order statistic of the input array.
e.g: Given array, find the i<sup>th</sup> smallest element.

###Motivation:
Its one of the very fundametal problems that comes all the time in CS. For e.g Slection problem most often act as the subproblem in solving very complex problem like nearest neighbor problem, shortest path problem etc..

### Naive Solution (Sort and return i<sup>th</sup> element): <code>Run time: O(n log n)</code>

One of the straight forward approach to handle this selection problems is to sort the given array and return ith element.
Since any comparison-based sorting algorithm can never be faster than <code>O(n log n)</code>, this selection problem would also end up with the same time complexity <code>O(n log n)</code>.

But you know what?. Slection problem is more fundametal than sorting. So, can we do better?. Yes. see better solution for more details.


### Better Solution (Deterministic selection): <code>Run time: O(n)</code>

Here we going to solve selection problem in <code>O(n)</code> time without randomization. It is not practically more
efficient than the randomized one (because of huge hidden constant) But, it also one of the clever algorithm, we will 
ever learn in CS. Only difference between randomized and determinstic is, here we wont choose the pivot randomly. Instead
we use "median of medians" as pivot(see course video. I bet you will enjoy it.)

###Benchmark:
Here I am going to do benchmark between randomized and deterministic algorithm.
<pre>
bash-4.2$ g++ naive.cc -o naive
bash-4.2$ g++ DSelect.cc -o DSelect
bash-4.2$ g++ RSelect.cc -o RSelect

bash-4.2$ time ./naive

real    0m0.767s
user    0m0.657s
sys     0m0.072s

bash-4.2# time ./DSelect

real    0m0.694s
user    0m0.677s
sys     0m0.016s

bash-4.2$ time ./RSelect

real    0m0.297s
user    0m0.228s
sys     0m0.042s
bash-4.2$ 
</pre>
