//
// Created by Illyasviel on 2021/10/5.
//
#include <bits/stdc++.h>
using namespace std;

void operate1(string& a, vector<string>& stage, int t, int x, char y) {
    a = stage[t];
    a[x-1] = y;
    stage.push_back(a);
}

void operate2(string& a, vector<string>& stage, int t, int x) {
    a = stage[t];
    a.erase(x-1,1);
    stage.push_back(a);
}

int main() {
    int n, k;
    string a;
    cin >> n >> a >> k;
    vector<string> stage;
    stage.push_back(a);

    for (int i = 0; i < k; ++i) {
        int ope;
        cin >> ope;
        if ( ope == 1 ) {
            int t, x; char y;
            cin >> t >> x >> y;
//            printf("%d: %d %d %c\n", i, t, x, y);
            operate1(a, stage, t, x, y);
        } else if ( ope == 2 ) {
            int t, x;
            cin >> t >> x;
//            printf("%d: %d %d\n", i, t, x);
            operate2(a, stage, t, x);
        } else {
//            printf("%d: %d %c", i, ope, ope);
        }
    }

    multimap<string, int> ans;
    for (int i = 1; i < k+1; ++i) {
        ans.insert(make_pair(stage[i], i));
    }
    for ( const auto& i : ans ) {
        printf("%d ", i.second);
    }
    return 0;
}