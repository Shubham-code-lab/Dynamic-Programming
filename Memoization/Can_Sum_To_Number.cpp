#include<iostream>
#include<vector>
#include<limits>
#include<map>
#include<climits>
#include<array>

using namespace std;

bool canSum(vector<int>&vec,int num,map<int,bool>&m){
	auto it = m.find(num);
	if(it != m.end())
	  return m[num];
	if(num == 0)
	  return true;                  // for the if statement
	if(num  < 0)
	  return false;                 //for the if statement
	for(unsigned int i{};i<vec.size();i++){
	  int target = num-vec[i];
	  m[num]=canSum(vec,target,m);
	  if(m[num]){
		  return true;
	  }                    //if statement // this is return result
	}
    return false;                   //for the if statement
}


bool howSum(int target,vector<int>&vec,map<int,bool>&m,vector<int>&res){
  std::map<int,bool,less<int>,allocator<pair<const int,bool>>>::iterator it =m.find(target);
  if(it != m.end())return m[target];
  if(target == 0)return true;
  if(target < 0)return false;
  for(unsigned int i{};i<vec.size();i++){
	  int temp = target-vec[i];
	  m[target] = howSum(temp,vec,m,res);
      if(m[target]){
    	res.push_back(vec[i]);
        return  true;
      }
  }
  return false;
}




vector<int> bestSum(int target,vector<int> &vec,map<int,vector<int>>&m){
	auto it = m.find(target);
	if(it != m.end())return m[target];
	if(target == 0)return {target};
	if(target < 0 )return {};
	vector<int>res{};
	for(size_t i{};i<vec.size();i++){
		int rem = target - vec[i];
		vector<int>temp = bestSum(rem,vec,m);
		if(temp.size() > 0){
			temp.push_back(vec[i]);
			if(res.size() == 0 || temp.size() < res.size()){
				res = temp;     //left tree output in res and right output in temp
			}                   // so res is not empty and right have smaller or equal value
		}
	}
	m[target] = res;           //res always contain output of tree and it is return and then check for which is greater with temp and if temp is smaller than res is updated as res =temp and res return this continue every times
	return res;
}

int main(){
	vector<int>vec{2,3};
	cout<<"Enter the  vector element :-\n";
//	int num{};
//	while(cin>>num)
//	  vec.push_back(num);
//	cin.clear();
//	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	int target{7};
//    cout<<"Enter the target sum:-\n";
//	cin>>target;
//    cout<<boolalpha;
//    map<int,bool>m;
//	cout<<"Result is :-\n"<<canSum(vec,target,m)<<"\n";
//	map<int,bool>m2;
//	vector<int>res;
//	cout<<"Sum element are :- \n";
//	howSum(target,vec,m2,res);
//	for(auto vecs : res)
//		cout<<vecs<<"\t";
map<int,vector<int>>m;
vector<int> v = bestSum(target,vec,m);
for(auto i : m){
	cout<<i.first<<"\t";
	for(int j{};j<i.second.size();j++){
		cout<<i.second[j]<<"\t";
	}
	cout<<"\n";
}
	return 0;
}
































//#include<bits/stdc++.h>
//#define        ll     long long int
//using namespace std;
//int target;
//vector<vector<int> >v;
//vector<int>x;                         ///this program works upto 10^5 within 1 sec
//bool visit[10000];
//vector<int>u;
//bool bestsum(int n,int m,int a[])
//{
//    if(n==target)
//    {
//        if(v[n][0]==-1)
//        {
//            v[n]=x;
//        }
//        else if(v[n].size()>x.size())
//        {
//            v[n]=x;
//        }
//        x.pop_back();
//        return true;
//    }
//
//   ///memoization  part
//    if(v[n][0]!=-1)
//    {
//        if(v[n].size()>x.size())
//        {
//            v[n]=x;
//             x.pop_back();
//            return true;
//        }
//       else if(x.size()>v[n].size()){
//             x.pop_back();
//            return true;;
//       }
//       else{
//             x.pop_back();
//            return true;;
//       }
//    }
//
//    for(int i=0; i<m; i++)
//    {
//        int r=n+a[i];
//        if(r<=target)
//        {
//            x.push_back(a[i]);
//            bestsum(r,m,a);
//        }
//    }
//    if(v[n][0]==-1)
//    {
//        v[n]=x;
//    }
//    else if(v[n].size()>x.size())
//    {
//        v[n]=x;
//    }
//
//    x.pop_back();
//    return false;
//}
//
//int main()
//{
//    int n,m;
//    //cin>>target>>m;
//    target =7;
//    m=2;
//    int a[]{2,3};
////    for(int i=0; i<m; i++)
////    {
////        cin>>a[i];
////    }
//    n=0;
//    for(int i=0; i<=target; i++)
//    {
//        vector<int>d;
//        d.push_back(-1);
//        v.push_back(d);
//    }
//    for(int i=0; i<=target; i++)
//    {
//        visit[i]=false;
//    }
//    sort(a, a + m, greater<int>());
//    bestsum(n,m,a);
//    for(int i=0; i<v[target].size(); i++)
//    {
//        cout<<v[target][i]<<" ";
//    }
//    cout<<endl;
//    return 0;
//}
