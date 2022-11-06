/*------PRIVATE VARIABLES-----*/
uint8_t uart1_rx_data = 0;
uint8_t uart1_rx_flag = 0;

uint8_t uart6_rx_data = 0;
uint8_t uart6_rx_data = 0;

/*------PERIPHERAL INTERRUPT HANDLERS------*/
void USART1_IRQHandler(void)
{
	if(LL_USART_IsActiveFlag_RXNE(USART1))
	{
		LL_USART_ClearFlag_RXNE(USART1);
		uart1_rx_data = LL_USART_ReceiveData8(USART1);
		uart1_rx_flag = 1;

		LL_USART_TransmitData8(USART6, uart1_rx_data);
	}
}

void USART6_IRQHandler(void)
{
	if (LL_USART_IsActiveFlag_RXNE(USART6))
	{
		LL_USART_ClearFlag_RXNE(USART6);
		uart6_rx_data = LL_USART_ReceiveData8(USART6);
		uart6_rx_flag = 1;

		LL_USART_TransmitData8(USART1, uart6_rx_data);
	}
}