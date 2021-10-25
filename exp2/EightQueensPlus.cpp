//
// Created by Illyasviel on 2021/10/14.
//
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
using board = vector< vector<int> >;

int n;
board a;
vector<int> column;
vector<int> lDia;
vector<int> rDia;
vector<int> last;

void Init() {
    a.assign(n, vector<int>(n, 0));
    column.assign(n, 0);
    lDia.assign(2*n, 0);
    rDia.assign(2*n, 0);
}

bool canPlace(int y, int x) {
    if ( column[x] || lDia[n-(y-x)-1] || rDia[x+y] ) {
        return false;
    } else {
        return true;
    }
}

int check(int y, int nex = 0) {
    for (int x = nex; x < n; ++x)
        if (canPlace(y, x)) return x;
    return -1;
}

void step(int &y, int x) {
    last.push_back(x);
    a[y][x]   = 1;
    column[x] = 1;
    lDia[n-(y-x)-1] = 1;
    rDia[x+y] = 1;
    y++;
}

void back(int &y, int &nex) {
    nex = last[y-1]+1;
    a[y-1][last[y-1]] = 0;
    column[last[y-1]] = 0;
    lDia[n-(y-1-last[y-1])-1] = 0;
    rDia[last[y-1]+y-1] = 0;
    last.pop_back();
    column.pop_back();
    y--;
}

int main() {
    int ans = 0;
    cin >> n;
    int nex = 0, y;
    Init();
    auto begin = clock();
    for ( y = 0; y < n; ) {
        auto x = check(y, nex);
        if ( x != -1 ) {
            nex = 0;
            if ( y == n-1 ) {
                ans++;
                nex = x+1;
            } else {
                step(y, x);
            }
        } else {
            if (y == 0) {
                break;
            }
            back(y, nex);
        }
    }
    auto end = clock();
    printf("cost time: %ld ms\n", (end-begin) );
    cout << ans;
}