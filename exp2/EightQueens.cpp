//
// Created by Illyasviel on 2021/10/11.
//
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
using board = vector< vector<int> >;

int n;
board a;
vector<int> stage;

void Init() {
    a.resize(n * n);
    a.assign(n, vector<int>(n, 0));
}

void show() {
    printf("array:\n");
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            printf("%d ", a[y][x]);
        }
        printf("\n");
    }
}

bool canPlace(int y, int x) {
    if ( stage.empty() ) {
//        printf("empty\n");
        return true;
    } else {
        for (int sy = 0; sy < stage.size(); ++sy) {
            if ( x == stage[sy] || (abs(x-stage[sy])==abs(y-sy) )) {
                return false;
            }
        }
        return true;
    }
}

int check(int y, int nex = 0) {
    for (int x = nex; x < n; ++x)
        if (canPlace(y, x)) return x;
    return -1;
}

int main() {
    int ans = 0;
    cin >> n;
    int nex = 0, y;
    auto begin = clock();
    Init();
    for ( y = 0; y < n; ) {
        auto x = check(y, nex);
        if ( x != -1 ) {
            nex = 0;
            if ( y == n-1 ) {
                a[y][x] = 1;
//                show();
//                a[y][x] = 0;
                ans++;
                nex = x+1;
            } else {
                a[y][x] = 1;
                stage.push_back(x);
                y++;
            }
        } else {
            if (y == 0) {
                break;
            }
            nex = stage[y-1]+1;
            a[y-1][stage[y-1]] = 0;
            stage.pop_back();
            y--;
        }
//        show();
    }
    auto end = clock();
    printf("cost %ld s\n", (end-begin)/1000 );
    cout << ans;
}