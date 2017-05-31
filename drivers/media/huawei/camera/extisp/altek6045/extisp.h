
#ifndef _MINI_ISP_H_
#define _MINI_ISP_H_

#include <linux/mutex.h>
#include <linux/semaphore.h>
#include <linux/spi/spi.h>
#include <linux/types.h>
//#include "mini_cam_util.h"


// Camera Profile
#define ISPCMD_CAMERA_GET_SYSTEMINFORMATION			0x3001
#define ISPCMD_CAMERA_SET_BASICPARAMETERS			0x3002
#define ISPCMD_CAMERA_GET_BASICPARAMETERS			0x3003
#define ISPCMD_CAMERA_SET_METERINGAREA				0x3004
#define ISPCMD_CAMERA_GET_METERINGAREA				0x3005
#define ISPCMD_CAMERA_SET_FOCUSAREA					0x3006
#define ISPCMD_CAMERA_GET_FOCUSAREA					0x3007
#define ISPCMD_CAMERA_SET_DIGTIALZOOMLEVEL			0x3008
#define ISPCMD_CAMERA_GET_DIGITALZOOMLEVEL			0x3009
#define ISPCMD_CAMERA_SET_SENSORMODE				0x300A
#define ISPCMD_CAMERA_GET_SENSORMODE				0x300B
#define ISPCMD_CAMERA_SET_SCENEMODE					0x300C
#define ISPCMD_CAMERA_GET_3AINFO					0x3101
#define ISPCMD_CAMERA_GET_MOTIONVECTOR				0x3103
#define ISPCMD_CAMERA_PREVIEWSTREAMONOFF            0x3010
#define ISPCMD_CAMERA_PREVIEWSTREAMOFF				0x3011
#define ISPCMD_CAMERA_STARTVIDEO					0x3020
#define ISPCMD_CAMERA_STOPVIDEO						0x3021
#define ISPCMD_CAMERA_TAKEPICTURES					0x3030
#define ISPCMD_CAMERA_TAKES1LOCK					0x3031
#define ISPCMD_CAMERA_PREVIEW_DISABLE_AE			0x3032
#define ISPCMD_CAMERA_PREVIEW_DISABLE_AF			0x3033
#define ISPCMD_CAMERA_PREVIEW_DISABLE_AWB			0x3034
#define ISPCMD_CAMERA_TAKES1LOCK_ABORT				0x3035
#define ISPCMD_CAMERA_STARTDUALVIDEO				0x3040
#define ISPCMD_CAMERA_STOPDUALVIDEO					0x3041
#define ISPCMD_CAMERA_SET_FAST_SHOT_MODE			0x3042
#define ISPCMD_CAMERA_SET_SENSOR_MODULE_ID			0x3043

// Bulk Data
#define ISPCMD_BULK_WRITE_COMPONENTCODE				0x2000
#define ISPCMD_BULK_READ_COMPONENTCODE				0x2001
#define ISPCMD_BULK_WRITE_BASICCODE					0x2002
#define ISPCMD_BULK_READ_BASICCODE					0x2003
#define ISPCMD_BULK_WRITE_ADVANCEDCODE				0x2004
#define ISPCMD_BULK_READ_ADVANCEDCODE				0x2005
#define ISPCMD_BULK_WRITE_CLIBRATIONDATA			0x2006
#define ISPCMD_BULK_READ_CALIBRATIONDATA			0x2007
#define ISPCMD_BULK_WRITE_BOOTCODE					0X2008
#define ISPCMD_BULK_WRITE_MEMORY					0x2100
#define ISPCMD_BULK_READ_MEMORY						0x2101
#define ISPCMD_BULK_LOG_DUMP						0x2102
#define ISPCMD_BULK_READ_OIS_DATA                   0x2105
#define ISPCMD_BULK_WRITE_OIS_DATA                  0x2106
#define ISPCMD_BULK_WRITE_PDAF_AREA                 0x2107
#define ISPCMD_BULK_GET_OTP_DATA					0x2104
#define ISPCMD_CAMERA_TAKEZSLPICTURES               0x2109
#define ISPCMD_CAMERA_STOPZSLPICTURES               0x210A

#define ISPCMD_GET_BULK_CHIPTEST_REPORT				0x010A
// Basic Setting
#define ISPCMD_BASIC_SET_ANTIFLICKER				0x1010
#define ISPCMD_BASIC_GET_ANTIFLICKER				0x1011
#define ISPCMD_BASIC_SET_AUTOEXPOSURE				0x1012
#define ISPCMD_BASIC_GET_AUTOEXPOSURE				0x1013
#define ISPCMD_BASIC_SET_METERINGAREA				0x1014
#define ISPCMD_BASIC_GET_METERINGAREA				0x1015
#define ISPCMD_BASIC_SET_EXPOSURECOMPENSATION		0x1016
#define ISPCMD_BASIC_GET_EXPOSURECOMPENSATION		0x1017
#define ISPCMD_BASIC_SET_AEMODE						0x1018
#define ISPCMD_BASIC_GET_AEMODE						0x1019
#define ISPCMD_BASIC_SET_BURSTMODE					0x101A
#define ISPCMD_BASIC_SET_AE_OVER_STATE				0x101B
#define ISPCMD_BASIC_SET_AUTOWHITEBALANCE			0x1020
#define ISPCMD_BASIC_GET_AUTOWHITEBALANCE			0x1021
#define ISPCMD_BASIC_SET_WHITEBALANCE				0x1022
#define ISPCMD_BASIC_GET_WHITEBALANCE				0x1023
#define ISPCMD_BASIC_SET_FOCUSMODE					0x1030
#define ISPCMD_BASIC_GET_FOCUSMODE					0x1031
#define ISPCMD_BASIC_SET_FOCUSAREA					0x1032
#define ISPCMD_BASIC_GET_FOCUSAREA					0x1033
#define ISPCMD_BASIC_GET_FOCALLENGTH				0x1034
#define ISPCMD_BASIC_GET_FOCUSDISTANCE				0x1035
#define ISPCMD_BASIC_SET_AFFLASHON					0x1036
#define ISPCMD_BASIC_SET_GSENSOR_INFO				0x1037
#define ISPCMD_BASIC_SET_AFLEVEL					0x1038
#define ISPCMD_BASIC_SET_ISOLEVEL					0x1040
#define ISPCMD_BASIC_GET_ISOLEVEL					0x1041
#define ISPCMD_BASIC_SET_DIGTIALZOOMLEVEL			0x1042
#define ISPCMD_BASIC_GET_DIGITALZOOMLEVEL			0x1043
#define ISPCMD_BASIC_SET_FLASHLIGHTMODE				0x1044
#define ISPCMD_BASIC_GET_FLASHLIGHTMODE				0x1045
#define ISPCMD_BASIC_SET_PREFLASHON					0x1046
#define ISPCMD_BASIC_SET_MAINFLASHENERGY			0x1047
#define ISPCMD_BASIC_SET_SHARPNESS					0x1050
#define ISPCMD_BASIC_GET_SHARPNESS					0x1051
#define ISPCMD_BASIC_SET_CONTRAST					0x1052
#define ISPCMD_BASIC_GET_CONTRAST					0x1053
#define ISPCMD_BASIC_SET_SATURATION					0x1054
#define ISPCMD_BASIC_GET_SATURATION					0x1055
#define ISPCMD_BASIC_SET_DIGITALLIGHTING			0x1056
#define ISPCMD_BASIC_GET_DIGITALLIGHTING			0x1057
#define ISPCMD_BASIC_SET_CAPTURE_MODE				0x1058
#define ISPCMD_BASIC_SET_SCENEMODE					0x1060
#define ISPCMD_BASIC_GET_SCENEMODE					0x1061
#define ISPCMD_BASIC_SET_FACEAREA					0x1062
#define ISPCMD_BASIC_GET_FACEAREA					0x1063
#define ISPCMD_BASIC_SET_PICTUREFORMAT				0x1070
#define ISPCMD_BASIC_GET_PICTUREFORMAT				0x1071
#define ISPCMD_BASIC_SET_PICTURESIZE				0x1072
#define ISPCMD_BASIC_GET_PICTURESIZE				0x1073
#define ISPCMD_BASIC_SET_LIVEVIEWFORMAT				0x1080
#define ISPCMD_BASIC_GET_LIVEVIEWFORMAT				0x1081
#define ISPCMD_BASIC_SET_LIVEVIEWFPSRANGE			0x1082
#define ISPCMD_BASIC_GET_LIVEVIEWFPSRANGE			0x1083
#define ISPCMD_BASIC_SET_LIVEVIEWSIZE				0x1084
#define ISPCMD_BASIC_GET_LIVEVIEWSIZE				0x1085
#define ISPCMD_BASIC_SET_VideoStabilization			0x1090
#define ISPCMD_BASIC_GET_VideoStabilization			0x1091
#define ISPCMD_BASIC_SET_3DNR						0x1092
#define ISPCMD_BASIC_GET_3DNR						0x1093
#define ISPCMD_BASIC_SET_WDR						0x1094
#define ISPCMD_BASIC_GET_WDR						0x1095
#define ISPCMD_BASIC_SET_HDR						0x1096
#define ISPCMD_BASIC_GET_HDR						0x1097
#define ISPCMD_BASIC_SET_SUPERRESOLUTION			0x1098
#define ISPCMD_BASIC_GET_SUPERRESOLUTION			0x1099
#define ISPCMD_BASIC_SET_ZEROSHUTTERLAG				0x109A
#define ISPCMD_BASIC_GET_ZEROSHUTTERLAG				0x109B
#define ISPCMD_BASIC_SET_HISTOGRAM					0x109C
#define ISPCMD_BASIC_GET_HISTOGRAM					0x109E
#define ISPCMD_BASIC_SET_SHUTTERKEY					0x109F
#define ISPCMD_BASIC_TAKE_AE_IMAGE					0x10A0
#define ISPCMD_BASIC_SET_DENOISEMODE                0x10A1
#define ISPCMD_BASIC_HDR_PROCESS					0x10A3
#define ISPCMD_BASIC_SET_S1AF_ENABLE				0x10A4
#define ISPCMD_BASIC_SET_MOTION_DETECTED			0x10A5


// System Management
#define ISPCMD_SYSTEM_GET_FIRMWAREVERSION			0x0001
#define ISPCMD_SYSTEM_GET_CHIPID					0x0003
#define ISPCMD_SYSTEM_GET_FIRSTSENSORID				0x0005
#define ISPCMD_SYSTEM_GET_SECONDSENSORID			0x0007
#define ISPCMD_SYSTEM_CHANGEMODE					0x0010
#define ISPCMD_SYSTEM_GET_STATUSOFMODECHANGE		0x0011
#define ISPCMD_SYSTEM_CAPTUREIMAGES					0x0012
#define ISPCMD_SYSTEM_GET_STATUSOFIMAGECAPTURE		0x0013
#define ISPCMD_SYSTEM_GET_STATUSOFLASTEXECUTEDCOMMAND	0x0015
#define ISPCMD_SYSTEM_GET_ERRORCODE					0x0016
#define ISPCMD_SYSTEM_SET_ISPREGISTER				0x0100
#define ISPCMD_SYSTEM_GET_ISPREGISTER				0x0101
#define ISPCMD_SYSTEM_SET_FIRSTSENSORREGISTER		0x0102
#define ISPCMD_SYSTEM_GET_FIRSTSENSORREGISTER		0x0103
#define ISPCMD_SYSTEM_SET_DEBUGCOMMAND				0x0104
#define ISPCMD_SYSTEM_GET_DEBUGCOMMAND				0x0105
#define ISPCMD_SYSTEM_SET_EXPO_TIME					0x0106
#define ISPCMD_SYSTEM_SET_AD_GAIN					0x0107
#define ISPCMD_SYSTEM_SET_LOG_LEVEL					0x0109

// AL6045 Operation
#define ISPCMD_AL6045_MINIISPOPEN					0x4000
#define ISPCMD_AL6045_ISOAWBCALIBRATION				0x4100
#define ISPCMD_AL6045_TAKEPICSHADING				0x4101


#define FWVER_INFOSIZE_MAX		34
#define AEZONECFG_MAXGROUP		5
#define AFZONECFG_MAXGROUP		5
#define FACEAREACFG_MAXGROUP	6

// Command error code
#define T_ERROR_NO_ERROR							0
#define T_ERROR_FAILURE								0x50
#define T_ERROR_COMMAND_NOT_SUPPORTED				0x51
#define T_ERROR_DATA_INVALID						0x52
#define T_ERROR_DATA_OUT_OF_RANGE					0x53
#define T_ERROR_SYSTEM_ALREADY_IN_STATE				0x54
#define T_ERROR_SYSTEM_IN_INVALIDE_STATE			0x55

//constants for Sensors' control to switch on
#define T_REAR1_SENSOR_ON		0
#define T_REAR2_SENSOR_ON		1
#define T_REAR1_REAR2_SENSOR_ON	2
#define T_FRONT_SENSOR_ON		3
#define T_FRONT_REAR1_SENSOR_ON	4
#define T_FRONT_REAR2_SENSOR_ON	5

//constants for Sensor mode for Sensor mode control
#define T_SENSOR_BINMODE		0
#define T_SENSOR_FRMODE			1
#define T_SENSOR_FRBINMODE		2
#define T_SENSOR_HDMODE			3

//constants for Preview mode for Change mode control
#define T_PREVIEW_TEST			0
#define T_PREVIEW_STILL			1
#define T_PREVIEW_RSVD0			2
#define T_PREVIEW_RSVD1			3
#define T_PREVIEW_BYPASS		4
#define T_PREVIEW_PWRDWN		5

//constants for anti-flicker mode
#define T_FREQ_AUTO				0
#define T_FREQ_OFF				1
#define T_FREQ_50HZ				2
#define T_FREQ_60HZ				3

//constants for auto-exposure mode
#define T_EXP_AUTO				0
#define T_EXP_DISABLE			1

//constants for exposure compensation
#define T_COMPEXPIDX_MIN		0
#define T_COMPEXPIDX_MAX		12
#define T_COMPEXPIDX_DEFAULT	6
#define T_COMPEXPVALUE_MIN		(-2)
#define T_COMPEXPVALUE_MAX		(2)

//constants for white balance
#define T_WB_AUTO				0
#define T_WB_INCANDESCENT		1
#define T_WB_FLUORESCENT		2
#define T_WB_WARM_FLUORESCENT	3
#define T_WB_DAYLIGHT			4
#define T_WB_CLOUDY_DAYLIGHT	5
#define T_WB_TWILIGHT			6
#define T_WB_SHADE				7

//constants for focus mode
#define T_AF_FIXED				0
#define T_AF_AUTO				1
#define T_AF_INFINITY			2
#define T_AF_MACRO				3
#define T_AF_CONTINUEVIDEO		4
#define T_AF_CONTINUEPICTURE	5
#define T_AF_EDOF				6

//constants for ISO level
#define T_ISO_AUTO				0
#define T_ISO_100				1
#define T_ISO_200				2
#define T_ISO_400				3
#define T_ISO_800				4
#define T_ISO_1600				5
#define T_ISO_3200				6
#define T_ISO_6400				7
#define T_ISO_12800				8

//constants for Scene mode
#define T_SCENE_AUTO            0
#define T_SCENE_ACTION          1
#define T_SCENE_PORTRAIT        2
#define T_SCENE_LANDSCAPE       3
#define T_SCENE_NIGHT           4
#define T_SCENE_NIGHTPORTRAIT   5
#define T_SCENE_THEATER         6
#define T_SCENE_BEACH           7
#define T_SCENE_SNOW            8
#define T_SCENE_SUNSET          9
#define T_SCENE_STEADYPHOTO     10
#define T_SCENE_FIREWORKS       11
#define T_SCENE_SPORTS          12
#define T_SCENE_PARTY           13
#define T_SCENE_CANDLELIGHT     14

//Take mode
#define T_TAKEPIC_SINGLE		0
#define T_TAKEPIC_CONTINUE		1
#define T_TAKEPIC_STOP			2

//AE metering mode
#define T_AE_AUTO				0 
#define T_AE_AVERAGE 			1
#define T_AE_CENTRWEIGHT		2
#define T_AE_SPOT				3


int misp_exec_unidir_cmd(u16 cmd, bool set_flag,\
							bool out_to_block, u8 *param, u32 len);
int misp_exec_bidir_cmd(u16 cmd, u8 *in, u32 in_len,\
						bool out_to_block, u8 *out, u32 out_len);

int misp_exec_write_block_res(u16 cmd, u8 *in, u32 in_len, bool out_to_block, u8 *out,u32 bulk_len, u32 out_len);
int misp_exec_write_block(u16 cmd, u8 *in, u32 in_len, u8 *out, u32 out_len);

int misp_init(void);
int misp_exit(void);
int misp_set_power(int on);
int misp_flush_log(void);
int misp_flush_reg(void);
int misp_reset_vcm(void);

void altek6045_notify_cmd_done( uint32_t cmd, uint32_t result);
void altek6045_notify_dump( uint32_t type);
void altek6045_notify_error( uint32_t id);
#endif

