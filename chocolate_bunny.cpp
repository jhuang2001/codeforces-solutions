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
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int main(){
    FAST
    int n; cin>>n;
    vi g; g.resize(n+1);
    stack<int> st;
    FE(i,1,n)st.push(i);
    
    while(!st.empty()){
        
        if(st.size()==1){
            int c = st.top();st.pop();
            g[c] = n;
            break;
        }
        
        int ab, ba;
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        
        cout<<"? "<<a<<" "<<b<<endl;
        cout.flush();
        cin>>ab;
        cout<<"? "<<b<<" "<<a<<endl;
        cout.flush();
        cin>>ba;
        
        if(ab<ba){
            g[b] = ba;
            st.push(a);
        }else{
            g[a] = ab;
            st.push(b);
        }
        
        
    }
    
    cout<<"! ";
    FE(i,1,n){
        cout<<g[i]<<" ";
    }
    cout<<endl; cout.flush();
}

