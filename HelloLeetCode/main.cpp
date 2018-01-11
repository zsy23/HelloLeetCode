#include "Util/Util.h"

#include <iostream>

int main(int argc, char *arg[]) {
	int tmp[] = { 11, 11, 11, 2, 2 };
	size_t count = sizeof(tmp) / sizeof(int);
	std::vector<int> nums(tmp, tmp + count);
	Util::quickSort(nums);
	for (int i = 0; i < nums.size(); ++i)
		std::cout << nums[i] << " ";
	std::cout << std::endl;

	system("pause");

	return 0;
}