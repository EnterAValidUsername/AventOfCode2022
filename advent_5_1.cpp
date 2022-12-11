#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main() {
	string input;
	vector < string > s;
	
	while (getline(fin, input) && input.find(" 1") == -1) {
		s.push_back(input);
	} 
	
	int N = input[input.size() - 2]; 
	
	vector < queue < char > > v(N);
	
	for (int i = 2; i < N * 3 + N - 1; i += 4) {
		for (int j = 0; j < s.size(); j++) {
			v[i].push(s[j][i]);
		}
	}
	
	string trash;
	int bin;
	char First, Last;
	
	while (fin >> trash >> bin >> trash >> First >> trash >> Last) {
		v[Last].push(v[First].front());
		v[First].pop();
	}
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].front();
	}
	
	// si incazza, ha problemi con accessi di memoria sbagliati probabilmente

	return 0;
}

