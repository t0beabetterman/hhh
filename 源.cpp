#include <iostream>
#include <string>
#include <conio.h>
#include<cstring>
#include<fstream>

using namespace std;
//����
class person {
	friend class list;
	
protected:
    char name[20];
	char gender[20];
	int age;
	char num[20];
	static person *ptr;
	person *next;
	
	ofstream myfile;
public:
	person(char *name, char *gender, int age, char *num);
		virtual void print();
		virtual void save();
		virtual void insert() {};
		
};
//������
class undergraduate :public person {
	friend class list;
	double grade;
public:
	undergraduate(char *name,char *gender,int age,char *num,double grade);
	void print();
	void insert();
	void save();
};
//�Ѳ��о���
class postgraduate_fulltime :public person {
	friend class list;
	char major[20];
public:
	postgraduate_fulltime(char *name, char *gender, int age, char *num, char *major);
	void print();
	void insert();
	void save();
};
//��ְ�о���
class postgraduate_parttime :public person {
	friend class list;
	float salary;
public:
	postgraduate_parttime(char *name, char *gender, int age, char *num, float salary);
	void print();
	void insert();
	void save();
};
//������Ա
class staff :public person {
	friend class list;
	char job[20];
	float salary;
public:
	staff(char *name, char *gender, int age, char *num, char *job,float salary);
	void print();
	void insert();
	void save();
};
//��ʦ
class teacher :public person {
	friend class list;
	char major[20];
	float salary;
public:
	teacher(char *name, char *gender, int age, char *num, char *major, float salary);
	void print();
	void insert();
	void save();
};
//����
class list {
	person *root;
public:
	list() { root = 0; }
	void insert_person(person *node);
	void find_name(char *name);
	void remove(char *name);
	void print_list();
	void save_list();
};
person::person(char *name, char *gender, int age, char *num)
{
	strcpy_s(person::name, name);
	strcpy_s(person::gender, gender);
	person::age = age;
	strcpy_s(person::num, num);
	next = 0;
}
void person::print()
{
	cout << endl;
	cout << "������" << name << endl;
	cout << "�Ա�" << gender << endl;
	cout << "���䣺" << age << endl;
	cout << "���֤���룺" << num << endl;
}
void person::save()
{
	myfile.open("d:\\abc.txt",ios::app);
	myfile << endl;
	myfile << "������" << name << endl;
	myfile << "�Ա�" << gender << endl;
	myfile << "���䣺" << age << endl;
	myfile << "���֤���룺" << num << endl;
	myfile.close();
}
undergraduate::undergraduate(char *name, char *gender, int age, char *num,double grade):person(name,gender,age,num)
{
	undergraduate::grade = grade;
}
void undergraduate::print() {
	person::print();
	cout << "�ɼ���" << grade << endl;
}
void undergraduate::save() {
	person::save();
	myfile.open("d:\\abc.txt",ios::app);
	myfile << "�ɼ���" << grade << endl;
	myfile.close();
}
void undergraduate::insert()
{
	ptr = new undergraduate(name,gender,age,num,grade);
}

postgraduate_fulltime::postgraduate_fulltime(char *name, char *gender, int age, char *num, char *major) :person(name, gender, age, num)
{
	strcpy_s(postgraduate_fulltime::major , major);
}
void postgraduate_fulltime::print() {
	person::print();
	cout << "רҵ��" << major << endl;
}
void postgraduate_fulltime::save() {
	person::save();
	myfile.open("d:\\abc.txt", ios::app);
	myfile << "רҵ��" << major << endl;
	myfile.close();
}
void postgraduate_fulltime::insert()
{
	ptr = new postgraduate_fulltime(name, gender, age, num, major);
}

postgraduate_parttime::postgraduate_parttime(char *name, char *gender, int age, char *num, float salary) :person(name, gender, age, num)
{
	postgraduate_parttime::salary = salary;
}
void postgraduate_parttime::print() {
	person::print();
	cout << "���ʣ�" << postgraduate_parttime::salary << endl;
}
void postgraduate_parttime::save() {
	person::save();
	myfile.open("d:\\abc.txt", ios::app);
	myfile << "���ʣ�" << postgraduate_parttime::salary << endl;
	myfile.close();
}
void postgraduate_parttime::insert()
{
	ptr = new postgraduate_parttime(name, gender, age, num, salary);
}

staff::staff(char *name, char *gender, int age, char *num, char *job,float salary) :person(name, gender, age, num)
{
	strcpy_s(staff::job,job);
	staff::salary = salary;
}
void staff::print() {
	person::print();
	cout << "��λ��" << staff::job << endl;
	cout << "���ʣ�" << salary << endl;
}
void staff::save() {
	person::save();
	myfile.open("d:\\abc.txt", ios::app);
	myfile<< "��λ��" << staff::job << endl;
	myfile<< "���ʣ�" << salary << endl;
	myfile.close();
}
void staff::insert()
{
	ptr = new staff(name, gender, age, num, job,salary);
}

teacher::teacher(char *name, char *gender, int age, char *num, char *major,float salary) :person(name, gender, age, num)
{
	strcpy_s(teacher::major,major);
	teacher::salary = salary;
}
void teacher::print() {
	person::print();
	cout << "רҵ��" << teacher::major << endl;
	cout << "���ʣ�" << salary << endl;
}
void teacher::save() {
	person::save();
	myfile.open("d:\\abc.txt", ios::app);
	myfile << "רҵ��" << teacher::major << endl;
	myfile << "���ʣ�" << salary << endl;
	myfile.close();
}
void teacher::insert()
{
	ptr = new teacher(name, gender, age, num, major,salary);
}

void list::insert_person(person *node) {
	char key[20];
	strcpy_s(key, node->name);
	person *curr_node = root;
	person *previous = 0;
	while (curr_node != 0 && strcmp(curr_node->name, key) < 0) {
		previous = curr_node;
		curr_node = curr_node->next;
	}
	node->insert();
	node->ptr->next = curr_node;
	if (previous == 0)
		root = node->ptr;
	else  previous->next = node->ptr;
}

void list::find_name(char *name) {
	person *curr_node = root;
	while (curr_node != 0 && strcmp(curr_node->name, name) != 0)
	{
		curr_node = curr_node->next;
	}
	curr_node->print();
}

void list::remove(char *name) {
	person *curr_node = root;
	person *previous = 0;
	while (curr_node != 0 && strcmp(curr_node->name, name) != 0)
	{
		previous = curr_node;
		curr_node = curr_node->next;
	}
	if (previous == 0)
	{
		root = curr_node->next;
		delete curr_node;
	}
	else {previous->next = curr_node->next;
	delete curr_node;
}
}

void list::print_list() {
	person *node = root;
	while (node!= 0) {
		node->print();
		node = node->next;
	}
}
void list::save_list() {
	person *node = root;
	while (node != 0) {
		node->save();
		node = node->next;
	}
}
person *person::ptr = 0;

int main() {
	
	list people;
	undergraduate und("���","��", 20, "36564789457985564", 88.302);
	postgraduate_fulltime pofu("����", "��", 25, "489456486514865", "������");
	postgraduate_parttime popa("����", "Ů", 24, "489456484648651", 9856);
	staff sta("���޼�", "��", 21, "89784564156", "���̽���", 8754);
	teacher tea("��������", "��", 61, "894564896545645", "��������", 75892);
	people.insert_person(&und);
	people.insert_person(&pofu);
	people.insert_person(&popa);
	people.insert_person(&sta);
	people.insert_person(&tea);
	people.print_list();
	cout << endl<<"���ϴ�ӡ��ԭ����!��������+�س�����ָ������"<<endl;
	char *c;
	c = new char[10];
	cin >> c;
	people.find_name(c);
	cout << endl<<"����Ϊ���ҵ��Ķ�����������+�س�ɾ��ָ������"<<endl;
	cin >> c;
	people.remove(c);
	people.print_list();
	cout <<endl<< "����Ϊɾ������������������+�س������ļ����رմ��ڣ�"<<endl;
	
	people.save_list();
	cin >> c;
	return 0;
}