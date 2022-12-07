#include<bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");

main() {
	// da sempre 0, si vede che la condizione di verifica per la presenza degli oggetti negli zaini, interna al primo for, del while non è mai vera
	string input1, input2, input3;
	unordered_set < char > Elf1, Elf2, Elf3;
	int ans = 0;
	
	while (fin >> input1 >> input2 >> input3) {
		// filling my Elf's rucksacks
		int N = Elf1.size();
		for (int i = 0; i < N; i++) {
			if (!Elf1.count(input1[i])) {
				Elf1.insert(input1[i]);
			}
		}
		N = Elf2.size();
		for (int i = 0; i < N; i++) {
			if (!Elf2.count(input2[i])) {
				Elf2.insert(input2[i]);
			}
		}
		N = Elf3.size();
		for (int i = 0; i < N; i++) {
			if (!Elf3.count(input3[i])) {
				Elf3.insert(input3[i]);
			}
		}
		
		N = Elf1.size();
		unordered_set < char > :: iterator i; // an iterator is like a pointer which can only be used to iterate through STL structs
		for (i = Elf1.begin(); i != Elf1.end(); i++) { // i'm assigning the value of the pointer which is pointing to the first element and forward to the end to the iterator i
			if (Elf2.count(*i) && Elf3.count(*i)) { // if the value of the element which i is pointing toward is in the set then do...
				if ((int) *i >= 65 and (int) *i <= 90) {
					ans += ((int) *i - 65 + 26 + 1);
				}
				else if ((int) *i >= 97 and (int) *i <= 122) {
					ans += ((int) *i - 97 + 1);
				}
				break; 
			}
		}
	}
	cout << ans;
}

