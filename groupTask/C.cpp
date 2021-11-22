//
// Created by Illyasviel on 2021/10/4.
//
#include <bits/stdc++.h>
using namespace std;

long num[1001];
int pre[1001];
int Rank[1001];

void init(int n) {
    for(int i = 0; i < n; i++){
        pre[i] = i;
        Rank[i] = 1;
    }
}

int find(int x) {
    if(pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}

bool isSame(int x, int y) {
    return find(x) == find(y);
}

bool join(int x,int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(Rank[x] > Rank[y]) pre[y]=x;
    else {
        if(Rank[x]==Rank[y]) Rank[y]++;
        pre[x]=y;
    }
    return true;
}

int main() {
    int n;
    map<int, int> ans;
    cin >> n;
    init(n);
    for (int i = 0; i < n; ++i) {
        cin>>num[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; ++j)
            if(num[i]>num[j]) {
                join(i,j);
            }
    for (int i = 0; i < n; ++i) {
        if( ans.find(pre[i])==ans.end() ) ans[pre[i]]=1;
        else ans[pre[i]]++;
    }
    printf("%d", ans.begin()->second);
    return 0;
}
