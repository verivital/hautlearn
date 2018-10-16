/* Include files */

#include "ESTNavigation_sfun.h"
#include "c3_ESTNavigation.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ESTNavigation_sfun_debug_macros.h"
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
#define c3_IN_M1                       ((uint8_T)1U)
#define c3_IN_M2                       ((uint8_T)2U)
#define c3_IN_M3                       ((uint8_T)3U)
#define c3_IN_M41                      ((uint8_T)4U)
#define c3_IN_M42                      ((uint8_T)5U)
#define c3_IN_M43                      ((uint8_T)6U)
#define c3_IN_M44                      ((uint8_T)7U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[5] = { "nargin", "nargout", "u1",
  "u2", "y" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void initialize_params_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct *
  chartInstance);
static void enable_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void disable_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_ESTNavigation
  (SFc3_ESTNavigationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_ESTNavigation
  (SFc3_ESTNavigationInstanceStruct *chartInstance);
static void set_sim_state_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_ESTNavigation
  (SFc3_ESTNavigationInstanceStruct *chartInstance);
static void finalize_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void sf_gateway_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void mdl_start_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void initSimStructsc3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void c3_enter_atomic_M42(SFc3_ESTNavigationInstanceStruct *chartInstance);
static void c3_enter_atomic_M1(SFc3_ESTNavigationInstanceStruct *chartInstance);
static void c3_M1(SFc3_ESTNavigationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_b_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_y, const char_T *c3_identifier, real_T
  c3_b_y[4]);
static void c3_c_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u1, const char_T *c3_identifier, real_T
  c3_y[16]);
static void c3_e_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[16]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_f_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_FnM(SFc3_ESTNavigationInstanceStruct *chartInstance, real_T
                   c3_u1[16], real_T c3_u2[4], real_T c3_y[4]);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_g_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_h_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_M2, const char_T *c3_identifier);
static uint8_T c3_i_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_j_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_Bc2, const char_T *c3_identifier, real_T
  c3_y[4]);
static void c3_k_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4]);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_l_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[7]);
static void c3_m_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[7]);
static const mxArray *c3_n_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_o_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc3_ESTNavigationInstanceStruct
  *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc3_ESTNavigationInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_ESTNavigationInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_ESTNavigation(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_M1 = 0U;
  chartInstance->c3_tp_M2 = 0U;
  chartInstance->c3_tp_M3 = 0U;
  chartInstance->c3_tp_M41 = 0U;
  chartInstance->c3_tp_M42 = 0U;
  chartInstance->c3_tp_M43 = 0U;
  chartInstance->c3_tp_M44 = 0U;
  chartInstance->c3_is_active_c3_ESTNavigation = 0U;
  chartInstance->c3_is_c3_ESTNavigation = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_x[0] = 0.5;
  for (c3_i0 = 0; c3_i0 < 4; c3_i0++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i0], 6U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  chartInstance->c3_x[1] = 0.5;
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i1], 6U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  chartInstance->c3_x[2] = 0.5;
  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i2], 6U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  chartInstance->c3_x[3] = 0.5;
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i3], 6U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    (*chartInstance->c3_xout)[0] = 0.4;
    for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i4], 7U, 1U, 0U,
                            chartInstance->c3_sfEvent, false);
    }

    (*chartInstance->c3_xout)[1] = 0.62;
    for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i5], 7U, 1U, 0U,
                            chartInstance->c3_sfEvent, false);
    }

    (*chartInstance->c3_xout)[2] = 0.5;
    for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i6], 7U, 1U, 0U,
                            chartInstance->c3_sfEvent, false);
    }

    (*chartInstance->c3_xout)[3] = 1.0;
    for (c3_i7 = 0; c3_i7 < 4; c3_i7++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i7], 7U, 1U, 0U,
                            chartInstance->c3_sfEvent, false);
    }
  }
}

static void initialize_params_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_ESTNavigation
  (SFc3_ESTNavigationInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_ESTNavigation == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ESTNavigation == c3_IN_M2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ESTNavigation == c3_IN_M3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ESTNavigation == c3_IN_M41) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ESTNavigation == c3_IN_M42) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ESTNavigation == c3_IN_M43) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ESTNavigation == c3_IN_M1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ESTNavigation == c3_IN_M44) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_ESTNavigation
  (SFc3_ESTNavigationInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  uint8_T c3_hoistedGlobal;
  const mxArray *c3_j_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  const mxArray *c3_k_y = NULL;
  const mxArray *c3_l_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(11, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", *chartInstance->c3_xout, 0, 0U, 1U,
    0U, 1, 4), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", chartInstance->c3_A1, 0, 0U, 1U, 0U,
    2, 4, 4), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", chartInstance->c3_A2, 0, 0U, 1U, 0U,
    2, 4, 4), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", chartInstance->c3_A3, 0, 0U, 1U, 0U,
    2, 4, 4), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", chartInstance->c3_Bc1, 0, 0U, 1U, 0U,
    2, 4, 1), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", chartInstance->c3_Bc2, 0, 0U, 1U, 0U,
    2, 4, 1), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", chartInstance->c3_Bc3, 0, 0U, 1U, 0U,
    2, 4, 1), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", chartInstance->c3_x, 0, 0U, 1U, 0U,
    1, 4), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_ESTNavigation;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_c3_ESTNavigation;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[4];
  int32_T c3_i8;
  real_T c3_dv1[16];
  int32_T c3_i9;
  real_T c3_dv2[16];
  int32_T c3_i10;
  real_T c3_dv3[16];
  int32_T c3_i11;
  real_T c3_dv4[4];
  int32_T c3_i12;
  real_T c3_dv5[4];
  int32_T c3_i13;
  real_T c3_dv6[4];
  int32_T c3_i14;
  real_T c3_dv7[4];
  int32_T c3_i15;
  boolean_T c3_bv0[7];
  int32_T c3_i16;
  c3_u = sf_mex_dup(c3_st);
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("xout", c3_u, 0)),
                        "xout", c3_dv0);
  for (c3_i8 = 0; c3_i8 < 4; c3_i8++) {
    (*chartInstance->c3_xout)[c3_i8] = c3_dv0[c3_i8];
  }

  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A1", c3_u, 1)),
                        "A1", c3_dv1);
  for (c3_i9 = 0; c3_i9 < 16; c3_i9++) {
    chartInstance->c3_A1[c3_i9] = c3_dv1[c3_i9];
  }

  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A2", c3_u, 2)),
                        "A2", c3_dv2);
  for (c3_i10 = 0; c3_i10 < 16; c3_i10++) {
    chartInstance->c3_A2[c3_i10] = c3_dv2[c3_i10];
  }

  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A3", c3_u, 3)),
                        "A3", c3_dv3);
  for (c3_i11 = 0; c3_i11 < 16; c3_i11++) {
    chartInstance->c3_A3[c3_i11] = c3_dv3[c3_i11];
  }

  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("Bc1", c3_u, 4)),
                        "Bc1", c3_dv4);
  for (c3_i12 = 0; c3_i12 < 4; c3_i12++) {
    chartInstance->c3_Bc1[c3_i12] = c3_dv4[c3_i12];
  }

  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("Bc2", c3_u, 5)),
                        "Bc2", c3_dv5);
  for (c3_i13 = 0; c3_i13 < 4; c3_i13++) {
    chartInstance->c3_Bc2[c3_i13] = c3_dv5[c3_i13];
  }

  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("Bc3", c3_u, 6)),
                        "Bc3", c3_dv6);
  for (c3_i14 = 0; c3_i14 < 4; c3_i14++) {
    chartInstance->c3_Bc3[c3_i14] = c3_dv6[c3_i14];
  }

  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("x", c3_u, 7)),
                        "x", c3_dv7);
  for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
    chartInstance->c3_x[c3_i15] = c3_dv7[c3_i15];
  }

  chartInstance->c3_is_active_c3_ESTNavigation = c3_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c3_ESTNavigation", c3_u,
       8)), "is_active_c3_ESTNavigation");
  chartInstance->c3_is_c3_ESTNavigation = c3_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c3_ESTNavigation", c3_u, 9)),
    "is_c3_ESTNavigation");
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 10)), "dataWrittenToVector", c3_bv0);
  for (c3_i16 = 0; c3_i16 < 7; c3_i16++) {
    chartInstance->c3_dataWrittenToVector[c3_i16] = c3_bv0[c3_i16];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 11)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_ESTNavigation(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_ESTNavigation
  (SFc3_ESTNavigationInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_tp_M1 = (uint8_T)(chartInstance->c3_is_c3_ESTNavigation ==
      c3_IN_M1);
    chartInstance->c3_tp_M2 = (uint8_T)(chartInstance->c3_is_c3_ESTNavigation ==
      c3_IN_M2);
    chartInstance->c3_tp_M3 = (uint8_T)(chartInstance->c3_is_c3_ESTNavigation ==
      c3_IN_M3);
    chartInstance->c3_tp_M41 = (uint8_T)(chartInstance->c3_is_c3_ESTNavigation ==
      c3_IN_M41);
    chartInstance->c3_tp_M42 = (uint8_T)(chartInstance->c3_is_c3_ESTNavigation ==
      c3_IN_M42);
    chartInstance->c3_tp_M43 = (uint8_T)(chartInstance->c3_is_c3_ESTNavigation ==
      c3_IN_M43);
    chartInstance->c3_tp_M44 = (uint8_T)(chartInstance->c3_is_c3_ESTNavigation ==
      c3_IN_M44);
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  c3_set_sim_state_side_effects_c3_ESTNavigation(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_ESTNavigation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ESTNavigationMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
}

static void c3_chartstep_c3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_d_nargout = 1.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargin = 0.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  boolean_T c3_d_out;
  int32_T c3_i17;
  int32_T c3_i18;
  real_T c3_g_nargout = 0.0;
  real_T c3_d0;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  static real_T c3_dv8[4] = { 0.4, 0.62, 0.5, 1.0 };

  int32_T c3_i23;
  int32_T c3_i24;
  real_T c3_h_nargin = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_h_nargout = 1.0;
  real_T c3_i_nargout = 1.0;
  real_T c3_j_nargout = 0.0;
  real_T c3_k_nargout = 0.0;
  boolean_T c3_e_out;
  boolean_T c3_f_out;
  int32_T c3_i25;
  int32_T c3_i26;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 0.0;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  real_T c3_m_nargin = 0.0;
  real_T c3_n_nargin = 0.0;
  int32_T c3_i30;
  real_T c3_dv9[16];
  int32_T c3_i31;
  real_T c3_dv10[16];
  real_T c3_m_nargout = 0.0;
  real_T c3_n_nargout = 1.0;
  static real_T c3_dv11[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0099,
    0.0, 0.9881, 0.0, 0.0, 0.0099, 0.0, 0.9881 };

  boolean_T c3_g_out;
  int32_T c3_i32;
  real_T c3_d6;
  real_T c3_dv12[4];
  real_T c3_dv13[4];
  real_T c3_dv14[4];
  int32_T c3_i33;
  int32_T c3_i34;
  real_T c3_o_nargin = 0.0;
  int32_T c3_i35;
  int32_T c3_i36;
  real_T c3_o_nargout = 0.0;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  static real_T c3_dv15[4] = { 0.0, 0.0, 0.0119, 0.0 };

  int32_T c3_i40;
  real_T c3_dv16[16];
  real_T c3_p_nargin = 0.0;
  int32_T c3_i41;
  real_T c3_p_nargout = 0.0;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  real_T c3_dv17[4];
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  int32_T c3_i51;
  static real_T c3_dv18[4] = { 0.0, 0.0, 0.0091, -0.0091 };

  int32_T c3_i52;
  int32_T c3_i53;
  real_T c3_dv19[16];
  int32_T c3_i54;
  int32_T c3_i55;
  real_T c3_dv20[16];
  real_T c3_dv21[4];
  int32_T c3_i56;
  int32_T c3_i57;
  real_T c3_dv22[4];
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  real_T c3_dv23[16];
  int32_T c3_i63;
  int32_T c3_i64;
  real_T c3_dv24[4];
  int32_T c3_i65;
  int32_T c3_i66;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i70;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_ESTNavigation == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_ESTNavigation = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_o_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    for (c3_i19 = 0; c3_i19 < 4; c3_i19++) {
      chartInstance->c3_x[c3_i19] = c3_dv8[c3_i19];
    }

    for (c3_i22 = 0; c3_i22 < 4; c3_i22++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i22], 6U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
    }

    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_is_c3_ESTNavigation = c3_IN_M1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_M1 = 1U;
    c3_enter_atomic_M1(chartInstance);
  } else {
    switch (chartInstance->c3_is_c3_ESTNavigation) {
     case c3_IN_M1:
      CV_CHART_EVAL(0, 0, 1);
      c3_M1(chartInstance);
      break;

     case c3_IN_M2:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_d_sf_marshallOut,
        c3_d_sf_marshallIn);
      c3_d0 = (((0.0011 * chartInstance->c3_x[0] - 1.007 * chartInstance->c3_x[1])
                + 0.0159 * chartInstance->c3_x[2]) + 0.0126 *
               chartInstance->c3_x[3]) + 1.0;
      c3_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, c3_d0, 0.0, -1,
        5U, c3_d0 >= 0.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_M2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ESTNavigation = c3_IN_M1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_M1 = 1U;
        c3_enter_atomic_M1(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_d_sf_marshallOut,
          c3_d_sf_marshallIn);
        c3_d4 = (((-1.0065 * chartInstance->c3_x[0] + 0.0031 *
                   chartInstance->c3_x[1]) + 0.0201 * chartInstance->c3_x[2]) -
                 0.0028 * chartInstance->c3_x[3]) + 1.0;
        c3_e_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0, c3_d4, 0.0,
          -1, 3U, c3_d4 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_ESTNavigation = c3_IN_M3;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M3 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i37 = 0; c3_i37 < 16; c3_i37++) {
            chartInstance->c3_A3[c3_i37] = c3_dv11[c3_i37];
          }

          chartInstance->c3_dataWrittenToVector[3U] = true;
          for (c3_i44 = 0; c3_i44 < 16; c3_i44++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A3[c3_i44], 2U, 4U, 3U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i48 = 0; c3_i48 < 4; c3_i48++) {
            chartInstance->c3_Bc3[c3_i48] = c3_dv18[c3_i48];
          }

          chartInstance->c3_dataWrittenToVector[5U] = true;
          for (c3_i52 = 0; c3_i52 < 4; c3_i52++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_Bc3[c3_i52], 5U, 4U, 3U,
                                  chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[3U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 3U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[5U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 3U,
              chartInstance->c3_sfEvent, false);
          }

          for (c3_i59 = 0; c3_i59 < 16; c3_i59++) {
            c3_dv23[c3_i59] = chartInstance->c3_A3[c3_i59];
          }

          for (c3_i62 = 0; c3_i62 < 4; c3_i62++) {
            c3_dv24[c3_i62] = chartInstance->c3_x[c3_i62];
          }

          c3_FnM(chartInstance, c3_dv23, c3_dv24, c3_dv13);
          for (c3_i66 = 0; c3_i66 < 4; c3_i66++) {
            chartInstance->c3_x[c3_i66] = c3_dv13[c3_i66] +
              chartInstance->c3_Bc3[c3_i66];
          }

          for (c3_i68 = 0; c3_i68 < 4; c3_i68++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i68], 6U, 4U, 3U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i69 = 0; c3_i69 < 4; c3_i69++) {
            (*chartInstance->c3_xout)[c3_i69] = chartInstance->c3_x[c3_i69];
          }

          for (c3_i70 = 0; c3_i70 < 4; c3_i70++) {
            _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i70], 7U, 4U, 3U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[2U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 2U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[4U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U,
              chartInstance->c3_sfEvent, false);
          }

          for (c3_i36 = 0; c3_i36 < 16; c3_i36++) {
            c3_dv16[c3_i36] = chartInstance->c3_A1[c3_i36];
          }

          for (c3_i40 = 0; c3_i40 < 4; c3_i40++) {
            c3_dv17[c3_i40] = chartInstance->c3_x[c3_i40];
          }

          c3_FnM(chartInstance, c3_dv16, c3_dv17, c3_dv13);
          for (c3_i45 = 0; c3_i45 < 4; c3_i45++) {
            chartInstance->c3_x[c3_i45] = c3_dv13[c3_i45] +
              chartInstance->c3_Bc1[c3_i45];
          }

          for (c3_i50 = 0; c3_i50 < 4; c3_i50++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i50], 6U, 4U, 2U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i54 = 0; c3_i54 < 4; c3_i54++) {
            (*chartInstance->c3_xout)[c3_i54] = chartInstance->c3_x[c3_i54];
          }

          for (c3_i56 = 0; c3_i56 < 4; c3_i56++) {
            _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i56], 7U, 4U, 2U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_M3:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_d_sf_marshallOut,
        c3_d_sf_marshallIn);
      c3_d1 = (((-0.0045 * chartInstance->c3_x[0] - 0.4971 * chartInstance->
                 c3_x[1]) + 0.0011 * chartInstance->c3_x[2]) + 0.0064 *
               chartInstance->c3_x[3]) + 1.0;
      c3_b_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, c3_d1, 0.0, -1,
        3U, c3_d1 <= 0.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_M3 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ESTNavigation = c3_IN_M41;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_M41 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        for (c3_i29 = 0; c3_i29 < 16; c3_i29++) {
          chartInstance->c3_A2[c3_i29] = c3_dv11[c3_i29];
        }

        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i32 = 0; c3_i32 < 16; c3_i32++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_A2[c3_i32], 1U, 4U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        for (c3_i35 = 0; c3_i35 < 4; c3_i35++) {
          chartInstance->c3_Bc2[c3_i35] = c3_dv15[c3_i35];
        }

        chartInstance->c3_dataWrittenToVector[1U] = true;
        for (c3_i41 = 0; c3_i41 < 4; c3_i41++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_Bc2[c3_i41], 4U, 4U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 4U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 4U,
            chartInstance->c3_sfEvent, false);
        }

        for (c3_i51 = 0; c3_i51 < 16; c3_i51++) {
          c3_dv20[c3_i51] = chartInstance->c3_A2[c3_i51];
        }

        for (c3_i55 = 0; c3_i55 < 4; c3_i55++) {
          c3_dv22[c3_i55] = chartInstance->c3_x[c3_i55];
        }

        c3_FnM(chartInstance, c3_dv20, c3_dv22, c3_dv13);
        for (c3_i58 = 0; c3_i58 < 4; c3_i58++) {
          chartInstance->c3_x[c3_i58] = c3_dv13[c3_i58] + chartInstance->
            c3_Bc2[c3_i58];
        }

        for (c3_i61 = 0; c3_i61 < 4; c3_i61++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i61], 6U, 4U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        for (c3_i64 = 0; c3_i64 < 4; c3_i64++) {
          (*chartInstance->c3_xout)[c3_i64] = chartInstance->c3_x[c3_i64];
        }

        for (c3_i67 = 0; c3_i67 < 4; c3_i67++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i67], 7U, 4U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_v_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_d_sf_marshallOut,
          c3_d_sf_marshallIn);
        c3_d5 = (((-0.4784 * chartInstance->c3_x[0] + 0.0019 *
                   chartInstance->c3_x[1]) - 0.0449 * chartInstance->c3_x[2]) +
                 0.0168 * chartInstance->c3_x[3]) + 1.0;
        c3_f_out = CV_EML_IF(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, c3_d5, 0.0,
          -1, 3U, c3_d5 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M3 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_ESTNavigation = c3_IN_M42;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M42 = 1U;
          c3_enter_atomic_M42(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_n_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U,
            c3_d_sf_marshallOut, c3_d_sf_marshallIn);
          c3_d6 = (((0.0083 * chartInstance->c3_x[0] - 1.0007 *
                     chartInstance->c3_x[1]) - 0.0166 * chartInstance->c3_x[2])
                   + 0.0139 * chartInstance->c3_x[3]) + 1.0;
          c3_g_out = CV_EML_IF(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0, c3_d6, 0.0,
            -1, 5U, c3_d6 >= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_g_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M3 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
            chartInstance->c3_is_c3_ESTNavigation = c3_IN_M1;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M1 = 1U;
            c3_enter_atomic_M1(chartInstance);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         chartInstance->c3_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
              c3_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            if (!chartInstance->c3_dataWrittenToVector[3U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 3U,
                chartInstance->c3_sfEvent, false);
            }

            if (!chartInstance->c3_dataWrittenToVector[5U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 3U,
                chartInstance->c3_sfEvent, false);
            }

            for (c3_i49 = 0; c3_i49 < 16; c3_i49++) {
              c3_dv19[c3_i49] = chartInstance->c3_A3[c3_i49];
            }

            for (c3_i53 = 0; c3_i53 < 4; c3_i53++) {
              c3_dv21[c3_i53] = chartInstance->c3_x[c3_i53];
            }

            c3_FnM(chartInstance, c3_dv19, c3_dv21, c3_dv13);
            for (c3_i57 = 0; c3_i57 < 4; c3_i57++) {
              chartInstance->c3_x[c3_i57] = c3_dv13[c3_i57] +
                chartInstance->c3_Bc3[c3_i57];
            }

            for (c3_i60 = 0; c3_i60 < 4; c3_i60++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i60], 6U, 4U, 3U,
                                    chartInstance->c3_sfEvent, false);
            }

            for (c3_i63 = 0; c3_i63 < 4; c3_i63++) {
              (*chartInstance->c3_xout)[c3_i63] = chartInstance->c3_x[c3_i63];
            }

            for (c3_i65 = 0; c3_i65 < 4; c3_i65++) {
              _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i65], 7U, 4U,
                                    3U, chartInstance->c3_sfEvent, false);
            }

            _SFD_SYMBOL_SCOPE_POP();
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_M41:
      CV_CHART_EVAL(0, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_d_sf_marshallOut,
        c3_d_sf_marshallIn);
      c3_d2 = ((-0.4904 * chartInstance->c3_x[0] - 0.0049 * chartInstance->c3_x
                [1]) + 0.003 * chartInstance->c3_x[2]) + 1.0;
      c3_c_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, c3_d2, 0.0, -1,
        3U, c3_d2 <= 0.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_M41 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ESTNavigation = c3_IN_M42;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_M42 = 1U;
        c3_enter_atomic_M42(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 4U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 4U,
            chartInstance->c3_sfEvent, false);
        }

        for (c3_i27 = 0; c3_i27 < 16; c3_i27++) {
          c3_dv9[c3_i27] = chartInstance->c3_A2[c3_i27];
        }

        for (c3_i30 = 0; c3_i30 < 4; c3_i30++) {
          c3_dv12[c3_i30] = chartInstance->c3_x[c3_i30];
        }

        c3_FnM(chartInstance, c3_dv9, c3_dv12, c3_dv13);
        for (c3_i33 = 0; c3_i33 < 4; c3_i33++) {
          chartInstance->c3_x[c3_i33] = c3_dv13[c3_i33] + chartInstance->
            c3_Bc2[c3_i33];
        }

        for (c3_i38 = 0; c3_i38 < 4; c3_i38++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i38], 6U, 4U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        for (c3_i42 = 0; c3_i42 < 4; c3_i42++) {
          (*chartInstance->c3_xout)[c3_i42] = chartInstance->c3_x[c3_i42];
        }

        for (c3_i46 = 0; c3_i46 < 4; c3_i46++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i46], 7U, 4U, 4U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_M42:
      CV_CHART_EVAL(0, 0, 5);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_d_sf_marshallOut,
        c3_d_sf_marshallIn);
      c3_d3 = (((0.0054 * chartInstance->c3_x[0] - 0.971 * chartInstance->c3_x[1])
                - 0.0176 * chartInstance->c3_x[2]) + 0.0521 *
               chartInstance->c3_x[3]) + 1.0;
      c3_d_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, c3_d3, 0.0, -1,
        5U, c3_d3 >= 0.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_M42 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ESTNavigation = c3_IN_M43;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_M43 = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[4U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 5U,
            chartInstance->c3_sfEvent, false);
        }

        for (c3_i28 = 0; c3_i28 < 16; c3_i28++) {
          c3_dv10[c3_i28] = chartInstance->c3_A1[c3_i28];
        }

        for (c3_i31 = 0; c3_i31 < 4; c3_i31++) {
          c3_dv14[c3_i31] = chartInstance->c3_x[c3_i31];
        }

        c3_FnM(chartInstance, c3_dv10, c3_dv14, c3_dv13);
        for (c3_i34 = 0; c3_i34 < 4; c3_i34++) {
          chartInstance->c3_x[c3_i34] = c3_dv13[c3_i34] + chartInstance->
            c3_Bc1[c3_i34];
        }

        for (c3_i39 = 0; c3_i39 < 4; c3_i39++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i39], 6U, 4U, 5U,
                                chartInstance->c3_sfEvent, false);
        }

        for (c3_i43 = 0; c3_i43 < 4; c3_i43++) {
          (*chartInstance->c3_xout)[c3_i43] = chartInstance->c3_x[c3_i43];
        }

        for (c3_i47 = 0; c3_i47 < 4; c3_i47++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i47], 7U, 4U, 5U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_M43:
      CV_CHART_EVAL(0, 0, 6);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      for (c3_i17 = 0; c3_i17 < 4; c3_i17++) {
        chartInstance->c3_x[c3_i17] = -1.0;
      }

      for (c3_i20 = 0; c3_i20 < 4; c3_i20++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i20], 6U, 4U, 6U,
                              chartInstance->c3_sfEvent, false);
      }

      for (c3_i23 = 0; c3_i23 < 4; c3_i23++) {
        (*chartInstance->c3_xout)[c3_i23] = chartInstance->c3_x[c3_i23];
      }

      for (c3_i25 = 0; c3_i25 < 4; c3_i25++) {
        _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i25], 7U, 4U, 6U,
                              chartInstance->c3_sfEvent, false);
      }

      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_M44:
      CV_CHART_EVAL(0, 0, 7);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_m_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      for (c3_i18 = 0; c3_i18 < 4; c3_i18++) {
        chartInstance->c3_x[c3_i18] = -1.0;
      }

      for (c3_i21 = 0; c3_i21 < 4; c3_i21++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i21], 6U, 4U, 7U,
                              chartInstance->c3_sfEvent, false);
      }

      for (c3_i24 = 0; c3_i24 < 4; c3_i24++) {
        (*chartInstance->c3_xout)[c3_i24] = chartInstance->c3_x[c3_i24];
      }

      for (c3_i26 = 0; c3_i26 < 4; c3_i26++) {
        _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i26], 7U, 4U, 7U,
                              chartInstance->c3_sfEvent, false);
      }

      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c3_is_c3_ESTNavigation = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_ESTNavigation(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_enter_atomic_M42(SFc3_ESTNavigationInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i71;
  static real_T c3_dv25[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0099,
    0.0, 0.9881, 0.0, 0.0, 0.0099, 0.0, 0.9881 };

  int32_T c3_i72;
  int32_T c3_i73;
  static real_T c3_dv26[4] = { 0.0, 0.0, 0.0, -0.0119 };

  int32_T c3_i74;
  int32_T c3_i75;
  int32_T c3_i76;
  real_T c3_dv27[16];
  real_T c3_dv28[4];
  real_T c3_dv29[4];
  int32_T c3_i77;
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i80;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  for (c3_i71 = 0; c3_i71 < 16; c3_i71++) {
    chartInstance->c3_A1[c3_i71] = c3_dv25[c3_i71];
  }

  chartInstance->c3_dataWrittenToVector[2U] = true;
  for (c3_i72 = 0; c3_i72 < 16; c3_i72++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_A1[c3_i72], 0U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
  }

  for (c3_i73 = 0; c3_i73 < 4; c3_i73++) {
    chartInstance->c3_Bc1[c3_i73] = c3_dv26[c3_i73];
  }

  chartInstance->c3_dataWrittenToVector[4U] = true;
  for (c3_i74 = 0; c3_i74 < 4; c3_i74++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Bc1[c3_i74], 3U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
  }

  if (!chartInstance->c3_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
      false);
  }

  if (!chartInstance->c3_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 5U, chartInstance->c3_sfEvent,
      false);
  }

  for (c3_i75 = 0; c3_i75 < 16; c3_i75++) {
    c3_dv27[c3_i75] = chartInstance->c3_A1[c3_i75];
  }

  for (c3_i76 = 0; c3_i76 < 4; c3_i76++) {
    c3_dv28[c3_i76] = chartInstance->c3_x[c3_i76];
  }

  c3_FnM(chartInstance, c3_dv27, c3_dv28, c3_dv29);
  for (c3_i77 = 0; c3_i77 < 4; c3_i77++) {
    chartInstance->c3_x[c3_i77] = c3_dv29[c3_i77] + chartInstance->c3_Bc1[c3_i77];
  }

  for (c3_i78 = 0; c3_i78 < 4; c3_i78++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i78], 6U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
  }

  for (c3_i79 = 0; c3_i79 < 4; c3_i79++) {
    (*chartInstance->c3_xout)[c3_i79] = chartInstance->c3_x[c3_i79];
  }

  for (c3_i80 = 0; c3_i80 < 4; c3_i80++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i80], 7U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_atomic_M1(SFc3_ESTNavigationInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i81;
  static real_T c3_dv30[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0099,
    0.0, 0.9881, 0.0, 0.0, 0.0099, 0.0, 0.9881 };

  int32_T c3_i82;
  int32_T c3_i83;
  static real_T c3_dv31[4] = { 0.0, 0.0, 0.0119, 0.0 };

  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  real_T c3_dv32[16];
  real_T c3_dv33[4];
  real_T c3_dv34[4];
  int32_T c3_i87;
  int32_T c3_i88;
  int32_T c3_i89;
  int32_T c3_i90;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  for (c3_i81 = 0; c3_i81 < 16; c3_i81++) {
    chartInstance->c3_A2[c3_i81] = c3_dv30[c3_i81];
  }

  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i82 = 0; c3_i82 < 16; c3_i82++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_A2[c3_i82], 1U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
  }

  for (c3_i83 = 0; c3_i83 < 4; c3_i83++) {
    chartInstance->c3_Bc2[c3_i83] = c3_dv31[c3_i83];
  }

  chartInstance->c3_dataWrittenToVector[1U] = true;
  for (c3_i84 = 0; c3_i84 < 4; c3_i84++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Bc2[c3_i84], 4U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
  }

  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
      false);
  }

  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 1U, chartInstance->c3_sfEvent,
      false);
  }

  for (c3_i85 = 0; c3_i85 < 16; c3_i85++) {
    c3_dv32[c3_i85] = chartInstance->c3_A2[c3_i85];
  }

  for (c3_i86 = 0; c3_i86 < 4; c3_i86++) {
    c3_dv33[c3_i86] = chartInstance->c3_x[c3_i86];
  }

  c3_FnM(chartInstance, c3_dv32, c3_dv33, c3_dv34);
  for (c3_i87 = 0; c3_i87 < 4; c3_i87++) {
    chartInstance->c3_x[c3_i87] = c3_dv34[c3_i87] + chartInstance->c3_Bc2[c3_i87];
  }

  for (c3_i88 = 0; c3_i88 < 4; c3_i88++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i88], 6U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
  }

  for (c3_i89 = 0; c3_i89 < 4; c3_i89++) {
    (*chartInstance->c3_xout)[c3_i89] = chartInstance->c3_x[c3_i89];
  }

  for (c3_i90 = 0; c3_i90 < 4; c3_i90++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i90], 7U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_M1(SFc3_ESTNavigationInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_d7;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d8;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  int32_T c3_i91;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  static real_T c3_dv35[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0099,
    0.0, 0.9881, 0.0, 0.0, 0.0099, 0.0, 0.9881 };

  int32_T c3_i92;
  int32_T c3_i93;
  int32_T c3_i94;
  static real_T c3_dv36[4] = { 0.0, 0.0, 0.0, -0.0119 };

  int32_T c3_i95;
  real_T c3_dv37[16];
  int32_T c3_i96;
  real_T c3_dv38[4];
  real_T c3_dv39[4];
  int32_T c3_i97;
  int32_T c3_i98;
  int32_T c3_i99;
  int32_T c3_i100;
  int32_T c3_i101;
  real_T c3_dv40[16];
  int32_T c3_i102;
  real_T c3_dv41[4];
  int32_T c3_i103;
  int32_T c3_i104;
  int32_T c3_i105;
  int32_T c3_i106;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  c3_d7 = (((0.0049 * chartInstance->c3_x[0] - 0.998 * chartInstance->c3_x[1]) -
            0.0134 * chartInstance->c3_x[2]) + 0.0217 * chartInstance->c3_x[3])
    + 1.0;
  c3_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, c3_d7, 0.0, -1, 3U,
    c3_d7 <= 0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_M1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_ESTNavigation = c3_IN_M2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_M2 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    for (c3_i91 = 0; c3_i91 < 16; c3_i91++) {
      chartInstance->c3_A1[c3_i91] = c3_dv35[c3_i91];
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    for (c3_i92 = 0; c3_i92 < 16; c3_i92++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_A1[c3_i92], 0U, 4U, 2U,
                            chartInstance->c3_sfEvent, false);
    }

    for (c3_i93 = 0; c3_i93 < 4; c3_i93++) {
      chartInstance->c3_Bc1[c3_i93] = c3_dv36[c3_i93];
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    for (c3_i96 = 0; c3_i96 < 4; c3_i96++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_Bc1[c3_i96], 3U, 4U, 2U,
                            chartInstance->c3_sfEvent, false);
    }

    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    for (c3_i99 = 0; c3_i99 < 16; c3_i99++) {
      c3_dv40[c3_i99] = chartInstance->c3_A1[c3_i99];
    }

    for (c3_i101 = 0; c3_i101 < 4; c3_i101++) {
      c3_dv41[c3_i101] = chartInstance->c3_x[c3_i101];
    }

    c3_FnM(chartInstance, c3_dv40, c3_dv41, c3_dv39);
    for (c3_i103 = 0; c3_i103 < 4; c3_i103++) {
      chartInstance->c3_x[c3_i103] = c3_dv39[c3_i103] + chartInstance->
        c3_Bc1[c3_i103];
    }

    for (c3_i104 = 0; c3_i104 < 4; c3_i104++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i104], 6U, 4U, 2U,
                            chartInstance->c3_sfEvent, false);
    }

    for (c3_i105 = 0; c3_i105 < 4; c3_i105++) {
      (*chartInstance->c3_xout)[c3_i105] = chartInstance->c3_x[c3_i105];
    }

    for (c3_i106 = 0; c3_i106 < 4; c3_i106++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i106], 7U, 4U, 2U,
                            chartInstance->c3_sfEvent, false);
    }

    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_w_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    c3_d8 = ((-0.5018 * chartInstance->c3_x[0] + 0.0067 * chartInstance->c3_x[2])
             - 0.003 * chartInstance->c3_x[3]) + 1.0;
    c3_b_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, c3_d8, 0.0, -1,
      3U, c3_d8 <= 0.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_M1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_ESTNavigation = c3_IN_M44;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_M44 = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[0U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
          false);
      }

      if (!chartInstance->c3_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 1U, chartInstance->c3_sfEvent,
          false);
      }

      for (c3_i94 = 0; c3_i94 < 16; c3_i94++) {
        c3_dv37[c3_i94] = chartInstance->c3_A2[c3_i94];
      }

      for (c3_i95 = 0; c3_i95 < 4; c3_i95++) {
        c3_dv38[c3_i95] = chartInstance->c3_x[c3_i95];
      }

      c3_FnM(chartInstance, c3_dv37, c3_dv38, c3_dv39);
      for (c3_i97 = 0; c3_i97 < 4; c3_i97++) {
        chartInstance->c3_x[c3_i97] = c3_dv39[c3_i97] + chartInstance->
          c3_Bc2[c3_i97];
      }

      for (c3_i98 = 0; c3_i98 < 4; c3_i98++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i98], 6U, 4U, 1U,
                              chartInstance->c3_sfEvent, false);
      }

      for (c3_i100 = 0; c3_i100 < 4; c3_i100++) {
        (*chartInstance->c3_xout)[c3_i100] = chartInstance->c3_x[c3_i100];
      }

      for (c3_i102 = 0; c3_i102 < 4; c3_i102++) {
        _SFD_DATA_RANGE_CHECK((*chartInstance->c3_xout)[c3_i102], 7U, 4U, 1U,
                              chartInstance->c3_sfEvent, false);
      }

      _SFD_SYMBOL_SCOPE_POP();
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
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
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
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
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
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
  int32_T c3_i107;
  const mxArray *c3_y = NULL;
  real_T c3_u[4];
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i107 = 0; c3_i107 < 4; c3_i107++) {
    c3_u[c3_i107] = (*(real_T (*)[4])c3_inData)[c3_i107];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_b_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_y, const char_T *c3_identifier, real_T
  c3_b_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_y), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_y);
}

static void c3_c_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4])
{
  real_T c3_dv42[4];
  int32_T c3_i108;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv42, 1, 0, 0U, 1, 0U, 1, 4);
  for (c3_i108 = 0; c3_i108 < 4; c3_i108++) {
    c3_y[c3_i108] = c3_dv42[c3_i108];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[4];
  int32_T c3_i109;
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_y), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_y);
  for (c3_i109 = 0; c3_i109 < 4; c3_i109++) {
    (*(real_T (*)[4])c3_outData)[c3_i109] = c3_b_y[c3_i109];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i110;
  int32_T c3_i111;
  const mxArray *c3_y = NULL;
  int32_T c3_i112;
  real_T c3_u[16];
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_i110 = 0;
  for (c3_i111 = 0; c3_i111 < 4; c3_i111++) {
    for (c3_i112 = 0; c3_i112 < 4; c3_i112++) {
      c3_u[c3_i112 + c3_i110] = (*(real_T (*)[16])c3_inData)[c3_i112 + c3_i110];
    }

    c3_i110 += 4;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 4, 4), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u1, const char_T *c3_identifier, real_T
  c3_y[16])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_u1), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_u1);
}

static void c3_e_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[16])
{
  real_T c3_dv43[16];
  int32_T c3_i113;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv43, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c3_i113 = 0; c3_i113 < 16; c3_i113++) {
    c3_y[c3_i113] = c3_dv43[c3_i113];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_u1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[16];
  int32_T c3_i114;
  int32_T c3_i115;
  int32_T c3_i116;
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_u1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_u1), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_u1);
  c3_i114 = 0;
  for (c3_i115 = 0; c3_i115 < 4; c3_i115++) {
    for (c3_i116 = 0; c3_i116 < 4; c3_i116++) {
      (*(real_T (*)[16])c3_outData)[c3_i116 + c3_i114] = c3_y[c3_i116 + c3_i114];
    }

    c3_i114 += 4;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_f_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
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

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_ESTNavigation_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_FnM(SFc3_ESTNavigationInstanceStruct *chartInstance, real_T
                   c3_u1[16], real_T c3_u2[4], real_T c3_y[4])
{
  uint32_T c3_debug_family_var_map[5];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i117;
  int32_T c3_i118;
  real_T c3_a[16];
  int32_T c3_i119;
  real_T c3_b[4];
  int32_T c3_i120;
  int32_T c3_i121;
  int32_T c3_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_u1, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_u2, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_y, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 2);
  for (c3_i117 = 0; c3_i117 < 16; c3_i117++) {
    c3_a[c3_i117] = c3_u1[c3_i117];
  }

  for (c3_i118 = 0; c3_i118 < 4; c3_i118++) {
    c3_b[c3_i118] = c3_u2[c3_i118];
  }

  for (c3_i119 = 0; c3_i119 < 4; c3_i119++) {
    c3_y[c3_i119] = 0.0;
  }

  for (c3_i120 = 0; c3_i120 < 4; c3_i120++) {
    c3_y[c3_i120] = 0.0;
    c3_i121 = 0;
    for (c3_i122 = 0; c3_i122 < 4; c3_i122++) {
      c3_y[c3_i120] += c3_a[c3_i121 + c3_i120] * c3_b[c3_i122];
      c3_i121 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_g_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i123;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i123, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i123;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_M2, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_M2), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_M2);
  return c3_y;
}

static uint8_T c3_i_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
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

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_M2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_b_tp_M2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_M2), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_M2);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i124;
  const mxArray *c3_y = NULL;
  real_T c3_u[4];
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i124 = 0; c3_i124 < 4; c3_i124++) {
    c3_u[c3_i124] = (*(real_T (*)[4])c3_inData)[c3_i124];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 4, 1), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_j_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_Bc2, const char_T *c3_identifier, real_T
  c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Bc2), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_Bc2);
}

static void c3_k_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4])
{
  real_T c3_dv44[4];
  int32_T c3_i125;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv44, 1, 0, 0U, 1, 0U, 2, 4, 1);
  for (c3_i125 = 0; c3_i125 < 4; c3_i125++) {
    c3_y[c3_i125] = c3_dv44[c3_i125];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_Bc2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[4];
  int32_T c3_i126;
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_b_Bc2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Bc2), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_Bc2);
  for (c3_i126 = 0; c3_i126 < 4; c3_i126++) {
    (*(real_T (*)[4])c3_outData)[c3_i126] = c3_y[c3_i126];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_l_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[7])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_m_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[7])
{
  boolean_T c3_bv1[7];
  int32_T c3_i127;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 7);
  for (c3_i127 = 0; c3_i127 < 7; c3_i127++) {
    c3_y[c3_i127] = c3_bv1[c3_i127];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_n_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_o_emlrt_marshallIn(SFc3_ESTNavigationInstanceStruct
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

static const mxArray *sf_get_hover_data_for_msg(SFc3_ESTNavigationInstanceStruct
  *chartInstance, int32_T c3_ssid)
{
  const mxArray *c3_msgInfo;
  (void)chartInstance;
  (void)c3_ssid;
  c3_msgInfo = NULL;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_ESTNavigationInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_xout = (real_T (*)[4])ssGetOutputPortSignal_wrapper
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

void sf_c3_ESTNavigation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3456559005U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1444174741U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3081797073U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1352914422U);
}

mxArray* sf_c3_ESTNavigation_get_post_codegen_info(void);
mxArray *sf_c3_ESTNavigation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("t5KlxmDdJ9UalfY7qawmsH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
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
      pr[0] = (double)(4);
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_ESTNavigation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_ESTNavigation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_ESTNavigation_jit_fallback_info(void)
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

mxArray *sf_c3_ESTNavigation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_ESTNavigation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_ESTNavigation(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[28],T\"xout\",},{M[3],M[29],T\"A1\",},{M[3],M[25],T\"A2\",},{M[3],M[30],T\"A3\",},{M[3],M[31],T\"Bc1\",},{M[3],M[26],T\"Bc2\",},{M[3],M[32],T\"Bc3\",},{M[3],M[27],T\"x\",},{M[8],M[0],T\"is_active_c3_ESTNavigation\",},{M[9],M[0],T\"is_c3_ESTNavigation\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ESTNavigation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_ESTNavigationInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ESTNavigationInstanceStruct *chartInstance =
      (SFc3_ESTNavigationInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ESTNavigationMachineNumber_,
           3,
           8,
           10,
           0,
           11,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_ESTNavigationMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ESTNavigationMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ESTNavigationMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"A1");
          _SFD_SET_DATA_PROPS(1,0,0,0,"A2");
          _SFD_SET_DATA_PROPS(2,0,0,0,"A3");
          _SFD_SET_DATA_PROPS(3,0,0,0,"Bc1");
          _SFD_SET_DATA_PROPS(4,0,0,0,"Bc2");
          _SFD_SET_DATA_PROPS(5,0,0,0,"Bc3");
          _SFD_SET_DATA_PROPS(6,0,0,0,"x");
          _SFD_SET_DATA_PROPS(7,2,0,1,"xout");
          _SFD_SET_DATA_PROPS(8,8,0,0,"");
          _SFD_SET_DATA_PROPS(9,8,0,0,"");
          _SFD_SET_DATA_PROPS(10,9,0,0,"");
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(7);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_CH_SUBSTATE_INDEX(1,2);
          _SFD_CH_SUBSTATE_INDEX(2,3);
          _SFD_CH_SUBSTATE_INDEX(3,4);
          _SFD_CH_SUBSTATE_INDEX(4,5);
          _SFD_CH_SUBSTATE_INDEX(5,6);
          _SFD_CH_SUBSTATE_INDEX(6,7);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
        }

        _SFD_CV_INIT_CHART(7,1,0,0);

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"FnM",0,-1,38);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,55,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,1,55,-1,5);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,56,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,2,56,-1,3);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,57,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,57,-1,3);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,57,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,57,-1,3);
        _SFD_CV_INIT_EML(7,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,44,1,44);
        _SFD_CV_INIT_EML_RELATIONAL(7,0,0,1,44,-1,3);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,55,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,55,-1,5);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,56,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,2,56,-1,5);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,57,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,57,-1,3);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,44,1,44);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,44,-1,3);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 1U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_g_sf_marshallOut,(MexInFcnForType)
            c3_g_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 1U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_g_sf_marshallOut,(MexInFcnForType)
            c3_g_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 1U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_g_sf_marshallOut,(MexInFcnForType)
            c3_g_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ESTNavigationMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ESTNavigationInstanceStruct *chartInstance =
      (SFc3_ESTNavigationInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c3_A2);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)&chartInstance->c3_Bc2);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)&chartInstance->c3_x);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c3_xout);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c3_A1);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c3_A3);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)&chartInstance->c3_Bc1);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)&chartInstance->c3_Bc3);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sNuTEZzwNlN8mQaGSWnucYE";
}

static void sf_opaque_initialize_c3_ESTNavigation(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ESTNavigationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_ESTNavigation((SFc3_ESTNavigationInstanceStruct*)
    chartInstanceVar);
  initialize_c3_ESTNavigation((SFc3_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_ESTNavigation(void *chartInstanceVar)
{
  enable_c3_ESTNavigation((SFc3_ESTNavigationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_ESTNavigation(void *chartInstanceVar)
{
  disable_c3_ESTNavigation((SFc3_ESTNavigationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_ESTNavigation(void *chartInstanceVar)
{
  sf_gateway_c3_ESTNavigation((SFc3_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_ESTNavigation(SimStruct* S)
{
  return get_sim_state_c3_ESTNavigation((SFc3_ESTNavigationInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_ESTNavigation(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c3_ESTNavigation((SFc3_ESTNavigationInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_ESTNavigation(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ESTNavigationInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ESTNavigation_optimization_info();
    }

    finalize_c3_ESTNavigation((SFc3_ESTNavigationInstanceStruct*)
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
  initSimStructsc3_ESTNavigation((SFc3_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ESTNavigation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_ESTNavigation((SFc3_ESTNavigationInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_ESTNavigation(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ESTNavigation_optimization_info
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
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1164821357U));
  ssSetChecksum1(S,(2189114516U));
  ssSetChecksum2(S,(2997569085U));
  ssSetChecksum3(S,(4287668479U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_ESTNavigation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_ESTNavigation(SimStruct *S)
{
  SFc3_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTNavigationInstanceStruct *)utMalloc(sizeof
    (SFc3_ESTNavigationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_ESTNavigationInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_ESTNavigation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_ESTNavigation;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_ESTNavigation;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_ESTNavigation;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_ESTNavigation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_ESTNavigation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_ESTNavigation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_ESTNavigation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ESTNavigation;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ESTNavigation;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_ESTNavigation;
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
  mdl_start_c3_ESTNavigation(chartInstance);
}

void c3_ESTNavigation_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ESTNavigation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ESTNavigation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ESTNavigation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ESTNavigation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
