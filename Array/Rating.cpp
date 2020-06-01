#include "Rating.h"
#include <iostream>
using namespace std;

Rating::Rating() {};

Rating::Rating(int t, int s) {
	this->ratingTotal = t;
	this->ratingSize = s;
}


int Rating::getRatingTotal() {
	return this->ratingTotal;
}
int Rating::getRatingSize() {
	return this->ratingSize;
}
void Rating::setRatingTotal(int n) {
	this->ratingTotal = n;
}
void Rating::setRatingSize(int n) {
	this->ratingSize = n;
}

void Rating::addRating(int rating) {
	this->ratingTotal += rating;
	this->ratingSize++;
}

int Rating::getRatingAverage() {
	//if no one has rated
	if (ratingSize == 0) {
		return 0;
	}
	else {
		return ratingTotal / ratingSize;
	}
}

void Rating::toString() {
	cout << "Rating Total: " << ratingTotal<<endl;
	cout << "Rating Size: " << ratingSize <<endl;
}

