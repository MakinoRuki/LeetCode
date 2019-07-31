#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 10001
using namespace std;
class Head {
  int cnt = 0;
  int heap[N];
  public:
    void push(int x) {
      heap[++cnt] = x;
      int cur = cnt;
      while(cur > 1) {
        if (heap[cur] >= heap[cur/2]) {
          break;
        }
        swap(heap[cur], heap[cur/2]);
        cur /= 2;
      }
    }
    bool empty() {
      return cnt == 0;
    }
    int top() {
      return heap[1];
    }
    void pop() {
      heap[1] = heap[cnt];
      cnt--;
      int cur = 1;
      while(cur < cnt) {
        if (heap[cur] <= heap[2*cur] && heap[cur] <= heap[cur*2+1]) {
          break;
        }
        if (heap[cur*2] <= heap[cur] && heap[cur*2] <= heap[cur*2+1]) {
          swap(heap[cur], heap[cur*2]);
          cur*=2;
        } else if (heap[cur*2+1] <= heap[cur] && heap[cur*2+1] <= heap[cur]) {
          swap(heap[cur], heap[cur*2+1]);
          cur=cur*2+1;
        }
      }
    }
};
