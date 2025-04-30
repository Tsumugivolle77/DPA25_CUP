# Optional Homework 1.5

One method to estimate the value of $\Pi$ (3.141592...) is by using a Monte Carlo method. A simple Monte Carlo simulation to approximate the value of $\Pi$ involves randomly selecting points in the unit square and determining the ratio $4m/n$ where $m$ is the number of points that satisfy $x_i^2 + y^2 \leq 1$, and $n$ is the number of randomly selected points. Implement the function
```c
double monte_carlo_pi(long long n);
```
in the file **your_code.c**. To test your implementation, compile the project by using
```
make
```
This will create an executable file called **prog** that automatically performs strong scalability experiments on your code. You can specify for which number of threads you want to run by listing the numbers as command line arguments to the program. For instance, running
```
./prog 2 4 8 16
```
Could generate the following output
```
Using n=67108864 random points
  P,      T,  S_rel,      pi,   error
  1,  1.213,  1.000, 3.14152, 0.00007
  2,  0.606,  2.001, 3.14144, 0.00015
  4,  0.303,  4.000, 3.14153, 0.00006
  8,  0.152,  8.001, 3.14172, 0.00013
 16,  0.076, 15.992, 3.14165, 0.00006
```
Where **P** is the number of threads used, **T** is the time spent in seconds, **S_rel** is the relative speedup, **pi** is the output from your function, and **error** is the absolute difference between the estimated value of $\Pi$ and the constant **M_PI**. The value of **n** is set as a constant in the main.c file.

You should only hand in the file **your_code.c**. Feel free to make other changes to the main.c file, but these changes will not be included when we evaluate your code.

## The Distributed and Parallel Algorithms Cup

This is the first problem included in the **completely optional** implementation challenge for the lecture. If you choose to submit your implementation, we will run your code on one of the large machines (likely an AMD 128-core CPU), and you will be able to see how your code performs. It is strongly recommended to take part, even if you do not intend to compete for first place. Spending time to optimize small parts of code like this is an important learning experience for writing more efficient parallel code. The students in the two best teams (max two people per team) will also walk away with the prestigious Algorithm Engineering coffee cup. The rest of the results will be anonymous, so you do not have to worry about getting a bad placement.

### Scoring

Even though it is fun to see big speedup numbers, we will not be scoring your submission based on relative speedup. Instead, the most important metric is the absolute performance (meaning the **T** column from above). Naturally, there are many ways to cheat here, especially on this first problem. For instance, if you handed in
```c
return M_PI;
```
you would be disqualified. We expect you to actually run the Monte Carlo simulation as described in the beginning. However, writing your own random number generator is fair game. Since this first task is simple and does not involve much parallel programming, it will be weighted lower than the later problems. The exact formula to determine the winner will be disclosed later in the lecture.

## Tips and Other Details

For best performance, consider using the following commands once in the terminal you will use to run your code.
```
export OMP_NUM_THREADS=[number of cores on your machine]
export OMP_PLACES=cores
export OMP_PROC_BIND=spread
```
For this task, only the middle command is really necessary. This ensures that each thread runs on its own core instead of sharing it via simultaneous multithreading (or hyperthreading). Note that this is completely outside the code, and you do not need to think about this for your submission. We will ensure the machine we use is configured for best performance.

When optimizing your code for this task, trying different random number generators is a good place to start. Since you have access to the GNU C library, you can try any of the pseudo-random number generators offered by the [library](https://www.gnu.org/software/libc/manual/html_node/Pseudo_002dRandom-Numbers.html). Alternatively, you can also have a look at writing your own generator [here](https://en.wikipedia.org/wiki/List_of_random_number_generators#Pseudorandom_number_generators_(PRNGs)). The Lehmer random number generator is simple and easy to implement.