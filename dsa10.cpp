#include <iostream>
using namespace std;

void swap(int A[],int i,int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
void reverse(int A[],int n){
	int mid = n/2;
	for(int i=0;i<=mid;i++) swap(A,i,n-i);
}
int max_element(int A[],int n){
	int max=0;
	for(int i=0;i<=n;i++){
		if(A[i]>A[max]) max = i;
	}
	return max;
}
int main(){
	int n,A[100]; cin >> n;
	for(int i=0;i<n;i++) cin >> A[i];
	int max;
	for(int i=1;i<=n;i++){
		max = max_element(A,n-i);	
		reverse(A,max);
		reverse(A,n-i);
	}
	for(int i=0;i<n;i++) cout << A[i] << " ";
	cout << endl;	
	return 0;
}