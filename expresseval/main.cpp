#include <iostream>
#include <cctype>
#include <string>
#include <vector>

enum class TokenType {
    INTEGER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LPAREN,
    RPAREN,
    END,
    ERROR
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
private:
    std::string expression;
    size_t current_pos;

public:
    Lexer(const std::string& expr) : expression(expr), current_pos(0) {}

    Token getNextToken() {
        while (current_pos < expression.size()) {
            char c = expression[current_pos++];
            switch (c) {
                case ' ': continue; // Skip whitespace
                case '+': return {TokenType::PLUS, "+"};
                case '-': return {TokenType::MINUS, "-"};
                case '*': return {TokenType::MULTIPLY, "*"};
                case '/': return {TokenType::DIVIDE, "/"};
                case '(': return {TokenType::LPAREN, "("};
                case ')': return {TokenType::RPAREN, ")"};
                default:
                    if (std::isdigit(c)) {
                        std::string num;
                        num += c;
                        while (current_pos < expression.size() && std::isdigit(expression[current_pos])) {
                            num += expression[current_pos++];
                        }
                        return {TokenType::INTEGER, num};
                    } else {
                        return {TokenType::ERROR, "Invalid token"};
                    }
            }
        }
        return {TokenType::END, ""}; // End of input
    }
};

int main() {
    std::string expression = "3 + 4 * (2 - 1)";
    Lexer lexer(expression);

    Token token;
    do {
        token = lexer.getNextToken();
        std::cout << "Token type: " << static_cast<int>(token.type) << ", Value: " << token.value << std::endl;
    } while (token.type != TokenType::END);


    return 0;
}
