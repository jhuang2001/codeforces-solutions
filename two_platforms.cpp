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
        int n, k;
        cin>>n>>k;
        
        vi in;
        int num;
        F(i,0,n){
            cin>>num;
            in.push_back(num);
        }
        F(i,0,n)cin>>num;
        
        sort(in.begin(), in.end());
        
        int a=0, b=0;
        vi pre;
        
        while(b<n){
            while(in[a]<in[b]-k)a++;
            pre.push_back(b-a+1);
            b++;
        }
        
        a=b=n-1;
        vi post;
        while(a>=0){
            while(in[b]>in[a]+k)b--;
            post.push_back(b-a+1);
            //cerr<<b-a+1<<endl;
            a--;
        }
        reverse(post.begin(), post.end());
        
        vi mpre; vi mpost;
        int m = 0;
        F(i,0,n){
            m = max(m,pre[i]);
            mpre.push_back(m);
        }
        m=0;
        FFE(i,n-1,0){
            m = max(m,post[i]);
            mpost.push_back(m);
        }
        reverse(mpost.begin(), mpost.end());
        
        int ans = 0;
        if(n==1)ans=1;
        F(i,0,n-1){
            //cerr<<mpre[i]<<" "<<mpost[i]<<endl;
            ans = max(ans, mpre[i]+mpost[i+1]);
        }
        
        cout<<ans<<endl;
    }
}

