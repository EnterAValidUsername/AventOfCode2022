#include<bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");

int main() {
	string input1, input2, input3;
	unordered_set < char > Elf1, Elf2, Elf3;
	int ans = 0;
	
	while (cin >> input1 >> input2 >> input3) {
		int N = input1.size();
		for (int i = 0; i < N; i++) {
			if (input2.find(input1[i]) != -1 && input3.find(input1[i]) != -1) {
				if (input1[i] >= 65 and input1[i] <= 90) {
					ans += input1[i] - 65 + 26 + 1;
				}
				else if (input1[i] >= 97 and input1[i] <= 122) {
					ans += input1[i] - 97 + 1;
				}
				break; 
			}
		}
	}
	cout << ans;
}
 