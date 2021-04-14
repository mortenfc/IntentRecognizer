#include "main.h"

// * What is the weather like today? => Prints (Intent: Get Weather)
// * What is the weather like in Paris today? => Prints (Intent: Get Weather City)
// * What is the weather like in New York today? => Prints (Intent: Get Weather City)
// * Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
// * Tell me an interesting fact. => Prints (Intent: Get Fact)

bool isWordProbablySimilarTo(const std::string& to_test, const std::string& ground_truth, float min_charactor_percentage_match = 80.0, bool is_case_sensitive = false) 
{
    
}

void main()
{
    // std::string in = "Tell me an interesting fact.";
    // std::string in = "Am I free at 13:00 PM tomorrow?";
    // std::string in = "What is the weather like in New York today?";
    // std::string in = "What is the weather like in Paris today?";
    std::string in = "What is the weather like today?";
    std::istringstream iss(in);
    std::vector<std::string> input_words(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>();

    Category category;
    Weather weather;

    for (size_t i = 0; i < input_words.size(); i++)
    {
        for (std::string weather_word in weather.mappings)
        {
            bool is_word_match = isWordProbablySimilarTo(input_words[i], weather_word);
            if (weather_word == input_words[i])
            {
                category = Category::weather;
            }
        }
        for (std::string calendar_word in calendar.mappings)
        {
            if (calendar_word == input_words[i])
            {
                category = Category::calendar;
            }
        }        
    }
}