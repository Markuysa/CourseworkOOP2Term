#ifndef _cl_base_
#define _cl_base_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class cl_base {
private:
	string obj_name; // Имя объекта
	cl_base* p_head; // Указатель на головной объект
	vector<cl_base*> childes; // Вектор наследников
public:
	cl_base(cl_base* p_head, string name = "root"); // Параметризированный конструктор
	void set_name(string name); // Сеттер имени объекта
	string get_name(); // Геттер имени объекта
	void print_tree(); // Метод для вывода дерева иерархии
	void set_p(cl_base* ptr); // Метод установки указателя на родителя
	cl_base* get_phead() { return this->p_head; }; // Метод для получения указателя на г.объект
};
#endif 


















