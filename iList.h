#include"Telefon.h"



class iList
{


public:

	virtual void add(Telefon* t) = 0;

	virtual void remove(int index) = 0;

	virtual void remove(Telefon* t) = 0;

	virtual bool contains(Telefon* t) = 0;

	virtual bool isEmpty() = 0;

	virtual int indexOf(Telefon* t) = 0;

	virtual int size() = 0;

	virtual Telefon* get(int index) = 0;

};


