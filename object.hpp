#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>

using namespace std;
namespace ecci
{

    class object
    {
    public:
        virtual void print(ostream &where) const;
        virtual bool comparemin(const ecci::object&) const;
        virtual bool comparemay(const ecci::object&) const;
        object();
        virtual ~object();

    protected:
    private:
    };

    
}
ostream &operator<<(ostream &out, const ecci::object &o);
bool operator<(const ecci::object&, const ecci::object&);
bool operator>(const ecci::object&, const ecci::object&);
#endif // OBJECT_H
