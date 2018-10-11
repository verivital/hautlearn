#ifndef __c3_HeatingSystem_h__
#define __c3_HeatingSystem_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_HeatingSystemInstanceStruct
#define typedef_SFc3_HeatingSystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_s1;
  uint8_T c3_tp_s1_2;
  uint8_T c3_tp_s1_1;
  uint8_T c3_tp_s2;
  uint8_T c3_tp_s2_2;
  uint8_T c3_tp_s2_1;
  uint8_T c3_tp_s3;
  uint8_T c3_tp_s3_1;
  uint8_T c3_tp_s3_2;
  uint8_T c3_is_active_c3_HeatingSystem;
  uint8_T c3_is_c3_HeatingSystem;
  uint8_T c3_is_s1;
  uint8_T c3_is_s2;
  uint8_T c3_is_s3;
  real_T c3_dif[3];
  real_T c3_get[3];
  boolean_T c3_dataWrittenToVector[1];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  real_T (*c3_X)[3];
  real_T (*c3_H)[3];
} SFc3_HeatingSystemInstanceStruct;

#endif                                 /*typedef_SFc3_HeatingSystemInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_HeatingSystem_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_HeatingSystem_get_check_sum(mxArray *plhs[]);
extern void c3_HeatingSystem_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
