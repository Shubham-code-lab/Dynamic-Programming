#include<iostream>
#include<map>
#include<functional>

using namespace std;

int fib_pro(map<int,long long int> &m,int num){
	auto it = m.find(num);
	if(it != m.end())
		return m[num];
    if(num <= 2)
    	return 1;
    m[num] = fib_pro(m,num-1)+fib_pro(m,num-2);
    return m[num];
}

int fib_navie(int num){
	if(num <= 2)
		return 1;
	return fib_navie(num-1)+fib_navie(num-2);
}

int main(){
   map<int,long long int> m;
   int num{};
   cout<<"Enter the number :- \n";
   cin>>num;
   cout<<fib_pro(m,num)<<"\n";
   cout<<fib_navie(num);
	return 0;
}
