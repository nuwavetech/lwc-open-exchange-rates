
/**
 *
 *  Copyright (c) 2019 NuWave Technologies, Inc. All rights reserved.
 *
 */

#pragma nolist
#include <cextdecs>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tal.h>
#pragma list

#include "oxrates.h"

static const char* formatRate(const char* rate, size_t size, size_t scale);
static const char* getEnvValue(const char* name);

/* These values must match the API definition. */
#define RATE_SIZE 18
#define RATE_SCALE 12

int main(int argc, char** argv, char** env) {
  int rc;
  const char* pathmon_name;
  const char* server_class;
  const char* app_id;
  const char* base_currency = "USD";
  long long startTime;
  long long endTime;
  size_t i;
  int reply_len;

  get_latest_rq_def request;

  union {
    lightwave_rp_header_def header;
    get_latest_200_rp_def reply_200;
    get_latest_other_rp_def reply_other;
  } reply;

  printf("\nLightWave Client(tm) - Open Exchange Rates API - Test Driver - 19JUL2019\n");

  /* Get variables from the environment. These are set by the SETENV macro. */
  if ((pathmon_name = getEnvValue("PATHMON-NAME")) == NULL) {
    return 0;
  }

  if ((server_class = getEnvValue("SERVER-CLASS")) == NULL) {
    return 0;
  }

  if ((app_id = getEnvValue("APP-ID")) == NULL) {
    return 0;
  }

  if ((base_currency = getEnvValue("BASE-CURRENCY")) == NULL) {
    return 0;
  }

  /* Initialize the request. */
  printf("\nBuilding request IPM ...\n");
  memset(&request, 0, sizeof(request));
  request.lightwave_rq_header.rq_code = rq_get_latest;
  strncpy(request.app_id, app_id, sizeof(request.app_id));
  strncpy(request.base, base_currency, sizeof(request.base));

  /* Send the request to the pathway server. */
  printf("Sending %u byte request to serverclass %s:%s ...\n", sizeof(request),
         pathmon_name, server_class);

  startTime = JULIANTIMESTAMP();

  rc = SERVERCLASS_SENDL_((char*)pathmon_name, (short)strlen(pathmon_name),
                          (char*)server_class, (short)strlen(server_class),
                          (char*)&request, (char*)&reply, sizeof(request),
                          sizeof(reply), &reply_len);

  endTime = JULIANTIMESTAMP();

  /* Check for serverclass send error. */
  if (rc != 0) {
    short frc;
    short prc;
    SERVERCLASS_SEND_INFO_(&prc, &frc);
    printf("\nSERVERCLASS_SEND_ error %hd:%hd occurred.\n\n", prc, frc);
    switch (frc) {
    case 14:
      printf("Did you start the pathway by running STARTPW?\n\n");
      break;
    default:
      break;
    }
    return 0;
  }

  printf("Received %d byte reply ...\n", reply_len);

  switch (reply.header.http_status) {
  case 200:
    printf("\n%d rates were returned for base currency: %s.\n\n",
           reply.reply_200.rates_response.rates.rate_count, base_currency);

    for (i = 0; i < reply.reply_200.rates_response.rates.rate_count; i++) {
      printf("  %-4s  %s\n",
             reply.reply_200.rates_response.rates.rate[i].curr_code,
             formatRate(reply.reply_200.rates_response.rates.rate[i].curr_rate,
                        RATE_SIZE, RATE_SCALE));
    }

    printf("\nThe request completed in %g seconds.\n\n",
           (double)(endTime - startTime) / 1000000.0);
    printf("Navigate to this URL to compare the rates:\n");
    printf(
        "  https://openexchangerates.org/api/latest.json?app_id=%s&base=%s\n\n",
        app_id, base_currency);
    break;
  default:
    printf("The service returned an error:\n");
    printf("  status: %d\n", reply.reply_other.error_response.status_rw);
    printf("  message: %s\n", reply.reply_other.error_response.message_rw);
    printf("  description: %s\n", reply.reply_other.error_response.description);
    printf("\n");
    break;
  }

  return 0;
}

static const char* formatRate(const char* rate, size_t size, size_t scale) {
  static char formatted[100];
  char* p;
  char* z;

  memcpy(formatted, rate, size);
  formatted[size] = 0;

  /* Insert decimal point. */
  p = &formatted[size - scale];
  memmove(&p[1], p, scale + 1);
  *p = '.';

  /* Trim trailing 0s, and remove the decimal if it's trailing. */
  for (z = &formatted[size]; *z == '0' && z > p; z--) {
    *z = 0;
  }
  if (p[1] == 0) {
    *p = 0;
  }

  /* Trim leading 0's */
  for (z = formatted; *z == '0' && z < &p[-1]; z++)
    ;
  if (z != formatted) {
    memmove(formatted, z, strlen(z) + 1);
  }

  return formatted;
}

static const char* getEnvValue(const char* name) {
  const char* v = getenv(name);
  if (v == NULL) {
    printf("PARAM \"%s\" not set. Did you run SETENV?\n", name);
  }
  return v;
}

/* End of file. */