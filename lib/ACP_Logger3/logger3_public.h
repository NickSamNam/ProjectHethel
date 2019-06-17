/* $Id: logger3_public.h $ */

#ifndef __vms_logger3_public_h__
#define __vms_logger3_public_h__

#include <stdint.h>

#define L3_SIGNATURE_MASK  0xFC00 // top six bits are the signature, identifying the start of a frame
#define L3_LENGTH_MASK     0x03FF // bottom ten bits are length of data that follows

#define L3_SIGNATURE_VALUE 0xAC00 // signature bits == 101011 == 0xAC

typedef uint16_t crc_t;

typedef struct
	{
		union
			{
				uint16_t u16;
				
				struct
					{
						uint16_t remaining_bytes : 10; // bottom ten bits are length of data that follows
						uint16_t signature       :  6; // top six bits are signature 0xAC
					}
				bits;
			}
		signature;

		crc_t             crc;  // crc spans all bytes that follow it

		// 32-bit packing of payload type id and timestamp
		struct
			{
				uint32_t          payload_id        : 8;  // top eight bits specifies which payload data structure follows header
				uint32_t          payload_timestamp : 24; // bottom 24 bits is 100 Hz clock from state system
			}
		id_and_timestamp;
	}
l3_header_t;

#define L3PAYLOAD_ID_BMS_SUMMARY 0x00
typedef struct
	{
		l3_header_t    header;

		uint16_t v_min; // base unit is 0.001 volts
		uint16_t v_max;
		uint16_t v_avg;
		
		int16_t  t_min; // base unit is 0.1 degree C
		int16_t  t_max;
		int16_t  t_avg;
		
		uint8_t  soc_percent;
	}
l3frame_bms_summary_t;

#define L3FRAME_ID_SYS_HIRATE 0x01
typedef struct
	{
		l3_header_t    header;

		uint32_t       error_bitmap;

		uint16_t       v_bat_x10;
		int16_t        i_sys_x10;
		int16_t        i_hyb_x10;
		int16_t        i_aux_x10;

		uint16_t       motor_rpm;
		
		uint8_t        ui_state_index;
		uint8_t        charge_result;
		
		uint8_t        reserved[4];
	}
l3frame_sys_highrate_t;

#define L3FRAME_ID_SYS_LOWRATE 0x02
typedef struct
	{
		l3_header_t    header;

		int16_t        motor_temp_x10;
		int16_t        peu_temp_x10;
		int16_t        batt_inlet_temp_x10;
		int16_t        ambient_temp_x10;
		
		int16_t        i_line_x10;
		uint16_t       v_line_x10;
		
		uint16_t       v_aps_x100;
		
		uint8_t        line_ampacity; // maximum line current in 1A units

/*
	BMS-specific error/status values
	
	For LOM systems:
	
	bms_error[0] == cumulative error count since system startup
	bms_error[1] == index of last monitor to report an error; 0 implies no error to date
	
	If both values are set to 0xFF, the VMS software does not support bms_error codes.
*/
		uint8_t        bms_error[2];
		
		uint8_t        reserved[1];
	}
l3frame_sys_lowrate_t;

#define L3PAYLOAD_ID_BMS_VOLTAGE     (0x03)
#define L3PAYLOAD_ID_BMS_TEMPERATURE (0x04)
// these payloads simply consist of a header plus a variable-length array of data

#define L3PAYLOAD_ID_TRIPLOG 0x05
typedef struct
    {
        l3_header_t    header;
        uint32_t ah_drive_x10k;
        uint32_t ah_regen_x10k;
        uint32_t ah_charge_x10k;
        uint32_t ah_dischg_x10k;
        
        uint32_t wh_drive_x10;
        uint32_t wh_regen_x10;
        uint32_t wh_charge_x10;
        uint32_t wh_dischg_x10;
        
        uint32_t distance_cm;
        
        uint32_t ac_wh_in;
        uint32_t ac_wh_out;
        
        uint32_t line_time_sec;   // time spent with AC line connected, whether charging or not
        uint32_t drive_time_sec;  // time spent in drive mode
    }
l3frame_triplog_t;

#endif // __vms_logger3_public_h__