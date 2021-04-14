// #include "../include/main.h"
#include <main.h>
#include <boost/algorithm/string.hpp>
#include <vector>

// * What is the weather like today? => Prints (Intent: Get Weather)
// * What is the weather like in Paris today? => Prints (Intent: Get Weather City)
// * What is the weather like in New York today? => Prints (Intent: Get Weather City)
// * Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
// * Tell me an interesting fact. => Prints (Intent: Get Fact)

bool isWordProbablySimilarTo(const std::string& to_test,
                             const std::string& ground_truth,
                             float min_charactor_percentage_match = 80.0,
                             bool is_case_sensitive = false)
{
    for (int i = 0; i < to_test.size(); i++)
    {
        std::cout << to_test[i];
    }
}

int main()
{
    // std::string in = "Tell me an interesting fact.";
    // std::string in = "Am I free at 13:00 PM tomorrow?";
    // std::string in = "What is the weather like in New York today?";
    // std::string in = "What is the weather like in Paris today?";
    std::string input_line = "What is the weather like today?";
    std::vector<std::string> input_words;
    boost::split(input_words, input_line, [](char c) { return c == ' '; });

    std::string output_prefix = "Intent: ";
    Category category;
    Weather weather;
    Calendar calendar;

    for (size_t i = 0; i < input_words.size(); i++)
    {
        for (std::string weather_word : weather.mappings)
        {
            bool is_word_match = isWordProbablySimilarTo(input_words[i], weather_word);
            if (weather_word == input_words[i])
            {
                // category = Category::weather;
                goto weather_execution;
            }
        }
        for (std::string calendar_word : calendar.mappings)
        {
            if (calendar_word == input_words[i])
            {
                // category = Category::calendar;
                goto calendar_execution;
            }
        }
    }

weather_execution:;
    {
        int a = 3;
    }
calendar_execution:;
    {
        int b = 5;
    }

    return 1;
}