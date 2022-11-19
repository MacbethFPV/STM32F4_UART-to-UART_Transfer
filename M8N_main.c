/* M8N GPS CODE*/

/*------PRIVATE TYPEDEF------*/
int _write(int file, char* p, int len)
{
	for(int i=0;i<len;i++)
	{
		LL_USART_TransmitData8(USART1, *(p+i));
		HAL_Delay(1);
	}
	return len;
}

/*------PRIVATE VARIABLES------*/
extern uint8_t uart1_rx_data;
extern uint8_t uart1_rx_flag;

extern uint8_t uart6_rx_data;
extern uint8_t uart6_rx_flag;

int main(void)
{

	LL_USART_EnableIT_RXNE(USART1);		// STM32 Nucleo <-> PC
	LL_USART_EnableIT_RXNE(USART6);		// M8N GPS <-> STM32 Nucleo

	while(1)
	{

	}
}
