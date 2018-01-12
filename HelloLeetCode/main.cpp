#include "Util/Util.h"
#include "TwoSum.h"

#include <iostream>

int main(int argc, char *arg[]) {
	int tmp[] = { 3,2,4 };
	std::vector<int> nums(tmp, tmp + 3);
	std::vector<int> res = twoSum(nums, 6);
	for (int i = 0; i < res.size(); ++i)
		std::cout << res[i] << " ";
	std::cout << std::endl;

	system("pause");

	return 0;
}