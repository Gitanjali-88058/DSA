#include<iostream>
using namespace std;
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>

// #define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
signed main(){
    map<int,int> m;
    m[8]=2;
    m[1]=3;
    m[5]=6;
    m[4]=2;
    m[4]=6;
    cout<<m[8]<<endl;
    cout<<m[1]<<endl;
    
    cout<<m[5]<<endl;
    cout<<m[4]<<endl;
    return 0;
}