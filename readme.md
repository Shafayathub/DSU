# Disjoint Set Union (DSU) - Union-Find Algorithm

## Overview
The **Disjoint Set Union (DSU)** or **Union-Find** is a data structure that keeps track of a partition of elements into disjoint sets. It is widely used in graph algorithms for **cycle detection**, **minimum spanning trees (MSTs)**, and **network connectivity**.

## Key Operations
1. **Find (with Path Compression)**: Determines which subset an element belongs to and optimizes future queries.
2. **Union (by Rank/Size)**: Merges two subsets to form a single set while keeping the structure balanced.

## Implementation
### **C++ Code for DSU**
```cpp
#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path Compression
        return parent[x];
    }
    
    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

int main() {
    DSU dsu(5); // Initialize DSU with 5 elements
    dsu.union_sets(0, 1);
    dsu.union_sets(1, 2);
    cout << "Find(2): " << dsu.find(2) << endl;
    cout << "Find(3): " << dsu.find(3) << endl;
    return 0;
}
```

## Applications
- **Cycle Detection in Graphs** (Kruskal’s Algorithm)
- **Connected Components in Graphs**
- **Network Connectivity Problems**
- **Image Processing (Region Merging)**

## Time Complexity
| Operation         | Complexity |
|------------------|------------|
| Find (Path Compression) | O(α(n)) (inverse Ackermann) |
| Union (by Rank)  | O(α(n)) |
| Overall Complexity | Nearly O(1) per operation |

## Summary
The DSU is an efficient and powerful data structure for managing disjoint sets, making it a crucial tool for solving a variety of graph-related problems efficiently.
