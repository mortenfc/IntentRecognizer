
#include <iostream>
#include <string>
#include <recognize_intent.h>
#include <gtest/gtest.h>

const bool DEBUG_PRINT = false;

TEST(recognizeIntent, basic_line_input)
{
    std::string input_line = "What is the weather like today?";
    std::string output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";

    input_line = "What is the weather like in Paris today?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";

    input_line = "What is the weather like in New York today?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";

    input_line = "Am I free at 13:00 PM tomorrow?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";

    input_line = "Tell me an interesting fact.";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Fact") << "With input line: \"" + input_line + "\"";
}

TEST(recognizeIntent, mixed_up_words)
{
    //* Setup
    std::string output_fail = "No intent found", input_line, output;

    //* Weather
    input_line = "What is the waether like tuday?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "Whatis the wether like tday?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "Will it rain tomorrow?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "Will it rayn?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "It will rayn..! Right?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "Will it ran?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "Will it rn?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";

    //* Weather City
    input_line = "What is the wether like in Pais today?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the wther like in Pariz tday?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the wher like in Paris tdy?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";
    input_line = "What is the weather like in New York today?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the weather like in NewYork today?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the weather like in N York today?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "What is the weather like in NYork today?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "What is the bear like in NYork?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";
    input_line = "Will it rain tomorrow in Paris?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "Wil it rayn! tomorow in Pris?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "Wil it rn over in Pris?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";
    // todo: following line has bug with merging "rn in" to "rnin" and matching it with "rain"
    // todo: input_line = "Wil it rn in Pris?";
    // todo fix could be to only include next word if first word had a match

    //* Calendar
    input_line = "What is something like in NYork tomorrow?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";
    input_line = "Am I free at 13:00 PM tomorrow?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";
    input_line = "Am I fre at 13:00 PM?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";
    input_line = "Am I alive at 13:00 PM?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";
    input_line = "Do I have an appointment at 13:00pm tomorrow?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";
    input_line = "Do I have something really nice at 13:00pm tomorrow?";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";

    //* Fact
    input_line = "Tell me an interesting fact.";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Fact") << "With input line: \"" + input_line + "\"";
    input_line = "Tell me an some knowledg";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Fact") << "With input line: \"" + input_line + "\"";
    input_line = "I am boed";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, "Intent: Get Fact") << "With input line: \"" + input_line + "\"";
    input_line = "I am bod";
    output = recognizeIntent(input_line, DEBUG_PRINT);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";
}

TEST(recognizeIntent, different_size_words_different_chars)
{
    ASSERT_TRUE(true);
}