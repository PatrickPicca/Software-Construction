#include <iostream>

unsigned int count(const std::string& str) {
    unsigned int counter = 0;
    bool on_space = true;
    
    for(int i = 0; i < str.size(); i++) {
        if (std::isspace(str[i]))
            on_space = true;
        else if (on_space) {
            counter++;
            on_space = false;
        }
    }

    return counter;
}


//This function counts the number of words in a string, delimited by whitespace.
//It takes a string and iterates through every character.
//When whitespace is encountered, a flag gets set.
//If the next character doesn't contain whitespace, the counter is incremented and the flag is unset.
