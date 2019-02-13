#include <iostream>
#include <exception>
#include <sstream>

class MalformedInstructionException : public std::exception {
public:
    explicit MalformedInstructionException() = default;;

    explicit MalformedInstructionException(const char* msg)
    : msg(msg) {}
    const char* what() {
        return msg;
    }
private:
    const char* msg = nullptr;
};

int main() {
    std::string inst = "a CHAR a b";

    std::stringstream ss;
    ss << inst;

    int pc;
    ss >> pc;
    try {
        if (ss.fail()) {
            throw MalformedInstructionException("Invalid Op Code");
        }
    } catch (MalformedInstructionException &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}