/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:47:30 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/08 21:15:52 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isValidNumber(const std::string& str)
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!isdigit(str[i]) || std::atof(str.c_str()) > std::numeric_limits<int>::max())
            return (false);
    }
    
    return (!str.empty());
}

