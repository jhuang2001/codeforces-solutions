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

int dp[201][201][201];

int main(){
    FAST
    int N,K;
    cin>>N>>K;
    string s, t;
    cin>>s>>t;
    
    if(t[0]==t[1]){
        int count = 0;
        for(auto c : s){
            if(c == t[0]) count++;
        }
        count+=K;
        count = min(count,s.length());
        cout<<(count*(count-1))/2<<endl;
    }else{
        F(i,0,N){
            F(j,0,N+1){
                FE(k,0,K) dp[k][i][j] = -1;
            }
        }
        
        int sc=0,count=0;
        F(i,0,N){
            if(s[i]==t[0])sc++;
            else if(s[i]==t[1])count+=sc;
            dp[0][i][sc] = count;
        }
        
        F(k,1,K){
            dp[k][0][0] = 0;
            dp[k][0][1] = 0;
        }
        
        FE(k,1,K){
            F(i,1,N){
                FE(j,0,i+1){
                    int tmp = -1;
                    if(j>0){        //convert to t0
                        if(t[0] == s[i]) tmp = dp[k][i-1][j-1];
                        tmp = max(tmp,dp[k-1][i-1][j-1]);
                    }
                    if(dp[k-1][i-1][j] >= 0){    //convert to t1
                        tmp = max(tmp,dp[k-1][i-1][j]+j);
                    }
                    if(dp[k][i-1][j] >= 0 && t[0] != s[i]){     //do nothing
                        tmp = max(tmp,dp[k][i-1][j]);
                        if(t[1]==s[i]) tmp = max(tmp,dp[k][i-1][j]+j);
                    }
                    dp[k][i][j] = tmp;
                    
                }
            }
        }
        
        int m = 0;
        F(j,0,N+1){
            m = max(m,dp[K][N-1][j]);
        }
        cout<<m<<endl;
    }
}

