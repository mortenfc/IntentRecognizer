#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>

#include <are_words_similar.h>

bool areWordsSimilar(std::string word_1,
                     std::string word_2,
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
    uint delta_size = long_word_size - short_word_size;
    uint short_word_char_count_skip = 0;
    uint char_match_count = 0;
    // std::cout << "\nSize matching:\n";
    do
    {
        for (int i = 0; i < short_word_size; i++)
        {
            if (short_word[i + short_word_char_count_skip] == long_word[i])
            {
                char_match_count++;
            }
        }
        short_word_char_count_skip++;
    } while (short_word_char_count_skip <= delta_size);

    float match_percentage = 100.0 * char_match_count / long_word_size;
    bool is_match = match_percentage > min_charactor_percentage_match;
    if (is_match)
    {
        std::cout << "\nSize matching:\n";
        std::cout << "match_percentage: " << match_percentage << std::endl;
        std::cout << "char_match_count: " << char_match_count << std::endl;
        std::cout << "long_word_size: " << long_word_size << std::endl;
        std::cout << "delta_size: " << delta_size << std::endl;
        return true;
    }
    else
    {
        //* At first mismatch, try shifting each word up to 2 characters forwards and then comparing
        // std::cout << "\nFirst mismatch index:\n";
        uint first_mismatch_index = 0;
        for (int i = 0; i < short_word_size; i++)
        {
            if (short_word[i] != long_word[i])
            {
                first_mismatch_index = i;
                break;
            }
        }
        // std::cout << "\nShort word skip at first mismatch:\n";
        char_match_count = 0;
        short_word_char_count_skip = 1;
        while (short_word_char_count_skip <= 2)
        {
            uint short_word_idx = 0;
            uint smaller_size = std::min(short_word_size - short_word_char_count_skip, long_word_size);
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
        }
        match_percentage = 100.0 * char_match_count / long_word_size;
        is_match = match_percentage > min_charactor_percentage_match;
        if (is_match)
        {
            std::cout << "\nShort word skip at first mismatch:\n";
            std::cout << "match_percentage: " << match_percentage << std::endl;
            std::cout << "char_match_count: " << char_match_count << std::endl;
            std::cout << "long_word_size: " << long_word_size << std::endl;
            std::cout << "short_word_char_count_skip: " << short_word_char_count_skip << std::endl;
            return true;
        }

        // std::cout << "\nLong word skip at first mismatch:\n";
        char_match_count = 0;
        uint long_word_char_count_skip = 1;
        while (long_word_char_count_skip <= 2)
        {
            uint long_word_idx = 0;
            uint smaller_size = std::min(short_word_size, long_word_size - long_word_char_count_skip);
            for (int i = 0; i < smaller_size; i++)
            {
                // std::cout << short_word[i] << " ";

                if (i >= first_mismatch_index)
                {
                    long_word_idx = i + long_word_char_count_skip;
                }
                else
                {
                    long_word_idx = i;
                }
                if (short_word[i] == long_word[long_word_idx])
                {
                    char_match_count++;
                }
            }
            long_word_char_count_skip++;
        }
        match_percentage = 100.0 * char_match_count / long_word_size;
        is_match = match_percentage > min_charactor_percentage_match;
        if (is_match)
        {
            std::cout << "\nLong word skip at first mismatch:\n";
            std::cout << "match_percentage: " << match_percentage << std::endl;
            std::cout << "char_match_count: " << char_match_count << std::endl;
            std::cout << "long_word_size: " << long_word_size << std::endl;
            std::cout << "long_word_char_count_skip: " << long_word_char_count_skip << std::endl;
            return true;
        }
    }

    return false;
}