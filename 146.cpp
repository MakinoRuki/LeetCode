// O(1) 用链表。

struct Node {
  int key;
  int val;
  Node* pre;
  Node* nxt;
  Node(int k, int v) : key(k), val(v), pre(NULL), nxt(NULL) {}
};

class LRUCache {
  public:
  int cap_;
  int sz_;
  Node* head;
  Node* tail;
  unordered_map<int, Node*> mm;
  LRUCache(int capacity) {
    cap_ = capacity;
    sz_ = 0;
    head= NULL;
    tail= NULL;
  }
  void modifyCache(int key, int val) {
    Node* cur = mm[key];
    if (cur == head) {
      if (!head->nxt) {
          head->val=val;
          return;
      }
      head=head->nxt;
      head->pre=NULL;
      tail->nxt=cur;
      cur->pre=tail;
      cur->nxt=NULL;
      tail = cur;
    } else if (cur!=tail) {
      Node* p1 = cur->pre;
      Node* p2 = cur->nxt;
      p1->nxt=p2;
      p2->pre=p1;
      tail->nxt=cur;
      cur->nxt=NULL;
      cur->pre=tail;
      tail=cur;
    }
    cur->val = val;
  }
  void put(int key, int val) {
    if (mm.find(key) != mm.end()) {
      modifyCache(key, val);
    } else {
      if (sz_ >= cap_) {
        mm.erase(head->key);
        head = head->nxt;
        head->pre = NULL;
        sz_--;
      }
      Node* cur = new Node(key, val);
      if (head == NULL) {
          head = cur;
          tail = cur;
      } else {
          tail->nxt=cur;
          cur->pre=tail;
          cur->nxt=NULL;
          tail=cur;
      }
      mm[key] = cur;
      sz_++;
    }
  }
  int get(int key) {
    if (mm.find(key) == mm.end()) return -1;
    modifyCache(key, mm[key]->val);
    return mm[key]->val;
  }
};
