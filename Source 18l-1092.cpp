#include <iostream>
#include"Header.h"
using namespace std;
student::student()//default constructr
{
	counter++;
	ID=counter;
	quizCapacity=3;
	GPA=-1;
	quizScore=new float[quizCapacity];
	for(int i=0;i<quizCapacity;i++)
		quizScore[i]=0;
	quizTaken=0;
	cout<<endl<<endl<<"COnstructor invoked for "<<ID<<endl<<endl;

}
student::student(int cap,float gp)//parmetrized constructor
{
	counter++;
	ID=counter;
	quizCapacity=cap;
	GPA=gp;
	quizTaken=0;
	quizScore=new float[quizCapacity];
	for(int i=0;i<quizCapacity;i++)
		quizScore[i]=0;
	cout<<endl<<endl<<"COnstructor 2 invoked for "<<ID<<endl<<endl;
}
student::student(const student &a)//copy constructor
{
	ID=a.ID;
	quizCapacity=a.quizCapacity;
	quizTaken=a.quizTaken;
	quizScore=new float[quizCapacity];
	for(int i=0;i<quizTaken;i++)
	{
		quizScore[i]=a.quizScore[i];
	}
	GPA=a.GPA;

	cout<<endl<<endl<<"Copy constructor invoked for "<<ID<<endl<<endl;
}
void student::addQuizScore(float a)//add quizz numbers
{
	if(quizTaken<quizCapacity)
	{
		quizScore[quizTaken]=a;
		quizTaken++;
	}
	else
		cout<<"No space to add new quizz"<<endl;
}
student::~student()//destructor
{
	delete [] quizScore;
	

}
void student:: setGPA(float gp)//setter for gpa
{
	GPA=gp;
}
float student :: getGPA() const//getter for gpa
{
	return GPA;
}
void student:: print() const//print function for all objects
{
	cout<<"THe id of student is : "<<ID<<endl;
	cout<<"The GPA of student is : "<<GPA<<endl;
	cout<<"Quizz Taken are : "<<quizTaken<<endl;
	for(int i=0;i<quizTaken;i++)
	{
		cout<<"Quizz "<<i+1<<"score is "<<quizScore[i]<<endl;
	}
}
bool student:: compare(student a)//compare two students
{
	if(GPA>a.GPA)
	{
		return 1;
	}
	else
		return 0;
}
void student ::updateScore(int score, int no)//update the score of quizz
{
	
	if(quizScore[no]!=0 && no<=quizTaken)
	quizScore[no]=score;	
	else 
	cout<<"NO quizz taken"<<endl;
}
void student:: sort(student *p ,int size)//sort the students according to gpa ,student with higher gpa will come first
{
	student *temp3;
	temp3=new student[size];//three times constructor invoked
	for(int i=0;i<p[i].quizCapacity;i++)
		temp3[i].quizScore=new float[p[i].quizTaken];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(p[j].GPA<p[j+1].GPA)
				{
					temp3[j]=p[j];
			
			for(int k=0;k<p[j].quizTaken;k++)
				temp3[j].quizScore[k]=p[i].quizScore[k];
			p[j]=p[j+1];
			for(int k=0;k<p[i].quizTaken;k++)
				p[j].quizScore[k]=p[j+1].quizScore[k];
			p[j+1]=temp3[j];
			for(int k=0;k<p[j].quizTaken;k++)
				p[j+1].quizScore[k]=temp3[j].quizScore[k];
				}

		}


	}
	
		
	
	
}
student *student::greate(student *p,int &size)//return array of students with gpa greater then 2.00
{
	student *temp2;
	int co=0;
	for(int i=0;i<size;i++)
	{
		if(p[i]. GPA > 2.00)
			co++;
	}
	
	temp2=new student[co];//construcor incoked two times as is forming an array of two
	for(int i=0,j=0;i<size;i++)
	{
		if(p[i]. GPA>2.00)
		{
			temp2[j].GPA=p[i].GPA;
			temp2[j].ID=p[i].ID;
			temp2[j].quizCapacity=p[i].quizCapacity;
			temp2[j].quizTaken=p[i].quizTaken;
			temp2[j].quizScore=new float[temp2[j].quizCapacity];
			for(int k=0;k<p[i].quizTaken;k++)
				temp2[j].quizScore[k]=p[i].quizScore[k];
			j++;

		}
	}
	size=co;
	return temp2;
}
int student::counter=0;