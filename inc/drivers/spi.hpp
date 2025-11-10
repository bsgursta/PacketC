#pragma once

/* SPI Macros */
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
StatusType spiCPHAset(SPI_TypeDef* spi_mod, uint8_t edge);
StatusType spiCPOLset(SPI_TypeDef* spi_mod, uint8_t clk_pol);
StatusType spiMSTRset(SPI_TypeDef* spi_mod, uint8_t mst_set);
StatusType spiBRset(SPI_TypeDef* spi_mod, uint8_t baud_rate );
StatusType spiSPEset(SPI_TypeDef* spi_mod, uint8_t state);
StatusType spiLSBFIRSTset(SPI_TypeDef* spi_mod, uint8_t format);
StatusType spiSSMset(SPI_TypeDef* spi_mod, uint8_t state);
StatusType spiRXONLYset(SPI_TypeDef* spi_mod, uint8_t mode) ;
StatusType spiCRCLset(SPI_TypeDef* spi_mod, uint8_t length);
StatusType spiCRCNEXTset(SPI_TypeDef* spi_mod, uint8_t next);
StatusType spiCRCENset(SPI_TypeDef* spi_mod, uint8_t value);
StatusType spiBIDIOEset(SPI_TypeDef* spi_mod, uint8_t calc);
StatusType spiBIDIMODEset(SPI_TypeDef* spi_mod, uint8_t mode);

/* SPIx_CR2 */
StatusType spiRXDMAENset(SPI_TypeDef* spi_mod, uint8_t en);
StatusType spiTXMAENset(SPI_TypeDef* spi_mod, uint8_t en);
StatusType spiSSOEset(SPI_TypeDef* spi_mod, uint8_t en);
StatusType spiNSSPset(SPI_TypeDef* spi_mod, uint8_t pulse);
StatusType spiFRFset(SPI_TypeDef* spi_mod, uint8_t format);
StatusType spiERRIEset(SPI_TypeDef* spi_mod, uint8_t en_int);
StatusType spiRXNEIEset(SPI_TypeDef* spi_mod, uint8_t en) ;
StatusType spiTXEIEset(SPI_TypeDef* spi_mod, uint8_t en);
StatusType spiDSset(SPI_TypeDef* spi_mod, uint8_t size);
StatusType spiFRXTHset(SPI_TypeDef* spi_mod, uint8_t thresh);
StatusType spiLDMA_RXset(SPI_TypeDef* spi_mod, uint8_t type);
StatusType spiLDMA_TXset(SPI_TypeDef* spi_mod, uint8_t type);

/* SPIx_SR */

bool spiRXNE_bufferEmpty(SPI_TypeDef* spi_mod);
bool spiTXNE_bufferEmpty(SPI_TypeDef* spi_mod);
int spiCHSIDEread(SPI_TypeDef* spi_mod);
bool spiUDR_underOccur(SPI_TypeDef* spi_mod);
bool spiCRCERR_matches(SPI_TypeDef* spi_mod);
bool spiMODF_faultOccured(SPI_TypeDef* spi_mod);
bool spiOVRflag(SPI_TypeDef* spi_mod);
bool spiBSYflag(SPI_TypeDef* spi_mod); 
bool spiFREflag(SPI_TypeDef* spi_mod);
int spiFRLVLread(SPI_TypeDef* spi_mod);
StatusType spiFTLVLread(SPI_TypeDef* spi_mod);

/* SPIx_DR -> Data Register */
uint16_t getSPIDRval(SPI_TypeDef* spi_mod);

/*  SPIx_CRCPR -> CRC Register */
uint16_t getCRCval(SPI_TypeDef* spi_mod);

/*  SPIx_RXCRCR -> CRC Value */
uint16_t getCRCvalRX(SPI_TypeDef* spi_mod);

/*  SPIx_TXCRCR -> CRC Value */

uint16_t getCRCvalTX(SPI_TypeDef* spi_mod);

/* I2S Macros */
#define I2S_CHLEN_16BIT (0U)
#define I2S_CHLEN_32BIT (1U)

#define I2S_DATLEN_16BIT (00U)
#define I2S_DATLEN_24BIT (01U)
#define I2S_DATLEN_32BIT (10U)
#define I2S_DATLEN_NA    (11U)

#define I2S_CKPOL_LOW   (0U)
#define I2S_CKPOL_HIGH  (1U)

#define I2S_I2SSTD_PHILIP   (00U)
#define I2S_I2SSTD_MSBJ     (01U)
#define I2S_I2SSTD_LSBJ     (10U)
#define I2S_I2SSTD_PCM      (11U)

#define I2S_PCMSYNC_SHORTF  (0U)
#define I2S_PCMSYNC_LONGF   (1U)

#define I2S_I2SCFG_SLAVE_TX  (00U)
#define I2S_I2SCFG_SLAVE_RX  (01U)
#define I2S_I2SCFG_MASTER_TX (10U)
#define I2S_I2SCFG_MASTER_RX (11U)

#define I2S_I2SE_ENABLE  (0U)
#define I2S_I2SE_DISABLE (1U)

#define I2S_I2SMOD_SPI  (0U)
#define I2S_I2SMOD_I2S  (1U)

#define I2S_ASTRTEN_ASYNC_OFF   (0U)
#define I2S_ASTRTEN_ASYNCH_ON   (1U)

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