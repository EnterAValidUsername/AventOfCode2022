#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

main() {
	string input;
	fin >> input;
	
	int N = input.size();
	set < char > Count; // it doesn't likes unordered_sets
	queue < char > q;
	
	int i = 0;
	while (q.size() < 14) {
		if (Count.find(input[i]) == Count.end()) { // not found
			q.push(input[i]); Count.insert(input[i]);
		}
		else { // if the element input[i] is already in the set
			while (Count.find(input[i]) != Count.end()) {
				
				Count.erase(q.front());
				q.pop();
			}
			
			q.push(input[i]); Count.insert(input[i]);
		}
		i++;
	}
	
	cout << i;
}

