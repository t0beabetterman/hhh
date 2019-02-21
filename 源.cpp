#include <iostream>
#include <string>
#include <conio.h>
#include<cstring>
#include<fstream>

using namespace std;
//基类
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
//本科生
class undergraduate :public person {
	friend class list;
	double grade;
public:
	undergraduate(char *name,char *gender,int age,char *num,double grade);
	void print();
	void insert();
	void save();
};
//脱产研究生
class postgraduate_fulltime :public person {
	friend class list;
	char major[20];
public:
	postgraduate_fulltime(char *name, char *gender, int age, char *num, char *major);
	void print();
	void insert();
	void save();
};
//在职研究生
class postgraduate_parttime :public person {
	friend class list;
	float salary;
public:
	postgraduate_parttime(char *name, char *gender, int age, char *num, float salary);
	void print();
	void insert();
	void save();
};
//行政人员
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
//教师
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
//链表
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
	cout << "姓名：" << name << endl;
	cout << "性别：" << gender << endl;
	cout << "年龄：" << age << endl;
	cout << "身份证号码：" << num << endl;
}
void person::save()
{
	myfile.open("d:\\abc.txt",ios::app);
	myfile << endl;
	myfile << "姓名：" << name << endl;
	myfile << "性别：" << gender << endl;
	myfile << "年龄：" << age << endl;
	myfile << "身份证号码：" << num << endl;
	myfile.close();
}
undergraduate::undergraduate(char *name, char *gender, int age, char *num,double grade):person(name,gender,age,num)
{
	undergraduate::grade = grade;
}
void undergraduate::print() {
	person::print();
	cout << "成绩：" << grade << endl;
}
void undergraduate::save() {
	person::save();
	myfile.open("d:\\abc.txt",ios::app);
	myfile << "成绩：" << grade << endl;
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
	cout << "专业：" << major << endl;
}
void postgraduate_fulltime::save() {
	person::save();
	myfile.open("d:\\abc.txt", ios::app);
	myfile << "专业：" << major << endl;
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
	cout << "工资：" << postgraduate_parttime::salary << endl;
}
void postgraduate_parttime::save() {
	person::save();
	myfile.open("d:\\abc.txt", ios::app);
	myfile << "工资：" << postgraduate_parttime::salary << endl;
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
	cout << "岗位：" << staff::job << endl;
	cout << "工资：" << salary << endl;
}
void staff::save() {
	person::save();
	myfile.open("d:\\abc.txt", ios::app);
	myfile<< "岗位：" << staff::job << endl;
	myfile<< "工资：" << salary << endl;
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
	cout << "专业：" << teacher::major << endl;
	cout << "工资：" << salary << endl;
}
void teacher::save() {
	person::save();
	myfile.open("d:\\abc.txt", ios::app);
	myfile << "专业：" << teacher::major << endl;
	myfile << "工资：" << salary << endl;
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
	undergraduate und("杨过","男", 20, "36564789457985564", 88.302);
	postgraduate_fulltime pofu("段誉", "男", 25, "489456486514865", "六脉神剑");
	postgraduate_parttime popa("黄蓉", "女", 24, "489456484648651", 9856);
	staff sta("张无忌", "男", 21, "89784564156", "明教教主", 8754);
	teacher tea("东方不败", "男", 61, "894564896545645", "葵花宝典", 75892);
	people.insert_person(&und);
	people.insert_person(&pofu);
	people.insert_person(&popa);
	people.insert_person(&sta);
	people.insert_person(&tea);
	people.print_list();
	cout << endl<<"以上打印出原链表!输入名字+回车查找指定人物"<<endl;
	char *c;
	c = new char[10];
	cin >> c;
	people.find_name(c);
	cout << endl<<"以上为查找到的对象！输入名字+回车删除指定人物"<<endl;
	cin >> c;
	people.remove(c);
	people.print_list();
	cout <<endl<< "以上为删除后的链表！输入任意键+回车保存文件并关闭窗口！"<<endl;
	
	people.save_list();
	cin >> c;
	return 0;
}