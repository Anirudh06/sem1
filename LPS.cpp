#include <bits/stdc++.h>
#include<algorithm>

int lps(char *str,int n){
    int i, j, l; 
    int L[n][n];
    for(int k=0;k<n;k++){
        for(int m=0;m<n;m++){
            L[k][m]=0;
        }
    }
    for (i = 0; i < n; i++) 
      L[i][i] = 1; 
    
	for (l=1; l<n; l++){ 
           for (i=0; i<n-l; i++){ 
            j = i+l; 
             if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = std::max(L[i][j-1], L[i+1][j]); 
        } 
    } 
    std::cout<<std::endl;
    int m;
    for(int k=0;k<n;k++){
        for(m=0;m<n;m++){
            std::cout<<L[k][m]<<" ";
        }
        std::cout<<std::endl;
    }

    

    return L[0][m-1];
} 
 


int main(){ 
    char seq[] = "AMADAMA"; 
    int n = strlen(seq); 
    int c=lps(seq,n);
    std::cout<<"The lnegth of the LPS is %d"<<" "<< c;  
    return 0; 
}  
