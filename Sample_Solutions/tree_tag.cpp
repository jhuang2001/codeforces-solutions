//libraries
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <iostream>

//macros
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define abs(a) (a<0?-a:a)
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define PI 3.1415926535897932384626
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

using namespace std;

//typedef
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vvi tree;
vi depth;

void dfs(int curr, int prev){
    for(auto n : tree[curr]){
        if(n!=prev){
            dfs(n,curr);
            depth[curr] = max(depth[n]+1,depth[curr]);
        }
    }
}

int dia(int curr, int prev){
    int ret; int m1 = 0, m2 = 0;
    for(auto n : tree[curr]){
        if(n!=prev){
            if(depth[n]>m1){m2=m1;m1=depth[n];}
            else if(depth[n]>m2)m2=depth[n];
        }
    }
    ret = m1+m2+1;
    for(auto n : tree[curr]){
        if(n!=prev){
            ret = max(dia(n,curr),ret);
        }
    }
    
    return ret;
}

int dist(int a, int b, int prev){
    if(a==b) return 0;
    for(auto n : tree[a]){
        if(n!=prev){
            int d = dist(n,b,a);
            if(d>=0) return d+1;
        }
    }
    
    return -1;
}

int main(){
    FAST
    int T; cin>>T;
    FE(CASE,1,T){
        bool ans = false;
        
        int n, a, b, da, db;
        cin>>n>>a>>b>>da>>db;
        
        tree.clear(); tree.resize(n+1);
        depth.assign(n+1, 1);
        F(i,0,n-1){
            int x, y;
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        
        dfs(a,0);
        if(dist(a,b,0)>da && db>2*da){
            int d = dia(a,0);
            if(d>2*da+1) ans = true;
            cerr<<d<<endl;
        }
        
        cout<<(ans? "Bob" : "Alice")<<endl;
    }
    
}

