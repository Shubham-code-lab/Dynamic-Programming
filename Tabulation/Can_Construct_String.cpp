#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool canConstruct(string str, string arr[] , int size){
   vector<bool> check(str.length()+10,false);
   check[0] =true;
   for(size_t i{};i<check.size();i++){
	  if(check[i]){
		for(int j{};j<size;j++){
	      if(str.length() >= arr[j].length()){
			if(str.substr(i,arr[j].length()) == arr[j]){
	           check[i+arr[j].length()]=true;
	        }
		  }
		 }
	   }
	 }
   return check[str.length()];
}

vector<string> howConstruct(string str , string arr[] , int size){
	vector<bool> check(str.length()+1,false);
	check[0] = true;
	vector<vector<string>> res;
	for(size_t i{};i<str.length()+1;i++){
		res.push_back(vector<string>());
	}
    for(size_t i{};i<check.size();i++){
    	if(check[i]){
    		int flag {};
    		for(int j{};j<size;j++){
    			if(str.length() >= arr[j].length()){
    				if(str.substr(i,arr[j].length()) == arr[j]){
    					check[i+arr[j].length()] =true;
    					for(size_t k{};k<res[i].size();k++){
    						res[i+arr[j].length()].push_back(res[i][k]);
    					}
    					res[i+arr[j].length()].push_back(arr[j]);
    					if(check[str.length()]){
    						flag = 1;
    						break;
    					}
    				}
    			}
    		}
    		if(flag)break;
    	}
    }
    return res[str.length()];
}



int main(){
string str{"enterapotentpot"};
cout<<"Enter the string :- \n";
//cin>>str;
int size{7};
cout<<"\nEnter the number of the sub-string :-\n";
//cin>>size;
cout<<"\nEnter the sub-string :-\n";
string arr[1000];
arr[0] = "a";
arr[1] = "p";
arr[2] = "ent";
arr[3] = "enter";
arr[4] = "ot";
arr[5] = "o";
arr[6] = "t";
string temp;
//for(int i{};i<size;i++){
//	cin>>temp;
//	arr[i] =temp;
//}
cout<<"\nResult is :-\n";
cout<<boolalpha;
cout<<canConstruct(str,arr,size)<<"\n";
vector<string> res1 = howConstruct(str,arr,size);
for(auto r : res1)
	cout<<r<<"\t";
return 0;
}



