#pragma once

class Drawable;
#include <vector>
using namespace std;
#include "Timer.h"

class Renderer
{
	static Renderer* m_pRenderer;
	int m_windowWidth = 0, m_windowHeight = 0;
	double m_frameDuration = 0.0;
	Timer m_frameTimer;
	vector <Drawable*> m_objects2D;

	void set2DMatrix();
public:
	Renderer();
	~Renderer();

	void initialize(int argc, char** argv);

	void setFrameRate(int framesPerSecond);
	double getFrameDuration() { return m_frameDuration; }

	static Renderer* get(); //this method returns the only instance to the renderer. Needs to be called after the constructor

	void drawScene();
	void addObject(Drawable* pObj);
	void removeObject(Drawable * pObj);
	void reshapeWindow(int x, int y);
	
	static void __drawScene();
	static void __reshapeWindow(int x, int y);
	Drawable* getObject(string name);
};

