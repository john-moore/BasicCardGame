#ifndef GAMEEXCEPTIONS_H
#define GAMEEXCEPTIONS_H
#include <stdexcept>

class InstanceNotAvailableException : public std::runtime_error {
public:
    explicit InstanceNotAvailableException(const char* msg);
    explicit InstanceNotAvailableException(const std::string& msg);
};

class GameAlreadyStartedexception : public std::runtime_error {
public:
    explicit GameAlreadyStartedexception(const char* msg);
    explicit GameAlreadyStartedexception(const std::string& msg);
};

class NoGameInProgressException : public std::runtime_error {
public:
    explicit NoGameInProgressException(const char* msg);
    explicit NoGameInProgressException(const std::string& msg);
};

class PlayerAlreadyExistsException : public std::runtime_error {
public:
    explicit PlayerAlreadyExistsException(const char* msg);
    explicit PlayerAlreadyExistsException(const std::string& msg);
};


#endif //GAMEEXCEPTIONS_H
