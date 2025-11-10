#include "macros.hpp"
#include "spi.hpp"
#include "stm32f767xx.h"
#include <stdint.h>

/* File contains the function implementations for SPI/I2S registers */

/*
/ Check which port is being used and get the current value
uint32_t getSPIClockFreq(SPI_TypeDef *port) {
    //Default clock HSI is 16 MHz

    //APB2 Clock -> High Speed
    if(port == SPI1 || port == SPI4 || port == SPI5 || port == SPI6) {
        
    }
    //APB1 Clock -> Low Speed
    else if( port == SPI3 || port == SPI2) {

    }
    else {

    }

}
*/

//Steps

// 1) Set GPIO registers 2) Write to SPI_CR1 register 3) Write to SPI_CR2 register 4) Write to CRCPR register 5) Configure DMA


/* SPIx_CR1 */

//Sets whether the data is captured at the first or second clock edge 
StatusType spiCPHAset(SPI_TypeDef* spi_mod, uint8_t edge) {
    if(!checkBinary(edge)) return STATUS_ERR;
    spi_mod -> CR1 |= (edge << 0);
    return STATUS_OK;
}

//Sets the clock idle logic
StatusType spiCPOLset(SPI_TypeDef* spi_mod, uint8_t clk_pol) {
    if(!checkBinary(clk_pol)) return STATUS_ERR;
    spi_mod -> CR1 |= (clk_pol << 1);
    return STATUS_OK;
}

//sets spi peripheral to either master or slave
StatusType spiMSTRset(SPI_TypeDef* spi_mod, uint8_t mst_set) {
    if(!checkBinary(mst_set)) return STATUS_ERR;
    spi_mod -> CR1 |= (mst_set << 2);
    return STATUS_OK;
}

//sets the Baud Rate for spi peripheral
StatusType spiBRset(SPI_TypeDef* spi_mod, uint8_t baud_rate ) {
    if(baud_rate >= 8) return STATUS_ERR;
    spi_mod -> CR1 |= (baud_rate << 3);
    return STATUS_OK;
}

//enables the SPI peripheral
StatusType spiSPEset(SPI_TypeDef* spi_mod, uint8_t state) {
    if(!checkBinary(state)) return STATUS_ERR;
    spi_mod -> CR1 |= (state << 6);
    return STATUS_OK;
}

//RX/TX with LSB or MSB first
StatusType spiLSBFIRSTset(SPI_TypeDef* spi_mod, uint8_t format) {
        if(!checkBinary(format)) return STATUS_ERR;
    spi_mod -> CR1 |= (format << 7);
    return STATUS_OK;
}

//master to receive only or full duplex
StatusType spiSSMset(SPI_TypeDef* spi_mod, uint8_t state) {
    if(!checkBinary(state)) return STATUS_ERR;
    spi_mod -> CR1 |= (state << 9);
    return STATUS_OK;
}

//sets the CRC length, 8 OR 16 bit
StatusType spiRXONLYset(SPI_TypeDef* spi_mod, uint8_t mode) {
    if(!checkBinary(mode)) return STATUS_ERR;
    spi_mod -> CR1 |= (mode << 10);
    return STATUS_OK;
}

StatusType spiCRCLset(SPI_TypeDef* spi_mod, uint8_t length) {
    if(!checkBinary(length)) return STATUS_ERR;
    spi_mod -> CR1 |= (length << 11);
    return STATUS_OK;
}

StatusType spiCRCNEXTset(SPI_TypeDef* spi_mod, uint8_t next) {
    if(!checkBinary(next)) return STATUS_ERR;
    spi_mod -> CR1 |= (next << 12);
    return STATUS_OK;
}

//enable/disable CRC calculation
StatusType spiCRCENset(SPI_TypeDef* spi_mod, uint8_t value) {
    if(!checkBinary(value)) return STATUS_ERR;
    spi_mod -> CR1 |= (value << 13);
    return STATUS_OK;
}

StatusType spiBIDIOEset(SPI_TypeDef* spi_mod, uint8_t calc) {
    if(!checkBinary(calc)) return STATUS_ERR;
    spi_mod -> CR1 |= (calc << 14);
    return STATUS_OK;
}

StatusType spiBIDIMODEset(SPI_TypeDef* spi_mod, uint8_t mode) {
    if(!checkBinary(mode)) return STATUS_ERR;
    spi_mod -> CR1 |= (mode << 13);
    return STATUS_OK;
}

/*
    SPIx_CR2 Register

*/
StatusType spiRXDMAENset(SPI_TypeDef* spi_mod, uint8_t en) {
    if(!checkBinary(en)) return STATUS_ERR;
    spi_mod -> CR2 |= (en << 0);
    return STATUS_OK;
}

StatusType spiTXMAENset(SPI_TypeDef* spi_mod, uint8_t en) {
    if(!checkBinary(en)) return STATUS_ERR;
    spi_mod -> CR2 |= (en << 1);
    return STATUS_OK;
}

StatusType spiSSOEset(SPI_TypeDef* spi_mod, uint8_t en) {
    if(!checkBinary(en)) return STATUS_ERR;
    spi_mod -> CR2 |= (en << 2);
    return STATUS_OK;
}

StatusType spiNSSPset(SPI_TypeDef* spi_mod, uint8_t pulse) {
    if(!checkBinary(pulse)) return STATUS_ERR;
    spi_mod -> CR2 |= (pulse << 3);
    return STATUS_OK;
}

StatusType spiFRFset(SPI_TypeDef* spi_mod, uint8_t format) {
    if(!checkBinary(format)) return STATUS_ERR;
    spi_mod -> CR2 |= (format << 4);
    return STATUS_OK;
}

StatusType spiERRIEset(SPI_TypeDef* spi_mod, uint8_t en_int) {
    if(!checkBinary(en_int)) return STATUS_ERR;
    spi_mod -> CR2 |= (en_int << 5);
    return STATUS_OK;
}

StatusType spiRXNEIEset(SPI_TypeDef* spi_mod, uint8_t en) {
    if(!checkBinary(en)) return STATUS_ERR;
    spi_mod -> CR2 |= (en << 6);
    return STATUS_OK;
}

StatusType spiTXEIEset(SPI_TypeDef* spi_mod, uint8_t en) {
    if(!checkBinary(en)) return STATUS_ERR;
    spi_mod -> CR2 |= (en << 7);
    return STATUS_OK;
}

StatusType spiDSset(SPI_TypeDef* spi_mod, uint8_t size) {
    if(size >= 16 ) return STATUS_ERR;
    spi_mod -> CR2 |= (size << 8);
    return STATUS_OK;
}

StatusType spiFRXTHset(SPI_TypeDef* spi_mod, uint8_t thresh) {
    if(!checkBinary(thresh)) return STATUS_ERR;
    spi_mod -> CR2 |= (thresh << 12);
    return STATUS_OK;
}

StatusType spiLDMA_RXset(SPI_TypeDef* spi_mod, uint8_t type) {
    if(!checkBinary(type)) return STATUS_ERR;
    spi_mod -> CR2 |= (type << 13);
    return STATUS_OK;
}

StatusType spiLDMA_TXset(SPI_TypeDef* spi_mod, uint8_t type) {
    if(!checkBinary(type)) return STATUS_ERR;
    spi_mod -> CR2 |= (type << 14);
    return STATUS_OK;
}

/*
    SPIx_SR Register

*/

//Check whether the receive buffer is empty
bool spiRXNE_bufferEmpty(SPI_TypeDef* spi_mod) {
    return !(spi_mod->SR & ( 1 << 0)); 
}

//Check whether the transmit buffer is empty
bool spiTXNE_bufferEmpty(SPI_TypeDef* spi_mod) {
    return !(spi_mod->SR & ( 1 << 1)); 
}

// I2S -> use to determine which side has to be transmitted
/* Return values:   1 -> Right side is ready
                    0 -> Left side is ready
*/
int spiCHSIDEread(SPI_TypeDef* spi_mod) {
    if(spi_mod->SR & ( 1 << 3)) {
        return 1;
    } 
    return 0;
}
//I2S -> check if underrun occured

bool spiUDR_underOccur(SPI_TypeDef* spi_mod) {
    return (spi_mod->SR & ( 1 << 3)); 
}

// CRC value doesn't match the SPIx_CRCR value

//clear with software LATER???

bool spiCRCERR_matches(SPI_TypeDef* spi_mod) {
    return !(spi_mod->SR & ( 1 << 4)); 
}
// Use to check if another devices is attempting to take control of the bus

bool spiMODF_faultOccured(SPI_TypeDef* spi_mod) {
    return (spi_mod->SR & ( 1 << 5)); 
}

//Flag indicates -> new data has been received before the previous data was sent

bool spiOVRflag(SPI_TypeDef* spi_mod) {
    return (spi_mod->SR & ( 1 << 6)); 
}
//Flag indicates that SPI/I2S is busy communicating or TX is not empty

bool spiBSYflag(SPI_TypeDef* spi_mod) {
    return (spi_mod->SR & ( 1 << 7));     
}/* Slave mode flag
    Check if there is a frame format error from receiving data
    1 -> Format Error   0 -> No Format Error
 */
bool spiFREflag(SPI_TypeDef* spi_mod) {
        return (spi_mod->SR & ( 1 << 6)); 
}

//Tells us the capacity of the FIFO which stores reception data
int spiFRLVLread(SPI_TypeDef* spi_mod) {
    
}
//Tells us the current size of the transmission buffer

StatusType spiFTLVLread(SPI_TypeDef* spi_mod) {
    
}

/* SPIx_DR -> Data Register */
uint16_t getSPIDRval(SPI_TypeDef* spi_mod) {
    return (spi_mod->DR & (0xFFFF));
}

/*  SPIx_CRCPR -> CRC Register 
    Default -> 0x0007
*/

uint16_t getCRCval(SPI_TypeDef* spi_mod) {
    return (spi_mod->CRCPR & (0xFFFF));
}

/*  SPIx_RXCRCR -> CRC Value */

uint16_t getCRCvalRX(SPI_TypeDef* spi_mod) {
    return (spi_mod->RXCRCR & (0xFFFF));
}

/*  SPIx_TXCRCR -> CRC Value */

uint16_t getCRCvalTX(SPI_TypeDef* spi_mod) {
    return (spi_mod->TXCRCR & (0xFFFF));
}


/* SPIx_I2SCFGR */

//Set the number of bits per audio channel

StatusType spiCHLENset(SPI_TypeDef* spi_mod) {

}

StatusType spiDATLENset(SPI_TypeDef* spi_mod) {

}

StatusType spiCKPOLset(SPI_TypeDef* spi_mod) {

}

StatusType spiI2SSTDset(SPI_TypeDef* spi_mod) {

}

StatusType spiPCMSYNCset(SPI_TypeDef* spi_mod) {

}

StatusType spiI2SCFGset(SPI_TypeDef* spi_mod) {
    
}

StatusType spiI2SEset(SPI_TypeDef* spi_mod) {

}

StatusType spiI2SMODset(SPI_TypeDef* spi_mod) {

}

StatusType spiASTRTENset(SPI_TypeDef* spi_mod) {

}

/* 
SPIx_I2SPR 
*/

StatusType spiI2SDIVset() {

}

StatusType spiODDset() {

}

StatusType spiMCKOEset() {
    
}