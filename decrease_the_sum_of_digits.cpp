//libraries
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
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

int sum(ll i){
    int r=0;
    while(i>0){
        r+=i%10;
        i/=10;
    }
    return r;
}

ll tens(int n){
    ll r = 1;
    F(i,0,n)r*=10;
    return r;
}

int main(){
    int T; cin>>T;
    while(T--){
        ll n; int s; cin>>n>>s;
        
        ll ans = 0; int ind = 0;
        while(sum(n)>s){
            int add = 10-(n%10);
            ans+=add*tens(ind);
            n+=add;
            n/=10;
            ind++;
        }
        cout<<ans<<endl;
    }
}

