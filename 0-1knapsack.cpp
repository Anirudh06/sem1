#include <bits/stdc++.h>
#include<algorithm>
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, j; 
   int K[n+1][W+1]; 
   for (i = 0; i < n+1; i++) 
   { 
       for (j = 0; j < W+1; j++) 
       { 
           if (i==0 || j==0) 
               K[i][j] = 0; 
           else if (wt[i-1] <= j) 
                 K[i][j] =std:: max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]); 
           else
                 K[i][j] = K[i-1][j]; 
       } 
   } 
   for (i = 1; i < n+1; i++) 
   { 
       for (j = 0; j < W+1; j++){
           std::cout<<K[i][j];

       } 
       std::cout<<std::endl;
   }
   
  
   return K[n][W]; 
} 
int main(){ 
    int val[] = {1,4,5,7}; 
    int wt[] = {1,3,4,5}; 
    int  W = 7; 
    int n = sizeof(val)/sizeof(val[0]); 
    std:: cout<<knapSack(W, wt, val, n); 
    return 0; 
} 
