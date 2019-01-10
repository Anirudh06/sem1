#include <iostream>
#include<algorithm>
using namespace std;

int fun(int arr[],int n,int m){
    int table[m][n+1];

    for(int i=0;i<n+1;i++)
        table[0][i]=1;
    for(int i=0;i<m;i++)
        table[i][0]=1;
    int j,k;
    for(j=1;j<m;j++){
        for(k=1;k<n+1;k++){
            if(arr[j]>k)
                table[j][k]=table[j-1][k];
            else 
                table[j][k]=(table[j-1][k])+(table[j][k-arr[j]]);
        }
        
    }
    for(j=0;j<m;j++){
        for(k=0;k<n+1;k++){
            cout<<table[j][k];
        }
        cout<<endl;
    }
    return table[m-1][n];
}

int main() {
    int arr[3]={1,2,4};
    int n=5, m=3;
    cout<<fun(arr,n,m);
}

