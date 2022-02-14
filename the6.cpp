#include "the6.h"
// Don't add any additional includes

/*
  N: Number of racers
  updates: Updates you have heard
*/
using namespace std;
class Graph {
    int vertices;
    vector<int>* adj;
    
    void DFS(int vertices, bool visit[],  queue<int>& Q);
    bool isCyclicUtil(int v, bool visited[],  queue<int>& Q,bool *recStack,int& berker);
public:
    Graph(int vertices);
    void clearEdge(int v);
    void addEdge(int v,int w);
    void topo(std::vector<int> &ans);
     bool isCyclic(std::vector<int> &ans);
};

Graph::Graph(int vertices){
    this->vertices=vertices;
    adj = new vector<int>[vertices];
    
    
}

void Graph::clearEdge(int v){
    adj[v].push_back(0);
}

void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}
bool Graph::isCyclicUtil(int v, bool visited[],queue<int>& Q,bool *recStack,int& berker )
{
    if(visited[v] == false)
    {
       int p=-1;
       int r=-1;
        visited[v] = true;
        recStack[v] = true;
        vector<int>::iterator i = adj[v].begin();
        int a=0;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, Q,recStack,berker) ){
                r=*i;
                if(v==Q.front()){
                    Q.push(r);
                    Q.push(v);
                    berker=-1;
                }
                if (berker!=-1)
                    Q.push(r);
                return true;
            }
                
            else if (recStack[*i]){
                p=*i;
                Q.push(p);
                return true;
            }
            a++;  
        }

    }
    recStack[v] = false;  
    //Q.pop();
    return false;
}
void clear( std::queue<int> &q )
{
   std::queue<int> empty;
   std::swap( q, empty );
}

bool Graph::isCyclic(std::vector<int> &ans)
{
    
    int flag=0;
    bool *visited = new bool[vertices]();
    bool *recStack = new bool[vertices]();
    queue<int> Q;
    int berker=-2;
    for(int i = 0; i < vertices; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    
    for(int i = 0; i < vertices; i++){
        clear(Q);
        if (isCyclicUtil(i, visited, Q,recStack, berker) )
            flag=1;
        if (flag==1)
            break;
            }
    while(Q.empty()==false){
        ans.insert(ans.begin(),Q.front());
        
        //xxx=Q.front();
            
            
        Q.pop();
    }
     

    if (flag==1)
        return true;
    else
        return false;
}





void Graph::DFS(int vertices, bool visit[],queue<int>& Q){
    visit[vertices]  = true;
    vector<int>::iterator i = adj[vertices].begin();
     for (i = adj[vertices].begin(); i != adj[vertices].end(); ++i){
         if (!visit[*i])
            DFS(*i, visit, Q);
     }
        
    Q.push(vertices);
}

void Graph::topo(std::vector<int> &ans){
    queue<int> Q;
    bool* visit = new bool[vertices]();
    for(int i=0;i<vertices;i++)
        visit[i] = false;

    for(int i = 0;i<vertices;i++){
        if(visit[i]==false)
            DFS(i,visit,Q);
    }
    while(Q.empty()==false){
        ans.insert(ans.begin(),Q.front());
        Q.pop();
    }
    
}



std::pair<bool, std::vector<int>>
RaceResult(int N, std::vector<std::pair<int, int>> updates) {
    int leng=updates.size();
    int i=0;
    Graph g_race(N);
    
    std::vector<int> ans;
    std::vector<int> ans1;
    
    
    while(i<leng){
        g_race.addEdge(updates[i].first,updates[i].second);
        i++;
    }
    if (g_race.isCyclic(ans1))
        return {false,ans1};
    g_race.topo(ans);
  return {true, ans}; // This is a dummy return value. YOU SHOULD CHANGE THIS!
}