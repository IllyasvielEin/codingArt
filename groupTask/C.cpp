//
// Created by Illyasviel on 2021/10/4.
//
#include <bits/stdc++.h>
using namespace std;

class graphNode {
private:
    int pos{};
    int value{-1};
    int cnt{-1};
    vector<graphNode> conList;

public:
    graphNode() = default;

    void setValue(int v) {
        value = v;
    }

    void setCnt(int _cnt) {
        cnt = _cnt;
    }

    void setPos(int p) {
        pos = p;
    }

    int getvalue() const {
        return value;
    }

    int getCnt() const {
        return cnt;
    }

    int getPos() const {
        return pos;
    }

    void connect(const graphNode& gp2) {
        cnt++;
        conList.push_back(gp2);
    }

    vector<graphNode> getConnections() {
        return conList;
    }

    bool more(const graphNode& gp2) const {
        return value > gp2.value;
    }


};

int main() {
    int n, tmpNum;
    cin >> n;
    auto* array = new graphNode[n];
    for (int i = 0; i < n; ++i) {
        cin >> tmpNum;
        array[i].setValue(tmpNum);
        array[i].setCnt(0);
        array[i].setPos(i);
    }

    for ( int i = 0; i < n; ++i ) {
        for (int j = i+1; j < n; ++j) {
            if ( array[i].more(array[j]) ) {
                array[i].connect(array[j]);
                array[j].connect(array[i]);
            }
        }
    }

    int max = array[0].getCnt(), location = 0;
    for (int i = 1; i < n; ++i) {
        if ( array[i].getCnt()>max ) {
            location = i;
            max = array[i].getCnt();
        }
    }

    int *idx = new int[n]{0};
    idx[location] = 1;
    int ans = 1;
    stack<graphNode> st;
    st.push(array[location]);
    do {
        auto tmp = st.top();
        st.pop();
        for (int i = 0; i < tmp.getCnt(); ++i) {
            if ( !idx[tmp.getConnections()[i].getPos()] ) {
                st.push(tmp.getConnections()[i]);
                idx[tmp.getConnections()[i].getPos()] = 1;
                ans++;
            }
        }
    } while ( !st.empty() );

    printf("%d", ans);
    return 0;
}
