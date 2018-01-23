#pragma once

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	ListNode *head = l1, *cur = NULL;
	ListNode *cur1 = l1, *cur2 = l2;
	if (l1->val > l2->val) {
		head = l2;
		cur2 = cur2->next;
	}
	else
		cur1 = cur1->next;
	cur = head;

	while (cur1 && cur2) {
		if (cur1->val <= cur2->val) {
			cur->next = cur1;
			cur1 = cur1->next;
		}
		else {
			cur->next = cur2;
			cur2 = cur2->next;
		}
		cur = cur->next;
	}

	if (!cur1)
		cur->next = cur2;
	else
		cur->next = cur1;

	return head;
}