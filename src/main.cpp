
#include <string>
#include <iostream>
#include <recognize_intent.h>

int main()
{
    const std::string input_line = "Tell me an interesting fact.";
    std::cout << recognizeIntent(input_line);
    return 1;
}