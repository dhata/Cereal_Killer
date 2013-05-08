#ifndef HIGHSCORE_H
#define HIGHSCORE_H


#include <QString>
#include <ostream>
#include <fstream>

/** HighScore is a class that keeps track of a player's username and score */
class HighScore {
public:
	/** name of the player */
	QString name_;
	/** score that the player achieved */
	int score_;
	/** default constructor that initializes name and score based on passed in values */
	HighScore(QString name, int score);
	/** overloaded less than operator that compares HighScore objects based on the score */
	bool operator<(const HighScore &rhs);
	/** overloaded greater than operator that compares HighScore objects based on the score */
	bool operator>( const HighScore &rhs);
	/** overloaded ostream << operator that prints out the player's name and score */
	friend std::ostream& operator<<(std::ostream &os, const HighScore &hs);
	/** overloaded ofstream << operator that prints out the player's name and score to a file */
	friend std::ofstream& operator<<(std::ofstream &ofs, const HighScore &hs);
	QString toString();
	
};

#endif
