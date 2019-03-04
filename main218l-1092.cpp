#include <iostream>
#include"header.h"
using namespace std;
int main()
{
	student s[3]={student (3,2),student (3,3),student(4,2.3)};//parmeterized constructor called for 3 objects id 1,id 2,id 3
	s[0].addQuizScore(1);
	s[0].addQuizScore(4);
	s[0].addQuizScore(10);
	s[1].addQuizScore(10);
	s[1].addQuizScore(4);
	s[1].addQuizScore(9);
	s[2].addQuizScore(9);
	s[2].addQuizScore(8);
	s[2].addQuizScore(7);
	
	student **arr =new student*[4];
	arr[0]=new student(3,2);//parmeterized constructor called for  object id 4 as new object is forming
	arr[1]=new student(3,3);//parmeterized constructor called for  object id 5 as new object is forming
	arr[2]=new student(4,2.33);//parmeterized constructor called for  object id 6 as new object is forming
	arr[3]=new student (4,1);//parmeterized constructor called for  object id 7 as new object is forming

	arr[0]->addQuizScore(1);
	arr[0]->addQuizScore(4);
	arr[0]->addQuizScore(10);
	arr[1]->addQuizScore(10);
	arr[1]->addQuizScore(4);
	arr[1]->addQuizScore(9);
	arr[2]->addQuizScore(9);
	arr[2]->addQuizScore(8);
	arr[2]->addQuizScore(7);
	arr[3]->addQuizScore(2);
	arr[3]->addQuizScore(3);
		cout<<endl<<"                    Array of dynamic members is this "<<endl;
	for(int i=0;i<4;i++)
		{
			arr[i]->print();
			cout<<endl;
		}
		cout<<endl<<"					 Array of simple members are this "<<endl;
	for(int i=0;i<3;i++)
		{
			s[i].print();
			cout<<endl;
		}
	//Greater gpa function for non dynamic array
	student s1;//default constructor invoked for id 8 as new object is forming
	student *temp;
	int size=3;
	temp=s1.greate(s,size);//default constructor invoked for temp having id 9 and on returning 10 as in function an array of objects is formed
		cout<<"                    After the Check of GPA new array is "<<endl;
	for(int i=0;i<size;i++)
		{
			temp[i].print();
			cout<<endl;
		}
	//Am not doing this work on dynamic array as you have said in class to leave it
	cout<<endl<<"                  After sorting the array is"<<endl<<endl;
	s1.sort(s,3);//sorting function
				//default constructor is invoked thrre times in this function
	for(int i=0;i<3;i++)
		{
			s[i].print();
			cout<<endl;
		}
	return 0;
}
//DEstructor invoked for id 8



//DEstructor invoked for id 1



//DEstructor invoked for id 3



//DEstructor invoked for id 2