#include<bits/stdc++.h>
#define MAX 127
using namespace std;
int n;
struct wall {
    double x, y[5];
}w[22];
double e[101][101];

//解析法求撞墙
bool crash(int w1, int w2, int w1y, int w2y) {
    if(w1 + 1 == w2) return true;
    double x1=w[w1].x;
    double x2=w[w2].x;
    double y1=w[w1].y[w1y];
    double y2=w[w2].y[w2y];
    double k = (y1-y2)/(x1-x2);
    double t = y1-x1*k;
    for (int i= w1 + 1; i < w2; i++) {
        double ty = k * w[i].x + t;
        if (ty < w[i].y[1] || ty > w[i].y[2] && ty < w[i].y[3] || ty > w[i].y[4])
            return false;
    }
    return true;
}

void addEdge(int a, int b, int w1y, int w2y) {
    if (!crash(a, b, w1y, w2y)) return; //撞墙则不连接
    double x1=w[a].x;
    double x2=w[b].x;
    double y1=w[a].y[w1y];
    double y2=w[b].y[w2y];
    e[a*4+w1y][b*4+w2y] = e[b*4+w2y][a*4+w1y] = sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

void Init() {
    cin>>n;
    memset(e,MAX,sizeof(e));
    for (int i=1;i<=n;i++)
    {
        cin>>w[i].x;
        for (int j=1;j<5;j++)
            cin>>w[i].y[j];
    }
    //起点终点设置
    w[0].x=0;
    w[n+1].x=10;
    n++; //n置为终点墙 x下标
    for (int i=1;i<5;i++) //起点终点端点特殊处理
        w[0].y[i]=w[n].y[i]=5;

    for (int i=0;i<n;i++) //循环建边
        for (int j=i+1;j<=n;j++)
            for (int k=1;k<5;k++)
                for (int l=1;l<5;l++)
                    addEdge(i,j,k,l);

    for (int i=0;i<101;i++) //对角线路径长度处理
        e[i][i]=0;
}

int main()
{
    Init();
    //floyd
    for (int k=1;k<=n*4+4;k++)
        for (int i=1;i<=n*4+4;i++)
            for (int j=1;j<=n*4+4;j++)
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
    printf("%f\n",e[1][n*4+1]);
    return 0;
}


