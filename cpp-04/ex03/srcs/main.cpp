/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:05:58 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/22 10:23:18 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"

// Prototypes
void	testCharacterMaterias(void);
void	testMateriaSource(void);
void	testCharacterCopyAndUse(void);
void	testSubject(void);

// Main
int	main(void)
{
	testMateriaSource();
	testCharacterMaterias();
	testCharacterCopyAndUse();
	testSubject();
	return (0);
}

void	testMateriaSource(void)
{
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp = src->createMateria("ice");

	if (!tmp)
		std::cout << std::endl << "Learning materias:" << std::endl << std::endl;

	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	src->learnMateria(NULL);
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;

	AMateria* tmp1 = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("cure");
	AMateria* tmp3 = src->createMateria("fire");

	if (!tmp3)
		std::cout << std::endl << "Finished!" << std::endl << std::endl;

	delete tmp1;
	delete tmp2;

	delete src;
}

void	testCharacterMaterias(void)
{
	std::cout << "Initialize materia source :" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	std::cout << "Creating materias :" << std::endl;
	AMateria* tmp1 = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("cure");
	AMateria* tmp3 = src->createMateria("ice");
	AMateria* tmp4 = src->createMateria("cure");
	AMateria* tmp5 = src->createMateria("ice");
	std::cout << std::endl;

	std::cout << "Creating Character and equip materias :" << std::endl;
	ICharacter* me = new Character("me");
	me->equip(tmp1);
	me->equip(tmp2);
	me->equip(tmp3);
	me->equip(tmp4);
	std::cout << std::endl;
	me->equip(tmp5);
	me->unequip(3);
	me->equip(tmp5);
	std::cout << std::endl;

	std::cout << "Delete floor materia :" << std::endl;
	delete tmp4;
	std::cout << "Delete character and its materias :" << std::endl;
	delete me;
	std::cout << "Delete materia source :" << std::endl;
	delete src;
}

void	testCharacterCopyAndUse(void)
{
	std::cout << "Initialize materia source :" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	std::cout << "Creating materias :" << std::endl;
	AMateria* tmp1 = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("cure");
	std::cout << std::endl;

	std::cout << "Creating Character and equip materias :" << std::endl;
	Character* me = new Character("me");
	me->equip(tmp1);
	me->equip(tmp2);
	std::cout << std::endl;

	std::cout << "Copy Character" << std::endl;
	Character jon(*me);
	std::cout << jon.getName() << std::endl;
	Character bob = jon;
	std::cout << bob.getName() << std::endl << std::endl;

	std::cout << "Use of materias and check that copy is not shallow" << std::endl;
	me->use(-1, bob);
	me->use(10, bob);
	me->use(0, bob);
	me->use(1, bob);
	bob.use(0, *me);
	bob.use(1, *me);

	std::cout << "Delete base character and their materias :" << std::endl;
	delete me;

	std::cout << std::endl << "Delete materia source :" << std::endl;
	delete src;
}

void	testSubject(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}
