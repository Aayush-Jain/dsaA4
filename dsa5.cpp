#include <iostream>
#include <math.h>
using namespace std;

int factors(int n){
	int answer = 1;
	for(int i=2;i<=n;i++){
		if(n%i==0){
			int count = 1;
			while(n%i==0){
				n = n/i;
				count++;
			}
			//cout << count << endl;
			answer = answer * (count);
		}
	}
	return answer;
}
void swap(int A[],int i,int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
int main(){
	int n,A[100],F[100]; cin >> n;
	for(int i=0;i<n;i++) cin >> A[i];
	for(int i=0;i<n;i++){
		F[i] = factors(A[i]);
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(F[i]<F[j]){
				swap(A,i,j);
				swap(F,i,j);
			}
		}
	}
	for(int i=0;i<n;i++) cout << A[i] << " ";
	return 0;
}