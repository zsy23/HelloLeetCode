#pragma once

#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int> &nums, int target) {
	std::unordered_map<int, int> table;
	int i = 0, vi = 0, vj = 0;

	for (; i < nums.size(); ++i) {
		vi = nums[i];
		vj = target - vi;
		if (table.find(vj) != table.end()) {
			int res[] = { table[vj], i };
			return std::vector<int>(res, res + 2);
		}

		table[vi] = i;
	}

	return std::vector<int>();
};