# RunningMedian.cpp

Efficient running median in C++

Have a look at the sibling project [RunningMedian.py](https://github.com/thomedes/RunningMedian.py)

It's run time for M sized window over a N long sequence is O(N * log(M)).

To put it in numbers, see this table obtained with a Core i7:

|     N     |    M    |   time   |
|-----------|---------|----------|
|    10,000 |   1,000 |  0.012 s |
|   100,000 |  10,000 |  0.196 s |
| 1,000,000 | 100,000 | 16.0   s |

If you need to do your own speed tests just adjust
SAMPLES and WINDOW_SIZE and run it.

# Usage

For a simple example have a look at the `main()` function:

```C++
    RunningMedian<int> rm(WINDOW_SIZE);

    for (size_t i = 0; i < SAMPLES; ++i) {
        int sample = rand();

        rm.insert(sample);
        median = rm.median();
        // Do something with median
    }
```
