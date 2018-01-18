#pragma once

#include <string>
#include <unordered_map>

int romanToInt(std::string s) {
	std::unordered_map<char, int> table = { { 'I' , 1 },
											{ 'V' , 5 },
											{ 'X' , 10 },
											{ 'L' , 50 },
											{ 'C' , 100 },
											{ 'D' , 500 },
											{ 'M' , 1000 } };

	//         int res = 0, tmp = 0;
	//         for(int i = 0; i < s.length(); ++i) {
	//             if(table.find(s[i]) == table.end())
	//                 return 0;
	//             if(i - 1 >= 0 && table[s[i]] > table[s[i - 1]]) {
	//                 res += table[s[i]] - tmp;
	//                 tmp = 0;
	//             }
	//             else if(i - 1 >= 0 && table[s[i]] < table[s[i - 1]]) {
	//                 res += tmp;
	//                 tmp = table[s[i]];
	//             }
	//             else
	//                 tmp += table[s[i]];
	//         }

	//         return res + tmp;

	// backward better
	int n = s.length();
	int res = table[s[n - 1]];

	for (int i = n - 2; i >= 0; --i) {
		if (table[s[i]] < table[s[i + 1]])
			res -= table[s[i]];
		else
			res += table[s[i]];
	}

	return res;
}