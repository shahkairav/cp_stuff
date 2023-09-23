#include <iostream>
#include <vector>

class DSU {
private:
  int n;
  vector<int> parent;
  vector<int> size;

public:
  DSU(int n) {
    parent.resize(n, 0);
    size.reserve(n);
    std::fill(parent.begin(), parent.end(), 0);
    std::fill(size.begin(), size.end(), 0);
  }

  void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
  }

  int find_set(int v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find_set(parent[v]); // path compression
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) { // union by size
      if (size[a] < size[b]) std::swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
};

int main() {

}

/*
Example use cases:
  1. connected components in a graph
*/