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
#include <iomanip>

//macros
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define abs(a) ((a) < 0 ? -(a) : (a))
#define F(i, L, R) for (int i = L; i < R; i++)
#define FE(i, L, R) for (int i = L; i <= R; i++)
#define FF(i, L, R) for (int i = L; i > R; i--)
#define FFE(i, L, R) for (int i = L; i >= R; i--)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define PI 3.1415926535897932384626
#define mp make_pair
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);

using namespace std;

//typedef
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

ll MOD = 1000000007;

ll pow(ll a, ll b){
    if(b == 0) return 1;

    ll ret = pow(a,b/2);
    ret = (ret*ret) % MOD;

    if(b % 2 == 1) 
        ret = (a*ret) % MOD;
    
    return ret;
}


ll fac[200001];
ll infac[200001];
void calcFac(int n){
    if(n==0){
        fac[0] = 1;
    }else{
        calcFac(n-1);
        fac[n] = (fac[n-1] * n) % MOD;
    }
    infac[n] = pow(fac[n], MOD-2);
}

ll C(int n, int k){
    if(k<0 || n<k) return 0;

    ll ret = (fac[n] * infac[k]) % MOD;
    return (ret * infac[n-k]) % MOD;
}

int main()
{
    
    calcFac(200001);
    int T; cin >> T;

    FE(test,1,T){
        int N, L, R;
        cin >> N >> L >> R;

        ll kmax = min(1-L, R-N);

        ll ans = (C(N, N/2) * kmax) % MOD;

        if(N % 2 == 1){
            ans += (C(N, N/2 + 1) * kmax);
            ans %= MOD;
        }

        FE(k, kmax+1, kmax + N){
            int l = max(1, L+k);
            int r = min(N, R-k);

            ll c = C(r-l+1, N/2 - l + 1);

            if(N % 2 == 1) c = (c + C(r-l+1, N/2 - l + 2)) % MOD;

            ans = (ans + c) % MOD;
        }

        if (ans < 0) ans += MOD;

        cout << ans << endl;

    }
}