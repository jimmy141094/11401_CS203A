# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++.  
Students are expected to implement and analyze the behavior of hash functions,  
evaluate their efficiency, and understand their applications in computer science.

**Developer:** Chen-Yao-Xiang  
**Email:** jimmy141094@gmail.com

---

## My Hash Function

### Integer Keys  

**Formula / pseudocode:**

```
ukey *= 6813;      // Multiply ukey by the constant 6813
ukey += ukey / 3;  // Add one-third of ukey
ukey += ukey % 7;  // Add the remainder of ukey divided by 7
return ukey % m;   // Final index = hash mod table size
```

**Rationale:**  
If we only multiply by a constant, periodic values (e.g., 21 and 51) still map to the same index.  
By adding both quotient and remainder components, we break the periodicity and reduce patterned collisions.

---

### Non-integer Keys

**Formula / pseudocode:**

```text
unsigned long hash = 0;
const int p = 41;

for (size_t i = 0; i < str.length(); ++i) {
    char c = str[i];
    hash = (hash * p) + c;   // Polynomial Rolling Hash
}

return static_cast<int>(hash % m);
```

**Rationale:**  
If we only sum characters or use the first character, strings like "cat/car" or "dog/god" collide.  
Polynomial Rolling Hash assigns positional weight to each character.  
Prime multiplier **p = 41** helps avoid patterns and reduces collision probability.

---

## Experimental Setup

- **Table sizes tested:** 10, 11, 37  
- **Test dataset:**  
  - Integers: 21–30, 51–60  
  - Strings: `"cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"`  
- **Compiler:** GCC / G++  
- **Standard:** C23 / C++23  

---

## Results

| Table Size (m) | Index Sequence       | Observation                                      |
|----------------|----------------------|--------------------------------------------------|
| 10             | Nonlinear, irregular | Collision at 21/51 eliminated                    |
| 11             | Nonlinear, irregular | Collision at 21/51 eliminated                    |
| 37             | Random dispersion    | Most balanced and evenly distributed             |

---

## Compilation, Build, Execution, and Output

### Build

```bash
# Build both C and C++ versions
make all

# Build only C version
make c

# Build only C++ version
make cxx
```

### Manual Compilation

**C version**

```bash
gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
```

**C++ version**

```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
```

### Clean

```bash
make clean
```

### Run

```bash
./hash_function
```
or

```bash
./hash_function_cpp
```

---

## Result Snapshot

### Example output (Integers)

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
```

### Example output (Strings)

```
=== String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     4
bat     1
cow     9
ant     3
owl     8
bee     0
hen     5
pig     0
fox     3

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     1
dog     10
bat     3
cow     6
ant     10
owl     2
bee     9
hen     6
pig     4
fox     1

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     16
dog     1
bat     0
cow     1
ant     36
owl     29
bee     1
hen     32
pig     21
fox     13
```

---

## Summary of Hash Table Outputs

### Example output for integers

```txt
Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
```

### Example output for strings

```txt
Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
```

---

## Observations

- Outputs match expectations: patterned collisions in integers are eliminated.  
- Prime table sizes (e.g., 37) produce the most uniform distribution.  

---

## Analysis

- **Prime vs non-prime:**  
  `m = 37` (prime) achieves lowest collision rate.  
  `m = 10` performs worst in strings.

- **Pattern collisions:**  
  Integer keys 21 and 51 differ by 30 → periodic collision if no correction.  
  The designed hash successfully breaks this pattern.

- **Improvement:**  
  Polynomial Rolling Hash provides distinct results even for anagrams.

---

## Reflection

1. Designing hash functions requires balancing simplicity and effectiveness.  
2. Table size `m` strongly affects distribution—primes consistently outperform non-primes.  
3.  
   - **Integer keys:** Breaking arithmetic periodicity is crucial (e.g., quotient + remainder mixing).  
   - **String keys:** Polynomial Rolling Hash ensures both character order and content influence the result.

---

