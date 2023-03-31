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
int visit[2] = {0};
// Mark the node if visited
void bfs(int s,int n)
{
    queue<int> q;
    cout << s << " ";
    q.push(s);

    visit[s] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int j = 0; j < n; j++)
        {
            if (vertArr[x][j] == 1 && visit[j] == 0)
            {
                cout << j << " ";
                q.push(j);
                visit[j] = 1;
            }
        }
    }
}

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
    cout << "DFS Traversal" << endl;
    dfs(1, v);
    cout << "BFS Traversal" << endl;
    bfs(1, v);
    return 0;
}