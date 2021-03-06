// Copyright 2016 Zou Lu <victl@163.com>.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
/*=========================================================================

  Program:   VeloSLAM
  Module:    TestIMUReader.cxx

  Copyright (c) Zou Lu
  All rights reserved.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME PacketFileSender -
// .SECTION Description
// This program reads IMU packets via UDP.

#include "INSSource.h"
#include "TransformManager.h"
#include "TimeSolver.h"

#include <string>
#include <cstdlib>
#include <iostream>

#include <boost/thread/thread.hpp>
#include <boost/date_time.hpp>

int main(int argc, char* argv[])
{
    INSSource source(1777);
    source.setOutputFile("/tmp/imu.bin");
    boost::shared_ptr<TransformManager> mgr(new TransformManager);
    source.setTransformManager(mgr);
    boost::shared_ptr<TimeSolver> solver(new TimeSolver);
    source.setTimeSolver(solver);
  try
    {
        std::cout << "heheda" << std::endl;
        source.start();
        while(true){
            boost::this_thread::sleep(boost::posix_time::seconds(1));
            int num = mgr->getNumberOfTransforms();
            std::cout<< "Got transforms: " << num << std::endl;
        }
    }
  catch( std::exception & e )
    {
    std::cout << "Caught Exception: " << e.what() << std::endl;
    return 1;
    }

  return 0;
}
