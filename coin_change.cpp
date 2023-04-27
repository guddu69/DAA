#include <iostream>
using namespace std;
int count(int coins[], int n, int sum)
{
	if (sum == 0)
		return 1;
	if (sum < 0)
		return 0;
	if (n <= 0)
		return 0;
	
	return count(coins, n - 1, sum) + count(coins, n, sum - coins[n - 1]);
}
int main()
{
	int coins[] = { 2,5,3,6};
	int sum = 10;
	int n = sizeof(coins) / sizeof(coins[0]);
	cout << " " << count(coins, n, sum)<<endl;
	return 0;
}
