
#include <iostream>
using namespace std;

#include "String.h"


String::String() { 
    size = 0;
    str = new char[1];
    str[0] = '\0';
}


String::String(char c) {
    size = 1;
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
}


String::String(const char *s) {

	size = count(s);
	str = new char[size+1];
	int i = 0;
	while (i < size) {
		str[i] = (const char) *(s+ i);
		i++;
	}
	//str[size] = '\0';
}

//Hilfsfunktion
int String::count(const char *s){
	int i = 0;
	while (*s != '\0'){
		s++;
		i++;
	}
	return i++;
}

String::String(const String& s) {
	
	//TODO
	size = s.size;
	str = new char[size+1];
	for (int i = 0 ; i < size; i++){
	    str[i]=s.str[i];
	}
	str[size] ='\0';
	
}

String::~String() { delete[] str; }

char& String::operator[](int index) {
	
	return str[index];
	//int s = this& + sizeof(char) * index;
	//TODO
}

//String::String(const String& src) {c = new String(*src.c);}

String& String::operator=(String& s) {
	// TODO
	//deep copy
	if(this != &s) {
      delete[] str;
      size = s.size;
	  str = new char[size+1];
	  for (int i = 0 ; i < size; i++){
	    str[i]=s.str[i];
	  }
	  str[size] ='\0';
    }
    return *this;
}

String& String::operator+=(String& s) {
  
  // TODO
  String copyString = String(*this);
  delete[] str;
  size = this->size + s.size;
  str = new char[size];
  for (int i = 0 ; i < copyString.size ; i++){
      str[i] = copyString.str[i];
  }
  int j = 0;
  for (int i = copyString.size; i < size ; i++) {
      str[i] =s.str[j];
      j++;
  }
  str[size] = '\0';
  
  return *this;
}
