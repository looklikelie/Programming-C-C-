#pragma once
#include <exception>

class MyQueueException : public std::exception{};

class ExistExeption : public MyQueueException{
public:
    const char* what() const throw() override{
        return "Matrix is smaller then index!\n";
    }
};


class EmptyException : public MyQueueException{
public:
    const char* what() const throw() override{
        return "Array is empty:!\n";
    }
};
