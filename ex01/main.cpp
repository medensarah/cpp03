/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:01:00 by smedenec          #+#    #+#             */
/*   Updated: 2026/10/02 21:14:44 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	std::cout << "========== CONSTRUCTORS ==========" << std::endl;
	ScavTrap defaultScav;
	ScavTrap bob("Bob");

	std::cout << std::endl;
	std::cout << "========== BASIC ATTACK ==========" << std::endl;
	bob.attack("Target");

	std::cout << std::endl;
	std::cout << "========== INHERITED FUNCTIONS ==========" << std::endl;
	bob.takeDamage(30);
	bob.beRepaired(10);

	std::cout << std::endl;
	std::cout << "========== GUARD GATE ==========" << std::endl;
	bob.guardGate();

	std::cout << std::endl;
	std::cout << "========== COPY CONSTRUCTOR ==========" << std::endl;
	ScavTrap copy(bob);
	copy.attack("CopyTarget");
	copy.guardGate();

	std::cout << std::endl;
	std::cout << "========== COPY ASSIGNMENT ==========" << std::endl;
	ScavTrap assigned("Assigned");
	assigned = bob;
	assigned.attack("AssignedTarget");

	std::cout << std::endl;
	std::cout << "========== ENERGY DEPLETION ==========" << std::endl;
	ScavTrap energy("EnergyTest");

	for (int i = 1; i <= 50; i++)
	{
		std::cout << "--- Attack " << i << " ---" << std::endl;
		energy.attack("Target");
	}

	std::cout << "--- Attack 51 (should do nothing) ---" << std::endl;
	energy.attack("Target");

	std::cout << std::endl;
	std::cout << "========== ENERGY WITH REPAIR ==========" << std::endl;
	ScavTrap energyRepair("EnergyRepair");

	for (int i = 1; i <= 25; i++)
		energyRepair.attack("Target");

	energyRepair.beRepaired(20);

	for (int i = 1; i <= 25; i++)
		energyRepair.attack("Target");

	std::cout << "--- Repair with 0 energy (should do nothing) ---" << std::endl;
	energyRepair.beRepaired(5);

	std::cout << std::endl;
	std::cout << "========== DEATH ==========" << std::endl;
	ScavTrap dead("Dead");

	dead.takeDamage(100);

	std::cout << "--- Attack with 0 HP (should do nothing) ---" << std::endl;
	dead.attack("Target");

	std::cout << "--- Repair with 0 HP (should do nothing) ---" << std::endl;
	dead.beRepaired(5);

	std::cout << std::endl;
	std::cout << "========== OVERKILL ==========" << std::endl;
	ScavTrap overkill("Overkill");

	overkill.takeDamage(999999);

	std::cout << "--- Attack after overkill (should do nothing) ---" << std::endl;
	overkill.attack("Target");

	std::cout << "--- Repair after overkill (should do nothing) ---" << std::endl;
	overkill.beRepaired(5);

	std::cout << std::endl;
	std::cout << "========== SELF ASSIGNMENT ==========" << std::endl;
	ScavTrap self("Self");
	self = self;
	self.attack("Target");

	std::cout << std::endl;
	std::cout << "========== CONSTRUCTION / DESTRUCTION CHAIN ==========" << std::endl;
	{
		ScavTrap scoped("Scoped");
		std::cout << "--- Leaving scope ---" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== END OF MAIN ==========" << std::endl;

	return (0);
}
