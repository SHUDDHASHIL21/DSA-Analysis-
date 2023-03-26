#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int start,int end)
{
    
    int pivot=arr[rand()%(end-start)+start];
    
    int up=end;
    int down=start;
    while(up>down)
    {
        while(arr[up]>pivot)
        {
            up--;
        }
        while(arr[down]<pivot)
        {
            down++;
        }
        if(up>down) swap(arr[up],arr[down]);
    }
  
    return up;
}
void quicksort(int arr[],int start, int end, int n)
{
   // cout<<"kkkk"<<endl;
    if (start >= end) return; 
   
    int p=partition(arr,start,end);
  //   cout<<start<<" "<<p<<" "<<end<<endl;
    quicksort(arr,start,p-1,n);
    quicksort(arr,p+1,end,n);
}

int main()
{
   // cout<<"kkk"<<endl;
    int arr[] = {7,8,9,2,1};
    quicksort(arr,0,4,5);
    for(int i=0;i<5;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
