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
#define abs(a) ((a)<0?-(a):(a))
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
typedef vector<pii> vii;
typedef vector<vi> vvi;

ll choose(int f, int t){
    if(f<0 || t<0) return -1;
    if(f<t) return 0;
    
    ll ret = 1;
    FF(i,f,f-t) ret*=i;
    FF(i,t,0) ret/=i;
    
    return ret;
}

int main(){
    FAST
    
    int T; cin>>T;
    cin.ignore(1000,'\n');
    
    FE(CASE,1,T){
        int n; cin>>n;
        
        vvi e; e.resize(n+1);
        F(i,0,n){
            int a, b; cin>>a>>b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        
        stack<int> dfs; dfs.push(1);
        vi par; par.resize(n+1,0);
        par[1] = -1;
        
        int cycle = 0;
        
        while(!dfs.empty()){
            int curr = dfs.top(); dfs.pop();
            for(int a : e[curr]){
                if(a == par[curr]) continue;
                if(!par[a]) dfs.push(a);
                else cycle = a;
                
                par[a] = curr;
            }
        }
        
        vi cyc;
        int c = cycle;
        do {
            cyc.push_back(c);
            c = par[c];
        }while(c != cycle);
        
        vector<bool> visited; visited.resize(n+1,false);
        vi sizes;
        for(int a : cyc) visited[a] = true;
        for(int a : cyc){
            int size = 0;
            stack<int> s; s.push(a);
            while(!s.empty()){
                int curr = s.top(); s.pop();
                visited[curr] = true;
                for(int child : e[curr]){
                    if(!visited[child]) s.push(child);
                }
                size++;
            }
            sizes.push_back(size);
        }
        
        ll ans = 0;
        for(int a : sizes){
            ans += choose(a,2);
            ans += (ll)a*(n-a);
        }
        
        cout<<ans<<endl;
        
    }
}

