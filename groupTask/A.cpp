#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &v1) {
    auto ans = (v1[0] + 2*v1[1] + 3*v1[2]) / 7;
    return ans;
}

void read(vector<int> &ans) {
    int groups;
    cin >> groups;
    for (int i = 1; i <= groups; ++i) {
        vector<int> line;
        int tmpNum = 0;
        cin >> tmpNum;
        for (int j = 0; j < 3; ++j) {
            if ( cin.good() ) {
                cin >> tmpNum;
            }
            line.push_back(tmpNum);
        }
        auto ians = func(line);
        ans.push_back( ians );
    }
}

void printAns(const vector<int>& ans) {
    for ( auto a : ans ) {
        printf("%d\n", a);
    }
}

int main_A() {
    vector<int> ans;
    read(ans);
    printAns(ans);
    return 0;
}

/*
 * 7 0 0
 * 5 1 0
 * 4 0 1
 * 3 2 0
 * 2 1 1
 * 1 3 0
 * 1 0 2
 * 0 2 1
 * */