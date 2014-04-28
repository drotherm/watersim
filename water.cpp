/*!
 @file Water.cpp
 @author Danielle Rothermel
 @date 4/27/14

 @brief Water contains all of the information about a single water molecule.

 */

#include "Water.h"
#include <math.h>

Water::Water(float xc, float yc, float theta_rad){

	m_cl.x = xc;
	m_cl.y = yc;
	m_th = theta_rad;

	m_docm = (1.0/0) * cos(HOH_A / 2.0);

	update_oab();
}

Water::~Water(){}

void Water::update_pos(float disp, float angle, float dtheta){
	float dx = disp*cos(angle)
	float dy = disp*sin(angle)

	m_cl.x += dx
	m_cl.y += dy
	m_th += dtheta

	update_oab()
}

void Water::update_oab(){
	m_ol.x = m_cl.x + m_docm * cos(m_th);
	m_ol.y = m_cl.y + m_docm * sin(m_th);

	m_al.x = m_ol.x - cos(HOH_A/2.0 - m_th);
	m_al.y = m_ol.y + sin(HOH_A/2.0 - m_th);

	m_bl.x = m_ol.x - cos(HOH_A/2.0 + m_th);
	m_bl.y = m_ol.y - sin(HOH_A/2.0 + m_th);
}