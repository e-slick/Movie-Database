#pragma once
#include "BSTree.h"

class Pictures
{
public:
	Pictures();
	~Pictures();

	//read in from a CSV file
	void readIn();

	//setters
	void setName(string _name) { name = _name; }
	void setNominations(string _nominations) { nominations = _nominations; }
	void setGenre1(string _genre1) { genre1 = _genre1; }
	void setGenre2(string _genre2) { genre2 = _genre2; }
	void setRelease(string _release) { release = _release; }
	void setSynopsis(string _synopsis) { synopsis = _synopsis; }
	void setYear(string _year) { year = _year; }
	void setRating(string _rating) { rating = _rating; }
	void setMetacritic(string _metacritic) { metacritic = _metacritic; }
	void setDuration(string _duration) { duration = _duration; }
	//getters
	string getName() { return name; }
	string getNominations() { return nominations; }
	string getGenre1() { return genre1; }
	string getGenre2() { return genre2; }
	string getRelease() { return release; }
	string getSynopsis() { return synopsis; }
	string getYear() { return year; }
	string getRating() { return rating; }
	string getMetacritic() { return metacritic; }
	string getDuration() { return duration; }


private:
	vector<Pictures> vecOfPictures;
	//name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
	string name, nominations, genre1, genre2, release, synopsis;
	string year, rating, metacritic, duration;
};

