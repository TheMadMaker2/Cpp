//Alice Houston
#include<iostream>
#include<vector>

using namespace std;

//choose(n,r) = n!/(r! (n-r)!) = 52! / (6! 46!)

double fact(int32_t n) {
	static vector<double> memo{1,1,2,6,24,120,720,5040,40320,362880,3628800};
	if (n < memo.size())
		return memo[n];
	for (uint32_t i = memo.size(); i <= n; i++) {
	if (memo.size() == memo.capacity())
		memo.reserve(memo.size()*1.50);
		memo.push_back(memo[i-1] * i);
	}
	return memo[n];
}

double choose(int n, int r) {
	static double memo[100][100] = {0};

	if (memo[n][r] != 0)
		return memo[n][r];
	
	memo[n][r]=fact(n)/(fact(n)*fact(n-r));
	return memo[n][r];
}

int main(){
	cout << fact(20) << '\n';
	cout << fact(170) << '\n';
	cout << fact(171) << '\n';
	cout << choose(52, 6) << '\n';
	
	return 0;
}