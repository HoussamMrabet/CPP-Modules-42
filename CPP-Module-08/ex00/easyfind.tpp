/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:25:34 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/03 01:47:51 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template<typename T>
int	easyfind(T const &container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	
	if (it == container.end())
		throw std::runtime_error("No occurrence found in the container.");

	return (*it);
}

#endif