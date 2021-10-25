//
// Created by Illyasviel on 2021/10/3.
//
#include <bits/stdc++.h>
#include <map>
using namespace std;

void read(int *ans, int n) {
    int tmpNum;
    int bigNum;
    int location;
    vector<int> num;
    for (int i = 0; i < n; ++i) {
        bigNum = 0;
        for (int j = 0; j < n; ++j) {
            cin >> tmpNum;
            num.push_back(tmpNum);
            if ( tmpNum == 0 ) {
                location = j;
            } else if ( tmpNum == 1 ) {
                bigNum++;
            }
        }
        ans[location] = bigNum+1;
    }
}

void printAns(int *ans, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
}

int main() {
    int n;
    cin >> n;
    int* ans = new int[n];
    read(ans, n);
    printAns(ans, n);
    return 0;
}

