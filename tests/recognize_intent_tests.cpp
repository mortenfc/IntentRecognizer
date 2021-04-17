
#include <iostream>
#include <string>
#include <recognize_intent.h>
#include <gtest/gtest.h>

TEST(recognizeIntent, basic_line_input)
{
    std::string input_line = "What is the weather like today?";
    std::string output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";

    input_line = "What is the weather like in Paris today?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";

    input_line = "What is the weather like in New York today?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";

    input_line = "Am I free at 13:00 PM tomorrow?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";

    input_line = "Tell me an interesting fact.";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Fact") << "With input line: \"" + input_line + "\"";
}

TEST(recognizeIntent, mixed_up_words)
{
    std::string output_fail = "No intent found";
    std::string input_line = "What is the waether like tuday?";
    std::string output = recognizeIntent(input_line);

    //* Weather
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "Whatis the wether like tday?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";

    //* Weather City
    input_line = "What is the wether like in Pais today?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the wther like in Pariz tday?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the wher like in Paris tdy?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";
    input_line = "What is the weather like in New York today?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the weather like in NewYork today?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the weather like in N York today?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "What is the weather like in NYork today?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "What is the bear like in NYork?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";

    //* Calendar
    input_line = "What is something like in NYork tomorrow?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";
    input_line = "Am I free at 13:00 PM tomorrow?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";
    input_line = "Am I fre at 13:00 PM?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";
    input_line = "Am I alive at 13:00 PM?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";
    input_line = "Do I have an appointment at 13:00pm tomorrow?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";    
    input_line = "Do I have something really nice at 13:00pm tomorrow?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";

    //* Fact
    input_line = "Tell me an interesting fact.";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Fact") << "With input line: \"" + input_line + "\"";
    input_line = "Tell me an some knowledg";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Fact") << "With input line: \"" + input_line + "\"";
    input_line = "I am boed";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Fact") << "With input line: \"" + input_line + "\"";
    input_line = "I am bod";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";
}

TEST(recognizeIntent, different_size_words_different_chars)
{
    ASSERT_TRUE(true);
}