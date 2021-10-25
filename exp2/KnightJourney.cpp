//
// Created by Illyasviel on 2021/10/16.
//
#include <bits/stdc++.h>
#define N 4
using namespace std;

struct point {
    int y;
    int x;

    point() : x(-1), y(-1) {}
    point(int _y, int _x) : y(_y), x(_x) {}

    point operator+(const point& p1);

    void show() const;
};

void point::show() const {
    printf("Pos:( %d, %d )\n", y, x);
}

point point::operator+(const point& p1) {
    point tmp = *this;
    tmp.x += p1.x;
    tmp.y += p1.y;
    if (tmp.x < 0 || tmp.y < 0 || tmp.x >= N || tmp.y >= N) return {-1, -1};
    return tmp;
}

vector<vector<int> > a;
vector<int> v;
vector<point> r;

vector<point> d{
    point(-1, -2),
    point(-2, -1),
    point(-2, 1),
    point(-1, 2),
    point(1, 2),
    point(2, 1),
    point(1, -2),
    point(2, -1)};

void Init() {
    a.assign(N, vector<int>(N, 0));
}

bool canPlace(point p1) {
    if (p1.x == -1 || p1.y == -1)
        return false;
    else
        return !a[p1.y][p1.x];
}

point getNext(point p1, int l) {
    for (int i = 0; i < 8; ++i) {
        if (i == l) continue;
        if (canPlace(p1 + d[i])) {
            printf("%d\n", i);
            v.push_back(i);
            return p1 + d[i];
        }
    }
    return {-1, -1};
}

int main() {
    Init();
    point knight;
    printf("Enter knight position <y x>:");
    cin >> knight.y >> knight.x;
    int i, l;
    point next = knight;
    //    a[next.y][next.x] = 1;
    for (i = 1; i <= N * N;) {
        if (canPlace(next)) {
            next.show();
            a[next.y][next.x] = 1;
            r.push_back(next);
            l = -1;
            ++i;
        } else {
            if (i == 1 || v.empty() || r.empty()) {
                break;
            }
            // printf("Back: ");

            next = *r.rbegin();
            a[next.y][next.x] = 0;
            r.pop_back();
            next = *r.rbegin();
            // next.show();
            l = *v.rbegin();
            // printf("l: %d\n", l);
            v.pop_back();
            // i--;
        }
        next = getNext(next, l);
    }
    return 0;
}
