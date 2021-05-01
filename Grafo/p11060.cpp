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

vector<int> adj[105];
int direcao[105];

bool visited[105];
queue<int> dq;

//11060 - Beverages
// Grafos - Topological Sort

void topologicosort(int n){
	
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < n; i++){
		if (direcao[i] == 0)
			q.push(i);
	}
	
	while (!q.empty()){
		int u = q.top();
		q.pop();
		dq.push(u);
		visited[u] = true;
		for(int v:adj[u]){
			if (!visited[v]){
				direcao[v]--;
				if (direcao[v] == 0)
					q.push(v);
			}
		}
	}
	
	
}


int main(){
	//in
	int n, m, k = 1;
	string a, b, c;
	string local[105];
	map<string, int> city;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> c;
			city[c] = i;
			local[i] = c;
			direcao[i] = 0;
			visited[i] = false;
		}
		cin >> m;
		for (int i = 0; i < m; i++){
			cin >> a >> b;
			adj[city[a]].push_back(city[b]);
			direcao[city[b]]++;
		}
		topologicosort(n);
		cout << "Case #" << k++ << ": Dilbert should drink beverages in this order: " << local[dq.front()];
		dq.pop();
		while(!dq.empty()){
			cout << " " << local[dq.front()];
			dq.pop();
		}
		cout << ".\n\n";
		for (int i = 0; i < n; i++){
			adj[i].clear();
		}
		city.clear();
	}
}
