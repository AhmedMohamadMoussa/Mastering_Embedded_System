#include <util/delay.h>
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/EXTERNAL_INTERRUPT/External_INT_interface.h"
#include "../include/MCAL/ADC/ADC_interface.h"
#include "../include/MCAL/GI/GI_interface.h"
#include "../include/MCAL/Timer/Timer_intereface.h"
#include "../include/MCAL/WDT/WDT_interface.h"
#include "../include/MCAL/UART/UART_interface.h"
#define F_cpu 8000000ul
void HSERVO_voidSetAngle (u8 A_u8Angle);
int main(void)
{
	// PIN A0  INPUT-FLOATING for ADC
	// set PD5 to Output-Low to setting pwm
	MDIO_voidInit();
	MTIMER1_voidInit();
	MADC_voidInit();
	u16 local_u16DigitalValue_0 =0,local_u16AnalogSignal_0;
	u16 local_u16DigitalValue_1 =0,local_u16AnalogSignal_1;
	u16 local_u16DigitalValue_2 =0,local_u16AnalogSignal_2;
	u16 local_u16DigitalValue_3 =0,local_u16AnalogSignal_3;
	u16 local_u16DigitalValue_4 =0,local_u16AnalogSignal_4;
	u16 local_u16DigitalValue_5 =0,local_u16AnalogSignal_5;
	u16 local_u16DigitalValue_6 =0,local_u16AnalogSignal_6;
	u16 local_u16DigitalValue_7 =0,local_u16AnalogSignal_7;

	u8 A_u8Angle =90;

	u16 A_u16_array_AnalogSignal[8]={0};

	MUART_voidInit();
	u8 local_u8PressedKeyValue =0;
	MUART_voidSendStringSyncNonBlocking("HELLO, this is automatic tracking system \r\n");
	MUART_voidSendStringSyncNonBlocking("for solar panal by using small LDR \r\n");
	while(1)
	{
		for (int var = 0; var < 30; ++var)
		{
			u16 sum=0;
			local_u16DigitalValue_0 =MADC_u16GetDigitalValue(ADC_0);
			local_u16AnalogSignal_0 =(local_u16DigitalValue_0 * 5000)/1024;
			sum+=local_u16AnalogSignal_0;
			if(var==29)
			{
				sum+=local_u16AnalogSignal_0;
				sum=sum/30;
				local_u16AnalogSignal_0=sum;
				A_u16_array_AnalogSignal[0]=sum;
			}
			//_delay_ms(100);
		}
		/*
		for (int var = 0; var < 30; ++var)
		{
			u16 sum=0;
			local_u16DigitalValue_1 =MADC_u16GetDigitalValue(ADC_1);
			local_u16AnalogSignal_1 =(local_u16DigitalValue_1 * 5000)/1024;
			sum+=local_u16AnalogSignal_1;
			if(var==29)
			{
				sum+=local_u16AnalogSignal_1;
				sum=sum/30;
				local_u16AnalogSignal_1=sum;
				A_u16_array_AnalogSignal[1]=sum;

			}
			//_delay_ms(100);
		}
		*/
		for (int var = 0; var < 30; ++var)
		{
			u16 sum=0;
			local_u16DigitalValue_2 =MADC_u16GetDigitalValue(ADC_2);
			local_u16AnalogSignal_2 =(local_u16DigitalValue_2 * 5000)/1024;
			sum+=local_u16AnalogSignal_2;
			if(var==29)
			{
				sum+=local_u16AnalogSignal_2;
				sum=sum/30;
				local_u16AnalogSignal_2=sum;
				A_u16_array_AnalogSignal[2]=sum;

			}
			//_delay_ms(100);
		}
		/*
		for (int var = 0; var < 30; ++var)
		{
			u16 sum=0;
			local_u16DigitalValue_3 =MADC_u16GetDigitalValue(ADC_3);
			local_u16AnalogSignal_3 =(local_u16DigitalValue_3 * 5000)/1024;
			sum+=local_u16AnalogSignal_3;
			if(var==29)
			{
				sum+=local_u16AnalogSignal_3;
				sum=sum/30;
				local_u16AnalogSignal_3=sum;
				A_u16_array_AnalogSignal[3]=sum;

			}
			//_delay_ms(100);
		}
		*/
		for (int var = 0; var < 30; ++var)
		{
			u16 sum=0;
			local_u16DigitalValue_4 =MADC_u16GetDigitalValue(ADC_4);
			local_u16AnalogSignal_4 =(local_u16DigitalValue_4 * 5000)/1024;
			sum+=local_u16AnalogSignal_4;
			if(var==29)
			{
				sum+=local_u16AnalogSignal_4;
				sum=sum/30;
				local_u16AnalogSignal_4=sum;
				A_u16_array_AnalogSignal[4]=sum;

			}
			//_delay_ms(100);
		}
		/*
		for (int var = 0; var < 30; ++var)
		{
			u16 sum=0;
			local_u16DigitalValue_5 =MADC_u16GetDigitalValue(ADC_5);
			local_u16AnalogSignal_5 =(local_u16DigitalValue_5 * 5000)/1024;
			sum+=local_u16AnalogSignal_5;
			if(var==29)
			{
				sum+=local_u16AnalogSignal_5;
				sum=sum/30;
				local_u16AnalogSignal_5=sum;
				A_u16_array_AnalogSignal[5]=sum;

			}
			//_delay_ms(100);
		}
		*/
		for (int var = 0; var < 30; ++var)
		{
			u16 sum=0;
			local_u16DigitalValue_6 =MADC_u16GetDigitalValue(ADC_6);
			local_u16AnalogSignal_6 =(local_u16DigitalValue_6 * 5000)/1024;
			sum+=local_u16AnalogSignal_6;
			if(var==29)
			{
				sum+=local_u16AnalogSignal_6;
				sum=sum/30;
				local_u16AnalogSignal_6=sum;
				A_u16_array_AnalogSignal[6]=sum;

			}
			//_delay_ms(100);
		}
		/*
		for (int var = 0; var < 30; ++var)
		{
			u16 sum=0;
			local_u16DigitalValue_7 =MADC_u16GetDigitalValue(ADC_7);
			local_u16AnalogSignal_7 =(local_u16DigitalValue_7 * 5000)/1024;
			sum+=local_u16AnalogSignal_7;
			if(var==29)
			{
				sum+=local_u16AnalogSignal_7;
				sum=sum/30;
				local_u16AnalogSignal_7=sum;
				A_u16_array_AnalogSignal[7]=sum;

			}
			//_delay_ms(100);
		}
		 */

		if(local_u16AnalogSignal_0>local_u16AnalogSignal_1 && local_u16AnalogSignal_0>local_u16AnalogSignal_2 && local_u16AnalogSignal_0>local_u16AnalogSignal_3&& local_u16AnalogSignal_0>local_u16AnalogSignal_4&& local_u16AnalogSignal_0>local_u16AnalogSignal_5&& local_u16AnalogSignal_0>local_u16AnalogSignal_6&& local_u16AnalogSignal_0>local_u16AnalogSignal_7 )
		{HSERVO_voidSetAngle(22); MUART_voidSendStringSyncNonBlocking("the angle of solar panel is 22 degree \r\n");}
		//if(local_u16AnalogSignal_1>local_u16AnalogSignal_0 && local_u16AnalogSignal_1>local_u16AnalogSignal_2 && local_u16AnalogSignal_1>local_u16AnalogSignal_3&& local_u16AnalogSignal_1>local_u16AnalogSignal_4&& local_u16AnalogSignal_1>local_u16AnalogSignal_5&& local_u16AnalogSignal_1>local_u16AnalogSignal_6&& local_u16AnalogSignal_1>local_u16AnalogSignal_7 )
		//{HSERVO_voidSetAngle(45); MUART_voidSendStringSyncNonBlocking("the angle of solar panel is 45 degree \r\n");}
		if(local_u16AnalogSignal_2>local_u16AnalogSignal_0 && local_u16AnalogSignal_2>local_u16AnalogSignal_1 && local_u16AnalogSignal_2>local_u16AnalogSignal_3&& local_u16AnalogSignal_2>local_u16AnalogSignal_4&& local_u16AnalogSignal_2>local_u16AnalogSignal_5&& local_u16AnalogSignal_2>local_u16AnalogSignal_6&& local_u16AnalogSignal_2>local_u16AnalogSignal_7 )
		{HSERVO_voidSetAngle(68); MUART_voidSendStringSyncNonBlocking("the angle of solar panel is 68 degree \r\n");}
		//if(local_u16AnalogSignal_3>local_u16AnalogSignal_0 && local_u16AnalogSignal_3>local_u16AnalogSignal_1 && local_u16AnalogSignal_3>local_u16AnalogSignal_2&& local_u16AnalogSignal_3>local_u16AnalogSignal_4&& local_u16AnalogSignal_3>local_u16AnalogSignal_5&& local_u16AnalogSignal_3>local_u16AnalogSignal_6&& local_u16AnalogSignal_3>local_u16AnalogSignal_7 )
		//{HSERVO_voidSetAngle(90); MUART_voidSendStringSyncNonBlocking("the angle of solar panel is 90 degree \r\n");}
		if(local_u16AnalogSignal_4>local_u16AnalogSignal_0 && local_u16AnalogSignal_4>local_u16AnalogSignal_1 && local_u16AnalogSignal_4>local_u16AnalogSignal_2&& local_u16AnalogSignal_4>local_u16AnalogSignal_3&& local_u16AnalogSignal_4>local_u16AnalogSignal_5&& local_u16AnalogSignal_4>local_u16AnalogSignal_6&& local_u16AnalogSignal_4>local_u16AnalogSignal_7 )
		{HSERVO_voidSetAngle(112); MUART_voidSendStringSyncNonBlocking("the angle of solar panel is 112 degree \r\n");}
		//if(local_u16AnalogSignal_5>local_u16AnalogSignal_0 && local_u16AnalogSignal_5>local_u16AnalogSignal_1 && local_u16AnalogSignal_5>local_u16AnalogSignal_2&& local_u16AnalogSignal_5>local_u16AnalogSignal_3&& local_u16AnalogSignal_5>local_u16AnalogSignal_4&& local_u16AnalogSignal_5>local_u16AnalogSignal_6&& local_u16AnalogSignal_5>local_u16AnalogSignal_7 )
		//{HSERVO_voidSetAngle(135); MUART_voidSendStringSyncNonBlocking("the angle of solar panel is 135 degree \r\n");}
		if(local_u16AnalogSignal_6>local_u16AnalogSignal_0 && local_u16AnalogSignal_6>local_u16AnalogSignal_1 && local_u16AnalogSignal_6>local_u16AnalogSignal_2&& local_u16AnalogSignal_6>local_u16AnalogSignal_3&& local_u16AnalogSignal_6>local_u16AnalogSignal_4&& local_u16AnalogSignal_6>local_u16AnalogSignal_5&& local_u16AnalogSignal_6>local_u16AnalogSignal_7 )
		{HSERVO_voidSetAngle(157); MUART_voidSendStringSyncNonBlocking("the angle of solar panel is 157 degree \r\n");}
		//if(local_u16AnalogSignal_7>local_u16AnalogSignal_0 && local_u16AnalogSignal_7>local_u16AnalogSignal_1 && local_u16AnalogSignal_7>local_u16AnalogSignal_2&& local_u16AnalogSignal_7>local_u16AnalogSignal_3&& local_u16AnalogSignal_7>local_u16AnalogSignal_4&& local_u16AnalogSignal_7>local_u16AnalogSignal_5&& local_u16AnalogSignal_7>local_u16AnalogSignal_6 )
		//{HSERVO_voidSetAngle(180); MUART_voidSendStringSyncNonBlocking("the angle of solar panel is 180 degree \r\n");}
	}
	return 0;
}

void HSERVO_voidSetAngle (u8 A_u8Angle)
{
	if (A_u8Angle <= 180)
	{
		u16 local_u16OCRValue = (((A_u8Angle*1000UL)/180) + 999);
		MTIMER1_voidSetOCR1AValue(local_u16OCRValue);//		 MTIMER1_voidSetOCR1AValue(1500);
		_delay_ms (200);
	}
}


