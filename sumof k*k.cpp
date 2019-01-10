#include <iostream> 
using namespace std; 
#define n 5 
void printSumTricky(int mat[n][n], int k) { 
if (k > n) return;  
int stripSum[n][n]; 
 
for (int j=0; j<n; j++){  
	int sum = 0; 
	for (int i=0; i<k; i++) 
		sum += mat[i][j]; 
	stripSum[0][j] = sum; 

	for (int i=1; i<n-k+1; i++){ 
			sum += (mat[i+k-1][j] - mat[i-1][j]); 
			stripSum[i][j] = sum; 
	} 
} 

for (int i=0; i<n-k+1; i++){ 
	int sum = 0; 
	for (int j = 0; j<k; j++) 
		sum += stripSum[i][j]; 
	cout << sum << " "; 
 
	for (int j=1; j<n-k+1; j++){ 
		sum += (stripSum[i][j+k-1] - stripSum[i][j-1]); 
		cout << sum << " "; 
	} 
	cout << endl; 
    } 
} 

int main(){ 
	int mat[n][n] = {{1, 1, 1, 1, 1}, 
					{2, 2, 2, 2, 2}, 
					{3, 3, 3, 3, 3}, 
					{4, 4, 4, 4, 4}, 
					{5, 5, 5, 5, 5}, 
					}; 
	int k = 3; 
	printSumTricky(mat, k); 
	return 0; 
} 

