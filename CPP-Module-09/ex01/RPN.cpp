/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:18:46 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 20:09:02 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(const std::string &token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool isNumber(const std::string &token)
{
    return (token.size() == 1 && std::isdigit(token[0]));
}

float performOperation(float a, float b, const std::string &op)
{
    if (op == "+")
        return (a + b);
    else if (op == "-")
        return (a - b);
    else if (op == "*")
        return (a * b);
    else if (op == "/") {
        if (b == 0)
        {
            std::cerr << "Error: Division by zero" << std::endl;
            std::exit(1);
        }
        return (a / b);
    }
    return (0);
}

float evaluateRPN(const std::string &expression)
{
    std::stack<float>     stack;
    std::istringstream  iss(expression);
    std::string         token;

    while (iss >> token)
    {
        if (isNumber(token))
        {
            stack.push(token[0] - '0');
        }
        else if (isOperator(token))
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: Malformed expression" << std::endl;
                std::exit(1);
            }
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            float result = performOperation(a, b, token);
            stack.push(result);
        }
        else
        {
            std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
            std::exit(1);
        }
    }

    if (stack.size() != 1)
    {
        std::cerr << "Error: Malformed expression" << std::endl;
        std::exit(1);
    }

    return (stack.top());
}
