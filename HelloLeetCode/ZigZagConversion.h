#pragma once

#include <vector>
#include <string>

std::string zigzagConversion(std::string s, int numRows) {
	if (numRows < 2)
		return s;

	int n = s.length(), m = numRows + numRows - 2;
	std::vector<std::string> mat(numRows, "");
	int y = 0, i = 0;

	for (i = 0; i < n; ++i) {
		y = i % m;
		y = (y < numRows) ? y : m - y;

		mat[y] += s[i];
	}

	std::string res = "";
	for (y = 0; y < numRows; ++y)
		res += mat[y];

	return res;
}