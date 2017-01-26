#include "stdafx.h"
#include "PictureManager.h"
typedef vector<IView *>::const_iterator PIter;

PictureManager::PictureManager(void)
{
	login_user = "";
}

PictureManager::~PictureManager(void)
{
	PIter seek = pictures.begin();
	PIter end = pictures.end();

	IView *iview = 0;

	for (; seek != end; ++seek)
	{
		iview = *seek;
		delete iview;
	}
}

void PictureManager::Login(string user)
{
	login_user = user;
	cout << login_user << "님께서 로긴 하셨습니다." << endl;
}

void PictureManager::MakePicture(string name)
{
	if (login_user != "")
	{
		IView *iview = new Picture(name, login_user);
		pictures.push_back(iview);
	}
}

void PictureManager::MakePicture(string name, UserList available_users)
{
	if (login_user != "")
	{
		ProtectionPicture *pro_picture = MakeProtectionPicture(name, available_users);
		pictures.push_back(pro_picture);
	}
}

void PictureManager::ListPicture()
{
	PIter seek = pictures.begin();
	PIter end = pictures.end();
	IView *iview = 0;
	ProtectionPicture *pro_picture = 0;

	for(; seek != end; ++seek)
	{
		iview = *seek;
		pro_picture = dynamic_cast<ProtectionPicture *>(iview);
			
		if (pro_picture)
		{
			pro_picture->SetUser(login_user);
		}

		iview->View();
	}
}

void PictureManager::Logout()
{
	cout << login_user << "님께서 로그 아웃 하였습니다." << endl;
	login_user = "";
}

ProtectionPicture *PictureManager::MakeProtectionPicture(string name, UserList available_users)
{
	ProtectionPicture *pro_picture = new ProtectionPicture(name, login_user);
	UIter seek = available_users.begin();
	UIter end = available_users.end();

	for (; seek != end; ++seek)
	{
		pro_picture->AddAvailableUser(login_user, *seek);
	}

	return pro_picture;
}