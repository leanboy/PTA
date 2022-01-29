#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int n, m, c1, c2;
    // dis[i]为到i的最短路径长度，num[i]为最短路径的条数，w[i]为救援队数目之和
    int e[500][500], weight[500], dis[500], num[500], w[500]; 
    bool visit[500]; // 默认全为false
    const int inf = INT_MAX;
    cin >> n >> m >> c1 >> c2;
    for(int i = 0; i < n; i++)
        cin >> weight[i];
    fill(e[0], e[0] + 500 * 500, inf); // e[0]为指向二维数组第一行第一个元素的指针
    fill(dis, dis + 500, inf);
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0; // 到自身的距离
    w[c1] = weight[c1];
    num[c1] = 1;
    for(int i = 0; i < n; i++) { // 遍历n个点
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) 
            if(visit[j] == false && dis[j] < minn) { // 首先成立的是j == c1
                u = j;
                minn = dis[j]; // 每轮选取未加入到集合中且dis最小的点
            }
        if(u == -1) break; // 能到达的点都访问过了就跳出
        visit[u] = true; // 将其加入已确定dis的集合中
        for(int v = 0; v < n; v++) // 计算从刚加入到集合中的点到其他点的距离，是否更新dis
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u]; // 最短路径条数更新
                    w[v] = w[u] + weight[v];
                } else if(dis[u] + e[u][v] == dis[v]) {
                    num[v] += num[u]; // 条数增加
                    if(w[u] + weight[v] > w[v]) // 判断是否更新救援队数目
                        w[v] = w[u] + weight[v];
                }
            }
    }
    cout << num[c2] << " " << w[c2];
    return 0;
}