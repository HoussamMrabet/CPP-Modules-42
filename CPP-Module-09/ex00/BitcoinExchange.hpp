/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:12:37 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 14:06:10 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdlib>

std::string                     trim(const std::string &str);
std::map<std::string, float>    loadDatabase(const std::string &filename);
int                             isLeapYear(int year);
bool                            isValidDate(int year, int month, int day);
bool                            parseDate(const std::string &date);
void                            processInput(const std::string &filename, const std::map<std::string, float> &db);

#endif