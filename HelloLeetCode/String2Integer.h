#pragma once

#include <string>

int myAtoi(std::string str) {
	int neg = 1, res = 0, flag = 1;
	int i = 0, j = str.length() - 1;

	for (; i <= j && (str[i] == ' ' || str[i] == '\t'); ++i);
	if (i > j)
		return 0;

	for (; i <= j; ++i) {
		if (flag == 1 && str[i] == '+') {
			neg = 1;
			flag = 0;
		}
		else if (flag == 1 && str[i] == '-') {
			neg = -1;
			flag = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			// overflow !!!
			if (neg == 1) {
				if (res > INT_MAX / 10 || res * 10 > INT_MAX - (str[i] - '0'))
					return INT_MAX;
			}
			else if (neg == -1) {
				if (-res < INT_MIN / 10 || -res * 10 < INT_MIN +/* !!! */(str[i] - '0')) // !!!
					return INT_MIN;
			}

			res = res * 10 + str[i] - '0';
			flag = 0;
		}
		else
			return neg * res; // "  -0012a42"
	}

	return neg * res;
}