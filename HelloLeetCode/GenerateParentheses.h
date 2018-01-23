#pragma once

#include <string>
#include <vector>

void backtracking(std::vector<std::string> &res, std::string s, int l, int r, int n) {
	if (l == n && r == n) {
		res.push_back(s);
		return;
	}

	if (l < n)
		backtracking(res, s + "(", l + 1, r, n);
	if (r < l)
		backtracking(res, s + ")", l, r + 1, n);
}

std::vector<std::string> generateParenthesis(int n) {
	std::vector<std::string> res;

	if (n == 0)
		return res;
	else if (n == 1) {
		res.push_back("()");
		return res;
	}

	backtracking(res, "", 0, 0, n);

	return res;
}