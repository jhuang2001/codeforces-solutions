//libraries
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <list>
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

using namespace std;

//typedef
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<vector<pll>> tree;
vector<ll> cnt;
vector<ll> val;

void dfs(ll curr, ll prev){
    
    bool leaf = true;
    
    for(auto it: tree[curr]){
        if(it.first != prev){
            leaf= false;
            dfs(it.first, curr);
            val[it.first] = it.second;
            cnt[curr] += cnt[it.first];
        }
    }
    
    if(leaf){
        cnt[curr] = 1;
    }
    
}

struct compProd{
bool operator()(const pll& a, const pll& b){
    return a.second<b.second;
}
};

priority_queue<pll, vector<pll>, compProd> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int T; cin>>T;
    
    while(T--){
        int n; ll s;
        cin>>n>>s;
        
        while(!q.empty())q.pop();
        tree.clear(); cnt.clear(); val.clear();
        tree.resize(n+1);
        cnt.resize(n+1);
        val.resize(n+1);
        
        F(i,0,n-1){
            int v,u,w;
            cin>>v>>u>>w;
            tree[v].push_back(mp(u,w));
            tree[u].push_back(mp(v,w));
        }
        
        dfs(1,0);
        
        ll sum = 0;
        
        FE(i,1,n){
            q.push(mp(i, (val[i]+1)/2*cnt[i]));
            sum+=val[i]*cnt[i];
        }
        
        ll moves = 0;
        
        while(sum>s){
            pll m = q.top();
            q.pop();
            
            sum-=m.second;
            val[m.first]/=2;
            q.push(mp(m.first, (val[m.first]+1)/2*cnt[m.first]));
            
            moves++;
        }
        
        cout<<moves<<'\n';
        
    }
}

