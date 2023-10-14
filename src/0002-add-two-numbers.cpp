#include <iostream>
#include "0002-add-two-numbers.h"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  int carry = 0;
  ListNode *head = nullptr;
  ListNode *tail = nullptr;

  while (l1 != nullptr || l2 != nullptr) {
    if (head == nullptr) {
      if (((l1 != nullptr ? l1->val : 0)
          + (l2 != nullptr ? l2->val : 0)
          + carry) > 9) {
        head = new ListNode((l1 != nullptr ? l1->val : 0)
                                + (l2 != nullptr ? l2->val : 0)
                                + carry - 10);
        carry = 1;
      } else {
        head = new ListNode((l1 != nullptr ? l1->val : 0)
                                + (l2 != nullptr ? l2->val : 0)
                                + carry);
        carry = 0;
      }
      tail = head;
    } else {
      if (((l1 != nullptr ? l1->val : 0)
          + (l2 != nullptr ? l2->val : 0)
          + carry) > 9) {
        tail->next = new ListNode((l1 != nullptr ? l1->val : 0)
                                      + (l2 != nullptr ? l2->val : 0)
                                      + carry - 10);
        carry = 1;
      } else {
        tail->next = new ListNode((l1 != nullptr ? l1->val : 0)
                                      + (l2 != nullptr ? l2->val : 0)
                                      + carry);
        carry = 0;
      }
      tail = tail->next;
    }

    if (l1 != nullptr) {
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      l2 = l2->next;
    }
  }

  if (carry == 1) {
    tail->next = new ListNode(1);
  }
  return head;
}
