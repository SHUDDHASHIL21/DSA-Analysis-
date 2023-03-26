#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> &a ,pair<int,int> &b) {return ((double)a.first/a.second)>((double)b.first/b.second);}
int main()
{
   int s,weight;
   cout<<"Enter the no. of items"<<endl;
   cin>>s;
   vector<pair<int,int > > vect(s);
   cout<<"Enter cost and corresponding weight"<<endl;
   for(int i=0;i<vect.size();i++) cin>>vect[i].first>>vect[i].second;
   cout<<"Enter available weight"<<endl;
   cin>>weight;
   int cost = 0;
   sort(vect.begin(),vect.end(),comp);
   int i;
   for(i=0;i<vect.size();i++)
   {
      if(weight>=vect[i].second)
      {
           cost+= vect[i].first;
           weight -= vect[i].second;
      }
      else break;  
   }
  if(i<s && weight>0)
  {
     cost += vect[i].first /vect[i].second * weight;
  } 
  cout<<cost<<endl;
   return 0;
}
