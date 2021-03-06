#ifndef __AS608_H
#define __AS608_H
#include <stdio.h>
//#include "stm32f4xx.h"  

typedef uint64_t  u64;
typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

#define PS_Sta   PAin(6)//读指纹模块状态引脚
#define CharBuffer1 0x01
#define CharBuffer2 0x02
#define CharBuffer3 0x03

#define ZW_TBL_IDX0 0
#define ZW_TBL_IDX1 1

extern u32 AS608Addr;//模块地址

typedef struct  
{
	u16 pageID;//指纹ID
	u16 mathscore;//匹配得分
}SearchResult;

typedef struct
{
	u16 PS_max;//指纹最大容量
	u8  PS_level;//安全等级
	u32 PS_addr;
	u8  PS_size;//通讯数据包大小
	u8  PS_N;//波特率基数N
}SysPara;

//void PS_StaGPIO_Init(void);//初始化PA6读状态引脚
	
u8 PS_GetImage(void); //录入图像 
 
u8 PS_GenChar(u8 BufferID);//生成特征 

u8 PS_Match(void);//精确比对两枚指纹特征 

u8 PS_Search(u8 BufferID,u16 StartPage,u16 PageNum,SearchResult *p);//搜索指纹 
 
u8 PS_RegModel(void);//合并特征（生成模板） 
 
u8 PS_StoreChar(u8 BufferID,u16 PageID);//储存模板 

u8 PS_DeletChar(u16 PageID,u16 N);//删除模板 

u8 PS_Empty(void);//清空指纹库 

u8 PS_WriteReg(u8 RegNum,u8 DATA);//写系统寄存器 
 
u8 PS_ReadSysPara(SysPara *p); //读系统基本参数 

u8 PS_SetAddr(u32 addr);  //设置模块地址 

u8 PS_WriteNotepad(u8 NotePageNum,u8 *content);//写记事本 

u8 PS_ReadNotepad(u8 NotePageNum,u8 *note);//读记事 

u8 PS_ReadIndexTable(u8 NotePageNum,u8 *Byte32);//读索引表,add

u8 PS_HighSpeedSearch(u8 BufferID,u16 StartPage,u16 PageNum,SearchResult *p);//高速搜索 
  
u8 PS_ValidTempleteNum(u16 *ValidN);//读有效模板个数 

u8 PS_HandShake(u32 *PS_Addr); //与AS608模块握手

const char *EnsureMessage(u8 ensure);//确认码错误信息解析


extern void log_release(void);
extern void send_cmd_to_lcd_pic(uint16_t temp);
extern void re_smartconfig_wifi(void);

extern void delay_ms(u16 nms);
extern uint8_t flag_rx2;

extern uint8_t data_rx2_m[];
extern int len_rx2_m;

// extern uint8_t data_rx2[];
// extern int len_rx2;

// extern const char *TAG ;




#define UART_NUM_LCD UART_NUM_1
#define UART_NUM_2G UART_NUM_0//tmp
#define UART_NUM_ZHIWEN UART_NUM_2
#define UART_NUM_LOCK UART_NUM_0
// #define UART_NUM_LOCK SOFTWARE_UART_NUM_3     uartlock_output

#define UART_NUM_DUBUG UART_NUM_0

//ESP_LOGI(TAG,"--------JudgeStr err--------!!!\r\n");
// int	_EXFUN(printf, (const char *__restrict, ...)
//                _ATTRIBUTE ((__format__ (__printf__, 1, 2))));

// #define __DEBUG__  
// #ifdef __DEBUG__  
// #define debug_print(format,...) printf("File: "__FILE__", Line: %05d: "format"/n", __LINE__, ##__VA_ARGS__)  
// #else  
// #define DEBUG(format,...)  
// #endif  

#define BAUD_RATE_DB 115200
#define BAUD_RATE_RL 115200
//9600


//for main debug, 0 or 1
#define _DEBUG_ 1
#if _DEBUG_
#define DB_PR(...) printf(__VA_ARGS__)
#else
#define DB_PR(...) 
#endif


//for key press 10ci debug,    1
#define _DEBUG2_ 1
#if _DEBUG2_
#define DB_PR2(...) printf(__VA_ARGS__)
#else
#define DB_PR2(...) 
#endif


//for 2G debug,   1
#define _DEBUG3_ 1
#if _DEBUG3_
#define DB_PR3(...) printf(__VA_ARGS__)
#else
#define DB_PR3(...) 
#endif



#endif

