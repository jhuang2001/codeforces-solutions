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

struct seg{
    int l,r,w;
};

struct tnode{
    int min, val;
};

vector<tnode> tree;
vector<seg> sgs;
int INF = 100000000+9;


void upd(int v, int tl, int tr, int l, int r, int add){
    if(l>r){
        return;
    }

    if(tl == l && tr == r){
        tree[v].val += add;
        return;
    }

    int m = (tl+tr)/2;
    upd(2*v, tl, m, l, min(r, m), add);
    upd(2*v+1, m+1, tr, max(m+1, l), r, add);

    tree[v].min = min(tree[2*v].min+tree[2*v].val, tree[2*v+1].min+tree[2*v+1].val);
}

int get(int v, int tl, int tr, int l, int r){
    if(l > r) return INF;

    if(l==tl && r==tr) return tree[v].val + tree[v].min;

    int m = (tl + tr)/2;

    int lmin = get(2*v, tl, m, l, min(m, r));
    int rmin = get(2*v+1, m+1, tr, max(m+1, l), r);

    return tree[v].val + min(lmin, rmin);
}

int N, M;
int get(int l, int r){
    return get(1,1,M,l,r);
}

int main()
{
    cin >> N >> M;

    sgs.resize(N);
    tree.resize(4*M + 1);

    F(s,0,N){
        int l, r, w;
        cin >> l >> r >> w;
        sgs[s].l = l;
        sgs[s].r = r-1;
        sgs[s].w = w;
    }

    sort(sgs.begin(), sgs.begin()+N, [](const seg &a, const seg &b) -> bool {return a.w < b.w;});

    int l = 0;
    int r = 0;

    int ans = INT32_MAX;

    FE(i,0,4*M){
        tree[i].min = tree[i].val = 0;
    }

    while(r < N){
        bool found = false;
        while(get(1,M-1) == 0 && r < N){
            upd(1,1,M, sgs[r].l, sgs[r].r, 1);
            r++;
        }
        if(get(1,M-1) > 0) found = true;
        while(get(1,M-1) > 0 && l < r){
            upd(1,1,M, sgs[l].l, sgs[l].r, -1);
            l++;
        }
        
        if(found) ans = min(ans, sgs[r-1].w - sgs[l-1].w);
    }

    cout<<ans<<endl;
}