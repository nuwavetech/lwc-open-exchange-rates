/* SCHEMA PRODUCED DATE - TIME : 7/19/2019 - 07:33:26 */
#pragma section lightwave_rp_code_enum
/* Definition LIGHTWAVE-RP-CODE-ENUM created on 07/19/2019 at 07:33 */
enum
{
   lw_rp_success = 0,
   lw_rp_info = 1,
   lw_rp_error = 2
};
typedef short                           lightwave_rp_code_enum_def;
#pragma section lightwave_info_code_enum
/* Definition LIGHTWAVE-INFO-CODE-ENUM created on 07/19/2019 at 07:33 */
enum
{
   lw_info_field_truncated = 100,
   lw_info_array_truncated = 101
};
typedef short                           lightwave_info_code_enum_def;
#pragma section lightwave_error_src_enum
/* Definition LIGHTWAVE-ERROR-SRC-ENUM created on 07/19/2019 at 07:33 */
enum
{
   lw_error_src_lightwave = 1,
   lw_error_src_http = 2,
   lw_error_src_tcpip = 3,
   lw_error_src_ssl = 4
};
typedef short                           lightwave_error_src_enum_def;
#pragma section lightwave_error_enum
/* Definition LIGHTWAVE-ERROR-ENUM created on 07/19/2019 at 07:33 */
enum
{
   lw_error_invalid_license = 1,
   lw_error_invalid_header = 2,
   lw_error_invalid_rq_code = 3,
   lw_error_invalid_type = 4,
   lw_error_serialization_error = 5,
   lw_error_deserialization_error = 6,
   lw_error_request_timeout = 7,
   lw_error_response_not_defined = 12,
   lw_error_internal_error = 500
};
typedef short                           lightwave_error_enum_def;
#pragma section lightwave_rq_header
/* Definition LIGHTWAVE-RQ-HEADER created on 07/19/2019 at 07:33 */
#include <tnsint.h>
#pragma fieldalign shared2 __lightwave_rq_header
typedef struct __lightwave_rq_header
{
   short                           rq_code;
   unsigned short                  rq_version;
   __uint32_t                      rq_timeout;
   char                            reserved[24];
} lightwave_rq_header_def;
#define lightwave_rq_header_def_Size 32
#pragma section lightwave_rp_header
/* Definition LIGHTWAVE-RP-HEADER created on 07/19/2019 at 07:33 */
#pragma fieldalign shared2 __lightwave_rp_header
typedef struct __lightwave_rp_header
{
   short                           rp_code;
   short                           http_status;
   short                           info_code;
   short                           info_detail;
   char                            reserved[24];
} lightwave_rp_header_def;
#define lightwave_rp_header_def_Size 32
#pragma section lightwave_error_rp
/* Definition LIGHTWAVE-ERROR-RP created on 07/19/2019 at 07:33 */
#include <tnsint.h>
#pragma fieldalign shared2 __lightwave_error_rp
typedef struct __lightwave_error_rp
{
   lightwave_rp_header_def         lightwave_rp_header;
   __int32_t                       error_source;
   __int32_t                       error_code;
   __int32_t                       error_subcode;
   char                            error_message[4096];
} lightwave_error_rp_def;
#define lightwave_error_rp_def_Size 4140
#pragma section open_exchange_rates_val
/* Definition OPEN-EXCHANGE-RATES-VAL created on 07/19/2019 at 07:33 */
#pragma fieldalign shared2 __open_exchange_rates_val
typedef struct __open_exchange_rates_val
{
   short                           rq_get_latest;
   /*value is 1*/
} open_exchange_rates_val_def;
#define open_exchange_rates_val_def_Size 2
#pragma section open_exchange_rates_enm
/* Definition OPEN-EXCHANGE-RATES-ENM created on 07/19/2019 at 07:33 */
enum
{
   rq_get_latest = 1
};
typedef short                           open_exchange_rates_enm_def;
#pragma section rates_type
/* Definition RATES-TYPE created on 07/19/2019 at 07:33 */
#pragma fieldalign shared2 __rates_type
typedef struct __rates_type
{
   short                           rate_count;
   struct
   {
      char                            curr_code[8];
      char                            curr_rate[18];
   } rate[200];
} rates_type_def;
#define rates_type_def_Size 5202
#pragma section rates_response
/* Definition RATES-RESPONSE created on 07/19/2019 at 07:33 */
#include <tnsint.h>
#pragma fieldalign shared2 __rates_response
typedef struct __rates_response
{
   char                            disclaimer[59];
   char                            license[37];
   __int32_t                       timestamp;
   char                            base[32];
   rates_type_def                  rates;
} rates_response_def;
#define rates_response_def_Size 5334
#pragma section error_response
/* Definition ERROR-RESPONSE created on 07/19/2019 at 07:33 */
#include <tnsint.h>
#pragma fieldalign shared2 __error_response
typedef struct __error_response
{
   __int32_t                       error_rw;
   __int32_t                       status_rw;
   char                            message_rw[128];
   char                            description[256];
} error_response_def;
#define error_response_def_Size 392
#pragma section get_latest_rq
/* Definition GET-LATEST-RQ created on 07/19/2019 at 07:33 */
#pragma fieldalign shared2 __get_latest_rq
typedef struct __get_latest_rq
{
   lightwave_rq_header_def         lightwave_rq_header;
   char                            app_id[64];
   char                            base[8];
   char                            symbols[64];
   char                            prettyprint[8];
   char                            show_alternative[8];
} get_latest_rq_def;
#define get_latest_rq_def_Size 184
#pragma section get_latest_200_rp
/* Definition GET-LATEST-200-RP created on 07/19/2019 at 07:33 */
#pragma fieldalign shared2 __get_latest_200_rp
typedef struct __get_latest_200_rp
{
   lightwave_rp_header_def         lightwave_rp_header;
   rates_response_def              rates_response;
} get_latest_200_rp_def;
#define get_latest_200_rp_def_Size 5366
#pragma section get_latest_other_rp
/* Definition GET-LATEST-OTHER-RP created on 07/19/2019 at 07:33 */
#pragma fieldalign shared2 __get_latest_other_rp
typedef struct __get_latest_other_rp
{
   lightwave_rp_header_def         lightwave_rp_header;
   error_response_def              error_response;
} get_latest_other_rp_def;
#define get_latest_other_rp_def_Size 424
