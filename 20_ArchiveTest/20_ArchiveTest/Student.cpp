#include "stdafx.h"
#include "Student.h"

Student::Student(int id, CString name, int age, int score)
{
	this->m_id = id;
	this->m_name = name;
	this->m_age = age;
	this->m_score = score;
}

Student::~Student()
{
}
