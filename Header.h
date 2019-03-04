#include <iostream>
using namespace std;
class student
{
private:
	
	static int counter; //to keep track of fumber of students and assign ID to new students
	int ID; 
	// each student will have unique ID. 1st student object created will have ID=1,
	//2nd student 2 and so on. ID will only be assigned in constructor and cannot be changed 
	float *quizScore; //array to keep score of quizzes
	int quizCapacity; // capacity of quizScore Array
	int quizTaken; // number of quizzes taken, cannot be greater than capacity
	float GPA;  

public:
	student(); 
	//default constructor, the defaut quizCapacity is 3 and default GPA is. 
	student(int,float);
	/* This constructor will take quizCapacity and GPA as args and set 
	 the values for the student being created*/
	student(const student &);
	/* copy constructor will copy all the variables (even ID). 
	The dynamic memory has to explicity deep copied*/
	~student(); 
	// Destructor will deallocate the dynamically allocated memory

	void addQuizScore(float);
	/* This function will add a quiz if the array iss not full. 
	If there is no capacity a messsage will be printed */
	void setGPA(float);
	// This function will set the GPA of student
	float getGPA() const; 
	// This function will return the GPA of student
	void print() const; 
	/* This function will print the information of student incl. 
	ID, GPA, quizzes taken and score of each quiz*/
	bool compare(student);
	/* This function will take another student by value and arg, 
	if the GPA of this student is > other student it will return true else false*/
	void updateScore(int, int); 
	/* This function takes quiz number and new score as input 
	and updates the score of that quiz, only of the quiz was taken*/
	void sort(student *s ,int);//sort the array of objects
student * greate(student *s,int &);//return araay of objecxts that have gpa >2.0
};
	