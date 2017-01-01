﻿#include "Skybox.h"

namespace game
{
	void Skybox::initialize()
	{
		
		if (!nightsky_texture_.loadImage("Milkyway_Skybox.jpg"))
			ofLog(OF_LOG_ERROR, "Error while loading Nightsky Texture");

		air_scatter_mesh_ = air_scatter_mesh_.box(190, 190, 190, 1, 1, 1);
	}

	void Skybox::draw(float timeOfDay)
	{
		glEnable(GL_TEXTURE_2D);

		glColor3f(1, 1, 1);

		glScalef(10, 10, 10);

		glRotatef(timeOfDay * 360, 0, 0, 1);

		glPushMatrix();
		
		nightsky_texture_.getTextureReference().bind();

		//Orientate the Garactic Background correctly
		glRotatef(90, 0, 0, 1);
		glRotatef(90, 1, 0, 0);

		//Draw Galactic Background
		glBegin(GL_QUADS);
		// front face
		glTexCoord2f(0.333f, 0.333f); glVertex3f(-200, 200, 200);
		glTexCoord2f(0.0f, 0.333f); glVertex3f(200, 200, 200);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(200, -200, 200);
		glTexCoord2f(0.333f, 0.0f); glVertex3f(-200, -200, 200);
		// right face
		glTexCoord2f(0.333f, 0.333f); glVertex3f(-200, 200, 200);
		glTexCoord2f(0.666f, 0.333f); glVertex3f(-200, 200, -200);
		glTexCoord2f(0.666f, 0.0f); glVertex3f(-200, -200, -200);
		glTexCoord2f(0.333f, 0.0f); glVertex3f(-200, -200, 200);
		// back face
		glTexCoord2f(0.666f, 0.333f); glVertex3f(-200, 200, -200);
		glTexCoord2f(1.0f, 0.333f); glVertex3f(200, 200, -200);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(200, -200, -200);
		glTexCoord2f(0.666f, 0.0f); glVertex3f(-200, -200, -200);
		// left face
		glTexCoord2f(0.0f, 0.666f); glVertex3f(200, 200, -200);
		glTexCoord2f(0.333f, 0.666f); glVertex3f(200, 200, 200);
		glTexCoord2f(0.333f, 0.333f); glVertex3f(200, -200, 200);
		glTexCoord2f(0.0f, 0.333f); glVertex3f(200, -200, -200);
		// top face
		glTexCoord2f(0.666f, 0.333f); glVertex3f(200, -200, 200);
		glTexCoord2f(0.666f, 0.666f); glVertex3f(-200, -200, 200);
		glTexCoord2f(0.333f, 0.666f); glVertex3f(-200, -200, -200);
		glTexCoord2f(0.333f, 0.333f); glVertex3f(200, -200, -200);
		// bottom face
		glTexCoord2f(0.666f, 0.333f); glVertex3f(200, 200, 200);
		glTexCoord2f(1.0f, 0.333f); glVertex3f(-200, 200, 200);
		glTexCoord2f(1.0f, 0.666f); glVertex3f(-200, 200, -200);
		glTexCoord2f(0.666f, 0.666f); glVertex3f(200, 200, -200);
		glEnd();

		nightsky_texture_.getTextureReference().unbind();
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();

		ofSetColor(100, 149, 237, CLAMP(sin(timeOfDay * PI * 2) * -1, 0, 0.5f) * 255 * 2);
		
		air_scatter_mesh_.draw();

		ofSetColor(255, 255, 230, 255);
		
		glTranslatef(50, 0, 0);
		glRotatef(90, 0, 1, 0);
		
		//glColor3f(255, 255, 200);
		ofDrawIcoSphere(1);
	}
}