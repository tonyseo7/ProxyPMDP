#include "stdafx.h"
#include "PictureManager.h"

void main()
{
	PictureManager *pm = new PictureManager();
	UserList avail_users;
	pm->Login("ȫ�浿");
	pm->MakePicture("ȫ�浿A", avail_users);
	avail_users.push_back("������");
	pm->MakePicture("ȫ�浿B", avail_users);
	pm->MakePicture("ȫ�浿C");
	pm->ListPicture();
	pm->Logout();
	pm->Login("������");
	pm->ListPicture();
	pm->Logout();

	delete pm;
}