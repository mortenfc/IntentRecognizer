
#include <string>
#include <array>

#ifndef RECOGNIZEINTENT
#define RECOGNIZEINTENT

void recognizeIntent(const std::string& input_line);

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

#endif /* RECOGNIZEINTENT */
