#include<bits/stdc++.h>
using namespace std;

int ca, cb, n;

struct node{
    int a, b;
    int from; // 回溯解
    int dis; // 利於檢測
    string mod; // 操作
};

bool used[1005][1005]; // 判斷是否出現重複狀態
vector<node> v;
stack<node> sta;

void sta_push(int f){ //從終點開始反向堆疊stack
    if (f > 0)sta.push(v[f]);
    if (v[f].from > 0){
        sta_push(v[f].from);
    }
    return;
}

void bfs(int ca, int cb, int n){
    //memset
    v.clear();
    memset(used, 0, sizeof(used));
    node cur, nxt;
    cur.a = 0;
    cur.b = 0;
    cur.dis = 0;
    cur.from = -1;
    v.push_back(cur);

    for (int i = 0 ; i < v.size() ; i++){
        cur = v[i];

        if (cur.a == n or cur.b == n){
            sta.push(cur);
            break;
        }

        // fill A
        nxt = cur;
        nxt.a = ca;
        if (!used[nxt.a][nxt.b]){
            used[nxt.a][nxt.b] = 1;
            nxt.dis++;
            nxt.from = i;
            nxt.mod = "fill A";
            v.push_back(nxt);
        }

        // fill B
        nxt = cur;
        nxt.b = cb;
        if (!used[nxt.a][nxt.b]){
            used[nxt.a][nxt.b] = 1;
            nxt.dis++;
            nxt.from = i;
            nxt.mod = "fill B";
            v.push_back(nxt);
        }

        // empty A
        nxt = cur;
        nxt.a = 0;
        if (!used[nxt.a][nxt.b]){
            used[nxt.a][nxt.b] = 1;
            nxt.dis++;
            nxt.from = i;
            nxt.mod = "empty A";
            v.push_back(nxt);
        }

        // empty B
        nxt = cur;
        nxt.b = 0;
        if (!used[nxt.a][nxt.b]){
            used[nxt.a][nxt.b] = 1;
            nxt.dis++;
            nxt.from = i;
            nxt.mod = "empty B";
            v.push_back(nxt);
        }

        // pour A B
        nxt = cur;
        nxt.b += nxt.a;
        if (nxt.b > cb){
            nxt.a = nxt.b-cb;
            nxt.b = cb;
        }
        else {
            nxt.a = 0;
        }
        if (!used[nxt.a][nxt.b]){
            used[nxt.a][nxt.b] = 1;
            nxt.dis++;
            nxt.from = i;
            nxt.mod = "pour A B";
            v.push_back(nxt);
        }

        // pour B A
        nxt = cur;
        nxt.a += nxt.b;
        if (nxt.a > ca){
            nxt.b = nxt.a-ca;
            nxt.a = ca;
        }
        else {
            nxt.b = 0;
        }
        if (!used[nxt.a][nxt.b]){
            used[nxt.a][nxt.b] = 1;
            nxt.dis++;
            nxt.from = i;
            nxt.mod = "pour B A";
            v.push_back(nxt);
        }
    }
    
    sta_push(sta.top().from);

    while (!sta.empty()){ // 利用stack從上層輸出到下層(起點~終點)
        cout << sta.top().mod << '\n';
        sta.pop();
    }

    cout << "success\n";
    return;
}

int main(){
    while (cin >> ca >> cb >> n){
        bfs(ca, cb, n);
    }
    return 0;
}
