//
// Created by Illyasviel on 2021/10/25.
//
#include <bits/stdc++.h>
using namespace std;

int **a;
int **b;
int **idx;
int x, y;
int EDGE_X, EDGE_Y;
void Init() {
    a = new int*[3];
    for (int i = 0; i < 3; ++i) {
        a[i] = new int[6];
    }
    ifstream is("../exp5/map1.in");
    char c;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            is >> c;
            if (c=='W') a[i][j] = 1;
            else if (c=='E') a[i][j] = 2;
            else if (c=='N') a[i][j] = 3;
            else if (c=='S') a[i][j] = 4;
            else printf("None\n");
        }
    }

    b = new int*[4];
    for (int i = 0; i < 4; ++i) {
        b[i] = new int[5];
    }
    is.close();
    is.open("../exp5/map2.in", ios::in);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            is >> c;
            if (c=='W') b[i][j] = 1;
            else if (c=='E') b[i][j] = 2;
            else if (c=='N') b[i][j] = 3;
            else if (c=='S') b[i][j] = 4;
            else printf("None\n");
        }
    }
}

void idxInit() {
    idx = new int*[EDGE_Y];
    for (int i = 0; i < EDGE_Y; ++i) {
        idx[i] = new int[EDGE_X]{0};
    }
}

void show(int t) {
    char c;
    if ( t == 1 ) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 6; ++j) {
                if      ( a[i][j] == 1 ) c = 'W';
                else if ( a[i][j] == 2 ) c = 'E';
                else if ( a[i][j] == 3 ) c = 'N';
                else if ( a[i][j] == 4 ) c = 'S';
                cout << c << " ";
            }
            printf("\n");
        }
    }
    else {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 5; ++j) {
                if      ( b[i][j] == 1 ) c = 'W';
                else if ( b[i][j] == 2 ) c = 'E';
                else if ( b[i][j] == 3 ) c = 'N';
                else if ( b[i][j] == 4 ) c = 'S';
                cout << c << " ";
            }
            printf("\n");
        }
    }
}

void mapGo(int t) {

    if ( t == 1 ) {
        EDGE_X = 6;
        EDGE_Y = 3;
        idxInit();
        show(t);
        printf("\n");
        printf("go map%d:\n", t);
        do {
            if ( !idx[y][x] ) {
                printf("[%d, %d]->", x+1, y+1);
                idx[y][x] = 1;
                if      (a[y][x]==1) x--;
                else if (a[y][x]==2) x++;
                else if (a[y][x]==3) y--;
                else if (a[y][x]==4) y++;
            }
            else break;
        } while(x>=0&&x<EDGE_X&&y>=0&&y<EDGE_Y);
        printf("end");
    }
    else {
        EDGE_X = 5;
        EDGE_Y = 4;
        idxInit();
        show(t);
        printf("\n");
        printf("go map%d:\n", t);
        do {
            if ( !idx[y][x] ) {
                printf("[%d, %d]->", x+1, y+1);
                idx[y][x] = 1;
                if      (b[y][x]==1) x--;
                else if (b[y][x]==2) x++;
                else if (b[y][x]==3) y--;
                else if (b[y][x]==4) y++;
            }
            else break;
        } while(x>=0&&x<EDGE_X&&y>=0&&y<EDGE_Y);
        printf("end");
    }
}

int main() {
    Init();
    //    show(1);
    //    show(2);
    int t;
    cin >> x >> y;
    x--; y--;
    cin >> t;
    mapGo(t);
    return 0;
}
