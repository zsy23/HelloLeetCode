#include "Util/Util.h"
#include "ThreeSumClosest.h"

#include <iostream>

int main(int argc, char *arg[]) {
	int tmp[] = { -1,0,1,2,-1,-4 };
	std::vector<int> ttt(tmp, tmp + 6);

	threeSumClosest(ttt, 1);

	system("pause");

	return 0;
}