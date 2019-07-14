/*
 *	Implementing division method of Hashing
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int base = 26, cnt = 1;
	string str, a;
	cin >> str;
	stringstream ss(str);
	long long mod_1 = 1000000 + 3, mod_2 = 989898;
	vector <pair <long long, long long>> v;
	while(ss >> a)
	{
		long long sum_1 = 0, sum_2 = 0;
		for(auto x : a)
		{
			sum_1 += (sum_1 * base + x) % mod_1;
			sum_1 %= mod_1;

			sum_2 += (sum_2 * base + x) % mod_2;
			sum_2 %= mod_2;
		}
		v.push_back({sum_1, sum_2});
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < v.size(); i++)
		if(v[i] != v[i - 1])
			cnt++;
	cout << cnt << endl;
}
