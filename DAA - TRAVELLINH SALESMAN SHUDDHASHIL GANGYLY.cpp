#include <bits/stdc++.h>
using namespace std;
#define val 4

int trav(int gra[][val], int s)
{
    vector<int> ver;
    for (int i = 0; i < val; i++)
        if (i != s)
            ver.push_back(i);
    int min_path = INT_MAX;
    
    do
    {
        int cur_pweight = 0;
        int k = s;
        for (int i = 0; i < ver.size(); i++)
        {
            cur_pweight += gra[k][ver[i]];
            k = ver[i];
        }
        cur_pweight += gra[k][s];
        min_path = min(min_path, cur_pweight);

    }
    while (next_permutation(ver.begin(), ver.end()));
    return min_path;
}

int main()
{
    int gra[][val] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    cout << "Travelling Sales Person problem: " << trav(gra, s) << endl;
    return 0;
}
