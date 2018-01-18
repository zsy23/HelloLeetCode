#pragma once

#include <vector>

// thought important !!!

int maxArea(std::vector<int>& height) {
	int n = height.size();
	int l = 0, r = n - 1;
	int area = 0, tmp = 0;

	while (l < r) {
		if (height[l] > height[r]) {
			tmp = (r - l) * height[r];
			area = tmp > area ? tmp : area;
			r--;
		}
		else {
			tmp = (r - l) * height[l];
			area = tmp > area ? tmp : area;
			l++;
		}
	}

	return area;
}