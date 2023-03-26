#include<iostream>
#include<iomanip>
#define Val 7
#define INF 999
using namespace std;

int mat[Val][Val] = {
   {0, 3, 6, INF, INF, INF, INF},
   {3, 0, 2, 1, INF, INF, INF},
   {6, 2, 0, 1, 4, 2, INF},
   {INF, 1, 1, 0, 2, INF, 4},
   {INF, INF, 4, 2, 0, 2, 1},
   {INF, INF, 2, INF, 2, 0, 1},
   {INF, INF, INF, 4, 1, 1, 0}
};
void floyd(){
   int price[Val][Val];
   for(int i = 0; i<Val; i++)
      for(int j = 0; j<Val; j++)
         price[i][j] = mat[i][j];
         for(int k = 0; k<Val; k++){
            for(int i = 0; i<Val; i++)
               for(int j = 0; j<Val; j++)
                  if(price[i][k]+price[k][j] < price[i][j])
                     price[i][j] = price[i][k]+price[k][j];
   }
   cout << "Matrix:" << endl;
   for(int i = 0; i<Val; i++){
      for(int j = 0; j<Val; j++)
         cout << setw(3) << price[i][j];
      cout << endl;
   }
}

int main(){
   floyd();
}
