#include <bits/stdc++.h>
using namespace std;
#define N 1001
int dp[N][N];
string s1, s2;
int a, b;
void Init() {
    cin >> s1 >> s2;
    a = int(s1.size());
    b = int(s2.size());
}

int min3(int i, int j, int k) {
    int min = i;
    if ( j<min ) min = j;
    if ( k<min ) min = k;
    return min;
}

void dpMin() {
    int i, j;
    for (i = 0; i < a; ++i) {
        dp[i][0] = i;
    }
    for (j = 0; j < b; ++j) {
        dp[0][j] = j;
    }
    for (i = 1; i < a; i++) {
        for ( j = 1; j < b; ++j) {
            if ( s1[i]==s2[j] ) dp[i][j]=dp[i-1][j-1];
            else dp[i][j] = min3(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1);
        }
    }
}
int main() {
    Init();
    dpMin();
    printf("min: %d\n", dp[a-1][b-1]);
    return 0;
}
