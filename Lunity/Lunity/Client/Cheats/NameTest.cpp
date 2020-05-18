#include "pch.h"
#include "NameTest.h"

NameTest::NameTest() : Cheat::Cheat("NameTest", "Other")
{
}

void NameTest::onEnable()
{
	/*
	LunMem::getClientInstance()->LocalPlayer->displayLocalizableMessage(new TextHolder("Test!"));
	LunMem::getClientInstance()->LocalPlayer->setName(new TextHolder("Franklin"));
	LunMem::getClientInstance()->LocalPlayer->setNameTagVisible(true);
	*/
	//enabled = false;
}

void NameTest::onPostRender() {

}
