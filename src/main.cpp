// #include "../include/main.h"
#include <main.h>
#include <boost/algorithm/string.hpp>
#include <vector>

// * What is the weather like today? => Prints (Intent: Get Weather)
// * What is the weather like in Paris today? => Prints (Intent: Get Weather City)
// * What is the weather like in New York today? => Prints (Intent: Get Weather City)
// * Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
// * Tell me an interesting fact. => Prints (Intent: Get Fact)

bool areWordsMostlySimilar(const std::string& word_1,
                             const std::string& word_2,
                             float min_charactor_percentage_match = 80.0,
                             bool is_case_sensitive = false)
{
    uint word_1_size = word_1.size();
    uint word_2_size = word_2.size();
    uint loop_count = std::min(word_2_size, word_1_size);
    int neighbour_index = 0;
    uint char_match_count = 0;
    for (int i = 0; i < loop_count; i++)
    {
        std::cout << word_1[i];

        if (word_1[i] == word_2[i])
        {
            char_match_count++;
            continue;
        }
        else if
    }
}

int main()
{
    // std::string input_line = "Tell me an interesting fact.";
    // std::string input_line = "Am I free at 13:00 PM tomorrow?";
    // std::string input_line = "What is the weather like in New York today?";
    // std::string input_line = "What is the weather like in Paris today?";
    std::string input_line = "What is the weather like today?";
    std::vector<std::string> input_words;
    boost::split(input_words, input_line, [](char c) { return c == ' '; });

    std::string output_prefix = "Intent: ";
    Weather weather;
    Calendar calendar;
    uint type_match_count = 0;

    for (size_t i = 0; i < input_words.size(); i++)
    {
        for (std::string weather_word : weather.weather)
        {
            bool is_word_match = areWordsMostlySimilar(input_words[i], weather_word);
            if (weather_word == input_words[i])
            {
                goto weather_execution;
            }
        }
        for (std::string calendar_word : calendar.mappings)
        {
            if (calendar_word == input_words[i])
            {
                goto calendar_execution;
            }
        }
    }

weather_execution:;
    {
        std::cout << output_prefix;
        for (size_t i = 0; i < type_match_count; i++)
        {
            std::cout << weather.intent_outputs[i];
        }
        
    }
calendar_execution:;
    {        
        std::cout << output_prefix;
        for (size_t i = 0; i < type_match_count; i++)
        {
            std::cout << calendar.intent_outputs[i];
        }
    }

    return 1;
}