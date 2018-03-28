#pragma once

#include "ECS/Core/Component.h"

#include <SFML/Graphics.hpp>

#include "tinyxml2.h"

class cScore :
    public cComponent
{
public:
    typedef  cComponent  tSuperClass;

public:
    virtual  ~cScore();
	cScore();
	cScore( int iValue);

public:
    // Copy
    virtual  cComponent* Clone();

public:
    // Input/Output
    virtual  void SaveXML( tinyxml2::XMLElement* iNode, tinyxml2::XMLDocument* iDocument );
    virtual  void LoadXML( tinyxml2::XMLElement* iNode );

public:
	int mValue;
};
