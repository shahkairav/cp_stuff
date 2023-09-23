#include <vector>
#include <queue>
using namespace std;

// Rather convoluted way by using Heap
// Simpler approaches: sort and then linear / binary search

class Solution {
public:
    int hIndex(vector<int>& citations) {
        priority_queue<int> heap(citations.begin(), citations.end());
        int h_index = 0;
        int counter = 0;
        while (!heap.empty()) {
          counter++;
          int element = heap.top();
          heap.pop();
          if (element > h_index) {
            h_index = min(element, counter);
          }
        }
        return h_index;
    }
};