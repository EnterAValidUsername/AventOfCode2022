#include <bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");

int main () {
	int i1, i2, f1, f2;
	char trash;
	int ans = 0;
	
	while (fin >> i1 >> trash >> f1 >> trash >> i2 >> trash >> f2) 
	{
		if ((i1 <= i2 && f2 <= f1) || (i2 <= i1 && f1 <= f2)) {
			ans++;
		}
	}
	cout << ans;
}