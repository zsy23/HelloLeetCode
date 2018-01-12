#pragma once

#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *res = new ListNode(0);
	ListNode *p = l1, *q = l2, *cur = res;
	int a = 0, c = 0;

	while (p != NULL || q != NULL) {
		a = (p != NULL) ? p->val : 0;
		a += (q != NULL) ? q->val : 0;
		a += c;

		cur->next = new ListNode(a % 10);
		cur = cur->next;

		c = a / 10;

		p = (p != NULL) ? p->next : NULL;
		q = (q != NULL) ? q->next : NULL;
	}

	if (c > 0)
		cur->next = new ListNode(c);

	return res->next;
}