/* 
Assignment No.7
Title:- Graph: Minimum Spanning Tree
 
Problem Statement:-Represent a graph of your college campus using adjacency list /adjacency matrix. 
Nodes should represent the various departments/institutes and links should represent the distance between them. 
Find minimum spanning tree:
a) Using Kruskal’s algorithm.
b) Using Prim’s algorithm.

*/

//code for Prims algorithm

#include<iostream>
#define SIZE 20
#define INFINITY 99
using namespace std;
class MST {
    private :
    int G [SIZE ][SIZE ],nodes ;
    public :
    MST();
    void Prim ();
    void get_data();


};
MST ::MST (){
    for (int  i = 0; i < SIZE ; i++)
    {
        for (int  j = 0; j < SIZE; j++)
        {
            G[i][j]=0;
        }
        
    }
    
}
void MST :: Prim ()
{
    int select [SIZE ],i,j,k;
    int min_dist ,v1 ,v2 ,total = 0;
    cout<<"\nThe minimum spanning tree "<<endl;
    for (int i = 0; i<nodes ; i++)
    {
        select[i]= 0;
        select[0]=1;
    }
    for (int k = 0; k <nodes-1 ; k++)
    {
        min_dist = INFINITY;
        for (int  i = 0; i <nodes ; i++)
        {
             for (int j = 0; j <nodes-1; j++)
             {
                 if (G[i][j] && ((select[i]&& !select[j] )||(!select [i ]&& select [j])))
                 {
                     if (G[i][j]<min_dist )
                     {
                         min_dist = G[i][j];
                         v1 = i;
                         v2 = j;
                     }
                     
                 }
                 
             }
             
        }
        
    
    cout<<"Edge "<<v1<<" " <<v2<< " and Weight =  "<<min_dist<<"\n";

    select [v1 ]= select[v2]= 1;
    total= total +min_dist ;
    }
    cout<<"\nTotal path length is  "<<total<<endl;



    
}
void MST::get_data(){
    int v1 ,v2 ,length ,n;
    cout <<"\nEnter the total number of nodes in the graph :  ";
    cin>>nodes;
    cout <<"\nEnter the total number of edges in the graph :  ";
    cin>>n;
    cout<<"\nEnter the edge and weight of the graph :  ";
    for (int  i = 0; i < n; i++)
    {
        cout<<"\nEnter the edge in the form of v1 , v2 (for e.g. if there is edge between 0 and 1 then write 0 1) "<<endl;

        cin>>v1>>v2;
        cout<<"\nEnter corresponding weight : "<<endl;
        cin>>length;
        G[v1][v2]= G[v2][v1]= length;

    }
    
}
int main (){
    MST obj ;
    cout<<"\nPrim's Algorithm\n";
    obj.get_data();
    cout<<" "<<endl;
    obj.Prim();
    return 0 ;
    
}

/*
PRIM's OUTPUT:
 

Prim's Algorithm

Enter the total number of nodes in the graph :  5

Enter the total number of edges in the graph :  7

Enter the edge and weight of the graph :  
Enter the edge in the form of v1 , v2 (for e.g. if there is edge between 0 and 1 then write 0 1) 
0 1

Enter corresponding weight : 
1

Enter the edge in the form of v1 , v2 (for e.g. if there is edge between 0 and 1 then write 0 1) 
0 2

Enter corresponding weight : 
2

Enter the edge in the form of v1 , v2 (for e.g. if there is edge between 0 and 1 then write 0 1) 
1 2

Enter corresponding weight : 
3

Enter the edge in the form of v1 , v2 (for e.g. if there is edge between 0 and 1 then write 0 1) 
2 3

Enter corresponding weight : 
4

Enter the edge in the form of v1 , v2 (for e.g. if there is edge between 0 and 1 then write 0 1) 
3 4

Enter corresponding weight : 
5

Enter the edge in the form of v1 , v2 (for e.g. if there is edge between 0 and 1 then write 0 1) 
1 3

Enter corresponding weight : 
6

Enter the edge in the form of v1 , v2 (for e.g. if there is edge between 0 and 1 then write 0 1) 
1 4

Enter corresponding weight : 
7
 

The minimum spanning tree 
Edge 0 1 and Weight =  1
Edge 0 2 and Weight =  2
Edge 2 3 and Weight =  4
Edge 4 3 and Weight =  5

Total path length is  12

*/


/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph 
{
   private:
  vector<pair<int, edge> > G;  
  vector<pair<int, edge> > T;  
  int *parent;
  int V; 
  
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
  
};


Graph::Graph(int V) 
{
  parent = new int[V];
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}


void Graph::AddWeightedEdge(int u, int v, int w) 
{
  G.push_back(make_pair(w, edge(u, v)));
}


int Graph::find_set(int i) 

{
  // If i is the parent of itself
  if (i == parent[i])
  {
    return i;
  }
  
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}


void Graph::union_set(int u, int v) 
{
  parent[u] = parent[v];
}


void Graph::kruskal() 
{
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) 
  {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    
    if (uRep != vRep) 
    {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
    
  }
  
}


void Graph::print() 
{
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) 
  {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
  
}


int main() 
{
  Graph g(6);
  g.AddWeightedEdge(0, 1, 4);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 2);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 2);
  g.AddWeightedEdge(5, 4, 3);
  g.kruskal();
  g.print();
  
  return 0;
  
}*/

/*
KRUSKAL's OUTPUT:

Edge : Weight
1 - 2 : 2
2 - 5 : 2
2 - 3 : 3
3 - 4 : 3
0 - 1 : 4


*/






