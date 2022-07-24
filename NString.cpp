#include "NString.h"


NString::NString(const char* string){
    this->string = new char[strlen(string)+1];
    strcpy(this->string, string);
    this->len = strlen(string);
}

NString::NString(char* string, bool shallow){
    this->string = string;
    this->len = strlen(this->string);
}

NString::NString(const NString& string){
    this->string = new char[string.len+1];
    strcpy(this->string, string.string);
    this->len = string.len;
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

bool NString::contains(char* sub){
    for(int i = 0; i < this->len - strlen(sub); i++){
        if(strcmp(&(this->string[i]), sub) == 0) return true;
    }
    return false;
}

NString NString::substring(int start, int end){
    char* s = new char[end-start+2];
    memcpy(s, &(this->string[start]), end-start+1);
    s[end-start+1] = '\0'; 
    return NString(s, true);
}

std::vector<NString> NString::split(NString string){
    std::vector<NString> splitString;
    
    int activeStringIndex = 0;
    char* activeString = new char[this->len+1];

    char* buffer = new char[string.len+1];
    
    for(int i = 0; i < (this->len - string.len); i++){
        memcpy(buffer, &(this->string[i]), string.len);
        buffer[string.len] = '\0';
        if(strcmp(buffer, string.string) == 0){
            
        }
    }

    return splitString;

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
    this->string = new char[string.len+1];
    strcpy(this->string, string.string);
    return *this;
}


NString& NString::operator=(NString&& other) noexcept{
    delete[] this->string;
    this->string = other.string;
    return *this;
}

char NString::operator[](int index){
    return this->string[index];
}

NString NString::operator+(NString string){
    char* newString = new char[this->len + string.len + 1];
    newString[0] = '\0';
    strcat(newString, this->string);
    strcat(newString, string.string);
    return NString(newString, true);
}

NString NString::operator*(int n){
    char* newString = new char[this->len * n + 1];
    newString[0] = '\0';
    for(int i = 0; i < n; i++){
        strcat(newString, this->string);
    }
    return NString(newString, true);
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










