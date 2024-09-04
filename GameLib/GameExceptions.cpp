//
// Created by John Moore on 9/1/24.
//

#include "GameExceptions.h"

InstanceNotAvailableException::InstanceNotAvailableException(const char* msg) :
    std::runtime_error(msg){
}

InstanceNotAvailableException::InstanceNotAvailableException(const std::string& msg) :
    std::runtime_error(msg) {
}

GameAlreadyStartedexception::GameAlreadyStartedexception(const char* msg) :
    std::runtime_error(msg){
}

GameAlreadyStartedexception::GameAlreadyStartedexception(const std::string& msg) :
    std::runtime_error(msg) {
}

NoGameInProgressException::NoGameInProgressException(const char* msg) :
    std::runtime_error(msg){
}

NoGameInProgressException::NoGameInProgressException(const std::string& msg) :
    std::runtime_error(msg) {
}

PlayerAlreadyExistsException::PlayerAlreadyExistsException(const char* msg) :
    std::runtime_error(msg){
}

PlayerAlreadyExistsException::PlayerAlreadyExistsException(const std::string& msg) :
    std::runtime_error(msg) {
}