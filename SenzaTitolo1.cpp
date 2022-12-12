#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main() {
	string input;
	vector < string > s;
	
	while (getline(fin, input) && input.find(" 1") == -1) {
		s.push_back(input);
	}
	
	int N = 9;
	
	vector < stack < char > > v(N);
	
	for (int i = 1; i < input.size(); i += 4) {
		for (int j = s.size() - 1; j >= 0; j--) {
			if (s[j][i] != ' ') {
				v[i / 4].push(s[j][i]);
			}
		}
	}
	
	getline(fin, input);
	
	string trash;
	int bin;
	char First, Last;
	
	while (fin >> trash >> bin >> trash >> First >> trash >> Last) {
		cout << bin << " " << First << " " << Last << "\n";
		Last--; First--;
		v[Last].push(v[First].top());
		v[First].pop();
	}
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].top();
	}
	
	// si incazza, ha problemi con accessi di memoria sbagliati probabilmente

	return 0;
}
