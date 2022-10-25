#pragma once

#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#define MARIO_WIDTH 14

class CBrick : public CGameObject {
public: 
	CBrick(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
};

//class CBrick2 : public CGameObject {
//public:
//	CBrick2(float x, float y) : CGameObject(x, y) {}
//	void Render();
//	void Update(DWORD dt) {}
//};

class CMario : public CGameObject
{
protected:
	float vx;
public:
	CMario(float x, float y, float vx);
	void Update(DWORD dt);
	void Render();
};

class CBird : public CGameObject
{
protected:
	float vx;
public:
	CBird(float x, float y, float vx);
	void Update(DWORD dt);
	void Render();
};

