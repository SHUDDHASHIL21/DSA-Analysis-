#include <bits/stdc++.h>
using namespace std;
class D
{
    int *pare;
    int *rank;

public:
    D(int n)
    {
        pare = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            pare[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (pare[i] == -1)
            return i;

        return pare[i] = find(pare[i]);
    }

    void combine(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
                pare[s1] = s2;

            else if (rank[s1] > rank[s2])
                pare[s2] = s1;

            else
            {
                pare[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class graph
{
    vector<vector<int> > list;
    int V;

public:
    graph(int V) { this->V = V; }

    void addEdge(int x, int y, int w)
    {
        list.push_back ({w, x, y});
    }

    void kruskals()
    {
        sort(list.begin(), list.end());
        D s(V);
        int answer = 0;
        cout << "Following are the edges in the constructed MST" << endl;
        for (auto edge : list)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if (s.find(x) != s.find(y))
            {
                s.combine(x, y);
                answer += w;
                cout << x << " -- " << y << " == " << w
                     << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree using Krushkal's algorithm: " << answer;
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    g.kruskals();
    return 0;
}
