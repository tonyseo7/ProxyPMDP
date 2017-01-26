#pragma once
#include "common.h"

class IView
{
public:
	virtual void View()const = 0;
	virtual string GetOwner()const = 0;
};
