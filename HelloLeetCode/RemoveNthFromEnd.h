#pragma once

#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *cur = head;
	ListNode *tar = head, *pre = head;
	int cnt = 0;

	for (cnt = 1; cnt < n; ++cnt)
		cur = cur->next;

	if (cur->next) {
		cur = cur->next;
		tar = tar->next;

		while (cur->next) {
			cur = cur->next;
			tar = tar->next;
			pre = pre->next;
		}

		pre->next = tar->next;
	}
	else
		head = head->next;

	return head;
}