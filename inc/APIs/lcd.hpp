#pragma once

#include "macros.hpp"

//4-wire SPI

StatusType lcd_4SPI_init(void);
StatusType lcd_reset(void);

StatusType lcd_transfer(uint8_t data);

StatusType  clearLCD(void);
StatusType  fillLCD(void);

StatusType  onLCD(void);
StatusType  lcd_ALLpixels(void);
StatusType  offLCD(void);
StatusType  lcd_RAMpixels(void);

StatusType  lcd_setcolumn_address(int column_num);
StatusType  lcd_setpage_address(int page_num);

StatusType setPageaddressing(void);
StatusType setVerticaladdressing(void);

StatusType lcd_writeRAM(uint8_t data);

//printing commands
StatusType lcd_printHELLO(void);

