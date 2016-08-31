#include <algorithm>
#include <cmath>
#include <cstdlib>//atof/atoi/atol/atoll/strtod/strtof/..., srand/rand, calloc/malloc, exit, qsort, abs
#include <iomanip>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define PRIME 1000000007

using namespace std;

int ipow(int base, int exp);
int left(int current, bool swap);
int right(int current, bool swap);


int xc,yc,r,xneg,yneg,xpos,ypos;

int main(void){
	int a, b, c, n;
	cin >> a >> b >> c;
	cout << (a > b ? c/b : c/a) << endl;
	return 0;
}


int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

int left(int current, bool swap){
	if(swap == 1){
		return right(current, false);
	} else if (swap == 0){
		return 2*current + 1;
	} else {
		std::cout << "Swap incorrect on left" << std::endl;
		exit(-1);
	}
}

int right(int current, bool swap){
	if(swap){
		return left(current, true);
	} else {
		return 2*(current+1);
	}
}
