/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:43:52 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/30 09:45:19 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    data.content = "Hmrabet's content";

    std::cout << "Data adress: " << &data << std::endl;
    std::cout << "Data value: " << data.content << std::endl;

    uintptr_t serializedData = Serializer::serialize(&data);
    std::cout << "Serialized Data adress: " << &serializedData << std::endl;
    std::cout << "Serialized Data value: " << serializedData << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized Data adress: " << deserializedData << std::endl;
    std::cout << "Deserialized Data value: " << deserializedData->content << std::endl;

    return 0;
}
