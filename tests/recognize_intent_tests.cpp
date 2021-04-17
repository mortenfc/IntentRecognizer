
#include <iostream>
#include <string>
#include <recognize_intent.h>
#include <gtest/gtest.h>

TEST(recognizeIntent, basic_line_input)
{
    // std::string input_line = "Am I free at 13:00 PM tomorrow?";
    // std::string input_line = "What is the weather like in New York today?";
    // std::string input_line = "What is the weather like in Paris today?";
    // std::string input_line = "What is the weather like today?";
    // * What is the weather like today? => Prints (Intent: Get Weather)
    // * What is the weather like in Paris today? => Prints (Intent: Get Weather City)
    // * What is the weather like in New York today? => Prints (Intent: Get Weather City)
    // * Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
    // * Tell me an interesting fact. => Prints (Intent: Get Fact)

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

TEST(recognizeIntent, same_size_words_different_chars)
{
    std::string output_fail = "No intent found";
    std::string input_line = "What is the waether like tuday?";
    std::string output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";
    input_line = "Whatis the wether like tday?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather") << "With input line: \"" + input_line + "\"";

    input_line = "What is the wether like in Pais today?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the wther like in Pariz tday?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";
    input_line = "What is the wer like in Pri tdy?";
    output = recognizeIntent(input_line);
    ASSERT_EQ(output, output_fail) << "With input line: \"" + input_line + "\"";

    // input_line = "What is the weather like in New York today?";
    // output = recognizeIntent(input_line);
    // ASSERT_EQ(output, "Intent: Get Weather City") << "With input line: \"" + input_line + "\"";

    // input_line = "Am I free at 13:00 PM tomorrow?";
    // output = recognizeIntent(input_line);
    // ASSERT_EQ(output, "Intent: Check Calendar") << "With input line: \"" + input_line + "\"";

    // input_line = "Tell me an interesting fact.";
    // output = recognizeIntent(input_line);
    // ASSERT_EQ(output, "Intent: Get Fact") << "With input line: \"" + input_line + "\"";
}

TEST(recognizeIntent, different_size_words_different_chars)
{
    ASSERT_TRUE(true);
}