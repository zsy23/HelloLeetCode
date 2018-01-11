#include "Util.h"

///////////////////////////////////////////////////// Util /////////////////////////////////////////////////////
void Util::swap(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

///////////////////////////////////////////////////// Sort /////////////////////////////////////////////////////
void Util::doQuickSort(std::vector<int> &nums, int left, int right) {
	if (left >= right)
		return;

	int i = left, j = right;
	int k = nums[i];

	while (i < j) {
		for (; i < j && nums[j] >= k; --j);
		if (i == j)
			break;
		else
			swap(nums[i], nums[j]);
		for (; i < j && nums[i] <= k; ++i);
		if (i == j)
			break;
		else
			swap(nums[i], nums[j]);
	}

	doQuickSort(nums, left, i - 1);
	doQuickSort(nums, j + 1, right);
}

void Util::quickSort(std::vector<int> &nums) {
	doQuickSort(nums, 0, nums.size() - 1);
}