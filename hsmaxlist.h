#ifndef HSMAXLIST_H
#define HSMAXLIST_H

#include "highscore.h"
#include <list>

class HSMaxList {

public:
	/** default constructor, initializes the underlying list */
	HSMaxList();
	/** deletes all members of the list */
	~HSMaxList();
	
	/** returns the size of the list */
	int size() const { return slist_.size(); }
	/** returns true if the list is empty */
	bool empty() const { return slist_.empty(); }
	/** inserts a HighScore object in descending order based on the score */
	void push(HighScore* hs);
	/** removes the first (max) score */
	void pop();
	/** returns the high score with the highest score */
	HighScore* top();
	
private:
	/** the sorted list */
	std::list<HighScore*> slist_;
};

#endif
