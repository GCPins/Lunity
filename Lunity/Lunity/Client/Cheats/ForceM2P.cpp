#pragma once
#include "pch.h"
#include "ForceM2P.h"
#include "../../SDK/EntList.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

ForceM2P::ForceM2P() : Cheat::Cheat("ForceM2P", "Other") {

}

int offset = 0x298;
int LROffset = 0x774;
void ForceM2P::onKey(ulong key) {
	if (key == 'L') {
		offset += 0x4;
	}
	if (key == 'K') {
		offset -= 0x4;
	}
	Logger::logHex("MOffset", offset);
	if (key == 'P') {
		LROffset += 0x4;
	}
	if (key == 'O') {
		LROffset -= 0x4;
	}
	Vector3 origin = LunMem::getClientInstance()->LevelRenderer->OriginA;
	Vector3 pos = Vector3(2, 4, 2);
	Vector3 subbed = pos.sub(origin);
	Logger::logHex("LROffset", LROffset);
	Logger::log("Subbed X" + to_string(subbed.x));
	Logger::log("Subbed Y" + to_string(subbed.y));
	Logger::log("Subbed Z" + to_string(subbed.z));
}

Matrix* generateMatrix() {
	ClientInstance* ci = LunMem::getClientInstance();
	GuiData* gd = ci->getGuiData();

	//Calc projection matrix
	float nearP = 0;
	float aspect = gd->Resolution.x / gd->Resolution.y;
	float fovy = ci->fovY;
	glm::mat4 projection = glm::infinitePerspective(fovy, aspect, nearP);


	//Calc view matrix
	LocalPlayer* lp = ci->LocalPlayer;
	LevelRenderer* lr = ci->LevelRenderer;
	glm::mat4 rotate_x = glm::rotate(glm::mat4(), lp->LookingVec.x, glm::vec3(1.0f, 0.0f, 0.0f)); //rotate around x
	glm::mat4 rotate_y = glm::rotate(glm::mat4(), lp->LookingVec.y, glm::vec3(0.0f, 1.0f, 0.0f)); //rotate around y
	glm::mat4 rotate_z = glm::rotate(glm::mat4(), 0.0f, glm::vec3(0.0f, 0.0f, 1.0f)); //rotate around z

	glm::mat4 translate = glm::translate(glm::mat4(), lr->OriginA.toGlmVec()); //make translation matrix

	glm::mat4 model = translate * rotate_z * rotate_y * rotate_x; //here will be stored the model matrix for camera, mult in this order!

	glm::mat4 view = glm::inverse(model); //unoptimalized for cpu but ez to implement in your hack

	//Calc view projection matrix
	glm::mat4 viewprojection = projection * view;
	Matrix* lunViewProjMatrix = (Matrix*)&viewprojection;
	return lunViewProjMatrix;
}

void ForceM2P::onPostRender() {
	if (enabled) {
		Vector2 coordsH;
		Vector2 coordsG;
		Vector2 coordsL;
		GuiData* gd = DrawUtils::getGuiData();
		Vector2 res = gd->Resolution;
		uintptr_t clientInstancePtr = (uintptr_t)LunMem::getClientInstance();//LunMem::getClientInstance()->MinecraftGame->GameRenderer;
		Vector3 origin = LunMem::getClientInstance()->LevelRenderer->OriginA;//(Vector3*)(((uintptr_t)LunMem::getClientInstance()->LevelRenderer) + LROffset);
		Vector2 fov = Vector2(LunMem::getClientInstance()->fovX, LunMem::getClientInstance()->fovY);
		Matrix* possibleMatrix = ((Matrix*)(clientInstancePtr + offset))->correct();
		Matrix* generatedMatrix = generateMatrix();
		vector<Actor*>* acts = getEntities();
		for (int i = 0; i < acts->size(); i++) {
			Actor* currentEnt = acts->at(i);
			possibleMatrix->DirtyWorldToScreen(origin, currentEnt->Pos, coordsH, fov, res);
			possibleMatrix->DirtyWorldToScreenGH(currentEnt->Pos, coordsG, res.x, res.y);
			//possibleMatrix->DirtyWorldToScreenGHFOV(origin, currentEnt->Pos, coordsL, fov , res);
			//DrawUtils::DirtyWorldToScreen(Vector3(0, 5, 0), coords, possibleMatrix, res.x, res.y);
			coordsG = Vector2(coordsG.x / 2, coordsG.y / 2);
			coordsH = Vector2(coordsH.x / 2, coordsH.y / 2);
			//coordsL = Vector2(coordsL.x / 2, coordsL.y / 2);
			//DrawUtils::WorldToScreen(Vector3(0, 5, 0), coords);
			DrawUtils::drawText(coordsH, &string("H"), nullptr, 1);
			DrawUtils::drawText(coordsG, &string("G"), nullptr, 1);
			//DrawUtils::drawText(coordsL, &string("L"), nullptr, 1);
		}

		/*Logger::log("X: " + to_string(coords.x));
		Logger::log("Y: " + to_string(coords.y));*/
		/*if (KeyHook::KeyState('P')) {
			offset += 0x4;
		}
		if (KeyHook::KeyState('O')) {
			offset -= 0x4;
		}*/
	}
}