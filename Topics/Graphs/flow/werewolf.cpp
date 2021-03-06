//ICPC live archive 7896
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 112
#define MAXM 1123

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


int frv[MAXN], sndv[MAXN];

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int to[MAXM], nxt[MAXM], n;

int freq[MAXN];

ll cap[MAXM];

vi adj[MAXN];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

ll dfs(int u, ll f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			ll df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

ll dinic(int s, int t) {
	ll result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}

int main() {
	while(scanf("%d", &n) == 1){
		int ans = 0;
		ms(freq, 0);
		frr(i, n){
			scanf("%d%d", &frv[i], &sndv[i]);
			freq[frv[i]]++;
			freq[sndv[i]]++;
		}
		frr(i, n){
			int aa = frv[i], bb = sndv[i];
			init();
			frr(j, n){
				if(i == j) {add(i + n, 2*n + 1, freq[i]); continue;}
				add(0, j, 1);
				if(j == aa || j == bb){
					add(n + j, 2*n + 1, freq[i] - 2);
				}
				else add(n + j, 2*n + 1, freq[i] - 1);
				int aaa = frv[j], bbb = sndv[j];
				if(aaa == i || bbb == i) {add(j, i + n, 1); continue;}
				add(j, aaa + n, 1);
				add(j, bbb + n, 1);
			}
			int plc = dinic(0, 2*n + 1);
			//printf("dinicao = %d\n", plc);  
			if(plc != n - 1) ans++;
		}
		printf("%d\n", ans);
	}
}








