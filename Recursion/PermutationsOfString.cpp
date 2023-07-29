#include <iostream>
using namespace std;

int permutationsOfString(string input, string output[]) {
    if (input.size()==1) {
        output[0] = "";
        return 1;
    }
    string smallOutput[5000];
    int smallSize = permutationsOfString(input.substr(1), smallOutput);
    int k = 0;
    for (int i=0; i<smallSize; i++) {
        for (int j=0; j<=smallOutput[i].size(); j++) {
            output[k] = smallOutput[i].substr(0,j) + input[0] + smallOutput[i].substr(j);
            k++;
        }
    }
    return k;
}


void permute(string a, int l, int r)  
{  
    // Base case  
    if (l == r)  
        cout<<a<<endl;  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(a[l], a[i]);  
  
            // Recursion called  
            permute(a, l+1, r);  
  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
}  
void printPermutations(string input){
    permute(input,0,input.size()-1);
}