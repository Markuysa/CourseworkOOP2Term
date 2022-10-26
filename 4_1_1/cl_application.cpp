#include "cl_application.h"
#include "cl_branch.h"
void application::build_Tree() {
	string name_of_p, name_of_ch; // Вводимые имена 
	int temp, j = 0;
	cin >> name_of_p;
	this->set_name(name_of_p);
	cl_base* head = this, * br = nullptr; // Создание головного объекта
	cin >> name_of_p >> name_of_ch >> temp;
	while (name_of_p != name_of_ch) {
		j++;
		cin >> name_of_ch >> temp;
		if (name_of_p == head->get_name()) // Если имя вводимого объекта-родителя совпадает с именем текущего head
			head = head;
		else if (name_of_p == br->get_name()) { //Если имя вводимого объекта-родителя совпадает с именем созанного потомока
			head = br;
		}
		else
			head = this; // Указатель на текущий объект 
		br = new cl_branch(head, name_of_ch);
		cin >> name_of_p >> name_of_ch >> temp;
	}

}
int application::executeApp() {
	//cout << this->get_name() << endl; // Вывод иимени обхекта-root
	this->print_tree(); // Вызов метода для вывода дерева иерархии
	return 0;

}























