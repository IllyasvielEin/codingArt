#include <bits/stdc++.h>
#define N 8
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
    printf("Pos:( %d, %d ) ", y, x);
}

point point::operator+(const point& p1) {
    point tmp = *this;
    tmp.x += p1.x;
    tmp.y += p1.y;
    if (tmp.x < 0 || tmp.y < 0 || tmp.x >= N || tmp.y >= N) return {-1, -1};
    return tmp;
}

vector<vector<int>> a;
vector<vector<int>> v;
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
    v.assign(N * N - 1, vector<int>{});
}

bool canPlace(point p1) {
    if (p1.x == -1 || p1.y == -1)
        return false;
    else
        return !a[p1.y][p1.x];
}

point getNext(point p1, int i) {
    assert(i >= 0 && i < N * N);
    for (int f = 0; f < 8; ++f) {
        if (find(v[i].begin(), v[i].end(), f) != v[i].end()) continue;
        if (canPlace(p1 + d[f])) {
            v[i].push_back(f);
            return p1 + d[f];
        }
    }
    return {-1, -1};
}

int main() {
    Init();
    int i;
    point knight;
    printf("Enter knight position <y x>:");
    cin >> knight.y >> knight.x;
    point next = knight;
    auto begin = clock();
    for (i = 0; i <= N * N;) {
        if (canPlace(next)) {
            //            next.show();
            a[next.y][next.x] = 1;
            r.push_back(next);
            ++i;
            //            printf(" __%d\n", i);
            if ( i == N*N ) {
                printf("yes\n");
                for ( const auto& rp : r ) {
                    rp.show();
                }
                break;
            }
            if (!v[i].empty()) v[i].clear();
        } else {
            //            printf("Back: ");
            next = *r.rbegin();
            a[next.y][next.x] = 0;
            r.pop_back();
            if ( r.empty() ) {
                printf("No\n");
                break;
            }
            next = *r.rbegin();

            //            next.show();
            i--;
            //            printf(" __%d\n", i);
        }
        next = getNext(next, i - 1);
    }
    auto end = clock();
    printf("cost time: %ld s", (end-begin)/1000);
    return 0;
}
