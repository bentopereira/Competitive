#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 501;

int pot[50];
int used[N];


int main(){
    rvr(n);
    vll a(n);
    fr(i, n) scanf("%lld", &a[i]);
    ll ans = -1;
    fr(i, n){
        fr(j, n){
            if(j <= i) continue;
            fr(k, n){
                if(k <= j) continue;
                ans = max(ans, ((a[i]|a[j])|a[k]));
            }
        }
    }
    ll plc = 0;
    fr(i, min(n, 3)) plc ^= a[i];
    ans = max(ans, plc);
    printf("%lld\n", ans);
}
