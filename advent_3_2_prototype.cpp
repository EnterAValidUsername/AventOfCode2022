#include<bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");

main() {
	string input1, input2, input3;
	unordered_set < char > Elf1, Elf2, Elf3;
	int ans = 0;
	
	while (fin >> input1 >> input2 >> input3) {
		// filling my Elf's rucksacks
		int N = input1.size();
		for (int i = 0; i < N; i++) {
			if (!Elf1.count(input1[i])) {
				Elf1.insert(input1[i]);
			}
		}
		N = input2.size();
		for (int i = 0; i < N; i++) {
			if (!Elf2.count(input2[i])) {
				Elf2.insert(input2[i]);
			}
		}
		N = input3.size();
		for (int i = 0; i < N; i++) {
			if (!Elf3.count(input3[i])) {
				Elf3.insert(input3[i]);
			}
		}
		
		N = Elf1.size();
		// auto here signifies: unordered_set < char > :: iterator i; // an iterator is like a pointer which can only be used to iterate through STL structs
		for (auto i = Elf1.begin(); i != Elf1.end(); i++) { // i'm checking if any of the elements in Elf1 is also present in Elf2 and ELf3, more precisely:
		// if the value of the cell i is pointing towards (in Elf1), is equal to any of the elements in Elf2 and Elf3 then //*calculate priority points*
			if (Elf2.count(*i) && Elf3.count(*i)) {
				if (*i >= 65 and *i <= 90) {
					cout << (int) *i - 65 + 26 + 1 << ", sono tra 65 e 90; ";
					ans += (int) *i - 65 + 26 + 1;
				}
				else if (*i >= 97 and *i <= 122) {
					cout << (int) *i - 97 + 1 << ", sono tra 97 e 122; ";
					ans += (int) *i - 97 + 1;
				}
				break; 
			}
		}
	}
	cout << ans;
	
	// it starts mistaking the ASCII conversions after the first one
	/*
	all of the numbers that you see in the calculations above referres to the conversion numbers from the
	complete ascii table setting the values of a = 97, z = 112, A = 65, and Z = 90
	*/
}

