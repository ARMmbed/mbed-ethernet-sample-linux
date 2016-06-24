/**
 * @file    AccelerometerResource.h
 * @brief   mbed CoAP Endpoint Accelerometer sensor resource supporting CoAP GET
 * @author  Doug Anson
 * @version 1.0
 * @see
 *
 * Copyright (c) 2014
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ACCELEROMETER_RESOURCE_H__
#define __ACCELEROMETER_RESOURCE_H__

// Base class
#include "mbed-connector-interface/DynamicResource.h"

// our Accelerometer sensor
#include "mbed-drivers/mbed.h"

// Synthetic Accelerometer values
float __x = 0.0;
float __y = 0.0;
float __z = 0.0;
float __mx = 0.0;
float __my = 0.0;
float __mz = 0.0;

/** 
 * AccelerometerResource class
 */
class AccelerometerResource : public DynamicResource
{
public:
    /**
    Default constructor
    @param logger input logger instance for this resource
    @param obj_name input the Accelerometer Object name
    @param res_name input the Accelerometer Resource name
    @param observable input the resource is Observable (default: FALSE)
    */
    AccelerometerResource(const Logger *logger,const char *obj_name,const char *res_name,const bool observable = false) : DynamicResource(logger,obj_name,res_name,"Accelerometer",M2MBase::GET_ALLOWED,observable) {
    }

    /**
    Get the value of the Accelerometer sensor
    @returns string containing the acclerometer sensor value
    */
    virtual string get() {
    	char buffer[128] = "";
    	
        // fill the value of the accelerometer
        sprintf(buffer,"{\"accelX\":%.1f,\"accelY\":%.1f,\"accelZ\":%.1f,\"magX\":%.1f,\"magY\":%.1f,\"magZ\":%.1f}",__x,__y,__z,__mx,__my,__mz);
 	this->updateAccelerometer();
        return string(buffer);
    }

private:
    void updateAccelerometer() {
	if (rand()%2)
             __x += 0.17;
        else
             __x -= 0.16;
	if (rand()%2)
             __y += 0.16;
        else
             __y -= 0.17;
        if (rand()%2)
             __z += 0.17;
        else
             __z -= 0.16;
        if (rand()%2)
             __mx += 0.16;
        else
             __mx -= 0.17;
        if (rand()%2)
             __my += 0.17;
        else
             __my -= 0.16;
        if (rand()%2)
             __mz += 0.16;
        else
             __mz -= 0.17;	
    }
};

#endif // __ACCELEROMETER_RESOURCE_H__
