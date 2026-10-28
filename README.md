# DSA Lab 8 — Algorithm Design and Analysis

**Course:** Data Structures and Algorithms
**Language:** C++
**Repository:** DSA-Lab8

## Overview

This repository contains solutions to three algorithmic problems involving binary search, backtracking, and iterative problem-solving techniques. Each program demonstrates an approach to solving the problem and analyzing its time and space complexity.

## Tasks

### Task 1: Peak Element in a 2D Array

**File:** `task1_peak_element.cpp`

A peak element in a 2D array is an element that is greater than or equal to its neighboring elements.

**Approach:**

* Use binary search over the columns.
* Find the maximum element in the middle column.
* Compare it with its horizontal neighbors to determine whether a peak has been found.
* Adjust the search range based on the comparison.

**Complexity:**

* Time: O(n log n) for an n × n matrix.
* Auxiliary space: O(1), excluding the input matrix.

**Input:** Matrix size followed by the matrix elements.

### Task 2: Knight's Tour Using Backtracking

**File:** `task2_knights_tour.cpp`

The Knight's Tour problem requires a knight to visit every square of an N × N chessboard exactly once, starting from a specified position.

**Approach:**

* Represent the chessboard using a 2D array.
* Generate the knight's eight possible moves.
* Check whether each move is within the board and leads to an unvisited square.
* Use recursion to explore possible paths.
* Backtrack when a path cannot produce a complete tour.

**Complexity:**

* Best case: Θ(N²) when a complete tour is found with minimal backtracking.
* Worst case: Exponential search in the number of candidate paths.
* Board space: O(N²).
* Recursive stack: O(N²) in the worst case.

The running time depends on the amount of backtracking required.

### Optimized Knight's Tour

**File:** `task2_optimized_algorithm.cpp`

This implementation improves the practical performance of the Knight's Tour backtracking algorithm using **Warnsdorff's heuristic**.

- Calculates the number of valid, unvisited moves available from each candidate square
- Prioritizes moves with the fewest onward moves
- Uses backtracking when a selected path cannot complete the tour
- Accepts board sizes from 1 to 10 and user-specified starting coordinates

**Complexity:**
- **Time:** Exponential in the worst case due to backtracking; the heuristic improves practical performance but does not guarantee polynomial time
- **Space:** O(N²) for the board and O(N²) maximum recursion depth

### Task 3: Iterative Tower of Hanoi

**File:** `task3_iterative_hanoi.cpp`

The Tower of Hanoi problem involves transferring a stack of disks from a source rod to a destination rod using an auxiliary rod.

**Rules:**

1. Move only one disk at a time.
2. Move only the top disk of a rod.
3. Never place a larger disk on a smaller disk.

**Approach:**

* Represent the rods using stack-like structures.
* Determine the legal move between two rods.
* Use iteration to perform the moves without recursive calls.
* Print each disk movement.

The minimum number of moves for N disks is:

**T(N) = 2^N − 1**

**Complexity:**

* Time: O(2^N).
* Auxiliary space: O(N) for storing the disks.

## Compilation and Execution

Compile each program separately using a C++ compiler that supports C++17.

### Task 1

```bash
g++ -std=c++17 -Wall -Wextra -pedantic task1_peak_element.cpp -o task1_peak_element
./task1_peak_element
```

Enter the matrix size and then the matrix elements when prompted.

### Task 2

```bash
g++ -std=c++17 -Wall -Wextra -pedantic task2_knights_tour.cpp -o task2_knights_tour
./task2_knights_tour
```

Enter the board size and starting row and column when prompted. Starting coordinates use zero-based indexing.

### Task 2 (Optimized Code)

```bash
g++ -std=c++17 -Wall -Wextra -pedantic task2_optimized_algorithm.cpp -o task2_optimized_algorithm
./task2_optimized_algorithm
```

Enter the board size and starting row and column when prompted. Starting coordinates use zero-based indexing.

### Task 3

```bash
g++ -std=c++17 -Wall -Wextra -pedantic task3_iterative_hanoi.cpp -o task3_iterative_hanoi
./task3_iterative_hanoi
```

Enter the number of disks when prompted.

## Repository Structure

```text
DSA-Lab8/
├── README.md
├── .gitignore
├── task1_peak_element.cpp
├── task2_knights_tour.cpp
└── task3_iterative_hanoi.cpp
```

## Notes

* All programs should be tested with valid inputs.
* Complexity analyses describe the algorithms and their assumptions.
* The Knight's Tour backtracking implementation does not guarantee polynomial worst-case running time.
* The iterative Tower of Hanoi implementation should be tested with both odd and even numbers of disks.

---

**End of Lab 8**
