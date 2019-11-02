#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 4;
    int p[4] = {1, 2, 3, 4};
    int j, min, q;
    int M[4][4], S[4][4];
    memset(M, 0, sizeof(M));
    memset(S, 0, sizeof(S));
    for (int d = 1; d < n-1; ++d) {
        for (int i = 1; i < n-d; ++i) {
            j = i + d;
            min = 32767;
            for (int k = i; k <= j-1; ++k) {
                q = M[i][k] + M[k+1][j] + (p[i-1] * p[k] * p[j]);
                if (q < min) {
                    min = q;
                    S[i][j] = k;
                }
            }
            M[i][j] = min;
        }
    }
    printf("%d\n", M[1][n-1]);
}
