#include<iostream>
#include<string>
using namespace std;


int tub_fib(int num){
	int arr[num+2];
	for(int i{};i<num+2;i++)
		arr[i]=0;
	arr[1] = 1;
	for(int i {};i<num;i++){
		arr[i+1] += arr[i];
		arr[i+2] += arr[i];
	}
	return arr[num];
}

int main(){
	int num{};
	cout<<"Enter the number ";
	cin>>num;
	cout<<tub_fib(num);
	return 0;
}

