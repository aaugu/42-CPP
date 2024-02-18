/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:34:54 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/19 00:04:27 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <iostream>

# define UNSORTED 0
# define SORTED 1
# define LIST 0
# define VECTOR 1
# define MAIN 0
# define PENDING 1

class PmergeMe
{
	private:
		std::list<int>		list;
		std::vector<int>	vector;
		std::list<int>		sortedList;
		std::vector<int>	sortedVector;

		// ------------------------------ List ------------------------------ //
		void	sortList(void);
		// List - Utils
		bool	isListSorted(std::list<int>& list);
		void	copyList(std::list<int>& src, std::list<int>& dest);
		// List - Sorting Algorithm
		void	mergeInsertionSort(std::list<int>& sequence, std::list<int>& sortedList);
		void	splitIntoPairs( std::list< std::pair<int, int> >& pairs, std::list<int>& sequence);
		void	sortPairs(std::list< std::pair<int, int> >& pairs);
		void	extractHighestValues(std::list< std::pair<int, int> >& pairs, std::list<int>& sequence);
		void	mergePendingsToSortedList(std::list< std::pair<int, int> >& pairs, std::list<int>& mainSequence);
		int		getPairFirst(std::list< std::pair<int, int> >& pairs, int nbToSearch);
		void	insertIntoSequence(std::list<int>& sequence, int nbToInsert);
		std::list<int>::iterator	binarySearchPosition(std::list<int>& sequence, int nbToInsert);
		int		getMiddlePosition(std::list<int>::iterator begin, std::list<int>::iterator end);

		// ----------------------------- Vector ----------------------------- //
		void	sortVector(void);
		// Vector - Utils
		bool	isVectorSorted(void);
		void	copyVector(std::vector<int>& src, std::vector<int>& dest);
		// Vector = Sorting Algorithm
		void	mergeInsertionSort(std::vector<int>& vector);

		// Print list or vector
		template < typename T >
		void	printElements(T& container) {
			for ( typename T::iterator it = container.begin(); it != container.end(); it++ )
				std::cout << *it << " ";
		};

		PmergeMe(void);

	public:
		// Orthodox Canonical Form
		PmergeMe(int* numbersToSort, int nbElements);
		PmergeMe(const PmergeMe& src);
		~PmergeMe(void);
		PmergeMe&	operator=(const PmergeMe& src);

		// Public member function
		std::clock_t	runSorting(int containerType);
		void			printRand(std::string period, int sorted);
};


#endif
