#include "macros.hpp"
#include "spi.hpp"
#include "stm32f767xx.h"

//Steps

// 1) Set GPIO registers 2) Write to SPI_CR1 register 3) Write to SPI_CR2 register 4) Write to CRCPR register 5) Configure DMA

/*
    SPIx_CR1

    spiCPHAset() -> sets whether the data is captured at the first or second clock edge
    spiCPOLset() -> sets the clock idle value
    spiMSTRset() -> sets spi peripheral to either master or slave
    spiBRset() -> sets the Baud Rate for spi peripheral
    spiSPEset() -> enables the SPI peripheral
    spiLSBFIRSTset() -> RX/TX with LSB or MSB first
    spiRXONLYset() -> master to receive only
    spiCRCLset() -> sets the CRC length, 8 OR 16 bit
    spiCRCNEXTset() -> ???
    spiCRCENset() -> enable/disable CRC calculation
    spiBIDIOEset() -> 
    spiBIDIMODEset() ->
*/
StatusType spiCPHAset() {

}

StatusType spiCPOLset() {

}

StatusType spiMSTRset() {

}

StatusType spiBRset() {

}

StatusType spiSPEset() {

}

StatusType spiLSBFIRSTset() {

}

StatusType spiRXONLYset() {

}

StatusType spiCRCLset() {

}

StatusType spiCRCNEXTset() {

}

StatusType spiCRCENset() {

}

StatusType spiBIDIOEset() {

}

StatusType spiBIDIMODEset() {

}

/*
    SPIx_CR2 Register

*/
StatusType spiRXDMAENset() {

}

StatusType spiTXMAENset() {

}

StatusType spiSSOEset() {

}

StatusType spiNSSPset() {

}

StatusType spiFRFset() {

}

StatusType spiERRIEset() {

}

StatusType spiRXNEIEset() {

}

StatusType spiTXEIEset() {

}

StatusType spiDSset() {

}

StatusType spiFRXTHset() {

}

StatusType spiLDMA_RXset() {

}

StatusType spiLDMA_TXset() {

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