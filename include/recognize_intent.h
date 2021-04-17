
#ifndef RECOGNIZEINTENT_H
#define RECOGNIZEINTENT_H

#include <string>
#include <array>

struct Weather
{
    static const uint array_size = 6;

    std::array<std::string, array_size> weather{"weather", "rain", "sunny", "warm", "snow", "wet"};

    std::array<std::string, array_size> city{"Copenhagen", "New York", "Stockholm", "Oslo", "Paris", "Berlin"};

    std::array<std::string, 2> intent_outputs{"Get Weather", "City"};
};

struct Calendar
{
    std::array<std::string, 6> calendar{"tomorrow", "free", "time", "available", "today", "after tomorrow"};

    std::array<std::string, 1> intent_outputs{"Check Calendar"};
};

struct Fact
{
    std::array<std::string, 6> fact{"fact", "interesting", "bored", "something", "random", "knowledge"};

    std::array<std::string, 1> intent_outputs{"Get Fact"};
};

template <class T>
std::string
    concatenateStringsToOutput(const std::string& output_prefix, const uint type_match_count, const T& type_structure)
{
    std::string output = output_prefix;
    for (size_t i = 0; i < type_match_count; i++)
    {
        output += type_structure.intent_outputs[i] + " ";
    }
    output.pop_back();

    return output;
};

std::string recognizeIntent(const std::string& input_line, const bool debug_print = false);

#endif /* RECOGNIZEINTENT_H */
