
#include <recognize_intent.h>
#include <are_words_similar.h>

#include <boost/algorithm/string.hpp>
#include <vector>
#include <string>
#include <iostream>

// * What is the weather like today? => Prints (Intent: Get Weather)
// * What is the weather like in Paris today? => Prints (Intent: Get Weather City)
// * What is the weather like in New York today? => Prints (Intent: Get Weather City)
// * Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
// * Tell me an interesting fact. => Prints (Intent: Get Fact)

std::string recognizeIntent(const std::string& input_line)
{
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
            is_weather_match = is_weather_match | areWordsSimilar(input_words[i], weather.weather[j]);
            is_city_match = is_city_match | areWordsSimilar(input_words[i], weather.city[j]);
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
            is_calendar_match = is_calendar_match | areWordsSimilar(input_words[i], calendar_word);
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
            is_fact_match = is_fact_match | areWordsSimilar(input_words[i], fact_word);
        }
    }
    type_match_count = uint(is_fact_match);
    if (type_match_count)
    {
        goto fact_execution;
    }

    return "No intent found";

weather_execution:;
    {
        std::string output = output_prefix;
        for (size_t i = 0; i < type_match_count; i++)
        {
            output += weather.intent_outputs[i] + " ";
        }

        return output;
    }
calendar_execution:;
    {
        std::string output = output_prefix;
        for (size_t i = 0; i < type_match_count; i++)
        {
            output += calendar.intent_outputs[i] + " ";
        }

        return output;
    }
fact_execution:;
    {
        std::string output = output_prefix;
        for (size_t i = 0; i < type_match_count; i++)
        {
            output += fact.intent_outputs[i] + " ";
        }

        return output;
    }
}