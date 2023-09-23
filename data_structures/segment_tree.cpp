#include <iostream>
#include <vector>

class SegmentTree {
private:
  int num_elements;
  std::vector<int> tree;

  void build(const std::vector<int>& arr, int v, int tl, int tr) {
    if (tl == tr) {
      tree[v] = arr[tl];
    } 
    else {
      int tm = (tl + tr) / 2;
      build(arr, v*2, tl, tm);
      build(arr, v*2+1, tm+1, tr);
      tree[v] = tree[v*2] + tree[v*2 + 1];
    }
  }

  void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
      tree[v] = new_val;
    }
    else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        update(2*v, tl, tm, pos, new_val);
      }
      else {
        update(2*v + 1, tm+1, tr, pos, new_val);
      }
      tree[v] = tree[2*v] + tree[2*v + 1];
    }
  }

  int sum(int v, int tl, int tr, int l, int r) {
    // v is the current node of the tree being processed
    // tl and tr are the actual boundaries of the node v
    if (l > r) return 0;
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    return sum(2*v, tl, tm, l, std::min(r, tm)) + sum(2*v+1, tm+1, tr, std::max(l, tm+1), r);
  }

public:
  SegmentTree(const std::vector<int>& arr) {
    num_elements = arr.size();
    tree.resize(4*num_elements, 0);
    build(arr, 1, 0, arr.size()-1);
  }

  void update(int pos, int new_val) {
    update(1, 0, num_elements-1, pos, new_val);
  }

  int sum(int l, int r) {
    return sum(1, 0, num_elements-1, l, r);
  }
};


int main() {
  int n;
  std::cin >> n;
  std::vector<int> vec;
  vec.resize(n, 0);
  for(int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }

  SegmentTree ST(vec);

  while (true) {
    char query;
    std::cin >> query;
    if (query == 'u') {
      int pos, new_val;
      std::cin >> pos >> new_val;
      ST.update(pos, new_val);
    }
    else if (query == 's') {
      int l, r;
      std::cin >> l >> r;
      std::cout << ST.sum(l, r) << std::endl;
    }
    else {
      std::cout << "Invalid query!" << std::endl;
    }
  }
  return 0;
}