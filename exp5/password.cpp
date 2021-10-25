//
// Created by Illyasviel on 2021/10/25.
//
#include <bits/stdc++.h>
using namespace std;
string s;
string *g;

int e;

void ts() {
    char c;
    g[0] = s;
    for (int i = 1; i<e ; i++) {
        c = s[0];
        s.erase(s.begin());
        s.push_back(c);
        g[i] = s;
    }
}

int findidx(const string &str, char c) {
    for (int i = int(str.size()) - 1; i >= 0; i--) {
        if (str[i]==c) return i;
    }
}

string* scan(const string& str, int* idx) {
    char c = s[0];

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < str.size(); j++) {
            if ( str[j]==s[i] ) c = str[j];

        }
    }
}

int main() {
    while ( true ) {
        int t;
        cin >> t;
        if ( t == -1 ) break;
        if ( t == 1 ) {
            cin >> s;
            e = int(s.length());
            g = new string[s.size()];
            ts();
            sort(&g[0], &g[0]+s.size(), [&](const string &a, const string &b) {
                return a[0]<b[0];
            });
            string ans;
            for (int i = 0; i < e; ++i) {
                ans += *g[i].rbegin();
                //        cout << g[i] << "\n";
            }
            printf("encrypted: %s.\n", ans.c_str());
        }
        else {
            cin >> s;
            string ms = s;
            sort(ms.begin(), ms.end());
//            cout << ms;
            int* idx = new int[s.size()]{0};
            scan(ms, idx);
        }
    }

    return 0;
}
