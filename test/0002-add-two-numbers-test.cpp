#include <catch2/catch_test_macros.hpp>
#include "0002-add-two-numbers.h"
#include <iostream>

static void print(ListNode *l) {
  while (l != nullptr) {
    std::cout << l->val << " ";
    l = l->next;
  }
  std::cout << std::endl;
}

static void printBoth(ListNode *l1, ListNode *l2) {
  std::cout << "l1: ";
  print(l1);
  std::cout << "l2: ";
  print(l2);
}

static void requireEqual(ListNode *l1, ListNode *l2) {
  auto *ol1 = l1;
  auto *ol2 = l2;
  printBoth(ol1, ol2);
  int pos = 0;
  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val != l2->val) {
      FAIL("l1->val: " << l1->val << " != l2->val: " << l2->val << " at pos: " << pos);
    }
    l1 = l1->next;
    l2 = l2->next;
    pos++;
  }
  if (l1 != nullptr) {
    FAIL("l1 is too long");
  }
  if (l2 != nullptr) {
    FAIL("l2 is too long");
  }
}

TEST_CASE("Same instance case", "[requireEqual]") {
  auto *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  requireEqual(l1, l1);
}

TEST_CASE("Different instance case", "[requireEqual]") {
  auto *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  auto *l2 = new ListNode(2);
  l2->next = new ListNode(4);
  l2->next->next = new ListNode(3);

  requireEqual(l1, l2);
}

TEST_CASE("Simple Case 1", "[addTwoNumbers]") {
  auto *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  auto *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  auto *expected = new ListNode(7);
  expected->next = new ListNode(0);
  expected->next->next = new ListNode(8);

  requireEqual(expected, addTwoNumbers(l1, l2));
}

TEST_CASE("Simple Case 2", "[addTwoNumbers]") {
  auto *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(3);

  auto *l2 = new ListNode(2);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(9);

  auto *expected = new ListNode(3);
  expected->next = new ListNode(5);
  expected->next->next = new ListNode(2);
  expected->next->next->next = new ListNode(1);

  requireEqual(expected, addTwoNumbers(l1, l2));
}
