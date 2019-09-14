/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int val) {
      Node* cur = head;
      if (!head) {
        head = new Node();
        head->val = val;
        head->next = head;
        return head;
      } else {
        bool found = false;
        while(true) {
          Node* next = cur->next;
          if (cur->val <= next->val) {
            if (val >= cur->val && val <= next->val) {
              Node* tmp = new Node(val, next);
              tmp->next = next;
              cur->next = tmp;
              found= true;
              break;
            }
          } else if (cur->val >= next->val) {
            if (val >= cur->val || val <= next->val) {
              Node* tmp = new Node(val, next);
              tmp->next = next;
              cur->next = tmp;
              found = true;
              break;
            }
          }
          cur = next;
          if (cur == head) break;
        }
        if (!found) {
          Node* tmp = new Node(val, head->next);
          tmp->next = head->next;
          head->next = tmp;
        }
      }
      return head;
    }
};
