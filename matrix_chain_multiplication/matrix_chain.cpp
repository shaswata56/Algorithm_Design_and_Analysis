#include <bits/stdc++.h>
using namespace std;

void parenthesis(int i, int j, int n, int *b, char &name)
{
    if(i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    parenthesis(i, *((b + j * n) + i), n, b, name);
    parenthesis(*((b + j * n) + i) + 1, j, n, b, name);
    cout << ")";
}

int minCost(int arr[], int n)
{
    int dp[n][n];
    for(int i = 1; i < n; i++)
        dp[i][i] = 0;
    for(int cl = 2; cl < n; cl++)
    {
        for(int i = 1; i < n - cl + 1; i++)
        {
            int j = i + cl - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++)
            {
                int val = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if(val < dp[i][j])
                {
                    dp[i][j] = val;
                    dp[j][i] = k;
                }
            }
        }
    }
    char name = 'A';
    cout << "Optimal Parenthesization: ";
    parenthesis(1, n - 1, n, (int *)dp, name);
    cout << endl;
    return dp[1][n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int min = minCost(arr, n);
    cout << "Minimum cost: " << min << endl;
}