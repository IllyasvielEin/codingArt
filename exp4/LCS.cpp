#include<bits/stdc++.h>
#define N 1001
using namespace std;
string s1, s2;
int dp[N][N];

int main() {
    cin >> s1 >> s2;
    int a = int(s1.size());
    int b = int(s2.size());
    string dps[a+1][b+1];
    dp[0][0] = 0;
//    dps[0][0] = "null";
    int i, j;
    for (i = 0, j = 0; j < b; ++j) {
        dp[i][j+1]  = 0;
    }
    for (i = 0, j = 0; i < a; i++) {
        dp[i+1][j] = 0;
    }

    for (i = 1; i <= a; i++) {
        for (j = 1; j <= b; ++j) {
            if ( s1[i-1]==s2[j-1] ) {
                dp[i][j] = dp[i-1][j-1]+1;
                dps[i][j] = dps[i-1][j-1]+s1[i-1];
            }
            else {
                if ( dp[i-1][j] > dp[i][j-1] ) {
                    dp[i][j] = dp[i-1][j];
                    dps[i][j] = dps[i-1][j];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                    dps[i][j] = dps[i][j-1];
                }
            }
        }
    }
    printf("the longest common subsequence is %s, size is %d\n", dps[a][b].c_str(), dp[a-1][b-1]);
}
