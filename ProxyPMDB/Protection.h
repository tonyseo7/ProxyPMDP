#pragma once
#include "Picture.h"
typedef vector<string>::const_iterator UIter;
typedef vector<string> UserList;

class ProtectionPicture : public IView
{
	Picture *picture;
	UserList available_users;
	string user;

public:
	ProtectionPicture(string name, string owner);
	~ProtectionPicture(void);
	virtual void View()const;
	virtual string GetOwner()const;
	void AddAvailableUser(string owner, string user);
	void SetUser(string user);

private:
	bool IsAvailableUser(string user)const;
};
