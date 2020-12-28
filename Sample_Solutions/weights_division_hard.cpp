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

vector<vector<pair<pll,int>>> tree;
vector<ll> cnt;
vector<ll> val;
vi cost;

void dfs(ll curr, ll prev){
    
    bool leaf = true;
    
    for(auto it: tree[curr]){
        if(it.first.first != prev){
            leaf= false;
            dfs(it.first.first, curr);
            val[it.first.first] = it.first.second;
            cost[it.first.first] = it.second;
            cnt[curr] += cnt[it.first.first];
        }
    }
    
    if(leaf){
        cnt[curr] = 1;
    }
    
}

struct comp{
    bool operator() (const pll &a, const pll &b){
        return a.second<b.second;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int T; cin>>T;
    
    while(T--){
        int n; ll s;
        cin>>n>>s;
        
        tree.clear(); cnt.clear(); val.clear();
        tree.resize(n+1);
        cnt.resize(n+1);
        val.resize(n+1);
        cost.resize(n+1);
        
        F(i,0,n-1){
            int v,u,w,c;
            cin>>v>>u>>w>>c;
            tree[v].push_back(mp(mp(u,w),c));
            tree[u].push_back(mp(mp(v,w),c));
        }
        
        dfs(1,0);
        
        ll sum = 0;
        ll s1 = 0, s2 = 0;
        
        priority_queue<pll, vector<pll>, comp> q;
        FE(i,1,n){
            sum+=val[i]*cnt[i];
            q.push(mp(i,((val[i]+1)/2)*cnt[i]));
        }
        if(sum<s){
            cout<<0<<endl;
            continue;
        }
        ll change = sum-s;
        list<ll> q1, q2;
        
        while(sum>0){
            pll m = q.top();
            q.pop();
            sum-=m.second;
            val[m.first]/=2;
            q.push(mp(m.first,((val[m.first]+1)/2)*cnt[m.first]));
            
            if(cost[m.first]==1)q1.push_back(m.second);
            else{q2.push_back(m.second); s2+=m.second;}
        }
        
        ll mc = LLONG_MAX;
        auto i1 = q1.begin();
        auto i2 = q2.rbegin();
        ll lc = 0, rc = 0;
        
        while(i2 != q2.rend() && s1+s2-*i2>=change){
            s2-=*i2;
            i2++;
            rc++;
        }
        if(s1+s2>=change) mc = min(lc+2*(q2.size()-rc), mc);
        
        while(i1 != q1.end()){
            s1+=*i1;
            lc++;
            i1++;
            while(i2 != q2.rend() && s1+s2-*i2>=change){
                s2-=*i2;
                i2++;
                rc++;
            }
            
            if(s1+s2>=change) mc = min(lc+2*(q2.size()-rc), mc);
        }
        cout<<mc<<endl;
    }
}

