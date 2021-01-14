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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
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
typedef vector<vi> vvi;

int intersect(pii a, pii b){
    int num = (a.second-b.second);
    int den = (b.first-a.first);
    if((num<0)^(den<0)) return -1;
    return num/den;
}

int main(){
    FAST
    
    int N, T, G;
    cin>>N>>T>>G;
    
    int C = 2*T;
    
    vi a; int in;
    F(i,0,N){
        cin>>in; a.push_back(in%(C));   //gondolas cycle with period C = 2*T
    }
    
    int dp[1441][401];
    
    int ans = INT32_MAX;
    
    FE(s,1,N){
        int sum = 0;
        int pre[C]; F(i,0,C) pre[i] = 0;
        
        int move = C;   //Shift until a gondola (a[i]) is at the end
        F(i,0,N){
            if(a[i]!=C-1) move = min(move, C-1-a[i]);
        }
        
        F(i,0,N){
            a[i] = (a[i]+move)%C;
            sum += C-1-a[i];
            pre[a[i]]++;
        }
        
        dp[0][1] = sum; //setup prefix sum array
        F(i,1,C){
            dp[i][1] = sum;
            pre[i]+=pre[i-1];
        }
        
        FE(k,2,G){
            dp[C-1][k] = dp[C-1][k-1];

            /*CHT -- Convex hull trick
            * dp[i][k] = min(dp[j][k-1] - pre[i]*(j-i)), for j>=i
            * Rewrite as dp[i][k] = pre[i]*i + min(dp[j][k-1] - j*pre[i]), for j>=i
            *  
            * Note that the min() is of linear functions of pre[i]
            * 
            * This solution uses CHT to convert O(N^2) DP to O(N)
            */

            deque<pair<pii,int>> dq;        //first pair represents line (m,b) -> y=mx+b
                                            //second element describes last pre[i] whre line is best

            dq.push_back(mp(mp(1-C, dp[C-1][k-1]), pre[C-1]));
            
            FFE(i,C-2,0){
                pii l = mp(-i, dp[i][k-1]);     //note that newly added lines have strictly decreasing slope
                int bef = -1;
                while(!dq.empty() && (bef = intersect(l, dq.front().first)) >= 0){  //pop overriden lines
                    if(bef>=dq.front().second) dq.pop_front();
                    else break;
                }
                
                if(bef >= 0) dq.push_front(mp(l,bef));  //add new line if it is better than the best line at some x>=0
                
                pair<pii,int> opt = dq.back();
                dq.pop_back();
                while(!dq.empty() && dq.back().second >= pre[i]){   //find best line at the current pre[i]
                    opt = dq.back(); dq.pop_back();                 //remove lines that are no longer best for pre[i]<current
                }

                dp[i][k] = pre[i] * (i+opt.first.first) + opt.first.second;     //note that the slope of line (m) == -j
                dq.push_back(opt);
                

                //dp[i][k] = dp[i][k-1];    //naive approach -- TLE
                //F(j,i+1,C){
                //    dp[i][k] = min(dp[i][k], dp[j][k-1] - pre[i]*(j-i));
                //}
            }
        }
        F(i,0,C) ans = min(ans, dp[i][G]);
    }
    
    cout<<ans<<endl;
    
    
}

