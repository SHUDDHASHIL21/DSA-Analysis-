#include <bits/stdc++.h>
using namespace std;
int main()
{
   
    int n;
    cin>>n;

    vector<int> h(n);


    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }

    int i =0,j = h.size()-1;

    int area = 0;
    while(i<j)
    {
        area = max(area,(j-i)*min(h[i],h[j]));
        cout<<i<<" "<<j<<" "<<min(h[i],h[j])<<" "<<area<<endl;

        if(h[i]<h[j])
        {
            i++;
        }
        else j--;
    }


    cout<<area<<endl;
    return 0;
}
