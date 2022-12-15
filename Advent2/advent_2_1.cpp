#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main() {
	
	char temp[2];
	int total = 0;
	
	while (fin >> temp[0] and fin >> temp[1]) {
		if (temp[0] == 'A') {
			if (temp[1] == 'X') total += (1 + 3);
			else if (temp[1] == 'Y') total += (2 + 6);
			else total += (3 + 0);
		}
		else if (temp[0] == 'B') {
			if (temp[1] == 'X') total += (1 + 0);
			else if (temp[1] == 'Y') total += (2 + 3);
			else total += (3 + 6);
		}
		else {
			if (temp[1] == 'X') total += (1 + 6);
			else if (temp[1] == 'Y') total += (2 + 0);
			else total += (3 + 3);
		}
	}
	
	cout << total;

	return 0;
}

