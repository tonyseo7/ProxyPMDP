#include "stdafx.h"
#include "Picture.h"

Picture::Picture(string name, string owner) : name(name), owner(owner)
{

}

void Picture::View()const
{
	cout << "파일명:" << name << "소유자:" << owner << endl;
}

string Picture::GetOwner()const
{
	return owner;
}