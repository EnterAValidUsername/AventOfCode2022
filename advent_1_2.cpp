#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main() {
	
	int ans[3] = {0}, temp = 0;
	string input;
	
	 while (getline(fin, input)) {
		if (input != "") {
			temp += stoi(input);
		}
		else {
			for (int i = 0; i < 3; i++) {
				if (ans[i] < temp) {
					for (int j = 2; j > i; j--) {
						ans[j] = ans[j - 1]; // repositioning the answers
					}
					ans[i] = temp;
					break;
				}
			}
			temp = 0;
		}
	}
	
	/*
	this code only works if in the file input at the end of all numbers
	is typed:
	
	0
	
	with 'enters' included
	*/
	
	//recycling temp as it was the answer variable because i love recycling
	temp = 0;
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << "\n";
		temp += ans[i];
	}
	
	cout << temp;

	return 0;
}

