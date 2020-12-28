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
typedef vector<pii> vii;

int g[20];
int siz[20];

int find(int i){
    if(g[i]!=g[g[i]])g[i] = find(g[i]);
    return g[i];
}

void uni(int x, int y){
    int a = find(x); int b = find(y);
    if(g[a]==g[b]) return;
    if(siz[a]<siz[b]) swap(a,b);
    g[b] = g[a];
    siz[a] += siz[b];
}

int main(){
    FAST
    
    int n,m; cin>>n>>m;
    vii r, s;
    
    F(i,0,n){
        int a,b; cin>>a>>b;
        r.push_back(mp(a,b));
    }
    
    int C[1000002] = {0};
    
    F(i,0,m){
        int a,b; cin>>a>>b;
        s.push_back(mp(a,b));
    }
    
    F(j,0,m){
        F(i,0,n){
            int dx = s[j].first - r[i].first;
            if(dx>=0){
                C[dx] = max(C[dx],s[j].second-r[i].second+1);
            }
        }
    }
    
    int ans = 1000001;
    FFE(i,1000000,0){
        C[i] = max(C[i],C[i+1]);
        ans = min(C[i]+i,ans);
    }
    cout<<ans<<endl;
}

