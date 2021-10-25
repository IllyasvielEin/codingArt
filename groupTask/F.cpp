//
// Created by Illyasviel on 2021/10/5.
//
#include <bits/stdc++.h>
using namespace std;

struct worker {
    int left;
    int right;
    int tBegin;
    int tEnd;
    set<int> worked;
};

int getBegin(pair< int, pair<int, int> > p1) {
    return p1.first;
}

int getEnd(pair< int, pair<int, int> > p1) {
    return p1.second.second;
}

int getArea(pair< int, pair<int, int> > p1) {
    return p1.second.first;
}

int workingTime(int x, int y, int a, int b) {
    /* 1 2 2 2 */
    if ( b<x || a>y ) return 0;
    int begin = a<x?x:a;
    int end   = y>b?b:y;
    return end-begin+1;
}

void show(const int* num, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

bool full(const int* num, int n) {
    for (int i = 0; i < n; ++i) {
        if ( num[i]==0 ) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    multimap< int, pair<int, int> > road;
    for (int i = 0; i < N; ++i) {
        int area, begin, end;
        cin >> area >> begin >> end;
        road.insert(make_pair(begin, make_pair(area, end)));
    }
    int Q;
    cin >> Q;
    vector<worker> workVec;
    for (int i = 0; i < Q; ++i) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        workVec.push_back( worker{l,r,a,b} );
    }

    for ( auto wor : workVec ) {
        int fullHours = wor.tEnd-wor.tBegin+1;
        int *timing = new int[fullHours]{0};
        int idx = 0;
        pair<int, int> lastWorking{-1,-1};
        for ( auto roadSnip : road ) {
            if ( wor.worked.find(getArea(roadSnip))!=wor.worked.end() ) {
                continue;
            } else {
                wor.worked.insert(getArea(roadSnip));
                if ( getArea(roadSnip)>=wor.left && getArea(roadSnip)<=wor.right ) {
                    auto wktime = workingTime(getBegin(roadSnip), getEnd(roadSnip), wor.tBegin, wor.tEnd);
                    if ( wktime != 0 ) {
                        if ( lastWorking.first == -1 || getBegin(roadSnip)>=lastWorking.second ) {
                            lastWorking = make_pair(getBegin(roadSnip), getEnd(roadSnip));
                            for (auto i = 0; idx<fullHours&&i<wktime ; idx++, i++) {
                                timing[idx]=1;
                            }
//                            dfs_show(timing, fullHours);
                        }
                    }
                }
            }
        }
        if (full(timing,fullHours)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}

/*
4
3 1 2
5 2 3
5 3 3
2 4 5
1
3 5 1 5

 */