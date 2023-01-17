#include "json.h"
#include <string>
using namespace crab::json;

Json::Json() : m_type(Type::json_null)
{
}
Json::Json(bool value) : m_type(Type::json_bool)
{
    m_value.m_bool = value;
}
Json::Json(int value) : m_type(Type::json_int)
{
    m_value.m_int = value;
}
Json::Json(double value) : m_type(Type::json_double)
{
    m_value.m_double = value;
}
Json::Json(const char *value) : m_type(Type::json_string)
{
    m_value.m_string = new string(value);
}
Json::Json(const string &value) : m_type(Type::json_string)
{
    m_value.m_string = new string(value);
}
Json::Json(Type type) : m_type(type)
{
    switch (type)
    {
    case Type::json_null:
        break;
    case Type::json_bool:
        m_value.m_bool = false;
        break;
    case Type::json_int:
        m_value.m_int = 0;
        break;
    case Type::json_double:
        m_value.m_double = 0.0;
        break;
    case Type::json_string:
        m_value.m_string = new string("");
        break;
    case Type::json_array:
        m_value.m_array = new vector<Json>();
        break;
    case Type::json_object:
        m_value.m_object = new map<string, Json>();
        break;

    default:
        break;
    }
}
Json::Json(const Json &other) : m_type(other.m_type)
{
    switch (other.m_type)
    {
    case Type::json_null:
        break;
    case Type::json_bool:
        m_value.m_bool = other.m_value.m_bool;
        break;
    case Type::json_int:
        m_value.m_int = other.m_value.m_int;
        break;
    case Type::json_double:
        m_value.m_double = other.m_value.m_double;
        break;
    case Type::json_string:
        m_value.m_string = other.m_value.m_string;
        break;
    case Type::json_array:
        m_value.m_array = other.m_value.m_array;
        break;
    case Type::json_object:
        m_value.m_object = other.m_value.m_object;
        break;

    default:
        break;
    }
}

// 转换函数
Json::operator bool()
{
    if (m_type != Type::json_bool)
        throw new logic_error("type error，type is not json_bool");

    return m_value.m_bool;
}
Json::operator int()
{
    if (m_type != Type::json_int)
        throw new logic_error("type error,type is not json_int");
    return m_value.m_int;
}
Json::operator double()
{
    if (m_type != Type::json_double)
        throw new logic_error("type error,type is not json_double");
    return m_value.m_double;
}
Json::operator string()
{
    if (m_type != Type::json_string)
        throw new logic_error("type error,type is not json_string");
    return *m_value.m_string;
}