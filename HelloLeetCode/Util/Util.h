#pragma once

#include <vector>

class Util {
public:
	// swap
	static void swap(int &a, int &b);

	// sort
	static void quickSort(std::vector<int> &nums);

private:
	static void doQuickSort(std::vector<int> &nums, int left, int right);
};