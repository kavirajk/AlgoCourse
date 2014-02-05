> <strong>Come to this problem after fully understanding the Merge Sort.</strong>

###Problem Statement:
Find the inversions of a given array.

Inversions of a Array A is defined as the no of elements contained in the array A satisfying the below condition

for all pair <pre> i < j, A[i] > A[j] </pre> 

###Motivation:
Have you ever wondered how while purchasing online, it suggests you the product that you are really interested in?. How does an website knows your taste?. Inversions is lying underhood in this problem.

####For example:
You have ranked 6 movies based on your taste. That movies be ordered based on your rank Let it be A{1,2,3,4,5,6}. The same movies were ranked by your friend as (say B) B {1,3,5,2,4,6}. Then the inversion of the list of movies is 3. i.e the similarity between you and your friend is 3 (larger the number, lesser the similarity). If both were ranked the movies in same order then inversions is 0. Which means both have exact taste over those movies. So the system can suggest the product your friend have bought. So cool right?.

### Naive Solution (brute force): <code>Run time: O(n<sup>2</sup>)</code>
All we need to do is just count the no of pairs satisfing the condition in the problem statement. In other words, count the no of pairs that are not in sorted order.


### Better Solution (Piggyback on Merge Sort): <code>Run time: O(nlogn)</code>
We use the subroutine "merge" from the merge sort to obtain the inversion of an array. For detail explanation go through couse video.

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
