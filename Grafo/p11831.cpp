#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<utility>
#include<cmath>
#include<iomanip>
#include<list>
#include<map>
#include<set>
#include<sstream>
#include<algorithm>
#include<deque>
#include<fstream>

#define f first
#define s second
#define pi 3.14159

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

//Grafo - 11906 - Knight in a war Grid
// Just Graph Traversal

char mat[102][102], vec[50005];
int ly[4] ={-1, 0, 1,  0};
int cx[4] ={ 0, 1, 0, -1};

struct robot{
    int l, c, pos;
    robot(){};
};
struct robot rbt;

void criar(int a, int b, int d){
    rbt.l = a; 
    rbt.c = b; 
    rbt.pos = 0;
    if(d == 'L'){
        rbt.pos++;
    }else if(d == 'S'){
        rbt.pos += 2;
    }else if(d == 'O'){
        rbt.pos += 3;
    }
    cout << "aqui rbt cria\n";
}

int andar(int w){
    int ans = 0;
    for(int i = 0; i < w; i++){
        char b = vec[i];
        if(b == 'D'){
            rbt.pos = (rbt.pos + 1)%4;
        }else if(b == 'E'){
            rbt.pos = (rbt.pos - 1)%4;
        }else{
            int kl = rbt.l + ly[rbt.pos];
            int kc = rbt.c + cx[rbt.pos];
            if(mat[kl][kc] != '#'){
                rbt.l = kl;
                rbt.c = kc;
                if(mat[kl][kc] == '*'){
                    ans++;
                }
                mat[kl][kc] = '.';
            }
        }
    }
    return ans;
}

int main(){
    int n, m, w;
    for(int i = 0; i < 102; i++){
        mat[0][i] = mat[i][0] = '#';
    }
    while (scanf("%d %d %d", &n, &m, &w), n || m || w)
    {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf("%c", &mat[i][j]);
                if(mat[i][j] >= 'L' && mat[i][j] <= 'S'){
                    criar(i, j, mat[i][j]);
                }
            }
            mat[i][m+1] = '#';
        }
        cout << "aqui 1\n";
        for(int i = 1; i <= m+1; i++){
            mat[n+1][i] = '#';
        }
        cout << "aqui 2\n";
        for(int i = 0; i < w; i++){
            scanf("%c", &vec[i]);
        }
        cout << "aqui 3\n";
        int ans = andar(w);
        printf("%d\n", ans);
        cout << "aqui 4\n";
    }
}
