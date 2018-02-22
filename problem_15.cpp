
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
 
// iPair ==>  Integer Pair
typedef pair<int, int> iPair;
 

class Graph
{
    int V;    // Number of vertices
 

    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
 
    // Print MST using Prim's algorithm
    void primMST();
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
// Prints shortest paths from src to all other vertices
void Graph::primMST()
{

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    int src = 0; // Taking vertex 0 as source
 

    vector<int> key(V, INF);
 
    // To store parent array which in turn store MST
    vector<int> parent(V, -1);
 
    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);
 
    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;
 
    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();
 
        inMST[u] = true;  // Include vertex in MST
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
         
            int v = (*i).first;
            int weight = (*i).second;
 
       
            if (inMST[v] == false && key[v] > weight)
            {
               
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 

    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}
 

int main()
{
   
    int V ;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);
 	
 
    cout << "Enter the number of edge: ";
    int ed;
    cin >> ed;
    int i;
    for(i=0;i<ed;i++){
    	int a,b,c;
    	cout << "Enter : starting edge : end edge : weight              ";
    	cin >> a >> b >> c;
    	g.addEdge(a,b,c);
	}
    
cout << "The MST is as follows\n\n";

    g.primMST();
 
    return 0;
}
