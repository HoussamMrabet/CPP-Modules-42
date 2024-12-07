/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:17:48 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 14:22:16 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

bool    isOperator(const std::string &token);
bool    isNumber(const std::string &token);
int     performOperation(int a, int b, const std::string &op);
int     evaluateRPN(const std::string &expression);

#endif
