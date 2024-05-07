#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct Graph{

     int V;
     vector<vector<int>>adj;
};

void add(Graph& graph ,int u , int v){
    graph.adj[u].push_back(v);
    graph.adj[v].push_back(u);
}

void DFSUtil(const Graph& graph , int v , vector<bool>& visited){
      visited[v] = true;
      cout<< v <<" ";
      
      for(int u : graph.adj[v]){
           if(!visited[u]){
              DFSUtil(graph , u , visited);
           }
    }     
}

void DFS(const Graph& graph){
     vector<bool>visited(graph.V,false);
     for(int v = 0 ; v < graph.V ; ++v){
         if(!visited[v]){
             DFSUtil(graph , v , visited);
         }
     }
}

void BFS(const Graph& graph){
    vector<bool>visited(graph.V , false);
    queue<int>q;
    
    for(int v=0 ; v<graph.V ; v++){
        if(!visited[v])
            visited[v] = true;
            q.push(v);
            
           while(!q.empty()){
             	int u = q.front();
             	q.pop();
             	cout << u;
             	
             	for(int adj: graph.adj[u]){
             	     if(!visited[u]){
             	          visited[u] = true;
             	          q.push(adj);
             	     }
             	}
             
        }
    }
}

int main(){
   int V,E;
   cout<<"Enter number of vertices";
   cin >> V;
   
   cout<<"Enter number of Edges";
   cin >> E;
   
   Graph graph;
   graph.V = V;
   graph.adj.resize(V);
   
   cout<<"Enter the edges {Format: Vertex1 Vertex2}"<<endl;
   int u,v;
   for(int i = 0; i<E ; i++){
     cin>>u>>v;
     add(graph,u,v);
   }
   
   cout<<"The DFS is "<<endl;
   DFS(graph);
   
   cout<<"The BFS is"<<endl;
   BFS(graph);
   
   return 0;
}







