#pragma once

#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	if (nums1.size() > nums2.size())
		return findMedianSortedArrays(nums2, nums1);

	int m = nums1.size(), n = nums2.size();
	int imin = 0, imax = m, i, j;
	while (imin <= imax) {
		i = (imin + imax) / 2;
		j = (m + n + 1) / 2 - i;

		// error
		//if (i > 0 && i < m &&
		//	nums1[i - 1] <= nums2[j] && nums2[j - 1] <= nums1[i])
		//	break;
		//else if (i > 0 && nums1[i - 1] > nums2[j])
		//	imax = i - 1;
		//else if (i < m && nums2[j - 1] > nums1[i])
		//	imin = i + 1;

		if (i > 0 && nums1[i - 1] > nums2[j])
			imax = i - 1;
		else if (i < m && nums2[j - 1] > nums1[i])
			imin = i + 1;
		else
			break;
	}

	double l = 0.0;
	if (i == 0)
		l = nums2[j - 1];
	else if (j == 0)
		l = nums1[i - 1];
	else
		l = nums1[i - 1] >= nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];

	// if (m + n % 2) -- error
	if ((m + n) % 2)
		return l;

	double r = 0.0;
	if (i == m)
		r = nums2[j];
	else if (j == n)
		r = nums1[i];
	else
		r = nums1[i] <= nums2[j] ? nums1[i] : nums2[j];

	return (l + r) / 2.0;
}