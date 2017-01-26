#include "stdafx.h"
#include "Protection.h"


ProtectionPicture::ProtectionPicture(string name, string owner)
{
	picture = new Picture(name, owner);
	user = "";
}

ProtectionPicture::~ProtectionPicture(void)
{
	delete picture;
}

void ProtectionPicture::View()const
{
	if (IsAvailableUser(user))
	{
		picture->View();
	}
	else
	{
		cout << "사진을 볼 수 있는 권한이 없습니다." << endl;
	}
}

string ProtectionPicture::GetOwner()const
{
	return picture->GetOwner();
}

void ProtectionPicture::AddAvailableUser(string owner, string user)
{
	if (owner != GetOwner())
	{
		cout << "소유자만이 사용 권한 설정을 할 수 있습니다." << endl;
		return;
	}

	if (IsAvailableUser(user) == false)
	{
		available_users.push_back(user);
	}
}

void ProtectionPicture::SetUser(string user)
{
	this->user = user;
}

bool ProtectionPicture::IsAvailableUser(string user)const
{
	if (picture->GetOwner() == user)
	{
		return true;
	}

	UIter seek = available_users.begin();
	UIter end = available_users.end();

	for (; seek != end; ++seek)
	{
		if ((*seek) == user)
		{
			return true;
		}
	}

	return false;

}
