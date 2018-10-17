#ifndef __c3_con_ESTHeatingSystem_h__
#define __c3_con_ESTHeatingSystem_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_con_ESTHeatingSystemInstanceStruct
#define typedef_SFc3_con_ESTHeatingSystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_M2;
  uint8_T c3_tp_M4;
  uint8_T c3_tp_M5;
  uint8_T c3_tp_M236;
  uint8_T c3_tp_M262;
  uint8_T c3_tp_M263;
  boolean_T c3_stateChanged;
  real_T c3_lastMajorTime;
  uint8_T c3_is_active_c3_con_ESTHeatingSystem;
  uint8_T c3_is_c3_con_ESTHeatingSystem;
  real_T c3_A2[9];
  real_T c3_B2[6];
  real_T c3_A1[9];
  real_T c3_A3[9];
  real_T c3_B1[6];
  real_T c3_B3[6];
  real_T c3_A4[9];
  real_T c3_B4[6];
  boolean_T c3_dataWrittenToVector[12];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  real_T *c3_out1;
  real_T *c3_ud;
  real_T *c3_x1;
  real_T *c3_x2;
  real_T *c3_x3;
  real_T *c3_out2;
  real_T *c3_out3;
} SFc3_con_ESTHeatingSystemInstanceStruct;

#endif                                 /*typedef_SFc3_con_ESTHeatingSystemInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_con_ESTHeatingSystem_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_con_ESTHeatingSystem_get_check_sum(mxArray *plhs[]);
extern void c3_con_ESTHeatingSystem_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
