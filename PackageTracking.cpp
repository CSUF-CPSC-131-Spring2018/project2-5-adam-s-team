//
//  PackageTracking.cpp
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//

#include "PackageTracking.h"

PackageTracking::PackageTracking(const string& strnum) {
    int numOfUpdates = 0;
    myTrackingNum = strnum;
    cursor = listOfStatus.begin();
}

// add a new update
void PackageTracking::m_addUpdate( const string& status, const string& location, const time_t& timeUpdated){
    ShippingStatus newStatus(status, location, timeUpdated);
    listOfStatus.push_front(newStatus);
    numOfUpdates++;
}

bool PackageTracking::m_moveBackward()//move iterator one step earlier in time
{
    if (cursor == listOfStatus.begin()) {
        cout << "You are at the beginning of the list." << endl;
        return false;
    }
    cursor--;
    return true;
}

bool PackageTracking::m_moveForward()//move iterator one step forward in time
{
    if (cursor == listOfStatus.end()) {
        cout << "You are at the end of the list." << endl;
        return false;
    }
    cursor++;
    return true;
}

string PackageTracking::m_getLocation( )//return the location of the current update
{
    //return cursor->location; //possibly the correct answer?
    return cursor->m_getLocation();
}

time_t PackageTracking::m_getTime( )//return the time of the current update
{
    //return cursor->timeUpdated; //possibly the correct answer?
    return cursor->m_getTime();
}

string PackageTracking::m_getStatus( )//return the status of the current update
{
    //return cursor->status; //possibly the correct answer?
    return cursor->m_getStatus();
}

int PackageTracking::m_getNumofUpdate() const // get the total numbers of shipping status updates
{
    return numOfUpdates; //returns the counted number of m_addUpdate()
}

void PackageTracking::m_printPreviousUpdates() //print all previous updates in the shipping chain when the package was shipped, all the way up to (but not including) the current update you are viewing (may not be the most recent update)
{
    if (listOfStatus.empty()) {
        cout << "No updates available to print." << endl;
        return;
    }
    for (list<ShippingStatus>::iterator i = listOfStatus.begin(); i != cursor; i++) {
        cout << i -> m_getLocation() << endl;
        cout << i -> m_getStatus() << endl;
        cout << i -> m_getTime() << endl << endl;
    }
}

//print all updates from the current update you are viewing to the last update in the tracking chain
void PackageTracking::m_printFollowingUpdates()
{
    if (listOfStatus.empty()){
        cout << "No list exists yet!" << endl;
        return;
    }
    for (list<ShippingStatus>::iterator i = cursor; i == listOfStatus.end(); i++) { //cursor will go up to the end of the list and print all of them
        cout << i -> m_getLocation() << endl;
        cout << i -> m_getStatus() << endl;
        cout << i -> m_getTime() << endl << endl;
    }
}

void PackageTracking::m_printFullTracking()//print all the updates in the tracking chain.
{
    cursor = listOfStatus.begin();
    list<ShippingStatus>::iterator i = listOfStatus.end();
    if (listOfStatus.empty()){
        cout << "List is empty." << endl;
        return;
    }

    for (cursor; cursor != i; cursor++) {
        cout << cursor -> m_getLocation() << endl;
        cout << cursor -> m_getStatus() << endl;
        cout << cursor -> m_getTime() << endl << endl;
    }
}

bool PackageTracking::m_setCurrent(const time_t& timeUpdated)//view an update.
{
    for (list<ShippingStatus>::iterator i = listOfStatus.begin(); i == listOfStatus.end(); i++) {
        if (i -> m_getTime() == timeUpdated) {
            cout << i -> m_getLocation() << endl;
            cout << i -> m_getStatus() << endl;
            cout << i -> m_getTime() << endl;
            cursor = i;
            return true;
        }
    }
    cout << "No result found." << endl;
    return false;
}


bool PackageTracking::m_readTrackingFile(string fileName) {

    string input, tempStatus, tempLocation;
    time_t tempTime;

    fstream myFile;

    myFile.open(fileName, ios::in);

    if (myFile.fail()) {
        return false;
    }
    while (!myFile.eof()) {
        myFile >> input;
        //input = toupper(input);
        if (input == "new") { //if use toupper() must change 'new' to 'NEW'!!!
            getline(myFile, input, ';');
        	tempStatus = input;
        	getline(myFile, input, ';');
        	tempLocation = input;

        	/*
        	code to take input for tempTime

        	getline(myFile, input, '\n');
        	tempTime = input;
            // other code here
        	*/
            /*
        	getline(myFile, input, '\n');
            stringstream conversion(input);
        	conversion >> tempTime;
        	*/
        	//add new update to the list with the items read from the file

        	m_addUpdate(tempStatus, tempLocation, tempTime);

        } else if (input == "back") {
            //if input is keyword: back, move cursor back
            m_moveBackward();
        } else if (input == "forward") {
            //if input is keyword: forward, move cursor forward
            m_moveForward();
        }
    }
    myFile.close();
    return true;
}


