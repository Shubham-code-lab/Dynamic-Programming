#include<iostream>
#include<vector>
#include<limits>
#include<map>

using  namespace std;

bool canConstruct(string str , vector<string> vec,map<string,bool>&m){
  auto it = m.find(str);
  if(it != m.end())return m[str];
  if(str.length() == 0)return true;
  for(unsigned int i{};i<vec.size();i++){
      if(vec[i].length() <= str.length()){
    	  if(str.substr(0,vec[i].length()) == vec[i]){
    		  m[str] = canConstruct(str.substr(vec[i].length()),vec,m);
    	      if(m[str]){return true;}
    	  }
      }
  }
  m[str] = false;
  return false;
}

bool count_Construct(string str,vector<string> vec,map<string,bool>&m,int &count){
  auto it = m.find(str);
  if(it != m.end())
	  return m[str];
  if(str.length() == 0)
	  return true;
  for(size_t i{};i<vec.size();i++){
	  if(vec[i].length() <= str.length()){
		  if(str.substr(0,vec[i].length()) == vec[i]){
			 m[str] = count_Construct(str.substr(vec[i].length()),vec,m,count);
			 if(m[str])count++;
		  }
	  }
  }
 // m[str] = false;        this make the string false even if it is usefull so don,t store false value. Noob shubham understand it
  return false;
}

vector<vector<string>> all_way(string str , vector<string> vec,map<string,vector<vector<string>>>&m){
	auto it = m.find(str);
	if(it != m.end())return m[str];
	if(str.length() == 0)return {{str}};
	vector<vector<string>> res;
	for(size_t i{};i<vec.size();i++){
		if(str.length() >= vec[i].length())
			if(str.substr(0,vec[i].length()) == vec[i]){
			 vector<vector<string>> temp = all_way(str.substr(vec[i].length()),vec,m);
				if(temp.size() >= 0){
		           for(size_t j{};j<temp.size();j++)temp[j].push_back(vec[i]);
				   if(res.size()==0)res = temp;
				   else if(res.size() > 0)for(size_t k{};k<temp.size();k++)res.push_back(temp[k]);
				 }
			}
		}
	m[str] = res;
	return res;
}

vector<string> sortest_way(string str , vector<string> vec, map<string,vector<string>>&m){
	auto it = m.find(str);
	if(it != m.end())return m[str];
	if(str.length() == 0)return {str};
	vector<string>res{};
	for(size_t i{};i<vec.size();i++){
		if(vec[i].length() <= str.length()){
			if(str.substr(0,vec[i].length()) == vec[i]){
				vector<string> temp =sortest_way(str.substr(vec[i].length()),vec,m);
				if(temp.size() > 0){
					temp.push_back(vec[i]);
					if(res.size() == 0 || temp.size() < res.size())
						res = temp;
				}
			}
		}
	}
	m[str] = res;
	return res;
}


int main(){
cout<<"Enter the string :-";
string str;//                                {"ababcdef"};
cin>>str;
cout<<"\nEnter the Sub-String:-\n";
string temp;
vector<string> vec;//                         {"ab","abc","cd","def","abcd","ef","c"};
int i{};
cout<<"Enter the number of the sub-string:-\n";
cin>>i;
while(i--){
	cin>>temp;
  vec.push_back(temp);
}
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<boolalpha;
map<string,bool>m;
cout<<"\nIs string constructed :-\n"<<canConstruct(str,vec,m)<<"\n";
int count{};
map<string,bool>m2;
count_Construct(str,vec,m2,count);
cout<<"\nTotal Result are :-\n"<<count<<"\n\n";
map<string,vector<string>>m3;
sortest_way(str,vec,m3);
cout<<"Shortest way to short";
for(auto s : m3){
	cout<<"\n"<<s.first<<":-\t";
	for(size_t i{1};i<s.second.size();i++){
		cout<<s.second[i]<<"\t";
	}
}
cout<<"\n\n";
cout<<"All way to short\n";
map<string,vector<vector<string>>>m4;
vector<vector<string>>vecs = all_way(str,vec,m4);
for(auto v: vecs){
	for(auto t : v)
		if(t != "")
		cout<<t<<"\t";
	cout<<"\n";
}
return 0;
}
