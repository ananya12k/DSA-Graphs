#include <iostream>
#include <queue>
using namespace std;
int vertArr[20][20] = {0}; // the adjacency matrix initially 0
int count = 0;
void displayMatrix(int v)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cout << vertArr[i][j] << " ";
        }
        cout << endl;
    }
}
void bfs(int v1,int n)
{
    // visit[v1] = 1;
    queue<int> Q;
    // front = rear = -1;
    Q.push(v1) ;
    while (!Q.empty())
    {
        v1 = Q.front();
        cout << v1 << endl;
        for (int v2 = 0; v2 < n; v2++)
        {
            if (vertArr[v1][v2] == 1 && visit[v2] == 0)
            {
                Q.push(v2) ;
                visit[v2] = 1;
            }
        }
    }
}
int visit[2] = {0};
void dfs(int v1, int n)
{
    cout << v1 << endl;
    visit[v1] = 1;
    for (int v2 = 0; v2 < n; v2++)
    {
        if (vertArr[v1][v2] == 1 && visit[v2] == 0)
        {
            dfs(v2, n);
        }
    }
}
void add_edge(int u, int v)
{ // function to add edge into the matrix
    vertArr[u][v] = 1;
    vertArr[v][u] = 1;
}
int main()
{
    int v = 3; // there are  3 vertices in the graph
    add_edge(0, 1);
    add_edge(1, 0);
    add_edge(2, 1);
    add_edge(1, 2);
    displayMatrix(v);
    dfs(1, v);
    // bfs(1,v);
    return 0;
}