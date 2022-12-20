#include<bits/stdc++.h>
using namespace std;

// it's still bugged
ifstream fin ("input.txt");

map < string, vector < string > > graph;

map < string, bool > visited; // contains the state of a node, whether is visited or not
map < string, int > memo_wh; // memoization for the wheights calculation
map < string, string > ancestors; // every node has a node from witch it origins, except for "/"

string clean (string raw) {
	// dir gd
	// 92838382 hh
	
	if (raw.find("dir") == 0) { // if the raw string starts with 'dir', it must be a directory
		return raw.substr(4);
	}
	return raw;
}

int dfs (string name) {
	visited[name] = true;
	
	int S = graph[name].size();
	
	if (S == 0) { // if the adjacencies of a node are null
		if (memo_wh.find(name) != memo_wh.end()) {
			return memo_wh[name];
		}
		else {
			int temp = name.find(' '); // works only if the last element is a file
			memo_wh[name] = stoi(name.substr(0, temp - 1)); // error "stoi not declared"
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
	
	while (!fin.eof()) { // it runs until the end of the input file is reached
		if (taken == false) getline(fin, input);
		taken = false;
		
		if (input[0] == '$') {
			if (input.find("$ cd") == 0) {
				if (input.find("/") == 6) {
					cd = "/"; pd = "/";
				}
				
				if (input.find("..") == 6) {
					cd = pd; pd = ancestors[cd];
				}
				
				else {
					cd = clean(input); // otherwise the current directory is this
				}
			}
			else if (input.find("$ ls") == 0) {
				while (getline(fin, input) && input[0] != '$') {
					graph[cd].push_back(input);
					ancestors[input] = clean(cd); // va ripulito, scrivi ripulisci.
					taken = true;
				}
			}
		}
		// otherwise error!
	}
	
	dfs("/");
	
	// weight menagement

	return 0;
}

