#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

bool vis[N];
vector<int> g[N];

vector<vector<int> >connComp;
vector<int>newConnComp;

void dfs(int vertex){
	vis[vertex]=true;
	newConnComp.push_back(vertex);
	
	for(int child:g[vertex]){
		if(vis[child])//visited vertex
			continue; 
		dfs(child);
	}
	
}


int main(){
	
	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int v1,v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2); // adjacent node listed
		g[v2].push_back(v1); //use's for undirected graph

	}
	int c = 0;
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		newConnComp.clear();
		dfs(i);
		connComp.push_back(newConnComp);
	}
	cout << "number of connected component node "<< connComp.size() << "\n\n";

	for(auto current_connNode : connComp){
		for(int vertex : current_connNode){
			cout << vertex << " ";
			
		}
		cout << "\n";
	}
	
	
}
