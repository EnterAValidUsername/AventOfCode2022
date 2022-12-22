#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

/*
	for clarity sake, in nested for loops i use:
	i = +x (rows);
	j = -y (columns);
*/

int main() {
	string input;
	vector < vector < pair < int, bool > > > grid;
	int S;
	
	while (getline(fin, input)) {
		S = input.size();
		vector < pair < int, bool > > temp(S);
		
		for (int i = 0; i < S; i++) {
			temp[i].first = (int)input[i] - 48;
			temp[i].second = false;
		}
		
		grid.push_back(temp);
	}
	
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	
	int ans = 0;
	
	for (int i = 0; i < S; i++) {
		grid[i][0].second = true; grid[i][S - 1].second = true;
		ans += 2;
		
		int current_max = grid[i][0].first;
		int max;
		
		for (int j = 1; j < S; j++) { // first and last already checked
			if (grid[i][j].first > current_max) {
				current_max = grid[i][j].first;
				
				if (!grid[i][j].second) {
					grid[i][j].second = true; ans++;
				}
			}
		}
		
		max = current_max;
		current_max = grid[i][S - 1].first;
		
		
		for (int j = (S - 1) - 1; j > 0; j--) { // i know that the first is already been set to true and that the last has been checked by the previous for loop
			if (grid[i][j].first == max) break;
			
			if (grid[i][j].first > current_max) {
				current_max = grid[i][j].first;
				
				if (!grid[i][j].second) {
					grid[i][j].second = true; ans++;
				}
			}
		}
	}
	
	// rows: left - right, right - left; it compiles correctly;
	
	for (int j = 0; j < S; j++) {
		
		if (!grid[0][j].second) {
			grid[0][j].second = true; ans++;
		}
		if (!grid[S - 1][j].second) {
			grid[S - 1][j].second = true; ans++;
		}
		
		int current_max = grid[0][j].first;
		int max;
		
		for (int i = 1; i < S - 1; i++) {
			if (grid[i][j].first > current_max) {
				current_max = grid[i][j].first;
				
				if (!grid[i][j].second) {
					grid[i][j].second = true; ans++;
				}
			}
		}
		
		max = current_max;
		current_max = grid[S - 1][j].first;
		
		for (int i = (S - 1) - 1; i > 0; i--) {
			if (grid[i][j].first == max) break;
			
			if (grid[i][j].first > current_max) {
				current_max = grid[i][j].first;
				
				if (!grid[i][j].second) {
					grid[i][j].second = true; ans++;
				}
			}
		}
	}
	
	cout << ans;
	
	// columns: top - bottom, bottom - top; it compiles correctly;
	// bugged: the example is right, but the solution for their input is too low

	return 0;
}

