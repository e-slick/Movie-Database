#include "Pictures.h"
//#include "BSTree.h"



Pictures::Pictures()
{
}


Pictures::~Pictures()
{
}

void Pictures::readIn()
{
	//vector of objects (movies) containing the following data:
	//name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
	GeneralData movies;

	ifstream myFile("pictures.csv");
	string tName, tNominations, tGenre1, tGenre2, tSynopsis, firstLine;
	string tYear, tRating, tDuration, tRelease, tMetacritic;

	//myFile.open("pictures.csv");
	getline(myFile, firstLine);
	while (getline(myFile, tName, ',')) {



		movies.name = tName;

		//a getline of a temporary string containing a value to be stored
		getline(myFile, tYear, ',');
		movies.year = tYear;

		getline(myFile, tNominations, ',');
		movies.nominations = tNominations;


		getline(myFile, tRating, ',');
		movies.rating = tRating;


		getline(myFile, tDuration, ',');
		movies.duration = tDuration;

		getline(myFile, tGenre1, ',');
		movies.genre1 = tGenre1;


		getline(myFile, tGenre2, ',');
		movies.genre2 = tGenre2;


		getline(myFile, tRelease, ',');
		movies.release = tRelease;


		getline(myFile, tMetacritic, ',');
		movies.metacritic = tMetacritic;


		getline(myFile, tSynopsis, '.');
		movies.synopsis = tSynopsis;
		
		getline(myFile, firstLine);
		//add movie to the vector
		//vecOfPictures.push_back(movie);
		
		//BSTree<GeneralData, string> *tree = new BSTree<GeneralData, string>;
		//tree->addNode(movies.name, movies);
	}
}
