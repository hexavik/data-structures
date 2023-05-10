/**
 * @file singlyLinkedList.cpp
 * 
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @brief 
 * This program is the impplementation of the singly linked list using C++.
 * Following are the algorithm steps to understand the flow of the methods.
 * 
 * Insertion
 * 1. Create a new node by assigning the value from the argument
 * 2. Check whether the head node is empty (or the list is empty or not)
 * 3. If the head node is empty then assign the new node to the head node 
 * 	  and return
 * 4. If the head node is not empty then create a temp node and assign 
 *    the head node to it
 * 5. While temp node's next is not empty, assign the temp node's next to 
 *    the temp node till it reaches to the edn of the list
 * 6. Once the temp node's next is null then get out of the loop and 
 *    assign the new node to the temp node's next
 * 
 * Deletion at the end
 * 1. Check if the linked list is empty to return as empty list
 * 2. Check if the head node is the single node present in the list to 
 *    make the list empty by assigning null pointer to the head node
 * 3. Create a temp node and assign the head node to it as a start of 
 *    the list
 * 4. Create a null node to record the previous node of the last node
 * 5. Reach till the end of the list by recording the last node before 
 *    assigning the next node to the temp node's next
 * 6. Delete the temp node and assign null pointer to the previous node's 
 *    next
 * 
 * Deletion at the specific location
 * 1. Check if the linked list is empty to return as empty list
 * 2. Check whether offset value is 0
 * 3. If offset value is 0 and the head is the only node present in the list 
 *    then empty the list by assigning null pointer to head
 * 4. If offset value is 0 and the head is not the only node present then 
 *    make the next node as the head node and delete the head node
 * 5. If offset value is not 0 then proceed further by creating a temp node 
 *    and assign head to it
 * 6. Create a node to record the previous node
 * 7. Create a variable to stroe the count of the visited nodes
 * 8. Loop through the while loop by assigning temp node to the previous 
 *    node and replacing the temp node to the next node
 * 9. If the count variable and offset matches then break the loop so that 
 *    temp node is pointing to the node that needs to be deleted
 * 10. If the offset value is greater than the count of the list which 
 *     denotes the length of the list then return the error
 * 11. Point the previous node's next to the temp node's next to link 
 *     between the nodes
 * 12. Delete the temp node which is pointing to the node that needs to be 
 *     deleted
 * 
 * Display
 * 1. Check if the head node is null to display the empty status of 
 *    the linked list
 * 2. If head is not null then create a temp node and assign the head 
 *    node to it
 * 3. Display the value of the temp node and assign the next node to it, 
 *    while tmep node is node is not null
 * 
 */

#include <iostream>

//#define DEBUG

// Create a node structure
struct Node {
	int data;
	Node * next;

	// Constructors
	Node() {}
	Node(int value) : data(value), next(nullptr) {}
};

// Create a class of LinkedList
class LinkedList {
private:
	Node * head = nullptr;
public:
	// Constructor
	LinkedList() {}

	// Insert a new node at the end of the linked list
	void insert(int );
	// Remove a node from the end of the linked list
	void remove();
	// Remove a node from the specified loction of the linked list
	void remove_at(int );
	// Display the value of all the nodes of the linked list
	void display();
};

/**
 * @brief Insert a node at the head of the linked list
 * 
 * @param value New node value
 */
void LinkedList::insert(int value) {
	// Create a new node
	Node * newNode = new Node{value};

	// Check the linked list's empty status
	if (!head) {
		// Since head is empty, assign the new node as the head
		head = newNode;
		return;
	}

	// Create a temp node and assign head to it
	auto tempNode = head;
	// If the temp node next is not null then the move to the next node
	// Repeat till the temp node is null (till end of the list)
	while (tempNode->next) {
		tempNode = tempNode->next;
	}

	// Assign the new node to the temp node's next
	tempNode->next = newNode;
}

/**
 * @brief Remove the node from the end of the linked list
 * 
 */
void LinkedList::remove() {
	// Check the linked list's empty status
	if (!head) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	// Check if the head node is the only node present in the list 
	// to make the list empty
	if (!head->next) {
		this->head = nullptr;
		return;
	}

	// Create a temp node and assign head to it as a start node
	auto tempNode = head;
	// Create a node to record the previous node
	Node * prevNode = nullptr;

	// Reach till the end of the linked list
	while (tempNode->next) {
		prevNode = tempNode;
		tempNode = tempNode->next;
	}

	// Remove the node
	delete tempNode;
	// Assign the null pointer to the previous node's next
	prevNode->next = nullptr;
}

/**
 * @brief Remove the node from the list at the specified location
 * 
 * @param offset 
 */
void LinkedList::remove_at(int offset) {
	// Check the linked list's empty status
	if (!head) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	// Check whether the offset is pointing to the head
	if (offset == 0) {
		// Check if the head node is the only node present in the list 
		// to make the list empty
		if (!head->next) {
			this->head = nullptr;
			return;
		}
	
		// Change the head of the list to the next node of the head
		// and delete it
		auto oldHead = head;
		head = head->next;
		delete oldHead;
		return;
	}

	// Create a temp node and assign head to it as a start of the list
	auto tempNode = head;
	// A node to record the previous node
	Node * prevNode = nullptr;
	// Incremental variable to count the visited nodes in the list
	int count = 0;

	// Loop through the list while checking the node count is equal 
	// to the offset value to break the loop
	while (tempNode->next) {
		prevNode = tempNode;
		tempNode = tempNode->next;

		if (++count == offset) {
			break;
		}
	}

	// Return if the offset value is greater than the length of the
	// list
	if (offset > count) {
		std::cout << "The offset value is not in the linked list's length" << std::endl;
		return;
	}
	
	// Assign the value of the previous node to the next node
	prevNode->next = tempNode->next;
	// Remove the node
	delete tempNode;
}

/**
 * @brief Display the value of all available nodes of the linked list
 * 
 */
void LinkedList::display() {
	// Check the linked list's empty status
	if (!head) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	// Create a temp node and assign head to it as a start node
	auto tempNode = head;

	// Reach till the end of the linked list
	while (tempNode) {
		std::cout << tempNode->data << " ";
		tempNode = tempNode->next;
	}
}

int main(void) {
	// Create an empty Linked List
	LinkedList list;

	// Insert nodes inside the list
	list.insert(10);
	list.insert(23);
	list.insert(12);
	list.insert(67);
	list.insert(56);

	// Remove nodes from the list
	list.remove();

	list.display();

	list.remove_at(4);

	// Display the list
	list.display();

	return 0;
}
