#include <iostream>
using namespace std;

void merge(int A[],int L[],int R[],int nl,int nr){
	int i=0,j=0,k=0;
	while(i<nl&&j<nr){
		if(L[i] < R[j]){
			A[k] = L[i];
			k++; i++;
		}
		else{
			A[k] = R[j];
			k++ ; j++;
		}
	}
	while(i<nl){
		A[k] = L[i];
		k++ ; i++;
	}
	while(j<nr){
		A[k] = R[j];
		k++; j++;
	}
}
void mergesort(int A[],int n){
	if(n<2) return;
	int L[100],R[100];
	int mid = n/2;
	for(int i=0;i<mid;i++) L[i] = A[i];
	for(int i=mid;i<n;i++) R[i-mid] = A[i];
	mergesort(L,mid);
	mergesort(R,n-mid);
	merge(A,L,R,mid,n-mid);	
}
int search(int A[],int low,int high,int x){
	if(low>high) return -1;
	int mid = (low + high)/2;
	if(A[mid]==x) return mid;
	else if(A[mid]>x) return search(A,low,mid-1,x);
	else return search(A,mid+1,high,x);
}
int main(){
	int n,x;
	cin >> n >> x;
	int A[100];
	for(int i=0;i<n;i++) cin >> A[i];
	mergesort(A,n);
	int answer = 0;
	for(int i=0;i<n;i++){
		if(x-A[i]>A[0]){
			int a = search(A,0,n-1,x-A[i]);
			if(a!=-1){
				answer++;
				break;
			} 
		}
	}
	if(answer==0) cout << "no";
	else cout << "YES";
	return 0;
}