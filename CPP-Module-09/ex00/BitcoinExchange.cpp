/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:04:01 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 14:04:30 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, price;

        if (std::getline(ss, date, ',') && std::getline(ss, price))
        {
            date = trim(date);
            price = trim(price);
            db[date] = std::atof(price.c_str());
        }
    }
    file.close();
    
    return (db);
}

int isLeapYear(int year)
{
    if (!(year % 4))
    {
        if (!(year % 100))
        {
            if (!(year % 400))
                return 1;
            else
                return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

bool isValidDate(int year, int month, int day)
{
    if (year < 2009) return false;
    if (month < 1 || month > 12) return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    return (day > 0 && day <= daysInMonth[month - 1]);
}

bool parseDate(const std::string &date)
{
    int dashCount = 0;
    
    for (std::string::const_iterator it = date.begin(); it != date.end(); ++it)
    {
        if (*it == '-')
            ++dashCount;
        else if (!std::isdigit(*it))
            return false;
    }

    if (dashCount != 2) return false;

    std::istringstream iss(date);
    std::string yearStr, monthStr, dayStr;
    if (!std::getline(iss, yearStr, '-') || !std::getline(iss, monthStr, '-') || !std::getline(iss, dayStr))
        return false;

    int year = 0, month = 0, day = 0;
    std::istringstream yearStream(yearStr), monthStream(monthStr), dayStream(dayStr);
    if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
        return false;

    return isValidDate(year, month, day);
}

void processInput(const std::string &filename, const std::map<std::string, float> &db)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    int i = 0;
    while (std::getline(file, line))
	{
        line = trim(line);
        if (!line.empty())
            ++i;

        if (line.empty() || (line == "date | value" && i == 1))
            continue;

        std::istringstream ss(line);
        std::string date, valueStr;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            date = trim(date);
            valueStr = trim(valueStr);

            if (!parseDate(date))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue ;
            }

            double value = std::atof(valueStr.c_str());
            if (valueStr.find_first_not_of("0123456789.") != std::string::npos || value < 0 || value > 1000)
            {
                if (value < 0)
                    std::cerr << "Error: not a positive number." << std::endl;
                else if (value > 1000)
                    std::cerr << "Error: too large a number." << std::endl;
                else
                    std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            std::map<std::string, float>::const_iterator it = db.lower_bound(date);
            if (it == db.end() || it->first != date)
            {
                if (it != db.begin())
                {
                    --it;
                }
                else
                {
                    std::cerr << "Error: no valid date found in database." << std::endl;
                    continue;
                }
            }

            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        }
        else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    file.close();
}
