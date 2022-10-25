#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"

/*
	Initialize game object 
*/
CGameObject::CGameObject(float x, float y, LPTEXTURE tex)
{
	this->x = x;
	this->y = y;
	this->texture = tex;
}

void CGameObject::Render()
{
	CGame::GetInstance()->Draw(x, y, texture);
}

CGameObject::~CGameObject()
{
	if (texture != NULL) delete texture;
}

#define MARIO_VX 0.1f
#define MARIO_WIDTH 14
#define MARIO_HEIGHT 14

void CMario::Update(DWORD dt)
{
	x += vx*dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) {
		
		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}
}

bool CBall::isColliding(const CBall& object, const CBall& other)
{
	float left = other.x - (object.x + MARIO_WIDTH);
	float top = (other.y + MARIO_HEIGHT) - object.y;
	float right = (other.x + MARIO_WIDTH) - object.x;
	float bottom = other.y - (object.y + MARIO_HEIGHT);

	return !(left > 0 || right < 0 || top < 0 || bottom > 0);
}

void CBall::Update(DWORD dt)
{
	vx += va * dt;
	vy += va * dt;
	x += vx * dt;
	y += vy * dt;
	
	
	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	int BackBufferHeight = CGame::GetInstance()->GetBackBufferHeight();

	/*if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) {

		va == 0.1f;
	}

	if (y <= 0 || y >= BackBufferHeight - MARIO_HEIGHT) {

		va -= 0.1f;
	}*/
	//va -= .01f;
	//if (va <= 0) { va = 0; }
	//if (vx <= 0) { vx = 0; }
	//if (vy <= 0) { vy = 0; }
	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}
	
	if (y <= 0 || y >= BackBufferHeight - MARIO_HEIGHT) {

		vy = -vy;

		if (y <= 0)
		{
			y = 0;
		}
		else if (y >= BackBufferHeight - MARIO_HEIGHT)
		{
			y = (float)(BackBufferHeight - MARIO_HEIGHT);
		}
	}
}
