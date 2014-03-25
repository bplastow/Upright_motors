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
#include "stdio.h"

int rest;
int cycles = 0;
int first = 0;
int holdTime = 5; //hold time in minutes
char* display_time;

int menu_select = 0;
int menu2_select = 1;
int run_mode = 1;
int current_count;
int current_cycle_count;
int cycle_count;
int time_delay;
int Reset_count = 0;
int reset_time;
int incline_delay_current;

//asdf
int incline_up_delay = 20;
int incline_down_delay = 10;
//int max_incline_sense = 100;
///asfd

//peak push test timing
int peakpush_time_delay = 300;
int peakpush_cycle_count = 10;

//peak pull test timing
int peakpull_time_delay = 300;
int peakpull_cycle_count = 10;

//regular push test timing
int regularpush_time_delay = 300;            
int regularpush_cycle_count = 300;

//regular pull test timing
int regularpull_time_delay = 300;            
int regularpull_cycle_count = 300;

//limit switch test timing
int toplimit_time_delay = 60;           
int toplimit_cycle_count = 1500;
int bottomlimit_time_delay = 60;
int bottomlimit_cycle_count = 1500;

char* test;
char* menu_select2test;
char* menu_upper;
char time_display[4];

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
void display_update(void);
void menu_update(void);
void running_display(void);

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	Disp_Start();
    Clock_1_Start();
	
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
	
	for(;;)
    {
        menu_update();
		display_update();       
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
        
    
}

void display_update()
{
	switch ( menu_select )
	{
		default:							//run stop manual
			if (run_mode == 1)
			{
				menu_upper = "Stopped";	
			}
			else
			{
				menu_upper = "Running";	
			}
				
			Disp_Position(0,0);
		    Disp_PrintString(menu_upper);
			Disp_Position(0,12);
			Disp_PrintNumber(Reset_count);
			Disp_PrintString("c");
			Disp_Position(1,0);
			Disp_PrintNumber(reset_time);
			Disp_PrintString("s");
			Disp_Position(1,12);
			Disp_PrintNumber(current_cycle_count);
			Disp_PrintString("c");	
			break;
			
		case 1:									//menu 2
			if (menu2_select == 1)
			{
			    menu_select2test = "Peak Push";
                time_delay = peakpush_time_delay;
                cycle_count = peakpush_cycle_count;
		    }
			else if (menu2_select == 2)
			{
				menu_select2test = "Peak Pull";
                time_delay = peakpull_time_delay;           
                cycle_count = peakpull_cycle_count;
			}					
			else if (menu2_select == 3)
			{
				menu_select2test = "Regular Push";
                time_delay = regularpush_time_delay;           
                cycle_count = regularpush_cycle_count;
			}	
			else if (menu2_select == 4)
			{
				menu_select2test = "Regular Pull";
                time_delay = regularpull_time_delay;            
                cycle_count = regularpull_cycle_count;
			}		
			else if (menu2_select == 5)
			{
				menu_select2test = "Top Limit Switch";
                time_delay = toplimit_time_delay;            
                cycle_count = toplimit_cycle_count;
			}
            else if (menu2_select == 6)
			{
				menu_select2test = "Bottom Limit Switch";
                time_delay = bottomlimit_time_delay;
                cycle_count = bottomlimit_cycle_count;
		    }
					
				
		    Disp_Position(0,0);
			Disp_PrintString("Test to Run");
			Disp_Position(1,0);
			Disp_PrintString(menu_select2test);				
			break;
		
		case 2:
				
			Disp_Position(0,0);
			Disp_PrintString("Up delay");
			Disp_Position(1,0);
			Disp_PrintNumber(incline_up_delay);
			Disp_PrintString("s");
			break;
		
		case 3:
			Disp_Position(0,0);
			Disp_PrintString("Down delay");
			Disp_Position(1,0);
			Disp_PrintNumber(incline_down_delay);
			Disp_PrintString("s");
			break;
		
//		case 4:
//			Disp_Position(0,0);
//			Disp_PrintString("Sense Count");
//			Disp_Position(1,0);
//			Disp_PrintNumber(max_incline_sense);
//			Disp_PrintString("c");
//			break;
			
		case 4:
			Disp_Position(0,0);
			Disp_PrintString("Cycles to run");
			Disp_Position(1,0);
			Disp_PrintNumber(cycle_count);
			Disp_PrintString("c");
			break;
			
		case 5:
			Disp_Position(0,0);
			Disp_PrintString("Time Delay");
			Disp_Position(1,0);
			Disp_PrintNumber(time_delay);
			Disp_PrintString("s");
			break;
			
		case 6:
			Disp_Position(0,0);
			Disp_PrintString("Reset Count");
			Disp_Position(1,0);
			Disp_PrintNumber(Reset_count);
			Disp_PrintString("c");
			break;
		
		
		}



}

void menu_update()
{
	
	if(But_Reg_Read() == 15)
	{
        Disp_ClearDisplay();
		switch(menu2_select)
		{
		/*	default:
				menu_select = 0;
							//manual mode
			break;
			*/
			default:
				current_count = 0;
                current_cycle_count = 0;
				
                peak_push();              //Peak push test
				
			break;
			
			case 2:
				current_count = 0;
                current_cycle_count = 0;
                peak_pull();               //Peak pull test
			break;
			
			case 3:
				current_count = 0;
                current_cycle_count = 0;
				regular_push();            //Regular push test cycling
			break;
			
			case 4:
				current_count = 0;
                current_cycle_count = 0;
				regular_pull();            //Regular pull test cycling
			break;
			
			case 5:
				current_count = 0;
                current_cycle_count = 0;
				top_limit();               //Top limit switch test
			break;
            
            case 6:                         
                current_count = 0;
                current_cycle_count = 0;
				bottom_limit();            //Bottom limit switch test
            break;
		}
	}
/**************************************************************************
************************* Up Button ***************************************
***************************************************************************/    
    if(But_Reg_Read() == 30)
    {
        Disp_ClearDisplay();
        switch (menu_select)
        {
            default:
                //incline up
                while(But_Reg_Read() == 30)
                {
                    Cont_Reg_Write(1);
                    display_update();
                }
                Cont_Reg_Write(0);
                break;
                
            case 1:
                menu2_select++;
                if(menu2_select > 6)
                {
                    menu2_select = 1;
                }
                break;
                    
            case 2:
                incline_up_delay ++;    
                break;
                
            case 3:
                
                incline_down_delay++;
                break;
                
//            case 4:
//                max_incline_sense++;
//                break;
				
		    case 4:
                if(menu2_select == 1)
                {
                    peakpush_cycle_count++;
                    cycle_count = peakpush_cycle_count;
                }
                else if(menu2_select == 2)
                {
                    peakpull_cycle_count++;
                    cycle_count = peakpull_cycle_count;
                }
                else if(menu2_select == 3)
                {
                    regularpush_cycle_count++;
                    cycle_count = regularpush_cycle_count;
                }
                else if(menu2_select == 4)
                {
                    regularpull_cycle_count++;
                    cycle_count = regularpull_cycle_count;
                }
                else if(menu2_select == 5)
                {
                    toplimit_cycle_count++;
                    cycle_count = toplimit_cycle_count;
                }
                else if (menu2_select == 6)
                {
                    bottomlimit_cycle_count++;
                    cycle_count = bottomlimit_cycle_count;
                }
                else
                {
			        cycle_count++;
                }
				break;
				
			case 5:
                if(menu2_select == 1)
                {
                    peakpush_time_delay++;
                    time_delay = peakpush_time_delay;
                }
                else if(menu2_select == 2)
                {
                    peakpull_time_delay++;
                    time_delay = peakpull_time_delay;
                }
                else if(menu2_select == 3)
                {
                    regularpush_time_delay++;
                    time_delay = regularpush_time_delay;
                }
                else if(menu2_select == 4)
                {
                    regularpull_time_delay++;
                    time_delay = regularpull_time_delay;
                }
                else if(menu2_select == 5)
                {
                    toplimit_time_delay++;
                    time_delay = toplimit_time_delay;
                }
                else if(menu2_select == 6)
                {
                    bottomlimit_time_delay++;
                    time_delay = bottomlimit_time_delay;
                }
                else
                {
                    time_delay++;
                }
                break;
				
            case 6:
                Reset_count = 0;
                break;
        }
        while(But_Reg_Read() == 30)
        {
            display_update();
                
        }
        
    }
/**************************************************************************
************************* Down Cycle **************************************
***************************************************************************/	
    if(But_Reg_Read() == 29)
    {
        Disp_ClearDisplay();
        switch (menu_select)
        {
            default:
                //incline down
                while(But_Reg_Read() == 29)
                {
                    Cont_Reg_Write(2);
                    display_update();
                }
                Cont_Reg_Write(0);
                break;
                
            case 1:
                menu2_select--;
                if(menu2_select < 1)
                {
                    menu2_select = 6;
                }
                break;
                    
            case 2:
                incline_up_delay--;    
                break;
                
            case 3:
                incline_down_delay--;
                break;
				
//            case 4:
//                max_incline_sense--;
//                break;
                
		    case 4:
                if(menu2_select == 1)
                {
                    peakpush_cycle_count--;
                    cycle_count = peakpush_cycle_count;
                }
                else if(menu2_select == 2)
                {
                    peakpull_cycle_count--;
                    cycle_count = peakpull_cycle_count;
                }
                else if(menu2_select == 3)
                {
                    regularpush_cycle_count--;
                    cycle_count = regularpush_cycle_count;
                }
                else if(menu2_select == 4)
                {
                    regularpull_cycle_count--;
                    cycle_count = regularpull_cycle_count;
                }
                else if(menu2_select == 5)
                {
                    toplimit_cycle_count--;
                    cycle_count = toplimit_cycle_count;
                }
                else if (menu2_select == 6)
                {
                    bottomlimit_cycle_count++;
                    cycle_count =  bottomlimit_cycle_count;
                }
                else
                {
					cycle_count--;
                }	
				break;
				
		    case 5:
                if(menu2_select == 1)
                {
                    peakpush_time_delay--;
                    time_delay = peakpush_time_delay;
                }
                else if(menu2_select == 2)
                {
                    peakpull_time_delay--;
                    time_delay = peakpull_time_delay;
                }
                else if(menu2_select == 3)
                {
                    regularpush_time_delay--;
                    time_delay = regularpush_time_delay;
                }
                else if(menu2_select == 4)
                {
                    regularpull_time_delay--;
                    time_delay = regularpull_time_delay;
                }
                else if(menu2_select == 5)
                {
                    toplimit_time_delay--;
                    time_delay = toplimit_time_delay;
                }
                else if(menu2_select == 6)
                {
                    bottomlimit_time_delay--;
                    time_delay = bottomlimit_time_delay;
                }
                else
                {
                    time_delay--;
                }
                break;
				
            case 6:
                Reset_count = 0;
                break;
        }
            
        while(But_Reg_Read() == 29)
        {
            display_update();
        }
    }
    
/**************************************************************************
************************* Menu Cycle **************************************
***************************************************************************/	
	if(But_Reg_Read() == 27)
	{
		menu_select++;
		Disp_ClearDisplay();

		if (menu_select > 6)
		{
			menu_select = 0;
		}
		while(But_Reg_Read() == 27)
		{
			display_update();
		}
	}

	else if(But_Reg_Read() == 23)
	{
		menu_select--;
		Disp_ClearDisplay();
			
		if (menu_select < 0)
		{
			menu_select = 6;
		}
			
		while(But_Reg_Read() == 23)
		{
			display_update();
		}
			
			
	}

}

void up(){
    rest = 0;
    incline_delay_current = incline_up_delay;
    Cont_Reg_Write(1);
    running_display();
    while(incline_delay_current != 0){
        running_display();
        incline_delay_current--;
        CyDelay(1000);
    }
}

void down(){
    rest = 0;
    incline_delay_current = incline_down_delay;
    Cont_Reg_Write(2);
    running_display();
    while(incline_delay_current != 0){
        running_display();
        incline_delay_current--;
        CyDelay(1000);
    }
}

void hold(){
    Cont_Reg_Write(0);
    CyDelay(1000);
}

void offTime(){
    int sec = time_delay;
	Cont_Reg_Write(0);
    while(sec != 0){
        Disp_Position(0,0);
        Disp_PrintString("Running");
        Disp_Position(1,0);
        Disp_PrintNumber(sec);
        Disp_PrintString("s ");
        CyDelay(1000);
        sec = sec - 1;
    }
    Disp_Position(1,0);
    Disp_PrintString("                ");
}

void peak_push(){
    run_mode = 2;
    up();
    down();
    current_cycle_count++;
    
    if(current_cycle_count == peakpush_cycle_count){
        Cont_Reg_Write(0);
        run_mode = 1;
    }
    display_update();
    offTime();
    
    while(current_cycle_count < peakpush_cycle_count){
        display_update();
        peak_push();
    }
}

void peak_pull(){
    run_mode = 2;
    down();
    up();
    current_cycle_count++;
    
    if(current_cycle_count == peakpull_cycle_count){
        Cont_Reg_Write(0);
        run_mode = 1;
    }
    display_update();
    offTime();
    
    while(current_cycle_count < peakpull_cycle_count){
        display_update();
        peak_pull();
    }
}

void regular_push(){
    run_mode = 2;
    up();
    down();
    current_cycle_count++;
    
    if(current_cycle_count == peakpush_cycle_count){
        Cont_Reg_Write(0);
        run_mode = 1;
    }
    display_update();
    offTime();
    
    while(current_cycle_count < peakpush_cycle_count){
        display_update();
        regular_push();
    }
}

void regular_pull(){
    run_mode = 2;
    down();
    up();
    current_cycle_count++;
    
    if(current_cycle_count == peakpull_cycle_count){
        Cont_Reg_Write(0);
        run_mode = 1;
    }
    display_update();
    offTime();
    
    while(current_cycle_count < peakpull_cycle_count){
        display_update();
        regular_pull();
    }
}

void top_limit(){
    run_mode = 2;
    up();
    down();
    current_cycle_count++;
    
    if(current_cycle_count == peakpush_cycle_count){
        Cont_Reg_Write(0);
        run_mode = 1;
    }
    display_update();
    offTime();
    
    while(current_cycle_count < peakpush_cycle_count){
        display_update();
        top_limit();
    }
}

void bottom_limit(){
    run_mode = 2;
    up();
    down();
    current_cycle_count++;
    
    if(current_cycle_count == peakpush_cycle_count){
        Cont_Reg_Write(0);
        run_mode = 1;
    }
    display_update();
    offTime();
    
    while(current_cycle_count < peakpush_cycle_count){
        display_update();
        bottom_limit();
    }
}

/***********************************************************************************************************
********************************** Running display *********************************************************
************************************************************************************************************/
void running_display()
{
	Disp_Position(0,0);
	Disp_PrintString("Running");
	Disp_Position(0,12);
	Disp_PrintNumber(current_cycle_count);
	Disp_PrintString("c");
		
	if (!rest)
    {
	    Disp_Position(1,0);
	    sprintf(time_display,"%1i",incline_delay_current);
	    display_time = time_display;
	    Disp_PrintString(display_time);
	    Disp_PrintString("s ");
	}
}

/* [] END OF FILE */
