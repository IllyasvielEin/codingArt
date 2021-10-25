//
// Created by Illyasviel on 2021/10/25.
//
#include <bits/stdc++.h>
using namespace std;
string s;
string *g;

int e;

void ts(string& str) {
    char c;
    g[0] = str;
    for (int i = 1; i<e ; i++) {
        c = str[0];
        str.erase(str.begin());
        str.push_back(c);
        g[i] = str;
    }
}

int findidx(const string &str, char c) {
    for (int i = int(str.size()) - 1; i >= 0; i--) {
        if (str[i]==c) return i;
    }
    return -1;
}

string scan(const string& str) {
    string ans;
    ans+=s[0];
    char c = str[0];
    ans+=c;
    int i;
    do {
        i = findidx(s, c);
        c = str[i];
        ans+=c;
    } while(ans.size()<e);
    return ans;
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
            ts(s);
            sort(&g[0], &g[0]+s.size(), [&](const string &a, const string &b) {
                return a[0]<b[0];
            });
            string ans;
            for (int i = 0; i < e; ++i) {
                ans += *g[i].rbegin();
//                cout << g[i] << "\n";
            }
            printf("encrypted: %s.\n", ans.c_str());
        }
        else {
            cin >> s;
            e = int(s.size());
            string ms = s;
            sort(ms.begin(), ms.end());
//            cout << ms;
            auto ans = scan(ms);
            ts(ans);
            printf("Possible solution:\n");
            for (int i = 0; i<e ; ++i) {
                cout << g[i] << "\n";
            }
        }
    }

    return 0;
}
