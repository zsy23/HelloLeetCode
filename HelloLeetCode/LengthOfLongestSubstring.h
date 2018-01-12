#pragma once

#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
	std::unordered_map<char, int> table;
	int start = 0, len = 0, cur = 0, tmp = 0;
	int n = s.length();
	char c = 0;

	for (; cur < n; ++cur) {
		c = s[cur];

		if (table.find(c) != table.end() && table[c] >= start) {
			tmp = cur - start;
			if (len < tmp)
				len = tmp;
			start = table[c] + 1;
		}

		table[c] = cur;
	}

	tmp = n - start;
	if (len < tmp)
		len = tmp;

	return len;
}