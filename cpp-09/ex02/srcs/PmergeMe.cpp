/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:35:24 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/19 00:18:46 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <ctime>
#include <utility>
#include <algorithm>
#include "../includes/PmergeMe.hpp"

void	printSequence(std::list<int>& sequence, std::string title);

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(int* numbersToSort, int nbElements) {
	for (int i = 0; i < nbElements; i++)
	{
		list.push_back(numbersToSort[i]);
		vector.push_back(numbersToSort[i]);
	}
}

PmergeMe::PmergeMe(const PmergeMe& src) : list(src.list), vector(src.vector) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& src) {
	(void) src;
	// copyList(src.list, list);
	// copyVector(src.vector, vector);
	return ( *this );
}

/* ************************************************************************** */
/*                          PUBLIC MEMBER FUNCTIONS                           */
/* ************************************************************************** */

std::clock_t	PmergeMe::runSorting(int containerType)
{
	std::clock_t	start = std::clock();

	if (containerType == LIST)
		sortList();
	else if (containerType == VECTOR)
		sortVector();
	std::clock_t	end = std::clock();

	return (end - start);
}


void	PmergeMe::printRand(std::string period, int sorted)
{
	std::cout << period;
	if (sorted)
		/*std::rand() % 2 ? */printElements(sortedList)/* : printElements(sortedVector)*/;
	else
		/*std::rand() % 2 ? */printElements(list)/* : printElements(vector)*/;
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                          PRIVATE MEMBER FUNCTIONS                          */
/* ************************************************************************** */

// ----------------------------- Container List ----------------------------- //

void	PmergeMe::sortList(void)
{
	if (isListSorted(list))
		return ( copyList(list, sortedList) );

	mergeInsertionSort(list, sortedList);

	if ( isListSorted(sortedList) == false )
		throw std::runtime_error("could not sort the list properly");
}

// ------------------------- Container List - Utils ------------------------- //

bool	PmergeMe::isListSorted(std::list<int>& list)
{
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator next = list.begin();
	next++;
	for ( ; next != list.end(); it++, next++ )
	{
		if ( *it > *next )
			return ( false );
	}
	return ( true );
}

void	PmergeMe::copyList(std::list<int>& src, std::list<int>& dest)
{
	for (  std::list<int>::iterator it = src.begin(); it != src.end(); it++ )
		dest.push_back(*it);
}

// ------------------ Container List - Sorting Algorithm ------------------- //

void	PmergeMe::mergeInsertionSort(std::list<int>& sequence, std::list<int>& sortedList)
{
	bool	leftOver = (sequence.size() % 2 != 0);

	std::list< std::pair<int, int> >	pairs;
	splitIntoPairs(pairs, sequence);
	sortPairs(pairs);

	std::list<int>	highestValues;
	if ( pairs.size() > 1 )
	{
		extractHighestValues(pairs, highestValues);
		mergeInsertionSort(highestValues, sortedList);
		mergePendingsToSortedList(pairs, sortedList);
	}
	else
	{
		sortedList.push_back(pairs.begin()->first);
		sortedList.push_back(pairs.begin()->second);
	}

	if (leftOver)
	{
		int	nbToInsert = *(sequence.rbegin());
		insertIntoSequence(sortedList, nbToInsert);
	}
}

void	PmergeMe::splitIntoPairs(std::list< std::pair<int, int> >& pairs, std::list<int>& sequence)
{
	int	firstOfPair = -1;

	for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
	{
		if (firstOfPair == -1)
			firstOfPair = *it;
		else
		{
			pairs.push_back(std::make_pair(firstOfPair, *it));
			firstOfPair = -1;
		}
	}
}

void	PmergeMe::sortPairs(std::list< std::pair<int, int> >& pairs)
{
	std::list< std::pair<int, int> >::iterator it;
	for (  it = pairs.begin(); it != pairs.end(); it++ )
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

void	PmergeMe::extractHighestValues(std::list< std::pair<int, int> >& pairs, std::list<int>& mainSequence)
{
	std::list< std::pair<int, int> >::iterator it;
	for ( it = pairs.begin(); it != pairs.end(); it++ )
		mainSequence.push_back(it->second);
}

void	PmergeMe::mergePendingsToSortedList(std::list< std::pair<int, int> >& pairs, std::list<int>& mainSequence)
{
	std::list<int>	sequence;
	copyList(mainSequence, sequence);

	std::list<int>::iterator	it;
	int	nbToInsert;
	for ( it = sequence.begin(); it != sequence.end(); it++)
	{
		nbToInsert = getPairFirst(pairs, *it);
		insertIntoSequence(mainSequence, nbToInsert);
	}
}

int	PmergeMe::getPairFirst(std::list< std::pair<int, int> >& pairs, int nbToSearch)
{
	std::list< std::pair<int, int> >::iterator it;
	for (  it = pairs.begin(); it != pairs.end(); it++ )
	{
		if (it->second == nbToSearch)
			return (it->first);
	}
	throw	std::runtime_error("cannot find other pair element");
}

void	PmergeMe::insertIntoSequence(std::list<int>& sequence, int nbToInsert)
{
	std::list<int>::iterator	itb = sequence.begin();
	std::list<int>::iterator	ite = sequence.end();
	ite--;

	if (nbToInsert < *itb)
		sequence.push_front(nbToInsert);
	else if (nbToInsert > *ite)
		sequence.push_back(nbToInsert);
	else
	{
		std::list<int>::iterator	position;
		position = binarySearchPosition(sequence, nbToInsert);
		sequence.insert(position, nbToInsert);
	}
}

std::list<int>::iterator	PmergeMe::binarySearchPosition(std::list<int>& sequence, int nbToInsert)
{
	std::list<int>::iterator	i = sequence.begin();
	std::list<int>::iterator	j = sequence.end();
	j--;
	std::list<int>::iterator	middleIt;

	int	middle = getMiddlePosition(i, j);

	while (getMiddlePosition(i, j) != 0)
	{
		middleIt = sequence.begin();
		for (int iter = 0; iter < middle; iter++)
			middleIt++;

		if (nbToInsert > *middleIt)
		{
			i = middleIt;
			middle += getMiddlePosition(i, j);
		}
		else
		{
			j = middleIt;
			middle -= getMiddlePosition(i, j);
		}
	}

	if (nbToInsert > *i)
        i++;
	return (i);
}

int	PmergeMe::getMiddlePosition(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	int	count = 0;
	for ( ; begin != end; begin++)
		count++;

	return (count / 2);
}

// ---------------------------- Container Vector ---------------------------- //

void	PmergeMe::sortVector(void)
{
	if (isVectorSorted(vector))
		return ( copyVector(vector, sortedVector) );

	mergeInsertionSort(vector, sortedVector);

	if ( isVectorSorted(sortedVector) == false )
		throw std::runtime_error("could not sort the vector properly");
}

// ------------------------ Container Vector - Utils ------------------------ //

bool	PmergeMe::isVectorSorted(std::vector<int>& vector)
{
	std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator next = vector.begin()++;
	for ( ; next != vector.end(); it++, next++ )
	{
		if ( next != vector.end() && *it > *next )
			return ( false );
	}
	return ( true );
}

void	PmergeMe::copyVector(std::vector<int>& src, std::vector<int>& dest)
{
	for (  std::vector<int>::iterator it = src.begin(); it != src.end(); it++ )
		dest.push_back(*it);
}

// ----------------- Container Vector - Sorting Algorithm ------------------- //

void	PmergeMe::mergeInsertionSort(std::vector<int>& sequence, std::vector<int>& sortedVector)
{
	bool	leftOver = (sequence.size() % 2 != 0);

	std::vector< std::pair<int, int> >	pairs;
	splitIntoPairs(pairs, sequence);
	sortPairs(pairs);

	std::vector<int>	highestValues;
	if ( pairs.size() > 1 )
	{
		extractHighestValues(pairs, highestValues);
		mergeInsertionSort(highestValues, sortedVector);
		mergePendingsToSortedVector(pairs, sortedVector);
	}
	else
	{
		sortedVector.push_back(pairs.begin()->first);
		sortedVector.push_back(pairs.begin()->second);
	}

	if (leftOver)
	{
		int	nbToInsert = *(sequence.rbegin());
		insertIntoSequence(sortedVector, nbToInsert);
	}
}

void	PmergeMe::splitIntoPairs(std::vector< std::pair<int, int> >& pairs, std::vector<int>& sequence)
{
	int	firstOfPair = -1;

	for (std::vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
	{
		if (firstOfPair == -1)
			firstOfPair = *it;
		else
		{
			pairs.push_back(std::make_pair(firstOfPair, *it));
			firstOfPair = -1;
		}
	}
}

void	PmergeMe::sortPairs(std::vector< std::pair<int, int> >& pairs)
{
	std::vector< std::pair<int, int> >::iterator it;
	for (  it = pairs.begin(); it != pairs.end(); it++ )
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

void	PmergeMe::extractHighestValues(std::vector< std::pair<int, int> >& pairs, std::vector<int>& mainSequence)
{
	std::vector< std::pair<int, int> >::iterator it;
	for ( it = pairs.begin(); it != pairs.end(); it++ )
		mainSequence.push_back(it->second);
}

void	PmergeMe::mergePendingsToSortedVector(std::vector< std::pair<int, int> >& pairs, std::vector<int>& mainSequence)
{
	std::vector<int>	sequence;
	copyVector(mainSequence, sequence);

	std::vector<int>::iterator	it;
	int	nbToInsert;
	for ( it = sequence.begin(); it != sequence.end(); it++)
	{
		nbToInsert = getPairFirst(pairs, *it);
		insertIntoSequence(mainSequence, nbToInsert);
	}
}

int	PmergeMe::getPairFirst(std::vector< std::pair<int, int> >& pairs, int nbToSearch)
{
	std::vector< std::pair<int, int> >::iterator it;
	for (  it = pairs.begin(); it != pairs.end(); it++ )
	{
		if (it->second == nbToSearch)
			return (it->first);
	}
	throw	std::runtime_error("cannot find other pair element");
}

void	PmergeMe::insertIntoSequence(std::vector<int>& sequence, int nbToInsert)
{
	std::vector<int>::iterator	itb = sequence.begin();
	std::vector<int>::iterator	ite = sequence.end();
	ite--;

	if (nbToInsert < *itb)
		sequence.insert(itb, nbToInsert);
	else if (nbToInsert > *ite)
		sequence.push_back(nbToInsert);
	else
	{
		std::vector<int>::iterator	position;
		position = binarySearchPosition(sequence, nbToInsert);
		sequence.insert(position, nbToInsert);
	}
}

std::vector<int>::iterator	PmergeMe::binarySearchPosition(std::vector<int>& sequence, int nbToInsert)
{
	std::vector<int>::iterator	i = sequence.begin();
	std::vector<int>::iterator	j = sequence.end();
	j--;
	std::vector<int>::iterator	middleIt;

	int	middle = getMiddlePosition(i, j);

	while (getMiddlePosition(i, j) != 0)
	{
		middleIt = sequence.begin();
		for (int iter = 0; iter < middle; iter++)
			middleIt++;

		if (nbToInsert > *middleIt)
		{
			i = middleIt;
			middle += getMiddlePosition(i, j);
		}
		else
		{
			j = middleIt;
			middle -= getMiddlePosition(i, j);
		}
	}

	if (nbToInsert > *i)
        i++;
	return (i);
}

int	PmergeMe::getMiddlePosition(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int	count = 0;
	for ( ; begin != end; begin++)
		count++;

	return (count / 2);
}


template < typename T >
void	printSequence(T& sequence, std::string title)
{
	std::cout << title << " ";
	for (typename T::iterator it = sequence.begin(); it != sequence.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
