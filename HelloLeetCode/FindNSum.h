#pragma once

#include <vector>
#include <algorithm>

std::vector<std::vector<int> > findNSum(std::vector<int> &nums, int start, int end, int N, int target) {
	std::vector<std::vector<int> > res;
	if (start > end || N * nums[start] > target || N * nums[end] < target)
		return res;

	if (N <= 2) {
		int l = start, r = end;
		while (l < r) {
			if (nums[l] + nums[r] < target)
				for (++l; l < r && nums[l] == nums[l - 1]; ++l);
			else if (nums[l] + nums[r] > target)
				for (--r; r > l && nums[r] == nums[r + 1]; --r);
			else {
				std::vector<int> tmp;
				tmp.push_back(nums[l]);
				tmp.push_back(nums[r]);
				res.push_back(tmp);
				for (++l; l < r && nums[l] == nums[l - 1]; ++l);
				for (--r; r > l && nums[r] == nums[r + 1]; --r);
			}
		}
	}
	else {
		for (int i = start; i < end - N + 2;) {
			if (N * nums[i] <= target) {
				std::vector<std::vector<int> > tmp = findNSum(nums, i + 1, end, N - 1, target - nums[i]);
				for (int j = 0; j < tmp.size(); ++j) {
					tmp[j].insert(tmp[j].begin(), nums[i]);
					res.push_back(tmp[j]);
				}
			}
			for (++i; i < end - N + 2 && nums[i] == nums[i - 1]; ++i);
		}
	}

	return res;
}

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
	int N = 4;
	//assert(N >= 2);
	std::sort(nums.begin(), nums.end());
	return findNSum(nums, 0, nums.size() - 1, N, target);
}