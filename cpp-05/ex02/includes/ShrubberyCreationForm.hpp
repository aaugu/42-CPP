/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:01:01 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/20 16:14:53 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target_;

		static const int	signGrade = 145;
		static const int	execGrade = 137;

	public:
		// Constructors & Destructor
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm(void);

		// Overload operator
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);

		// Member functions
		void	beExecuted(void) const;

		// Accessors
		const std::string	getTarget(void) const;

		static const std::string	teaTree;
};

#endif
