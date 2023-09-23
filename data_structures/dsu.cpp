#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
  int n;
  vector<int> parent;

public:
  DSU(int n) {
    parent.reserve(n);
    std::fill(parent.begin(), parent.end(), 0);
  }

  void make_set(int v) {
    parent[v] = v;
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
    if (a != b) {
      parent[b] = a;
    }
  }
};

int main() {

}