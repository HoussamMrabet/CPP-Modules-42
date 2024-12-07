/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:45:54 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 02:47:48 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib> // for std::exit

bool isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isNumber(const std::string &token) {
    return token.size() == 1 && std::isdigit(token[0]);
}

int performOperation(int a, int b, const std::string &op) {
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/") {
        if (b == 0) {
            std::cerr << "Error: Division by zero" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        return a / b;
    }
    return 0; // Should never reach here
}

int evaluateRPN(const std::string &expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isNumber(token)) {
            stack.push(token[0] - '0'); // Convert char digit to int
        } else if (isOperator(token)) {
            if (stack.size() < 2) {
                std::cerr << "Error: Malformed expression" << std::endl;
                std::exit(EXIT_FAILURE);
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result = performOperation(a, b, token);
            stack.push(result);
        } else {
            std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Error: Malformed expression" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return stack.top();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Invalid arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::string expression = argv[1];
    try {
        int result = evaluateRPN(expression);
        std::cout << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
