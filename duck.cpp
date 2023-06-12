#include<bits/stdc++.h>
using namespace std;



struct node
{
    string w;
    int dis;
};

string s;
string st, ed;

set<string> dic;

queue<node> q;
map<string, bool> used;

int bfs(string st, string ed){

    while (!q.empty()){
        q.pop();
    }
    for (auto a:used){
        used[a.first] = 0;
    }


    node cur, nxt;
    cur.w = st;
    cur.dis = 0;

    q.push(cur);    
    while (!q.empty()){
        cur = q.front();
        if (cur.w == ed){
            return cur.dis;
        }

        
        for (int i = 0 ; i < cur.w.size() ; i++){
            nxt = cur;
            for (char c = 'a' ; c <= 'z' ; c++){
                nxt.w[i] = c;
                if (dic.count(nxt.w) and !used[nxt.w]){
                    used[nxt.w] = 1;
                    nxt.dis = cur.dis+1;
                    q.push(nxt);
                }
            }
        }
        q.pop();
    }
    return -1;
}


int main(){
    
    while (cin >> s){
        if (s == "*"){
            break;
        }
        used[s] = 0;
        dic.insert(s);
    }
    while (cin >> st){
        if (st == " "){
            return 0;
        }
        cin >> ed;
        cout << st << " " << ed << " " << bfs(st, ed) << '\n';
    }
    
}