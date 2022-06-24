/*
 * Timer.c
 *
 * Created: 3/30/2022 10:49:19 PM
 *  Author: Ali
 */ 

#include "Timer.h"

Uint32 N_OVFlows ;
Uint32 Init_Value;
void (*GlobalP_Fn)(void) = null;


void Timer_Init(TimerControl* TimerC)
{
	set_bit(SREG,7);
	if (TimerC -> TimerSelect == TIMER0)
	{
		if (TimerC -> TimerMode == TIMER_NORMAL_MODE)
		{
			set_bit(TIMSK,0);
			clr_bit(TCCR0,3);
			clr_bit(TCCR0,6);
		} 
		else if (TimerC -> TimerMode == TIMER_CTC_MODE)
		{
			set_bit(TCCR0,3);
			clr_bit(TCCR0,6);
			if (TimerC -> TimerCompSelect  == TIMER_COMPARETOR_NORMAL)
			{
				//comp00 4
				//comp01 5
				clr_bit(TCCR0,4);
				clr_bit(TCCR0,5);
			}
			else if (TimerC -> TimerCompSelect  == TIMER_COMPARETOR_TOGGLE)
			{
				set_bit(TCCR0,4);
				clr_bit(TCCR0,5);
			}
			else if (TimerC -> TimerCompSelect  == TIMER_COMPARETOR_CLR)
			{
				set_bit(TCCR0,5);
				clr_bit(TCCR0,4);
			}
			else if (TimerC -> TimerCompSelect  == TIMER_COMPARETOR_SET)
			{
				set_bit(TCCR0,4);
				set_bit(TCCR0,5);
			}
// 			else{
// 				#error "Wrong Timer Comparetor Selected"
// 			}
		}
		else if (TimerC -> TimerMode == TIMER_PHASE_CORRECT_8BIT_PWM_MODE)
		{
			set_bit(TCCR0,6);
			clr_bit(TCCR0,3);
			if (TimerC -> TimerCompSelect  == TIMER_COMPARETOR_NORMAL)
			{
				//comp00 4
				//comp01 5
				clr_bit(TCCR0,4);
				clr_bit(TCCR0,5);
			}
			else if (TimerC -> TimerCompSelect  == TIMER_COMPARETOR_TOGGLE)
			{
				set_bit(TCCR0,4);
				clr_bit(TCCR0,5);
			}
			else if (TimerC -> TimerCompSelect  == TIMER_COMPARETOR_CLR)
			{
				set_bit(TCCR0,5);
				clr_bit(TCCR0,4);
			}
			else if (TimerC -> TimerCompSelect  == TIMER_COMPARETOR_SET)
			{
				set_bit(TCCR0,4);
				set_bit(TCCR0,5);
			}
// 			else{
// 				#error "Wrong Timer Comparetor Selected"
// 			}
		}
		else if (TimerC -> TimerMode == TIMER_FAST_PWM_MODE)
		{
			set_bit(TCCR0,3);
			set_bit(TCCR0,6);
			if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_NORMAL)
			{
				//comp00 4
				//comp01 5
				clr_bit(TCCR0,4);
				clr_bit(TCCR0,5);
			}
			else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_TOGGLE)
			{
				set_bit(TCCR0,4);
				clr_bit(TCCR0,5);
			}
			else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_CLR)
			{
				set_bit(TCCR0,5);
				clr_bit(TCCR0,4);
			}
			else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_SET)
			{
				set_bit(TCCR0,4);
				set_bit(TCCR0,5);
			}
// 			else{
// 				#error "Wrong Timer Comparetor Mode"
// 			}
		}
// 		else{
// 			#error "Wrong Timer Mode Selected"
// 		}
	} 
	else if (TimerC -> TimerSelect == TIMER1)
	{
		
		if (TimerC -> TimerMode == TIMER_NORMAL_MODE)
		{
			set_bit(TIMSK,2);
			TCCR1A = 0X00;
			
		}
		else if (TimerC -> TimerMode == TIMER_CTC_MODE)
		{
			set_bit(TIMSK,5);
			
	
		}
		else if (TimerC -> TimerMode == TIMER_PHASE_CORRECT_8BIT_PWM_MODE)
		{
			set_bit(TCCR1A,0);
			if (TimerC -> TimerCompSelect  == TIMER1_COMPARETOR_A)
			{
				if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_NORMAL)
				{
					clr_bit(TCCR1A,4);
					clr_bit(TCCR1A,5);
				}
				else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_TOGGLE)
				{
					set_bit(TCCR1A,4);
					clr_bit(TCCR1A,5);
				}
				else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_CLR)
				{
					set_bit(TCCR1A,5);
					clr_bit(TCCR1A,4);
				}
				else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_SET)
				{
					set_bit(TCCR1A,4);
					set_bit(TCCR1A,5);
				}
// 				else{
// 					#error "Wrong Timer Comparetor Mode"
// 				}
			}
			else if (TimerC -> TimerCompSelect  == TIMER1_COMPARETOR_B)
			{
				if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_NORMAL)
				{
					clr_bit(TCCR1A,6);
					clr_bit(TCCR1A,7);
				}
				else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_TOGGLE)
				{
					set_bit(TCCR1A,6);
					clr_bit(TCCR1A,7);
				}
				else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_CLR)
				{
					set_bit(TCCR1A,7);
					clr_bit(TCCR1A,6);
				}
				else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_SET)
				{
					set_bit(TCCR1A,6);
					set_bit(TCCR1A,7);
				}
				
// 				else{
// 					#error "Wrong Timer Comparetor Mode"
// 				}
			}
// 			else{
// 				#error "Wrong Timer Comparetor Selected"
// 			}	
		}
		else if (TimerC -> TimerMode == TIMER_FAST_PWM_MODE)
		{
			set_bit(TCCR1A,0);
			clr_bit(TCCR1A,1);
			set_bit(TCCR1B,3);
			if (TimerC -> TimerCompSelect  == TIMER1_COMPARETOR_A)
			{
				if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_NORMAL)
				{
					clr_bit(TCCR1A,4);
					clr_bit(TCCR1A,5);
				}
				else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_TOGGLE)
				{
					set_bit(TCCR1A,4);
					clr_bit(TCCR1A,5);
				}
				else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_CLR)
				{
					set_bit(TCCR1A,5);
					clr_bit(TCCR1A,4);
				}
				else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_SET)
				{
					set_bit(TCCR1A,4);
					set_bit(TCCR1A,5);
				}
			//	else{
// 					#error "Wrong Timer Comparetor Mode"
// 				}
				}
				else if (TimerC -> TimerCompSelect  == TIMER1_COMPARETOR_B)
				{
					if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_NORMAL)
					{
						clr_bit(TCCR1A,6);
						clr_bit(TCCR1A,7);
					}
					else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_TOGGLE)
					{
						set_bit(TCCR1A,6);
						clr_bit(TCCR1A,7);
					}
					else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_CLR)
					{
						set_bit(TCCR1A,7);
						clr_bit(TCCR1A,6);
					}
					else if (TimerC -> TimerCompMode  == TIMER_COMPARETOR_SET)
					{
						set_bit(TCCR1A,6);
						set_bit(TCCR1A,7);
					}
// 				else{
// 					#error "Wrong Timer Comparetor Mode"
	// 				}
		}
		
// 			else{
// 				#error "Wrong Timer Comparetor Selected"
	// 			}
		}
// 		else{
// 			#error "Wrong Timer Mode Selected"
// 		}
	}
// 	else{
// 		#error "Wrong Timer Selected"
// 	}
	
}

void Timer_Start(TimerControl* TimerC)
{
	if (TimerC -> TimerSelect == TIMER0){
		if (TimerC -> TimerPrescaler == TimerPrescaler_0)
		{
			set_bit(TCCR0,0);
			clr_bit(TCCR0,1);
			clr_bit(TCCR0,2);
		}
		else if (TimerC -> TimerPrescaler == TimerPrescaler_8)
		{
			clr_bit(TCCR0,0);
			set_bit(TCCR0,1);
			clr_bit(TCCR0,2);
		}
		
		else if (TimerC -> TimerPrescaler == TimerPrescaler_64)
		{
			set_bit(TCCR0,0);
			set_bit(TCCR0,1);
			clr_bit(TCCR0,2);
		}
		else if (TimerC -> TimerPrescaler == TimerPrescaler_256)
		{
			clr_bit(TCCR0,0);
			clr_bit(TCCR0,1);
			set_bit(TCCR0,2);
		}
		else if (TimerC -> TimerPrescaler == TimerPrescaler_1024)
		{
			set_bit(TCCR0,0);
			clr_bit(TCCR0,1);
			set_bit(TCCR0,2);
		}
// 		else{
// 			#error "Wrong Timer Prescaler Selected"
// 		}
	}
	else if (TimerC -> TimerSelect == TIMER1)
	{
		if (TimerC -> TimerPrescaler == TimerPrescaler_0)
		{
			set_bit(TCCR1B,0);
			clr_bit(TCCR1B,1);
			clr_bit(TCCR1B,2);
		}
		else if (TimerC -> TimerPrescaler == TimerPrescaler_8)
		{		
			clr_bit(TCCR1B,0);
			set_bit(TCCR1B,1);
			clr_bit(TCCR1B,2);
		}
		else if (TimerC -> TimerPrescaler == TimerPrescaler_64)
		{
			set_bit(TCCR1B,0);
			set_bit(TCCR1B,1);
			clr_bit(TCCR1B,2);
		}
		else if (TimerC -> TimerPrescaler == TimerPrescaler_256)
		{
			clr_bit(TCCR1B,0);
			clr_bit(TCCR1B,1);
			set_bit(TCCR1B,2);
		}
		else if (TimerC -> TimerPrescaler == TimerPrescaler_1024)
		{
			set_bit(TCCR1B,0);
			clr_bit(TCCR1B,1);
			set_bit(TCCR1B,2);
		}
// 		else{
// 			#error "Wrong Timer Prescaler Selected"
// 		}
	}
	
}

void Timer_Stop(TimerControl* TimerC)
{
	if (TimerC -> TimerSelect == TIMER0){
		clr_bit(TCCR0,0);
		clr_bit(TCCR0,1);
		clr_bit(TCCR0,2);
	}
	else if (TimerC -> TimerSelect == TIMER1){
		clr_bit(TCCR1B,0);
		clr_bit(TCCR1B,1);
		clr_bit(TCCR1B,2);
	}
	else if (TimerC -> TimerSelect == TIMER2){
		clr_bit(TCCR2,0);
		clr_bit(TCCR2,1);
		clr_bit(TCCR2,2);
	}
}

void Timer_SetDelay(TimerControl* TimerC,Uint32 Delay_Ms)
{
	Uint32 Tick_Time = ((Uint16) (TimerC -> TimerPrescaler) / (Uint16) F_CPU);
	
	Uint32 Total_Ticks = (Delay_Ms * 1000) / Tick_Time ;
	
	 N_OVFlows = Total_Ticks / 256;
	
	 Init_Value = 256 - (Total_Ticks % 256);
	
	TCCR0 = Init_Value;
	
	N_OVFlows++;
}
void Timer_SetINTERUPPT(TimerControl* TimerC,Uint32 InterruptSelect)
{
	if (TimerC -> TimerSelect == TIMER1)
	{
		if (TimerC -> TimerInterruptSelect == TIMER1_Input_Capture_Interrupt_En)
		{
			set_bit(TIMSK,5);
		} 
		else if (TimerC -> TimerInterruptSelect == TIMER1_Output_CompareA_Match_Interrupt_En)
		{
			set_bit(TIMSK,4);
		}
		else if (TimerC -> TimerInterruptSelect == TIMER1_Output_CompareB_Match_Interrupt_En)
		{
			set_bit(TIMSK,3);
		}
		else if (TimerC -> TimerInterruptSelect == TIMER1_Overflow_Interrupt_Enable)
		{
			set_bit(TIMSK,2);
		}
	} 

}
void Timer_SetRisingFallingEdge(TimerControl* TimerC,Uint8 Rising_Falling)
{
	if (TimerC -> TimerSelect == TIMER1)
	{
		set_bit(TCCR1B,Rising_Falling);	
	}

}

void Timer_ClearFlage(TimerControl* TimerC,Uint8 Flag)
{
	if (TimerC -> TimerSelect == TIMER1)
	{
		if (Flag == TIMER_ICP_FALG)
		{
			set_bit(TIFR ,5);
		}
		else if (Flag == TIMER_OVERFLOW_FALG)
		{
			set_bit(TIFR ,2);
		}
	}
}

void SetCallBack(TimerControl* TimerC,void (*P_Fn)(void))
{
	GlobalP_Fn = P_Fn;
}
// ISR(TIMER0_OVF_vect)
// {
// 	static Uint32 cnt = 0;
// 	
// 	cnt++;
// 	
// 	if(cnt == N_OVFlows)
// 	{
// 		TCNT0 = Init_Value;
// 		GlobalP_Fn() ;
// 		cnt = 0;
// 	}
// }