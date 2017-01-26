#pragma once
#include "common.h"
#include "IView.h"

class Picture :public IView
{
	const string name;
	const string owner;

public:
	Picture(string name, string owner);
	virtual void View()const;
	virtual string GetOwner()const;
};
