#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void to_int(char str[],int A[]){
	for(int i=0;i<strlen(str);i++) A[i] = str[i]-'0';
}
bool palindrome(int A[],int len){					// works for both even and odd number of digits
	int k = 0;
	for(int i=0;i<len/2;i++) if(A[i]!=A[len-i-1]) k++;
	if(k==0) return true;
	else return false;
}

int main(){
	char str[1000];int A[1000];
	scanf("%[^\n]%*c", str);
	int len = strlen(str),mid = len/2;
	to_int(str,A);
	
	int no_9 = 0;
	for(int i=0;i<len;i++) if(A[i]==9) no_9++;
	
	if(no_9==len){
		cout << 1;
		for(int i=0;i<len-1;i++) cout << 0;
		cout << 1;
	}
	else{
		if(palindrome(A,len)){
			if(len%2==0){
				A[mid-1]++;
				A[mid] = A[mid-1];
			}
			if(len%2==1) A[mid]++;
		}
		else{
			if(len%2==0){
				int k = 0;
				for(int i=0;i<mid;i++){
					if(A[mid-i-1]>A[mid+i]) A[mid+i] = A[mid-i-1];
					else if(A[mid-i-1]<A[mid+i]){
						if(k==0){
							A[mid-i-1]++;
							k++;
						}
						A[mid+i] = A[mid-i-1];
					}
				}
			}
			if(len%2==1){
				int k = 0;
				for(int i=0;i<mid;i++){
					if(A[mid-i-1]>A[mid+i+1]) A[mid+i+1] = A[mid-i-1];
					else if(A[mid-i-1]<A[mid+i+1]){
						if(k==0){
							A[mid-i-1]++;
							k++;
						}
						A[mid+i+1] = A[mid-i-1];
					} 
				}	
			}
		}
		for(int i=0;i<len;i++) cout << A[i];
	}	
		
	return 0;
}