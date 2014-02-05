###Problem Statement:
To find the closest pair of points in the collection of given points (say P). The distance between two points is a simple
[euclidiean distance](http://en.wikipedia.org/wiki/Euclidean_distance).

###Motivation:
This problem has application in traffic-control systems. A system for controlling sea or air traffic might need to identify the two closest vehicles in order to detect potential collisions.

### Naive Solution (brute force): <code>Run time: O(n<sup>2</sup>)</code>

Compute distance between all possible pair of points and return min of those.

### Better Solution (closest_pair algorithm): <code>Run time: O(nlogn)</code>

Uses divide and conquer approach. One of the coolest divide and conquer algorithm. Check out the course video for detail study. 

###Benchmark:
<pre>

</pre>
