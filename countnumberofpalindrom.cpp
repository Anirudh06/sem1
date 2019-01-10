#include <bits/stdc++.h>
using namespace std;
int count(char* S,char*P,int n,int m){
    int count =0,sum=0;
    int arr[26];
    for(int i=0;i<26;i++)
        arr[i]=0;
    for(int i=0;i<n;i++)
        arr[S[i]-'A']++;

    for(int i=0;i<26;i++)
        sum=sum+arr[i];
    int p=n/m;
    for(int j=1;j<=p;j++){
        int sum1=0;
        for(int i=0;i<26;i++)
            cout<<arr[i]<<" ";
            cout<<endl;
        for(int k=0;k<m;k++)
        {
            if(arr[P[k]-'A'])
            arr[P[k]-'A']--;  
        }
        

        for(int i=0;i<26;i++)
            sum1=sum1+arr[i];
        if(sum1==sum-(j*m))
            count++;
    }

return count;
}
int main() {
    char S[] = "CACCBCA"; 
    int n = strlen(S); 

    sort(S,S+n);
    for(int i=0;i<n;i++)
            cout<<S[i]<<" ";
            cout<<endl;
    char P[] = "CAC"; 
    int m = strlen(P); 
    sort(P,P+m);
    for(int i=0;i<m;i++)
            cout<<P[i]<<" ";
            cout<<endl;
    cout<<count(S,P,n,m);
}
