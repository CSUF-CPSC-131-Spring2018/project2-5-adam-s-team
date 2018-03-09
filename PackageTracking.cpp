//
//  PackageTracking.cpp
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//

#include "PackageTracking.h"

PackageTracking::PackageTracking(const string& strnum) {
	//to be completed
}

// add a new update
void PackageTracking::m_addUpdate(const string& status, const string& location, const time_t& timeUpdated) {
	//to be completed
}

bool PackageTracking::m_moveBackward()//move iterator one step earlier in time
{
	//to be completed
}

bool PackageTracking::m_moveForward()//move iterator one step forward in time
{
	//to be completed
}

string PackageTracking::m_getLocation()//return the location of the current update
{
	//to be completed
}

time_t PackageTracking::m_getTime()//return the time of the current update
{
	//to be completed
}

string PackageTracking::m_getStatus()//return the status of the current update
{
	//to be completed
}

int PackageTracking::m_getNumofUpdate() const // get the total numbers of shipping status updates
{
	//to be completed
}

void PackageTracking::m_printPreviousUpdates() //print all previous updates in the shipping chain when the package was shipped, all the way up to (but not including) the current update you are viewing (may not be the most recent update)
{
	//to be completed
}

//print all updates from the current update you are viewing to the last update in the tracking chain
void PackageTracking::m_printFollowingUpdates()
{
	//to be completed
}

void PackageTracking::m_printFullTracking()//print all the updates in the tracking chain.
{
	//to be completed
}

bool PackageTracking::m_setCurrent(const time_t& timeUpdated)//view an update.
{
	//to be completed
}


bool PackageTracking::m_readTrackingFile(string fileName) {
	fstream fileReader;
	fileReader.open("TBA688567081000.txt", ios::in);
		if (fileReader.fail()) {
			return false;
		}
		while (!fileReader.eof()) {
			string nextInput, tempStatus, tempLocation;
			time_t tempTime;
			fileReader >> nextInput;

			if (nextInput == "new") {
				getline(fileReader, nextInput, ';');
				tempStatus = nextInput;
				getline(fileReader, nextInput, ';');
				tempLocation = nextInput;
				getline(fileReader, nextInput, '\n');

				stringstream conversion(nextInput);
				conversion >> tempTime;
				
				m_addUpdate(tempStatus, tempLocation, tempTime);
			}

			else if (nextInput == "back") {

			}
			else if (nextInput == "forward") {

			}

		}
}
