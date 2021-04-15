#include <string>

#ifndef AREWORDSSIMILAR
#define AREWORDSSIMILAR

bool areWordsSimilar(std::string word_1,
                     std::string word_2,
                     const float min_charactor_percentage_match = 80.0,
                     const bool is_case_sensitive = false);

#endif /* AREWORDSSIMILAR */
