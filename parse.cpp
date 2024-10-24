#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

#include <salamapper/parse.hpp>

std::unordered_map<std::string, std::vector<std::string>> Parse(const std::string& format) {
    std::unordered_map<std::string, std::vector<std::string>> g;
    std::istringstream ss(format);
    std::string token;
	if (format.empty() || format.find(":") == std::string::npos){
		throw std::invalid_argument("Invalid format string");
	}
    while (std::getline(ss, token, ';')) {
        std::istringstream ss_token(token);
        std::string id_str;
        if (!std::getline(ss_token, id_str, ':')){
			throw std::invalid_argument("Invalid format: missing colon");
		}
		if (id_str.empty()){
			throw std::invalid_argument("Invalid format: empty ID");
		}
        std::string children_str;
        std::getline(ss_token, children_str);
        std::istringstream ss_children(children_str);
        std::string child;
        while (std::getline(ss_children, child, ',')) {
            g[id_str].push_back(child);
        }
    }
    return g;
}