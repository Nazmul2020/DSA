#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

bool vis[N];
vector<int> g[N];
pair<vector<int>, int > p[N];

int sameNode[N];

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
		g[v1].push_back(v2);
		g[v2].push_back(v1);

		p[v1].first.push_back(v2);
		p[v2].first.push_back(v1);

		p[v1].second +=sameNode[v1] +1;
		p[v2].second +=sameNode[v2] +1;


	}
	int c = 0;
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		dfs(i);
		c++;
	}
	cout << "number of connected component node "<< c << "\n\n";


	cout << "adjacent list of each node\n";
	for (int i = 1; i <= n; ++i){
		cout << i << "--> ";
		for(int node:p[i].first){
			cout<< node << " ";
		}
		cout << "[total adjacent node "<<p[i].second<<"]\n";
	}
}
