struct node {
  int x;
  bool operator < (const node& y) const {
    return x > y.x;
  }
};

class MedianFinder {
public:
  MedianFinder() {
  }
  void addNum(int num) {
    if (maxq.size() == minq.size()) {
        if (minq.size() > 0 && minq.top().x < num) {
            node top = minq.top();
            minq.pop();
            maxq.push(top.x);
            node tmp;
            tmp.x = num;
            minq.push(tmp);
        } else {
            maxq.push(num);
        }
    } else {
        if (num >= maxq.top()) {
            node tmp;
            tmp.x = num;
            minq.push(tmp);
        } else {
            int t = maxq.top();
            maxq.pop();
            node tmp;
            tmp.x = t;
            minq.push(tmp);
            maxq.push(num);
        }
    }
  }
  double findMedian() {
    if (maxq.size() > minq.size()) {
      return maxq.top();
    }
    int x = maxq.top();
    node tmp = minq.top();
    int y = tmp.x;
    return 0.5*(x+y);
  }
private:
  priority_queue<int> maxq;
  priority_queue<node> minq;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
