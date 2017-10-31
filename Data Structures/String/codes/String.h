#ifndef STRING_H_
#define STRING_H_

#include <iostream>
#include <stddef.h>
#include <string.h>

class String
{
public:
        String();                       // A String object with length 0
        String(size_t len);             // A String object with len blanks
        String(const char * str);       // A String object that is pointed by str
        String(const String & s);       // A String object that is referenced by s

        ~String();

        // Operators for String data type
        char & operator[](int index);
        String & operator=(const String &s);
        friend String operator+(const String &s1, const String &s2);
        friend std::ostream& operator<<(std::ostream &os, String &s);

        // Comparision Operators
        friend bool operator==(const String &s1, const String &s2);
        friend bool operator!=(const String &s1, const String &s2);
        friend bool operator<=(const String &s1, const String &s2);
        friend bool operator>=(const String &s1, const String &s2);
        friend bool operator<(const String &s1, const String &s2);
        friend bool operator>(const String &s1, const String &s2);

        // Some methods for making String class easy to use
        size_t len();

private:
        size_t _length;
        size_t _maxlen;
        char *p_c;
        std::ostream & print(std::ostream &os);
};

#endif