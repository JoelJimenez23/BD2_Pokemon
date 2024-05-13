#ifndef PROXY_HPP
#define PROXY_HPP

#include "apple_store_record.hpp"
#include "../structures/avl/avl.hpp"
#include "../structures/avl/node.hpp"
#include "../structures/avl/utils.hpp"
#include <charconv>

const std::string APP_STORE_FILE = "data/AppleStore.dat";

#define SELECT_ATTRIBUTE(attribute, type) \
    if (query.where_attribute == #attribute) { \
        std::function<type(AppRecord &)> index = [=](AppRecord& record) { return record.attribute; }; \
        AVLFile<type, AppRecord> avl(APP_STORE_FILE ,#attribute, index); \
        if(!avl){std::cout << "index created" << std::endl;avl.create_index();}\
        type search_value{}; \
        std::string str = query.where_value; \
        auto result = std::from_chars(str.data(), str.data() + str.size(), search_value); \
        query_records = std::move(avl.search(search_value));\
    }\

#define SELECT_ATTRIBUTE_CHAR(attribute, char_size) \
    if (query.where_attribute == #attribute) { \
        std::function<bool (char[char_size],char[char_size])> cmp = [=](char a[char_size], char b[char_size]) -> bool {return strcmp(a,b)>0;}; \
        std::function<char *(AppRecord &)> index = [=](AppRecord& record) { return record.attribute; }; \
        AVLFile<char[char_size], AppRecord, decltype(index), decltype(cmp)> avl(APP_STORE_FILE , #attribute, index, cmp); \
        if(!avl){std::cout << "char index created" << std::endl;avl.create_index();}\
        char value[char_size]; \
        strcpy(value, query.where_value.c_str()); \
        query_records = std::move(avl.search(value));\
    }\

#define SELECT_RANGE(attribute, type) \
    if (query.where_attribute == #attribute) { \
        std::function<type(AppRecord &)> index = [=](AppRecord& record) { return record.attribute; }; \
        AVLFile<type, AppRecord> avl(APP_STORE_FILE ,#attribute, index); \
        if(!avl){std::cout << "index created, range" << std::endl; avl.create_index();} \
        type init{}, ending{}; \
        std::string str_i = query.init; std::string str_e = query.ending; \
        auto resutl1 = std::from_chars(str_i.data(), str_i.data() + str_i.size(), init); \
        auto resutl2 = std::from_chars(str_e.data(), str_e.data() + str_e.size(), ending); \
        query_records = std::move(avl.range_search(init, ending)); \
    } \

#define SELECT_RANGE_CHAR(attribute, char_size) \
    if (query.where_attribute == #attribute) { \
        std::function<bool (char[char_size],char[char_size])> cmp = [=](char a[char_size], char b[char_size]) -> bool {return strcmp(a,b)>0;}; \
        std::function<char *(AppRecord &)> index = [=](AppRecord& record) { return record.attribute; }; \
        AVLFile<char[char_size], AppRecord, decltype(index), decltype(cmp)> avl(APP_STORE_FILE ,#attribute, index, cmp); \
        if(!avl){std::cout << "char index created, range" << std::endl;avl.create_index();}\
        char init[char_size], ending[char_size]; \
        strcpy(init, query.init.c_str()); strcpy(ending, query.ending.c_str()); \
        query_records = std::move(avl.range_search(init, ending)); \
    } \



struct Query{
    std::string query_type="SELECT";
    std::string token1="FROM";
    std::string table_name="apple_store";
    std::string operation_type="WHERE";
    // std::string where_attribute="id"; // opción 2
    std::string where_attribute="prime_genre"; // opción 1
    std::string token2="="; // con =
    // std::string where_value="284882215";  // opción 2
    std::string where_value="Catalogs"; // opción 1

    // PARA RANGE SEARCH
    // std::string init="284882215"; // opción 1
    //std::string where_attribute = "app_name";
    std::string init="Fac";
    //std::string token2 = "BETWEEN"; // con BETWEEN
    // std::string ending="284993459"; // opción 1
    std::string ending="Fad";
};

class Proxy {
private:
    std::vector<AppRecord> query_records;
    std::vector<std::string> parser{"SELECT * FROM apple_store WHERE prime_genre = 'Catalogs';"};
    Query query; // query = parser?

    
public:
    Proxy() = default;
    ~Proxy() = default;

    void execute_query() {
        if (query.query_type == "SELECT") {
            if (query.token2 == "="){
                SELECT_ATTRIBUTE(id, unsigned int);
                SELECT_ATTRIBUTE(size_bytes, unsigned int);
                SELECT_ATTRIBUTE(price, float);
                SELECT_ATTRIBUTE(rating_count_tot, unsigned int);
                SELECT_ATTRIBUTE_CHAR(app_name, 256);
                SELECT_ATTRIBUTE_CHAR(cont_rating, 4);
                SELECT_ATTRIBUTE_CHAR(prime_genre, 18);
            }else if (query.token2 == "BETWEEN"){ 
                SELECT_RANGE(id, unsigned int);
                SELECT_RANGE(size_bytes, unsigned int);
                SELECT_RANGE(price, float);
                SELECT_RANGE(rating_count_tot, unsigned int);
                SELECT_RANGE_CHAR(app_name, 256);
                SELECT_RANGE_CHAR(cont_rating, 4);
                SELECT_RANGE_CHAR(prime_genre, 18);
            }
        } 
        for (auto &record : query_records) {
            std::cout << record.to_string() << std::endl;
        }
    }
};

#endif //PROXY_HPP
