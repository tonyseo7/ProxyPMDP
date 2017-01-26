#include "stdafx.h"
#include "PictureManager.h"

void main()
{
	PictureManager *pm = new PictureManager();
	UserList avail_users;
	pm->Login("È«±æµ¿");
	pm->MakePicture("È«±æµ¿A", avail_users);
	avail_users.push_back("°­°¨Âù");
	pm->MakePicture("È«±æµ¿B", avail_users);
	pm->MakePicture("È«±æµ¿C");
	pm->ListPicture();
	pm->Logout();
	pm->Login("°­°¨Âù");
	pm->ListPicture();
	pm->Logout();

	delete pm;
}