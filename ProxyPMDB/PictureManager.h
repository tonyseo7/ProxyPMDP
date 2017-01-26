#pragma once
#include "Protection.h"
typedef vector<IView *> Pictures;

class PictureManager
{
	Pictures pictures;
	string login_user;

public:
	PictureManager(void);
	~PictureManager(void);
	void Login(string user);
	void MakePicture(string name, UserList available_users);
	void MakePicture(string name);
	void ListPicture();
	void Logout();

private:
	ProtectionPicture *MakeProtectionPicture(string name, UserList available_users);
};
