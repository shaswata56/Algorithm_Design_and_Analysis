#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int row[MAX], col[MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];

int f(int beg, int end)
{
	if(beg >= end)
		return 0;
	if(visited[beg][end])
		return dp[beg][end];
	int res = 1 << 30;
	for(int mid = beg; mid < end; mid++)
	{
		int left_op = f(beg, mid);
		int right_op = f(mid + 1, end);
		int lr_op = row[beg] * col[mid] * col[end];
		int sum = left_op + right_op + lr_op;
		res = min(res, sum);
	}
	visited[beg][end] = 1;
	dp[beg][end] = res;
	return res;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> row[i] >> col[i];
	}
	cout << f(0, n - 1) << endl;
}
