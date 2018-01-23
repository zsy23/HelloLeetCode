#pragma once

#include <string>
#include <stack>

bool isValid(std::string s) {
	int n = s.length();
	std::stack<char> stk;

	for (int i = 0; i < n; ++i) {
		switch (s[i]) {
		case '(':
			stk.push(')');
			break;
		case '{':
			stk.push('}');
			break;
		case '[':
			stk.push(']');
			break;
		case ')':
		case '}':
		case ']':
			if (stk.size() == 0 || stk.top() != s[i])
				return 0;
			stk.pop();
			break;
		default:
			return 0;
		}
	}

	return stk.size() == 0;
}