#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int fun(char arr1[], char arr2[],int m,int n){
    int table[m+1][n+1];
    for(int i=0;i<m+1;i++)
        table[0][i]=0;
    for(int i=0;i<n+1;i++)
        table[i][0]=0;

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(arr1[i]==arr2[j])
            table[i][j]=1+table[i-1][j-1];
            else 
            table[i][j]=std::max(table[i-1][j],table[i][j-1]);
        }
    }
     return table[m][n];
}

int main() {
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
    int m = strlen(X); 
    int n = strlen(Y); 
    //fun(X,Y,m,n);
    cout<<fun(X,Y,m,n);
    return 0;
}

