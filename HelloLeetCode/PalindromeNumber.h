#pragma once

bool isPalindrome(int x) {
	if (x<0 || // neg is not
		(x != 0 && x % 10 == 0)) // !!! 10, 21120 is not but 0 is
		return false;

	int sum = 0;
	while (x>sum) { // convert only half
		sum = sum * 10 + x % 10;
		x = x / 10;
	}
	return (x == sum) || (x == sum / 10);
}