# DAA Lab Manual - Design and Analysis of Algorithms (5th Sem)

**Faculty of Technology - Department of AI, ML & DS**  
**Course Code:** 01AI0506 / 01AI0304 - DAA Lab Manual  
**Student:** Ravi Gohel | **Enrollment No:** 92510118030  
**Academic Year:** 2026

---

## 📚 Practical Sequence (Line-wise Formatting)

All 12 practicals are organized in sequential order. Each folder contains **source code + PDF + output** in uniform format.

| Sr. No. | Practical Title | Folder | Source Code | PDF Report | Language | Time Complexity |
|:-------:|-----------------|--------|-------------|------------|----------|:---------------:|
| 01 | **Sorting Algorithms** - Bubble, Selection, Insertion, Merge & Quick Sort | [`Practical-01/`](./Practical-01/) | [`practical_01.cpp`](./Practical-01/practical_01.cpp) | [`Practical_01_Sorting_Ravi.pdf`](./Practical-01/Practical_01_Sorting_Ravi.pdf) | C++ | O(n²) / O(n log n) |
| 02 | **Searching Algorithms** - Linear Search & Binary Search | [`Practical-02/`](./Practical-02/) | [`practical_02.cpp`](./Practical-02/practical_02.cpp) | [`Practical_02_Searching_Ravi.pdf`](./Practical-02/Practical_02_Searching_Ravi.pdf) | C++ | O(n) / O(log n) |
| 03 | **Max-Heap Sort** | [`Practical-03/`](./Practical-03/) | [`practical_03.cpp`](./Practical-03/practical_03.cpp) | [`Practical_03_HeapSort_Ravi.pdf`](./Practical-03/Practical_03_HeapSort_Ravi.pdf) | C++ | O(n log n) |
| 04 | **Factorial** - Iterative vs Recursive | [`Practical-04/`](./Practical-04/) | [`practical_04.cpp`](./Practical-04/practical_04.cpp) | [`Practical_04_Factorial_Ravi.pdf`](./Practical-04/Practical_04_Factorial_Ravi.pdf) | C++ | O(n) |
| 05 | **0/1 Knapsack Problem** (DP) | [`Practical-05/`](./Practical-05/) | [`practical_05.cpp`](./Practical-05/practical_05.cpp) | [`Practical_05_Knapsack_Ravi.pdf`](./Practical-05/Practical_05_Knapsack_Ravi.pdf) | C++ | O(n·W) |
| 06 | **Matrix Chain Multiplication** (DP) | [`Practical-06/`](./Practical-06/) | [`practical_06.cpp`](./Practical-06/practical_06.cpp) | [`Practical_06_MatrixChain_Ravi.pdf`](./Practical-06/Practical_06_MatrixChain_Ravi.pdf) | C++ | O(n³) |
| 07 | **Making Change / Coin Change** (DP) | [`Practical-07/`](./Practical-07/) | [`practical_07.cpp`](./Practical-07/practical_07.cpp) | [`Practical_07_MakingChange_Ravi.pdf`](./Practical-07/Practical_07_MakingChange_Ravi.pdf) | C++ | O(n·V) |
| 08 | **BFS & DFS Traversal** | [`Practical-08/`](./Practical-08/) | [`practical_08.py`](./Practical-08/practical_08.py) | [`Practical_08_BFS_DFS.pdf`](./Practical-08/Practical_08_BFS_DFS.pdf) | Python | O(V+E) |
| 09 | **Prim's Algorithm** - MST (Greedy) | [`Practical-09/`](./Practical-09/) | [`practical_09.py`](./Practical-09/practical_09.py) | [`Practical_09_Prims_Ravi.pdf`](./Practical-09/Practical_09_Prims_Ravi.pdf) | Python | O(V²) / O(E log V) |
| 10 | **Kruskal's Algorithm** - MST (Greedy + DSU) | [`Practical-10/`](./Practical-10/) | [`practical_10.py`](./Practical-10/practical_10.py) | [`Practical_10_Kruskal_Ravi.pdf`](./Practical-10/Practical_10_Kruskal_Ravi.pdf) | Python | O(E log E) |
| 11 | **Floyd-Warshall** - All-Pairs Shortest Path (DP) | [`Practical-11/`](./Practical-11/) | [`practical_11.py`](./Practical-11/practical_11.py) | [`Practical_11_Floyd_Warshall.pdf`](./Practical-11/Practical_11_Floyd_Warshall.pdf) | Python | O(V³) |
| 12 | **Travelling Salesman Problem** - Held-Karp (DP + Bitmask) | [`Practical-12/`](./Practical-12/) | [`practical_12.py`](./Practical-12/practical_12.py) | [`Practical_12_Travelling_Salesman.pdf`](./Practical-12/Practical_12_Travelling_Salesman.pdf) | Python | O(N²·2ᴺ) |

---

## 📁 Repository Structure (Formatted in Sequence)

```
DAA_5th_sem/
├── README.md                               # This file - Line-wise sequence index
├── Practical-01/                           # Sorting (C++)
│   ├── practical_01.cpp
│   ├── output.txt
│   └── Practical_01_Sorting_Ravi.pdf
├── Practical-02/                           # Searching (C++)
│   ├── practical_02.cpp
│   ├── output.txt
│   └── Practical_02_Searching_Ravi.pdf
├── Practical-03/                           # Heap Sort (C++)
│   ├── practical_03.cpp
│   ├── output.txt
│   └── Practical_03_HeapSort_Ravi.pdf
├── Practical-04/                           # Factorial (C++)
│   ├── practical_04.cpp
│   ├── output.txt
│   └── Practical_04_Factorial_Ravi.pdf
├── Practical-05/                           # Knapsack (C++)
│   ├── practical_05.cpp
│   ├── output.txt
│   ├── Practical_05_Knapsack_Ravi.pdf
│   └── Practical_05_Knapsack_Detailed_Ravi.pdf
├── Practical-06/                           # Matrix Chain (C++)
│   ├── practical_06.cpp
│   ├── output.txt
│   └── Practical_06_MatrixChain_Ravi.pdf
├── Practical-07/                           # Making Change (C++)
│   ├── practical_07.cpp
│   ├── output.txt
│   └── Practical_07_MakingChange_Ravi.pdf
├── Practical-08/                           # BFS/DFS (Python)
│   ├── practical_08.py
│   ├── output.txt
│   └── Practical_08_BFS_DFS.pdf
├── Practical-09/                           # Prim's MST (Python)
│   ├── practical_09.py
│   ├── output.txt
│   └── Practical_09_Prims_Ravi.pdf
├── Practical-10/                           # Kruskal MST (Python)
│   ├── practical_10.py
│   ├── output.txt
│   └── Practical_10_Kruskal_Ravi.pdf
├── Practical-11/                           # Floyd-Warshall (Python)
│   ├── practical_11.py
│   ├── output.txt
│   └── Practical_11_Floyd_Warshall.pdf
└── Practical-12/                           # TSP (Python)
    ├── practical_12.py
    ├── output.txt
    └── Practical_12_Travelling_Salesman.pdf
```

> **Note:** Original PDFs are also preserved at repository root for reference:
> `Practical_1.pdf` ... `Practical_5.pdf`, `Practical_05_Knapsack.pdf`, etc. + combined `Practical11_12_Ravi.pdf`.

---

## ▶️ How to Run

### C++ Practicals (01-07)
```bash
g++ -std=c++17 Practical-01/practical_01.cpp -o p01 && ./p01
g++ -std=c++17 Practical-02/practical_02.cpp -o p02 && ./p02
g++ -std=c++17 Practical-03/practical_03.cpp -o p03 && ./p03
g++ -std=c++17 Practical-04/practical_04.cpp -o p04 && ./p04
g++ -std=c++17 Practical-05/practical_05.cpp -o p05 && ./p05
echo -e "4\n10 20 30 40 30" | g++ -std=c++17 Practical-06/practical_06.cpp -o p06 && ./p06
echo -e "3\n1 3 4\n6" | g++ -std=c++17 Practical-07/practical_07.cpp -o p07 && ./p07
```

### Python Practicals (08-12)
```bash
python3 Practical-08/practical_08.py
python3 Practical-09/practical_09.py
python3 Practical-10/practical_10.py
python3 Practical-11/practical_11.py
python3 Practical-12/practical_12.py
```

---

## 📊 Sample Outputs

**Practical-01 (Sorting):**
```
Size    Bubble  Selection     Insertion       Merge   Quick
100     59      30            17              39      10
1000    6508    2597          1789            438     151
...
```

**Practical-05 (Knapsack):**
```
Maximum value in knapsack of capacity 50: 240
```

**Practical-08 (BFS/DFS):**
```
BFS: ['A', 'B', 'C', 'D', 'E', 'F']
DFS: ['A', 'B', 'D', 'E', 'F', 'C']
```

**Practical-11 (Floyd-Warshall):**
```
Final Shortest Distance Matrix:
[0, 3, 5, 6]
[5, 0, 2, 3]
[3, 6, 0, 1]
[2, 5, 7, 0]
```

**Practical-12 (TSP):**
```
Minimum Tour Cost: 80
Optimal Tour Path: 0 -> 1 -> 3 -> 2 -> 0
```

---

## 👤 Author
**Ravi Gohel** - Enrollment No: **92510118030**  
Department of AI, ML & DS - Faculty of Technology

> All practicals formatted line-wise in sequence as per DAA Lab Manual 2026.
