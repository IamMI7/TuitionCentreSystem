#include "Rating.h"
#include <iostream>

/**Rating Class**/

// Constructor
Rating::Rating() {}
Rating::Rating(int ratingTotal, int ratingSize) 
{
	Rating::ratingTotal = ratingTotal;
	Rating::ratingSize = ratingSize;
}

// Methods
void Rating::addRating(int rating)
{
	Rating::ratingTotal += rating;
	Rating::ratingSize += 1;
}

int Rating::getRatingAverage()
{
	//Return average if tutor has been rated, if not, return 0
	if (ratingSize == 0) {
		return 0;
	}
	else {
		int ratingAverage = ratingTotal / ratingSize;
		return ratingAverage;
	}
}