#ifndef AREWORDSSIMILAR_H
#define AREWORDSSIMILAR_H

#include <string>

uint findFirstMismatchIndex(const uint short_word_size, const std::string& long_word, const std::string& short_word);

bool isMatchWithLongWordSkipping(const uint short_word_size,
                                 const uint long_word_size,
                                 const std::string& long_word,
                                 const std::string& short_word,
                                 const float min_charactor_percentage_match,
                                 const uint first_mismatch_index,
                                 const bool debug_print = false);

bool isMatchWithShortWordSkipping(const uint short_word_size,
                                  const uint long_word_size,
                                  const std::string& long_word,
                                  const std::string& short_word,
                                  const float min_charactor_percentage_match,
                                  const uint first_mismatch_index,
                                  const bool debug_print = false,
                                  const std::string& title = "isMatchWithShortWordSkipping",
                                  const bool words_are_inverted_but_not_sizes = false);

bool isMatchWithoutSkipping(const uint short_word_size,
                            const uint long_word_size,
                            const std::string& long_word,
                            const std::string& short_word,
                            const float min_charactor_percentage_match,
                            const bool debug_print);

bool areWordsSimilar(std::string word_1,
                     std::string word_2,
                     const float min_charactor_percentage_match = 70.0,
                     const bool is_case_sensitive = false,
                     const bool debug_print = false);
#endif /* AREWORDSSIMILAR_H */
