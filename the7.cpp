#include "the7.h"
using namespace std;
int minDistance(int dist[], bool sptSet[],int V)
{
  
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}





stack<int> dijkstra(int **graph, int src,int destination,int V)
{
    int dist[V]; 
    
    bool sptSet[V]; 
    stack<int> Q;
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    
    dist[src] = 0;
    int array[V] = {0};
    
    for (int count = 0; count < V - 1; count++) {
        
        int u = minDistance(dist, sptSet,V);
        
        
        sptSet[u] = true;

        
        for (int v = 0; v < V; v++){
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                
                dist[v] = dist[u] + graph[u][v];
                array[v]=u;

                
                }
                            
        }
        
       
            
            
    }

    int xxx=destination;
    Q.push(destination);
    
    while(xxx!=src){
        xxx=array[xxx];
        Q.push(xxx);
    }
    Q.push(dist[destination]);
    
    return Q;
}


int** turn(vector<Road> road, int n,int max ){
    
    int r,c;
    int** graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int[n]();
        //fill_n(graph[i], n, max);    
    }
    
    for (const Road& i : road){
        r = i.endpoints.first;
        c = i.endpoints.second;
        graph[r][c]  = i.time;
        graph[c][r] = i.time;
    }
    return graph;
}



void FindRoute(int n, std::vector<Road> roads, int s, int d, int x, int y) {
  // You can change these variables. These are here for demo only.
    int i;
   
  std::vector<int> path;
  int cost = INT_MAX;
  int dist_s_x;
    int dist_s_y;
    int dist_x_y;
    int dist_x_d;
    int dist_y_d;
    int **graph;
    stack<int> Q_s_x;
    stack<int> Q_s_y;
    stack<int> Q_x_y;
    stack<int> Q_y_d;
    stack<int> Q_x_d;
    graph =  turn(roads,n, INT_MAX);
  // Write your code here...
 Q_s_x=dijkstra(graph, s,x,n);
   dist_s_x = Q_s_x.top();
   Q_s_x.pop();

   Q_s_y=dijkstra(graph, s,y,n);
   dist_s_y = Q_s_y.top();
   Q_s_y.pop();

   Q_x_y=dijkstra(graph, x,y,n);
   dist_x_y = Q_x_y.top();
   Q_x_y.pop();

   Q_x_d=dijkstra(graph, x,d,n);
   dist_x_d = Q_x_d.top();
   Q_x_d.pop();

   Q_y_d=dijkstra(graph, y,d,n);
   dist_y_d = Q_y_d.top();
   Q_y_d.pop();

    int t=0;
   if (dist_s_x+dist_x_y+dist_y_d<dist_s_y+dist_x_y+dist_x_d){
       t=Q_s_x.size();
       for(i=0;i<t-1;i++){
           path.push_back(Q_s_x.top());
           Q_s_x.pop();
       }
       Q_s_x.pop();
       t=Q_x_y.size();
       for(i=0;i<t-1;i++){
           path.push_back(Q_x_y.top());
           Q_x_y.pop();
       }
       Q_x_y.pop();
       t=Q_y_d.size();
       for(i=0;i<t;i++){
           path.push_back(Q_y_d.top());
           Q_y_d.pop();
       }
       
      cost = dist_s_x+dist_x_y+dist_y_d;
   }
   else {
       stack<int> Q_y_x;
       while(!Q_x_y.empty()){
           Q_y_x.push(Q_x_y.top());
           Q_x_y.pop();
       }
       t=Q_s_y.size();
       for(i=0;i<t-1;i++){
           path.push_back(Q_s_y.top());
           Q_s_y.pop();
       }
       Q_s_y.pop();
       t=Q_y_x.size();
       for(i=0;i<t-1;i++){
           path.push_back(Q_y_x.top());
           Q_y_x.pop();
       }
       Q_y_x.pop();
       t=Q_x_d.size();
       for(i=0;i<t;i++){
           path.push_back(Q_x_d.top());
           Q_x_d.pop();
       }
        cost = dist_s_y+dist_x_y+dist_x_d;
   }
  // Your output should be like this. You can change this as long as you keep
  // the output format. PrintRange function helps you print elements of
  // containers with iteratos (e.g., std::vector).
  std::cout << cost << " ";
  PrintRange(path.begin(), path.end());
  std::cout << std::endl;
}