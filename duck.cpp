#include<bits/stdc++.h>
using namespace std;

map<string, int> m;
map<int, string> mr;
int top;

int n;
string dep, des;
int st, ed;
bool access[10000][10000];
bool used[1000000];


struct node
{
    int pos;
    int from;
    int dis;
};

vector<node> v, stk;

void stk_push(node data){
    stk.push_back(data);
    node x = data;
    while (x.from >= 0){
        x = v[x.from];
        stk.push_back(x);
    }
    return;
}

void bfs(int st, int ed){
    node cur, nxt;
    cur.pos = st;
    cur.from = -1;
    cur.dis = 0;
    v.push_back(cur);
    for (int i = 0 ; i < v.size() ; i++){
        
        cur = v[i];
        
        if (cur.pos == ed){
            stk_push(cur);
            for (int j = stk.size()-1 ; j > 0 ; j--){
                cout << mr[stk[j].pos] << ' ' << mr[stk[j-1].pos] << '\n';
            }
            return;
        }

        for (int j = 0 ; j < top ; j++){
            if (access[cur.pos][j] and !used[j]){
                nxt = cur;
                nxt.from = i;
                nxt.pos = j;
                used[j] = 1;
                nxt.dis++;
                v.push_back(nxt);
            }
        }
    }
    cout << "No route\n";
    return;
}




int main(){

    ios_base::sync_with_stdio(0), cin.tie(0);

    while (cin >> n){
        // memset
        m.clear();
        mr.clear();
        v.clear();
        stk.clear();
        memset(used, 0, sizeof(used));
        memset(access, 0, sizeof(used));
        top = 0;
        
        // 建表
        for (int i = 0 ; i < n ; i++){
            cin >> dep >> des;
            if (!m.count(dep)){
                m[dep] = top;
                top++;
            }
            if (!m.count(des)){
                m[des] = top;
                top++;
            }
            access[m[dep]][m[des]] = 1;
            access[m[des]][m[dep]] = 1;
        }
        for (auto s: m){
            mr[s.second] = s.first;
        }
        


        cin >> dep >> des;
        st = m[dep];
        ed = m[des];
        bfs(st, ed);
        cout << '\n';
    }

    return 0;
    
}