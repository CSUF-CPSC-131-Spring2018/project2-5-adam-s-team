//
//  PackageTracking.cpp
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//
#include "PackageTracking.h"

PackageTracking::PackageTracking(const string& strnum) {
	trackingNumber = strnum;
	cursor = tracker.begin();
}

// add a new update
void PackageTracking::m_addUpdate(const string& status, const string& location, const time_t& timeUpdated) {
	ShippingStatus new_status(status, location, timeUpdated);
	tracker.push_back(new_status);
	cursor = tracker.end();
	cursor--;
}

bool PackageTracking::m_moveBackward()//move iterator one step earlier in time
{
	if (tracker.empty() || cursor == tracker.begin()) {
		return false;
	}
	cursor--;
	return true;
}

bool PackageTracking::m_moveForward()//move iterator one step forward in time
{
	if (tracker.empty() || cursor == tracker.end()) {
		return false;
	}
	cursor++;
	return true;
}

string PackageTracking::m_getLocation()//return the location of the current update
{
	return cursor->m_getLocation();
}

time_t PackageTracking::m_getTime()//return the time of the current update
{
	return cursor->m_getTime();
}

string PackageTracking::m_getStatus()//return the status of the current update
{
	return cursor->m_getStatus();
}

int PackageTracking::m_getNumofUpdate() const // get the total numbers of shipping status updates
{
	return tracker.size();
}

void PackageTracking::m_printPreviousUpdates() //print all previous updates in the shipping chain when the package was shipped, all the way up to (but not including) the current update you are viewing (may not be the most recent update)
{
	if (tracker.empty()) {
		return;
	}
	for (list<ShippingStatus>::iterator p = tracker.begin(); p != cursor; p++) {
		cout << p->m_getTime() << '\t';
		cout << p->m_getStatus() << endl;
		cout << p->m_getLocation() << endl << endl;
	}

}

//print all updates from the current update you are viewing to the last update in the tracking chain
void PackageTracking::m_printFollowingUpdates()
{
	if (tracker.empty()) {
		return;
	}
	for (list<ShippingStatus>::iterator p = cursor; p != tracker.end(); p++) {
		cout << p->m_getTime() << '\t';
		cout << p->m_getStatus() << endl;
		cout << p->m_getLocation() << endl << endl;
	}
}

void PackageTracking::m_printFullTracking()//print all the updates in the tracking chain.
{
	if (tracker.empty()) {
		cout << "No package information yet on record!/n";
		return;
	}
	for (list<ShippingStatus>::iterator p = tracker.begin(); p != tracker.end(); p++) {
		cout << p->m_getTime() << '\t';
		cout << p->m_getStatus() << endl;
		cout << p->m_getLocation() << endl << endl;
	}
}

bool PackageTracking::m_setCurrent(const time_t& timeUpdated)//view an update.
{
	for (list<ShippingStatus>::iterator p = tracker.begin(); p != tracker.end(); p++) {
		if (p->m_getTime() == timeUpdated) {
			cursor = p;
			return true;
		}
	}
	cout << "No status in record for that time!/n";
	return false;
}


bool PackageTracking::m_readTrackingFile(string fileName) {
	fstream fileReader;
	fileReader.open(fileName, ios::in);
		if (fileReader.fail()) {
			return false;
		}
		string nextInput, tempStatus, tempLocation;
		time_t tempTime;
		while (!fileReader.eof()) {
			
			fileReader >> nextInput;

			if (nextInput == "new") {
				getline(fileReader, nextInput, ';');
				tempStatus = nextInput.substr(1, nextInput.length()); //to skip \n
				getline(fileReader, nextInput, ';');
				tempLocation = nextInput;
				getline(fileReader, nextInput, '\n');

				stringstream conversion(nextInput);
				conversion >> tempTime;
				
				m_addUpdate(tempStatus, tempLocation, tempTime);
			}

			else if (nextInput == "back") {
				m_moveBackward();
			}
			else if (nextInput == "forward") {
				m_moveForward();
			}
		}
		return true;
}
