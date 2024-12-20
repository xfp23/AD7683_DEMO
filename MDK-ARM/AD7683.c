#include "AD7683.h"
#include "spi.h"


/*******************************************************************************
 * Name            : AD7683_getADC
 * Syntax          : AD7683_getADC()
 * Parameters(reg) : 读取AD7683的转换结果
 * Parameters(none): --
 * Return value    : AD值
 * Description     : 
 * Date            : 2024/12/12
 *******************************************************************************/
uint16_t AD7683_getADC()
{
    uint8_t bytes[3] = {0};
	CS_LOW();
#if DMA_ENABLE
    HAL_SPI_Receive_DMA(AD7683_SPI, bytes, 3);
#else
    HAL_SPI_Receive(AD7683_SPI, bytes, 3, TIMEOUT);
#endif
	CS_HIGH();
    bytes[0] &= 0x03;  //按照时序保留最后两个字节
    bytes[1] &= 0xFF;  //按照时序保留中间所有字节
    bytes[2] &= 0xFC;   //按照时序清除最后两个字节
    uint32_t result = ((uint16_t)bytes[0] << 14) | ((uint16_t)bytes[1] << 6) | (bytes[2] >> 2);
    return (uint16_t)result;
}


