#ifndef __c3_Navigation_h__
#define __c3_Navigation_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_NavigationInstanceStruct
#define typedef_SFc3_NavigationInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_S1;
  uint8_T c3_tp_sys;
  uint8_T c3_b_tp_S1;
  uint8_T c3_tp_S2;
  uint8_T c3_tp_S3;
  uint8_T c3_tp_S4;
  uint8_T c3_tp_S5;
  uint8_T c3_tp_A;
  uint8_T c3_tp_Conditions;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_Navigation;
  uint8_T c3_is_c3_Navigation;
  uint8_T c3_is_S1;
  uint8_T c3_is_active_S1;
  uint8_T c3_is_active_Conditions;
  boolean_T c3_c1;
  boolean_T c3_c2;
  boolean_T c3_c3;
  boolean_T c3_c4;
  boolean_T c3_c5;
  real_T c3_label;
  boolean_T c3_dataWrittenToVector[2];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  real_T *c3_x;
  real_T *c3_y;
  real_T *c3_vdx;
  real_T *c3_vdy;
} SFc3_NavigationInstanceStruct;

#endif                                 /*typedef_SFc3_NavigationInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Navigation_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Navigation_get_check_sum(mxArray *plhs[]);
extern void c3_Navigation_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
