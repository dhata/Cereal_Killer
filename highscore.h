#ifndef HIGHSCORE_H
#define HIGHSCORE_H


#include <QString>
#include <ostream>
#include <fstream>

class HighScore {
public:
	QString name_;
	int score_;
	HighScore(QString name, int score);
	bool operator<(const HighScore &rhs);
	bool operator>( const HighScore &rhs);
	friend std::ostream& operator<<(std::ostream &os, const HighScore &hs);
	friend std::ofstream& operator<<(std::ofstream &ofs, const HighScore &hs);
	QString toString();
	
};

#endif
