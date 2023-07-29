#include <cstring>
void helper(char *input, int size) {
	if (input[1]=='\0') {
		return;
	}
	if (input[0]=='p' and input[1]=='i') {
		for (int i = size; i>1; i--) {
			input[i+2] = input[i];
		}
		input[0] = '3';
		input[1] = '.';
		input[2] = '1';
		input[3] = '4';	
		size = size+2;
	}
	helper(input+1, size-1);
	return;
}

void replacePi(char input[]) {
	helper(input, strlen(input));
}