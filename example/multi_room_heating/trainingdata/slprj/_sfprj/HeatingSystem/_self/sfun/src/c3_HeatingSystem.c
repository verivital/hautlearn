/* Include files */

#include "HeatingSystem_sfun.h"
#include "c3_HeatingSystem.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "HeatingSystem_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_s1                       ((uint8_T)1U)
#define c3_IN_s2                       ((uint8_T)2U)
#define c3_IN_s3                       ((uint8_T)3U)
#define c3_IN_s1_1                     ((uint8_T)1U)
#define c3_IN_s1_2                     ((uint8_T)2U)
#define c3_IN_s2_1                     ((uint8_T)1U)
#define c3_IN_s2_2                     ((uint8_T)2U)
#define c3_IN_s3_1                     ((uint8_T)1U)
#define c3_IN_s3_2                     ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance);
static void initialize_params_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct *
  chartInstance);
static void enable_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance);
static void disable_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_HeatingSystem
  (SFc3_HeatingSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_HeatingSystem
  (SFc3_HeatingSystemInstanceStruct *chartInstance);
static void set_sim_state_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_HeatingSystem
  (SFc3_HeatingSystemInstanceStruct *chartInstance);
static void finalize_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance);
static void sf_gateway_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance);
static void mdl_start_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance);
static void initSimStructsc3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance);
static void c3_s1(SFc3_HeatingSystemInstanceStruct *chartInstance);
static void c3_exit_internal_s1(SFc3_HeatingSystemInstanceStruct *chartInstance);
static void c3_enter_atomic_s1_2(SFc3_HeatingSystemInstanceStruct *chartInstance);
static void c3_s2(SFc3_HeatingSystemInstanceStruct *chartInstance);
static void c3_exit_internal_s2(SFc3_HeatingSystemInstanceStruct *chartInstance);
static void c3_enter_atomic_s2_2(SFc3_HeatingSystemInstanceStruct *chartInstance);
static void c3_s3(SFc3_HeatingSystemInstanceStruct *chartInstance);
static void c3_exit_internal_s3(SFc3_HeatingSystemInstanceStruct *chartInstance);
static void c3_enter_atomic_s3_2(SFc3_HeatingSystemInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_b_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_s1, const char_T *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_f_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_H, const char_T *c3_identifier, real_T
  c3_y[3]);
static void c3_g_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_h_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[1]);
static void c3_i_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[1]);
static const mxArray *c3_j_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_k_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc3_HeatingSystemInstanceStruct
  *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_HeatingSystemInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc3_HeatingSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_HeatingSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_HeatingSystem(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_s1 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_s1 = 0U;
  chartInstance->c3_tp_s1_1 = 0U;
  chartInstance->c3_tp_s1_2 = 0U;
  chartInstance->c3_is_s2 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_s2 = 0U;
  chartInstance->c3_tp_s2_1 = 0U;
  chartInstance->c3_tp_s2_2 = 0U;
  chartInstance->c3_is_s3 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_s3 = 0U;
  chartInstance->c3_tp_s3_1 = 0U;
  chartInstance->c3_tp_s3_2 = 0U;
  chartInstance->c3_is_active_c3_HeatingSystem = 0U;
  chartInstance->c3_is_c3_HeatingSystem = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_dif[0] = 2.0;
  for (c3_i0 = 0; c3_i0 < 3; c3_i0++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_dif[c3_i0], 2U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  chartInstance->c3_dif[1] = 3.0;
  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_dif[c3_i1], 2U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  chartInstance->c3_dif[2] = 2.0;
  for (c3_i2 = 0; c3_i2 < 3; c3_i2++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_dif[c3_i2], 2U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  chartInstance->c3_get[0] = 16.0;
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_get[c3_i3], 3U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  chartInstance->c3_get[1] = 16.0;
  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_get[c3_i4], 3U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  chartInstance->c3_get[2] = 15.0;
  for (c3_i5 = 0; c3_i5 < 3; c3_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_get[c3_i5], 3U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }
}

static void initialize_params_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_HeatingSystem
  (SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_HeatingSystem == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_HeatingSystem == c3_IN_s1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_s1 == c3_IN_s1_2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_s1 == c3_IN_s1_1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_HeatingSystem == c3_IN_s2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_s2 == c3_IN_s2_2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_s2 == c3_IN_s2_1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_HeatingSystem == c3_IN_s3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_s3 == c3_IN_s3_1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_s3 == c3_IN_s3_2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_HeatingSystem
  (SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(7, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", *chartInstance->c3_H, 0, 0U, 1U, 0U,
    1, 3), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_HeatingSystem;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_c3_HeatingSystem;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_c_hoistedGlobal = chartInstance->c3_is_s2;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_c_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_d_hoistedGlobal = chartInstance->c3_is_s1;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_s3;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_e_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 1), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[3];
  int32_T c3_i6;
  boolean_T c3_bv0[1];
  c3_u = sf_mex_dup(c3_st);
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("H", c3_u, 0)),
                        "H", c3_dv0);
  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    (*chartInstance->c3_H)[c3_i6] = c3_dv0[c3_i6];
  }

  chartInstance->c3_is_active_c3_HeatingSystem = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c3_HeatingSystem", c3_u,
       1)), "is_active_c3_HeatingSystem");
  chartInstance->c3_is_c3_HeatingSystem = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c3_HeatingSystem", c3_u, 2)),
    "is_c3_HeatingSystem");
  chartInstance->c3_is_s2 = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_s2", c3_u, 3)), "is_s2");
  chartInstance->c3_is_s1 = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_s1", c3_u, 4)), "is_s1");
  chartInstance->c3_is_s3 = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_s3", c3_u, 5)), "is_s3");
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 6)), "dataWrittenToVector", c3_bv0);
  chartInstance->c3_dataWrittenToVector[0] = c3_bv0[0];
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_HeatingSystem(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_HeatingSystem
  (SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_tp_s1 = (uint8_T)(chartInstance->c3_is_c3_HeatingSystem ==
      c3_IN_s1);
    chartInstance->c3_tp_s1_1 = (uint8_T)(chartInstance->c3_is_s1 == c3_IN_s1_1);
    chartInstance->c3_tp_s1_2 = (uint8_T)(chartInstance->c3_is_s1 == c3_IN_s1_2);
    chartInstance->c3_tp_s2 = (uint8_T)(chartInstance->c3_is_c3_HeatingSystem ==
      c3_IN_s2);
    chartInstance->c3_tp_s2_1 = (uint8_T)(chartInstance->c3_is_s2 == c3_IN_s2_1);
    chartInstance->c3_tp_s2_2 = (uint8_T)(chartInstance->c3_is_s2 == c3_IN_s2_2);
    chartInstance->c3_tp_s3 = (uint8_T)(chartInstance->c3_is_c3_HeatingSystem ==
      c3_IN_s3);
    chartInstance->c3_tp_s3_1 = (uint8_T)(chartInstance->c3_is_s3 == c3_IN_s3_1);
    chartInstance->c3_tp_s3_2 = (uint8_T)(chartInstance->c3_is_s3 == c3_IN_s3_2);
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  int32_T c3_i7;
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i8;
  int32_T c3_i9;
  c3_set_sim_state_side_effects_c3_HeatingSystem(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_X)[c3_i7], 0U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_HeatingSystem == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_HeatingSystem = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_s_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
      (*chartInstance->c3_H)[c3_i8] = 0.0;
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    for (c3_i9 = 0; c3_i9 < 3; c3_i9++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i9], 1U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
    }

    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_is_c3_HeatingSystem = c3_IN_s2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_s2 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_s2 = c3_IN_s2_2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_s2_2 = 1U;
    c3_enter_atomic_s2_2(chartInstance);
  } else {
    switch (chartInstance->c3_is_c3_HeatingSystem) {
     case c3_IN_s1:
      CV_CHART_EVAL(0, 0, 1);
      c3_s1(chartInstance);
      break;

     case c3_IN_s2:
      CV_CHART_EVAL(0, 0, 2);
      c3_s2(chartInstance);
      break;

     case c3_IN_s3:
      CV_CHART_EVAL(0, 0, 3);
      c3_s3(chartInstance);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c3_is_c3_HeatingSystem = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_HeatingSystemMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc3_HeatingSystem(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_s1(SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_d0;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  int32_T c3_i10;
  int32_T c3_i11;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_d0 = chartInstance->c3_get[1];
  guard1 = false;
  if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (*chartInstance->c3_X)
        [1], c3_d0, -1, 3U, (*chartInstance->c3_X)[1] <= c3_d0))) {
    c3_d1 = (*chartInstance->c3_X)[0] - (*chartInstance->c3_X)[1];
    c3_d2 = chartInstance->c3_dif[1];
    if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1, c3_d1, c3_d2, -1, 5U,
          c3_d1 >= c3_d2))) {
      CV_EML_MCDC(1, 0, 0, true);
      CV_EML_IF(1, 0, 0, true);
      c3_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    CV_EML_MCDC(1, 0, 0, false);
    CV_EML_IF(1, 0, 0, false);
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    c3_exit_internal_s1(chartInstance);
    chartInstance->c3_tp_s1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_HeatingSystem = c3_IN_s2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_s2 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_s2 = c3_IN_s2_2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_s2_2 = 1U;
    c3_enter_atomic_s2_2(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    switch (chartInstance->c3_is_s1) {
     case c3_IN_s1_1:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_b_out = CV_EML_IF(10, 0, 0, (*chartInstance->c3_X)[0] <= 20.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        (*chartInstance->c3_H)[0] = 1.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i10], 1U, 5U, 10U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_tp_s1_1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_s1 = c3_IN_s1_2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_s1_2 = 1U;
        c3_enter_atomic_s1_2(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_s1_2:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_i_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_c_out = CV_EML_IF(11, 0, 0, (*chartInstance->c3_X)[0] >= 21.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        (*chartInstance->c3_H)[0] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i11], 1U, 5U, 11U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_tp_s1_2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_s1 = c3_IN_s1_1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_s1_1 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        (*chartInstance->c3_H)[0] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i12], 1U, 4U, 1U,
                                chartInstance->c3_sfEvent, false);
        }

        (*chartInstance->c3_H)[1] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i13], 1U, 4U, 1U,
                                chartInstance->c3_sfEvent, false);
        }

        (*chartInstance->c3_H)[2] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i14], 1U, 4U, 1U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c3_is_s1 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void c3_exit_internal_s1(SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  switch (chartInstance->c3_is_s1) {
   case c3_IN_s1_1:
    CV_STATE_EVAL(0, 1, 1);
    chartInstance->c3_tp_s1_1 = 0U;
    chartInstance->c3_is_s1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_s1_2:
    CV_STATE_EVAL(0, 1, 2);
    chartInstance->c3_tp_s1_2 = 0U;
    chartInstance->c3_is_s1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 1, 0);
    chartInstance->c3_is_s1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    break;
  }
}

static void c3_enter_atomic_s1_2(SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  (*chartInstance->c3_H)[0] = 1.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i15], 1U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
  }

  (*chartInstance->c3_H)[1] = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i16], 1U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
  }

  (*chartInstance->c3_H)[2] = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i17], 1U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_s2(SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  int32_T c3_i18;
  int32_T c3_i19;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_v_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_d3 = chartInstance->c3_get[2];
  guard1 = false;
  if (CV_EML_COND(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (*chartInstance->c3_X)
        [2], c3_d3, -1, 3U, (*chartInstance->c3_X)[2] <= c3_d3))) {
    c3_d4 = (*chartInstance->c3_X)[1] - (*chartInstance->c3_X)[2];
    c3_d5 = chartInstance->c3_dif[2];
    if (CV_EML_COND(3, 0, 1, CV_RELATIONAL_EVAL(5U, 3U, 1, c3_d4, c3_d5, -1, 5U,
          c3_d4 >= c3_d5))) {
      CV_EML_MCDC(3, 0, 0, true);
      CV_EML_IF(3, 0, 0, true);
      c3_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    CV_EML_MCDC(3, 0, 0, false);
    CV_EML_IF(3, 0, 0, false);
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    c3_exit_internal_s2(chartInstance);
    chartInstance->c3_tp_s2 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_HeatingSystem = c3_IN_s3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_s3 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_s3 = c3_IN_s3_2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_s3_2 = 1U;
    c3_enter_atomic_s3_2(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    switch (chartInstance->c3_is_s2) {
     case c3_IN_s2_1:
      CV_STATE_EVAL(3, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_k_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_b_out = CV_EML_IF(4, 0, 0, (*chartInstance->c3_X)[1] <= 19.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        (*chartInstance->c3_H)[1] = 1.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i18 = 0; c3_i18 < 3; c3_i18++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i18], 1U, 5U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_tp_s2_1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_s2 = c3_IN_s2_2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_s2_2 = 1U;
        c3_enter_atomic_s2_2(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_s2_2:
      CV_STATE_EVAL(3, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_c_out = CV_EML_IF(5, 0, 0, (*chartInstance->c3_X)[1] >= 21.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_n_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        (*chartInstance->c3_H)[1] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i19 = 0; c3_i19 < 3; c3_i19++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i19], 1U, 5U, 5U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_tp_s2_2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_s2 = c3_IN_s2_1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_s2_1 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        (*chartInstance->c3_H)[0] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i20 = 0; c3_i20 < 3; c3_i20++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i20], 1U, 4U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        (*chartInstance->c3_H)[1] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i21], 1U, 4U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        (*chartInstance->c3_H)[2] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i22], 1U, 4U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(3, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c3_is_s2 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
}

static void c3_exit_internal_s2(SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  switch (chartInstance->c3_is_s2) {
   case c3_IN_s2_1:
    CV_STATE_EVAL(3, 1, 1);
    chartInstance->c3_tp_s2_1 = 0U;
    chartInstance->c3_is_s2 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_s2_2:
    CV_STATE_EVAL(3, 1, 2);
    chartInstance->c3_tp_s2_2 = 0U;
    chartInstance->c3_is_s2 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 1, 0);
    chartInstance->c3_is_s2 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;
  }
}

static void c3_enter_atomic_s2_2(SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  (*chartInstance->c3_H)[0] = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i23 = 0; c3_i23 < 3; c3_i23++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i23], 1U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
  }

  (*chartInstance->c3_H)[1] = 1.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i24 = 0; c3_i24 < 3; c3_i24++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i24], 1U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
  }

  (*chartInstance->c3_H)[2] = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i25 = 0; c3_i25 < 3; c3_i25++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i25], 1U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_s3(SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d8;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  int32_T c3_i26;
  int32_T c3_i27;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_d6 = chartInstance->c3_get[0];
  guard1 = false;
  if (CV_EML_COND(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (*chartInstance->c3_X)
        [0], c3_d6, -1, 3U, (*chartInstance->c3_X)[0] <= c3_d6))) {
    c3_d7 = (*chartInstance->c3_X)[2] - (*chartInstance->c3_X)[0];
    c3_d8 = chartInstance->c3_dif[0];
    if (CV_EML_COND(2, 0, 1, CV_RELATIONAL_EVAL(5U, 2U, 1, c3_d7, c3_d8, -1, 5U,
          c3_d7 >= c3_d8))) {
      CV_EML_MCDC(2, 0, 0, true);
      CV_EML_IF(2, 0, 0, true);
      c3_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    CV_EML_MCDC(2, 0, 0, false);
    CV_EML_IF(2, 0, 0, false);
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    c3_exit_internal_s3(chartInstance);
    chartInstance->c3_tp_s3 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_HeatingSystem = c3_IN_s1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_s1 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_s1 = c3_IN_s1_2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_s1_2 = 1U;
    c3_enter_atomic_s1_2(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    switch (chartInstance->c3_is_s3) {
     case c3_IN_s3_1:
      CV_STATE_EVAL(6, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_b_out = CV_EML_IF(8, 0, 0, (*chartInstance->c3_X)[2] <= 19.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_p_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        (*chartInstance->c3_H)[2] = 1.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i26 = 0; c3_i26 < 3; c3_i26++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i26], 1U, 5U, 8U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_tp_s3_1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_s3 = c3_IN_s3_2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_s3_2 = 1U;
        c3_enter_atomic_s3_2(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_s3_2:
      CV_STATE_EVAL(6, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_c_out = CV_EML_IF(7, 0, 0, (*chartInstance->c3_X)[2] >= 22.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_r_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        (*chartInstance->c3_H)[2] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i27 = 0; c3_i27 < 3; c3_i27++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i27], 1U, 5U, 7U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_tp_s3_2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_s3 = c3_IN_s3_1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_s3_1 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        (*chartInstance->c3_H)[0] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i28 = 0; c3_i28 < 3; c3_i28++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i28], 1U, 4U, 7U,
                                chartInstance->c3_sfEvent, false);
        }

        (*chartInstance->c3_H)[1] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i29 = 0; c3_i29 < 3; c3_i29++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i29], 1U, 4U, 7U,
                                chartInstance->c3_sfEvent, false);
        }

        (*chartInstance->c3_H)[2] = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i30 = 0; c3_i30 < 3; c3_i30++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i30], 1U, 4U, 7U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(6, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c3_is_s3 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
}

static void c3_exit_internal_s3(SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  switch (chartInstance->c3_is_s3) {
   case c3_IN_s3_1:
    CV_STATE_EVAL(6, 1, 1);
    chartInstance->c3_tp_s3_1 = 0U;
    chartInstance->c3_is_s3 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_s3_2:
    CV_STATE_EVAL(6, 1, 2);
    chartInstance->c3_tp_s3_2 = 0U;
    chartInstance->c3_is_s3 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(6, 1, 0);
    chartInstance->c3_is_s3 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;
  }
}

static void c3_enter_atomic_s3_2(SFc3_HeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  (*chartInstance->c3_H)[0] = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i31 = 0; c3_i31 < 3; c3_i31++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i31], 1U, 4U, 8U,
                          chartInstance->c3_sfEvent, false);
  }

  (*chartInstance->c3_H)[1] = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i32 = 0; c3_i32 < 3; c3_i32++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i32], 1U, 4U, 8U,
                          chartInstance->c3_sfEvent, false);
  }

  (*chartInstance->c3_H)[2] = 1.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i33 = 0; c3_i33 < 3; c3_i33++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_H)[c3_i33], 1U, 4U, 8U,
                          chartInstance->c3_sfEvent, false);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d9;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d9, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d9;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_b_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_HeatingSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i34;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i34, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i34;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_s1, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_s1), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_s1);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_s1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_b_tp_s1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_s1), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_s1);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i35;
  const mxArray *c3_y = NULL;
  real_T c3_u[3];
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i35 = 0; c3_i35 < 3; c3_i35++) {
    c3_u[c3_i35] = (*(real_T (*)[3])c3_inData)[c3_i35];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_f_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_H, const char_T *c3_identifier, real_T
  c3_y[3])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_H), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_H);
}

static void c3_g_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3])
{
  real_T c3_dv1[3];
  int32_T c3_i36;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i36 = 0; c3_i36 < 3; c3_i36++) {
    c3_y[c3_i36] = c3_dv1[c3_i36];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_H;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i37;
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_b_H = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_H), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_H);
  for (c3_i37 = 0; c3_i37 < 3; c3_i37++) {
    (*(real_T (*)[3])c3_outData)[c3_i37] = c3_y[c3_i37];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_h_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[1])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_i_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[1])
{
  boolean_T c3_bv1[1];
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 1);
  c3_y[0] = c3_bv1[0];
  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_j_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_k_emlrt_marshallIn(SFc3_HeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc3_HeatingSystemInstanceStruct
  *chartInstance, int32_T c3_ssid)
{
  const mxArray *c3_msgInfo;
  (void)chartInstance;
  (void)c3_ssid;
  c3_msgInfo = NULL;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_HeatingSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_X = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_H = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_HeatingSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(41397623U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(216734238U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(769879292U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(244652735U);
}

mxArray* sf_c3_HeatingSystem_get_post_codegen_info(void);
mxArray *sf_c3_HeatingSystem_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("G804U92M8Nehifyiub8GnF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_HeatingSystem_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_HeatingSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_HeatingSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_HeatingSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_HeatingSystem_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_HeatingSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[28],T\"H\",},{M[8],M[0],T\"is_active_c3_HeatingSystem\",},{M[9],M[0],T\"is_c3_HeatingSystem\",},{M[9],M[1],T\"is_s2\",},{M[9],M[6],T\"is_s1\",},{M[9],M[7],T\"is_s3\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_HeatingSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_HeatingSystemInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_HeatingSystemInstanceStruct *chartInstance =
      (SFc3_HeatingSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _HeatingSystemMachineNumber_,
           3,
           9,
           13,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_HeatingSystemMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_HeatingSystemMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _HeatingSystemMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"X");
          _SFD_SET_DATA_PROPS(1,2,0,1,"H");
          _SFD_SET_DATA_PROPS(2,7,0,0,"dif");
          _SFD_SET_DATA_PROPS(3,7,0,0,"get");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_CH_SUBSTATE_INDEX(2,6);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,2);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_INDEX(3,1,5);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,2);
          _SFD_ST_SUBSTATE_INDEX(6,0,7);
          _SFD_ST_SUBSTATE_INDEX(6,1,8);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(11,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(7,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 13, 33 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,13,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,1,16,33,-1,5);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 13, 33 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,13,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,1,16,33,-1,5);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 13, 33 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,13,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,1,16,33,-1,5);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _HeatingSystemMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_HeatingSystemInstanceStruct *chartInstance =
      (SFc3_HeatingSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c3_dif);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c3_X);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)&chartInstance->c3_get);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c3_H);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sJe3QC2lkbb8J4v7gkTFUqE";
}

static void sf_opaque_initialize_c3_HeatingSystem(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_HeatingSystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_HeatingSystem((SFc3_HeatingSystemInstanceStruct*)
    chartInstanceVar);
  initialize_c3_HeatingSystem((SFc3_HeatingSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_HeatingSystem(void *chartInstanceVar)
{
  enable_c3_HeatingSystem((SFc3_HeatingSystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_HeatingSystem(void *chartInstanceVar)
{
  disable_c3_HeatingSystem((SFc3_HeatingSystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_HeatingSystem(void *chartInstanceVar)
{
  sf_gateway_c3_HeatingSystem((SFc3_HeatingSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_HeatingSystem(SimStruct* S)
{
  return get_sim_state_c3_HeatingSystem((SFc3_HeatingSystemInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_HeatingSystem(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c3_HeatingSystem((SFc3_HeatingSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_HeatingSystem(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_HeatingSystemInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_HeatingSystem_optimization_info();
    }

    finalize_c3_HeatingSystem((SFc3_HeatingSystemInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_HeatingSystem((SFc3_HeatingSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_HeatingSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_HeatingSystem((SFc3_HeatingSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_HeatingSystem(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_HeatingSystem_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1176074981U));
  ssSetChecksum1(S,(3955510767U));
  ssSetChecksum2(S,(425554872U));
  ssSetChecksum3(S,(2839383849U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_HeatingSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_HeatingSystem(SimStruct *S)
{
  SFc3_HeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_HeatingSystemInstanceStruct *)utMalloc(sizeof
    (SFc3_HeatingSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_HeatingSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_HeatingSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_HeatingSystem;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_HeatingSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_HeatingSystem;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_HeatingSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_HeatingSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_HeatingSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_HeatingSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_HeatingSystem;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_HeatingSystem;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_HeatingSystem;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_HeatingSystem(chartInstance);
}

void c3_HeatingSystem_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_HeatingSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_HeatingSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_HeatingSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_HeatingSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
