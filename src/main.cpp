#include <main.h>
#include <boost/algorithm/string.hpp>
#include <vector>

// * What is the weather like today? => Prints (Intent: Get Weather)
// * What is the weather like in Paris today? => Prints (Intent: Get Weather City)
// * What is the weather like in New York today? => Prints (Intent: Get Weather City)
// * Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
// * Tell me an interesting fact. => Prints (Intent: Get Fact)

bool areWordsMostlySimilar(std::string word_1,
                           std::string word_2,
                           float min_charactor_percentage_match = 80.0,
                           bool is_case_sensitive = false)
{
    if (not is_case_sensitive)
    {
        boost::to_lower(word_1);
        boost::to_lower(word_2);
    }

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
    uint short_word_char_count_skip = 0;
    uint char_match_count = 0;
    // std::cout << "\nSize matching:\n";
    do
    {
        for (int i = 0; i < short_word_size; i++)
        {
            if (short_word[i + short_word_char_count_skip] == long_word[i])
            {
                char_match_count++;
            }
        }
        short_word_char_count_skip++;
    } while (short_word_char_count_skip <= delta_size);

    float match_percentage = 100.0 * char_match_count / long_word_size;
    bool is_match = match_percentage > min_charactor_percentage_match;
    if (is_match)
    {
        std::cout << "\nSize matching:\n";
        std::cout << "match_percentage: " << match_percentage << std::endl;
        std::cout << "char_match_count: " << char_match_count << std::endl;
        std::cout << "long_word_size: " << long_word_size << std::endl;
        std::cout << "delta_size: " << delta_size << std::endl;
        return true;
    }
    else
    {
        //* At first mismatch, try shifting each word up to 2 characters forwards and then comparing
        // std::cout << "\nFirst mismatch index:\n";
        uint first_mismatch_index = 0;
        for (int i = 0; i < short_word_size; i++)
        {
            if (short_word[i] != long_word[i])
            {
                first_mismatch_index = i;
                break;
            }
        }
        // std::cout << "\nShort word skip at first mismatch:\n";
        char_match_count = 0;
        short_word_char_count_skip = 1;
        while (short_word_char_count_skip <= 2)
        {
            uint short_word_idx = 0;
            uint smaller_size = std::min(short_word_size - short_word_char_count_skip, long_word_size);
            for (int i = 0; i < smaller_size; i++)
            {
                if (i >= first_mismatch_index)
                {
                    short_word_idx = i + short_word_char_count_skip;
                }
                else
                {
                    short_word_idx = i;
                }
                if (short_word[short_word_idx] == long_word[i])
                {
                    char_match_count++;
                }
            }
            short_word_char_count_skip++;
        }
        match_percentage = 100.0 * char_match_count / long_word_size;
        is_match = match_percentage > min_charactor_percentage_match;
        if (is_match)
        {
            std::cout << "\nShort word skip at first mismatch:\n";
            std::cout << "match_percentage: " << match_percentage << std::endl;
            std::cout << "char_match_count: " << char_match_count << std::endl;
            std::cout << "long_word_size: " << long_word_size << std::endl;
            std::cout << "short_word_char_count_skip: " << short_word_char_count_skip << std::endl;
            return true;
        }

        // std::cout << "\nLong word skip at first mismatch:\n";
        char_match_count = 0;
        uint long_word_char_count_skip = 1;
        while (long_word_char_count_skip <= 2)
        {
            uint long_word_idx = 0;
            uint smaller_size = std::min(short_word_size, long_word_size - long_word_char_count_skip);
            for (int i = 0; i < smaller_size; i++)
            {
                // std::cout << short_word[i] << " ";

                if (i >= first_mismatch_index)
                {
                    long_word_idx = i + long_word_char_count_skip;
                }
                else
                {
                    long_word_idx = i;
                }
                if (short_word[i] == long_word[long_word_idx])
                {
                    char_match_count++;
                }
            }
            long_word_char_count_skip++;
        }
        match_percentage = 100.0 * char_match_count / long_word_size;
        is_match = match_percentage > min_charactor_percentage_match;
        if (is_match)
        {
            std::cout << "\nLong word skip at first mismatch:\n";
            std::cout << "match_percentage: " << match_percentage << std::endl;
            std::cout << "char_match_count: " << char_match_count << std::endl;
            std::cout << "long_word_size: " << long_word_size << std::endl;
            std::cout << "long_word_char_count_skip: " << long_word_char_count_skip << std::endl;
            return true;
        }
    }

    return false;
}

int main()
{
    std::string input_line = "Tell me an interesting fact.";
    // std::string input_line = "Am I free at 13:00 PM tomorrow?";
    // std::string input_line = "What is the weather like in New York today?";
    // std::string input_line = "What is the weather like in Paris today?";
    // std::string input_line = "What is the weather like today?";
    std::vector<std::string> input_words;
    boost::split(input_words, input_line, [](char c) { return c == ' '; });

    std::string output_prefix = "Intent: ";
    Weather weather;
    Calendar calendar;
    Fact fact;
    uint type_match_count = 0;
    bool is_weather_match = false;
    bool is_city_match = false;
    bool is_calendar_match = false;
    bool is_fact_match = false;

    for (size_t i = 0; i < input_words.size(); i++)
    {
        for (size_t j = 0; j < weather.array_size; j++)
        {
            is_weather_match = is_weather_match | areWordsMostlySimilar(input_words[i], weather.weather[j]);
            is_city_match = is_city_match | areWordsMostlySimilar(input_words[i], weather.city[j]);
        }
    }
    type_match_count = uint(is_weather_match) + uint(is_city_match);
    if (type_match_count)
    {
        goto weather_execution;
    }

    for (size_t i = 0; i < input_words.size(); i++)
    {
        for (std::string calendar_word : calendar.calendar)
        {
            is_calendar_match = is_calendar_match | areWordsMostlySimilar(input_words[i], calendar_word);
        }
    }
    type_match_count = uint(is_calendar_match);
    if (type_match_count)
    {
        goto calendar_execution;
    }

    for (size_t i = 0; i < input_words.size(); i++)
    {
        for (std::string fact_word : fact.fact)
        {
            is_fact_match = is_fact_match | areWordsMostlySimilar(input_words[i], fact_word);
        }
    }
    type_match_count = uint(is_fact_match);
    if (type_match_count)
    {
        goto fact_execution;
    }

weather_execution:;
    {
        std::cout << output_prefix;
        for (size_t i = 0; i < type_match_count; i++)
        {
            std::cout << weather.intent_outputs[i] << " ";
        }

        return 1;
    }
calendar_execution:;
    {
        std::cout << output_prefix;
        for (size_t i = 0; i < type_match_count; i++)
        {
            std::cout << calendar.intent_outputs[i];
        }

        return 1;
    }
fact_execution:;
    {
        std::cout << output_prefix;
        for (size_t i = 0; i < type_match_count; i++)
        {
            std::cout << fact.intent_outputs[i];
        }

        return 1;
    }
}