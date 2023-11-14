#include <iostream> 
#include <stack>
#include <list>
using namespace std;

class Graph{
    private:
        int V;
        list<int> *adj;
    public:
        Graph(int V){this->V=V; adj= new list<int>[V];};
        void addEdge(int v, int w);
        void DFS(int s);
};
void Graph::DFS(int s){
    bool *visited= new bool[V];
    for (int i=0;i<V;i++){
        visited[i]=false;
    }
    stack<int> stack;
    stack.push(s);
    while(!stack.empty()){
        s = stack.top();
        stack.pop();
        if(!visited[s]){
            cout<<s<<endl;
            visited[s]=true;
        }
        for(list<int>::iterator i = adj[s].begin();i!=adj[s].end();++i){
            if(visited[*i]){
                stack.push(*i);
            }
        }
    }
}

void Graph::addEdge(int v, int w){
adj[v].push_back(w);

}
int main(){
Graph g(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,0);
g.addEdge(2,0);
g.DFS(0);
}