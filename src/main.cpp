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
    std::string short_word, long_word;
    if (word_1.size() > word_2.size())
    {
        long_word = word_1;
        short_word = word_2;
    }
    else
    {
        long_word = word_2;
        short_word = word_1;
    }
    uint short_word_size = short_word.size();
    uint long_word_size = long_word.size();
    uint delta_size = long_word_size - short_word_size;
    uint short_word_shift = 0;
    uint char_match_count = 0;
    do
    {    
        for (int i = 0; i < short_word_size; i++)
        {
            std::cout << short_word[i];

            if (short_word[i] == long_word[i + short_word_shift])
            {
                char_match_count++;
            }
        }
        short_word_shift++;
    }
    while (short_word_shift <= delta_size);

    float match_percentage = 100.0 * short_word_size / char_match_count;
    bool is_match = match_percentage > min_charactor_percentage_match;

    if(is_match)
    {
        return true;
    }
    else
    {
        char_match_count = 0;
        //* Try shifting each word up to 2 characters forwards and then comparing
    }

    float match_percentage = 100.0 * short_word_size / char_match_count;
    bool is_match = match_percentage > min_charactor_percentage_match;
    return is_match
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
            if (is_word_match)
            {
                goto weather_execution;
            }
        }
        for (std::string calendar_word : calendar.calendar)
        {
            bool is_word_match = areWordsMostlySimilar(input_words[i], calendar_word);
            if (is_word_match)
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