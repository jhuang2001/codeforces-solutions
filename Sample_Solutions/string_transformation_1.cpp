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
    
    int T; cin>>T;
    
    while(T-- ){
        int n; cin>>n;
        string A, B;
        cin>>A>>B;
        
        F(i,0,20){
            g[i] = i;
            siz[i] = 1;
        }
        
        int ans = 0;
        F(i,0,20){
            if(ans == -1) break;
            F(j,0,n){
                if(B[j]==i+'a'){
                    if(find(A[j]-'a') == find(i)){
                        continue;
                    }else if(A[j]<=B[j]){
                        uni(A[j]-'a',i);
                        ans++;
                    }else{
                        ans = -1;
                        break;
                    }
                }
            }
            
        }
        cout<<ans<<endl;
    }
}

