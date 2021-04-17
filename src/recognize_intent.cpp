
#include <recognize_intent.h>
#include <are_words_similar.h>

#include <boost/algorithm/string.hpp>
#include <vector>
#include <string>
#include <iostream>

bool isSpecialCharacter(const char c)
{
    switch (c)
    {
        case '(':
        case ')':
        case '-':
        case '!':
        case '?':
        case '.':
        case ',':
            return true;
        default:
            return false;
    }
}

std::string recognizeIntent(std::string input_line, const bool debug_print)
{
    //* Remove special characers from input
    input_line.erase(std::remove_if(input_line.begin(), input_line.end(), &isSpecialCharacter), input_line.end());

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
    uint input_words_size = input_words.size();
    for (size_t i = 0; i < input_words_size; i++)
    {
        for (size_t j = 0; j < weather.array_size; j++)
        {
            is_weather_match = is_weather_match | areWordsSimilar(input_words[i], weather.weather[j], debug_print);
            is_city_match = is_city_match | areWordsSimilar(input_words[i], weather.city[j], debug_print);

            // Todo something similar
            // std::vector<std::string> two_city_words;
            // boost::split(two_city_words,  weather.city[j], [](char c) { return c == ' '; });
            // bool is_first_city_word_match = areWordsSimilar(two_city_words[0], weather.city[j], debug_print);
            // if (is_first_city_word_match and ...)
            if (is_weather_match + is_city_match < 2 and i < input_words_size - 1)
            {
                is_weather_match =
                    is_weather_match |
                    areWordsSimilar(input_words[i] + input_words[i + 1], weather.weather[j], debug_print);
                is_city_match =
                    is_city_match | areWordsSimilar(input_words[i] + input_words[i + 1], weather.city[j], debug_print);
            }
        }
    }
    type_match_count = uint(is_weather_match) + uint(is_city_match);
    if (is_weather_match)
    {
        return concatenateStringsToOutput(output_prefix, type_match_count, weather);
    }
    for (size_t i = 0; i < input_words_size; i++)
    {
        for (std::string calendar_word : calendar.calendar)
        {
            is_calendar_match = is_calendar_match | areWordsSimilar(input_words[i], calendar_word, debug_print);
        }
    }
    type_match_count = uint(is_calendar_match);
    if (is_calendar_match)
    {
        return concatenateStringsToOutput(output_prefix, type_match_count, calendar);
    }
    for (size_t i = 0; i < input_words_size; i++)
    {
        for (std::string fact_word : fact.fact)
        {
            is_fact_match = is_fact_match | areWordsSimilar(input_words[i], fact_word, debug_print);
        }
    }
    type_match_count = uint(is_fact_match);
    if (is_fact_match)
    {
        return concatenateStringsToOutput(output_prefix, type_match_count, fact);
    }

    return "No intent found";
}