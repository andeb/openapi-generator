/**
 * OpenAPI Petstore
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 7.9.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */


#ifndef OPENAPI_MODELS_HELPER_H_
#define OPENAPI_MODELS_HELPER_H_



#include <string>
#include <map>
#include <vector>
#include <set>

namespace org {
namespace openapitools {
namespace server {
namespace model {

template<class T>
boost::property_tree::ptree toPt(const T& val) {
    boost::property_tree::ptree pt;
    pt.put_value(val);
    return pt;
}

template <class T>
boost::property_tree::ptree toPt(const std::vector<T> & vec) {
    boost::property_tree::ptree pt;
    for (auto &childEntry : vec) {
        boost::property_tree::ptree childNode = toPt(childEntry);
        pt.push_back(std::make_pair("", childNode));
    }
    return pt;
}

template <class T>
boost::property_tree::ptree toPt(const std::map<std::string, T> & map) {
    boost::property_tree::ptree pt;
    for (auto &childEntry : map) {
        boost::property_tree::ptree childNode = toPt(childEntry.second);
        pt.push_back(boost::property_tree::ptree::value_type(childEntry.first, childNode));
    }
    return pt;
}

template <class T>
boost::property_tree::ptree toPt(const std::set<T> & set) {
    boost::property_tree::ptree pt;
    for (auto &childEntry : set) {
        boost::property_tree::ptree childNode = toPt(childEntry);
        pt.push_back(std::make_pair("", childNode));
    }
    return pt;
}


template<typename T>
struct is_vector
{
    static constexpr bool value = false;
};

template<typename... C>
struct is_vector<std::vector<C...>>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_map
{
    static constexpr bool value = false;
};

template<typename... C>
struct is_map<std::map<C...>>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_set
{
    static constexpr bool value = false;
};

template<typename... C>
struct is_set<std::set<C...>>
{
    static constexpr bool value = true;
};


template<class T>
std::enable_if_t<!is_vector<T>::value && !is_map<T>::value && !is_set<T>::value, T>
fromPt(const boost::property_tree::ptree& pt) {
    return pt.get_value<T>();
}

template<class T>
std::enable_if_t<is_vector<T>::value,T>
fromPt(const boost::property_tree::ptree& pt) {
    T vec;
    for (const auto &child: pt) {
        typename T::value_type childElement = fromPt<typename T::value_type>(child.second);
        vec.emplace_back(childElement);
    }
    return vec;
}

template <class T>
std::enable_if_t<is_map<T>::value,T>
fromPt(const boost::property_tree::ptree &pt) {
    T map;
    for (const auto &child: pt) {
        using ChildType = typename T::mapped_type;
        ChildType childElement = fromPt<ChildType>(child.second);
        map.insert(std::make_pair(child.first, childElement));
    }
    return map;
}

template<class T>
std::enable_if_t<is_set<T>::value,T>
fromPt(const boost::property_tree::ptree& pt) {
    T set;
    for (const auto &child: pt) {
        typename T::value_type childElement = fromPt<typename T::value_type>(child.second);
        set.insert(childElement);
    }
    return set;
}

}
}
}
}

#endif /* OPENAPI_MODELS_HELPER_H_ */