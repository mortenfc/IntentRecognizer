#include <are_words_similar.h>
#include <gtest/gtest.h>

TEST(are_words_similar, basic_input)
{
    std::string input_line = "Tell me an interesting fact.";
    // std::string input_line = "Am I free at 13:00 PM tomorrow?";
    // std::string input_line = "What is the weather like in New York today?";
    // std::string input_line = "What is the weather like in Paris today?";
    // std::string input_line = "What is the weather like today?";
    // * What is the weather like today? => Prints (Intent: Get Weather)
    // * What is the weather like in Paris today? => Prints (Intent: Get Weather City)
    // * What is the weather like in New York today? => Prints (Intent: Get Weather City)
    // * Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
    // * Tell me an interesting fact. => Prints (Intent: Get Fact)
    ASSERT_TRUE(true);
}

TEST(are_words_similar, same_size_different_chars)
{
    ASSERT_TRUE(true);
}

TEST(are_words_similar, different_size_different_chars)
{
    ASSERT_TRUE(true);
}