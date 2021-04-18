# Intent Recognizer - proof of concept
- It matches certain words to certain categories to guess your intent.
- It can detect most spelling mistakes by not requring a 100% character match, but a specificaly amount, given as 
default param in [this file](include/are_words_similar.h)

## The unit tests tell the limitations and extent of functionality, check them out
[Link to system tests](./tests/recognize_intent_tests.cpp).
[Link to unit tests](./tests/are_words_similar_tests.cpp).
[Link to words that are searched for](./include/are_words_similar.h).
To run the unit tests,
"""bash
bash test_run_after_build.sh
"""

## Running the cin cout wrapper of the intent recognizer
"""bash
bash main_run_after_build.sh
"""

## Requirements of project
[Link to markdown](./challenges_IntentRecognizer).