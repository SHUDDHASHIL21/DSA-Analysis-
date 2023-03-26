#include <bits/stdc++.h>
using namespace std;

bool cycle;
bool isSafe(int v, int G[][6], vector<int> path, int pos)
{
    if (G[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

void Find_Ham(int G[][6], int pos, vector<int> path, bool visited[], int N)
{
    if (pos == N)
    {
        if (G[path[path.size() - 1]][path[0]] != 0)
        {
            path.push_back(0);
            for (int i = 0; i < path.size(); i++)
                cout << path[i] << " ";

            cout << endl;
            path.pop_back();
            cycle = true;
        }
        return;
    }

    for (int v = 0; v < N; v++)
    {
        if (isSafe(v, G, path, pos) && !visited[v])
        {
            path.push_back(v);
            visited[v] = true;
            Find_Ham(G, pos + 1, path, visited, N);
            visited[v] = false;
            path.pop_back();
        }
    }
}

void ham(int G[][6], int N)
{
    cycle = false;
    vector<int> path;
    path.push_back(0);
    bool visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    visited[0] = true;
    Find_Ham(G, 1, path, visited, N);
    if (!cycle)
    {
        cout << "Hamiltonian Cycle not possible " << endl;
        return;
    }
}

int main()
{
    int G[][6] = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {1, 1, 0, 0, 1, 0},
    };

    ham(G, 6);
    return 0;
}
