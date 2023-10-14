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

static ListNode *createList(const std::vector<int> &nums) {
  ListNode *head = nullptr;
  ListNode *tail = nullptr;
  for (int num : nums) {
    if (head == nullptr) {
      head = new ListNode(num);
      tail = head;
    } else {
      tail->next = new ListNode(num);
      tail = tail->next;
    }
  }
  return head;
}

TEST_CASE("Single create list", "[createList]") {
  auto *l1 = new ListNode(2);

  std::vector<int> nums = {2};

  requireEqual(l1, createList(nums));
}

TEST_CASE("Simple create list", "[createList]") {
  auto *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  std::vector<int> nums = {2, 4, 3};

  requireEqual(l1, createList(nums));
}

TEST_CASE("Same instance case", "[requireEqual]") {
  auto *l1 = createList(std::vector<int>{5, 0, 8, 2});

  requireEqual(l1, l1);
}

TEST_CASE("Different instance case", "[requireEqual]") {
  auto *l1 = createList(std::vector<int>{3, 1, 7, 6, 3});
  auto *l2 = createList(std::vector<int>{3, 1, 7, 6, 3});

  requireEqual(l1, l2);
}

TEST_CASE("Simple Case 1", "[addTwoNumbers]") {
  auto *l1 = createList(std::vector<int>{2, 4, 3});
  auto *l2 = createList(std::vector<int>{5, 6, 4});
  auto *expected = createList(std::vector<int>{7, 0, 8});

  requireEqual(expected, addTwoNumbers(l1, l2));
}

TEST_CASE("Simple Case 2", "[addTwoNumbers]") {
  auto *l1 = createList(std::vector<int>{1, 2, 3});
  auto *l2 = createList(std::vector<int>{2, 3, 9});
  auto *expected = createList(std::vector<int>{3, 5, 2, 1});

  requireEqual(expected, addTwoNumbers(l1, l2));
}

TEST_CASE("Multi carry 1", "[addTwoNumbers]") {
  auto *l1 = createList(std::vector<int>{9, 9, 9});
  auto *l2 = createList(std::vector<int>{1});
  auto *expected = createList(std::vector<int>{0, 0, 0, 1});

  requireEqual(expected, addTwoNumbers(l1, l2));
}

TEST_CASE("Multi carry 2", "[addTwoNumbers]") {
  auto *l1 = createList(std::vector<int>{9, 9, 9});
  auto *l2 = createList(std::vector<int>{9, 9, 9, 9});
  auto *expected = createList(std::vector<int>{8, 9, 9, 0, 1});

  requireEqual(expected, addTwoNumbers(l1, l2));
}

TEST_CASE("Complex Case 1", "[addTwoNumbers]") {
  auto *l1 = createList(std::vector<int>{0, 8, 6, 5, 6, 8, 3, 5, 7});
  auto *l2 = createList(std::vector<int>{6, 7, 8, 0, 8, 5, 8, 9, 7});
  auto *expected = createList(std::vector<int>{6, 5, 5, 6, 4, 4, 2, 5, 5, 1});

  requireEqual(expected, addTwoNumbers(l1, l2));
}
