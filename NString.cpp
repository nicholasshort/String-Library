#include "NString.h"

NString::NString(char* string){
    this->string = new char[strlen(string)+1];
    strcpy(this->string, string);
}

NString::NString(char* string, bool deep){
    this->string = string;
}

NString::NString(const char* string){
    this->string = new char[strlen(string)+1];
    strcpy(this->string, string);
}

NString::NString(const NString& string){
    this->string = new char[strlen(string.string)+1];
    strcpy(this->string, string.string);
}

NString::~NString(){
    delete[] this->string;
}

int NString::length(){
    return strlen(this->string);
}

int NString::indexOf(char c){
    for(int i = 0; i < this->length(); i++){
        if(string[i] == c) return i;
    }
    return -1;
}

// int NString::indexOf(NString string){
//     if(this->contains(string) )
// }

bool NString::contains(char* sub){
    for(int i = 0; i < this->length() - strlen(sub); i++){
        if(strcmp(&(this->string[i]), sub)) return true;
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

}

NString& NString::operator=(const NString& string){
    
    //Guard Self-Assignment
    if(*this == string){
        return *this;
    }

    delete[] this->string;
    this->string = new char[strlen(string.string)+1];
    strcpy(this->string, string.string);
    return *this;
}

char NString::operator[](int index){
    return this->string[index];
}

NString NString::operator+(NString string){
    char* newString = new char[this->length() + string.length() + 1];
    newString[0] = '\0';
    strcat(newString, this->string);
    strcat(newString, string.string);
    return NString(newString, true);
}

NString NString::operator*(int n){
    char* newString = new char[this->length() * n + 1];
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





