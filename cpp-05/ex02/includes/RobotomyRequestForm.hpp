/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:01:45 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/20 15:27:47 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target_;

		static const int	signGrade = 72;
		static const int	execGrade = 45;

	public:
		// Constructors & Destructor
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		~RobotomyRequestForm(void);

		// Overload operator
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);

		// Member functions
		void	beExecuted(void) const;

		// Accessors
		const std::string	getTarget(void) const;
};

#endif
