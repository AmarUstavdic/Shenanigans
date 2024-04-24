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
public:

    Lexer(const std::string& src_code);


private:

    std::string in;


};
