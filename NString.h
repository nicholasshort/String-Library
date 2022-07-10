//The best string library
#include <string.h>
#include <iostream>
#include <vector>
class NString{

private:
    char* string;

public:
    NString(char* string);
    NString(char* string, bool deep);
    NString(const char* string);
    NString(const NString& string);
    ~NString();

    int length();
    int indexOf(char c);
    bool contains(char* sub);
    NString substring(int start, int end);
    
    NString& operator=(const NString& string);
    NString operator+(NString string);
    NString operator*(int n);
    bool operator==(NString string);
    char operator[](int index);
    friend std::ostream& operator<<(std::ostream& os, NString& string);

    //TODO
    std::vector<NString> split(NString string);
    bool contains(NString string);
    int count(char c);
    int count(char* string);
};