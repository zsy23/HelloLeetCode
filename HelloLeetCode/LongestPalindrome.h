#pragma once

#include <string>
#include <vector>

//#define DYNAMIC_PROGRAMMING
#define MANACHER

std::string longestPalindrome(std::string s) {
#ifdef DYNAMIC_PROGRAMMING

	int n = s.length();
	// char *table = new char[n * n](0); -- error
	char *table = new char[n * n]();
	int i = 0, j = 0;
	std::string res = "";

	for (j = 1; j <= n; ++j) {
		for (i = 0; i + j <= n; ++i) {
			table[i * n + (i + j - 1)] =
				(s[i] == s[i + j - 1]) && (j < 3 || table[(i + 1) * n + (i + j - 2)]);

			if (table[i * n + (i + j - 1)] && (j > res.length()))
				res = s.substr(i, j);
		}
	}

	delete[] table;

	return res;

#endif

#ifdef MANACHER

	int n = s.length();
	std::string padStr(2 * n + 1, '`');
	std::vector<int> len(2 * n + 1, 1);
	int pos = 0, p = 0, i = 0, j = 0, l = 0;

	for (i = 0; i < n; ++i)
		padStr[2 * i + 1] = s[i];

	n = padStr.length();
	for (i = 1; i < n; ++i) {
		if (i <= p) {
			j = 2 * pos - i;
			if (i + len[j] - 1 < p)
				len[i] = len[j];
			else {
				for (l = p; l < n && 2 * i - l >= 0 &&
					padStr[l] == padStr[2 * i - l]; ++l);
				pos = i;
				p = l - 1;
				len[i] = p - i + 1;
			}
		}
		else {
			for (l = 2; i + l - 1 < n && i - l + 1 >= 0 &&
				padStr[i + l - 1] == padStr[i - l + 1]; ++l);
			len[i] = l - 1;
			if (i + len[i] - 1 > p) {
				pos = i;
				p = i + len[i] - 1;
			}
		}
	}

	l = len[0];
	j = 0;
	for (i = 0; i < n; ++i) {
		if (l < len[i]) {
			l = len[i];
			j = i;
		}
	}

	std::string res(l - 1, 0);
	for (i = 0; i < l - 1; ++i)
		res[i] = padStr[j - l + 1 + 2 * i + 1];

	return res;

#endif

}