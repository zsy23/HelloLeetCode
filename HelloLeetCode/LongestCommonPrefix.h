#pragma once

#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
	int sn = strs.size();
	if (sn <= 0)
		return "";

	std::string res = "";
	char c = 0;
	int i = 0, j = 0;

	while (j < strs[0].length()) {
		c = strs[0][j];
		for (i = 1; i < sn; ++i) {
			if (j >= strs[i].length() || c != strs[i][j])
				return res;
		}

		res += c;
		j++;
	}

	return res;
}