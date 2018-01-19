#pragma once

#include <vector>
#include <algorithm>

int threeSumClosest(std::vector<int>& nums, int target) {
	if (nums.size() < 3)
		return 0;

	int closest = nums[0] + nums[1] + nums[2];
	int n = nums.size(), cur = 0;

	std::sort(nums.begin(), nums.end());

	for (int i = 0; i < n - 2;) {
		for (int l = i + 1, r = n - 1; l < r;) {
			if ((cur = nums[i] + nums[l] + nums[r]) < target) {
				if (abs(cur - target) < abs(closest - target))
					closest = cur;
				for (++l; (l < r) && (nums[l] == nums[l - 1]); ++l);
			}
			else if ((cur = nums[i] + nums[l] + nums[r]) > target) {
				if (abs(cur - target) < abs(closest - target))
					closest = cur;
				for (--r; (r > l) && (nums[r + 1] == nums[r]); --r);
			}
			else {
				return target;
			}
		}

		for (++i; (i < n - 2) && (nums[i] == nums[i - 1]); ++i);
	}

	return closest;
}