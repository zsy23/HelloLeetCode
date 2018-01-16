#pragma once

#include <limits>

int reverseInteger(int x) {
	int neg = x < 0 ? -1 : 1;
	int res = 0;

	x *= neg;
	while (x > 0) {
		if (INT_MAX / 10 < res || INT_MAX - x % 10 < res * 10) // !!!
			return 0;
		res = res * 10 + x % 10;
		x /= 10;
	}

	return res * neg;
}

//int reverse(int x)
//{
//	int result = 0;
//
//	while (x != 0)
//	{
//		int tail = x % 10;
//		int newResult = result * 10 + tail;
//		if ((newResult - tail) / 10 != result) // !!!
//		{
//			return 0;
//		}
//		result = newResult;
//		x = x / 10;
//	}
//
//	return result;
//}
