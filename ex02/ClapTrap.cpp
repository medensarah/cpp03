/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:04:48 by smedenec          #+#    #+#             */
/*   Updated: 2026/10/02 21:09:11 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"



// Constructors, Operator

ClapTrap::ClapTrap(): _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called (Default), creating ClapTrap " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called, creating ClapTrap " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage)
				: _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "Constructor called, creating ClapTrap " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hitPoints(other._hitPoints),
											_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor called, creating ClapTrap " << this->_name << " from ClapTrap " << other._name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called, assigning " << other._name << " to " << this->_name << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called, destroying ClapTrap " << this->_name << std::endl;
}



// Public Functions

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " is being attacked, causing " << amount << " points of damage!" << std::endl;
	if (this->_hitPoints > amount)
		this->_hitPoints = this->_hitPoints - amount;
	else
		this->_hitPoints = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " repairs itself, recovering " << amount << " HP!" << std::endl;
	if (amount > UINT_MAX - this->_hitPoints)
		this->_hitPoints = UINT_MAX;
	else
		this->_hitPoints += amount;
	this->_energyPoints--;
}
