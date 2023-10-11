#pragma once

#include "iostream"
#include "string"

using namespace std;

template<typename Item_Type>
class Single_Linked_List {
	private:
		struct node {
			Item_Type data;
			node* next;

			node(const Item_Type& _data, node* _next = NULL) : data(_data), next(_next) {}
		};
		node* head;
		node* tail;
		int num_items;
	public:
		Single_Linked_List() {
			head = NULL;
			tail = NULL;
			num_items = 0;
		}

		void push_front(const Item_Type& item) {
			head = new node(item, head);
			if (tail == NULL) {
				tail = head;
			}
			num_items++;
		}

		void push_back(const Item_Type& item) {
			if (tail != NULL) {
				tail->next = new node(item);
				tail = tail->next;
			}
			else {
				push_front(item);
				return;
			}
			num_items++;
		}

		void pop_front() {
			if (head == NULL) {
				throw invalid_argument("Attempt to call pop_front() on an empty list");
			}
			node* removed_node = head;
			head = head->next;
			delete removed_node;
			if (head == NULL) {
				tail = NULL;
			}
			num_items--;
		}

		void pop_back() {
			if (tail == NULL) {
				throw invalid_argument("Attempt to call pop_back() on an empty list");
			}
			node* temp = head;
			if (num_items == 1) {
				head = NULL;
				tail = NULL;
				delete temp;
				return;
			}

			//get second to last node
			for (int i = 0; i < num_items - 2; i++) {
				temp = temp->next;
			}
			node* removed_node = temp->next;
			tail = temp;
			delete removed_node;
			num_items--;
		}

		Item_Type& front() {
			return head->data;
		}

		Item_Type& back() {
			return tail->data;
		}

		bool empty() {
			return num_items == 0;
		}

		void insert(size_t index, const Item_Type& item) {
			node* temp = head->next;
			node* prev = head;
			
			if (index == 0 || num_items == 0) {
				push_front(item);
				return;
			}
			
			if (num_items == 1) {
				if (index == 0) push_front(item);
				else push_back(item);
				return;
			}

			for (int i = 1; i < num_items; i++) {
				if (i == index) {
					node* inserted_node = new node(item);
					prev->next = inserted_node;
					inserted_node->next = temp;
					num_items++;
					return;
				}
				prev = temp;
				temp = temp->next;
			}
			cout << "reached push_back() in insert()";
			push_back(item);
		}

		bool remove(size_t index) {
			node* temp = head->next;
			node* prev = head;

			if (index >= num_items) return false;
			if (index == 0) {
				pop_front();
				return true;
			}
			if (index == num_items - 1) {
				pop_back();
				return true;
			}

			//loop over the "middle" values
			for (int i = 1; i < num_items - 1; i++) {
				if (i == index) {
					prev->next = temp->next;
					delete temp;
					num_items--;
					return true;
				}
				prev = temp;
				temp = temp->next;
			}
		}

		size_t find(const Item_Type& item) {
			node* temp = head;
			for (int i = 0; i < num_items; i++) {
				if (temp->data == item) {
					return i;
				}
				temp = temp->next;
			}
			return num_items;
		}

		Item_Type item_at(int index) {
			node* temp = head;
			for (int i = 0; i < num_items; i++) {
				if (i == index) return temp->data;
 				temp = temp->next;
			}
			return NULL;
		}

		int get_num_items() {
			return num_items;
		}
};
