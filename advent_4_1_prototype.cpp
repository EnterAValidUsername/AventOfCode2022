#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main () {
	
	string input;
	vector < string > v;
	
	while (fin >> input) {
		int N = input.size();
		int i = 0;
		for (int j = 0; j < 2; j++) {
			string t = "";
			
			while (input[i] != ',' && i < N) {
				t += input[i];
				i++;
			}
			i++;
			v.push_back(t);
		}
	} // i'm removing the comma by putting as strings every couplet in a vector
	
	int N = v.size() / 2;
	vector < pair < int, int > > V;
	int ans = 0; // the variable that will store our answer
	
	for (int i = 0; i < N; i++) {
		int pos_ = v[i].find('-'); // pos_ is the position of the character '-' inside of the string
		V.push_back( make_pair ( stoi(v[i * 2].substr (0, pos_)), stoi( v[i * 2 + 1].substr (pos_ + 1, v[i].size() - pos_) ) ) );
	}
	/*
	this might be hard but follow me:
	i'm inserting in our vector of pairs a freshly composed pair composed by:
		- the conversion to int of a substring, that's part of the string at index i, in the vector of couplets made of strings (v), 
		that spaces from the first cell (0) to the next cells until it reaches '-', this number of cell il pos_ (the second term of the function substr())
		
		- the conversion to int of the substring, part of the string i in the vector v, that spaces from the position immediately after the '-' character, to
		the last cell, this number of cells is: dimension - position of '-'
	*/
	
	N = V.size();
	for (int i = 0; i < N; i += 2) {
		if (V[i].first < V[i + 1].first && V[i].second > V[i + 1].second) {
			ans++;
		}
	}
	// fuck complexity, i'm trying brute force, i'm too mentally tired to think of an optimized solution
	// immagina essere riusciti a farsi venire il problema... URLO
	cout << ans;
	
	return 0;
}
