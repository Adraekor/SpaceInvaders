 #include "UserInput.h"


// -------------------------------------------------------------------------------------
// ------------------------------------------------------------ Construction/Destruction
// -------------------------------------------------------------------------------------


cUserInput::~cUserInput()
{
}


cUserInput::cUserInput() :
    tSuperClass( "userinput" )
{
}


cUserInput::cUserInput( const cUserInput & iUserInput ) :
    tSuperClass( iUserInput )
{
}


// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------- Copy
// -------------------------------------------------------------------------------------


cComponent*
cUserInput::Clone()
{
    return  new cUserInput( *this );
}



