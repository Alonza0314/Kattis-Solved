#include<iostream>
#include<sstream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

int rules;
string input,dependency_file,key_file,target;
unordered_map<string,vector<string>> un_map;
unordered_set<string> un_set;
vector<string> output;

void dfs(string compilered){
    un_set.insert(compilered);
    for(vector<string>::iterator itt=un_map[compilered].begin();itt!=un_map[compilered].end();itt++){
        if(!un_set.count(*itt)){
            dfs(*itt);
        }
    }
    output.push_back(compilered);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>rules;
    getline(cin,input);
    while(rules--){
        getline(cin,input);
        stringstream ss(input);
        ss>>dependency_file;
        dependency_file=dependency_file.substr(0,dependency_file.size()-1);
        while(ss>>key_file){
            un_map[key_file].push_back(dependency_file);
        }
    }

    cin>>target;
    dfs(target);

    for(vector<string>::iterator itt=output.end()-1;itt>=output.begin();itt--){
        cout<<*itt<<"\n";
    }

    return 0;
}