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
        int add = (k-1)/(n-1);
        cout<<k+add<<endl;
    }
}

