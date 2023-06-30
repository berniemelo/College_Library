//HEADER STARTS HERE

/*
Student: Bernie Cherlie Melo Chirions
Student ID: 10610272
Date: 04/22/2023
Assigment Title: HW2 - CS003
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

class Book//creating class of books
{	
private:          //members are private
	int code;     //integer variable to store code books
	string title; //string variable to store book titles
	int available;//integer variable to store how many available books are
	int rented;  //integer variable to store how many books of a specific title have been rented
public:
	Book();//Default constructor declaration 
	Book(int code, string title, int available, int rented);//parameterized constructor declaration 
	virtual void basefunction() = 0;//virtual function to create an abstract class
	//Getters and setter declaration of private members are below
	int getCode();
	string getTitle();
	int getAvailable();
	int getRented();
	void setCode(int code);
	void setTitle(string title);
	void setAvailable(int available);
	void setRented(int rented);
	//Setter and getters below are = 0; and removed from the implementation so this are only declared in the derived classes
	//Setters and Getters from ChildrenBook
	virtual int getAge() = 0;
	virtual void setAge(int age) = 0;
	//End of Setters and Getters from ChildrenBook

	//Setters and Getters from ComputerBook
	virtual string getPublisher() = 0;
	virtual void setPublisher(string publisher) = 0;
	//End of Setters and Getters from ChildrenBook

	//Setters and Getters from Novel
	virtual int getPublish_Date() = 0;
	virtual void setPublish_Date(int date) = 0;
	//End of Setters and Getters from Novel
};

class ChildrenBook : public Book //creating child class of ChildrenBooks 
{	
private://members are private
	int age;//integer variable to indicate the recommended age of the reader
public:
	ChildrenBook();//default constructor declaration
	ChildrenBook(int code, string title, int available, int rented, int age);//parameterized constructor declaration	
	/*getters and setter declaration for this child class*/
	int getAge();
	void setAge(int age);
	virtual void basefunction() {}//added from the parent class to avoid being abstract

	//Including method from other classes to avoid error
	virtual string getPublisher()
	{
		return "";
	}
	virtual void setPublisher(string publisher) {}
	virtual int getPublish_Date() {
		return 0;
	}
	virtual void setPublish_Date(int date) {}
};

class ComputerBook : public Book  //creating child class of Computer books 
{	
private://members are private
	string publisher;
public:
	ComputerBook();//default constructor declaration
	ComputerBook(int code, string title, string publisher, int available, int rented);//parameterized constructor declaration	
	/*getters and setter declaration for this child class*/
	string getPublisher();
	void setPublisher(string publisher);
	virtual void basefunction() {}//added from the parent class to avoid being abstract
	
	//Including method from other classes to avoid error
	virtual int getAge() { return 0; }
	virtual void setAge(int age) {}
	//End of Setters and Getters from ChildrenBook	
	//Setters and Getters from Novel
	virtual int getPublish_Date() { return 0; }
	virtual void setPublish_Date(int date) {}
	//End of Setters and Getters from Novel
};

class Novel : public Book  //creating child class of Novel books 
{	
private://members are private
	int publish_date;//integer variable to hold the year in which the book was published
public:
	Novel();//Default constructor declaration  
	Novel(int code, string title, int available, int rented, int date);//parameterized constructor declaration  	
	/*getters and setter declaration for this child class*/
	int getPublish_Date();
	void setPublish_Date(int date);
	virtual void basefunction() {}//added from the parent class to avoid being abstract

	//Including method from other classes to avoid error
	//Setters and Getters from ChildrenBook
	virtual int getAge() { return 0; }
	virtual void setAge(int age) {}
	//End of Setters and Getters from ChildrenBook

	//Setters and Getters from ComputerBook
	virtual string getPublisher() { return ""; }
	virtual void setPublisher(string publisher) {}
	//End of Setters and Getters from ChildrenBook
}; 
//-------------------------------------------------PERSON CLASS-------------------------------------------------//
class Person
{	
private:
	int id;//integer variable to store the id of the person
	string name;//string variable to store the name of the person
	int count;//integer variable to store 
public:
	Person();//Default constructor declaration
	Person(int id, string name, int count);//parameterized constructor declaration
	//Getters and setter declaration of this class
	int getId();
	string gettName();
	int getCount();
	void setId(int id);
	void setName(string name);
	void setCount(int count);

	virtual void basefunction() = 0;
	//Setters and Getters from Student Class
	virtual int* getCodeStudent() = 0;
	virtual void setCodeStudent(int* code, int index, int book_code) = 0;
	//End of Setters and Getters from Student Class
	//Setters and Getters from Teacher Class
	virtual int* getCodeTeacher() = 0;
	virtual void setCodeTeacher(int* code, int index, int book_code) = 0;
	//End of Setters and Getters from Teacher Class
};

class Student : public Person
{
private:
	int code[2];
public:
	Student();//Default constructor declaration
	Student(int id, string name, int count, int* code);//parameterized constructor declaration	
	/*getters and setter declaration for this child class*/
	int* getCodeStudent();
	void setCodeStudent(int* code, int index, int book_code);

	//getters and setter to avoid abstraction
	virtual int* getCodeTeacher()
	{
		return nullptr;
	}
	virtual void setCodeTeacher(int* code, int index, int book_code) {}
	virtual void basefunction() {}//overrinding from parent class
};

class Teacher : public Person
{	
private:
	int code[3];
public:
	Teacher();//Default constructor declaration
	Teacher(int id, string name, int count, int* code);//parameterized constructor declaration	
	/*getters and setter declaration for this child class*/
	int* getCodeTeacher();
	void setCodeTeacher(int* code, int index, int book_code);

	//getters and setter to avoid abstraction
	virtual int* getCodeStudent()
	{
		return nullptr;
	}
	virtual void setCodeStudent(int* code, int index, int book_code) {}
	virtual void basefunction() {}
};