/* Include files */

#include "con_ESTNavigation_sfun.h"
#include "c3_con_ESTNavigation.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "con_ESTNavigation_sfun_debug_macros.h"
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

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

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

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

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

/* Function Declarations */
static void initialize_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance);
static void initialize_params_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static void enable_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance);
static void disable_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static void set_sim_state_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static void finalize_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance);
static void sf_gateway_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance);
static void mdl_start_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct *
  chartInstance);
static void zeroCrossings_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static void derivatives_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static void outputs_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance);
static void initSimStructsc3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static void c3_eml_ini_fcn_to_be_inlined_582
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static void c3_eml_term_fcn_to_be_inlined_582
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_emlrt_marshallOut(SFc3_con_ESTNavigationInstanceStruct *
  chartInstance, const real_T c3_u);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const boolean_T c3_u);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier);
static boolean_T c3_d_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const int32_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_sfEvent, const char_T *c3_identifier);
static int32_T c3_f_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const uint8_T c3_u);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_M44, const char_T *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const real_T c3_u[16]);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_i_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_A2, const char_T *c3_identifier, real_T
  c3_y[16]);
static void c3_j_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[16]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const real_T c3_u[4]);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_k_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_B1, const char_T *c3_identifier, real_T
  c3_y[4]);
static void c3_l_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4]);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance);
static const mxArray *c3_h_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const boolean_T c3_u[14]);
static void c3_m_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u);
static void c3_n_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[14]);
static void c3_o_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[14]);
static const mxArray *c3_p_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_q_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
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
  chartInstance->c3_is_active_c3_con_ESTNavigation = 0U;
  chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_con_ESTNavigation == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M44) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M41) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M42) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M43) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  const mxArray *c3_st = NULL;
  c3_st = NULL;
  sf_mex_assign(&c3_st, c3_g_emlrt_marshallOut(chartInstance), false);
  return c3_st;
}

static void set_sim_state_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const mxArray *c3_st)
{
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_st));
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_con_ESTNavigation(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_tp_M1 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M1);
    chartInstance->c3_tp_M2 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M2);
    chartInstance->c3_tp_M3 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M3);
    chartInstance->c3_tp_M41 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M41);
    chartInstance->c3_tp_M42 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M42);
    chartInstance->c3_tp_M43 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M43);
    chartInstance->c3_tp_M44 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTNavigation == c3_IN_M44);
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_h_nargin = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_l_nargin = 0.0;
  real_T c3_h_nargout = 1.0;
  real_T c3_i_nargout = 1.0;
  real_T c3_j_nargout = 1.0;
  real_T c3_k_nargout = 1.0;
  real_T c3_l_nargout = 1.0;
  real_T c3_m_nargin = 0.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  boolean_T c3_d_out;
  boolean_T c3_e_out;
  real_T c3_m_nargout = 0.0;
  real_T c3_n_nargin = 0.0;
  real_T c3_o_nargin = 0.0;
  real_T c3_p_nargin = 0.0;
  real_T c3_n_nargout = 1.0;
  real_T c3_o_nargout = 1.0;
  real_T c3_p_nargout = 1.0;
  boolean_T c3_f_out;
  boolean_T c3_g_out;
  boolean_T c3_h_out;
  real_T c3_q_nargin = 0.0;
  real_T c3_q_nargout = 0.0;
  real_T c3_r_nargin = 0.0;
  real_T c3_s_nargin = 0.0;
  real_T c3_t_nargin = 0.0;
  real_T c3_u_nargin = 0.0;
  int32_T c3_i0;
  real_T c3_r_nargout = 0.0;
  real_T c3_s_nargout = 0.0;
  real_T c3_t_nargout = 0.0;
  real_T c3_u_nargout = 0.0;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  static real_T c3_dv0[16] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0,
    -0.12, 0.01, 0.0, 0.1, 0.01, -0.12 };

  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  real_T c3_v_nargin = 0.0;
  static real_T c3_dv1[4] = { 0.0, 0.0, 0.01, -0.12 };

  real_T c3_v_nargout = 1.0;
  int32_T c3_i15;
  static real_T c3_dv2[4] = { 0.0, 0.0, 0.12, -0.01 };

  boolean_T c3_i_out;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  real_T c3_w_nargin = 0.0;
  real_T c3_x_nargin = 0.0;
  real_T c3_w_nargout = 0.0;
  real_T c3_x_nargout = 0.0;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  static real_T c3_dv3[4] = { 0.0, 0.0, 0.0919, -0.0919 };

  int32_T c3_i26;
  int32_T c3_i27;
  real_T c3_y_nargin = 0.0;
  real_T c3_y_nargout = 0.0;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  int32_T c3_i31;
  c3_set_sim_state_side_effects_c3_con_ESTNavigation(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0U) {
    chartInstance->c3_lastMajorTime = _sfTime_;
    chartInstance->c3_stateChanged = (boolean_T)0;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_sfEvent = CALL_EVENT;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_is_active_c3_con_ESTNavigation == 0U) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_active_c3_con_ESTNavigation = 1U;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_n_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_x1 = 0.4;
      chartInstance->c3_dataWrittenToVector[10U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1, 6U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
      *chartInstance->c3_x2 = 0.62;
      chartInstance->c3_dataWrittenToVector[11U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2, 7U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
      *chartInstance->c3_x3 = 0.5;
      chartInstance->c3_dataWrittenToVector[12U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x3, 8U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
      *chartInstance->c3_x4 = 1.0;
      chartInstance->c3_dataWrittenToVector[13U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x4, 9U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_M1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      for (c3_i1 = 0; c3_i1 < 16; c3_i1++) {
        chartInstance->c3_A2[c3_i1] = c3_dv0[c3_i1];
      }

      chartInstance->c3_dataWrittenToVector[0U] = true;
      for (c3_i6 = 0; c3_i6 < 16; c3_i6++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_A2[c3_i6], 1U, 4U, 0U,
                              chartInstance->c3_sfEvent, false);
      }

      for (c3_i11 = 0; c3_i11 < 4; c3_i11++) {
        chartInstance->c3_B2[c3_i11] = c3_dv2[c3_i11];
      }

      chartInstance->c3_dataWrittenToVector[8U] = true;
      for (c3_i16 = 0; c3_i16 < 4; c3_i16++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_B2[c3_i16], 4U, 4U, 0U,
                              chartInstance->c3_sfEvent, false);
      }

      _SFD_SYMBOL_SCOPE_POP();
    } else {
      switch (chartInstance->c3_is_c3_con_ESTNavigation) {
       case c3_IN_M1:
        CV_CHART_EVAL(0, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        c3_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (((0.0049 *
          *chartInstance->c3_x1 - 0.998 * *chartInstance->c3_x2) - 0.0134 *
          *chartInstance->c3_x3) + 0.0217 * *chartInstance->c3_x4) + 1.0, 0.0,
          -1, 3U, (((0.0049 * *chartInstance->c3_x1 - 0.998 *
                     *chartInstance->c3_x2) - 0.0134 * *chartInstance->c3_x3) +
                   0.0217 * *chartInstance->c3_x4) + 1.0 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M2 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_s_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_s_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i2 = 0; c3_i2 < 16; c3_i2++) {
            chartInstance->c3_A1[c3_i2] = c3_dv0[c3_i2];
          }

          chartInstance->c3_dataWrittenToVector[1U] = true;
          for (c3_i7 = 0; c3_i7 < 16; c3_i7++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A1[c3_i7], 0U, 4U, 1U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i12 = 0; c3_i12 < 4; c3_i12++) {
            chartInstance->c3_B1[c3_i12] = c3_dv1[c3_i12];
          }

          chartInstance->c3_dataWrittenToVector[7U] = true;
          for (c3_i17 = 0; c3_i17 < 4; c3_i17++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B1[c3_i17], 3U, 4U, 1U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_v_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 4U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[12U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 4U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[13U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 4U,
              chartInstance->c3_sfEvent, false);
          }

          c3_f_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, ((-0.5018 *
            *chartInstance->c3_x1 + 0.0067 * *chartInstance->c3_x3) - 0.003 *
            *chartInstance->c3_x4) + 1.0, 0.0, -1, 3U, ((-0.5018 *
            *chartInstance->c3_x1 + 0.0067 * *chartInstance->c3_x3) - 0.003 *
            *chartInstance->c3_x4) + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M1 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
            chartInstance->c3_stateChanged = true;
            chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M44;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M44 = 1U;
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
          }
        }
        break;

       case c3_IN_M2:
        CV_CHART_EVAL(0, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        c3_b_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (((0.0011 * *
          chartInstance->c3_x1 - 1.007 * *chartInstance->c3_x2) + 0.0159 *
          *chartInstance->c3_x3) + 0.0126 * *chartInstance->c3_x4) + 1.0, 0.0,
          -1, 5U, (((0.0011 * *chartInstance->c3_x1 - 1.007 *
                     *chartInstance->c3_x2) + 0.0159 * *chartInstance->c3_x3) +
                   0.0126 * *chartInstance->c3_x4) + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M1 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_t_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_t_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i3 = 0; c3_i3 < 16; c3_i3++) {
            chartInstance->c3_A2[c3_i3] = c3_dv0[c3_i3];
          }

          chartInstance->c3_dataWrittenToVector[0U] = true;
          for (c3_i8 = 0; c3_i8 < 16; c3_i8++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A2[c3_i8], 1U, 4U, 0U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i13 = 0; c3_i13 < 4; c3_i13++) {
            chartInstance->c3_B2[c3_i13] = c3_dv2[c3_i13];
          }

          chartInstance->c3_dataWrittenToVector[8U] = true;
          for (c3_i18 = 0; c3_i18 < 4; c3_i18++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B2[c3_i18], 4U, 4U, 0U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 5U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[11U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 5U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[12U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 5U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[13U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 5U,
              chartInstance->c3_sfEvent, false);
          }

          c3_g_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0, (((-1.0065
            * *chartInstance->c3_x1 + 0.0031 * *chartInstance->c3_x2) + 0.0201 *
            *chartInstance->c3_x3) - 0.0028 * *chartInstance->c3_x4) + 1.0, 0.0,
            -1, 3U, (((-1.0065 * *chartInstance->c3_x1 + 0.0031 *
                       *chartInstance->c3_x2) + 0.0201 * *chartInstance->c3_x3)
                     - 0.0028 * *chartInstance->c3_x4) + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_g_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M2 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
            chartInstance->c3_stateChanged = true;
            chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M3;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M3 = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
              c3_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_w_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_w_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            for (c3_i20 = 0; c3_i20 < 16; c3_i20++) {
              chartInstance->c3_A3[c3_i20] = c3_dv0[c3_i20];
            }

            chartInstance->c3_dataWrittenToVector[2U] = true;
            for (c3_i22 = 0; c3_i22 < 16; c3_i22++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_A3[c3_i22], 2U, 4U, 2U,
                                    chartInstance->c3_sfEvent, false);
            }

            for (c3_i24 = 0; c3_i24 < 4; c3_i24++) {
              chartInstance->c3_B3[c3_i24] = c3_dv3[c3_i24];
            }

            chartInstance->c3_dataWrittenToVector[9U] = true;
            for (c3_i26 = 0; c3_i26 < 4; c3_i26++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_B3[c3_i26], 5U, 4U, 2U,
                                    chartInstance->c3_sfEvent, false);
            }

            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
          }
        }
        break;

       case c3_IN_M3:
        CV_CHART_EVAL(0, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 6U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 6U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 6U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 6U,
            chartInstance->c3_sfEvent, false);
        }

        c3_c_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, (((-0.0045 *
          *chartInstance->c3_x1 - 0.4971 * *chartInstance->c3_x2) + 0.0011 *
          *chartInstance->c3_x3) + 0.0064 * *chartInstance->c3_x4) + 1.0, 0.0,
          -1, 3U, (((-0.0045 * *chartInstance->c3_x1 - 0.4971 *
                     *chartInstance->c3_x2) + 0.0011 * *chartInstance->c3_x3) +
                   0.0064 * *chartInstance->c3_x4) + 1.0 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M3 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M41;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M41 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_u_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_u_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i4 = 0; c3_i4 < 16; c3_i4++) {
            chartInstance->c3_A2[c3_i4] = c3_dv0[c3_i4];
          }

          chartInstance->c3_dataWrittenToVector[0U] = true;
          for (c3_i9 = 0; c3_i9 < 16; c3_i9++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A2[c3_i9], 1U, 4U, 3U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i14 = 0; c3_i14 < 4; c3_i14++) {
            chartInstance->c3_B2[c3_i14] = c3_dv2[c3_i14];
          }

          chartInstance->c3_dataWrittenToVector[8U] = true;
          for (c3_i19 = 0; c3_i19 < 4; c3_i19++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B2[c3_i19], 4U, 4U, 3U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 8U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[11U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 8U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[12U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 8U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[13U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 8U,
              chartInstance->c3_sfEvent, false);
          }

          c3_h_out = CV_EML_IF(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, (((-0.4784
            * *chartInstance->c3_x1 + 0.0019 * *chartInstance->c3_x2) - 0.0449 *
            *chartInstance->c3_x3) + 0.0168 * *chartInstance->c3_x4) + 1.0, 0.0,
            -1, 3U, (((-0.4784 * *chartInstance->c3_x1 + 0.0019 *
                       *chartInstance->c3_x2) - 0.0449 * *chartInstance->c3_x3)
                     + 0.0168 * *chartInstance->c3_x4) + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_h_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M3 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
            chartInstance->c3_stateChanged = true;
            chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M42;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M42 = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
              c3_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_x_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_x_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            for (c3_i21 = 0; c3_i21 < 16; c3_i21++) {
              chartInstance->c3_A1[c3_i21] = c3_dv0[c3_i21];
            }

            chartInstance->c3_dataWrittenToVector[1U] = true;
            for (c3_i23 = 0; c3_i23 < 16; c3_i23++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_A1[c3_i23], 0U, 4U, 4U,
                                    chartInstance->c3_sfEvent, false);
            }

            for (c3_i25 = 0; c3_i25 < 4; c3_i25++) {
              chartInstance->c3_B1[c3_i25] = c3_dv1[c3_i25];
            }

            chartInstance->c3_dataWrittenToVector[7U] = true;
            for (c3_i27 = 0; c3_i27 < 4; c3_i27++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_B1[c3_i27], 3U, 4U, 4U,
                                    chartInstance->c3_sfEvent, false);
            }

            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                         chartInstance->c3_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
              c3_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_out, 2U,
              c3_b_sf_marshallOut, c3_b_sf_marshallIn);
            if (!chartInstance->c3_dataWrittenToVector[10U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            if (!chartInstance->c3_dataWrittenToVector[11U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            if (!chartInstance->c3_dataWrittenToVector[12U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            if (!chartInstance->c3_dataWrittenToVector[13U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            c3_i_out = CV_EML_IF(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
              (((0.0083 * *chartInstance->c3_x1 - 1.0007 * *chartInstance->c3_x2)
                - 0.0166 * *chartInstance->c3_x3) + 0.0139 *
               *chartInstance->c3_x4) + 1.0, 0.0, -1, 5U, (((0.0083 *
              *chartInstance->c3_x1 - 1.0007 * *chartInstance->c3_x2) - 0.0166 *
              *chartInstance->c3_x3) + 0.0139 * *chartInstance->c3_x4) + 1.0 >=
              0.0));
            _SFD_SYMBOL_SCOPE_POP();
            if (c3_i_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_M3 = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
              chartInstance->c3_stateChanged = true;
              chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M1;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_M1 = 1U;
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
                c3_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_y_nargin, 0U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_y_nargout, 1U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              for (c3_i28 = 0; c3_i28 < 16; c3_i28++) {
                chartInstance->c3_A2[c3_i28] = c3_dv0[c3_i28];
              }

              chartInstance->c3_dataWrittenToVector[0U] = true;
              for (c3_i29 = 0; c3_i29 < 16; c3_i29++) {
                _SFD_DATA_RANGE_CHECK(chartInstance->c3_A2[c3_i29], 1U, 4U, 0U,
                                      chartInstance->c3_sfEvent, false);
              }

              for (c3_i30 = 0; c3_i30 < 4; c3_i30++) {
                chartInstance->c3_B2[c3_i30] = c3_dv2[c3_i30];
              }

              chartInstance->c3_dataWrittenToVector[8U] = true;
              for (c3_i31 = 0; c3_i31 < 4; c3_i31++) {
                _SFD_DATA_RANGE_CHECK(chartInstance->c3_B2[c3_i31], 4U, 4U, 0U,
                                      chartInstance->c3_sfEvent, false);
              }

              _SFD_SYMBOL_SCOPE_POP();
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U,
                           chartInstance->c3_sfEvent);
            }
          }
        }
        break;

       case c3_IN_M41:
        CV_CHART_EVAL(0, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 7U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 7U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 7U,
            chartInstance->c3_sfEvent, false);
        }

        c3_d_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, ((-0.4904 * *
          chartInstance->c3_x1 - 0.0049 * *chartInstance->c3_x2) + 0.003 *
          *chartInstance->c3_x3) + 1.0, 0.0, -1, 3U, ((-0.4904 *
          *chartInstance->c3_x1 - 0.0049 * *chartInstance->c3_x2) + 0.003 *
          *chartInstance->c3_x3) + 1.0 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M41 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M42;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M42 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_q_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_q_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i0 = 0; c3_i0 < 16; c3_i0++) {
            chartInstance->c3_A1[c3_i0] = c3_dv0[c3_i0];
          }

          chartInstance->c3_dataWrittenToVector[1U] = true;
          for (c3_i5 = 0; c3_i5 < 16; c3_i5++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A1[c3_i5], 0U, 4U, 4U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i10 = 0; c3_i10 < 4; c3_i10++) {
            chartInstance->c3_B1[c3_i10] = c3_dv1[c3_i10];
          }

          chartInstance->c3_dataWrittenToVector[7U] = true;
          for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B1[c3_i15], 3U, 4U, 4U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
        }
        break;

       case c3_IN_M42:
        CV_CHART_EVAL(0, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        c3_e_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (((0.0054 * *
          chartInstance->c3_x1 - 0.971 * *chartInstance->c3_x2) - 0.0176 *
          *chartInstance->c3_x3) + 0.0521 * *chartInstance->c3_x4) + 1.0, 0.0,
          -1, 5U, (((0.0054 * *chartInstance->c3_x1 - 0.971 *
                     *chartInstance->c3_x2) - 0.0176 * *chartInstance->c3_x3) +
                   0.0521 * *chartInstance->c3_x4) + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M42 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_M43;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M43 = 1U;
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
        }
        break;

       case c3_IN_M43:
        CV_CHART_EVAL(0, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c3_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
        break;

       case c3_IN_M44:
        CV_CHART_EVAL(0, 0, 7);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c3_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
        break;

       default:
        CV_CHART_EVAL(0, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        break;
      }
    }

    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c3_is_c3_con_ESTNavigation) {
   case c3_IN_M1:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M2:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M3:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M41:
    CV_CHART_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M42:
    CV_CHART_EVAL(0, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M43:
    CV_CHART_EVAL(0, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_out1 = -1.0;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out2 = -1.0;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out3 = -1.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out4 = -1.0;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M44:
    CV_CHART_EVAL(0, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_out1 = -1.0;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out2 = -1.0;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out3 = -1.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out4 = -1.0;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_con_ESTNavigationMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void zeroCrossings_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_d_nargout = 1.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  boolean_T c3_d_out;
  boolean_T c3_e_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  real_T c3_g_nargout = 1.0;
  real_T c3_h_nargout = 1.0;
  boolean_T c3_f_out;
  boolean_T c3_g_out;
  boolean_T c3_h_out;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_i_out;
  real_T *c3_zcVar;
  c3_zcVar = (real_T *)(ssGetNonsampledZCs_wrapper(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_lastMajorTime == _sfTime_) {
    *c3_zcVar = -1.0;
  } else {
    chartInstance->c3_stateChanged = (boolean_T)0;
    if (chartInstance->c3_is_active_c3_con_ESTNavigation == 0U) {
      chartInstance->c3_stateChanged = true;
    } else {
      switch (chartInstance->c3_is_c3_con_ESTNavigation) {
       case c3_IN_M1:
        CV_CHART_EVAL(0, 0, 1);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        c3_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (((0.0049 *
          *chartInstance->c3_x1 - 0.998 * *chartInstance->c3_x2) - 0.0134 *
          *chartInstance->c3_x3) + 0.0217 * *chartInstance->c3_x4) + 1.0, 0.0,
          -1, 3U, (((0.0049 * *chartInstance->c3_x1 - 0.998 *
                     *chartInstance->c3_x2) - 0.0134 * *chartInstance->c3_x3) +
                   0.0217 * *chartInstance->c3_x4) + 1.0 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_out) {
          chartInstance->c3_stateChanged = true;
        } else {
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_v_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 4U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[12U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 4U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[13U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 4U,
              chartInstance->c3_sfEvent, false);
          }

          c3_f_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, ((-0.5018 *
            *chartInstance->c3_x1 + 0.0067 * *chartInstance->c3_x3) - 0.003 *
            *chartInstance->c3_x4) + 1.0, 0.0, -1, 3U, ((-0.5018 *
            *chartInstance->c3_x1 + 0.0067 * *chartInstance->c3_x3) - 0.003 *
            *chartInstance->c3_x4) + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_f_out) {
            chartInstance->c3_stateChanged = true;
          }
        }
        break;

       case c3_IN_M2:
        CV_CHART_EVAL(0, 0, 2);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        c3_b_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (((0.0011 * *
          chartInstance->c3_x1 - 1.007 * *chartInstance->c3_x2) + 0.0159 *
          *chartInstance->c3_x3) + 0.0126 * *chartInstance->c3_x4) + 1.0, 0.0,
          -1, 5U, (((0.0011 * *chartInstance->c3_x1 - 1.007 *
                     *chartInstance->c3_x2) + 0.0159 * *chartInstance->c3_x3) +
                   0.0126 * *chartInstance->c3_x4) + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          chartInstance->c3_stateChanged = true;
        } else {
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 5U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[11U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 5U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[12U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 5U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[13U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 5U,
              chartInstance->c3_sfEvent, false);
          }

          c3_g_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0, (((-1.0065
            * *chartInstance->c3_x1 + 0.0031 * *chartInstance->c3_x2) + 0.0201 *
            *chartInstance->c3_x3) - 0.0028 * *chartInstance->c3_x4) + 1.0, 0.0,
            -1, 3U, (((-1.0065 * *chartInstance->c3_x1 + 0.0031 *
                       *chartInstance->c3_x2) + 0.0201 * *chartInstance->c3_x3)
                     - 0.0028 * *chartInstance->c3_x4) + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_g_out) {
            chartInstance->c3_stateChanged = true;
          }
        }
        break;

       case c3_IN_M3:
        CV_CHART_EVAL(0, 0, 3);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 6U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 6U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 6U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 6U,
            chartInstance->c3_sfEvent, false);
        }

        c3_c_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, (((-0.0045 *
          *chartInstance->c3_x1 - 0.4971 * *chartInstance->c3_x2) + 0.0011 *
          *chartInstance->c3_x3) + 0.0064 * *chartInstance->c3_x4) + 1.0, 0.0,
          -1, 3U, (((-0.0045 * *chartInstance->c3_x1 - 0.4971 *
                     *chartInstance->c3_x2) + 0.0011 * *chartInstance->c3_x3) +
                   0.0064 * *chartInstance->c3_x4) + 1.0 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_c_out) {
          chartInstance->c3_stateChanged = true;
        } else {
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 8U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[11U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 8U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[12U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 8U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[13U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 8U,
              chartInstance->c3_sfEvent, false);
          }

          c3_h_out = CV_EML_IF(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, (((-0.4784
            * *chartInstance->c3_x1 + 0.0019 * *chartInstance->c3_x2) - 0.0449 *
            *chartInstance->c3_x3) + 0.0168 * *chartInstance->c3_x4) + 1.0, 0.0,
            -1, 3U, (((-0.4784 * *chartInstance->c3_x1 + 0.0019 *
                       *chartInstance->c3_x2) - 0.0449 * *chartInstance->c3_x3)
                     + 0.0168 * *chartInstance->c3_x4) + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_h_out) {
            chartInstance->c3_stateChanged = true;
          } else {
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
              c3_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_out, 2U,
              c3_b_sf_marshallOut, c3_b_sf_marshallIn);
            if (!chartInstance->c3_dataWrittenToVector[10U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            if (!chartInstance->c3_dataWrittenToVector[11U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            if (!chartInstance->c3_dataWrittenToVector[12U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            if (!chartInstance->c3_dataWrittenToVector[13U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            c3_i_out = CV_EML_IF(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
              (((0.0083 * *chartInstance->c3_x1 - 1.0007 * *chartInstance->c3_x2)
                - 0.0166 * *chartInstance->c3_x3) + 0.0139 *
               *chartInstance->c3_x4) + 1.0, 0.0, -1, 5U, (((0.0083 *
              *chartInstance->c3_x1 - 1.0007 * *chartInstance->c3_x2) - 0.0166 *
              *chartInstance->c3_x3) + 0.0139 * *chartInstance->c3_x4) + 1.0 >=
              0.0));
            _SFD_SYMBOL_SCOPE_POP();
            if (c3_i_out) {
              chartInstance->c3_stateChanged = true;
            }
          }
        }
        break;

       case c3_IN_M41:
        CV_CHART_EVAL(0, 0, 4);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 7U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 7U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 7U,
            chartInstance->c3_sfEvent, false);
        }

        c3_d_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, ((-0.4904 * *
          chartInstance->c3_x1 - 0.0049 * *chartInstance->c3_x2) + 0.003 *
          *chartInstance->c3_x3) + 1.0, 0.0, -1, 3U, ((-0.4904 *
          *chartInstance->c3_x1 - 0.0049 * *chartInstance->c3_x2) + 0.003 *
          *chartInstance->c3_x3) + 1.0 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          chartInstance->c3_stateChanged = true;
        }
        break;

       case c3_IN_M42:
        CV_CHART_EVAL(0, 0, 5);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        c3_e_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (((0.0054 * *
          chartInstance->c3_x1 - 0.971 * *chartInstance->c3_x2) - 0.0176 *
          *chartInstance->c3_x3) + 0.0521 * *chartInstance->c3_x4) + 1.0, 0.0,
          -1, 5U, (((0.0054 * *chartInstance->c3_x1 - 0.971 *
                     *chartInstance->c3_x2) - 0.0176 * *chartInstance->c3_x3) +
                   0.0521 * *chartInstance->c3_x4) + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_e_out) {
          chartInstance->c3_stateChanged = true;
        }
        break;

       case c3_IN_M43:
        CV_CHART_EVAL(0, 0, 6);
        break;

       case c3_IN_M44:
        CV_CHART_EVAL(0, 0, 7);
        break;

       default:
        CV_CHART_EVAL(0, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (chartInstance->c3_stateChanged) {
      *c3_zcVar = 1.0;
    } else {
      *c3_zcVar = -1.0;
    }
  }
}

static void derivatives_c3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargout = 0.0;
  real_T *c3_x1_dot;
  real_T *c3_x2_dot;
  real_T *c3_x3_dot;
  real_T *c3_x4_dot;
  c3_x4_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 3);
  c3_x3_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 2);
  c3_x2_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 1);
  c3_x1_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 0);
  *c3_x1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 6U, 1U, 0U, chartInstance->c3_sfEvent, false);
  *c3_x2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 7U, 1U, 0U, chartInstance->c3_sfEvent, false);
  *c3_x3_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 8U, 1U, 0U, chartInstance->c3_sfEvent, false);
  *c3_x4_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_x4_dot, 9U, 1U, 0U, chartInstance->c3_sfEvent, false);
  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c3_is_c3_con_ESTNavigation) {
   case c3_IN_M1:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A2[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_A2[12] * *chartInstance->c3_x4) +
      chartInstance->c3_B2[0];
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 6U, 4U, 0U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A2[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[9] * *chartInstance->c3_x3) +
                  chartInstance->c3_A2[13] * *chartInstance->c3_x4) +
      chartInstance->c3_B2[1];
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 7U, 4U, 0U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A2[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[6] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[10] * *chartInstance->c3_x3) +
                  chartInstance->c3_A2[14] * *chartInstance->c3_x4) +
      chartInstance->c3_B2[2];
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 8U, 4U, 0U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x4_dot = (((chartInstance->c3_A2[3] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[7] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[11] * *chartInstance->c3_x3) +
                  chartInstance->c3_A2[15] * *chartInstance->c3_x4) +
      chartInstance->c3_B2[3];
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x4_dot, 9U, 4U, 0U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M2:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A1[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_A1[12] * *chartInstance->c3_x4) +
      chartInstance->c3_B1[0];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 6U, 4U, 1U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A1[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[9] * *chartInstance->c3_x3) +
                  chartInstance->c3_A1[13] * *chartInstance->c3_x4) +
      chartInstance->c3_B1[1];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 7U, 4U, 1U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A1[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[6] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[10] * *chartInstance->c3_x3) +
                  chartInstance->c3_A1[14] * *chartInstance->c3_x4) +
      chartInstance->c3_B1[2];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 8U, 4U, 1U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x4_dot = (((chartInstance->c3_A1[3] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[7] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[11] * *chartInstance->c3_x3) +
                  chartInstance->c3_A1[15] * *chartInstance->c3_x4) +
      chartInstance->c3_B1[3];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x4_dot, 9U, 4U, 1U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M3:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A3[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A3[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A3[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_A3[12] * *chartInstance->c3_x4) +
      chartInstance->c3_B3[0];
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 6U, 4U, 2U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A3[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A3[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A3[9] * *chartInstance->c3_x3) +
                  chartInstance->c3_A3[13] * *chartInstance->c3_x4) +
      chartInstance->c3_B3[1];
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 7U, 4U, 2U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A3[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A3[6] * *chartInstance->c3_x2) +
                   chartInstance->c3_A3[10] * *chartInstance->c3_x3) +
                  chartInstance->c3_A3[14] * *chartInstance->c3_x4) +
      chartInstance->c3_B3[2];
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 8U, 4U, 2U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x4_dot = (((chartInstance->c3_A3[3] * *chartInstance->c3_x1 +
                    chartInstance->c3_A3[7] * *chartInstance->c3_x2) +
                   chartInstance->c3_A3[11] * *chartInstance->c3_x3) +
                  chartInstance->c3_A3[15] * *chartInstance->c3_x4) +
      chartInstance->c3_B3[3];
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x4_dot, 9U, 4U, 2U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M41:
    CV_CHART_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A2[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_A2[12] * *chartInstance->c3_x4) +
      chartInstance->c3_B2[0];
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 6U, 4U, 3U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A2[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[9] * *chartInstance->c3_x3) +
                  chartInstance->c3_A2[13] * *chartInstance->c3_x4) +
      chartInstance->c3_B2[1];
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 7U, 4U, 3U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A2[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[6] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[10] * *chartInstance->c3_x3) +
                  chartInstance->c3_A2[14] * *chartInstance->c3_x4) +
      chartInstance->c3_B2[2];
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 8U, 4U, 3U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x4_dot = (((chartInstance->c3_A2[3] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[7] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[11] * *chartInstance->c3_x3) +
                  chartInstance->c3_A2[15] * *chartInstance->c3_x4) +
      chartInstance->c3_B2[3];
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x4_dot, 9U, 4U, 3U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M42:
    CV_CHART_EVAL(0, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A1[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_A1[12] * *chartInstance->c3_x4) +
      chartInstance->c3_B1[0];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 6U, 4U, 4U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A1[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[9] * *chartInstance->c3_x3) +
                  chartInstance->c3_A1[13] * *chartInstance->c3_x4) +
      chartInstance->c3_B1[1];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 7U, 4U, 4U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A1[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[6] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[10] * *chartInstance->c3_x3) +
                  chartInstance->c3_A1[14] * *chartInstance->c3_x4) +
      chartInstance->c3_B1[2];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 8U, 4U, 4U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x4_dot = (((chartInstance->c3_A1[3] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[7] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[11] * *chartInstance->c3_x3) +
                  chartInstance->c3_A1[15] * *chartInstance->c3_x4) +
      chartInstance->c3_B1[3];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x4_dot, 9U, 4U, 4U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M43:
    CV_CHART_EVAL(0, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M44:
    CV_CHART_EVAL(0, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    break;
  }
}

static void outputs_c3_con_ESTNavigation(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargout = 0.0;
  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c3_is_c3_con_ESTNavigation) {
   case c3_IN_M1:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 0U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M2:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M3:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M41:
    CV_CHART_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M42:
    CV_CHART_EVAL(0, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out4 = *chartInstance->c3_x4;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M43:
    CV_CHART_EVAL(0, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_out1 = -1.0;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out2 = -1.0;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out3 = -1.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out4 = -1.0;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M44:
    CV_CHART_EVAL(0, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_out1 = -1.0;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 10U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out2 = -1.0;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 11U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out3 = -1.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 12U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_out4 = -1.0;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out4, 13U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_c3_con_ESTNavigation = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    break;
  }
}

static void initSimStructsc3_con_ESTNavigation
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_ini_fcn_to_be_inlined_582
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_term_fcn_to_be_inlined_582
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

static const mxArray *c3_emlrt_marshallOut(SFc3_con_ESTNavigationInstanceStruct *
  chartInstance, const real_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_emlrt_marshallOut(chartInstance, *(real_T
    *)c3_inData), false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  *(real_T *)c3_outData = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const boolean_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_b_emlrt_marshallOut(chartInstance,
    *(boolean_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  return c3_y;
}

static boolean_T c3_d_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
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
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  *(boolean_T *)c3_outData = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_con_ESTNavigation_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const int32_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_c_emlrt_marshallOut(chartInstance,
    *(int32_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_sfEvent, const char_T *c3_identifier)
{
  int32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  return c3_y;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i32;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i32, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i32;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c3_outData = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const uint8_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_d_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_M44, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_M44),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_M44);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
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
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c3_outData = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const real_T c3_u[16])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 4, 4), false);
  return c3_y;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_e_emlrt_marshallOut(chartInstance,
    *(real_T (*)[16])c3_inData), false);
  return c3_mxArrayOutData;
}

static void c3_i_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_A2, const char_T *c3_identifier, real_T
  c3_y[16])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_A2), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_A2);
}

static void c3_j_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[16])
{
  real_T c3_dv4[16];
  int32_T c3_i33;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv4, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c3_i33 = 0; c3_i33 < 16; c3_i33++) {
    c3_y[c3_i33] = c3_dv4[c3_i33];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  real_T c3_dv5[16];
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mxArrayInData), c3_varName,
                        c3_dv5);
  c3_i34 = 0;
  for (c3_i35 = 0; c3_i35 < 4; c3_i35++) {
    for (c3_i36 = 0; c3_i36 < 4; c3_i36++) {
      (*(real_T (*)[16])c3_outData)[c3_i36 + c3_i34] = c3_dv5[c3_i36 + c3_i34];
    }

    c3_i34 += 4;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const real_T c3_u[4])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 4, 1), false);
  return c3_y;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_f_emlrt_marshallOut(chartInstance,
    *(real_T (*)[4])c3_inData), false);
  return c3_mxArrayOutData;
}

static void c3_k_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_B1, const char_T *c3_identifier, real_T
  c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_B1), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_B1);
}

static void c3_l_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4])
{
  real_T c3_dv6[4];
  int32_T c3_i37;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv6, 1, 0, 0U, 1, 0U, 2, 4, 1);
  for (c3_i37 = 0; c3_i37 < 4; c3_i37++) {
    c3_y[c3_i37] = c3_dv6[c3_i37];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  real_T c3_dv7[4];
  int32_T c3_i38;
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)chartInstanceVoid;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mxArrayInData), c3_varName,
                        c3_dv7);
  for (c3_i38 = 0; c3_i38 < 4; c3_i38++) {
    (*(real_T (*)[4])c3_outData)[c3_i38] = c3_dv7[c3_i38];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance)
{
  const mxArray *c3_y;
  int32_T c3_i39;
  real_T c3_dv8[16];
  int32_T c3_i40;
  real_T c3_dv9[16];
  int32_T c3_i41;
  real_T c3_dv10[16];
  int32_T c3_i42;
  real_T c3_dv11[4];
  int32_T c3_i43;
  real_T c3_dv12[4];
  int32_T c3_i44;
  real_T c3_dv13[4];
  int32_T c3_i45;
  boolean_T c3_bv0[14];
  c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(17, 1), false);
  sf_mex_setcell(c3_y, 0, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_out1));
  sf_mex_setcell(c3_y, 1, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_out2));
  sf_mex_setcell(c3_y, 2, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_out3));
  sf_mex_setcell(c3_y, 3, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_out4));
  for (c3_i39 = 0; c3_i39 < 16; c3_i39++) {
    c3_dv8[c3_i39] = chartInstance->c3_A1[c3_i39];
  }

  sf_mex_setcell(c3_y, 4, c3_e_emlrt_marshallOut(chartInstance, c3_dv8));
  for (c3_i40 = 0; c3_i40 < 16; c3_i40++) {
    c3_dv9[c3_i40] = chartInstance->c3_A2[c3_i40];
  }

  sf_mex_setcell(c3_y, 5, c3_e_emlrt_marshallOut(chartInstance, c3_dv9));
  for (c3_i41 = 0; c3_i41 < 16; c3_i41++) {
    c3_dv10[c3_i41] = chartInstance->c3_A3[c3_i41];
  }

  sf_mex_setcell(c3_y, 6, c3_e_emlrt_marshallOut(chartInstance, c3_dv10));
  for (c3_i42 = 0; c3_i42 < 4; c3_i42++) {
    c3_dv11[c3_i42] = chartInstance->c3_B1[c3_i42];
  }

  sf_mex_setcell(c3_y, 7, c3_f_emlrt_marshallOut(chartInstance, c3_dv11));
  for (c3_i43 = 0; c3_i43 < 4; c3_i43++) {
    c3_dv12[c3_i43] = chartInstance->c3_B2[c3_i43];
  }

  sf_mex_setcell(c3_y, 8, c3_f_emlrt_marshallOut(chartInstance, c3_dv12));
  for (c3_i44 = 0; c3_i44 < 4; c3_i44++) {
    c3_dv13[c3_i44] = chartInstance->c3_B3[c3_i44];
  }

  sf_mex_setcell(c3_y, 9, c3_f_emlrt_marshallOut(chartInstance, c3_dv13));
  sf_mex_setcell(c3_y, 10, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x1));
  sf_mex_setcell(c3_y, 11, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x2));
  sf_mex_setcell(c3_y, 12, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x3));
  sf_mex_setcell(c3_y, 13, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x4));
  sf_mex_setcell(c3_y, 14, c3_d_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_active_c3_con_ESTNavigation));
  sf_mex_setcell(c3_y, 15, c3_d_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_c3_con_ESTNavigation));
  for (c3_i45 = 0; c3_i45 < 14; c3_i45++) {
    c3_bv0[c3_i45] = chartInstance->c3_dataWrittenToVector[c3_i45];
  }

  sf_mex_setcell(c3_y, 16, c3_h_emlrt_marshallOut(chartInstance, c3_bv0));
  return c3_y;
}

static const mxArray *c3_h_emlrt_marshallOut
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, const boolean_T c3_u[14])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 11, 0U, 1U, 0U, 1, 14), false);
  return c3_y;
}

static void c3_m_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u)
{
  real_T c3_dv14[16];
  int32_T c3_i46;
  real_T c3_dv15[16];
  int32_T c3_i47;
  real_T c3_dv16[16];
  int32_T c3_i48;
  real_T c3_dv17[4];
  int32_T c3_i49;
  real_T c3_dv18[4];
  int32_T c3_i50;
  real_T c3_dv19[4];
  int32_T c3_i51;
  boolean_T c3_bv1[14];
  int32_T c3_i52;
  *chartInstance->c3_out1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("out1", c3_u, 0)), "out1");
  *chartInstance->c3_out2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("out2", c3_u, 1)), "out2");
  *chartInstance->c3_out3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("out3", c3_u, 2)), "out3");
  *chartInstance->c3_out4 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("out4", c3_u, 3)), "out4");
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A1", c3_u, 4)),
                        "A1", c3_dv14);
  for (c3_i46 = 0; c3_i46 < 16; c3_i46++) {
    chartInstance->c3_A1[c3_i46] = c3_dv14[c3_i46];
  }

  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A2", c3_u, 5)),
                        "A2", c3_dv15);
  for (c3_i47 = 0; c3_i47 < 16; c3_i47++) {
    chartInstance->c3_A2[c3_i47] = c3_dv15[c3_i47];
  }

  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A3", c3_u, 6)),
                        "A3", c3_dv16);
  for (c3_i48 = 0; c3_i48 < 16; c3_i48++) {
    chartInstance->c3_A3[c3_i48] = c3_dv16[c3_i48];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("B1", c3_u, 7)),
                        "B1", c3_dv17);
  for (c3_i49 = 0; c3_i49 < 4; c3_i49++) {
    chartInstance->c3_B1[c3_i49] = c3_dv17[c3_i49];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("B2", c3_u, 8)),
                        "B2", c3_dv18);
  for (c3_i50 = 0; c3_i50 < 4; c3_i50++) {
    chartInstance->c3_B2[c3_i50] = c3_dv18[c3_i50];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("B3", c3_u, 9)),
                        "B3", c3_dv19);
  for (c3_i51 = 0; c3_i51 < 4; c3_i51++) {
    chartInstance->c3_B3[c3_i51] = c3_dv19[c3_i51];
  }

  *chartInstance->c3_x1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x1", c3_u, 10)), "x1");
  *chartInstance->c3_x2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x2", c3_u, 11)), "x2");
  *chartInstance->c3_x3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x3", c3_u, 12)), "x3");
  *chartInstance->c3_x4 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x4", c3_u, 13)), "x4");
  chartInstance->c3_is_active_c3_con_ESTNavigation = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c3_con_ESTNavigation",
       c3_u, 14)), "is_active_c3_con_ESTNavigation");
  chartInstance->c3_is_c3_con_ESTNavigation = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_c3_con_ESTNavigation", c3_u,
       15)), "is_c3_con_ESTNavigation");
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 16)), "dataWrittenToVector", c3_bv1);
  for (c3_i52 = 0; c3_i52 < 14; c3_i52++) {
    chartInstance->c3_dataWrittenToVector[c3_i52] = c3_bv1[c3_i52];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 17)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c3_u);
}

static void c3_n_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[14])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_o_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[14])
{
  boolean_T c3_bv2[14];
  int32_T c3_i53;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv2, 1, 11, 0U, 1, 0U, 1, 14);
  for (c3_i53 = 0; c3_i53 < 14; c3_i53++) {
    c3_y[c3_i53] = c3_bv2[c3_i53];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_p_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_q_emlrt_marshallIn(SFc3_con_ESTNavigationInstanceStruct
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

static const mxArray *sf_get_hover_data_for_msg
  (SFc3_con_ESTNavigationInstanceStruct *chartInstance, int32_T c3_ssid)
{
  const mxArray *c3_msgInfo;
  (void)chartInstance;
  (void)c3_ssid;
  c3_msgInfo = NULL;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_con_ESTNavigationInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_out1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_out2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_out3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_out4 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_x1 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    0);
  chartInstance->c3_x2 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    1);
  chartInstance->c3_x3 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    2);
  chartInstance->c3_x4 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    3);
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

void sf_c3_con_ESTNavigation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2138392128U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(836986030U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2613211138U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2062458984U);
}

mxArray* sf_c3_con_ESTNavigation_get_post_codegen_info(void);
mxArray *sf_c3_con_ESTNavigation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("XTF1OZXg4mYSW28UpFuR9");
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_con_ESTNavigation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_con_ESTNavigation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_con_ESTNavigation_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("plant_model_chart");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_con_ESTNavigation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_con_ESTNavigation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_con_ESTNavigation(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[35],T\"out1\",},{M[1],M[36],T\"out2\",},{M[1],M[37],T\"out3\",},{M[1],M[38],T\"out4\",},{M[3],M[29],T\"A1\",},{M[3],M[25],T\"A2\",},{M[3],M[30],T\"A3\",},{M[3],M[39],T\"B1\",},{M[3],M[40],T\"B2\",},{M[3],M[41],T\"B3\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[5],M[42],T\"x1\",},{M[5],M[43],T\"x2\",},{M[5],M[44],T\"x3\",},{M[5],M[45],T\"x4\",},{M[8],M[0],T\"is_active_c3_con_ESTNavigation\",},{M[9],M[0],T\"is_c3_con_ESTNavigation\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 17, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_con_ESTNavigation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_con_ESTNavigationInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_con_ESTNavigationInstanceStruct *chartInstance =
      (SFc3_con_ESTNavigationInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _con_ESTNavigationMachineNumber_,
           3,
           7,
           10,
           0,
           14,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_con_ESTNavigationMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_con_ESTNavigationMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _con_ESTNavigationMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"A1");
          _SFD_SET_DATA_PROPS(1,0,0,0,"A2");
          _SFD_SET_DATA_PROPS(2,0,0,0,"A3");
          _SFD_SET_DATA_PROPS(3,0,0,0,"B1");
          _SFD_SET_DATA_PROPS(4,0,0,0,"B2");
          _SFD_SET_DATA_PROPS(5,0,0,0,"B3");
          _SFD_SET_DATA_PROPS(6,0,0,0,"x1");
          _SFD_SET_DATA_PROPS(7,0,0,0,"x2");
          _SFD_SET_DATA_PROPS(8,0,0,0,"x3");
          _SFD_SET_DATA_PROPS(9,0,0,0,"x4");
          _SFD_SET_DATA_PROPS(10,2,0,1,"out1");
          _SFD_SET_DATA_PROPS(11,2,0,1,"out2");
          _SFD_SET_DATA_PROPS(12,2,0,1,"out3");
          _SFD_SET_DATA_PROPS(13,2,0,1,"out4");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_CH_SUBSTATE_COUNT(7);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_CH_SUBSTATE_INDEX(5,5);
          _SFD_CH_SUBSTATE_INDEX(6,6);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(7,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

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
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,47,1,47);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,1,47,-1,5);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,48,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,2,48,-1,3);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,49,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,49,-1,3);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,49,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,49,-1,3);
        _SFD_CV_INIT_EML(7,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,38,1,38);
        _SFD_CV_INIT_EML_RELATIONAL(7,0,0,1,38,-1,3);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,47,1,47);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,47,-1,5);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,48,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,2,48,-1,5);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,49,1,48);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,49,-1,3);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,38,1,38);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,38,-1,3);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 1U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 1U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 1U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _con_ESTNavigationMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_con_ESTNavigationInstanceStruct *chartInstance =
      (SFc3_con_ESTNavigationInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c3_A2);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c3_A1);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c3_A3);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c3_out1);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c3_out2);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c3_out3);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c3_out4);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)&chartInstance->c3_B1);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)&chartInstance->c3_B2);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)&chartInstance->c3_B3);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c3_x1);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c3_x2);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c3_x3);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c3_x4);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sbPD8BifQPofpoX5qKB7bJC";
}

static void sf_opaque_initialize_c3_con_ESTNavigation(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar);
  initialize_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_con_ESTNavigation(void *chartInstanceVar)
{
  enable_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_con_ESTNavigation(void *chartInstanceVar)
{
  disable_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c3_con_ESTNavigation(void *chartInstanceVar)
{
  zeroCrossings_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_derivatives_c3_con_ESTNavigation(void *chartInstanceVar)
{
  derivatives_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_outputs_c3_con_ESTNavigation(void *chartInstanceVar)
{
  outputs_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_con_ESTNavigation(void *chartInstanceVar)
{
  sf_gateway_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_con_ESTNavigation(SimStruct* S)
{
  return get_sim_state_c3_con_ESTNavigation
    ((SFc3_con_ESTNavigationInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_con_ESTNavigation(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_con_ESTNavigation(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_con_ESTNavigationInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_con_ESTNavigation_optimization_info();
    }

    finalize_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
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
  initSimStructsc3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_con_ESTNavigation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_con_ESTNavigation((SFc3_con_ESTNavigationInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_con_ESTNavigation(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_con_ESTNavigation_optimization_info
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
        infoStruct,3,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1063501187U));
  ssSetChecksum1(S,(3618916309U));
  ssSetChecksum2(S,(1268916446U));
  ssSetChecksum3(S,(2599817916U));
  ssSetNumContStates(S,4);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_con_ESTNavigation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_con_ESTNavigation(SimStruct *S)
{
  SFc3_con_ESTNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTNavigationInstanceStruct *)utMalloc(sizeof
    (SFc3_con_ESTNavigationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_con_ESTNavigationInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_con_ESTNavigation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_con_ESTNavigation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_con_ESTNavigation;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_con_ESTNavigation;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_con_ESTNavigation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_con_ESTNavigation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_con_ESTNavigation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_con_ESTNavigation;
  chartInstance->chartInfo.zeroCrossings =
    sf_opaque_zeroCrossings_c3_con_ESTNavigation;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c3_con_ESTNavigation;
  chartInstance->chartInfo.derivatives =
    sf_opaque_derivatives_c3_con_ESTNavigation;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_con_ESTNavigation;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_con_ESTNavigation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_con_ESTNavigation;
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
  mdl_start_c3_con_ESTNavigation(chartInstance);
}

void c3_con_ESTNavigation_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_con_ESTNavigation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_con_ESTNavigation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_con_ESTNavigation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_con_ESTNavigation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
