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

int main(){
    FAST
    int T; cin>>T;
    
    while(T--){
        int n; cin>>n;
        vi a; a.resize(n);
        F(i,0,n) cin>>a[i];
        
        vi y(n), f(n);
        
        y[0] = n+1;
        y[1] = f[0] = a[0];
        f[1] = a[0] + a[1];
        
        F(i,2,n){
            y[i] = min(f[i-2],f[i-1]);
            f[i] = min(y[i-2]+a[i-1]+a[i],y[i-1]+a[i]);
        }
        
        cout<<min(y[n-1],f[n-1])<<endl;
        
    }
}

