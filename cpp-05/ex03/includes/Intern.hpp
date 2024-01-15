/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:20:00 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/15 16:50:32 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	private:
		AForm* createPresidentPardonForm_(std::string target);
		AForm* createRobotomyRequestForm_(std::string target);
		AForm* createShrubberyCreationForm_(std::string target);

	public:
		// Constructors & Destructor
		Intern(void);
		Intern(const Intern& src);
		~Intern();

		// Overload operator
		Intern& operator=(Intern const & src);

		// Public member function
		AForm*	makeForm(std::string formName, std::string target);
};

#endif
