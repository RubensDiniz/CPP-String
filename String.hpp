#ifndef TRABALHOSO_2020_02_10_STRING_HPP
#define TRABALHOSO_2020_02_10_STRING_HPP
#include <string>
#include <string.h>
using namespace std;

class String {

private:
    const char* str;
public:
    // Constructors (a1, a2, a3)
    String () {
        this->str = (char*)"";
    }

    String (char c) {
        this->str = new char[2] {c, '\0'};
    }

    String (const char* c){
        memcpy(&this->str, &(c += *"\0"), sizeof(c));
    }

    // Destructors
    ~String () {
        delete(str);
    }

    // Functions (e, f, g, h, i)
    int length() const{
        int i = 0;
        for (i = 0; this->str[i] != '\0'; i++);
        return i;
    }

    int index(char c){
        for (int i = 0; i < this->length(); i++){
            if (this->str[i] == c){
                return i;
            }
        }
        return -1;
    }

    bool is_upper_case(char c){
        return c >= 65 && c <= 90;
    }

    String* upcase(int a, int b){
        if (a >= 0 && b <= this->length()){
            char* array = new char[this->length() + 1];

            for (int i = 0; i < this->length(); ++i) {
                if (!is_upper_case(this->str[i]) && i >= a && i <= b){
                    array[i] = (char)(this->str[i] - 32);
                } else {
                    array[i] = this->str[i];
                }
            }

            array[this->length()] = '\0';

            return new String(array);
        } else {
            return new String(this->str);
        }
    }

    String* lowercase(int a, int b){
        if (a >= 0 && b <= this->length()){
            char* array = new char[this->length() + 1];

            for (int i = 0; i < this->length(); ++i) {
                if (is_upper_case(this->str[i]) && i >= a && i <= b){
                    array[i] = (char)(this->str[i] + 32);
                } else {
                    array[i] = this->str[i];
                }
            }

            array[this->length()] = '\0';

            return new String(array + *"\0");
        } else {
            return new String(this->str);
        }
    }

    String* toggle_case(int a, int b){
        if (a >= 0 && b <= this->length()){
            char* array = new char[this->length() + 1];

            for (int i = 0; i < this->length(); ++i) {
                if (is_upper_case(this->str[i]) && i >= a && i <= b){
                    array[i] = (char)(this->str[i] + 32);
                } else if (!is_upper_case(this->str[i]) && i >= a && i <= b) {
                    array[i] = (char)(this->str[i] - 32);
                } else {
                    array[i] = this->str[i];
                }
            }

            array[this->length()] = '\0';

            return new String(array + *"\0");
        } else {
            return new String(this->str);
        }
    }

    // Friends and operators (b, c, d, j...) TODO
    friend ostream& operator<<(ostream &os, const String& s);
    friend istream& operator>>(istream &is, String& s);
    char operator[](const int i) const {return str[i];}

    String* operator+(const String &s) {
        const int l1 = this->length();
        const int l2 = s.length();
        int total = l1 + l2 + 1;

        char* array = new char[total];

        for (int i = 0; i < total; i++){
            if (i < l1){
                array[i] = this->str[i];
            } else {
                array[i] = s[i - l1];
            }
        }

        array[total] = '\0';

        delete(this);

        const char* newString = array;
        return new String(newString);
    }

    String* operator+(const char* &s) {
        const int l1 = this->length();
        String aux = s;
        const int l2 = aux.length();
        int total = l1 + l2 + 1;

        char* array = new char[total];

        for (int i = 0; i < total; i++){
            if (i < l1){
                array[i] = this->str[i];
            } else {
                array[i] = aux[i - l1];
            }
        }

        array[total] = '\0';

        delete(this);

        const char* newString = array;
        return new String(newString);
    }

    String* operator+(char* &s) {
        const int l1 = this->length();
        int total = l1 + 2;

        char* array = new char[total];

        for (int i = 0; i < total - 1; i++){
            array[i] = this->str[i];
        }

        array[total - 1] = *s;
        array[total] = '\0';

        delete(this);

        const char* newString = array;
        return new String(newString);
    }

    String* operator+=(const String &s) {
        const int l1 = this->length();
        const int l2 = s.length();
        int total = l1 + l2 + 1;

        char *array = new char[total];
        char* cast = const_cast<char *>(this->str);

        for (int i = 0; i < total; i++) {
            if (i < l1) {
                array[i] = cast[i];
            } else {
                array[i] = s[i - l1];
            }
        }

        array[total] = '\0';

        delete(this);

        (*this) = (*new String(array));
        return this;
    }

    String* operator+=(const char* &s) {
        const int l1 = this->length();
        String aux = s;
        const int l2 = aux.length();
        int total = l1 + l2 + 1;

        char *array = new char[total];
        char* cast = const_cast<char *>(this->str);

        for (int i = 0; i < total; i++) {
            if (i < l1) {
                array[i] = cast[i];
            } else {
                array[i] = aux[i - l1];
            }
        }

        array[total] = '\0';

        delete(this);

        (*this) = (*new String(array));
        return this;
    }

    String* operator+=(char* &s) {
        const int l1 = this->length();
        int total = l1 + 2;

        char *array = new char[total];
        char* cast = const_cast<char *>(this->str);

        for (int i = 0; i < total - 1; i++) {
            array[i] = cast[i];
        }

        array[total - 1] = *s;
        array[total] = '\0';

        delete(this);

        (*this) = (*new String(array));
        return this;
    }

    String& operator=(const String* s){
        delete(this);
        memcpy(&this->str, &s->str, sizeof(this->str));
        return *this;
    }

    String& operator=(const char* s){
        delete(this);
        memcpy(&this->str, &s, sizeof(this->str));
        return *this;
    }

    String& operator=(char* s){
        delete(this);
        memcpy(&this->str, &s, sizeof(s));
        return *this;
    }

    // TODO down below
    bool operator==(const String &s) {
        return memcmp(this->str, s.str, sizeof(this->length())) == 0 && this->length() == s.length();
    }

    bool operator==(const char* &s) {
        String* aux = new String(s);
        bool result = memcmp(this->str, aux->str, sizeof(this->length())) == 0 && this->length() == aux->length();
        delete(aux);
        return result;
    }

    bool operator==(char* &s) {
        String* aux = new String(s);
        bool result = memcmp(this->str, aux->str, sizeof(this->length())) == 0 && this->length() == aux->length();
        delete(aux);
        return result;
    }

    bool operator!=(const String &s) {
        return !(memcmp(this->str, s.str, sizeof(this->length())) == 0 && this->length() == s.length());
//        if (this->length() != s.length()){
//            return true;
//        } else {
//            for (int i = 0; i < this->length(); i++){
//                if (this->str[i] != s[i]){
//                    return true;
//                }
//            }
//        }
//        return false;
    }

    bool operator!=(const char* &s) {
        String* aux = new String(s);
        bool result = !(memcmp(this->str, aux->str, sizeof(this->length())) == 0 && this->length() == aux->length());
        delete(aux);
        return result;
    }

    bool operator!=(char* &s) {
        String* aux = new String(s);
        bool result = !(memcmp(this->str, aux->str, sizeof(this->length())) == 0 && this->length() == aux->length());
        delete(aux);
        return result;
    }

    bool operator>(const String &s) {
        int l1 = this->length();
        int l2 = s.length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++) {
            if (this->str[i] > s.str[i]) {
                return true;
            } else if (this->str[i] < s.str[i]) {
                return false;
            } else {
                continue;
            }
        }

        if (l1 == l2){
            return false;
        } else {
            return smallest != l1;
        }
    }

    bool operator>(const char* &s) {
        int l1 = this->length();
        String* aux = new String(s);
        int l2 = aux->length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++) {
            if (this->str[i] > aux->str[i]) {
                return true;
            } else if (this->str[i] < aux->str[i]) {
                return false;
            } else {
                continue;
            }
        }

        if (l1 == l2){
            return false;
        } else {
            return smallest != l1;
        }
    }

    bool operator>(char* &s) {
        int l1 = this->length();
        String* aux = new String(s);
        int l2 = aux->length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++) {
            if (this->str[i] > aux->str[i]) {
                return true;
            } else if (this->str[i] < aux->str[i]) {
                return false;
            } else {
                continue;
            }
        }

        delete(aux);

        if (l1 == l2){
            return false;
        } else {
            return smallest != l1;
        }
    }

    bool operator>=(const String &s) {
        int l1 = this->length();
        int l2 = s.length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++) {
            if (this->str[i] > s.str[i]) {
                return true;
            } else if (this->str[i] < s.str[i]) {
                return false;
            } else {
                continue;
            }
        }

        if (l1 == l2){
            return true;
        } else {
            return smallest != l1;
        }
        //return (smallest == l1) || (memcmp(this->str, s.str, sizeof(this->length())) == 0 && this->length() == s.length());
    }

    bool operator>=(const char* &s) {
        int l1 = this->length();
        String* aux = new String(s);
        int l2 = aux->length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++) {
            if (this->str[i] > aux->str[i]) {
                return true;
            } else if (this->str[i] < aux->str[i]) {
                return false;
            } else {
                continue;
            }
        }

        delete(aux);

        if (l1 == l2){
            return true;
        } else {
            return smallest != l1;
        }
    }

    bool operator>=(char* &s) {
        int l1 = this->length();
        String* aux = new String(s);
        int l2 = aux->length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++) {
            if (this->str[i] > aux->str[i]) {
                return true;
            } else if (this->str[i] < aux->str[i]) {
                return false;
            } else {
                continue;
            }
        }

        delete(aux);

        if (l1 == l2){
            return true;
        } else {
            return smallest != l1;
        }
    }

    bool operator<(const String &s) {
        int l1 = this->length();
        int l2 = s.length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++){
            if (this->str[i] > s.str[i]){
                return false;
            } else if (this->str[i] < s.str[i]){
                return true;
            } else {
                continue;
            }
        }

        if (l1 == l2){
            return false;
        } else {
            return smallest == l1;
        }
    }

    bool operator<(const char* &s) {
        int l1 = this->length();
        String* aux = new String(s);
        int l2 = aux->length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++){
            if (this->str[i] > aux->str[i]){
                return false;
            } else if (this->str[i] < aux->str[i]){
                return true;
            } else {
                continue;
            }
        }

        delete(aux);

        if (l1 == l2){
            return false;
        } else {
            return smallest == l1;
        }
    }

    bool operator<(char* &s) {
        int l1 = this->length();
        String* aux = new String(s);
        int l2 = aux->length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++){
            if (this->str[i] > aux->str[i]){
                return false;
            } else if (this->str[i] < aux->str[i]){
                return true;
            } else {
                continue;
            }
        }

        delete(aux);

        if (l1 == l2){
            return false;
        } else {
            return smallest == l1;
        }
    }

    bool operator<=(const String &s) {
        int l1 = this->length();
        int l2 = s.length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++){
            if (this->str[i] > s.str[i]){
                return false;
            } else if (this->str[i] < s.str[i]){
                return true;
            } else {
                continue;
            }
        }

        if (l1 == l2){
            return true;
        } else {
            return smallest == l1;
        }
        //return (smallest != l1) || (memcmp(this->str, s.str, sizeof(this->length())) == 0 && this->length() == s.length());
    }

    bool operator<=(const char* &s) {
        int l1 = this->length();
        String* aux = new String(s);
        int l2 = aux->length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++){
            if (this->str[i] > aux->str[i]){
                return false;
            } else if (this->str[i] < aux->str[i]){
                return true;
            } else {
                continue;
            }
        }

        delete(aux);

        if (l1 == l2){
            return true;
        } else {
            return smallest == l1;
        }
    }

    bool operator<=(char* &s) {
        int l1 = this->length();
        String* aux = new String(s);
        int l2 = aux->length();

        int smallest = l1;
        if (l1 >= l2) { smallest = l2; }

        for (int i = 0; i < smallest; i++){
            if (this->str[i] > aux->str[i]){
                return false;
            } else if (this->str[i] < aux->str[i]){
                return true;
            } else {
                continue;
            }
        }

        delete(aux);

        if (l1 == l2){
            return true;
        } else {
            return smallest == l1;
        }
    }


};


ostream& operator<<(ostream &os, const String& s){
    os << s.str;
    return os;
}

istream& operator>>(istream &is, String &s){
    char* aux = new char[256];
    is >> aux;
    s = aux;
    return is;
}


#endif
