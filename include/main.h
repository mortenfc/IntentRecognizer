#ifndef MAIN
#define MAIN

#include <iostream>
#include <string>
#include <array>
#include <istream>

// * What is the weather like today? => Prints (Intent: Get Weather)
// * What is the weather like in Paris today? => Prints (Intent: Get Weather City)
// * What is the weather like in New York today? => Prints (Intent: Get Weather City)
// * Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
// * Tell me an interesting fact. => Prints (Intent: Get Fact)

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

#endif /* MAIN */
