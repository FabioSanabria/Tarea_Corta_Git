#ifndef FLOAT_H
#define FLOAT_H

#include "object.hpp"
#include <iostream>

using namespace std;

namespace ecci {
    class flo : public ecci::object{
        public:
        flo(const float);
        virtual ~flo();
        void print(ostream &where) const override;
        bool comparemin(const ecci::object&) const override;
        bool comparemay(const ecci::object&) const override;
        float get_flo() const;
        flo operator+(const flo&);
        flo operator-(const flo&);
        flo operator*(const flo&);
        flo operator/(const flo&);

        private:
        float m_float;

    };
}

ostream& operator<<(ostream&, const ecci::flo&);
istream& operator>>(istream&, const ecci::flo&);
bool operator<(const ecci::flo&, const ecci::flo&);
bool operator>(const ecci::flo&, const ecci::flo&);
bool operator==(const ecci::flo&, const ecci::flo&);
bool operator!=(const ecci::flo&, const ecci::flo&);
bool operator<=(const ecci::flo&, const ecci::flo&);
bool operator>=(const ecci::flo&, const ecci::flo&);



#endif // FLOAT_H