#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main() {
	
	string input;
	vector < string > cmds;
	
	unordered_map < string, vector < string > > adj;
	
	while (getline(fin, input)) {
		cmds.push_back(input);
	}
	
	int K = cmds.size();
	for (int k = 0; k < K; k++) {
		int N = cmds[k].size();
		string name;
		
		if (cmds[k].find("$ cd") == 0) { // if the subs is found and starts at index 0 then...
			if (cmds[k].find("..") == 6) {
				// ??
			}
			else if (cmds[k].find("/") == 6) {
				// ??
			}
			else {
				name = cmds[k].substr(7);
				k += 2; // the next line will always be a "$ ls" so i'm skipping to the line after it
				
				vector < string > temp;
				
				while (cmds[k].find("$") == -1) {
					temp.push_back(cmds[k]);
					k++;
				}
				k--; // this is due to the fact that the while loop will terminate with the next command already inserted
				
				adj.insert({name, temp});
			}
		}
	}

	return 0;
}

