#include <iostream>

using namespace std;

struct Node
{
	Node* next;
	int value;
};

Node* create_list() {
	Node* list = new Node;
	Node* top = list;
	
	for (int i = 0, j = 9; i < 10; i++, j--) {
		list->next = new Node;
		list = list->next;
		list->value = i;
		list->next = NULL;
	}

	return top;
}

void output_list(Node* list) {
	//list = list->next;
	cout << list->value << " ";
	if (list->next != NULL)
		output_list(list->next);
}

int occurrences_x(Node* list, int x) {
	int count = 0;
	if (list == NULL)
		return count;
	else
	{
		if (list->value == x)
			count++;
		count += occurrences_x(list->next, x);
		return count;
	}
}

void delete_first_occurrences_x(Node* list, int x) {
	if (list->next != NULL) {
		if (list->next->value == x) {
			Node* temp = list->next;
			list->next = list->next->next;
			delete temp;
		}
		else
			delete_first_occurrences_x(list->next, x);
	}
}

void add_y(Node* list, int x, int y) {
	if (list) {
		if (list->value == x) {
			Node* temp = new Node;
			temp->next = list->next;
			temp->value = y;
			list->next = temp;
		}
		add_y(list->next, x, y);
	}
}

Node* create_copy(Node* list) {
	Node* list_copy = new Node;
	if (list->next != NULL)
		list_copy->next = create_copy(list->next);
	else
		list_copy->next = NULL;
	list_copy->value = list->value;
	return list_copy;
}

bool equal_lists(Node* list1, Node* list2) {
	if (list1->value == list2->value && list1->next && list2->next)
		equal_lists(list1->next, list2->next);
	else return false;

	return true;
}

int max_value(int a, int b) {
	if (a >= b) return  a;
	return b;
}
int max_in_list(Node* list) {  // исправить
	if (list->next == NULL) return list->value;
	else 
		return max_value(list->value, max_in_list(list->next));
}

void output_list_from_the_end(Node* list) {
	if (list->next != NULL)
		output_list_from_the_end(list->next);

	cout << list->value << " ";
}

void delete_list(Node* list) { // вроде работает
	if (list->next != NULL) {
		delete_list(list->next);
		delete list;
	}
}

Node* merging_lists_with_destruction(Node* list1, Node* list2) {
	Node* list3 = NULL;

	if (list1->next != NULL && list2->next != NULL)
	{
		if (list1->value >= list2->value) {
			list3 = list2;
			list3->next = merging_lists_with_destruction(list1, list2->next);
		}
		else {
			list3 = list1;
			list3->next = merging_lists_with_destruction(list1->next, list2);
		}
	}
	return list3;
}

//Node* merging_lists_without_collapsing(Node* list1, Node* list2) {
//
//}
//


int main()
{
	Node* list = new Node;

	list = create_list();

	output_list(list);
	cout << endl << endl;

	cout << "1" << endl;
	int occurrences = occurrences_x(list, 5);
	cout << "Occurrences x = " << occurrences << endl << endl;

	cout << "2" << endl;
	delete_first_occurrences_x(list, 5);
	output_list(list);
	cout << endl << endl;

	cout << "3" << endl;
	add_y(list, 6, 7);
	output_list(list);
	cout << endl << endl;

	cout << "4" << endl;
	Node* list_copy = create_copy(list);
	output_list(list);
	cout << endl;
	output_list(list_copy);
	cout << endl << endl;

	cout << "5" << endl;
	cout << equal_lists(list, list_copy) << endl;
	cout << endl << endl;

	cout << "6" << endl;
	cout << max_in_list(list) << endl;
	cout << endl;

	cout << "7" << endl;
	output_list_from_the_end(list->next);
	cout << endl << endl;

	cout << "8" << endl;
	delete_list(list_copy);
	cout << "delete list" << endl << endl;

	cout << "9" << endl;
	Node* list2 = create_list();
	output_list(list);
	cout << endl;
	output_list(list2);
	cout << endl;
	Node* list3 = merging_lists_with_destruction(list, list2);
	output_list(list3);
	cout << endl;
	output_list(list);
	cout << endl;
	output_list(list2);
	cout << endl;
	delete_list(list3);

	//cout << "10" << endl;

	//Node* list3 = merging_lists_without_collapsing(list, list2);
	//output_list(list3);
	//cout << endl;
	//output_list(list);
	//cout << endl;
	//output_list(list2);
	//cout << endl;
	//delete_list(list3);



	



	cout << "I HATE PROGRAMMING" << endl;
}
