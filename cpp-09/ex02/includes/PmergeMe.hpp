/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:34:54 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/08 10:38:59 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe
{
	private:
		/* data */

	public:
		// Orthodox Canonical Form
		PmergeMe(void);
		PmergeMe(const PmergeMe& src);
		~PmergeMe(void);
		PmergeMe&	operator=(const PmergeMe& src);
};

#endif
