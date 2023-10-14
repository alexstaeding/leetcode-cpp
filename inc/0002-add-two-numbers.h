#ifndef ADD_TWO_NUMBERS_H
#define ADD_TWO_NUMBERS_H

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

#endif // ADD_TWO_NUMBERS_H
