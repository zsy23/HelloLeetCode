#pragma once

#include <vector>
#include <algorithm>

std::vector<std::vector<int>>  threeSum(std::vector<int>& nums) {
	std::vector<std::vector<int> > res;
	std::vector<int> tmp;
	int n = nums.size(), target = 0;

	std::sort(nums.begin(), nums.end());

	// error
	//for (int i = 0; i < n - 2; ++i) {
	//	target = -nums[i];

	//	for (int l = i + 1, r = n - 1; l < r;) {
	//		if (nums[l] + nums[r] < target)
	//			for (; ((l + 1) < r) && (nums[l + 1] == nums[l]); ++l); // !!!
	//		else if (nums[l] + nums[r] > target)
	//			for (; ((r - 1) > l) && (nums[r - 1] == nums[r]); --r); // !!!
	//		else {
	//			tmp.clear();
	//			tmp.push_back(nums[i]);
	//			tmp.push_back(nums[l]);
	//			tmp.push_back(nums[r]);
	//			res.push_back(tmp);

	//			for (; ((l + 1) < r) && (nums[l + 1] == nums[l]); ++l);
	//			for (; ((r - 1) > l) && (nums[r - 1] == nums[r]); --r);
	//		}
	//	}

	//	for (; (i + 1 < n - 2) && (nums[i + 1] == nums[i]); ++i); // !!!
	//}

	for (int i = 0; i < n - 2;) {
		target = -nums[i];

		for (int l = i + 1, r = n - 1; l < r;) {
			if (nums[l] + nums[r] < target)
				for (++l; (l < r) && (nums[l] == nums[l - 1]); ++l);
			else if (nums[l] + nums[r] > target)
				for (--r; (r > l) && (nums[r + 1] == nums[r]); --r);
			else {
				tmp.clear();
				tmp.push_back(nums[i]);
				tmp.push_back(nums[l]);
				tmp.push_back(nums[r]);
				res.push_back(tmp);

				for (++l; (l < r) && (nums[l] == nums[l - 1]); ++l);
				for (--r; (r > l) && (nums[r + 1] == nums[r]); --r);
			}
		}

		for (++i; (i < n - 2) && (nums[i] == nums[i - 1]); ++i);
	}

	return res;
}