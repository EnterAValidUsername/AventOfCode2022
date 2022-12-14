#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main() {
	string input;
	vector < string > s;
	
	while (getline(fin, input) && input.find(" 1") == -1) {
		s.push_back(input);
	}
	
	int N = (int)input[input.size() - 2] - 48;
	
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
	int num;
	int First, Last;
	
	while (fin >> trash >> num >> trash >> First >> trash >> Last) {
		Last--; First--;
		for (int i = 0; i < num; i++) {
			v[Last].push(v[First].top());
			v[First].pop();
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].top();
	}
	
	return 0;
}
