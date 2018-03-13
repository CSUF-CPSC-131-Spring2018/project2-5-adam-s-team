//
//  ShippingStatus.cpp
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//

#include "ShippingStatus.h"

ShippingStatus::ShippingStatus() {
  myStatus = "";
  myLocation = "";
  //myTime = NUll; //?
}

ShippingStatus::ShippingStatus(const string& status, const string& location, const time_t& timeUpdated) {
  myStatus = status;
  myLocation = location;
  myTime = timeUpdated;
}

string ShippingStatus::m_getStatus(){
  return myStatus;
}

string ShippingStatus::m_getLocation(){
   return myLocation;
}

time_t ShippingStatus::m_getTime() {
    return myTime;
}
