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


int main(){
    FAST
    
    int MOD = 1000000007;
    int n; cin>>n; cin.ignore(999,'\n');
    string s; getline(cin, s);
    
    long long a = 0, b = 0, c = 0;
    long long subs = 1;
    
    F(i,0,n){
        if(s[i] == 'c'){
            c+=b; c%=MOD;
        }else if(s[i] == 'b'){
            b+=a; b%=MOD;
        }else if(s[i] == 'a'){
            a+=subs; a%=MOD;
        }else if(s[i] == '?'){
            c*=3; c+=b; c%=MOD;
            b*=3; b+=a; b%=MOD;
            a*=3; a+=subs; a%=MOD;
            subs*=3; subs%=MOD;
        }
        
        //cerr<<i<<' '<<a<<' '<<b<<' '<<c<<endl;
    }
    
    cout<<c<<endl;
    
    
}

