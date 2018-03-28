#include "GameScreen.h"

#include "ECS/Core/Entity.h"
#include "ECS/Utilities/EntityParser.h"
#include "ECS/Core/World.h"

#include "GameMockup/GameApplication.h"
#include "GameMockup/Components/Color.h"
#include "GameMockup/Components/Position.h"
#include "GameMockup/Components/Size.h"
#include "GameMockup/Components/SpriteAnimated.h"
#include "GameMockup/Components/UserInput.h"
#include "GameMockup/Components/SimplePhysic.h"

#include <iostream>
#include <string>
#include <random>

// -------------------------------------------------------------------------------------
// ------------------------------------------------------------------------ Construction
// -------------------------------------------------------------------------------------


cGameScreen::~cGameScreen()
{
}


cGameScreen::cGameScreen()
{
}


// -------------------------------------------------------------------------------------
// ----------------------------------------------------------------------- Init/Finalize
// -------------------------------------------------------------------------------------


void
cGameScreen::Initialize()
{
    sf::Window* window = cGameApplication::App()->Window();
    sf::Vector2u windowSize = window->getSize();

    cWorld* world = cGameApplication::App()->World();

	auto width  = 5 * 40 + 4 * 40;
	auto height = 4 * 64 + 3 * 64;
	auto topleftX = windowSize.x / 2 - width / 2;
	auto topleftY = windowSize.y / 2 - height/ 2;
	auto x1 = topleftX;
	auto y1 = topleftY;

	for( int n = 0; n < 5; ++n )
	{
		for( int m = 0; m < 4; ++m )
		{
			cEntity* ent = cEntityParser::Instance()->CreateEntityFromPrototypeMap( "monster1" );

			auto posA = dynamic_cast< cPosition* > ( ent->GetComponentByName( "position" ) );
			posA->mPosition.x = x1;
			posA->mPosition.y = y1;
			auto spriteanimated = dynamic_cast< cSpriteAnimated* >( ent->GetComponentByName( "spriteanimated" ) );

			ent->AddComponent( new cSimplePhysic( x1, y1, spriteanimated->mCurrentSpriteRect.width, spriteanimated->mCurrentSpriteRect.height, cSimplePhysic::eType::kDynamic ) );
			world->AddEntity( ent );

			y1 += 40;
		}
		y1 = topleftY;
		x1 += 64;
	}

	cEntity* entity = cEntityParser::Instance()->CreateEntityFromFile( "resources/Core/Entities/spaceship.entity" );
	entity->AddComponent( new cUserInput() );

	auto spriteanimated = dynamic_cast< cSpriteAnimated* >( entity->GetComponentByName( "spriteanimated" ) );
	float x = windowSize.x / 2.0F - spriteanimated->mCurrentSpriteRect.width / 2.0F;
	float y = 4 * windowSize.y / 5;

	auto pos = dynamic_cast< cPosition* > ( entity->GetComponentByName( "position" ) );
	pos->mPosition.x = x;
	pos->mPosition.y = y;

	auto sprite = dynamic_cast< cSpriteAnimated* > ( entity->GetComponentByName( "spriteanimated" ) );
	entity->AddComponent( new cSimplePhysic( x, y, sprite->mCurrentSpriteRect.width, sprite->mCurrentSpriteRect.height, cSimplePhysic::eType::kDynamic ) );
	world->AddEntity( entity );
}


void
cGameScreen::Finalize()
{

}


// -------------------------------------------------------------------------------------
// -------------------------------------------------------------- Main Running functions
// -------------------------------------------------------------------------------------


void
cGameScreen::Draw( sf::RenderTarget* iRenderTarget )
{
}


void
cGameScreen::Update( unsigned int iDeltaTime )
{
}


// -------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------ Events
// -------------------------------------------------------------------------------------


void
cGameScreen::Resized( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::TextEntered( const sf::Event& iEvent )
{
}


void
cGameScreen::KeyPressed( const sf::Event& iEvent )
{

}


void
cGameScreen::KeyReleased( const sf::Event& iEvent )
{
    // Does nothing
    if( iEvent.key.code == sf::Keyboard::Key::S )
    {
        SaveXML();
    }
    else if( iEvent.key.code == sf::Keyboard::Key::T )
    {
        cEntity* entity = cEntityParser::Instance()->CreateEntityFromFile( "resources/Core/Entities/test.entity" );
        cGameApplication::App()->World()->AddEntity( entity );
    }
    else if( iEvent.key.code == sf::Keyboard::Key::A )
    {
        cEntity* entity = cEntityParser::Instance()->CreateEntityFromPrototypeMap( "entA" );
        cGameApplication::App()->World()->AddEntity( entity );
    }
    else if( iEvent.key.code == sf::Keyboard::Key::B )
    {
        cEntity* entity = cEntityParser::Instance()->CreateEntityFromPrototypeMap( "entB" );
        cGameApplication::App()->World()->AddEntity( entity );
    }
    else if( iEvent.key.code == sf::Keyboard::Key::C )
    {
        cEntity* entity = cEntityParser::Instance()->CreateEntityFromPrototypeMap( "testUltime" );
        cGameApplication::App()->World()->AddEntity( entity );
    }
}


void
cGameScreen::MouseWheelMoved( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::MouseWheelScrolled( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::MouseButtonPressed( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::MouseButtonReleased( const sf::Event& iEvent )
{
}


void
cGameScreen::MouseMoved( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::MouseEntered( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::MouseLeft( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::JoystickButtonPressed( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::JoystickButtonReleased( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::JoystickMoved( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::JoystickConnected( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::JoystickDisconnected( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::TouchBegan( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::TouchMoved( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::TouchEnded( const sf::Event& iEvent )
{
    // Does nothing
}


void
cGameScreen::SensorChanged( const sf::Event& iEvent )
{
    // Does nothing
}


// -------------------------------------------------------------------------------------
// ------------------------------------------------------------------------ Input/Output
// -------------------------------------------------------------------------------------

void
cGameScreen::SaveXML()
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* elm = doc.NewElement( "world" );

    cGameApplication::App()->World()->SaveXML( elm, &doc );

    doc.InsertFirstChild( elm );

    tinyxml2::XMLError error = doc.SaveFile( "test.xml" );
    if( error )
    {
        std::cout << "Heh, couldn't save ..." << std::endl;
    }
}


void
cGameScreen::LoadXML()
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = doc.LoadFile( "test.xml" );

    cGameApplication::App()->World()->LoadXML( doc.FirstChildElement( "world" ) );

    if( !error )
        std::cout << "Successfuly loaded " << std::endl;
    else
        std::cout << "Failed to load" << std::endl;
}






