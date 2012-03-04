// pan_tilt.c
// created Mar 3, 2012
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
#include "config.h"
#include "motor.h"
#include "webserver.h"
#include "servo.h"
#include "io.h"
#include "fasttimer.h"
#include "AT91SAM7X256.h"

#define SERVO_OFFSET  1000
#define SERVO_MIN_POSITION  -512
#define SERVO_MAX_POSITION  1536
#define SERVO_MID_POSITION 512
#define SERVO_CYCLE 2048
#define SERVO_SAFE_MIN 0
#define SERVO_SAFE_MAX 1023

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


