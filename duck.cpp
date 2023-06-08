#include<bits/stdc++.h>
using namespace std;

struct cor
{
    int r, c, l;
    int dis;
};
int len_r, len_c, len_l;
char maze[35][35][35];

int dr[] = {1, 0, 0, -1, 0, 0},
dc[] = {0, 1, 0, 0, -1, 0},
dl[] = {0, 0, 1, 0, 0, -1};

bool used[35][35][35];

cor st, ed;
queue<cor> q;


int bfs(){
    
    cor cur, nxt;
    q.push(st);

    while (!q.empty()){

        cur = q.front();
        
        if (cur.r == ed.r
        and cur.c == ed.c
        and cur.l == ed.l){
            return cur.dis;
        }

        for (int k = 0 ; k < 6 ; k++){
            nxt = cur;
            nxt.r += dr[k];
            nxt.c += dc[k];
            nxt.l += dl[k];
            nxt.dis++;

            if (!used[nxt.l][nxt.r][nxt.c]
            and nxt.l >= 0 and nxt.l < len_l
            and nxt.r >= 0 and nxt.r < len_r
            and nxt.c >= 0 and nxt.c < len_c
            and maze[nxt.l][nxt.r][nxt.c] != '#'){
                used[nxt.l][nxt.r][nxt.c] = 1;
                q.push(nxt);
            }
        }
        q.pop();
    }

    return -1;
}

int main(){
    
    while(cin >> len_l >> len_r >> len_c){
        
        if (!len_l and !len_c and !len_r){
            return 0;
        }

        for (int k = 0 ; k < 35 ; k++){
            for (int j = 0 ; j < 35 ; j++){
                for (int i = 0 ; i < 35 ; i++){
                    maze[k][j][i] = 0;
                    used[k][j][i] = 0;
                }
            }
        }

        while (!q.empty()){
            q.pop();
        }

    
        for (int k = 0 ; k < len_l ; k++){
            for (int j = 0 ; j < len_r ; j++){
                for (int i = 0 ; i < len_c ; i++){
                    cin >> maze[k][j][i];
                    if (maze[k][j][i] == 'S'){
                        st.r = j;
                        st.c = i;
                        st.l = k;
                    }
                    else if (maze[k][j][i] == 'E'){
                        ed.r = j;
                        ed.c = i;
                        ed.l = k;
                    }
                }
            }
        }

        if (bfs() == -1){
            cout << "Trapped!\n";
        }
        else {
            cout << "Escaped in " << bfs() << " minute(s).\n";
        }
    }

    


    
}
