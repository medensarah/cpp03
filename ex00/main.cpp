/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:01:00 by smedenec          #+#    #+#             */
/*   Updated: 2026/09/30 22:00:39 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main()
{
	std::cout << "========== CONSTRUCTORS ==========" << std::endl;
	ClapTrap defaultClap;
	ClapTrap bob("Bob");

	std::cout << std::endl;
	std::cout << "========== BASIC ATTACK ==========" << std::endl;
	bob.attack("Target");

	std::cout << std::endl;
	std::cout << "========== TAKE DAMAGE ==========" << std::endl;
	bob.takeDamage(3);
	bob.takeDamage(2);

	std::cout << std::endl;
	std::cout << "========== REPAIR ==========" << std::endl;
	bob.beRepaired(4);

	std::cout << std::endl;
	std::cout << "========== COPY CONSTRUCTOR ==========" << std::endl;
	ClapTrap copy(bob);
	copy.attack("CopyTarget");

	std::cout << std::endl;
	std::cout << "========== COPY ASSIGNMENT ==========" << std::endl;
	ClapTrap assigned("Assigned");
	assigned = bob;
	assigned.attack("AssignedTarget");

	std::cout << std::endl;
	std::cout << "========== ENERGY DEPLETION ==========" << std::endl;
	ClapTrap energy("EnergyTest");

	for (int i = 1; i <= 10; i++)
	{
		std::cout << "--- Attack " << i << " ---" << std::endl;
		energy.attack("Target");
	}

	std::cout << "--- Attack 11 (should do nothing) ---" << std::endl;
	energy.attack("Target");

	std::cout << std::endl;
	std::cout << "========== ENERGY DEPLETION WITH REPAIR ==========" << std::endl;
	ClapTrap energyRepair("EnergyRepair");

	for (int i = 1; i <= 5; i++)
		energyRepair.attack("Target");

	energyRepair.beRepaired(5);

	for (int i = 1; i <= 5; i++)
		energyRepair.attack("Target");

	std::cout << "--- Repair with 0 energy (should do nothing) ---" << std::endl;
	energyRepair.beRepaired(5);

	std::cout << std::endl;
	std::cout << "========== DEATH ==========" << std::endl;
	ClapTrap dead("Dead");

	dead.takeDamage(10);

	std::cout << "--- Attack with 0 HP (should do nothing) ---" << std::endl;
	dead.attack("Target");

	std::cout << "--- Repair with 0 HP (should do nothing) ---" << std::endl;
	dead.beRepaired(5);

	std::cout << std::endl;
	std::cout << "========== OVERKILL ==========" << std::endl;
	ClapTrap overkill("Overkill");

	overkill.takeDamage(999999);

	std::cout << "--- Attack after overkill (should do nothing) ---" << std::endl;
	overkill.attack("Target");

	std::cout << "--- Repair after overkill (should do nothing) ---" << std::endl;
	overkill.beRepaired(5);

	std::cout << std::endl;
	std::cout << "========== ZERO DAMAGE ==========" << std::endl;
	ClapTrap zeroDamage("ZeroDamage");

	zeroDamage.takeDamage(0);
	zeroDamage.attack("Target");
	zeroDamage.beRepaired(0);

	std::cout << std::endl;
	std::cout << "========== MULTIPLE DAMAGE / REPAIR ==========" << std::endl;
	ClapTrap fighter("Fighter");

	fighter.takeDamage(4);
	fighter.beRepaired(2);
	fighter.takeDamage(7);
	fighter.beRepaired(10);
	fighter.attack("Target");

	std::cout << std::endl;
	std::cout << "========== SELF ASSIGNMENT ==========" << std::endl;
	ClapTrap self("Self");
	self = self;
	self.attack("Target");

	std::cout << std::endl;
	std::cout << "========== END OF MAIN ==========" << std::endl;

	return (0);
}
