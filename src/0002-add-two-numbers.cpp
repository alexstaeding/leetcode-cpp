#include <iostream>
#include "0002-add-two-numbers.h"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  // numbers do not contain leading 0, except for 0 itself
  if (l1->val == 0) {
    return l2;
  }
  if (l2->val == 0) {
    return l1;
  }

  int carry = 0;
  ListNode *head = nullptr;
  ListNode *tail = nullptr;

  while (l1 != nullptr || l2 != nullptr) {
    int currentDigit = (l1 != nullptr ? l1->val : 0)
        + (l2 != nullptr ? l2->val : 0)
        + carry;

    if (currentDigit >= 10) {
      carry = 1;
      currentDigit -= 10;
    } else {
      carry = 0;
    }

    std::cout << "currentDigit: " << currentDigit << std::endl;
    if (head == nullptr) {
      head = new ListNode(currentDigit);
      tail = head;
    } else {
      tail->next = new ListNode(currentDigit);
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
