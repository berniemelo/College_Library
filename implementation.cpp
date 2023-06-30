
//IMPLEMENTATION STARTS HERE
/*
Student: Bernie Cherlie Melo Chirions
Student ID: 10610272
Date: 04/22/2023
Assigment Title: HW2 - CS003
*/
#include "Header.h"

Book::Book() : code(0), title(""), available(0), rented(0) {}//Default constructor definition
Book::Book(int code, string title, int available, int rented) : code(code), title(title), available(available), rented(rented) {}//parameterized constructor definition

/*GETTERS DEFINITION*/
int Book::getCode()
{
	return code;
}
string Book::getTitle()
{
	return title;
}
int Book::getAvailable()
{
	return available;
}
int Book::getRented()
{
	return rented;
}
/*SETTERS DEFINITION*/
void Book::setCode(int code)
{
	this->code = code;
}
void Book::setTitle(string title)
{
	this->title = title;
}
void Book::setAvailable(int available)
{
	this->available = available;
}
void Book::setRented(int rented)
{
	this->rented = rented;
}

//CHILDRENBOOK CONSTRUCTOR
ChildrenBook::ChildrenBook() : Book(0, "", 0, 0), age(0) {}//default constructor definition
ChildrenBook::ChildrenBook(int code, string title, int available, int rented, int age) : Book(code, title, available, rented), age(age) {}//parameterized constructor definition

//Setters and Getters definition from ChildrenBook
int ChildrenBook::getAge()
{
	return age;
}
void ChildrenBook::setAge(int age)
{
	this->age = age;
}
//End of Setters and Getters definition from ChildrenBook


//COMPUTERBOOK CONSTRUCTOR
ComputerBook::ComputerBook() :Book(0, "", 0, 0), publisher("") {}//default constructor definition
ComputerBook::ComputerBook(int code, string title, string publisher, int available, int rented) : Book(code, title, available, rented), publisher(publisher) {}//parameterized constructor definition

//Setters and Getters definition from ComputerBook
string  ComputerBook::getPublisher()
{
	return publisher;
}
void  ComputerBook::setPublisher(string publisher)
{
	this->publisher = publisher;
}
//End of Setters and Getters definition from ComputerBook

//NOVEL CONSTRUCTOR
Novel::Novel() : Book(0, "", 0, 0), publish_date(0) {}//default constructor definition
Novel::Novel(int code, string title, int available, int rented, int publish_date) : Book(code, title, available, rented), publish_date(publish_date) {}//parameterized constructor definition


//Setters and Getters definition from Novel
int Novel::getPublish_Date()
{
	return publish_date;
}
void Novel::setPublish_Date(int date)
{
	this->publish_date = publish_date;
}
//End of Setters and Getters definition from Novel
//----------------------------------------------------PERSON-------------------------------------------------//
Person::Person() : id(0), name(""), count(0) {}//default constructor definition
Person::Person(int id, string name, int count) : id(id), name(name), count(count) {}//parameterized constructor definition
/*PERSON GETTERS DEFINITION*/
int Person::getId()
{
	return id;
}
string Person::gettName()
{
	return name;
}
int Person::getCount()
{
	return count;
}
/*PERSON SETTERS DEFINITION*/
void Person::setId(int id)
{
	this->id = id;
}
void Person::setName(string name)
{
	this->name = name;
}
void Person::setCount(int count)
{
	this->count = count;
}

//STUDENT CONSTRUCTOR
Student::Student() : Person(0, "", 0) {//default constructor definition
	for (int i = 0; i < 2; i++)
	{
		this->code[i] = 0;
	}
}
Student::Student(int id, string name, int count, int* code) : Person(id, name, count)//parameterized constructor definition
{
	//cout << "Student constructor called" << endl;
	for (int i = 0; i < count; i++)
	{
		this->code[i] = code[i];
	}
}
//getters and setter definition for this child class//
int* Student::getCodeStudent()
{
	return this->code;

}
void Student::setCodeStudent(int* code, int index, int book_code)
{
	this->code[index] = book_code;
}

//TEACHER CONSTRUCTOR
Teacher::Teacher() : Person(0, "", 0)//default constructor definition
{
	for (int i = 0; i < 3; i++)
	{
		this->code[i] = 0;
	}
}
Teacher::Teacher(int id, string name, int count, int* code) : Person(id, name, count)//parameterized constructor definition
{
	//cout << "Teacher constructor called" << endl;
	for (int i = 0; i < count; i++)
	{
		this->code[i] = code[i];
	}
}
//getters and setter definition for this child class//
int* Teacher::getCodeTeacher()
{
	return this->code;
}
void Teacher::setCodeTeacher(int* code, int index, int book_code)
{
	this->code[index] = book_code;

}