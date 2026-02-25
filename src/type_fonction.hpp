#ifndef TYPE_HELPERS_HPP
#define TYPE_HELPERS_HPP

#include "ast.hpp"  


inline std::string type_to_string(algo_types::type_kind tk) {
    switch(tk) {
        case algo_types::BOOLEAN:   return "bool";
        case algo_types::INTEGER:   return "int";
        case algo_types::CHARACTER: return "char";
        case algo_types::STRING:    return "std::string";
        case algo_types::ARRAY:     return "std::vector";
        case algo_types::ERROR:     return "error";
        default:                    return "unknown";
    }
}


//Afin de retrouver le types des elements d'un tableau 
inline algo_types get_array_element_type(const algo_types &type) {
    if (type.kind == algo_types::ARRAY && !type.parameters.empty()){
        return type.parameters[0];
    }
    return algo_types::ERROR;
}

#endif // TYPE_HELPERS_HPP

