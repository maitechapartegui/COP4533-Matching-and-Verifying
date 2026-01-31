# COP4533-Matching-and-Verifying

**Students:**
Heiryn Hernandez Rojas - 90988659

Maite Chapartegui - 54536135

## Files
Within src folder:
* `matcher.cpp`: Holds the G-S algorithm, timer and stability checker
* `hospitalStudents.cpp`: Has the Hospital and Student struct
Within data folder:
* `examplen.txt`: The input values ranging from 1-128
* `examplen.out`: the output with the stable matches

## Compilation
Our program is written in C++
To compile the code, .......

### Our assumptions:



## TASK C
Using <chrono>: 
    We started a timer that started right before the while loop and ended right after, ignoring taking in the input and out.
    This was done with code like:
    `    auto start = chrono::high_resolution_clock::now();`
    `auto end = chrono::high_resolution_clock::now();`
    `auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);`

We ran a variety of different tests getting their duration in nanoseconds.

- inputs:1, time: in ns 583
- inputs:2, time: in ns 167
- inputs:3, time: in ns 542
- inputs:5, time: in ns 666
- inputs:8, time: in ns 791
- inputs:16, time: in ns 2333
- inputs:32, time: in ns 6209
- inputs:64, time: in ns 14250
- inputs:128, time: in ns 40834

![graphRuntimeImage.png](graphRuntimeImage.png)
