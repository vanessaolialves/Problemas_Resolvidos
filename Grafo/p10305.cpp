#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<map>

#define f first
#define s second
#define mod  1000000007
#define in freopen("entrada.txt", "r",stdin);
#define out freopen("saida.txt", "w",stdout);

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef pair<ii, int> iii;
typedef pair<int, string> is;
typedef pair<ii, is> iiis;
typedef pair<ic, int> ici;
typedef pair<string, string> ss;

int tempo, inicio[105];
ii fim[105];
bool visited[105];
vector<int> adj[105];

//10305 - Ordering Tasks
// Grafos - Topological Sort

void dfs(int u){
	visited[u] = true;
	tempo++;
	inicio[u] = tempo;
	for (int v:adj[u]){
		if (!visited[v]){
			dfs(v);
			
		}
	}
	tempo++;
	fim[u].f = tempo;
}

bool cmp(ii & a, ii & b){
	return a.f > b.f;
}


int main(){
	
	//in
	int n, m, a, b;
	while (scanf("%d %d", &n, &m), n || m){
		for (int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}
		for (int i = 0; i <= n; i++){
			fim[i].f = -1;
			fim[i].s = i;
			visited[i] = false;
		}
		tempo = 0;
		for (int i = 1; i <= n; i++){
			if (!visited[i]){
				dfs(i);
			}
		}
		sort(fim+1, fim+n+1, cmp);
		printf("%d",fim[1].s);
		for (int i = 2; i <= n; i++){
			printf(" %d", fim[i].s);
		}
		printf("\n");
		for (int i = 1; i <= n; i++){
			adj[i].clear();
		}
	}
}
