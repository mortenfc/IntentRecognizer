#include <are_words_similar.h>
#include <gtest/gtest.h>

TEST(findFirstMismatchIndex, character_typo)
{
    std::string short_word = "waether";
    std::string long_word = "weather";

    uint first_mismatch_index = findFirstMismatchIndex(short_word.size(), long_word, short_word);

    ASSERT_EQ(first_mismatch_index, 1);
}

TEST(isMatchWithShortWordSkipping, length_mismatch_char_typo)
{
    std::string short_word = "weather";
    std::string long_word = "wetherrr";
    float min_charactor_percentage_match = 70.0;
    uint first_mismatch_index = 2;

    bool is_match = isMatchWithShortWordSkipping(short_word.size(),
                                                 long_word.size(),
                                                 long_word,
                                                 short_word,
                                                 min_charactor_percentage_match,
                                                 first_mismatch_index);
    ASSERT_TRUE(is_match);
    is_match = isMatchWithLongWordSkipping(short_word.size(),
                                           long_word.size(),
                                           long_word,
                                           short_word,
                                           min_charactor_percentage_match,
                                           first_mismatch_index);
    ASSERT_FALSE(false);

    short_word = "wher";
    long_word = "weather";
    min_charactor_percentage_match = 10.0;
    first_mismatch_index = 1;
    is_match = isMatchWithLongWordSkipping(short_word.size(),
                                           long_word.size(),
                                           long_word,
                                           short_word,
                                           min_charactor_percentage_match,
                                           first_mismatch_index);
    ASSERT_TRUE(is_match);

    short_word = "weather";
    long_word = "wther";
    min_charactor_percentage_match = 90.0;
    first_mismatch_index = 1;
    is_match = isMatchWithLongWordSkipping(short_word.size(),
                                           long_word.size(),
                                           long_word,
                                           short_word,
                                           min_charactor_percentage_match,
                                           first_mismatch_index);
    ASSERT_FALSE(is_match);

    short_word = "wather";
    long_word = "weather";
    min_charactor_percentage_match = 100.0;
    first_mismatch_index = 1;
    is_match = isMatchWithLongWordSkipping(short_word.size(),
                                           long_word.size(),
                                           long_word,
                                           short_word,
                                           min_charactor_percentage_match,
                                           first_mismatch_index);
    ASSERT_FALSE(is_match);
}

TEST(isMatchWithLongWordSkipping, all_checks)
{
    std::string short_word = "weather";
    std::string long_word = "wether";
    float min_charactor_percentage_match = 70.0;
    uint first_mismatch_index = 2;
    bool is_match = isMatchWithLongWordSkipping(short_word.size(),
                                                long_word.size(),
                                                long_word,
                                                short_word,
                                                min_charactor_percentage_match,
                                                first_mismatch_index);
    ASSERT_FALSE(is_match);
    is_match = isMatchWithShortWordSkipping(short_word.size(),
                                                 long_word.size(),
                                                 long_word,
                                                 short_word,
                                                 min_charactor_percentage_match,
                                                 first_mismatch_index);
    ASSERT_TRUE(is_match);

    long_word = "wher";
    short_word = "weather";
    min_charactor_percentage_match = 10.0;
    first_mismatch_index = 1;
    is_match = isMatchWithLongWordSkipping(short_word.size(),
                                           long_word.size(),
                                           long_word,
                                           short_word,
                                           min_charactor_percentage_match,
                                           first_mismatch_index);
    ASSERT_TRUE(is_match);

    long_word = "weather";
    short_word = "wther";
    min_charactor_percentage_match = 90.0;
    first_mismatch_index = 1;
    is_match = isMatchWithLongWordSkipping(short_word.size(),
                                           long_word.size(),
                                           long_word,
                                           short_word,
                                           min_charactor_percentage_match,
                                           first_mismatch_index);
    ASSERT_FALSE(is_match);

    long_word = "wather";
    short_word = "weather";
    min_charactor_percentage_match = 100.0;
    first_mismatch_index = 1;
    is_match = isMatchWithLongWordSkipping(short_word.size(),
                                           long_word.size(),
                                           long_word,
                                           short_word,
                                           min_charactor_percentage_match,
                                           first_mismatch_index);
    ASSERT_FALSE(is_match);
}

TEST(areWordsSimilar, all_checks)
{
    std::string word_1 = "weather";
    std::string word_2 = "weather";
    float min_charactor_percentage_match = 100.0;
    bool is_match = areWordsSimilar(word_1, word_2, min_charactor_percentage_match);
    ASSERT_TRUE(is_match);

    word_1 = "wEaTher";
    word_2 = "WeatheR";
    min_charactor_percentage_match = 100.0;
    is_match = areWordsSimilar(word_1, word_2, min_charactor_percentage_match);
    ASSERT_TRUE(is_match);

    word_1 = "wEthEr";
    word_2 = "weaTher";
    min_charactor_percentage_match = 80.0;
    is_match = areWordsSimilar(word_1, word_2, min_charactor_percentage_match);
    ASSERT_TRUE(is_match);

    word_1 = "wher";
    word_2 = "weather";
    min_charactor_percentage_match = 20.0;
    is_match = areWordsSimilar(word_1, word_2, min_charactor_percentage_match);
    ASSERT_TRUE(is_match);

    word_1 = "weather";
    word_2 = "wther";
    min_charactor_percentage_match = 90.0;
    is_match = areWordsSimilar(word_1, word_2, min_charactor_percentage_match);
    ASSERT_FALSE(is_match);

    word_1 = "wather";
    word_2 = "weather";
    min_charactor_percentage_match = 80.0;
    is_match = areWordsSimilar(word_1, word_2, min_charactor_percentage_match);
    ASSERT_TRUE(is_match);

    word_1 = "watherrr";
    word_2 = "Weather";
    min_charactor_percentage_match = 60.0;
    is_match = areWordsSimilar(word_1, word_2, min_charactor_percentage_match);
    ASSERT_TRUE(is_match);

    word_1 = "wwweatherrr";
    word_2 = "Weather";
    min_charactor_percentage_match = 60.0;
    is_match = areWordsSimilar(word_1, word_2, min_charactor_percentage_match);
    ASSERT_TRUE(is_match);

    word_1 = "wwweatherrrr";
    word_2 = "Weather";
    min_charactor_percentage_match = 60.0;
    is_match = areWordsSimilar(word_1, word_2, min_charactor_percentage_match);
    ASSERT_FALSE(is_match);
}