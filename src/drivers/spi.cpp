#include "macros.hpp"
#include "spi.hpp"
#include "stm32f767xx.h"

/* File contains the function implementations for SPI/I2S registers */

/* Check which port is being used and get the current value */
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

bool checkBinary(uint8_t number) {
    if(number == 1 || number == 0) {
        return true;
    }
    return false;
}

//Steps

// 1) Set GPIO registers 2) Write to SPI_CR1 register 3) Write to SPI_CR2 register 4) Write to CRCPR register 5) Configure DMA

/* SPIx_CR1 */

//sets whether the data is captured at the first or second clock edge 
StatusType spiCPHAset(SPI_TypeDef* spi_mod, uint8_t edge) {
    if(!checkBinary(edge)) return STATUS_ERR;
    spi_mod -> CR1 |= (edge << 0);
    return STATUS_OK;
}

//sets the clock idle value
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

StatusType spiRXNEread() {

}
StatusType spiRXEread() {
    
}
StatusType spiCHSIDEread() {
    
}
StatusType spiUDRread() {
    
}
StatusType spiCRCERRread() {
    
}
StatusType spiMODFread() {
    
}
StatusType spiOVRread() {
    
}
StatusType spiBSYread() {
    
}
StatusType spiFREread() {
    
}
StatusType spiFRLVLread() {
    
}
StatusType spiFTLVLread() {
    
}

/* 
SPIx_I2SCFGR
*/

StatusType spiCHLENset() {

}

StatusType spiDATLENset() {

}

StatusType spiCKPOLset() {

}

StatusType spiI2SSTDset() {

}

StatusType spiPCMSYNCset() {

}

StatusType spiI2SCFGset() {
    
}

StatusType spiI2SEset() {

}

StatusType spiI2SMODset() {

}

StatusType spiASTRTENset() {

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