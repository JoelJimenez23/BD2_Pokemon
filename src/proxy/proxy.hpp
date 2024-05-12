#ifndef PROXY_HPP
#define PROXY_HPP

#include "apple_store_record.hpp"
#include "../structures/avl/avl.hpp"
#include "../structures/avl/node.hpp"
#include "../structures/avl/utils.hpp"

const std::string APP_STORE_FILE = "AppleStore.dat";


#define SELECT_BY_ATTRIBUTE(attribute, attribute_name, type) \
    if (query.selected_attribute == attribute_name) { \
        std::function<type(AppRecord &)> index = [=](AppRecord& record) { return record.attribute; }; \
        AVLFile<type, AppRecord> avl(APP_STORE_FILE ,attribute_name, index); \
        if(!avl){\
            std::cout << "index created" << std::endl;\
            avl.create_index();\
        }\
        query_records = avl.search(query.where_value);\
    }\

struct Query{
    std::string query_type="SELECT";
    std::string selected_attribute="id";
    std::string token1="FROM";
    std::string table_name="apple_store";
    std::string operation_type="WHERE";
    std::string where_attribute="id";
    std::string token2="=";
    unsigned int where_value=284882215;
};

class Proxy {
private:
    std::vector<AppRecord> query_records;
    std::vector<std::string> parser{"SELECT appName FROM apple_store WHERE prime_genre = 'Catalogs';"};
    Query query; // query = parser?

    
public:
    Proxy() = default;
    ~Proxy() = default;

    void execute_query() {
        if (query.query_type == "SELECT") {
            SELECT_BY_ATTRIBUTE(id, "id", unsigned int);
        }
        for (auto &record : query_records) {
            std::cout << record.to_string() << std::endl;
        }
    }
};

#endif //PROXY_HPP
