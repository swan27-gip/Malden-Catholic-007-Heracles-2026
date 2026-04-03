#include <kipr/wombat.h>
//Functions

int	line = 4000;
        
	void drive(int power){
        motor(0,power);
        motor(1,power);
        motor(2,power);
        motor(3,power + 10);
    }
	void left(int power){
        motor(0,-power);
        motor(1,power);
        motor(2,-power);
        motor(3,power + 10);
    }
	void right(int power){
        motor(0,power);
        motor(1,-power);
        motor(2,power);
        motor(3,-power + 10);
    }
	void turnL(int power){
        motor(0,-power);
        motor(1,-power);
        motor(2,power);
        motor(3,power + 10);
    }
	void turnR(int power){
        motor(0,power);
        motor(1,power);
        motor(2,-power);
        motor(3,-power + 10);
    }
//Arm can only go from 230(up) - 530(down)
    void arm(int degree){
        enable_servos();
        set_servo_position(3, degree);
        msleep(100);
    }
	void claw(int degree){
        enable_servos();
        set_servo_position(0,degree);
        msleep(100);
    }
	
	void wait(int time){
		drive(0);
		msleep(time);
}
	
        
        
//Sections Done (after a part of the bots code is perfected mark the beginning and end on the board and make it into a function)

    void Upperwarehouse_start(){
            arm(230); 		 //initialization (starting position (remember to place wait for light after this section and make init a function!!!))
    			   	 //start with a (janeale) 3 finger gap from the back section of the upper warehouse		
    				 // <---- wait_for_light(0);
    
    
    turnR(40);
    msleep(1500);

    left(40);
    msleep(900);
    
    				//back up to square off with back wall
    drive(-40);
    msleep(600);
    
    drive (-25);
    msleep(200);
    				//arm goes down to get palms in claw
    arm(530);
    
    				//claw goes here
    
    drive(40);
    msleep(5000);
    
    				//claw closes here!! lines up with next section and then moves forward
    
    left(40);
    msleep(1500);
    
    left(25);
    msleep(1000);
    
    right(25);
    msleep(500);
    
   					 //claw opens again for other section and drives forward
    
    drive(40);
    msleep(3500);
    
 				   	 //ignore this \/\/\/   
 /*     
   					 //goes towards the red cube
    
    right(40);
    msleep(2000);
    
    arm(230);
*/
  					  //claw stays closed now until it drops poms
    
  					  //goes down ramp here (little adjustment for line following down)
       
        
    while (analog(0) < line){
         printf("here 1");
        right(40);
        if (analog(0) > line){
            printf("stopped 1");
            break;
        }
    }
        
     wait(100);      
        
    while (analog(0) > line){
         printf("here 2");
        left(40);
        if (analog(0) < line){
             printf("stopped 2");
            break;
        }
    }
      
     wait(100);
        
    while (analog(0) < line && analog(5) < line){
       drive(40);
         printf("here 3");
        if (analog(0) > line){
            turnR(40);
        }
        if (analog(5) > line){
            turnL(40);
        }
        if (analog(0) > line && analog(5) > line){
            break;
        }
    }
        
      drive(40);
      msleep(3000);
        wait(100);
    
      while (analog(0) < line && analog(5) < line){
       drive(40);
         printf("here 4");
        if (analog(0) > line){
            turnR(40);
        }
        if (analog(5) > line){
            turnL(40);
        }
        if (analog(0) > line && analog(5) > line){
            break;
        }
    }
        while (analog(0) > line){
         printf("here 5");
        drive(40);
        if (analog(0) < line){
             printf("stopped 5");
            break;
        }
    }
        
    
    
  					  //wait(100);
   // drive(60);
   // msleep(9500);
    
    
    
/*
    while (digital(5) < 2900){
        printf("got here");
    drive(25);
        if (digital(5) > 2900){
            right(25);
        }
       if (digital(5) < 2000){
            break;
       }
    }
 */   
    					//turning to face right way for poms

    drive(40);
    msleep(3200);
        
    right(40);
    msleep(1500);
    
    turnR(40);
    msleep(1000);
    
}

int main()
{
	Upperwarehouse_start();
    
    					//(this is where any code for poms should start)Going forward until first black line
    
    while (analog(0) < line && analog(5) < line){
        drive(40);
        if (analog(0) > line && analog (5) < line){
            break;
        }
    }
   
   wait(100);
    
       while (analog(0) > line && analog(5) > line){
        drive(40);
        if (analog(0) < line && analog (5) < line){
            break;
        }
    }
   
    
    
     // wait(100);
    drive(40);
    msleep(1000);
     while (analog(0) < line && analog(5) < line){
        drive(40);
    //     printf("made it here");
        if (analog(0) > line && analog (5) < line){
            break;
        }
    }
    
    wait(100);
    
         while (analog(0) > line && analog(5) > line){
        drive(50);
         printf("made it here");
        if (analog(0) < line && analog (5) < line){
            break;
        }
    }
    
    turnR(50);
    msleep(1250);
    
    while (analog(5) < line){
        left(25);
        if (analog(5) > line){
            break;
        }
    }
    
    
    
   
    
    return 0;
}
