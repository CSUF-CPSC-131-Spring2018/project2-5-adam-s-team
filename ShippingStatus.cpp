//
//  ShippingStatus.cpp
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//

#include "ShippingStatus.h"

ShippingStatus::ShippingStatus() {
	package_status = "";
	package_location = "";
	timestamp = NULL;
}

ShippingStatus::ShippingStatus(const string& status, const string& location, const time_t& timeUpdated) {
	package_status = status;
	package_location = location;
	timestamp = timeUpdated;
}

string ShippingStatus::m_getStatus(){
	return package_status;
}

string ShippingStatus::m_getLocation(){
	return package_location;
}

time_t ShippingStatus::m_getTime() {
	return timestamp;
}
