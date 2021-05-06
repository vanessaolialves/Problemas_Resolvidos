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

using namespace std;
typedef pair<int, int> ii;

int dist[102][102];
bool visit[102][102];
int linha[8], coluna[8];
int ly[8] = {1, -1, -1,  1, 1,  1, -1, -1};
int cx[8] = {1,  1, -1, -1, 1, -1, -1,  1};

//Grafos - 11831 - Sticker Collector Robot
// Just Graph Traversal

void bsf(int r, int c, int m, int n){
	
	int w = 8;
	queue<ii> q;
	q.push(ii(0, 0));
	visit[0][0] = 1;
	dist[0][0] = 2;
	for (int i = 0; i < 4; i++){
		linha[i] = m * ly[i];
		coluna[i] = n * cx[i];
	}
	for (int i = 4; i < 8; i++){
		linha[i] = n * ly[i];
		coluna[i] = m * cx[i];
	}
	if (m == 0 || n == 0){
		w = 4;
		linha[2] = linha[4];
		coluna[2] = coluna[4];
		if (m == 0){
			linha[1] = linha[3];
			coluna[1] = coluna[3];
			linha[3] = linha[7];
			coluna[3] = coluna[7];
		}else{
			linha[3] = linha[5];
			coluna[3] = coluna[5];
		}
	}
	if(m == n){
		w = 4;
	}
	
	while(!q.empty()){
		ii u = q.front();
		q.pop();
		for (int i = 0; i < w; i++){
			ii v = u;
			v.f += linha[i];
			v.s += coluna[i];
			if (v.f >= 0 && v.f < r && v.s >= 0 && v.s < c && dist[v.f][v.s] != -1){
				dist[v.f][v.s]++;
				if (!visit[v.f][v.s]){
					visit[v.f][v.s] = 1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	
	int t, r, c, m, n, w, x, y, ans[2];
	
	scanf("%d", &t);
	for (int k = 1; k <= t; k++){
		scanf("%d %d %d %d", &r, &c, &m, &n);
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				dist[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		scanf("%d", &w);
		for (int i = 0; i < w; i++){
			scanf("%d %d", &x, &y);
			dist[x][y] = -1;
			visit[x][y] = 1;
		}
		bsf(r, c, m, n);
		ans[0] = 0;
		ans[1] = 0;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (dist[i][j] > 0){
					ans[dist[i][j]%2]++;
				}
			}
		}
		printf("Case %d: %d %d\n", k, ans[0], ans[1]);
		
	}
	
}

