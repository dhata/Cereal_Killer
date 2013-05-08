#include "hsmaxlist.h"

HSMaxList::HSMaxList() : slist_(){
}

HSMaxList::~HSMaxList() {
	while(!slist_.empty()){
		HighScore * temp = slist_.front();
		slist_.pop_front();
		delete temp;
	}
	slist_.clear();
}

void HSMaxList::push(HighScore* hs){
	std::list<HighScore*>::iterator it;
	for(it=slist_.begin();it!=slist_.end();it++){
		if(*hs>**it){
			slist_.insert(it,hs);
			return;
		}
	}
	slist_.insert(it,hs);
}

void HSMaxList::pop()
{
  slist_.pop_front();
}

HighScore* HSMaxList::top(){
	return slist_.front();
}
