#ifndef PARSEREXCP_H
#define PARSEREXCP_H

#include <exception>
#include <string>

namespace ParserExcp {

    class TokenAnomalo : public std::exception {
        private:
            std::string _token;

        public:
            TokenAnomalo(std::string token);
            const char* what() const throw();
            std::string GetToken();
    };
}

#endif