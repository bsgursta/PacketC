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