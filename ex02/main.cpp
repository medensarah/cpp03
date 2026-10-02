/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:01:00 by smedenec          #+#    #+#             */
/*   Updated: 2026/10/02 21:47:28 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::cout << "========== CONSTRUCTORS ==========" << std::endl;

	FragTrap defaultFrag;
	FragTrap frag("Bob");

	std::cout << std::endl;

	std::cout << "========== BASIC ATTACK ==========" << std::endl;

	frag.attack("Target");

	std::cout << std::endl;

	std::cout << "========== HIGH FIVE ==========" << std::endl;

	frag.highFivesGuys();

	std::cout << std::endl;

	std::cout << "========== INHERITED FUNCTIONS ==========" << std::endl;

	frag.takeDamage(30);
	frag.beRepaired(10);

	std::cout << std::endl;

	std::cout << "========== COPY CONSTRUCTOR ==========" << std::endl;

	FragTrap copy(frag);

	copy.attack("CopyTarget");
	copy.highFivesGuys();

	std::cout << std::endl;

	std::cout << "========== COPY ASSIGNMENT ==========" << std::endl;

	FragTrap assigned("Assigned");

	assigned = frag;

	assigned.attack("AssignedTarget");

	std::cout << std::endl;

	std::cout << "========== ENERGY DEPLETION ==========" << std::endl;

	FragTrap energyTest("EnergyTest");

	for (int i = 1; i <= 100; i++)
	{
		std::cout << "--- Attack " << i << " ---" << std::endl;
		energyTest.attack("Target");
	}

	std::cout << "--- Attack 101 (should do nothing) ---" << std::endl;
	energyTest.attack("Target");

	std::cout << std::endl;

	std::cout << "========== ENERGY WITH REPAIR ==========" << std::endl;

	FragTrap energyRepair("EnergyRepair");

	for (int i = 0; i < 50; i++)
		energyRepair.attack("Target");

	energyRepair.beRepaired(20);

	for (int i = 0; i < 50; i++)
		energyRepair.attack("Target");

	std::cout << "--- Repair with 0 energy (should do nothing) ---" << std::endl;
	energyRepair.beRepaired(20);

	std::cout << std::endl;

	std::cout << "========== DEATH ==========" << std::endl;

	FragTrap dead("Dead");

	dead.takeDamage(100);

	std::cout << "--- Attack with 0 HP (should do nothing) ---" << std::endl;
	dead.attack("Target");

	std::cout << "--- Repair with 0 HP (should do nothing) ---" << std::endl;
	dead.beRepaired(20);

	std::cout << std::endl;

	std::cout << "========== OVERKILL ==========" << std::endl;

	FragTrap overkill("Overkill");

	overkill.takeDamage(999999);

	std::cout << "--- Attack after overkill (should do nothing) ---" << std::endl;
	overkill.attack("Target");

	std::cout << "--- Repair after overkill (should do nothing) ---" << std::endl;
	overkill.beRepaired(20);

	std::cout << std::endl;

	std::cout << "========== SELF ASSIGNMENT ==========" << std::endl;

	FragTrap self("Self");

	self = self;

	self.attack("Target");

	std::cout << std::endl;

	std::cout << "========== CONSTRUCTION / DESTRUCTION CHAIN ==========" << std::endl;

	{
		FragTrap scoped("Scoped");

		std::cout << "--- Leaving scope ---" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "========== END OF MAIN ==========" << std::endl;

	return (0);
}
