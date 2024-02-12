/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:34:43 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/08 10:38:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

class RPN
{
	private:
		/* data */

	public:
		// Orthodox Canonical Form
		RPN(void);
		RPN(const RPN& src);
		~RPN(void);
		RPN&	operator=(const RPN& src);
};

#endif
