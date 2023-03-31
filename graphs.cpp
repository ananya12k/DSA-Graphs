#include <iostream>
#include <queue>
using namespace std;
int g[4][4] = {{0, 1, 0, 1},
               {1, 0, 1, 0},
               {0, 1, 0, 1},
               {1, 0, 1, 0}};
int v[4] = {};
int n = 4;
void dfs(int i)
{
    cout << i << " ";
    v[i] = 1;
    for (int j = 0; j < n; j++)
    {
        if (g[i][j] == 1 && v[j] == 0)
        {
            dfs(j);
        }
    }
}
void bfs(int i)
{

    queue<int> q;
    cout << i << " ";
    q.push(i);

    v[i] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int j = 0; j < n; j++)
        {
            if (g[x][j] == 1 && v[j] == 0)
            {
                cout << j << " ";
                q.push(j);
                v[j] = 1;
            }
        }
    }
}

int main()
{
    cout << "dfs:";
    dfs(0);
    for (int i = 0; i < 4; i++)
    {
        v[i] = 0;
    }
    cout << endl
         << "bfs:";
    bfs(0);
    return 0;
}