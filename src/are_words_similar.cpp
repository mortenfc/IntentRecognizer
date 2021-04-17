#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>

#include <are_words_similar.h>

uint findFirstMismatchIndex(const uint short_word_size, const std::string& long_word, const std::string& short_word)
{
    uint first_mismatch_index = 0;
    for (int i = 0; i < short_word_size; i++)
    {
        if (short_word[i] != long_word[i])
        {
            first_mismatch_index = i;
            break;
        }
    }

    return first_mismatch_index;
}

bool isMatchWithLongWordSkipping(const uint short_word_size,
                                 const uint long_word_size,
                                 const std::string& long_word,
                                 const std::string& short_word,
                                 const float min_charactor_percentage_match,
                                 const uint first_mismatch_index,
                                 const bool debug_print)
{
    //* Inverts short word and long word for DRY.
    return isMatchWithShortWordSkipping(short_word_size,
                                        long_word_size,
                                        short_word,
                                        long_word,
                                        min_charactor_percentage_match,
                                        first_mismatch_index,
                                        debug_print,
                                        "isMatchWithLongWordSkipping",
                                        true);
}

bool isMatchWithShortWordSkipping(const uint short_word_size,
                                  const uint long_word_size,
                                  const std::string& long_word,
                                  const std::string& short_word,
                                  const float min_charactor_percentage_match,
                                  const uint first_mismatch_index,
                                  const bool debug_print,
                                  const std::string& title,
                                  const bool words_are_inverted_but_not_sizes)
{
    uint char_match_count = 0;
    uint short_word_char_count_skip = 1;
    float match_percentage;
    bool is_match = false;
    while (short_word_char_count_skip <= 2 and not is_match)
    {
        char_match_count = 0;
        uint short_word_idx = 0;
        uint smaller_size;
        if (words_are_inverted_but_not_sizes)
        {
            smaller_size = std::min(short_word_size, long_word_size - short_word_char_count_skip);
        }
        else
        {
            smaller_size = std::min(short_word_size - short_word_char_count_skip, long_word_size);
        }
        for (int i = 0; i < smaller_size; i++)
        {
            if (i >= first_mismatch_index)
            {
                short_word_idx = i + short_word_char_count_skip;
            }
            else
            {
                short_word_idx = i;
            }
            if (short_word[short_word_idx] == long_word[i])
            {
                char_match_count++;
            }
        }
        short_word_char_count_skip++;
        match_percentage = 100.0 * char_match_count / long_word_size;
        is_match = match_percentage >= min_charactor_percentage_match;
    }
    if (is_match and debug_print)
    {
        std::cout << "-----------------" << title << "----------------\n";
        std::cout << "match_percentage: " << match_percentage << std::endl;
        std::cout << "char_match_count: " << char_match_count << std::endl;
        std::cout << "long_word_size: " << long_word_size << std::endl;
        std::cout << "short_word_char_count_skip: " << short_word_char_count_skip << std::endl;
        std::cout << "long_word: " << long_word << std::endl;
        std::cout << "short_word: " << short_word << std::endl;
        std::cout << "first_mismatch_index: " << first_mismatch_index << std::endl;
        return true;
    }
    return is_match;
}

bool isMatchWithoutSkipping(const uint short_word_size,
                            const uint long_word_size,
                            const std::string& long_word,
                            const std::string& short_word,
                            const float min_charactor_percentage_match,
                            const bool debug_print)
{
    const uint delta_size = long_word_size - short_word_size;
    uint char_match_count = 0;
    float match_percentage;
    bool is_match = false;
    uint short_word_char_count_skip = 0;
    do
    {
        char_match_count = 0;
        for (int i = 0; i < short_word_size; i++)
        {
            if (short_word[i + short_word_char_count_skip] == long_word[i])
            {
                char_match_count++;
            }
        }
        short_word_char_count_skip++;
        match_percentage = 100.0 * char_match_count / long_word_size;
        is_match = match_percentage >= min_charactor_percentage_match;

    } while (short_word_char_count_skip <= delta_size and not is_match);

    if (is_match and debug_print)
    {
        std::cout << "-----------------isMatchWithoutSkipping-----------------\n";
        std::cout << "match_percentage: " << match_percentage << std::endl;
        std::cout << "char_match_count: " << char_match_count << std::endl;
        std::cout << "long_word_size: " << long_word_size << std::endl;
        std::cout << "delta_size: " << delta_size << std::endl;
        std::cout << "long_word: " << long_word << std::endl;
        std::cout << "short_word: " << short_word << std::endl;
        return true;
    }
    return is_match;
}

bool areWordsSimilar(std::string word_1,
                     std::string word_2,
                     const bool debug_print,
                     const float min_charactor_percentage_match,
                     const bool is_case_sensitive)
{
    if (not is_case_sensitive)
    {
        boost::to_lower(word_1);
        boost::to_lower(word_2);
    }

    std::string short_word, long_word;
    if (word_1.size() > word_2.size())
    {
        long_word = word_1;
        short_word = word_2;
    }
    else
    {
        long_word = word_2;
        short_word = word_1;
    }
    uint short_word_size = short_word.size();
    uint long_word_size = long_word.size();
    if (isMatchWithoutSkipping(
            short_word_size, long_word_size, long_word, short_word, min_charactor_percentage_match, debug_print))
    {
        return true;
    }
    else
    {
        //* At first mismatch, try shifting each word up to 2 characters forwards and then comparing
        uint first_mismatch_index = findFirstMismatchIndex(short_word_size, long_word, short_word);

        if (isMatchWithShortWordSkipping(short_word_size,
                                         long_word_size,
                                         long_word,
                                         short_word,
                                         min_charactor_percentage_match,
                                         first_mismatch_index,
                                         debug_print))
        {
            return true;
        }

        if (isMatchWithLongWordSkipping(short_word_size,
                                        long_word_size,
                                        long_word,
                                        short_word,
                                        min_charactor_percentage_match,
                                        first_mismatch_index,
                                        debug_print))
        {
            return true;
        }
    }

    return false;
}