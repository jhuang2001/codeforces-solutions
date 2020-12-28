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

int manDist(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second-b.second);
}

int main(){
    FAST
    
    int T; cin>>T;
    cin.ignore(1000,'\n');
    
    F(CASE,0,T){
        int n,k; cin>>n>>k;
        
        vii data;
        F(i,0,n){
            int x,y; cin>>x>>y;
            data.push_back(mp(x,y));
        }
        
        bool doable = false;
        F(i,0,n){
            bool center = true;
            F(j,0,n){
                if(manDist(data[i], data[j])>k){
                    center = false;
                    break;
                }
            }
            if(center){
                doable = true;
                break;
            }
        }
        if(doable) cout<<1<<endl;
        else cout<<-1<<endl;
    }
    
    
    
}

