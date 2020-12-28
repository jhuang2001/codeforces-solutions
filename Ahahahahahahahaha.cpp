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


int main(){
    int T; cin>>T;
    F(CASE,0,T){
        int n; cin>>n;
        int c0 = 0, c1 = 0, t = n;
        while(t--){
            int in; cin>>in;
            if(in) c1++;
            else c0++;
        }
        
        if(c0>=n/2){
            cout<<c0<<endl;
            F(i,0,c0) cout<<0<<" ";
            cout<<endl;
        }else{
            int ans = c1 - c1%2;
            cout<<ans<<endl;
            F(i,0,ans) cout<<1<<" ";
            cout<<endl;
        }
        
    }
}

