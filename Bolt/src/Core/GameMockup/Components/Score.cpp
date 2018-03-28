#include "Score.h"


// -------------------------------------------------------------------------------------
// ------------------------------------------------------------ Construction/Destruction
// -------------------------------------------------------------------------------------


cScore::~cScore()
{
}


cScore::cScore() :
    tSuperClass( "score" ),
	mValue( 0 )
{
}

cScore::cScore( int iValue ) :
	tSuperClass( "score" ),
	mValue( iValue )
{
}



// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------- Copy
// -------------------------------------------------------------------------------------


cComponent*
cScore::Clone()
{
    return  new cScore( *this );
}


// -------------------------------------------------------------------------------------
// ------------------------------------------------------------------------ Input/Output
// -------------------------------------------------------------------------------------


void
cScore::SaveXML( tinyxml2::XMLElement* iNode, tinyxml2::XMLDocument* iDocument )
{
    tSuperClass::SaveXML( iNode, iDocument );
    iNode->SetAttribute( "score", mValue );
}


void
cScore::LoadXML( tinyxml2::XMLElement* iNode )
{
    tSuperClass::LoadXML( iNode );
    mValue = iNode->IntAttribute( "score", 0 );
}

