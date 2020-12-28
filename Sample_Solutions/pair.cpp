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

int doable(int x, const vi& in, const vi& out, const int& n){
    if(x>n) return 1;
    
    int l = 0, r = n-1;
    FFE(i,x-1,0){
        if(in[i]>out[r]) return 1;
        r--;
    }
    
    F(i,x,n){
        if(in[i]<out[l]) return -1;
        l++;
    }
    
    return 0;
}

int main(){
    FAST
    
    int T; cin>>T;
    cin.ignore(1000,'\n');
    
    FE(CASE,1,T){
        int n; cin>>n;
        
        int tmp;
        vi in, out;
        F(i,0,n){
            cin>>tmp; in.push_back(tmp);
        }
        
        tmp = 0;
        FE(i,1,2*n){
            if(i==in[tmp])tmp++;
            else out.push_back(i);
        }
        
        
        int l = 0;
        int inc = n/2;
        
        if(doable(0,in,out,n)==0) l=-1;
        else while(inc>0){
            int ret = doable(l+inc, in, out, n);
            if(ret>=0) inc/=2;
            else l+=inc;
        }
        
        int r = 0;
        inc = n/2;
        while(inc>0){
            int ret = doable(r+inc, in, out, n);
            if(ret>0) inc/=2;
            else r+=inc;
        }
        
        if(n==1) cout<<1<<endl;
        else cout<<r-l<<endl;
    }
    
    
    
}

