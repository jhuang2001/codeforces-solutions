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
#include <string>

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

int main(){
    FAST
    
    int N, W; cin>>N>>W;
    
    vl points; points.resize(N+1,0);
    vl ranks; ranks.resize(W+1,1);
    vl sums; sums.resize(N+1,0);
    vl update; update.resize(W+1,0);
    vl pre; pre.resize(W+1,0);
    
    ranks[0] = 1; update[0] = 1;
    
    ll maxScore = 0;
    
    FE(w,1,W){
        int k; cin>>k;
        F(i,0,k){
            int a; cin>>a;
            
            ll p = points[a];
            points[a]++;
            
            if(points[a]>maxScore){
                maxScore = points[a];
                update[maxScore] = w;
            }
            
            if(update[p] != w){     //only update the prefixes we need to add to sum[a]
                pre[p] += ranks[p] * (w - update[p]);
                update[p] = w;
            }
            if(update[p+1] != w){
                pre[p+1] += ranks[p+1] * (w-update[p+1]);
                update[p+1] = w;
            }
            
            ranks[p]++;     //increment rank of previous score
            
            sums[a] += pre[p] - pre[p+1];   //subtracting the current value of pre[p+1]
                                            //we will be adding pre[p+1] later when we update person a.
        }
    }
    
    FE(i,0,maxScore){
        pre[i] += ranks[i] * (W+1-update[i]);   //update all prefix final values
    }
    
    FE(i,1,N) sums[i] += pre[points[i]];    //add final prefix sum to sums
    
    FE(i,1,N){
        double ans = (double) sums[i] / (double) W;
        printf("%.7f\n", ans);
    }
    
    return 0;
}
