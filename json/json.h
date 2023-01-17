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