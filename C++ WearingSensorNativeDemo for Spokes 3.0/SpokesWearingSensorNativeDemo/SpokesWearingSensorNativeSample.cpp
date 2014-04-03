// SpokesNativeSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "Spokes3G.h"
#include "cpp\query_cast.h"

// create sink for receiving device listener events
class DeviceListenerEventSink : public IDeviceListenerCallback
{
public:
	DeviceListenerEventSink() {}
	// IDeviceListenerCallback implementations
	virtual void onHeadsetButtonPressed(DeviceListenerEventArgs const &args) { }
    virtual void onHeadsetStateChanged(DeviceListenerEventArgs const &args) 
	{ 
		switch (args.headsetStateChange)
		{
			case HS_STATE_CHANGE_DON:
				wcout << "Headset is worn" << endl;
				break;
			case HS_STATE_CHANGE_DOFF:
				wcout << "Headset is not worn" << endl;
				break;
		}
	}
    virtual void onBaseButtonPressed(DeviceListenerEventArgs const &args) { }
    virtual void onBaseStateChanged(DeviceListenerEventArgs const &args) { }
    virtual void onATDStateChanged(DeviceListenerEventArgs const &args) { }
};

int _tmain(int argc, _TCHAR* argv[])
{
    InitSpokesRuntime();

	// create session manager
	ISessionManager *sessionManager = nullptr;
	if( SM_RESULT_SUCCESS == getSessionManager(&sessionManager) )
	{
		// create session
		ISession* session = nullptr;
		if( SM_RESULT_SUCCESS == sessionManager->registerSession( L"Spokes Wearing Sensor Native Sample", &session ) )
		{
			IDevice* activeDevice = nullptr;
			if( SM_RESULT_SUCCESS != session->getActiveDevice( &activeDevice ) )
			{
				wcout << "there is no active devices, please attach one then run the app again" << endl;
				activeDevice = nullptr;
			}
			else
			{
				// Get device listener
				pDeviceListener dev_listener = nullptr;
				auto dm_result = activeDevice->getDeviceListener(&dev_listener);

				if(dm_result != DM_RESULT_SUCCESS) 
				{
					wcout << "failed to get device listener interface" << endl;
				}
				else
				{
					// Register device listener callbacks
					IDeviceListenerCallback* deviceListenerEventSink( new DeviceListenerEventSink() );
					dm_result = dev_listener->registerCallback(deviceListenerEventSink);

					if(dm_result != DM_RESULT_SUCCESS)
					{
						wcout << "failed to register device listener callback" << endl;
					}
				}
			}

			wcout << "Press enter to quit..." << endl;
			cin.ignore();

			if (activeDevice != nullptr) activeDevice->Release();
			sessionManager->unregisterSession( session );
			session->Release();
			//sessionManager->Release();
		    ShutDownSpokesRuntime();
		}
	}
	return 0;
}
