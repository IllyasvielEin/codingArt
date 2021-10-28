#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;

    point(double _x, double _y) : x(_x), y(_y){}

    bool operator==(const point& p1) const;

    point operator-(const point& p1);

    double operator*(const point& p1) const;

    double operator^(const point& p1) const;
};

point point::operator-(const point &p1) {
    auto tmp = *this;
    tmp.x-=p1.x;
    tmp.y-=p1.y;
    return tmp;
}

double point::operator*(const point &p1) const {
    return x*p1.x + y*p1.y;
}

double point::operator^(const point &p1) const {
    double cp = x*p1.y-p1.x*y;
    return cp;
}

bool point::operator==(const point& p1) const {
    return (abs(x-p1.x)<0.001 && abs(y-p1.y)<0.001 );
}

bool recInter(point p1, point p2, point p3, point p4) {
    if ( p3==p1 || p4==p1 || p3==p2 || p4==p2 ) return true;
    auto miny1 = min(p1.y, p2.y);
    auto maxy1 = max(p1.y, p2.y);
    auto minx1 = min(p1.x, p2.x);
    auto maxx1 = max(p1.x, p2.x);
    auto miny2 = min(p3.y, p4.y);
    auto maxy2 = max(p3.y, p4.y);
    auto minx2 = min(p3.x, p4.x);
    auto maxx2 = max(p3.x, p4.x);
    return (maxy2>miny1 && maxy1>miny2 && maxx1>minx2 && minx1<maxx2) ||
    (maxy1>miny2 && maxy2>miny1 && maxx2>minx1 && minx2<maxx1);
}

double cross(point p1, point p2, point p3) {
    auto l1 = p1 - p3;
    auto l2 = p2 - p3;
    return l1^l2;
}

bool inters(point p1, point p2, point p3, point p4) {
    if ( recInter(p1, p2, p3, p4) ) {
        auto cp1 = cross(p1,p2,p3);
        auto cp2 = cross(p1,p2,p4);
        return cp1*cp2<=0;
    } else {
        return false;
    }
}

//int main() {
//    vector<point> v;
//    printf("enter 4 points <x y> :");
//    for (int i = 0; i < 4; ++i) {
//        int x, y;
//        cin >> x >> y;
//        v.emplace_back(x, y);
//    }
//    if (inters(v[0],v[1],v[2],v[3])) printf("yes\n");
//    else printf("no\n");
//
//    return 0;
//}