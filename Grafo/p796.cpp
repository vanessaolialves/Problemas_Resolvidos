#include<iostream>
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

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef pair<ii, int> iii;
typedef pair<int, string> is;
typedef pair<ii, is> iiis;
typedef pair<ic, int> ici;
typedef pair<string, string> ss;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> tin, low;
vector<ii> is_bridge;
int timer;

	/**
	  *Problema uva - 796 - Critical Links
	  *Grafos
	  *Finding Articulation Points/Bridges
	  **/

void dfs(int v, int p){
	visited[v] = 1;
	tin[v] = low[v] = timer++;
	for(int to:adj[v]){
		if(to == p) continue;
		if(visited[to]){
			low[v] = min(low[v], tin[to]);
		}else{
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if(low[to] > tin [v]){
				if(to > v){
					is_bridge.push_back(ii(v, to));
				}else{
					is_bridge.push_back(ii(to, v));
				}
			}
				
		}
	}
}

void find_brigde(int n){
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for(int i = 0; i < n; i++){
		if(!visited[i])
		dfs(i, -1);
	}
}


int main(){
	//in
	int n, a, b, c;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			adj.push_back(vector<int> ());
		}
		for(int i = 0; i < n; i++){
			scanf("%d (%d)", &a, &c);
			for(int i = 0; i < c; i++){
				scanf("%d", &b);
				adj[a].push_back(b);
			}
		}
		find_brigde(n);
		sort(is_bridge.begin(), is_bridge.end());
		printf("%d critical links\n", (int)is_bridge.size());
		for(ii i:is_bridge){
			printf("%d - %d\n", i.f, i.s);
		}
		printf("\n");
		is_bridge.clear();
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		adj.clear();
	}
}


