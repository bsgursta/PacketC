/* Macros */
#define SPI_CPHA_FIRST_CLOCK  (0U)
#define SPI_CPHA_SECOND_CLOCK (1U)

#define SPI_CPOL_ZERO_IDLE  (0U)
#define SPI_CPOL_ONE_IDLE   (1U)

#define SPI_MSTR_SLAVECONF  (0U)
#define SPI_MSTR_MASTERCONF (1U)

#define SPI_ENABLE  (1U)
#define SPI_DISABLE (0U)

#define SPI_BR_PRE2 (000U)
#define SPI_BR_PRE4 (001U)
#define SPI_BR_PRE8 (010U)
#define SPI_BR_PRE16 (011U)
#define SPI_BR_PRE32 (100U)
#define SPI_BR_PRE64 (101U)
#define SPI_BR_PRE128 (110U)
#define SPI_BR_PRE256 (111U)

#define SPI_SPE_DISABLE (0U)
#define SPI_SPE_ENABLE (1U)

#define SPI_LSBFIRST_MSB (0U)
#define SPI_LSBFIRST_LSB (1U)

#define SPI_SSM_DISABLE (0U)
#define SPI_SSM_ENABLE (1U)

#define SPI_RXONLY_FULL (0U)
#define SPI_RXONLY_EN (1U)

#define SPI_CRCL_LEN8 (0U)
#define SPI_CRCL_LEN16 (1U)

#define SPI_CRCNEXT_TXBUF (0U)
#define SPI_CRCNEXT_CRCREG (1U)

#define SPI_CRCEN_DISABLE (0U)
#define SPI_CRCEN_ENABLE (1U)

#define SPI_BIDIOE_RXONLY (0U)
#define SPI_BIDIOE_TXONLY (1U)

#define SPI_BIDIMODE_2LINEUNI (0U)
#define SPI_BIDIMODE_1LINEBI (1U)



/* SPIx_CR1 */
StatusType spiCPHAset();
StatusType spiCPOLset();
StatusType spiMSTRset();
StatusType spiBRset();
StatusType spiSPEset();
StatusType spiLSBFIRSTset();
StatusType spiRXONLYset();
StatusType spiCRCLset();
StatusType spiCRCNEXTset();
StatusType spiCRCENset();
StatusType spiBIDIOEset();
StatusType spiBIDIMODEset();

/* SPIx_CR2 */
StatusType spiRXDMAENset();
StatusType spiTXMAENset();
StatusType spiSSOEset();
StatusType spiNSSPset();
StatusType spiFRFset();
StatusType spiERRIEset();
StatusType spiRXNEIEset();
StatusType spiTXEIEset();
StatusType spiDSset();
StatusType spiFRXTHset();
StatusType spiLDMA_RXset();
StatusType spiLDMA_TXset();

/* SPIx_SR */

StatusType spiRXNEread();
StatusType spiRXEread();
StatusType spiCHSIDEread();
StatusType spiUDRread();
StatusType spiCRCERRread();
StatusType spiMODFread();
StatusType spiOVRread();
StatusType spiBSYread();
StatusType spiFREread();
StatusType spiFRLVLread();
StatusType spiFTLVLread();

/* SPIx_I2SCFGR*/
StatusType spiCHLENset();
StatusType spiDATLENset();
StatusType spiCKPOLset();
StatusType spiI2SSTDset();
StatusType spiPCMSYNCset();
StatusType spiI2SCFGset();
StatusType spiI2SEset();
StatusType spiI2SMODset();
StatusType spiASTRTENset();

/* SPIx_I2SPR */
StatusType spiI2SDIVset();
StatusType spiODDset();
StatusType spiMCKOEset();