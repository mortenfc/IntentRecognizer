
#include <string>
#include <iostream>
#include <recognize_intent.h>

int main()
{
    while (true)
    {
        std::cout << "======================================================================================================\n";
        std::cout << "Type a sentence that shows your intent, for instance \"I wonder how my day is tomorrow.\"\n";
        std::string input_line = "";
        std::getline(std::cin, input_line);
        std::cout << "-----------------------------------------------------------------------------------------"
                     "-----\nRecognized input: \"" +
                         input_line +
                         "\".\n--------------------------------------------------------------------------------"
                         "--------------\n";
        std::cout << recognizeIntent(input_line) << "\n\n";
    }
    return 1;
}