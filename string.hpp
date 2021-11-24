#ifndef STRING_H
#define STRING_H

#include "object.hpp"

namespace ecci {

    class string : public ecci::object
    {
        public:
            enum {MAX_LENGTH = (size_t)-1};
            string(const char*);
            string(const string&);
            virtual ~string();
            void print(ostream &where) const override;
            bool comparemin(const ecci::object&) const override;
            bool comparemay(const ecci::object&) const override;
            const string& operator=(const string&);
            const string& operator+=(const string&);
            char& operator[](size_t);
            char operator[](size_t) const;
            char* c_str() const { return m_buffer; }
            size_t length() const { return m_length; }
        protected:
        private:
            char* m_buffer;
            size_t m_buffer_length;
            size_t m_length;
    };

}

std::ostream& operator<<(std::ostream&, const ecci::string&);
std::istream& operator>>(std::istream&, ecci::string&);
std::istream& getline(std::istream&, ecci::string&);
bool operator==(const ecci::string&, const ecci::string&);
bool operator!=(const ecci::string&, const ecci::string&);
bool operator<(const ecci::string&, const ecci::string&);
bool operator<=(const ecci::string&, const ecci::string&);
bool operator>(const ecci::string&, const ecci::string&);
bool operator>=(const ecci::string&, const ecci::string&);


#endif // STRING_H
