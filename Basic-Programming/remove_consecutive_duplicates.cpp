#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) { //recursive function two remove repeating characters in array of characters or string
if(input[0]=='\0'){  //Base case
    return;          
}
    if(input[0]==input[1]){    // condition
        int i;
    	for(i=0;input[i]!='\0';i++){
            input[i]=input[i+1];
        }
        input[i]=input[i+1];
        removeConsecutiveDuplicates(input);  //recursive call on condition being true
    }else{
        removeConsecutiveDuplicates(input+1); //recursive call on condition being false
    }
}



int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}