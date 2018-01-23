#include "Util/Util.h"
#include "FindNSum.h"

#include <iostream>

int main(int argc, char *arg[]) {
	int nums2[] = { -2,0,0,3,3,-1 };
	std::vector<int> nums(nums2, nums2 + 6);

	std::vector<std::vector<int>> res = fourSum(nums, 5);

	system("pause");

	return 0;
}