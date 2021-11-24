#ifndef INTEGER_H
#define INTEGER_H

#include "object.hpp"
#include <iostream>

using namespace std;

namespace ecci {
    
    class integer : public ecci::object{

        public:
        integer();
        integer(const int);
        virtual ~integer();
        int get_dato() const;
        void set_int(int x){m_integer = x;};
        void print(ostream &where) const override;
        bool comparemin(const ecci::object&) const override;
        bool comparemay(const ecci::object&) const override;
        integer operator+(const integer&);
        integer operator-(const integer&);
        integer operator*(const integer&);
        integer operator/(const integer&);

        private:
        int m_integer;

    };

}
ostream& operator<<(ostream&, const ecci::integer&);
istream& operator>>(istream&, ecci::integer&);
bool operator<(const ecci::integer&, const ecci::integer&);
bool operator>(const ecci::integer&, const ecci::integer&);
bool operator==(const ecci::integer&, const ecci::integer&);
bool operator!=(const ecci::integer&, const ecci::integer&);
bool operator<=(const ecci::integer&, const ecci::integer&);
bool operator>=(const ecci::integer&, const ecci::integer&);

#endif // INTEGER_H