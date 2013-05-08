#include "highscore.h"

HighScore::HighScore(QString name, int score){
	name_=name;
	score_=score;
}

bool HighScore::operator<(const HighScore &rhs){
	if(score_< rhs.score_){
		return true;
	} else 
		return false;
}

bool HighScore::operator>(  const HighScore &rhs){
	if( score_>rhs.score_){
		return true;
	} else {
		return false;
	}
}

std::ostream& operator<<(std::ostream &os, const HighScore &hs){ 
	os<<hs.name_.toStdString() << '\t' << hs.score_;
	return os;
}

std::ofstream& operator<<(std::ofstream &ofs, const HighScore &hs){ 
	ofs<<hs.name_.toStdString() << '\n' << hs.score_;
	return ofs;
}

QString HighScore::toString(){
	QString a;
	a.setNum(score_);
	return name_+'\t'+a;
}
