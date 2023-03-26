#include <bits/stdc++.h>
using namespace std;
#define val 5

int minEle(int ele[], bool set[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < val; v++)
        if (set[v] == false && ele[v] < min)
            min = ele[v], min_index = v;
    return min_index;
}

void output(int pare[], int graph[val][val])
{
    cout << " Edge \t      Weight\n";
    for (int i = 1; i < val; i++)
        cout << pare[i] << " - " << i << " \t\t"
             << graph[i][pare[i]] << " \n";
}

void prim(int graph[val][val])
{
    int pare[val];
    int ele[val];
    bool set[val];

    for (int i = 0; i < val; i++)
        ele[i] = INT_MAX, set[i] = false;
    ele[0] = 0;
    pare[0] = -1;
    for (int count = 0; count < val - 1; count++)
    {
        int u = minEle(ele, set);
        set[u] = true;
        for (int v = 0; v < val; v++)
            if (graph[u][v] && set[v] == false && graph[u][v] < ele[v])
                pare[v] = u, ele[v] = graph[u][v];
    }
    output(pare, graph);
}

int main()
{
    int graph[val][val] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    prim(graph);
    return 0;
}
