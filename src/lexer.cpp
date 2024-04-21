#include "lexer.h"
#include <regex>

std::vector<std::pair<std::string, std::string>> TOKENS = {
    {"IDENTIFIER", "[a-zA-Z_][a-zA-Z0-9_]*"},
    {"KEYWORD", "if|else|while|for|int|char|print|println|scanf"},
    {"INTEGER_LITERAL", "[0-9]+"},
    {"STRING_LITERAL", "\"([^\"\\\\]|\\\\.)*\""},
    {"OPERATOR", "\\+|-|\\*|/|%|==|!=|<|<=|>|>=|&&|\\|\\|"},
    {"PUNCTUATION", "\\{|\\}|\\(|\\)|\\[|\\]|,|;"}
};

std::vector<Token> lex(const std::string& input_string) {
    std::vector<Token> tokens;
    std::smatch match;

    std::string remaining_input = input_string;
    while (!remaining_input.empty()) {
        for (const auto& token : TOKENS) {
            if (std::regex_search(remaining_input, match, std::regex("^" + token.second))) {
                tokens.push_back({token.first, match[0]});
                remaining_input = match.suffix();
                break;
            }
        }
    }

    return tokens;
}
