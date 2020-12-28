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
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

using namespace std;

//typedef
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//static vars
vector<ll> cnt;
vector<long long> w;
vvi e;
ll MOD = 1000000007;

void dfs(int curr, int prev){
    for(int p : e[curr]){
        if(p != prev){
            dfs(p, curr);
            cnt[curr]+=cnt[p];
        }
    }
}

int main(){
    FAST
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        
        int a,b;
        e.clear(); e.resize(n+1);
        F(i,0,n-1){
            cin>>a>>b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        
        cnt.assign(n+1, 1);
        cnt[0] = 0;
        
        dfs(1,0);
        
        
        FE(i,1,n){
            cnt[i] = cnt[i] * (n-cnt[i]);
        }
        
        sort(cnt.begin(), cnt.end());
        
        int m;
        cin>>m;
        
        vector<ll> p; p.resize(m);
        F(i,0,m) cin>>p[i];
        
        sort(p.begin(), p.end());
        
        if(m>n-1){
            ll fin = p.back();
            p.pop_back();
            while(m>n-1){
                ll l = p.back(); p.pop_back();
                fin*=l; fin%=MOD;
                m--;
            }
            p.push_back(fin);
        }
        
        ll ans = 0;
        vector<ll>::iterator cit = --cnt.end();
        vector<ll>::iterator pit = --p.end();
        
        while(cit > cnt.begin() && pit >= p.begin()){
            cerr<< *pit << endl;
            ans += ((*cit)* (*pit)) % MOD; ans %= MOD;
            cit--;
            pit--;
        }
        while(cit > cnt.begin()){
            ans+= (*cit) % MOD; ans%= MOD; --cit;
        }
        
        cout<<ans<<endl;
    }
}

