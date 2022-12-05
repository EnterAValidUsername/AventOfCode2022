#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main() {
	
	int ans = 0, temp = 0;
	string input;
	
	while (getline(fin, input)) {
		if (input != "") {
			temp += stoi(input);
		}
		else{
			ans = max(ans, temp);
			temp = 0;
		}
	}
	
	cout << ans;

	return 0;
}

