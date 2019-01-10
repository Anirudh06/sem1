#include<bits/stdc++.h>
using namespace std;

int count( int S[], int m, int n ) 
{ 
    int table[n+1]; 
    table[0] = 1; 
    for(int i=1;i<n;i++)
        table[i]=0;

    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
    
    for(int i=0;i<n;i++)
        cout<<table[i]<<" " ;
  
    return table[n]; 
} 

int main() {
    int arr[3]={2,3,4};
    int n=7, m=3;
    cout<<count(arr,m,n);
}

