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


int main(){
    FAST
    
    int T; cin>>T;
    cin.ignore(1000,'\n');
    
    F(CASE,0,T){
        vector<vector<char>> d;
        int n; cin>>n;
        cin.ignore(1000,'\n');
        
        int k = 0;
        d.resize(n);
        F(i,0,n){
            F(j,0,n){
                char c; cin>>c;
                d[i].push_back(c);
                if(c != '.') k++;
            }
            cin.ignore(1000,'\n');
        }
        
        vector<vector<bool>> s;
        vector<vector<bool>> s2;
        F(offset,0,3){
            int swaps = 0;
            bool found = false;
            s.clear();
            s.resize(n);
            F(i,0,n){
                s[i].resize(n, false);
            }
            
            F(r,0,n){
                F(c,0,n){
                    int m = (r-c)%3;
                    if(m<0)m+=3;
                    if(m==offset && d[r][c] == 'X'){
                        
                        if(r>=2 && d[r-2][c] == 'X' && d[r-1][c] == 'X') s[r][c] = true;
                        else if(r>=1 && r<=n-2 && d[r-1][c] == 'X' && d[r+1][c] == 'X') s[r][c] = true;
                        else if (r<=n-3 && d[r+2][c] == 'X' && d[r+1][c] == 'X') s[r][c] = true;
                        
                        else if(c>=2 && d[r][c-2] == 'X' && d[r][c-1] == 'X') s[r][c] = true;
                        else if(c>=1 && c<=n-2 && d[r][c-1] == 'X' && d[r][c+1] == 'X') s[r][c] = true;
                        else if (c<=n-3 && d[r][c+1] == 'X' && d[r][c+2] == 'X') s[r][c] = true;
                        
                        if(s[r][c] == true) swaps++;
                    }
                }
            }
            
            F(off2,0,3){
                int oswaps = 0;
                if(off2 == offset) continue;
                s2.clear();
                s2.resize(n);
                F(i,0,n){
                    s2[i].resize(n, false);
                }
                F(r,0,n){
                    F(c,0,n){
                        int m = (r-c)%3;
                        if(m<0)m+=3;
                        if(m==off2 && d[r][c] == 'O'){
                            
                            if(r>=2 && d[r-2][c] == 'O' && d[r-1][c] == 'O') s2[r][c] = true;
                            else if(r>=1 && r<=n-2 && d[r-1][c] == 'O' && d[r+1][c] == 'O') s2[r][c] = true;
                            else if (r<=n-3 && d[r+2][c] == 'O' && d[r+1][c] == 'O') s2[r][c] = true;
                            
                            else if(c>=2 && d[r][c-2] == 'O' && d[r][c-1] == 'O') s2[r][c] = true;
                            else if(c>=1 && c<=n-2 && d[r][c-1] == 'O' && d[r][c+1] == 'O') s2[r][c] = true;
                            else if (c<=n-3 && d[r][c+1] == 'O' && d[r][c+2] == 'O') s2[r][c] = true;
                            
                            if(s2[r][c] == true) oswaps++;
                        }
                    }
                }
                if(swaps+oswaps<=k/3){
                    found = true;
                    break;
                }
            }
            
            if(found)break;
        }
        
        F(r,0,n){
            F(c,0,n){
                char out = d[r][c];
                if(s[r][c]) out = 'O';
                if(s2[r][c]) out = 'X';
                cout<<out;
            }
            cout<<endl;
        }
    }
    
    
    
}

