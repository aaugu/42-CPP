/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:01:11 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/15 16:05:06 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target_;

		static const int	signGrade = 25;
		static const int	execGrade = 5;

	public:
		// Constructors & Destructor
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		~PresidentialPardonForm(void);

		// Overload operator
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);

		// Accessors
		const std::string	getTarget(void) const;
};



#endif
