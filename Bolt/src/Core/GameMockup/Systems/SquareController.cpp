#include "SquareController.h"

#include "ECS/Core/Entity.h"
#include "ECS/Utilities/EntityParser.h"
#include "ECS/Core/World.h"

#include "GameMockup/GameApplication.h"
#include "GameMockup/Components/SimplePhysic.h"
#include "GameMockup/Components/Position.h"
#include "GameMockup/Components/SpriteAnimated.h"
#include "GameMockup/Components/UserInput.h"
#include "GameMockup/Components/Score.h"
#include "Math/Utils.h"

#include "SFML/Graphics.hpp"

#include <iostream>

static cEntity* gBullet;

// -------------------------------------------------------------------------------------
// ------------------------------------------------------------ Construction/Destruction
// -------------------------------------------------------------------------------------


cSquareController::~cSquareController()
{
}


cSquareController::cSquareController() :
    tSuperClass()
{
}


// -------------------------------------------------------------------------------------
// ----------------------------------------------------------------------- Init/Finalize
// -------------------------------------------------------------------------------------


void
cSquareController::Initialize()
{
	gBullet = cEntityParser::Instance()->CreateEntityFromPrototypeMap( "bullet" );

	auto pos = dynamic_cast< cPosition* >( gBullet->GetComponentByName( "position" ) );
	pos->mPosition.x = -50.0F;
	pos->mPosition.y = -50.0F;

	auto phys = dynamic_cast< cSimplePhysic* >( gBullet->GetComponentByName( "simplephysic" ) );
	phys->mHitBox.left = -50.0F;
	phys->mHitBox.top = -50.0F;

	phys->mVelocity.y = 0.0F;

	phys->mCollisionCallback = [ phys, pos ]( cEntity* iEntity )
	{
		if( iEntity )
		{
			iEntity->Destroy( );
			auto score = dynamic_cast< cScore* >( iEntity->GetComponentByName( "score" ) );
			gScore += score->mValue;
			std::cout << gScore << '\n';
		}
		phys->mVelocity.y = 0.0F;
		phys->mHitBox.left = -10.0F;
		phys->mHitBox.top = -10.0F;
		pos->mPosition.x = -10.0F;
		pos->mPosition.y = -10.0F;
	};

	cGameApplication::App()->World()->AddEntity( gBullet );
}



void
cSquareController::Finalize()
{
}


// -------------------------------------------------------------------------------------
// ------------------------------------------------------------------------- Update/Draw
// -------------------------------------------------------------------------------------


void
cSquareController::Draw( sf::RenderTarget* iRenderTarget )
{
}


void
cSquareController::Update( unsigned int iDeltaTime )
{
    for( int i = 0; i < mEntityGroup.size(); ++i )
    {
        cEntity* entity = mEntityGroup[ i ];

        auto userinput      = dynamic_cast< cUserInput* >( entity->GetComponentByName( "userinput" ) );
        auto simplephysic	= dynamic_cast< cSimplePhysic* >( entity->GetComponentByName( "simplephysic" ) );
        auto spriteanimated = dynamic_cast< cSpriteAnimated* >( entity->GetComponentByName( "spriteanimated" ) );
		auto position		= dynamic_cast< cPosition* >( entity->GetComponentByName( "position" ) );

        simplephysic->mVelocity.x = 0;
        simplephysic->mVelocity.y = 0;
		
        for( int i = 0; i < userinput->mActions.size(); ++i )
        {
            if( ( userinput->mActions[ i ] == "moveright" ) && (position->mPosition.x + spriteanimated->mCurrentSpriteRect.width < cGameApplication::App()->Window()->getSize().x ) )
            {
                simplephysic->mVelocity.x += 1.5F;
                if( spriteanimated )
                    spriteanimated->Flip();
            }
            else if( userinput->mActions[ i ] == "moveleft" && (position->mPosition.x > 0 ) )
            {
                simplephysic->mVelocity.x -= 1.5F;
                if( spriteanimated )
                    spriteanimated->Unflip();
            }
            else if( userinput->mActions[ i ] == "moverightslow" )
            {
                simplephysic->mVelocity.x += 0.001F;
            }
            else if( userinput->mActions[ i ] == "moveleftslow" )
            {
                simplephysic->mVelocity.x -= 0.001F;
            }
            else if( userinput->mActions[ i ] == "attack" )
            {
				auto phys = dynamic_cast< cSimplePhysic* >( gBullet->GetComponentByName( "simplephysic" ) );
				if ( phys->mVelocity.y == 0.0F )
				{
					float x = position->mPosition.x + 35;
					float y = simplephysic->mHitBox.top - simplephysic->mHitBox.height / 2;
					auto pos = dynamic_cast< cPosition* >( gBullet->GetComponentByName( "position" ) );
					pos->mPosition.x = x;
					pos->mPosition.y = y;

					auto phys = dynamic_cast< cSimplePhysic* >( gBullet->GetComponentByName( "simplephysic" ) );
					phys->mHitBox.left = x;
					phys->mHitBox.top = y;

					phys->mVelocity.y = -2.0F;
					userinput->mActions.erase( userinput->mActions.begin() + i );

				}
            }
        }
    }
}


// -------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------ Entity
// -------------------------------------------------------------------------------------


void
cSquareController::IncomingEntity( cEntity * iEntity )
{
    auto userinput = iEntity->GetComponentByName( "userinput" );
    auto simplephysic = iEntity->GetComponentByName( "simplephysic" );

    if( userinput && simplephysic )
        AcceptEntity( iEntity );
}

