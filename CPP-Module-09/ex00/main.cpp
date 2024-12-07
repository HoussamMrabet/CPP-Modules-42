/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:34:24 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 02:36:19 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdlib>

std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::map<std::string, float> loadDatabase(const std::string &filename)
{
    std::map<std::string, float> db;
    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, price;

        if (std::getline(ss, date, ',') && std::getline(ss, price)) {
            date = trim(date);
            price = trim(price);
            db[date] = std::atof(price.c_str());
        }
    }

    file.close();
    return db;
}

void processInput(const std::string &filename, const std::map<std::string, float> &db)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
	{
        line = trim(line);
        
        if (line.empty() || line == "date | value") {
            continue;
        }

        std::istringstream ss(line);
        std::string date, valueStr;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date = trim(date);
            valueStr = trim(valueStr);

            double value = std::atof(valueStr.c_str());
            if (valueStr.find_first_not_of("0123456789.") != std::string::npos || value < 0 || value > 1000) {
                if (value < 0) {
                    std::cerr << "Error: not a positive number." << std::endl;
                } else if (value > 1000) {
                    std::cerr << "Error: too large a number." << std::endl;
                } else {
                    std::cerr << "Error: bad input => " << line << std::endl;
                }
                continue;
            }

            std::map<std::string, float>::const_iterator it = db.lower_bound(date);
            if (it == db.end() || it->first != date) {
                if (it != db.begin()) {
                    --it;
                } else {
                    std::cerr << "Error: no valid date found in database." << std::endl;
                    continue;
                }
            }

            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    file.close();
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    try
	{
        std::map<std::string, float> db = loadDatabase("data.csv");

        processInput(argv[1], db);
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
