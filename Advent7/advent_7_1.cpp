#include<bits/stdc++.h>
using namespace std;

// it's still bugged
#define EVAL
#ifdef EVAL
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define cin fin
#define cout fout
#endif

map < string, vector < string > > graph;

map < string, bool > visited; // contains the state of a node, whether is visited or not
map < string, int > memo_wh; // memoization for the wheights calculation

int dfs (string name) {
	visited[name] = true;
	
	int S = graph[name].size();
	
	if (S == 0 && name[0] != 'd') { // if the adjacencies of a node are null and it isn't a directory
		if (memo_wh.find(name) != memo_wh.end()) {
			return memo_wh[name];
		}
		else {
			int temp = name.find(' ');
			memo_wh[name] = stoi(name.substr(0, temp - 1));
		}
	}
	if (memo_wh.find(name) != memo_wh.end()) {
		return memo_wh[name];
	}
	else {
		for (int i = 0; i < S; i++) {
			
			if (visited[graph[name][i]] == false) {
				memo_wh[name] += dfs(graph[name][i]);
			}
		}
	}
}

int main() {
	
	string input;
	string cd, pd; // current directory, previous directory
	// i'm going to set them the same value if there isn't any previous directory
	bool taken = false;
	map < string, string > ancestors;
	
	while (!fin.eof()) { // it runs until the end of the input file is reached
		if (taken == false) getline(fin, input);
		taken = false;
		
		if (input[0] == '$') {
			if (input.find("$ cd") == 0) {
				if (input.find("/") == 6) {
					cd = "/"; pd = "/";
				}
				
				if (input.find("..") == 6) {
					cd = pd; pd = cd;
				}
				
				else {
					cd = input.substr(6);
				}
			}
			else if (input.find("$ ls") == 0) {
				while (getline(fin, input) && input[0] != '$') {
					graph[cd].push_back(input);
					ancestor[input] = cd; // va ripulito, scrivi ripulisci.
					taken = true;
				}
			}
		}
		// otherwise error!
	}
	
	dfs("/");

	return 0;
}

