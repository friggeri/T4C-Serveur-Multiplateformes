#include "stdafx.h"
#include "ForFlow.h"

using namespace std;

namespace{
    string AnGetName(){
        return GetAppString( IDS_INST_FOR );
    }
    string AnGetHelp(){
        return GetAppString( IDS_INST_FOR_HELP );
    }
};


namespace NPC_Editor
{

ForFlow::ForFlow()	: ControlFlow( AnGetName(), AnGetHelp(), InsFor )
{
}

ForFlow::~ForFlow()
{
}
/////////////////////////////////////////////////////////////////////////////
void ForFlow::SaveImp
/////////////////////////////////////////////////////////////////////////////
// 
//
(
WDAFile &file
)
// Return: WDAFile
/////////////////////////////////////////////////////////////////////////////
{
    file.Write( startValue );
    file.Write( endValue );
    file.Write( assignedVar );
}
/////////////////////////////////////////////////////////////////////////////
void ForFlow::LoadImp
/////////////////////////////////////////////////////////////////////////////
// 
//
(
WDAFile &file
)
// Return: WDAFile
/////////////////////////////////////////////////////////////////////////////
{
    file.Read( startValue );
    file.Read( endValue );
    file.Read( assignedVar );	
}

//////////////////////////////////////////////////////////////////////////////////////////
Instruction *ForFlow::Clone( void )
//////////////////////////////////////////////////////////////////////////////////////////
// Clone a FOR
//////////////////////////////////////////////////////////////////////////////////////////
{
    ForFlow *theFor = new ForFlow;

    theFor->Copy( this );
    theFor->startValue = this->startValue;
    theFor->endValue = this->endValue;
    theFor->assignedVar = this->assignedVar;

    return theFor;
}

//////////////////////////////////////////////////////////////////////////////////////////
void ForFlow::UpdateName( void )
//////////////////////////////////////////////////////////////////////////////////////////
// Update the name.
// 
//////////////////////////////////////////////////////////////////////////////////////////
{
    char buf[ 4096 ];
    sprintf( 
        buf, 
        GetAppString( IDS_FOR_DISPLAY ).c_str(), 
        assignedVar.c_str(),
        startValue.c_str(),
        endValue.c_str()
    );
    
    SetName( buf );
}

} // NPC_Editor
