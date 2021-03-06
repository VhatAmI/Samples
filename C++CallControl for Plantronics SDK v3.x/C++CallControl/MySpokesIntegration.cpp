#include "stdafx.h"
#include "MySpokesIntegration.h"

extern int mycallid;

MySpokesIntegration::MySpokesIntegration(void)
{
	m_spokes = Spokes::GetInstance();  // TODO resolved unresolved external!

	m_spokes->SetLogger(this);  // TODO resolved unresolved external!

	m_spokes->SetEventHandler(this);  // TODO resolved unresolved external!
}

MySpokesIntegration::~MySpokesIntegration(void)
{
	delete m_spokes;
	m_spokes = NULL;
}

void MySpokesIntegration::Spokes_TakenOff(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Taken Off.");
	delete e;
}

void MySpokesIntegration::Spokes_PutOn(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Put On.");
	delete e;
}

void MySpokesIntegration::Spokes_Near(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Near.");
	delete e;
}

void MySpokesIntegration::Spokes_Far(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Far.");
	delete e;
}

void MySpokesIntegration::Spokes_InRange(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> In Range.");
	delete e;
}

void MySpokesIntegration::Spokes_OutOfRange(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Out of Range.");
	delete e;
}

void MySpokesIntegration::Spokes_Docked(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Docked.");
	delete e;
}

void MySpokesIntegration::Spokes_UnDocked(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> UnDocked.");
	delete e;
}

void MySpokesIntegration::Spokes_MobileCallerId(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Mobile Caller Id.");
	delete e;
}

void MySpokesIntegration::Spokes_OnMobileCall(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> On Mobile Call.");
	delete e;
}

void MySpokesIntegration::Spokes_NotOnMobileCall(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Not On Mobile Call.");
	delete e;
}

void MySpokesIntegration::Spokes_SerialNumber(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Serial Number.");
	delete e;
}

void MySpokesIntegration::Spokes_CallAnswered(CallAnsweredArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Call Answered.");
	delete e;
}

void MySpokesIntegration::Spokes_CallEnded(CallEndedArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Call Ended.");
	delete e;
}

void MySpokesIntegration::Spokes_CallSwitched(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Call Switched.");
	delete e;
}

void MySpokesIntegration::Spokes_OnCall(OnCallArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> On Call.");
	delete e;
}

void MySpokesIntegration::Spokes_NotOnCall(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Not On Call.");
	delete e;
}

void MySpokesIntegration::Spokes_MuteChanged(MuteChangedArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Mute Changed.");
	delete e;
}

void MySpokesIntegration::Spokes_LineActiveChanged(LineActiveChangedArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Line Active Changed.");
	delete e;
}

void MySpokesIntegration::Spokes_Attached(AttachedArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Attached.");
	DebugPrint(__FUNCTION__, "Device was: ");
	DebugPrint(__FUNCTION__, e->m_strDeviceName);
	delete e;
}

void MySpokesIntegration::Spokes_Detached(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Detached.");
	delete e;
}

void MySpokesIntegration::Spokes_CapabilitiesChanged(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Capabilities Changed.");
	delete e;
}

void MySpokesIntegration::Spokes_MultiLineStateChanged(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> MultiLine State Changed.");
	delete e;
}

// These are commented out - not available from the Plantronics SDK
//void MySpokesIntegration::Spokes_SystemSuspending(EventArgs * e)
//{
//	DebugPrint(__FUNCTION__, ">>> System Suspending!");
//	delete e;
//
//	DebugPrint(__FUNCTION__, ">>> END the call quick (if one in progress)");
////	Spokes::GetInstance()->EndCall(mycallid);  // TODO resolved unresolved external!
//}
//
//void MySpokesIntegration::Spokes_SystemResuming(EventArgs * e)
//{
//	DebugPrint(__FUNCTION__, ">>> System Resuming!");
//	delete e;
//}

void MySpokesIntegration::Spokes_BatteryLevelChanged(EventArgs * e)
{
	DebugPrint(__FUNCTION__, ">>> Battery Level changed.");
	delete e;
}

void MySpokesIntegration::Spokes_ProximityUnknown(EventArgs * e) 
{ 
	DebugPrint(__FUNCTION__, ">>> Proximity Unknown");
	delete e;
}

void MySpokesIntegration::Spokes_ProximityEnabled(EventArgs * e)
{ 
	DebugPrint(__FUNCTION__, ">>> Proximity Enabled");
	delete e;
}

void MySpokesIntegration::Spokes_ProximityDisabled(EventArgs * e) 
{ 
	DebugPrint(__FUNCTION__, ">>> Proximity Disabled");
	delete e;
}

void MySpokesIntegration::Spokes_Connected(EventArgs * e)
{ 
	DebugPrint(__FUNCTION__, ">>> Headset QD Connector is connected");
	delete e;
}

void MySpokesIntegration::Spokes_Disconnected(EventArgs * e)
{ 
	DebugPrint(__FUNCTION__, ">>> Headset QD Connector is disconnected");
	delete e;
}

void MySpokesIntegration::Spokes_ButtonPressed(ButtonPressArgs * e)
{ 
	string outstr;
	ostringstream tmpstrm;
	tmpstrm << ">>> Button Pressed: " << e->m_headsetButton;
	outstr = tmpstrm.str();
	DebugPrint(__FUNCTION__, outstr);

	delete e;
}

void MySpokesIntegration::Spokes_BaseButtonPressed(BaseButtonPressArgs * e)
{ 
	string outstr;
	ostringstream tmpstrm;
	tmpstrm << ">>> Base Button Pressed: " << e->m_baseButton;
	outstr = tmpstrm.str();
	DebugPrint(__FUNCTION__, outstr);

	delete e;
}

void MySpokesIntegration::Spokes_CallRequested(CallRequestedArgs * e)
{ 
	DebugPrint(__FUNCTION__, ">>> Call Requested");
	DebugPrint(__FUNCTION__, e->m_contactName);
	delete e;
}

void MySpokesIntegration::DebugPrint(string methodname, string str)
{
	string newEntry;

		SYSTEMTIME systime;
	GetSystemTime(&systime);

	ostringstream tmpstrm;
	tmpstrm
		<< std::setfill('0') << std::setw(2) << systime.wHour << ":"
		<< std::setfill('0') << std::setw(2) << systime.wMinute << ":"
		<< std::setfill('0') << std::setw(2) << systime.wSecond << "."
		<< std::setfill('0') << std::setw(3) << systime.wMilliseconds << ": "
		<< methodname << ": " << str << endl;
	newEntry = tmpstrm.str();

	// convert to wide string as demonstration to support unicode output (wide character support) for Spokes debug output
	// thanks: http://stackoverflow.com/questions/6691555/converting-narrow-string-to-wide-string
    wchar_t* buf = new wchar_t[newEntry.size() * 2 + 2];
    swprintf( buf, L"%S", newEntry.c_str() );
    std::wstring wideval = buf;
    delete[] buf;

	// using wcout to demonstrate adding Spokes debug output to a wide character standard output (unicode support)
	wcout << wideval;
}