#ifndef __c3_ESTNavigation_h__
#define __c3_ESTNavigation_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_ESTNavigationInstanceStruct
#define typedef_SFc3_ESTNavigationInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_M2;
  uint8_T c3_tp_M3;
  uint8_T c3_tp_M41;
  uint8_T c3_tp_M42;
  uint8_T c3_tp_M43;
  uint8_T c3_tp_M1;
  uint8_T c3_tp_M44;
  uint8_T c3_is_active_c3_ESTNavigation;
  uint8_T c3_is_c3_ESTNavigation;
  real_T c3_A2[16];
  real_T c3_Bc2[4];
  real_T c3_x[4];
  real_T c3_A1[16];
  real_T c3_A3[16];
  real_T c3_Bc1[4];
  real_T c3_Bc3[4];
  boolean_T c3_dataWrittenToVector[7];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  real_T (*c3_xout)[4];
} SFc3_ESTNavigationInstanceStruct;

#endif                                 /*typedef_SFc3_ESTNavigationInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_ESTNavigation_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_ESTNavigation_get_check_sum(mxArray *plhs[]);
extern void c3_ESTNavigation_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
