#pragma once
#include <string>

using namespace std;

struct Rating {
private:
	//Total amount of Rating
	int ratingTotal = 0;
	//Total amount of people who rated
	int ratingSize = 0;

public:
	//Constructor;
	Rating();
	Rating(int t, int s);
	//Getter and Setter
	int getRatingTotal();
	int getRatingSize();
	void setRatingTotal(int n);
	void setRatingSize(int n);
	//Method
	//addRating to Tutor
	void addRating(int rating);
	//get Rating Average
	int getRatingAverage();
	//toString
	void toString();
};