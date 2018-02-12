#include <iostream>
using namespace std;

void merge(int A[],int L[],int R[],int nl,int nr){
	int i = 0,j = 0,k = 0;
	while(i<nl&&j<nr){
		if(L[i]<R[j]){
			A[k] = L[i];
			k++;i++;
		}
		else {
			A[k] = R[j];
			k++;j++;
		}
	}
	while(i<nl){
		A[k] = L[i];
		k++;i++;
	}
	while(j<nr){
		A[k] = R[j];
		k++;j++;
	}	
}
void mergesort(int A[],int n){
	if(n<2) return;
	int L[100],R[100],mid = n/2;
	for(int i=0;i<mid;i++) L[i] = A[i];
	for(int i=mid;i<n;i++) R[i-mid] = A[i];
	mergesort(L,mid);
	mergesort(R,n-mid);
	merge(A,L,R,mid,n-mid);
}
void partition(int A[],int L[],int R[],int n){
	int i=0,j=0;
	for(int k=0;k<n;k++){
		if(k%2==0){
			L[i] = A[k];
			i++;
		}
		else{
			R[j] = A[k];
			j++;
		}
	}
	int nl = i, nr = j;
	mergesort(L,nl);
	mergesort(R,nr);
	for(int i=0;i<nl;i++) cout << L[i] << " ";
	for(int i=nr-1;i>=0;i--) cout << R[i] << " ";		
}
int main(){
	int n; cin >> n;
	int A[100],L[100],R[100];
	for(int i=0;i<n;i++) cin >> A[i];

	partition(A,L,R,n);
	return 0; 
}