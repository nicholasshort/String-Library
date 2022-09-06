//The best string library
#include <cstring>
#include <cstdlib>
#include <iostream>

#ifndef NSTRING_H
#define NSTRING_H

class NString{

private:
    char* string;
    uint32_t len; 

public:
    NString(const char* string);
    //Copy Constructor
    NString(const NString& string);
    //Move Constructor
    NString(NString&& other) noexcept;
    ~NString();

    uint32_t length();
    uint32_t indexOf(char c);
    uint32_t count(char c);
    NString substring(int start, int end);

    //Copy Assignment
    NString& operator=(const NString& string);
    //Move Assignment
    NString& operator=(NString&& other) noexcept;
    
    operator const char* ();
    NString operator+(NString string);
    NString operator*(int n);
    bool operator==(NString string);
    char operator[](int index);
    friend std::ostream& operator<<(std::ostream& os, NString& string);
    friend std::ostream& operator<<(std::ostream& os, NString&& string);

};

#endif