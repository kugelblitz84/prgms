#include <iostream>

using namespace std;

int main(){
   int n;
   cin>>n;
   int adj_matrix[n][n];
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cin>>adj_matrix[i][j];
      }
   }

   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         for(int k=0;k<n;k++){
            if(adj_matrix[i][k]+adj_matrix[k][j]<adj_matrix[i][j]){
               adj_matrix[i][j]=adj_matrix[i][k]+adj_matrix[k][j];
            }
         }
      }
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cout<<adj_matrix[i][j]<<" ";
      }
      cout<<endl;
   }
   return 0;
}