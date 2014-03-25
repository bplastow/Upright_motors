/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int cycles = 0;
int first = 0;
int holdTime = 5; //hold time in minutes
int menu = 0;

char* test;

void up(void);
void down(void);
void hold(void);
void offTime(void);
void menuSel(void);
void peak_pull(void);
void peak_push(void);
void regular_pull(void);
void regular_push(void);
void top_limit(void);
void bottom_limit(void);

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	Disp_Start();
    Clock_1_Start();
	
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    Disp_Position(0,0);
    Disp_PrintString("Cycles: ");
	Disp_PrintNumber(cycles);
	
	for(;;)
    {
		if(But_Reg_Read() == 30){
            Cont_Reg_Write(1);
        }
        else if(But_Reg_Read() == 29){
            Cont_Reg_Write(2);
        }
        else{
            Cont_Reg_Write(0);
        }
        
        menuSel();
        
        /* if(pinStart_Read() == 0 || first == 1){
            
            
            first = 1;
			
            
            
            //hold();
            
            down();
            
            up();
            
			cycles++;
			
			Disp_Position(0,0);
		    Disp_PrintString("Cycles: ");
		    Disp_PrintNumber(cycles);
			
            if(cycles == 9){
                first = 0;
                Disp_Position(1,0);
                Disp_PrintString("Complete");
                break;
            }
			offTime();
            
		}
		
	*/	
    }
        
    return 0;
    
}

void menuSel(){
    if(But_Reg_Read() == 27){  // Menu button pressed
        
        Disp_ClearDisplay();
        switch(menu){
            case 0:
                test = "Peak";
                break;
            case 1:
                test = "Regular";
                break;
            case 2:
                test = "Limit Switch";
                break;
        }
        
        Disp_Position(0,0);
        Disp_PrintString("Test to perform:");
	    Disp_Position(1,0);
        Disp_PrintString(test);
        
        menu++;
        if(menu > 2){
            menu = 0;
        }
    }
    
    if(But_Reg_Read() == 23){ // Back button pressed
        
    }
}

void up(){
    Cont_Reg_Write(1);
    CyDelay(10000);  // was 13500 for full cycle with 50 lb load
					// was 5800 for 50 lb load to do half cycle
					// was 3900 for no load cycling
}

void down(){
    Cont_Reg_Write(2);
    CyDelay(23000); // was 9700 for full cycle with 50 lb load
				   // was 5000 for 50 lb load to do half cycle
				   // was 4700 for no load cycling
}

void hold(){
    Cont_Reg_Write(0);
    CyDelay(1000);
}

void offTime(){
    int sec = 0;
    int min = 5;
	Up_Write(0);
	Down_Write(0);
    while(sec != 0 || min != 0){
        Disp_Position(1,0);
        Disp_PrintString("Time Left: ");
        Disp_PrintNumber(min);
        Disp_PrintString(":");
        if(sec < 10){
            Disp_PrintNumber(0);
        }
        Disp_PrintNumber(sec);
        CyDelay(1000);
        sec = sec - 1;
        if(sec < 0){
            min = min - 1;
            sec = 59;
        }
    }
    Disp_Position(1,0);
    Disp_PrintString("                ");
}

/* [] END OF FILE */
