#include <string>
#include <unordered_map>
using namespace std;

string uniqueChar(string str) {
	string output = "";
	unordered_map<char, bool> seen;
	for (int i=0; i<str.size(); i++) {
		if (seen.count(str[i])==0) {
			seen[str[i]] = true;
			output = output + str[i];
		}				
	}
	return output;
}