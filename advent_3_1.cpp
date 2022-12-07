#include<bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main() {
	
	string input;
	int ans = 0;
	
	while (fin >> input) {
		int N = input.size();
		
		map < char, int > m;
		
		for (int i = 0; i < N/2; i++) {
			m[input[i]] = 0; // a random number that we won't mind, which only purpose it's to create the item in our map
		}
		
		for (int i = N/2; i < N; i++) {
			if (m.count(input[i])) {
				if ((int)input[i] >= 65 and (int)input[i] <= 90) {
					ans += ((int)input[i] - 65 + 26 + 1);
					/* 
					the ascii values of the letters between A and Z space between 65 and 90, so for the points calculation i have to subtract 65, the value
					of the A character and to sum 26, as the first letters that the problem contemplates are the lowercase ones, and 1, because the first letter
					of this sum doesn't value 26 but 27
					*/
				}
				else if ((int)input[i] >= 97 and (int)input[i] <= 122) {
					ans += ((int)input[i] - 97 + 1);
					/* 
					the ascii values of the letters between a and z here space between 97 and 122 and i'm proceeding the exact same way as i did above
					*/
				}
				break; 
				// this break grants me that after finding the letter paired in both the portions of the sack the calculation of this input stops, avoiding annoying
				// errors and lowering a littel bit the complexity too
			}
		}
	}
	
	cout << ans;

	return 0;
}

