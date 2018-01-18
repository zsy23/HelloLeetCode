#pragma once

#include <string>

std::string intToRoman(int num) {
	std::string ge[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	std::string shi[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	std::string bai[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	std::string qian[] = { "", "M", "MM", "MMM" };

	return qian[num / 1000 % 10] + bai[num / 100 % 10] + shi[num / 10 % 10] + ge[num % 10];
}