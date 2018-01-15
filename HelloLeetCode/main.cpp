#include "Util/Util.h"
#include "FindMedianSortedArrays.h"

#include <iostream>

int main(int argc, char *arg[]) {
	std::vector<int> nums1, nums2;
	nums1.push_back(1); nums1.push_back(2);
	nums2.push_back(3); nums2.push_back(4);
	printf("%lf\n", findMedianSortedArrays(nums1, nums2));

	system("pause");

	return 0;
}