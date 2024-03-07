/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:21:02 by aouchaad          #+#    #+#             */
/*   Updated: 2024/03/06 19:04:07 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sys/stat.h>

typedef struct location {
	std::string 				uri;
	std::string 				root;
	std::string					redirection;
	std::string					upload_path;
	std::string					cgi_path;
	std::vector<std::string>	cgi_extentions;
	std::string					index;
	bool 						autoIndex;
	std::vector<std::string> 	acceptedMethods;
	std::string 				alias;
	
} location;

typedef struct s_config
{
	std::string 					serverName;
	unsigned int 					host;
	int								port;
	size_t 							maxBodySize;
	std::map<std::string, location> locations;
	std::map<int, std::string> 		Errors;
} t_server_config;


class SyntaxErrorException : public std::exception {
	public:
		const char * what() const throw() {
			return "Syntax Error";
	}
};
class InvalidPathException : public std::exception {
	public:
		const char * what() const throw() {
			return "Invalid Path";
	}
};
class UndefinedTokenException : public std::exception {
	public:
		const char * what() const throw() {
			return "Undefined Token";
	}
};
class UndefinedValueException : public std::exception {
	public:
		const char * what() const throw() {
			return "Undefined Value";
	}
};
class CantOpenConfFileException : public std::exception {
	public:
		const char * what() const throw() {
			return "cant open confige file";
	}
};
class DuplicatedPortException : public std::exception {
	public:
		const char * what() const throw() {
			return "the same port used in different servers";
	}
};
class DuplicatedLocationException : public std::exception {
	public:
		const char * what() const throw() {
			return "Duplicated location";
	}
};


std::vector<t_server_config> readConfigeFile(char *path);
void setToDefault(std::vector<t_server_config> &configs);
void printConfigs(std::vector<t_server_config> &configs);
void checkForDuplicatedPorts(std::vector<t_server_config> &configs);