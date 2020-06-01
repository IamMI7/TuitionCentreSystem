#ifndef RATING_H // To make sure you don't declare the function more than once by including the header multiple times.
#define RATING_H

struct Rating 
{
private:
	int ratingTotal;
	int ratingSize;
public:
	// Constructors
	Rating();
	Rating(int ratingSize, int ratingTotal);

	// Methods
	void addRating(int rating);
	int getRatingAverage();
};

#endif