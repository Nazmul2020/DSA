#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

bool vis[N];
vector<int> g[N];

int indegree[N];

void dfs(int vertex){
	vis[vertex]=true;
	
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
		indegree[v2]+=1; //calculate indegree
		//g[v2].push_back(v1); //use's for undirected graph

	}
	int c = 0;
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		dfs(i);
		c++; //count connected component
	}
	cout << "number of connected component node "<< c << "\n\n";
	
	for (int i = 1; i <=n; ++i){
		cout << i << "--> ";
		for(int node:g[i])
			cout << node << " ";
		cout <<"[indegree "<<indegree[i] <<" outdegree "<<g[i].size()<<"]\n";
	}
}
