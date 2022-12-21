#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main() {
	// to avoid any inconvenience:
	// - y = i
	// + x = j
	
	string input;
	vector < vector < pair < int, bool > > > grid;
	int S;
	
	while (getline(fin, input)) {
		S = input.size();
		vector < pair < int, bool > > temp(S);
		
		for (int i = 0; i < S; i++) {
			temp[i].first = (int)input[i];
			temp[i].second = false;
		}
		grid.push_back(temp);
	}
	// grid of trees saved successfully, every tree now is an int
	
	int ans = 0;
	ans += (S - 1) * 4; // all of the external trees are visible
	
	for (int i = 1; i < S - 1; i++) { // rows, left to right
		int current_max = grid[i][0].first;
		
		for (int j = 1; j < S - 1; j++) {
			
			if (grid[i][j].first > current_max) {
				
				current_max = grid[i][j].first;
				grid[i][j].second = true;
				ans++;
			}
		}
	}
	
	for (int i = 1; i < S - 1; i++) { // rows, right to left
		int current_max = grid[i][S - 1].first;
		
		for (int j = S - 2; j > 0; j--) {
			
			if (grid[i][j].first > current_max && !grid[i][j].second) {
				
				current_max = grid[i][j].first;
				grid[i][j].second = true;
				ans++;
			}
		}
	}
	
	for (int j = 1; j < S - 1; j++) {
		int current_max = grid[0][j].first;
		
		for (int i = 1; i < S - 1; i++) {
			
			if (grid[i][j].first > current_max && !grid[i][j].second) {
				
				current_max = grid[i][j].first;
				grid[i][j].second = true;
				ans++;
			}
		}
	}
	
	for (int j = 1; j < S - 1; j++) {
		int current_max = grid[0][j].first;
		
		for (int i = S - 2; i > 0; i--) {
			
			if (grid[i][j].first > current_max && !grid[i][j].second) {
				
				current_max = grid[i][j].first;
				grid[i][j].second = true;
				ans++;
			}
		}
	}
	
	cout << ans;

	return 0;
}

