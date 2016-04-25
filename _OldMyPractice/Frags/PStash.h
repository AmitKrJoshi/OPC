#ifndef PSTASH_H
#define PSTASH_H

class PStash{
	int quantity;	// No of storage space
	int next;		// Next empty space
	// Pointer storage
	void ** storage;
	void inflate(int increase);
public:
	PStash() : quantity(0), storage(0), next(0){}
	~PStash();
	int add(void* element);
	void* operator[](int index) const;		// To fetch
	void* remove(int index);				// Remoe the reference from this PStash
	int count() const {
		return next;
	}
};

#endif