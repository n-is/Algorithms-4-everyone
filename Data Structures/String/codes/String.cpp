#include "String.h"

using namespace std;

const unsigned int chunk_size = 8;

String::String()
{
        _length = 0;
        _maxlen = chunk_size;
        p_c = new char[_maxlen];
        p_c[0] = '\0';
}

String::String(size_t len)
{
        _length = len;
        _maxlen = chunk_size * (_length / chunk_size + 1);
        p_c = new char[_maxlen];
        unsigned int i;
        for(i = 0; i < _length; ++i) p_c[i] = ' ';
        p_c[i] = '\0';
}

String::String(const char * str)
{
        _length = strlen(str);
        _maxlen = chunk_size * (_length / chunk_size + 1);
        p_c = new char[_maxlen];
        strcpy(p_c, str);
}

String::String(const String & s)
{
        _length = s._length;
        _maxlen = s._maxlen;
        p_c = new char[_maxlen];
        strcpy(p_c, s.p_c);
}

String::~String()
{
        delete p_c;
}

size_t String::len()
{
        return _length;
}

char & String::operator[](int index)
{
        if(index > (int)(_maxlen - 1)) index = (int)(_maxlen - 1);
        while(index < 0) index += _length;
        return p_c[index];
}

bool operator==(const String &s1, const String &s2)
{
        return (strcmp(s1.p_c, s2.p_c) == 0);
}

bool operator!=(const String &s1, const String &s2)
{
        return (strcmp(s1.p_c, s2.p_c) != 0);
}

bool operator<=(const String &s1, const String &s2)
{
        return (strcmp(s1.p_c, s2.p_c) <= 0);
}

bool operator>=(const String &s1, const String &s2)
{
        return (strcmp(s1.p_c, s2.p_c) >= 0);
}

bool operator<(const String &s1, const String &s2)
{
        return (strcmp(s1.p_c, s2.p_c) < 0);
}

bool operator>(const String &s1, const String &s2)
{
        return (strcmp(s1.p_c, s2.p_c) > 0);
}

ostream & String::print(ostream &os)
{
        os << p_c;
        return os;
}

ostream & operator<<(ostream &os, String &s)
{
        return s.print(os);
}

String & String::operator=(const String &s)
{
        _length = s._length;
        _maxlen = s._maxlen;
        p_c = new char[_maxlen];
        strcpy(p_c, s.p_c);
        return *this;
}

String operator+(const String &s1, const String &s2)
{
        String newString;
        newString._length = s1._length + s2._length;
        newString._maxlen = chunk_size * (newString._length / chunk_size + 1);
        newString.p_c = new char[newString._maxlen];
        strcpy(newString.p_c, s1.p_c);
        strcat(newString.p_c, s2.p_c);
        return newString;
}
