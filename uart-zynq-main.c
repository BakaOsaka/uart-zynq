/*
 *  uart-zynq-main.c
 *
 *  Simple test for uart-zynq driver
 *
 *  2017.05.23 Created
 *
 */

#include "uart-zynq.h"

/*---------------------------------------------------------------------------
** Entry conditions:    None.
**
** Exit conditions:     None.
**
** Purpose:             Entry point to the application.
**
** Parameters:          Void.
**
** Returns:             Void.
**
** Notes:
*/
void c_entry() 
{
  char ch[6] = "R:  ";
  uart_initialise();

  /*
   * Test the UART by sending a range of characters.
   */
  write_uart_string(UART2_BASE,
  "Hello, world!\r\n"
  "1234567890\r\n"
  "the quick brown fox jumps over the lazy dog\r\n"
  "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG\r\n");
  while(1)
  {
    /*
     * Read the character, and then
     * print out with formatter.
     */
    ch[3] = read_uart_char(UART2_BASE);
    write_uart_string(UART2_BASE, ch);
    write_uart_char(UART2_BASE, '\r');
  }
}
