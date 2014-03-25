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
int menu_select = 0;
int menu2_select = 1;
int run_mode;

char* test;
char* menu_select2test;
char* menu_upper;

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
			    menu_select2test = "Peak Pull";
                time_delay = normal_time_delay;
                cycle_count = normal_cycle_count;
		    }
			else if (menu2_select == 2)
			{
				menu_select2test = "Peak Push";
                time_delay = nineCycle_time_delay;           //cycle every 2 minutes
                cycle_count = nine_cycle_count;
			}					
			else if (menu2_select == 3)
			{
				menu_select2test = "Regular Pull";
                time_delay = nusiance_time_delay;            //cycle every 2 minutes
                cycle_count = nusiance_cycle_count;
			}	
			else if (menu2_select == 4)
			{
				menu_select2test = "Regular Push";
                time_delay = nusiance_time_delay;            //cycle every 2 minutes
                cycle_count = nusiance_cycle_count;
			}		
			else if (menu2_select == 5)
			{
				menu_select2test = "Limit Switch";
                time_delay = nusiance_time_delay;            //cycle every 2 minutes
                cycle_count = nusiance_cycle_count;
			}
            else if (menu2_select == 6)
			{
				menu_select2test = "Life Cycle";
                time_delay = life_cycle_delay;
                cycle_count = life_cycle_count;
		    }
					
				
		    Disp_Position(0,0);
			Disp_PrintString("Test to Run");
			Disp_Position(1,0);
			Disp_PrintString(menu_select2test);				
			break;
		
		case 2:
				
			Disp_Position(0,0);
			Disp_PrintString("Incline up");
			Disp_Position(1,0);
			Disp_PrintNumber(incline_up_delay);
			Disp_PrintString("s");
			break;
		
		case 3:
			Disp_Position(0,0);
			Disp_PrintString("Incline Down");
			Disp_Position(1,0);
			Disp_PrintNumber(incline_down_delay);
			Disp_PrintString("s");
			break;
		
		case 4:
			Disp_Position(0,0);
			Disp_PrintString("Sense Count");
			Disp_Position(1,0);
			Disp_PrintNumber(max_incline_sense);
			Disp_PrintString("c");
			break;
			
		case 5:
			Disp_Position(0,0);
			Disp_PrintString("Cycles to run");
			Disp_Position(1,0);
			Disp_PrintNumber(cycle_count);
			Disp_PrintString("c");
			break;
			
		case 6:
			Disp_Position(0,0);
			Disp_PrintString("Time Delay");
			Disp_Position(1,0);
			Disp_PrintNumber(time_delay);
			Disp_PrintString("s");
			break;
			
		case 7:
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
				regular_pull();            //Regular pull test
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
    if(But_Reg_Read() == 27)
    {
        Disp_ClearDisplay();
        switch (menu_select)
        {
            default:
                //incline up
                while(But_Reg_Read() == 27)
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
                
            case 4:
                max_incline_sense++;
                break;
				
		    case 5:
                if(menu2_select == 1)
                {
                    normal_cycle_count++;
                    cycle_count = normal_cycle_count;
                }
                else if(menu2_select == 2)
                {
                    nine_cycle_count++;
                    cycle_count = nine_cycle_count;
                }
                else if(menu2_select == 3)
                {
                    nusiance_cycle_count++;
                    cycle_count = nusiance_cycle_count;
                }
                else if (menu2_select == 6)
                {
                    life_cycle_count = life_cycle_count + 200;
                    cycle_count = life_cycle_count;
                }
                else
                {
			        cycle_count++;
                }
				break;
				
			case 6:
                if(menu2_select == 1)
                {
                    normal_time_delay++;
                    time_delay = normal_time_delay;
                }
                else if(menu2_select == 2)
                {
                    nineCycle_time_delay++;
                    time_delay = nineCycle_time_delay;
                }
                else if(menu2_select == 3)
                {
                    nusiance_time_delay++;
                    time_delay = nusiance_time_delay;
                }
                else if(menu2_select == 6)
                {
                    life_cycle_delay++;
                    time_delay = life_cycle_delay;
                }
                else
                {
                    time_delay++;
                }
                break;
				
            case 7:
                Reset_count = 0;
                break;
        }
        while(But_Reg_Read() == 27)
        {
            display_update();
                
        }
        
    }
/**************************************************************************
************************* Down Cycle **************************************
***************************************************************************/	
    if(But_Reg_Read() == 23)
    {
        Disp_ClearDisplay();
        switch (menu_select)
        {
            default:
                //incline down
                while(But_Reg_Read() == 23)
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
				
            case 4:
                max_incline_sense--;
                break;
                
		    case 5:
                if(menu2_select == 1)
                {
                    normal_cycle_count--;
                    cycle_count = normal_cycle_count;
                }
                else if(menu2_select == 2)
                {
                    nine_cycle_count--;
                    cycle_count = nine_cycle_count;
                }
                else if(menu2_select == 3)
                {
                    nusiance_cycle_count--;
                    cycle_count = nusiance_cycle_count;
                }
                else if (menu2_select == 6)
                {
                    life_cycle_count = life_cycle_count - 200;
                    cycle_count = life_cycle_count;
                }
                else
                {
					cycle_count--;
                }	
				break;
				
		    case 6:
                if(menu2_select == 1)
                {
                    normal_time_delay--;
                    //time_delay--;
                    time_delay = normal_time_delay;
                }
                else if(menu2_select == 2)
                {
                    nineCycle_time_delay--;
                    //time_delay--;
                    time_delay = nineCycle_time_delay;
                }
                else if(menu2_select == 3)
                {
                    nusiance_time_delay--;
                    //time_delay--;
                    time_delay = nusiance_time_delay;
                }
                else if(menu2_select == 6)
                {
                    life_cycle_delay--;
                    //time_delay--;
                    time_delay = life_cycle_delay;
                }
                else
                {
                    time_delay--;
                }
                break;
				
            case 7:
                Reset_count = 0;
                break;
        }
            
        while(But_Reg_Read() == 23)
        {
            display_update();
        }
    }
    
/**************************************************************************
************************* Menu Cycle **************************************
***************************************************************************/	
	if(But_Reg_Read() == 30)
	{
		menu_select++;
		Disp_ClearDisplay();

		if (menu_select > 7)
		{
			menu_select = 0;
		}
		while(But_Reg_Read() == 30)
		{
			display_update();
		}
	}

	else if(But_Reg_Read() == 29)
	{
		menu_select--;
		Disp_ClearDisplay();
			
		if (menu_select < 0)
		{
			menu_select = 7;
		}
			
		while(But_Reg_Read() == 29)
		{
			display_update();
		}
			
			
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
    int min = holdTime;
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
