/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 21:16:18 by smedenec          #+#    #+#             */
/*   Updated: 2026/10/02 21:29:18 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"



// Constructors, Operator

FragTrap::FragTrap(): ClapTrap("Unknown", 100, 100, 30)
{
	std::cout << "Constructor called, creating FragTrap " << this->_name << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "Constructor called, creating FragTrap " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "Copy constructor called, creating FragTrap " << this->_name << " from FragTrap " << other._name << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Copy assignment operator called for FragTrap" << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called, destroying FragTrap " << this->_name << std::endl;
}



// Public Functions

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a positive high-five!" << std::endl;
}
