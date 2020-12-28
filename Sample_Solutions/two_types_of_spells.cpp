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


int main(){
    FAST
    
    int n; cin>>n;
    ll sum = 0;
    
    int l = 0;
    set<int> f1,f2,l1,l2;
    F(i,0,n){
        int a,b;
        cin>>a>>b;
        if(b>0){
            sum+=b;
            if(a==1){
                l1.insert(b);
                l++;
            }
            else f1.insert(b);
        }else{
            if(a==1){
                if(l1.count(-b)>0){
                    l1.erase(-b);
                    sum+=b;
                }else{
                    l2.erase(-b);
                    sum+=2*b;
                }
                l--;
            }else{
                if(f1.count(-b)>0){
                    f1.erase(-b);
                    sum+=b;
                }else{
                    f2.erase(-b);
                    sum+=2*b;
                }
            }
        }
        
        if(f2.size()>0){
            f1.insert(*f2.begin());
            sum-=*f2.begin();
            f2.erase(f2.begin());
        }
        
        if(l2.size()>0){
            l1.insert(*l2.begin());
            sum-=*l2.begin();
            l2.erase(l2.begin());
        }
        
        int m;
        while(l1.size()>1 && f1.size()>0 && f2.size()+l2.size()<l){
            if(*l1.rbegin() > *f1.rbegin()){
                m = *l1.rbegin(); l1.erase(m);
                l2.insert(m);
            }else{
                m = *f1.rbegin(); f1.erase(m);
                f2.insert(m);
            }
            sum+=m;
        }
        
        while(f1.size()>0 && f2.size()+l2.size()<l){
            m = *f1.rbegin(); f1.erase(m);
            f2.insert(m);
            sum+=m;
        }
        
        while(l1.size()>1 && f2.size()+l2.size()<l){
            m = *l1.rbegin(); l1.erase(m);
            l2.insert(m);
            sum+=m;
        }
        
        cout<<sum<<endl;
    }
    
}

