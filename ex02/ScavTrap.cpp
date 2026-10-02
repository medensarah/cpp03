/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:36:53 by smedenec          #+#    #+#             */
/*   Updated: 2026/10/02 21:22:22 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"



// Constructors, Operator

ScavTrap::ScavTrap(): ClapTrap("Unknown", 100, 50, 20)
{
	std::cout << "Constructor called, creating ScavTrap " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "Constructor called, creating ScavTrap " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "Copy constructor called, creating ScavTrap " << this->_name << " from ScavTrap " << other._name << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "Copy assignment operator called for ScavTrap" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called, destroying ScavTrap " << this->_name << std::endl;
}



// Public Functions

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		return ;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
