#include<bits/stdc++.h>
using namespace std;


char mtx[100][100];
int row, col;
struct node
{
    int r, c;
    int dis;
}st, ed;

queue<node> q;

bool used[100][100];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int bfs(node st, node ed){
    
    q.push(st);

    node cur, nxt;
    while (!q.empty()){
        cur = q.front();
        
        if (cur.r == ed.r and cur.c == ed.c){
            return cur.dis;
        }
        for (int k = 0 ; k < 4 ; k++){
            
            nxt = cur;
            nxt.r += dr[k];
            nxt.c += dc[k];
            nxt.dis++;
            
            if (nxt.r < row and nxt.r >= 0 
            and nxt.c < col and nxt.c >= 0 and !used[nxt.r][nxt.c]){

                used[nxt.r][nxt.c] = 1;
                if (mtx[nxt.r][nxt.c] != '#'){
                    q.push(nxt);
                }
            }
        }
        
        q.pop();
        cerr << q.size() << "\n";
    }
    return -1;
}



int main(){

    cin >> row >> col;
    for (int j = 0 ; j < row ; j++){
        for (int i = 0 ; i < col ; i++){
            cin >> mtx[j][i];
            if (mtx[j][i] == 'S'){
                st.r = j;
                st.c = i;
            }
            else if (mtx[j][i] == 'E'){
                ed.r = j;
                ed.c = i;
            }
        }
    }
    cout << bfs(st, ed);
    

}
