#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>

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

vector<int > adj[105];
set<int> resp;
vector<bool> visited;
vector<int> tin, low;
int timer;

//problema do uva: 315 - Network
//Tipo: Finding Articulation Points/Bridges

void dfs(int v, int p){
	visited[v] = 1;
	tin[v] = low[v] = timer++;
	int kids = 0;
	for(int to:adj[v]){
		if(to == p) continue;
		if(visited[to]){
			low[v] = min(low[v], tin[to]);
		}else{
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if(low[to] >= tin [v] && p != -1){
				resp.insert(v);
			}
			kids++;
				
		}
	}
	if (p == -1 && kids > 1)
		resp.insert(v);
}

void find_brigde(int n){
	timer = 0;
	visited.assign(n+2, false);
	tin.assign(n+2, -1);
	low.assign(n+2, -1);
	for(int i = 1; i <= n; i++){
		if(!visited[i])
			dfs(i, -1);
	}
}


int main(){
	//in
	//out
	
	int n, a, b;
	string s;
	while (cin >> n, n){
		
		while (getline(cin, s), s != "0"){
			stringstream valor(s);
			valor >> a;
			while (valor >> b){
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
			
		}
		find_brigde(n);
		cout << (int)resp.size() << "\n";
		for(int i = 0; i <= n; i++){
			adj[i].clear();
		}
		resp.clear();
	}
	
	
}
