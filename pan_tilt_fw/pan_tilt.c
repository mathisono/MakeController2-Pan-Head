/**
*Program Name: MakeController2-Pan-Head 
*Written By :
* ___ ___  ____ ______ __ __ ____ _____ ___  ____        ___  ______ ______ 
*|   |   |/    |      |  |  |    / ___//   \|    \      /   \|      |      |
*| _   _ |  o  |      |  |  ||  (   \_|     |  _  |    |     |      |      |
*|  \_/  |     |_|  |_|  _  ||  |\__  |  O  |  |  |    |  O  |_|  |_|_|  |_|
*|   |   |  _  | |  | |  |  ||  |/  \ |     |  |  |    |     | |  |   |  |  
*|   |   |  |  | |  | |  |  ||  |\    |     |  |  |    |     | |  |   |  |  
*|___|___|__|__| |__| |__|__|____|\___|\___/|__|__|     \___/  |__|   |__|  
* 
* JPM 
*/
// pan_tilt.c
// created Mar 2, 2012
#include "config.h"
#include "motor.h"
#include "servo.h"
#include "webserver.h"

void MyTask( void* p );

void Run( ) // this task gets called as soon as we boot up.
{
  TaskCreate( MyTask, "Me", 1000, 0, 3 );
}

void MyTask( void* p )
{
  (void)p;
  // initialize here...

  while( true )
  {
    // loop forever in here...
    Sleep(1);
  }
}


