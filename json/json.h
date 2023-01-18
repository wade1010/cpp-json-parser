#pragma
#include <string>
#include <vector>
#include <map>
using namespace std;
namespace crab
{
    namespace json
    {
        // 类似protobuf的解析器设计思路
        class Json
        {
        public:
            enum class Type
            {
                json_null = 0,
                json_bool,
                json_int,
                json_double,
                json_string,
                json_array,
                json_object
            };

            Json();
            Json(bool);
            Json(int);
            Json(double);
            Json(const char *);
            Json(const string &);
            Json(Type);
            Json(const Json &);

            // 转换函数
            operator bool();
            operator int();
            operator double();
            operator string();

            // 数组
            //  重载[]
            Json &operator[](int);
            void append(const Json &);
            string str() const;

            // 重载[]
            Json &operator[](const char *);
            Json &operator[](const string &);
            void operator=(const Json &);
            bool operator==(const Json &);
            bool operator!=(const Json &);

            void clear();

            void copy(const Json &);

            typedef std::vector<Json>::iterator iterator;
            iterator begin()
            {
                return m_value.m_array->begin();
            }

            iterator end()
            {
                return m_value.m_array->end();
            }

            bool isNull() { return m_type == Type::json_null; }
            bool isBool() { return m_type == Type::json_bool; }
            bool isInt() { return m_type == Type::json_int; }
            bool isDouble() { return m_type == Type::json_double; }
            bool isString() { return m_type == Type::json_string; }
            bool isArray() { return m_type == Type::json_array; }
            bool isObject() { return m_type == Type::json_object; }

            bool asBool() const;
            int asInt() const;
            double asDouble() const;
            string asString() const;

            // 判断数组是否有这个索引
            bool has(int);
            // 判断对象是否有这个key
            bool has(const char *);
            // 判断对象是否有这个key
            bool has(const string &);

            void remove(int);
            void remove(const char *);
            void remove(const string &);

        private:
            union Value
            {
                bool m_bool;
                int m_int;
                double m_double;
                std::string *m_string;
                std::vector<Json> *m_array;
                std::map<string, Json> *m_object;
            };
            Type m_type;
            Value m_value;
        };
    } // namespace json
}