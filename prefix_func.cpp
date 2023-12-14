#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> prefix_function (string s) {  // O(n^3);
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=0; i<n; ++i)
		for (int k=0; k<=i; ++k)
			if (s.substr(0,k) == s.substr(i-k+1,k))
				pi[i] = k;      
	return pi;
}
int main()
{
    vector<int> s = prefix_function("ababbabbabbababbabb");
    for (int i = 0; i < s.size(); i++){
        cout << s[i] << " ";
    }

    return 0;
}