# Analysis of Algorithms - Lab 06

<div align="center">

# 🚀 Sorting Algorithms Lab in C++

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)
![Course](https://img.shields.io/badge/Course-Analysis%20of%20Algorithms-orange?style=for-the-badge)
![Lab](https://img.shields.io/badge/Lab-06-purple?style=for-the-badge)

**Implementation and experimental analysis of Merge Sort and Quick Sort in C++**

</div>

---

## 📌 Description

This repository contains the solution for **Lab 06** of the **Analysis of Algorithms** course.  
The project focuses on the implementation, execution, and empirical analysis of the following topics:

- **Merge Sort implementation**
- **Stability test of Merge Sort**
- **Quick Sort implementation**
- **Empirical analysis of Quick Sort**
- **Theoretical exercises** documented with screenshots

---

## 🧠 Objectives

- Implement **Merge Sort** in C++.
- Verify experimentally whether **Merge Sort is stable**.
- Implement **Quick Sort** in C++.
- Test Quick Sort with randomly generated lists.
- Compare the empirical behavior of Quick Sort with its theoretical analysis.
- Organize evidence of execution and theory using screenshots.

---

## 🗂️ Project Structure

```bash
Lab06/
│
├── main.cpp        # Source code with parts 2, 3, 4 and 5
├── main.exe        # Compiled executable (Windows)
├── screen1         # Screenshot of parts 2 and 3 execution
├── screen2         # Screenshot of parts 4 and 5 execution
├── Photo1          # Screenshot of theoretical exercises (part 1)
└── Photo2          # Screenshot of the remaining theoretical exercises
```

> **Note:** If your files have extensions such as `.png`, `.jpg`, or `.jpeg`, update the names in this README accordingly.

---

## ⚙️ Implemented Sections

<details>
<summary><strong>📍 Part 2 - Merge Sort</strong></summary>
<br>

Merge Sort was implemented using the divide-and-conquer paradigm:

1. Split the array into two halves.
2. Recursively sort each half.
3. Merge both sorted halves.

### Expected behavior
- Input: unsorted array
- Output: sorted array in ascending order

</details>

<details>
<summary><strong>📍 Part 3 - Stability of Merge Sort</strong></summary>
<br>

A custom structure with:
- `key`
- `label`

was used to verify whether elements with equal keys preserve their original relative order after sorting.

### Conclusion
Merge Sort is **stable**, because equal keys maintain their original order.

</details>

<details>
<summary><strong>📍 Part 4 - Quick Sort</strong></summary>
<br>

Quick Sort was implemented using:
- the **last element as pivot**, and
- recursive partitioning.

### Expected behavior
- Input: random list
- Output: sorted list

</details>

<details>
<summary><strong>📍 Part 5 - Empirical Analysis of Quick Sort</strong></summary>
<br>

The program measures execution time for different input sizes:

- 1,000
- 5,000
- 10,000
- 20,000
- 50,000
- 100,000

Then it compares observed time with the theoretical growth trend of:

\[
O(n \log n)
\]

</details>

---

## ▶️ How to Run the Project

### Option 1 - Compile with g++

```bash
g++ -std=c++17 -O2 -o lab06 main.cpp
./lab06
```

### Option 2 - Run on Windows

```bash
g++ -std=c++17 -O2 -o main.exe main.cpp
main.exe
```

---

## 🖥️ Example Execution Flow

<details>
<summary><strong>Click to see what the program does</strong></summary>
<br>

- Displays the Merge Sort example
- Shows the stability test
- Generates a random list for Quick Sort
- Sorts the list
- Prints whether the list is correctly sorted
- Measures execution time for different sizes
- Prints an empirical analysis table

</details>

---

## 📸 Evidence / Screenshots

## 1. Theoretical Exercises

### Photo 1
> Replace the path with the correct extension if needed.

```md
![Photo1](./Photo1.png)
```

![Photo1](./Photo1.png)

### Photo 2

```md
![Photo2](./Photo2.png)
```

![Photo2](./Photo2.png)

---

## 2. Program Execution

### Screen 1 - Parts 2 and 3

```md
![Screen1](./screen1.png)
```

![Screen1](./screen1.png)

### Screen 2 - Parts 4 and 5

```md
![Screen2](./screen2.png)
```

![Screen2](./screen2.png)

---

## 🧪 Technical Summary

| Section | Description |
|--------|-------------|
| Part 2 | Merge Sort implementation |
| Part 3 | Stability verification of Merge Sort |
| Part 4 | Quick Sort implementation |
| Part 5 | Empirical time analysis of Quick Sort |
| Photo1 | Theoretical exercises evidence |
| Photo2 | Additional theory evidence |
| screen1 | Execution capture for parts 2 and 3 |
| screen2 | Execution capture for parts 4 and 5 |

---

## 📈 Theoretical Notes

### Merge Sort
- Time complexity: **O(n log n)**
- Stable: **Yes**
- Paradigm: **Divide and Conquer**

### Quick Sort
- Average case: **O(n log n)**
- Worst case: **O(n²)**
- Stable: **No** (in the classic implementation)
- Paradigm: **Divide and Conquer**

---

## 🛠️ Technologies Used

- **C++17**
- **g++ compiler**
- **Standard Template Library (STL)**
- **chrono** for time measurement
- **random** for test data generation

---

## 📚 Learning Outcomes

Through this lab, the following concepts were reinforced:

- recursive algorithm design
- divide and conquer strategy
- sorting stability
- experimental algorithm analysis
- comparison between theory and practice

---

## ✅ Final Conclusion

This lab demonstrates the practical implementation of two classical sorting algorithms in C++.  
Merge Sort proved to be a **stable** sorting algorithm, while Quick Sort showed strong empirical performance on random inputs, matching its expected **average-case complexity of** `O(n log n)`.

In addition, the repository includes both:
- **source code**, and
- **visual evidence** of execution and theoretical development.

---

## 👨‍💻 Author

**Andrés**  
Analysis of Algorithms - Lab 06

---

<div align="center">

### ⭐ If this repository helped you, consider giving it a star.

</div>
