//
// Created by Illyasviel on 2021/10/6.
//
#include <bits/stdc++.h>
using namespace std;

class treeNode {
private:
    int depth = 1;
    int value{};
    vector<treeNode*> next;

public:
    treeNode() = default;
    explicit treeNode(int v) : value(v), next() {}
    treeNode(int v, treeNode* n) : value(v), next{n} {}

    void setValue(int v)  { value = v;    }
    int  getValue() const { return value; }

    void setDepth(int d)  { depth = d;    }
    int  getDepth() const { return depth; }

    void setNext(vector<treeNode*> n) { next = move(n); }
    auto getNext() const  { return next; }

    void connect(treeNode* n) { next.push_back(n); }
};

int n;
int head;
multimap<int, int> group;
treeNode* headNode;
treeNode* hdLoc;

bool isNext(treeNode* node) {
    for (auto i : node->getNext()) {
        if ( i->getValue()==head ) {
            return true;
        }
    }
    return false;
}

bool theSame(int x) {
    auto rec = group.equal_range(x);
    if ( rec.first!=group.end() ) {
        for ( auto it = rec.first; it != rec.second; it++) {
            if ( it->second == head ) {
                return true;
            }
        }
    }
    return false;
}

void dfsAns(treeNode* node, int step, set<int>& idx) {
    if ( step > 5 ) {
        return;
    }
    auto x = node->getValue();
    if ( idx.find(x)==idx.end() ) {
        if ( step == 4 && !theSame(x) && !isNext(node) ) {
            group.insert({head,x});
            hdLoc[head].connect(&hdLoc[x]);
            hdLoc[x].connect(&hdLoc[head]);
//            printf("step %d : ( %d, %d )\n", step, head, x);
        }
        idx.insert(x);
        for ( auto pNext : node->getNext() ) {
            dfsAns(pNext, step+1, idx);
        }
    }
}

int main() {
    cin >> n;
    auto* nodeList = new treeNode[n+1]{};
    hdLoc = &nodeList[0];
    for (int i = 1; i <= n; ++i) {
        nodeList[i].setValue(i);
    }
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        nodeList[a].connect(&nodeList[b]);
        nodeList[b].connect(&nodeList[a]);
    }
    for (int i = 1; i <= n ; ++i) {
        set<int> idx;
        head = i;
        headNode = &nodeList[i];
        dfsAns(headNode, 1, idx);
    }
    cout << group.size();
    return 0;
}

