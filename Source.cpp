//MAIN STARTS HERE
#include "Header.h"
#include <fstream>
/*
Student: Bernie Cherlie Melo Chirions
Student ID: 10610272
Date: 04/22/2023
Assigment Title: HW2 - CS003
*/
string removeUnderscore(string title);//This function takes a string argument "title" and returns a modified string with underscores removed.
void searchBook(Book** allBooks, int counter_book_file, int code, string title);//Function to search a Book. 
void rentBook(Book** allBooks, int counter_book_file, Person** allPeople, int counter_people_file, int id, string title);//Function to rent a book
void returningBook(Book** allBooks, int counter_book_file, Person** allPeople, int counter_people_file, int id, string title); // Function to return a book
void showMyinformation(Book** allBooks, int counter_book_file, Person** allPeople, int counter_people_file, int id, string name);// Function to show the person's status in the library
void showAllBooks(Book** allBooks, int counter_book_file);//Function to show all Books status in the library

void searchBook(Book** allBooks, int counter_book_file, int code, string title)
{
	bool code_and_title_do_not_match = true;//boolean variable to throw exceptions when book title and book code do not match
	string str = "";//string variable to remove underscores in the book title

	for (int i = 0; i < counter_book_file; i++)//traversing the array
	{	
		if ((code > 1000 && code <= 2000) && code == allBooks[i]->getCode() && title == allBooks[i]->getTitle())//Searching for Children Books
		{
			code_and_title_do_not_match = false;
			str = removeUnderscore(allBooks[i]->getTitle());//calling function to remove underscore symbol
			cout << "'" << str << "' exists." << endl;
			cout << "Category  : Children Books" << endl;
			cout << "Age       : " << allBooks[i]->getAge() << endl;
			cout << allBooks[i]->getAvailable() << " available, " << allBooks[i]->getRented() << " rented." << endl;;

		}
		else if ((code > 2000 && code <= 3000) && code == allBooks[i]->getCode() && title == allBooks[i]->getTitle())//Searching for Computer Books
		{
			code_and_title_do_not_match = false;
			str = removeUnderscore(allBooks[i]->getTitle());//calling function to remove underscore symbol
			cout << "'" << str << "' exists." << endl;
			cout << "Category  : Computer Books" << endl;
			cout << "Publisher : " << allBooks[i]->getPublisher() << endl;
			cout << allBooks[i]->getAvailable() << " available, " << allBooks[i]->getRented() << " rented." << endl;;

		}
		else if ((code > 3000 && code <= 4000) && code == allBooks[i]->getCode() && title == allBooks[i]->getTitle())//Searching for Novels
		{
			code_and_title_do_not_match = false;
			str = removeUnderscore(allBooks[i]->getTitle());//calling function to remove underscore symbol
			cout << "'" << str << "' exists." << endl;
			cout << "Category       : Novel Books" << endl;
			cout << "Published Date : " << allBooks[i]->getPublish_Date() << endl;
			cout << allBooks[i]->getAvailable() << " available, " << allBooks[i]->getRented() << " rented." << endl;;
		}
	}
	try
	{
		if (code_and_title_do_not_match == true) throw code_and_title_do_not_match;//if code and title do not match throw exception
	}
	catch (bool x) {//catching exception and displaying corresponding message
		cout << endl;
		cout << "Code and Title do not match" << endl;
		cout << endl;
	}
	cout << endl;
}

void rentBook(Book** allBooks, int counter_book_file, Person** allPeople, int counter_people_file, int id, string title)
{
	string option_to_rent = "";//string variable to rent a book, yes or no
	int index = 0;//integer variable to save the index in which the person is located within the array and avoid conflicts further in the code
	bool already_rented_max_amount_of_books = true;// variable to throw exception
	bool teacher = false;//variable to determine if the user is a teacher
	bool student = false;//variable to determine if the user is a student
	int  wrong_id = 1;//if you want to go the extra mile apply exception for wrong id
	int unavailable = 1;// variable to throw exception when book is unavailable

	try {

		if (id > 1 && id <= 100) teacher = true;// determine if the user is a teacher
		else if (id > 100 && id <= 300) student = true;	// determine if the user is a student

		for (int i = 0; i < counter_people_file; i++)//traversing the person array
		{
			if (id == allPeople[i]->getId())
			{
				if ((teacher == true && allPeople[i]->getCount() == 3) || (student == true && allPeople[i]->getCount() == 2)) throw already_rented_max_amount_of_books;//throw exception if maximum limit is reached
				cout << endl;					
				index = i;//Saving the index in which the person is located within the array
				for (int book_counter = 0; book_counter < counter_book_file; book_counter++)//traversing the book array
				{
					if (title == allBooks[book_counter]->getTitle())//finding the book title in the array
					{
						if (allBooks[book_counter]->getAvailable() == 0) throw unavailable;//if not available throw exception
						cout << "You are " << allPeople[i]->gettName() << ". You have rented " << allPeople[i]->getCount() << " book. " << endl;
						cout << "Do you want to rent '" << allBooks[book_counter]->getTitle() << "' (y/n)? : ";
						cin >> option_to_rent;
						if (option_to_rent == "y" || "Y")//if statement to ask fior user decision
						{
							allBooks[book_counter]->setAvailable(allBooks[book_counter]->getAvailable() - 1);//availability is reduced by one
							allBooks[book_counter]->setRented(allBooks[book_counter]->getRented() + 1);//amount of rente books increase by one
							
							if (student == true)//checking if the person is a student
							{	//Block of code to insert the code book in the register of the person							
								allPeople[i]->setCodeStudent(allPeople[i]->getCodeStudent(), allPeople[i]->getCount(), allBooks[book_counter]->getCode());//arguments are array ,  index, and book code
							}
							else if (teacher == true)//checking if the person is a teacher
							{    //Block of code to insert the code book in the register of the teacher
								allPeople[i]->setCodeTeacher(allPeople[i]->getCodeTeacher(), allPeople[i]->getCount(), allBooks[book_counter]->getCode());
							}
							allPeople[index]->setCount(allPeople[index]->getCount() + 1);//this value is change after we used it as the index for inserting the code book, order matters.
							cout << "***** Rent succeed!!. Check your info!" << endl << endl;
						}
					}
				}
			}
		}
	}
	//catching statements per situation
	catch (bool y)// execute after the line: throw already_rented_max_amount_of_books 
	{
		if (student == true)//if the person is a student this message appears
		{	
			cout << "You are a student and have rented the maximum limit, which is two books." << endl;
			cout << "Select option 3 below to return a book first" << endl;

		}
		else if (teacher == true)//if the person is a teacher this message appears
		{
			cout << "You are a teacher and have rented the maximum limit, which is three books." << endl;
			cout << "Select option 3 below to return a book first" << endl;
		}
	}
	catch (int x)// catching from the line : throw unavailable and display corresponding message
	{
		
		cout << "Sorry, there are not more books availables with this title" << endl;
		cout << "Try with another title" << endl;
	}
}

//Function to return a book
void returningBook(Book** allBooks, int counter_book_file, Person** allPeople, int counter_people_file, int id, string title) {

	string option_to_rent = "";//string variable to rent a book, yes or no
	int index = 0;//integer variable to save the index of a person in the array allPeople
	bool already_rented_max_amount_of_books = true;//boolean to determine the maximum amount of books rented
	bool teacher = false;//boolean to determine if a person is a teacher
	bool student = false;//boolean to determine if a person is a student
	char  wrong_id = 1;//if you want to go the extra mile apply exception for wrong id
	int unavailable = 1;//value to trhow exception when a book is unavailable
	string wrond_id_teacher = "1";////value to trhow exception when a teacher has the wrong id
	bool no_books = true;//boolean to determine when there are no books 

	try {//try all this code and throw exception in respective cases
		if (id > 1 && id <= 100) teacher = true;//checking if the id belongs to a teacher
		else if (id > 100 && id <= 300) student = true;	//checking if the id belongs to a student	

		for (int i = 0; i < counter_people_file; i++)//traversing the person array
		{
			if (id == allPeople[i]->getId())//chekcing if id coincides with any person in the array
			{
				if (allPeople[i]->getCount() == 0) throw no_books;//if the person has no rented books then throw exception				
				index = i;//saving the index to avoid conflicts in following comparisons
				for (int book_counter = 0; book_counter < counter_book_file; book_counter++)
				{
					if (title == allBooks[book_counter]->getTitle())//finding the book title in the array
					{	
						if (student == true)//determining if the user is a student or a professor
						{							
							for (int book_codes = 0; book_codes < allPeople[i]->getCount(); book_codes++)
							{
								//comparing codes in the Book array with the books the array of books of the person
								if (allPeople[i]->getCodeStudent()[book_codes] == allBooks[book_counter]->getCode())
								{									
									wrong_id = 0;//exception is avoided if the person has inserted the right code book									
								}
							}							
							if (wrong_id == 1)
							{
								throw wrong_id;//trowing exception if the code was not found in the array of books from the person
							}
						}
						else if (teacher == true)
						{	
							//Checking if the book is in possesion of the teacher trying to return the book
							for (int book_codes = 0; book_codes < allPeople[i]->getCount(); book_codes++)
							{
								//checking if the person has rented the book;
								if (allPeople[i]->getCodeTeacher()[book_codes] == allBooks[book_counter]->getCode())
								{
									//The person has rented this book , exception avoided
									wrond_id_teacher = "0";
								}
							}							
							if (wrond_id_teacher == "1")
							{
								throw wrond_id_teacher;////The person has not rented this book , throwing exception 
							}
						}
						//Asking the user if wants to return the book
						cout << endl;
						cout << "Do you want to return  '" << allBooks[book_counter]->getTitle() << "' (y/n)? : ";
						cin >> option_to_rent;//captuiring the user decision

						if (option_to_rent == "y" || "Y")//Checking if positive to continue renting process
						{
							allBooks[book_counter]->setAvailable(allBooks[book_counter]->getAvailable() + 1);//when returning a book the availability of the book is increased by one
							allBooks[book_counter]->setRented(allBooks[book_counter]->getRented() - 1);//when returning a book the amount of rented books decrease by one							
							
							int amount_of_books_before_returning = allPeople[index]->getCount();
							allPeople[index]->setCount(allPeople[index]->getCount() - 1);//this value is change after we used it as the index for inserting the code book, order matters.
							cout << "***** Returning succeed!!. Check your info!" << endl;
							
							if (student == true)//checking if the user is a student
							{
								cout << endl;
								//Deleting the code book from the student register
								for (int book_codes = 0; book_codes < allPeople[index]->getCount(); book_codes++)
								{
									if (allPeople[i]->getCodeStudent()[book_codes] == allBooks[book_counter]->getCode())
									{										
										allPeople[i]->getCodeStudent()[book_codes] = NULL;
									}
								}
								//Rearranging code books in the array of books from the student
								int temp = 0;//temporal value for swaping book codes
								for (int book_codes_i = 0; book_codes_i < allPeople[index]->getCount(); book_codes_i++)
								{
									for (int book_codes_j = book_codes_i + 1; book_codes_j < 2; book_codes_j++)
									{
										if (allPeople[i]->getCodeStudent()[book_codes_i] == NULL)
										{
											allPeople[i]->getCodeStudent()[book_codes_i] = allPeople[i]->getCodeStudent()[book_codes_j];//Rearranging code books doing a swap
											allPeople[i]->getCodeStudent()[book_codes_j] = NULL;
										}
									}
								}	
							}
							else if (teacher == true)//checking if the user is a teacher
							{								
								cout << endl;	
								//Deleting the code book from the teacher register
								for (int book_codes = 0; book_codes < allPeople[index]->getCount(); book_codes++)
								{
									if (allPeople[i]->getCodeTeacher()[book_codes] == allBooks[book_counter]->getCode())
									{										
										allPeople[i]->getCodeTeacher()[book_codes] = NULL;
									}
								}
								//Rearranging code books in the array of books from the teacher
								int temp = 0;//temporal value for swaping book codes
								for (int book_codes_i = 0; book_codes_i < allPeople[index]->getCount(); book_codes_i++)
								{
									for (int book_codes_j = book_codes_i + 1; book_codes_j < 3; book_codes_j++)
									{
										if (allPeople[i]->getCodeTeacher()[book_codes_i] == NULL)
										{
											allPeople[i]->getCodeTeacher()[book_codes_i] = allPeople[i]->getCodeTeacher()[book_codes_j];//Rearranging code books doing a swap
											allPeople[i]->getCodeTeacher()[book_codes_j] = NULL;
										}
									}
								}								
							}
						}
					}
				}
			}
		}
	}
	//catching statements per situation
	catch (bool t) 
	{
		cout << "Sorry, you have not rented a single book" << endl;
		cout << "Try renting one first with option (2) below." << endl;
	}	
	catch (char y)
	{

		cout << "Sorry, you did not rent this book" << endl;
		cout << "Try with another title" << endl;
	}

	catch (string z)
	{

		cout << "Sorry, you did not rent this book" << endl;
		cout << "Try with another title" << endl;
	}
}

//Function to show information of the user
void showMyinformation(Book** allBooks, int counter_book_file, Person** allPeople, int counter_people_file, int id, string name)

{	//Checking if the code belongs to a student or  a teacher
	bool teacher = false;//boolean to check if the user is a teacher
	bool student = false;//boolean to check if the user is a student
	int code = 0;//variable to store book code temporraily

	// check if the user is a student or a teacher
	if (id > 1 && id <= 100) teacher = true;
	else if (id > 100 && id <= 300) student = true;

	if (student == true)//checking if the person is a student
	{
		for (int i = 0; i < counter_people_file; i++)
		{
			if (allPeople[i]->gettName() == name && allPeople[i]->getId() == id)
			{
				cout << "You rented " << allPeople[i]->getCount() << " book(s)." << endl;
				for (int code_book_counter_person = 0; code_book_counter_person < allPeople[i]->getCount(); code_book_counter_person++)
				{
					//searching array of books of the student
					for (int code_book_counter = 0; code_book_counter < counter_book_file; code_book_counter++)
					{
						//Comparing the books from the array of the student with the array of books	and displaying book information							
						if (allPeople[i]->getCodeStudent()[code_book_counter_person] == allBooks[code_book_counter]->getCode())
						{														
							if (allBooks[code_book_counter]->getCode() > 1000 && allBooks[code_book_counter]->getCode() <= 2000)//Children Books
							{
								cout << "* " << allBooks[code_book_counter]->getTitle() << " (" << allBooks[code_book_counter]->getCode() << ") "
									<< "- Age : " << allBooks[code_book_counter]->getAge() << endl;
							}
							else if (allBooks[code_book_counter]->getCode() > 2000 && allBooks[code_book_counter]->getCode() <= 3000)//Computer Books
							{
								cout << "* " << allBooks[code_book_counter]->getTitle() << " (" << allBooks[code_book_counter]->getCode() << ") "
									<< "- Publisher : " << allBooks[code_book_counter]->getPublisher() << endl;
							}
							else if (allBooks[code_book_counter]->getCode() > 3000 && allBooks[code_book_counter]->getCode() <= 4000)//Novel Books

							{
								cout << "* " << allBooks[code_book_counter]->getTitle() << " (" << allBooks[code_book_counter]->getCode() << ") "
									<< "- Published Date : " << allBooks[code_book_counter]->getPublish_Date() << endl;
							}
						}
					}
				}
			}
		}
	}
	else  if (teacher == true)//check if the person is a teacher
	{
		for (int i = 0; i < counter_people_file; i++)
		{
			if (allPeople[i]->gettName() == name && allPeople[i]->getId() == id)
			{
				cout << "You rented " << allPeople[i]->getCount() << " book(s)." << endl;
				for (int code_book_counter_person = 0; code_book_counter_person < allPeople[i]->getCount(); code_book_counter_person++)
				{
					//searching array of books of the teacher
					for (int code_book_counter = 0; code_book_counter < counter_book_file; code_book_counter++)//array of books of the student
					{
						//Comparing the books from the array of the student with the array of books	and displaying book information				
						if (allPeople[i]->getCodeTeacher()[code_book_counter_person] == allBooks[code_book_counter]->getCode())
						{    //checking what kind of book was found and displaying information
							if (allBooks[code_book_counter]->getCode() > 1000 && allBooks[code_book_counter]->getCode() <= 2000)//Children Books
							{
								cout << "* " << allBooks[code_book_counter]->getTitle() << " (" << allBooks[code_book_counter]->getCode() << ") "
									<< "- Age : " << allBooks[code_book_counter]->getAge() << endl;
							}
							else if (allBooks[code_book_counter]->getCode() > 2000 && allBooks[code_book_counter]->getCode() <= 3000)//Computer Books
							{
								cout << "* " << allBooks[code_book_counter]->getTitle() << " (" << allBooks[code_book_counter]->getCode() << ") "
									<< "- Publisher : " << allBooks[code_book_counter]->getPublisher() << endl;
							}
							else if (allBooks[code_book_counter]->getCode() > 3000 && allBooks[code_book_counter]->getCode() <= 4000)//Novel Books
							{
								cout << "* " << allBooks[code_book_counter]->getTitle() << " (" << allBooks[code_book_counter]->getCode() << ") "
									<< "- Published Date : " << allBooks[code_book_counter]->getPublish_Date() << endl;
							}

						}
					}
				}
			}
		}
	}
}

//Function to remove underscore symbol
string removeUnderscore(string title)
{
	string str = title;//string variable to save the book title
	char underscore = '_';//char variable to save the underscore symbol
	char space = ' ';//char variable to save the space
	replace(str.begin(), str.end(), underscore, space);//removing the underscore from the beginning to the end of the string
	return str;

}

void showAllBooks(Book** allBooks, int counter_book_file)
{
	//setting columns width to show book information
	int col1 = 10;
	int col2 = 30;
	int col3 = 20;
	int col4 = 12;
	int col5 = 5;
	string refined_title = "";//initializing string variable to replace the underscores from the title with spaces
	//Displaying information using the columns configured above per every kind of book
	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "                                 Children Books                                " << endl;
	cout << "===============================================================================" << endl;
	cout << setw(col1) << left << "Code"
		<< setw(col2) << left << "Title"
		<< setw(col3) << "Age"
		<< setw(col4) << left << "Available"
		<< setw(col5) << left << "Rented" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < counter_book_file; i++)
	{
		if (allBooks[i]->getCode() > 1000 && allBooks[i]->getCode() <= 2000)//Children Books
		{	//displaying book information
			refined_title = removeUnderscore(allBooks[i]->getTitle());//removing underscores from title
			cout << setw(col1) << left << allBooks[i]->getCode()
				<< setw(col2) << left << refined_title
				<< setw(col3) << left << allBooks[i]->getAge()
				<< setw(col4) << left << allBooks[i]->getAvailable()
				<< setw(col5) << left << allBooks[i]->getRented() << endl;
		}
	}
	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "                                 Computer Books                                " << endl;
	cout << "===============================================================================" << endl;
	cout << setw(col1) << left << "Code"
		<< setw(col2) << left << "Title"
		<< setw(col3) << "Publisher"
		<< setw(col4) << left << "Available"
		<< setw(col5) << left << "Rented" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < counter_book_file; i++)
	{
		if (allBooks[i]->getCode() > 2000 && allBooks[i]->getCode() <= 3000)//Computer Books
		{   //displaying book information
			refined_title = removeUnderscore(allBooks[i]->getTitle());//removing underscores from title
			cout << setw(col1) << left << allBooks[i]->getCode()
				<< setw(col2) << left << refined_title
				<< setw(col3) << left << allBooks[i]->getPublisher()
				<< setw(col4) << left << allBooks[i]->getAvailable()
				<< setw(col5) << left << allBooks[i]->getRented() << endl;
		}
	}
	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "                                  Novel  Books                                 " << endl;
	cout << "===============================================================================" << endl;
	cout << setw(col1) << left << "Code"
		<< setw(col2) << left << "Title"
		<< setw(col3) << "Published Date"
		<< setw(col4) << left << "Available"
		<< setw(col5) << left << "Rented" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < counter_book_file; i++)
	{    //displaying book information
		if (allBooks[i]->getCode() > 3000 && allBooks[i]->getCode() <= 4000)//Novel Books
		{
			refined_title = removeUnderscore(allBooks[i]->getTitle());//removing underscores from title
			cout << setw(col1) << left << allBooks[i]->getCode()
				<< setw(col2) << left << refined_title
				<< setw(col3) << left << allBooks[i]->getPublish_Date()
				<< setw(col4) << left << allBooks[i]->getAvailable()
				<< setw(col5) << left << allBooks[i]->getRented() << endl;
		}
	}
	cout << endl;
}

int main() {

	int code = 0;             //integer variable to store temporarily the book code when reading the file
	string title = "";        //string variable to store temporarily  the book title when reading the file
	int age = 0;              //integer variable to store temporarily the  recommended age of a book  when reading the file
	string publisher = "";    //string variable to store temporarily  the publisher of a book  when reading the file
	int published_date = 0;   //integer variable to store temporarily the published date of a book when reading the file
	int available = 0;        //integer variable  to store temporarily how many available of a specific title are in the library when reading the file
	int rent = 0;			 //integer variable  to store temporarily how many units of a specific title are currently rented when reading the file
	int counter = 0;         //counter to figure out the how many books or people are registered in the file to create a dynamic array of pointers 
	int counter_book_file = 0;//counter to figure out the how many books are registered in the file to create a dynamic array of pointers ***DELETING 
	ifstream inFile;		 //C++ class used to open a file for reading 
	inFile.open("book.txt");//Opening the file
	if (inFile.fail()) {//If opening fails prompt the user
		cout << "Input file opening failed.\n";
		exit(1);
	}
	while (!inFile.eof()) {//reading the file until the end
		inFile >> code;
		if (code > 1000 && code <= 2000)//filtering books per code
		{
			inFile >> title >> age >> available >> rent;//moving the pointer to the next line
		}
		else if (code > 2000 && code <= 3000)//filtering books per code
		{
			inFile >> title >> publisher >> available >> rent;//moving the pointer to the next line
		}
		else//filtering the rest of books per code
		{
			inFile >> title >> published_date >> available >> rent;	//moving the pointer to the next line	
		}
		counter++;//counting how many books are registered in the file
		counter_book_file++;//counting how books people are registered in the file *****DELETING  
	}
	inFile.close();//closing the file	
	
	Book** allBooks = new Book * [counter];//creating dynamic array of pointers  to store Book data per index
	counter = 0;//resetting the counter
	inFile.open("book.txt");//opening book file again to inert the data in the dynamic array
	if (inFile.fail()) {//if opening fails prompt the user
		cout << "Input file opening failed.\n";
		exit(1);
	}
	while (!inFile.eof()) {//read the file until the end
		inFile >> code;
		if (code > 1000 && code <= 2000)//Children Books
		{
			inFile >> title >> age >> available >> rent;
			allBooks[counter] = new ChildrenBook(code, title, available, rent, age);//Creating instance of object ChildrenBook			
			counter++;
		}
		else if (code > 2000 && code <= 3000)//Computer Books
		{
			inFile >> title >> publisher >> available >> rent;
			allBooks[counter] = new ComputerBook(code, title, publisher, available, rent);//Creating instance of object ComputerBook
			counter++;
		}
		else
		{
			inFile >> title >> published_date >> available >> rent;//Novel Books			
			allBooks[counter] = new Novel(code, title, available, rent, published_date);//Creating instance of object Novel
			counter++;
		}

	}
	inFile.close();//closing the file

	int id = 0;                     //integer variable to store temporarily the student or teacher code when reading the file
	string name = "";               //string variable to store temporarily the student or teacher's name when reading the file  
	int number_of_books_rented = 0; //integer variable to store temporarily the amount of books of  currently rented by a person
	int codes_of_rented_books = 0;  //integer variable to store temporarily the code of books currently rented by a person
	counter = 0;                    //resetting the counter to now count people
	inFile.open("person.txt");      //opening the person file
	if (inFile.fail()) {            //checkig person file for errors
		cout << "Input file opening failed.\n";
		exit(1);
	}
	while (!inFile.eof()) {//reading file until the end
		inFile >> id;//reading people ID
		if (id > 0 && id <= 100)//Filtering Teachers per ID
		{
			inFile >> name >> number_of_books_rented;//reading the line			
			counter++;//counting the line
		}
		else if (id > 100 && id <= 300)//Filtering Students per ID
		{

			inFile >> name >> number_of_books_rented;//reading the line			
			counter++;//counting the line
		}
	}
	inFile.close();//closing the file

	int counter_people_file = counter;//variable dedicated to counter total of people for the sake of avoiding conflict
	Person** allPeople = new Person * [counter];//creating dynamic array of people
	counter = 0;//resetting the counter to insert data to follow the index when inserting data in the dynamic array

	inFile.open("person.txt");//opening the person file again
	//cout << "File opened?" << endl;
	if (inFile.fail()) {//checking if failed, if so, prompt the user
		cout << "Input file opening failed.\n";
		exit(1);
	}
	while (!inFile.eof()) {//reading the file until the end
		inFile >> id;		
		if (id > 0 && id <= 100)//filtering ID  by Teachers
		{
			inFile >> name >> number_of_books_rented;//reading the line			
			int* array_codes_of_rented_books = new int[number_of_books_rented];//creating a dynamic array of books to hold book codes in the person array
			for (int i = 0; i < number_of_books_rented; i++)
			{				
				inFile >> codes_of_rented_books;				
				array_codes_of_rented_books[i] = codes_of_rented_books;//inserting codes in the dynamic array of book codes
			}			
			allPeople[counter] = new Teacher(id, name, number_of_books_rented, array_codes_of_rented_books);//creating instance of a teacher and assigning initial values			
			counter++;
		}
		else if (id > 100 && id <= 300)//filtering ID by Students
		{
			inFile >> name >> number_of_books_rented;//reading the line
			int* array_codes_of_rented_books = new int[number_of_books_rented];	//creating a dynamic array of books to hold book codes in the person array	

			for (int i = 0; i < number_of_books_rented; i++)
			{				
				inFile >> codes_of_rented_books;				
				array_codes_of_rented_books[i] = codes_of_rented_books;//inserting codes in the dynamic array of book codes
			}
			allPeople[counter] = new Student(id, name, number_of_books_rented, array_codes_of_rented_books);//creating instance of a student and assigning initial values		
			counter++;
		}

	}
	inFile.close();	//closing the file

	int option = 1;//default option is one to enter the while loop
	while (option > 0 || option <= 6) {
		cout << endl;
		cout << "---------------------------" << endl;
		cout << "            Menu           " << endl;
		cout << "---------------------------" << endl;

		cout << "1. Search a Book" << endl;
		cout << "2. Rent a Book" << endl;
		cout << "3. Return a Book" << endl;
		cout << "4. Show my information" << endl;
		cout << "5. Show all books" << endl;
		cout << "6. Exit" << endl;
		cout << endl;
		cout << "Select (1 ~ 6) : ";
		cin >> option;//waiting for the user input

		if (option < 1 || option > 6) {

			cout << "Invalid choice. Please enter a number between 1 and 6.---" << endl;
		}
		switch (option) {
		case 1:
			// Code for searching a book
			cout << "Enter code : ";
			cin >> code;
			cout << "Enter title : ";
			cin >> title;
			searchBook(allBooks, counter_book_file, code, title);//calling function to search books
			break;
		case 2:
			// Code for renting a book
			cout << "Enter your ID  : ";
			cin >> id;
			cout << "Enter book title : ";
			cin >> title;
			rentBook(allBooks, counter_book_file, allPeople, counter_people_file, id, title);//calling function to rent books
			break;
		case 3:
			// Code for returning a book
			cout << "Enter your ID  : ";
			cin >> id;
			cout << "Enter book title : ";
			cin >> title;
			returningBook(allBooks, counter_book_file, allPeople, counter_people_file, id, title);//calling function to return books
			break;
		case 4:
			// Code for showing user information
			cout << "Enter your ID  : ";
			cin >> id;
			cout << "Enter your name : ";
			cin >> name;
			showMyinformation(allBooks, counter_book_file, allPeople, counter_people_file, id, name);//calling function to show information of a student or teacher
			break;
		case 5:
			// Code for showing all books
			showAllBooks(allBooks, counter_book_file);//callinng function to show all books
			break;
		case 6:
			exit(1);//exit 
			break;
			//default				
		}
	}
	//freeing memory
	delete[] allBooks;
	delete[] allPeople;
	return 0;
}