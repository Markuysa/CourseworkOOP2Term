#include "cl_base.h"
#include "cl_base.h"
cl_base::cl_base(cl_base* p_head, string name) {
	this->obj_name = name; // Присваивание имени объекту
	if (p_head) { // Если не nullptr
		this->p_head = p_head;
		set_p(p_head);
	}
}
void cl_base::set_p(cl_base* ptr) {
	int size = p_head->childes.size(); // Размер массива наследников текущего гол.объекта
	for (int i = 0; i < size; i++) // Проход по всем потомкам родительского объекта и удаление объекта, который перестал подчиняться родительскому
	{
		if (p_head->childes[i] == this)
		{
			p_head->childes.erase(p_head->childes.begin() + i);
			break;
		}
	}
	p_head->childes.push_back(this); //Добавление указателя на текущий объект
	this->p_head = p_head;
}
void cl_base::set_name(string name) {
	this->obj_name = name; // Установка имени объекта
}
string cl_base::get_name() {
	return obj_name; // Возврат имени объекта
}

void cl_base::print_tree() {
	cout << this->get_name() << "  ";
	for (int i = 0; i < childes.size(); i++)
		if (i == childes.size() - 1)
			cout << childes[i]->get_name();
		else
			cout << childes[i]->get_name() << "  ";
	for (int j = 0; j < childes.size(); j++) {
		if (this->childes[j]->childes.size() != 0) {     // Форматирование вывода
			cout << endl;
			this->childes[j]->print_tree();
		}
	}
}