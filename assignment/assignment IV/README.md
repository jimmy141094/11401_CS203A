# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: Chen-Yao-Xiang
Email: jimmy141094@gmail.com
ㄔ
## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```
    ukey*=6813; Multiply ukey by a self-selected constant 6813
    ukey+=ukey/3; Add ukey to itself divided by 3
    ukey+=ukey%7; Add ukey to the remainder of itself divided by 7.
    return ukey % m; Return the value after the change and then divide by m
  ```
- Rationale: If you simply multiply by any prime number, the periodic values ​​21, 51, etc., will still have the same index. Therefore, we use the quotient and remainder to make it unique, ensuring that we don't encounter the same index value within the same period.

### Non-integer Keys
- Formula / pseudocode:
  ```text
  unsigned long hash = 0; Initialize the hash value to 0.
    const int p = 41; Define the cardinality p=41
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];           Multiply the current hash value by the base p, and then add the ASCII value of the current character c.
        hash = (hash * p) + c; 
    }
    return static_cast<int>(hash % m);  Return the calculated large hash value modulo m, limiting the result to the size of the hash table (0 to m-1)
  ```
- Rationale: If we only take the value of the first character or the sum of all characters, the results for "cat,car" and "dog,god" will be the same. We choose Polynomial Rolling Hash to assign a weight to each character. We use the prime number p=41 as the multiplier, instead of numbers like 10 or 20 which are prone to generating patterns. Prime numbers minimize the chance that two slightly different strings will coincidentally produce the same hash value.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation                                    |
|----------------|------------------------|------------------------------------------------|
| 10             | Nonlinear, irregular   | The collision at the21 51 has been eliminated  |
| 11             | Nonlinear, irregular   | The collision at the21 51 has been eliminated  |
| 37             | Random Dispersion      | Evenly distributed                             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
    Key     Index
    -----------------
    21      4
    22      3
    23      5
    24      7
    25      6
    26      8
    27      0
    28      2
    29      1
    30      3
    51      7
    52      9
    53      8
    54      0
    55      2
    56      4
    57      3
    58      5
    59      7
    60      6

 === Table Size m = 11 ===
    Key     Index
    -----------------
    21      2
    22      5
    23      1
    24      8
    25      0
    26      7
    27      3
    28      10
    29      2
    30      9
    51      0
    52      7
    53      10
    54      6
    55      2
    56      9
    57      1
    58      8
    59      4
    60      7

 === Table Size m = 37 ===
    Key     Index
    -----------------
    21      29
    22      16
    23      33
    24      13
    25      0
    26      17
    27      34
    28      14
    29      1
    30      18
    51      10
    52      27
    53      14
    54      31
    55      11
    56      28
    57      15
    58      32
    59      12
    60      36

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
    Key     Index
    -----------------
    21      4
    22      3
    23      5
    24      7
    25      6
    26      8
    27      0
    28      2
    29      1
    30      3
    51      7
    52      9
    53      8
    54      0
    55      2
    56      4
    57      3
    58      5
    59      7
    60      6

 === Table Size m = 11 ===
    Key     Index
    -----------------
    21      2
    22      5
    23      1
    24      8
    25      0
    26      7
    27      3
    28      10
    29      2
    30      9
    51      0
    52      7
    53      10
    54      6
    55      2
    56      9
    57      1
    58      8
    59      4
    60      7

 === Table Size m = 37 ===
    Key     Index
    -----------------
    21      29
    22      16
    23      33
    24      13
    25      0
    26      17
    27      34
    28      14
    29      1
    30      18
    51      10
    52      27
    53      14
    54      31
    55      11
    56      28
    57      15
    58      32
    59      12
    60      36
  
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat	   2
  dog	   4
  bat	   1
  cow      9
  ant	   3
  owl	   8
  bee	   0
  hen	   5
  pig	   0
  fox	   3

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat	  1
  dog	  10
  bat	  3
  cow	  6
  ant	  10
  owl	  2
  bee	  9
  hen	  6
  pig	  4
  fox	  1


  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat	   16
  dog	   1
  bat	   0
  cow	   1
  ant	   36
  owl	   29
  bee	   1
  hen	   32
  pig	   21
  fox	   13

  ```

- Observations: Outputs align with the analysis, showing the successful elimination of patterned collisions for integers Distribution is best when the table size m is a larger prime number.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime : The prime number m=37 provides the largest dispersion space and achieves the lowest collision rate. The non-prime     
  number m=10 performs the worst in string hashing, demonstrating the importance of choosing prime numbers for table size.
- Patterns or collisions: The difference between 21 and 51 is 30, and they will keep hitting the same index. This is like a cyclical error pattern.
- Improvements: Using Polynomial Rolling Hash, it calculates a unique number for each string.

## Reflection
1. Designing hash functions requires striking a balance between simplicity and efficiency to minimize collisions. In integer hash design, simple
   arithmetic operations alone are insufficient to eliminate recurring errors.
2. The table size m significantly affects the uniformity of the hash distribution. Compared to a non-prime number m=10, using a prime number m=37
   always produces the lowest collision rate and the best dispersion effect.
3. For integer keys: The key to success lies in using XOR folding to break the arithmetic periodicity within the key.

   For string keys: The key to success lies in employing Polynomial Rolling Hash, assigning positional weights to characters to ensure that both 
   the position and content of a character determine the final hash value, thus avoiding collisions between letters in different orders.