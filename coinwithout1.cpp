#include<bits/stdc++.h>
using namespace std;

int fun(int arr[],int m,int n){
    int table[n+1];
    table[0]=0;
    for(int i=1;i<n+1;i++)
        table[i]=INT_MAX;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++)
            if(arr[j]<=i){
                int res=table[i-arr[j]];
                if(res!=INT_MAX && res+1<table[i])
                    table[i]=res+1;
            }
        }
    return table[n];
}

int main() {
    int arr[3]={2,3,4};
    int n=5, m=3;
    cout<<fun(arr,m,n);
}

