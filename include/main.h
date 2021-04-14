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

enum class Category
{
    weather,
    calendar
};

struct Weather
{
    std::array<std::string, 6> mappings{
        "weather",
        "rain",
        "sunny",
        "warm",
        "snow",
        "wet"};

    std::array<std::string, 6> capitals{
        "Copenhagen",
        "New York",
        "Stockholm",
        "Oslo",
        "Paris",
        "Berlin"};

    std::array<std::string, 2> intent_outputs{
        "Weather",
        "City"};

    // struct Capitals
    // {
    //     std::string Copenhagen : "Copenhagen";
    //     std::string New York : "New York";
    //     std::string Stockholm : "Stockholm";
    //     std::string Oslo : "Oslo";
    //     std::string Paris : "Paris";
    //     std::string Berlin : "Berlin";
    // };
};

struct Calendar
{
    std::array<std::string, 6> mappings{
        "weather",
        "rain",
        "sunny",
        "warm",
        "snow",
        "wet"};

    std::array<std::string, 6> capitals{
        "Copenhagen",
        "New York",
        "Stockholm",
        "Oslo",
        "Paris",
        "Berlin"};

    std::array<std::string, 2> intent_outputs{
        "Weather",
        "City"};
};

#endif /* MAIN */
