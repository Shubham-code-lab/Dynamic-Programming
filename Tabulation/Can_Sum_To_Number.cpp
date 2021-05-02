#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using  namespace std;

bool canSum(int num , int arr[], int size){
  bool check[num+1];
  for(int i{};i<=num;i++){
	  check[i] = false;
  }
  check[0]= true;
  for(int i{};i<=num;i++){
	if(check[i]){
	   for(int j{};j<size;j++){
		   int k =i+arr[j];
		   if(k <= num){
			   check[k] =true;
		   }
	   }
	}
  }
  return check[num];
}


vector<int> howSum(int target , int arr[] , int size){
	vector<vector<int>> vec;
	for(int i{};i<=target;i++){
		vec.push_back(vector<int>());
		vec[i].push_back(-1);
	}
	vec[0][0] = 0;
    for(int i{};i<=target;i++){
    	if(vec[i][0] != -1){
    	for(int j{};j<size;j++){
           int k = i+arr[j];
           if(k<=target){
        	   vec[k].clear();                // good job
        	   for(auto z : vec[i])
        		   if(z != 0)
        		   vec[k].push_back(z);
        	   vec[k].push_back(arr[j]);
        	   if(target == k){j=size;i=target+1;}
           }
    	}
      }
    }
    return vec[target];
}

vector<int> best_Sum(int target,int  arr[], int size){
	vector<vector<int>>vec;
	for(int i{};i<=target;i++){
		vec.push_back(vector<int>());
		vec[i].push_back(-1);
	}
	vec[0][0] = 0;
	for(int i{};i<=target;i++){
		if(vec[i][0] != -1){
			for(int j{};j<size;j++){          //j = array , i= vector
				int k = i + arr[j];
				if(k<=target){
                    if(vec[k][0] == -1 ){
                     vec[k].clear();
                     vec[k].push_back(arr[j]);
                     if(i != 0 )vec[k].insert(vec[k].end(),vec[i].begin(),vec[i].end());
                    }
                    else if(vec[k].size() > vec[i].size()+1){
                      vec[k].clear();
                      vec[k].push_back(arr[j]);
                      vec[k].insert(vec[k].end(),vec[i].begin(),vec[i].end());
                    }
				}
			}
		}
	}
	return vec[target];
}


int main(){
int target;
cout<<"Enter the number :-\n";
cin>>target;
int size{4};
int arr[size];
int value{};
cout<<"Enter the array element :-\n";
for(int i{};i<size;i++){
	cin>>value;
	arr[i] = value;
}
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<boolalpha;
cout<<"can addition form :-\n";
cout<<canSum(target,arr,size);
vector<int> res1 = howSum(target,arr,size);
cout<<"\nsum from the below number addition :-\n";
for(auto r : res1)
	cout<<r<<"\t";
cout<<"\n";
vector<int> res2 = best_Sum(target,arr,size);
cout<<"Sortest Way to sort :-\n";
for(auto r : res2)
	cout<<r<<"\t";
return 0;
}
