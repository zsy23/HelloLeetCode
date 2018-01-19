#pragma once

#include <string>
#include <vector>

//#define RECURSION
#define ITERATION

std::string table[10];

#ifdef RECURSION
void iter(std::vector<std::string> &res, std::string digits, std::string tmp) {
	if (digits.length() <= 0) {
		if (tmp.length() > 0)
			res.push_back(tmp);
		return;
	}

	std::string candi = table[digits[0] - '0'];
	for (int i = 0; i < candi.length(); ++i) {
		iter(res, digits.substr(1), tmp + candi[i]);
	}
}
#endif

std::vector<std::string> letterCombinations(std::string digits) {
	table[0] = "";
	table[1] = "";
	table[2] = "abc";
	table[3] = "def";
	table[4] = "ghi";
	table[5] = "jkl";
	table[6] = "mno";
	table[7] = "pqrs";
	table[8] = "tuv";
	table[9] = "wxyz";

	std::vector<std::string> res;

#ifdef RECURSION
	iter(res, digits, "");
#endif

#ifdef ITERATION
	if (digits.length() <= 0)
		return res;

	res.push_back("");

	for (int i = 0; i < digits.length(); ++i) {
		if (table[digits[i] - '0'].length() == 0)
			continue;

		std::vector<std::string> tmp;

		for (int j = 0; j < table[digits[i] - '0'].length(); ++j)
			for (int k = 0; k < res.size(); ++k)
				tmp.push_back(res[k] + table[digits[i] - '0'][j]);

		res = tmp;
	}
#endif

	return res;
}