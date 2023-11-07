#include <iostream>

bool isValid(std::string s) {
        bool result = true;
        int stringLength = s.length();
        int validParanthesesChecker[stringLength];
        for(int i = 0 ; i < stringLength ; i++)
        {
            //"{[()]}" (Length = 6) --> 0 1 2 3 4 5
            if(s[i] == '(' || s[i] == ')'){validParanthesesChecker[i] = 1;}
            if(s[i] == '[' || s[i] == ']'){validParanthesesChecker[i] = 2;}
            if(s[i] == '{' || s[i] == '}'){validParanthesesChecker[i] = 3;}
        }
        for(int i = 0 ; i < stringLength/2 ; i++)
        {
            if(validParanthesesChecker[i] == validParanthesesChecker[stringLength-(i+1)])
            {continue;}
            else{result = false; break;}
        }
        return result;
    }

int main() {
    std::cout << isValid("()") << std::endl;    //Expected true
    std::cout << "()[]{}" << std::endl;             //Expected true
    std::cout << "(]" << std::endl;                 //Expected false
}
