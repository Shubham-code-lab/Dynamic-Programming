#include<iostream>
#define mod 100000000
using namespace std;

void travel(int m ,int n){
	int arr[m+1][n+1];
	for(int i{};i<=m;i++)
		for(int j{};j<=n;j++)
			arr[i][j]=0;
	arr[1][1]= 1;
	for(int i{};i<=m;i++){
		for(int j{};j<=n;j++){
          if(i+1 <= m)arr[i+1][j] = ((arr[i+1][j])%mod + (arr[i][j])%mod)%mod;
          if(j+1 <= n)arr[i][j+1] = ((arr[i][j+1])%mod + (arr[i][j])%mod)%mod;
		}
	}
	for(int i{};i<m;i++){
		for(int j{};j<n;j++)
			cout<<arr[i][j]<<"  ";
		cout<<"\n";
	}
	cout<<"\n"<<arr[m][n];
}

int main(){
	int m{},n{};
	cin>>m>>n;
    travel(m,n);
	return 0;
}


