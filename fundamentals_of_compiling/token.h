
/************************************************
#
#      Filename: token.h
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-04-21 09:17:03
# Last Modified: 2021-04-21 09:17:03
#***********************************************/

#ifndef __TOKEN_H
#define __TOKEN_H
#include <string>

enum class TokenType{
    KEYWORD,
    VARIABLE,
    OPERATOR,
    BRACKET,
    STRING,
    FLOAT,
    BOOLEAN
};

class Token{
    public:

    private:
        TokenType type;

};

#endif //TOKEN_H
