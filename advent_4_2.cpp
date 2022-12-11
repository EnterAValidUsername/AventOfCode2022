#include <bits/stdc++.h>
using namespace std;
#define fin cin 

int main () {
	int i1, i2, f1, f2;
	char trash;
	int ans = 0;
	
	while (cin >> i1 >> trash >> f1 >> trash >> i2 >> trash >> f2) 
	{
		if ((i1 <= i2 && f2 <= f1) || (i2 <= i1 && f1 <= f2)) {
			ans++;
		} 
		else if ((i1 <= i2 && i2 <= f1) || (i2 <= i1 && i1 <= f2) || (i1 <= f2 && f2 <= f1) || (i2 <= f1 && f1 <= f2)) {
			ans++;
		}
	}
	cout << ans;
}