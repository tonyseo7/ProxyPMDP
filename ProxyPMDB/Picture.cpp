#include "stdafx.h"
#include "Picture.h"

Picture::Picture(string name, string owner) : name(name), owner(owner)
{

}

void Picture::View()const
{
	cout << "���ϸ�:" << name << "������:" << owner << endl;
}

string Picture::GetOwner()const
{
	return owner;
}