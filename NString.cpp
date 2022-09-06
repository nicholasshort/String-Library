#include "NString.h"


NString::NString(const char* string){
    this->len = strlen(string);
    this->string = new char[this->len];
    memcpy(this->string, string, len);
    
}

NString::NString(const NString& string){
    this->len = string.len;
    this->string = new char[string.len];
    memcpy(this->string, string.string, this->len);
}

NString::NString(NString&& other) noexcept{
    //std::cout << "Move!" << std::endl;
    this->string = other.string;
    this->len = other.len;

    other.string = nullptr;
    other.len = 0;
}

NString::~NString(){
    delete[] this->string;
}

uint32_t NString::length(){
    return this->len;
}

uint32_t NString::indexOf(char c){
    for(int i = 0; i < this->len; i++){
        if(string[i] == c) return i;
    }
    return -1;
}

uint32_t NString::count(char c){
    uint32_t count = 0;
    for(int i = 0; i < this->len; i++){
        if(this->string[i] == c) count++;
    }
    return count;
}


NString NString::substring(int start, int end){
    char* newString = new char[end-start+1];
    memcpy(newString, &(this->string[start]), end-start+1);
    newString[end-start+1] = '\0'; 
    return NString(newString);
}


NString::operator const char* () {
	return string;
}

//Copy assignment
NString& NString::operator=(const NString& string){
    
    //Guard Self-Assignment
    if(*this == string){
        return *this;
    }

    delete[] this->string;
    this->string = new char[string.len];
    memcpy(this->string, string.string, string.len);
    return *this;
}

//Move assignment
NString& NString::operator=(NString&& other) noexcept{

    if(this == &other) {
        this->len = 0;
        delete[] this->string;
        this->string = other.string;
        this->len = other.len;
    }

    return *this;
}

char NString::operator[](int index){
    return this->string[index];
}

NString NString::operator+(NString string){
    char* newString = new char[this->len + string.len];
    newString[0] = '\0';
    strcat(newString, this->string);
    strcat(newString, string.string);
    return NString(newString);
}

NString NString::operator*(int n){
    char* newString = new char[this->len * n];
    newString[0] = '\0';
    for(int i = 0; i < n; i++){
        strcat(newString, this->string);
    }
    return NString(newString);
}

bool NString::operator==(NString string){
    return strcmp(this->string, string.string) == 0;
}

std::ostream& operator<<(std::ostream& os, NString& string) {
    os << string.string;
    return os;
}

std::ostream& operator<<(std::ostream& os, NString&& string) {
    os << string.string;
    return os;
}










