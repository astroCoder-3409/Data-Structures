#pragma once

using namespace std;

#include <list>

template<typename Item_Type>
class ListQueue {
public:
	ListQueue() {}

	/** Pushes an item onto the back of the queue.
	@param item The item to be inserted
	*/
	void push(const Item_Type& item) {
		container.push_back(item);
	}

	/** Returns the object at the front of the queue
	and removes it.
	@return The object at the front of the queue
	*/
	Item_Type frontThenPop() {
		Item_Type item = container.front();
		container.pop_front();
		return item;
	}

	/** Returns the object at the front of the queue
	without removing it.
	@return The object at the front of the queue
	*/
	Item_Type front() {
		return container.front();
	}

	/** Determines whether the queue is empty. */
	bool empty() const {
		return container.empty();
	}
	
	/** Returns the number of items in the queue */
	size_t size() const {
		return container.size();
	}

private:
	list<Item_Type> container;
}; 
