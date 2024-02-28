# pragma once

# include <sys/poll.h>
# include "../../Webserv.hpp"
# include <iostream>
# include <sstream>
#include <dirent.h>
# include <vector>
# include <ctime>

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

std::string getCurrentTimeInGMT();
std::string getFileContent(std::string fileName);
int         getConfigIndexByPort(int port, const std::vector<t_server_config>& configs);
std::string GetExtensionPrefix(std::string extension);
std::string list_dir(std::string dir_name);
bool        alreadyExist(const std::vector<pollfd>& vector, int element);
std::string getCgiExtension(std::string filename);

template<typename T>
std::string ft_to_string(const T& value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
};