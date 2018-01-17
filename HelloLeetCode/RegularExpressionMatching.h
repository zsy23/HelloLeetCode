#pragma once

#include <vector>

//#define DP_TOP_DOWN
#define DP_BOTTOM_UP

std::vector<std::vector<int> > res;

int dp(std::string s, int i, std::string p, int j) {
	if (res[i][j] >= 0)
		return res[i][j];

	int sn = s.length(), pn = p.length();

	if (pn == 0)
		return !sn;

	int ans = -1;

	int firstMatch = sn && ((s[0] == p[0]) || (p[0] == '.'));

	if (pn >= 2 && p[1] == '*')
		ans = dp(s.substr(0), i, p.substr(2), j + 2) || 
			 (firstMatch && dp(s.substr(1), i + 1, p.substr(0), j));
	else
		ans = firstMatch && dp(s.substr(1), i + 1, p.substr(1), j + 1);

	res[i][j] = ans;

	return ans;
}

bool isMatch(std::string s, std::string p) {
	int sn = s.length(), pn = p.length();
	res.resize(sn + 1);
	for (int i = 0; i < sn + 1; ++i)
		res[i].assign(pn + 1, -1);

#ifdef DP_TOP_DOWN
	int ans = dp(s, 0, p, 0);
#endif

#ifdef DP_BOTTOM_UP
	for (int i = sn; i >= 0; --i) {
		for (int j = pn; j >= 0; --j) {
			if (j == pn) {
				res[i][j] = (i == sn);
				continue;
			}

			if (p[j] == '*')
				continue;

			int firstMatch = (i < sn) && ((s[i] == p[j]) || (p[j] == '.'));

			if (j + 1 < pn && p[j + 1] == '*')
				res[i][j] = res[i][j + 2] ||
					(firstMatch && res[i + 1][j]);
			else
				res[i][j] = firstMatch && res[i + 1][j + 1];
		}
	}

	int ans = res[0][0];
#endif

	return ans;
}