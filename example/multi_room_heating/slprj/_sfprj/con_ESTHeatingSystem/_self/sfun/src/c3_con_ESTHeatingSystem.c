/* Include files */

#include "con_ESTHeatingSystem_sfun.h"
#include "c3_con_ESTHeatingSystem.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "con_ESTHeatingSystem_sfun_debug_macros.h"
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
#define c3_IN_M2                       ((uint8_T)1U)
#define c3_IN_M236                     ((uint8_T)2U)
#define c3_IN_M262                     ((uint8_T)3U)
#define c3_IN_M263                     ((uint8_T)4U)
#define c3_IN_M4                       ((uint8_T)5U)
#define c3_IN_M5                       ((uint8_T)6U)

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
static void initialize_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void initialize_params_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void enable_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void disable_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void set_sim_state_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void finalize_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void sf_gateway_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void mdl_start_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void zeroCrossings_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void derivatives_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void outputs_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void initSimStructsc3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void c3_eml_ini_fcn_to_be_inlined_491
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void c3_eml_term_fcn_to_be_inlined_491
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const real_T c3_u);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const boolean_T c3_u);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier);
static boolean_T c3_d_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const int32_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_sfEvent, const char_T *c3_identifier);
static int32_T c3_f_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const uint8_T c3_u);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_M2, const char_T *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const real_T c3_u[9]);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_i_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_A2, const char_T *c3_identifier, real_T
  c3_y[9]);
static void c3_j_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[9]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const real_T c3_u[6]);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_k_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_B2, const char_T *c3_identifier, real_T
  c3_y[6]);
static void c3_l_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[6]);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static const mxArray *c3_h_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const boolean_T c3_u
   [12]);
static void c3_m_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u);
static void c3_n_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[12]);
static void c3_o_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[12]);
static const mxArray *c3_p_emlrt_marshallIn
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_q_emlrt_marshallIn
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_M2 = 0U;
  chartInstance->c3_tp_M236 = 0U;
  chartInstance->c3_tp_M262 = 0U;
  chartInstance->c3_tp_M263 = 0U;
  chartInstance->c3_tp_M4 = 0U;
  chartInstance->c3_tp_M5 = 0U;
  chartInstance->c3_is_active_c3_con_ESTHeatingSystem = 0U;
  chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c3_out1 = 15.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c3_out2 = 15.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c3_out3 = 15.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }
}

static void initialize_params_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_con_ESTHeatingSystem == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M5) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M236) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M262) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M263) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  const mxArray *c3_st = NULL;
  c3_st = NULL;
  sf_mex_assign(&c3_st, c3_g_emlrt_marshallOut(chartInstance), false);
  return c3_st;
}

static void set_sim_state_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const mxArray *c3_st)
{
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_st));
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_con_ESTHeatingSystem(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_tp_M2 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M2);
    chartInstance->c3_tp_M236 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M236);
    chartInstance->c3_tp_M262 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M262);
    chartInstance->c3_tp_M263 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M263);
    chartInstance->c3_tp_M4 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M4);
    chartInstance->c3_tp_M5 = (uint8_T)
      (chartInstance->c3_is_c3_con_ESTHeatingSystem == c3_IN_M5);
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_g_nargin = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_l_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
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
  boolean_T c3_f_out;
  real_T c3_m_nargout = 0.0;
  real_T c3_n_nargin = 0.0;
  real_T c3_n_nargout = 1.0;
  boolean_T c3_g_out;
  real_T c3_o_nargin = 0.0;
  real_T c3_p_nargin = 0.0;
  real_T c3_q_nargin = 0.0;
  real_T c3_r_nargin = 0.0;
  real_T c3_s_nargin = 0.0;
  real_T c3_o_nargout = 0.0;
  real_T c3_p_nargout = 0.0;
  real_T c3_q_nargout = 0.0;
  real_T c3_r_nargout = 0.0;
  real_T c3_s_nargout = 1.0;
  int32_T c3_i0;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  real_T c3_t_nargin = 0.0;
  boolean_T c3_h_out;
  real_T c3_u_nargin = 0.0;
  real_T c3_t_nargout = 0.0;
  real_T c3_u_nargout = 1.0;
  int32_T c3_i4;
  static real_T c3_dv0[9] = { -0.0994, 0.0209, 0.041, 0.0302, -0.104, 0.0504,
    0.0392, 0.053, -0.1413 };

  static real_T c3_dv1[9] = { -0.1001, 0.0299, 0.0398, 0.0298, -0.1001, 0.0497,
    0.04, 0.05, -0.14 };

  static real_T c3_dv2[9] = { -0.0532, 0.0299, 0.0397, -0.0776, -0.0999, 0.0502,
    0.0941, 0.05, -0.1399 };

  boolean_T c3_i_out;
  static real_T c3_dv3[9] = { -0.1003, 0.0298, 0.0395, 0.0298, -0.1001, 0.0497,
    0.0397, 0.0498, -0.1406 };

  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  real_T c3_v_nargin = 0.0;
  real_T c3_v_nargout = 0.0;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  real_T c3_w_nargin = 0.0;
  int32_T c3_i14;
  real_T c3_w_nargout = 0.0;
  int32_T c3_i15;
  int32_T c3_i16;
  static real_T c3_dv4[6] = { 0.0301, 0.023, 0.0502, -0.0025, 0.8405, -0.0042 };

  static real_T c3_dv5[6] = { 0.0301, 0.02, 0.0501, 0.0036, 0.0024, 1.106 };

  static real_T c3_dv6[6] = { 0.023, 0.02, 0.0501, 0.9161, 0.0, 0.0 };

  static real_T c3_dv7[6] = { 0.0303, 0.0202, 0.0505, 0.0107, 0.0071, 0.0179 };

  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  real_T c3_x_nargin = 0.0;
  real_T c3_x_nargout = 0.0;
  int32_T c3_i25;
  int32_T c3_i26;
  real_T c3_y_nargin = 0.0;
  real_T c3_ab_nargin = 0.0;
  int32_T c3_i27;
  real_T c3_y_nargout = 0.0;
  real_T c3_ab_nargout = 0.0;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  boolean_T guard1 = false;
  c3_set_sim_state_side_effects_c3_con_ESTHeatingSystem(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0U) {
    chartInstance->c3_lastMajorTime = _sfTime_;
    chartInstance->c3_stateChanged = (boolean_T)0;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ud, 11U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
    chartInstance->c3_sfEvent = CALL_EVENT;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_is_active_c3_con_ESTHeatingSystem == 0U) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_active_c3_con_ESTHeatingSystem = 1U;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_n_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_x1 = 10.0;
      chartInstance->c3_dataWrittenToVector[8U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1, 8U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
      *chartInstance->c3_x2 = 10.0;
      chartInstance->c3_dataWrittenToVector[9U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2, 9U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
      *chartInstance->c3_x3 = 10.0;
      chartInstance->c3_dataWrittenToVector[10U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x3, 10U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_M2 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_t_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_t_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      for (c3_i4 = 0; c3_i4 < 9; c3_i4++) {
        chartInstance->c3_A2[c3_i4] = c3_dv0[c3_i4];
      }

      chartInstance->c3_dataWrittenToVector[0U] = true;
      for (c3_i9 = 0; c3_i9 < 9; c3_i9++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_A2[c3_i9], 1U, 4U, 1U,
                              chartInstance->c3_sfEvent, false);
      }

      for (c3_i16 = 0; c3_i16 < 6; c3_i16++) {
        chartInstance->c3_B2[c3_i16] = c3_dv4[c3_i16];
      }

      chartInstance->c3_dataWrittenToVector[1U] = true;
      for (c3_i23 = 0; c3_i23 < 6; c3_i23++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_B2[c3_i23], 5U, 4U, 1U,
                              chartInstance->c3_sfEvent, false);
      }

      _SFD_SYMBOL_SCOPE_POP();
    } else {
      switch (chartInstance->c3_is_c3_con_ESTHeatingSystem) {
       case c3_IN_M2:
        CV_CHART_EVAL(0, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[9U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        guard1 = false;
        if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (-0.4794 *
               *chartInstance->c3_x2 + 0.477 * *chartInstance->c3_x3) + 1.0, 0.0,
              -1, 3U, (-0.4794 * *chartInstance->c3_x2 + 0.477 *
                       *chartInstance->c3_x3) + 1.0 <= 0.0))) {
          if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1, (0.0014 *
                 *chartInstance->c3_x1 - 0.0659 * *chartInstance->c3_x3) + 1.0,
                0.0, -1, 5U, (0.0014 * *chartInstance->c3_x1 - 0.0659 *
                              *chartInstance->c3_x3) + 1.0 >= 0.0))) {
            CV_EML_MCDC(1, 0, 0, true);
            CV_EML_IF(1, 0, 0, true);
            c3_out = true;
          } else {
            guard1 = true;
          }
        } else {
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 1U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[8U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 1U,
              chartInstance->c3_sfEvent, false);
          }

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
          chartInstance->c3_tp_M2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M4;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M4 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i10 = 0; c3_i10 < 9; c3_i10++) {
            chartInstance->c3_A1[c3_i10] = c3_dv1[c3_i10];
          }

          chartInstance->c3_dataWrittenToVector[2U] = true;
          for (c3_i17 = 0; c3_i17 < 9; c3_i17++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A1[c3_i17], 0U, 4U, 5U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i24 = 0; c3_i24 < 6; c3_i24++) {
            chartInstance->c3_B1[c3_i24] = c3_dv5[c3_i24];
          }

          chartInstance->c3_dataWrittenToVector[4U] = true;
          for (c3_i27 = 0; c3_i27 < 6; c3_i27++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B1[c3_i27], 4U, 4U, 5U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_s_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_s_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[9U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 4U,
              chartInstance->c3_sfEvent, false);
          }

          c3_h_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, -0.048 *
            *chartInstance->c3_x2 + 1.0, 0.0, -1, 3U, -0.048 *
            *chartInstance->c3_x2 + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_h_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M2 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
            chartInstance->c3_stateChanged = true;
            chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M236;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M236 = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
              c3_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_x_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_x_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            for (c3_i26 = 0; c3_i26 < 9; c3_i26++) {
              chartInstance->c3_A4[c3_i26] = c3_dv3[c3_i26];
            }

            chartInstance->c3_dataWrittenToVector[6U] = true;
            for (c3_i31 = 0; c3_i31 < 9; c3_i31++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_A4[c3_i31], 3U, 4U, 2U,
                                    chartInstance->c3_sfEvent, false);
            }

            for (c3_i34 = 0; c3_i34 < 6; c3_i34++) {
              chartInstance->c3_B4[c3_i34] = c3_dv7[c3_i34];
            }

            chartInstance->c3_dataWrittenToVector[7U] = true;
            for (c3_i37 = 0; c3_i37 < 6; c3_i37++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_B4[c3_i37], 7U, 4U, 2U,
                                    chartInstance->c3_sfEvent, false);
            }

            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
          }
        }
        break;

       case c3_IN_M236:
        CV_CHART_EVAL(0, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        c3_b_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, -0.0527 *
          *chartInstance->c3_x1 + 1.0, 0.0, -1, 5U, -0.0527 *
          *chartInstance->c3_x1 + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M236 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M2 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i0 = 0; c3_i0 < 9; c3_i0++) {
            chartInstance->c3_A2[c3_i0] = c3_dv0[c3_i0];
          }

          chartInstance->c3_dataWrittenToVector[0U] = true;
          for (c3_i5 = 0; c3_i5 < 9; c3_i5++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A2[c3_i5], 1U, 4U, 1U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i11 = 0; c3_i11 < 6; c3_i11++) {
            chartInstance->c3_B2[c3_i11] = c3_dv4[c3_i11];
          }

          chartInstance->c3_dataWrittenToVector[1U] = true;
          for (c3_i18 = 0; c3_i18 < 6; c3_i18++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B2[c3_i18], 5U, 4U, 1U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
        }
        break;

       case c3_IN_M262:
        CV_CHART_EVAL(0, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 5U,
            chartInstance->c3_sfEvent, false);
        }

        c3_c_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0, -0.0539 *
          *chartInstance->c3_x3 + 1.0, 0.0, -1, 5U, -0.0539 *
          *chartInstance->c3_x3 + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M262 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M4;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M4 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i1 = 0; c3_i1 < 9; c3_i1++) {
            chartInstance->c3_A1[c3_i1] = c3_dv1[c3_i1];
          }

          chartInstance->c3_dataWrittenToVector[2U] = true;
          for (c3_i6 = 0; c3_i6 < 9; c3_i6++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A1[c3_i6], 0U, 4U, 5U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i12 = 0; c3_i12 < 6; c3_i12++) {
            chartInstance->c3_B1[c3_i12] = c3_dv5[c3_i12];
          }

          chartInstance->c3_dataWrittenToVector[4U] = true;
          for (c3_i19 = 0; c3_i19 < 6; c3_i19++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B1[c3_i19], 4U, 4U, 5U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
        }
        break;

       case c3_IN_M263:
        CV_CHART_EVAL(0, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 7U,
            chartInstance->c3_sfEvent, false);
        }

        c3_d_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, -0.0496 *
          *chartInstance->c3_x1 + 1.0, 0.0, -1, 5U, -0.0496 *
          *chartInstance->c3_x1 + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M263 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M5;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M5 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_q_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_q_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i2 = 0; c3_i2 < 9; c3_i2++) {
            chartInstance->c3_A3[c3_i2] = c3_dv2[c3_i2];
          }

          chartInstance->c3_dataWrittenToVector[3U] = true;
          for (c3_i7 = 0; c3_i7 < 9; c3_i7++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A3[c3_i7], 2U, 4U, 6U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i13 = 0; c3_i13 < 6; c3_i13++) {
            chartInstance->c3_B3[c3_i13] = c3_dv6[c3_i13];
          }

          chartInstance->c3_dataWrittenToVector[5U] = true;
          for (c3_i20 = 0; c3_i20 < 6; c3_i20++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B3[c3_i20], 6U, 4U, 6U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
        }
        break;

       case c3_IN_M4:
        CV_CHART_EVAL(0, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[9U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        guard1 = false;
        if (CV_EML_COND(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, ((0.4884 *
                *chartInstance->c3_x1 + 0.0013 * *chartInstance->c3_x2) - 0.4901
               * *chartInstance->c3_x3) + 1.0, 0.0, -1, 3U, ((0.4884 *
                *chartInstance->c3_x1 + 0.0013 * *chartInstance->c3_x2) - 0.4901
               * *chartInstance->c3_x3) + 1.0 <= 0.0))) {
          if (CV_EML_COND(2, 0, 1, CV_RELATIONAL_EVAL(5U, 2U, 1, -0.0627 *
                *chartInstance->c3_x1 + 1.0, 0.0, -1, 5U, -0.0627 *
                *chartInstance->c3_x1 + 1.0 >= 0.0))) {
            CV_EML_MCDC(2, 0, 0, true);
            CV_EML_IF(2, 0, 0, true);
            c3_e_out = true;
          } else {
            guard1 = true;
          }
        } else {
          if (!chartInstance->c3_dataWrittenToVector[8U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 2U,
              chartInstance->c3_sfEvent, false);
          }

          guard1 = true;
        }

        if (guard1) {
          CV_EML_MCDC(2, 0, 0, false);
          CV_EML_IF(2, 0, 0, false);
          c3_e_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M4 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M5;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M5 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_w_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_w_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i15 = 0; c3_i15 < 9; c3_i15++) {
            chartInstance->c3_A3[c3_i15] = c3_dv2[c3_i15];
          }

          chartInstance->c3_dataWrittenToVector[3U] = true;
          for (c3_i22 = 0; c3_i22 < 9; c3_i22++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A3[c3_i22], 2U, 4U, 6U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i25 = 0; c3_i25 < 6; c3_i25++) {
            chartInstance->c3_B3[c3_i25] = c3_dv6[c3_i25];
          }

          chartInstance->c3_dataWrittenToVector[5U] = true;
          for (c3_i30 = 0; c3_i30 < 6; c3_i30++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B3[c3_i30], 6U, 4U, 6U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_v_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_u_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_u_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 6U,
              chartInstance->c3_sfEvent, false);
          }

          c3_i_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, -0.0456 * *
            chartInstance->c3_x3 + 1.0, 0.0, -1, 3U, -0.0456 *
            *chartInstance->c3_x3 + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_i_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M4 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
            chartInstance->c3_stateChanged = true;
            chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M262;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M262 = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
              c3_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_y_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_y_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            for (c3_i28 = 0; c3_i28 < 9; c3_i28++) {
              chartInstance->c3_A4[c3_i28] = c3_dv3[c3_i28];
            }

            chartInstance->c3_dataWrittenToVector[6U] = true;
            for (c3_i32 = 0; c3_i32 < 9; c3_i32++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_A4[c3_i32], 3U, 4U, 3U,
                                    chartInstance->c3_sfEvent, false);
            }

            for (c3_i35 = 0; c3_i35 < 6; c3_i35++) {
              chartInstance->c3_B4[c3_i35] = c3_dv7[c3_i35];
            }

            chartInstance->c3_dataWrittenToVector[7U] = true;
            for (c3_i38 = 0; c3_i38 < 6; c3_i38++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_B4[c3_i38], 7U, 4U, 3U,
                                    chartInstance->c3_sfEvent, false);
            }

            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
          }
        }
        break;

       case c3_IN_M5:
        CV_CHART_EVAL(0, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 8U,
            chartInstance->c3_sfEvent, false);
        }

        c3_f_out = CV_EML_IF(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, -0.0475 *
          *chartInstance->c3_x1 + 1.0, 0.0, -1, 3U, -0.0475 *
          *chartInstance->c3_x1 + 1.0 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M5 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M263;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_M263 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i3 = 0; c3_i3 < 9; c3_i3++) {
            chartInstance->c3_A4[c3_i3] = c3_dv3[c3_i3];
          }

          chartInstance->c3_dataWrittenToVector[6U] = true;
          for (c3_i8 = 0; c3_i8 < 9; c3_i8++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_A4[c3_i8], 3U, 4U, 4U,
                                  chartInstance->c3_sfEvent, false);
          }

          for (c3_i14 = 0; c3_i14 < 6; c3_i14++) {
            chartInstance->c3_B4[c3_i14] = c3_dv7[c3_i14];
          }

          chartInstance->c3_dataWrittenToVector[7U] = true;
          for (c3_i21 = 0; c3_i21 < 6; c3_i21++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_B4[c3_i21], 7U, 4U, 4U,
                                  chartInstance->c3_sfEvent, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[8U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 9U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[9U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 9U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 9U,
              chartInstance->c3_sfEvent, false);
          }

          guard1 = false;
          if (CV_EML_COND(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0, ((-0.3309 *
                  *chartInstance->c3_x1 + 0.3292 * *chartInstance->c3_x2) +
                 0.0016 * *chartInstance->c3_x3) + 1.0, 0.0, -1, 3U, ((-0.3309 *
                  *chartInstance->c3_x1 + 0.3292 * *chartInstance->c3_x2) +
                 0.0016 * *chartInstance->c3_x3) + 1.0 <= 0.0))) {
            if (CV_EML_COND(9, 0, 1, CV_RELATIONAL_EVAL(5U, 9U, 1, -0.0641 *
                  *chartInstance->c3_x2 + 1.0, 0.0, -1, 5U, -0.0641 *
                  *chartInstance->c3_x2 + 1.0 >= 0.0))) {
              CV_EML_MCDC(9, 0, 0, true);
              CV_EML_IF(9, 0, 0, true);
              c3_g_out = true;
            } else {
              guard1 = true;
            }
          } else {
            if (!chartInstance->c3_dataWrittenToVector[9U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            guard1 = true;
          }

          if (guard1) {
            CV_EML_MCDC(9, 0, 0, false);
            CV_EML_IF(9, 0, 0, false);
            c3_g_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c3_g_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M5 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
            chartInstance->c3_stateChanged = true;
            chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_M2;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_M2 = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
              c3_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ab_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ab_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            for (c3_i29 = 0; c3_i29 < 9; c3_i29++) {
              chartInstance->c3_A2[c3_i29] = c3_dv0[c3_i29];
            }

            chartInstance->c3_dataWrittenToVector[0U] = true;
            for (c3_i33 = 0; c3_i33 < 9; c3_i33++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_A2[c3_i33], 1U, 4U, 1U,
                                    chartInstance->c3_sfEvent, false);
            }

            for (c3_i36 = 0; c3_i36 < 6; c3_i36++) {
              chartInstance->c3_B2[c3_i36] = c3_dv4[c3_i36];
            }

            chartInstance->c3_dataWrittenToVector[1U] = true;
            for (c3_i39 = 0; c3_i39 < 6; c3_i39++) {
              _SFD_DATA_RANGE_CHECK(chartInstance->c3_B2[c3_i39], 5U, 4U, 1U,
                                    chartInstance->c3_sfEvent, false);
            }

            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
          }
        }
        break;

       default:
        CV_CHART_EVAL(0, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        break;
      }
    }

    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c3_is_c3_con_ESTHeatingSystem) {
   case c3_IN_M2:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M236:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M262:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M263:
    CV_CHART_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M4:
    CV_CHART_EVAL(0, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M5:
    CV_CHART_EVAL(0, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_con_ESTHeatingSystemMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void zeroCrossings_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
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
  real_T c3_e_nargout = 1.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  boolean_T c3_d_out;
  boolean_T c3_e_out;
  boolean_T c3_f_out;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_g_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 1.0;
  boolean_T c3_h_out;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_i_out;
  real_T *c3_zcVar;
  boolean_T guard1 = false;
  c3_zcVar = (real_T *)(ssGetNonsampledZCs_wrapper(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_lastMajorTime == _sfTime_) {
    *c3_zcVar = -1.0;
  } else {
    chartInstance->c3_stateChanged = (boolean_T)0;
    if (chartInstance->c3_is_active_c3_con_ESTHeatingSystem == 0U) {
      chartInstance->c3_stateChanged = true;
    } else {
      switch (chartInstance->c3_is_c3_con_ESTHeatingSystem) {
       case c3_IN_M2:
        CV_CHART_EVAL(0, 0, 1);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[9U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        guard1 = false;
        if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (-0.4794 *
               *chartInstance->c3_x2 + 0.477 * *chartInstance->c3_x3) + 1.0, 0.0,
              -1, 3U, (-0.4794 * *chartInstance->c3_x2 + 0.477 *
                       *chartInstance->c3_x3) + 1.0 <= 0.0))) {
          if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1, (0.0014 *
                 *chartInstance->c3_x1 - 0.0659 * *chartInstance->c3_x3) + 1.0,
                0.0, -1, 5U, (0.0014 * *chartInstance->c3_x1 - 0.0659 *
                              *chartInstance->c3_x3) + 1.0 >= 0.0))) {
            CV_EML_MCDC(1, 0, 0, true);
            CV_EML_IF(1, 0, 0, true);
            c3_out = true;
          } else {
            guard1 = true;
          }
        } else {
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 1U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[8U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 1U,
              chartInstance->c3_sfEvent, false);
          }

          guard1 = true;
        }

        if (guard1) {
          CV_EML_MCDC(1, 0, 0, false);
          CV_EML_IF(1, 0, 0, false);
          c3_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_out) {
          chartInstance->c3_stateChanged = true;
        } else {
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[9U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 4U,
              chartInstance->c3_sfEvent, false);
          }

          c3_h_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, -0.048 *
            *chartInstance->c3_x2 + 1.0, 0.0, -1, 3U, -0.048 *
            *chartInstance->c3_x2 + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_h_out) {
            chartInstance->c3_stateChanged = true;
          }
        }
        break;

       case c3_IN_M236:
        CV_CHART_EVAL(0, 0, 2);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 3U,
            chartInstance->c3_sfEvent, false);
        }

        c3_b_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, -0.0527 *
          *chartInstance->c3_x1 + 1.0, 0.0, -1, 5U, -0.0527 *
          *chartInstance->c3_x1 + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          chartInstance->c3_stateChanged = true;
        }
        break;

       case c3_IN_M262:
        CV_CHART_EVAL(0, 0, 3);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 5U,
            chartInstance->c3_sfEvent, false);
        }

        c3_c_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0, -0.0539 *
          *chartInstance->c3_x3 + 1.0, 0.0, -1, 5U, -0.0539 *
          *chartInstance->c3_x3 + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_c_out) {
          chartInstance->c3_stateChanged = true;
        }
        break;

       case c3_IN_M263:
        CV_CHART_EVAL(0, 0, 4);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 7U,
            chartInstance->c3_sfEvent, false);
        }

        c3_d_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, -0.0496 *
          *chartInstance->c3_x1 + 1.0, 0.0, -1, 5U, -0.0496 *
          *chartInstance->c3_x1 + 1.0 >= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          chartInstance->c3_stateChanged = true;
        }
        break;

       case c3_IN_M4:
        CV_CHART_EVAL(0, 0, 5);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[9U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        guard1 = false;
        if (CV_EML_COND(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, ((0.4884 *
                *chartInstance->c3_x1 + 0.0013 * *chartInstance->c3_x2) - 0.4901
               * *chartInstance->c3_x3) + 1.0, 0.0, -1, 3U, ((0.4884 *
                *chartInstance->c3_x1 + 0.0013 * *chartInstance->c3_x2) - 0.4901
               * *chartInstance->c3_x3) + 1.0 <= 0.0))) {
          if (CV_EML_COND(2, 0, 1, CV_RELATIONAL_EVAL(5U, 2U, 1, -0.0627 *
                *chartInstance->c3_x1 + 1.0, 0.0, -1, 5U, -0.0627 *
                *chartInstance->c3_x1 + 1.0 >= 0.0))) {
            CV_EML_MCDC(2, 0, 0, true);
            CV_EML_IF(2, 0, 0, true);
            c3_e_out = true;
          } else {
            guard1 = true;
          }
        } else {
          if (!chartInstance->c3_dataWrittenToVector[8U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 2U,
              chartInstance->c3_sfEvent, false);
          }

          guard1 = true;
        }

        if (guard1) {
          CV_EML_MCDC(2, 0, 0, false);
          CV_EML_IF(2, 0, 0, false);
          c3_e_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_e_out) {
          chartInstance->c3_stateChanged = true;
        } else {
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_v_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 6U,
              chartInstance->c3_sfEvent, false);
          }

          c3_i_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, -0.0456 * *
            chartInstance->c3_x3 + 1.0, 0.0, -1, 3U, -0.0456 *
            *chartInstance->c3_x3 + 1.0 <= 0.0));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_i_out) {
            chartInstance->c3_stateChanged = true;
          }
        }
        break;

       case c3_IN_M5:
        CV_CHART_EVAL(0, 0, 6);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 8U,
            chartInstance->c3_sfEvent, false);
        }

        c3_f_out = CV_EML_IF(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, -0.0475 *
          *chartInstance->c3_x1 + 1.0, 0.0, -1, 3U, -0.0475 *
          *chartInstance->c3_x1 + 1.0 <= 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_f_out) {
          chartInstance->c3_stateChanged = true;
        } else {
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          if (!chartInstance->c3_dataWrittenToVector[8U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 5U, 9U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[9U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 9U,
              chartInstance->c3_sfEvent, false);
          }

          if (!chartInstance->c3_dataWrittenToVector[10U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 9U,
              chartInstance->c3_sfEvent, false);
          }

          guard1 = false;
          if (CV_EML_COND(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0, ((-0.3309 *
                  *chartInstance->c3_x1 + 0.3292 * *chartInstance->c3_x2) +
                 0.0016 * *chartInstance->c3_x3) + 1.0, 0.0, -1, 3U, ((-0.3309 *
                  *chartInstance->c3_x1 + 0.3292 * *chartInstance->c3_x2) +
                 0.0016 * *chartInstance->c3_x3) + 1.0 <= 0.0))) {
            if (CV_EML_COND(9, 0, 1, CV_RELATIONAL_EVAL(5U, 9U, 1, -0.0641 *
                  *chartInstance->c3_x2 + 1.0, 0.0, -1, 5U, -0.0641 *
                  *chartInstance->c3_x2 + 1.0 >= 0.0))) {
              CV_EML_MCDC(9, 0, 0, true);
              CV_EML_IF(9, 0, 0, true);
              c3_g_out = true;
            } else {
              guard1 = true;
            }
          } else {
            if (!chartInstance->c3_dataWrittenToVector[9U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 9U,
                chartInstance->c3_sfEvent, false);
            }

            guard1 = true;
          }

          if (guard1) {
            CV_EML_MCDC(9, 0, 0, false);
            CV_EML_IF(9, 0, 0, false);
            c3_g_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c3_g_out) {
            chartInstance->c3_stateChanged = true;
          }
        }
        break;

       default:
        CV_CHART_EVAL(0, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_NO_ACTIVE_CHILD;
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

static void derivatives_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T *c3_x1_dot;
  real_T *c3_x2_dot;
  real_T *c3_x3_dot;
  c3_x3_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 2);
  c3_x2_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 1);
  c3_x1_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 0);
  *c3_x1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 8U, 1U, 0U, chartInstance->c3_sfEvent, false);
  *c3_x2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 9U, 1U, 0U, chartInstance->c3_sfEvent, false);
  *c3_x3_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 10U, 1U, 0U, chartInstance->c3_sfEvent,
                        false);
  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c3_is_c3_con_ESTHeatingSystem) {
   case c3_IN_M2:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A2[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[3] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[6] * *chartInstance->c3_x3) +
                  chartInstance->c3_B2[0] * *chartInstance->c3_ud) +
      chartInstance->c3_B2[3];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 8U, 4U, 1U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A2[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[7] * *chartInstance->c3_x3) +
                  chartInstance->c3_B2[1] * *chartInstance->c3_ud) +
      chartInstance->c3_B2[4];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 9U, 4U, 1U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A2[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A2[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A2[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_B2[2] * *chartInstance->c3_ud) +
      chartInstance->c3_B2[5];
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 10U, 4U, 1U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M236:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A4[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A4[3] * *chartInstance->c3_x2) +
                   chartInstance->c3_A4[6] * *chartInstance->c3_x3) +
                  chartInstance->c3_B4[0] * *chartInstance->c3_ud) +
      chartInstance->c3_B4[3];
    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 8U, 4U, 2U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A4[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A4[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A4[7] * *chartInstance->c3_x3) +
                  chartInstance->c3_B4[1] * *chartInstance->c3_ud) +
      chartInstance->c3_B4[4];
    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 9U, 4U, 2U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A4[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A4[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A4[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_B4[2] * *chartInstance->c3_ud) +
      chartInstance->c3_B4[5];
    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 10U, 4U, 2U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M262:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A4[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A4[3] * *chartInstance->c3_x2) +
                   chartInstance->c3_A4[6] * *chartInstance->c3_x3) +
                  chartInstance->c3_B4[0] * *chartInstance->c3_ud) +
      chartInstance->c3_B4[3];
    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 8U, 4U, 3U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A4[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A4[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A4[7] * *chartInstance->c3_x3) +
                  chartInstance->c3_B4[1] * *chartInstance->c3_ud) +
      chartInstance->c3_B4[4];
    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 9U, 4U, 3U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A4[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A4[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A4[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_B4[2] * *chartInstance->c3_ud) +
      chartInstance->c3_B4[5];
    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 10U, 4U, 3U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M263:
    CV_CHART_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A4[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A4[3] * *chartInstance->c3_x2) +
                   chartInstance->c3_A4[6] * *chartInstance->c3_x3) +
                  chartInstance->c3_B4[0] * *chartInstance->c3_ud) +
      chartInstance->c3_B4[3];
    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 8U, 4U, 4U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A4[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A4[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A4[7] * *chartInstance->c3_x3) +
                  chartInstance->c3_B4[1] * *chartInstance->c3_ud) +
      chartInstance->c3_B4[4];
    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 9U, 4U, 4U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A4[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A4[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A4[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_B4[2] * *chartInstance->c3_ud) +
      chartInstance->c3_B4[5];
    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 10U, 4U, 4U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M4:
    CV_CHART_EVAL(0, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A1[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[3] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[6] * *chartInstance->c3_x3) +
                  chartInstance->c3_B1[0] * *chartInstance->c3_ud) +
      chartInstance->c3_B1[3];
    chartInstance->c3_dataWrittenToVector[4U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 8U, 4U, 5U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A1[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[7] * *chartInstance->c3_x3) +
                  chartInstance->c3_B1[1] * *chartInstance->c3_ud) +
      chartInstance->c3_B1[4];
    chartInstance->c3_dataWrittenToVector[4U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 9U, 4U, 5U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A1[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A1[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A1[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_B1[2] * *chartInstance->c3_ud) +
      chartInstance->c3_B1[5];
    chartInstance->c3_dataWrittenToVector[4U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 10U, 4U, 5U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M5:
    CV_CHART_EVAL(0, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x1_dot = (((chartInstance->c3_A3[0] * *chartInstance->c3_x1 +
                    chartInstance->c3_A3[3] * *chartInstance->c3_x2) +
                   chartInstance->c3_A3[6] * *chartInstance->c3_x3) +
                  chartInstance->c3_B3[0] * *chartInstance->c3_ud) +
      chartInstance->c3_B3[3];
    chartInstance->c3_dataWrittenToVector[5U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 8U, 4U, 6U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x2_dot = (((chartInstance->c3_A3[1] * *chartInstance->c3_x1 +
                    chartInstance->c3_A3[4] * *chartInstance->c3_x2) +
                   chartInstance->c3_A3[7] * *chartInstance->c3_x3) +
                  chartInstance->c3_B3[1] * *chartInstance->c3_ud) +
      chartInstance->c3_B3[4];
    chartInstance->c3_dataWrittenToVector[5U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 9U, 4U, 6U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    *c3_x3_dot = (((chartInstance->c3_A3[2] * *chartInstance->c3_x1 +
                    chartInstance->c3_A3[5] * *chartInstance->c3_x2) +
                   chartInstance->c3_A3[8] * *chartInstance->c3_x3) +
                  chartInstance->c3_B3[2] * *chartInstance->c3_ud) +
      chartInstance->c3_B3[5];
    chartInstance->c3_dataWrittenToVector[5U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*c3_x3_dot, 10U, 4U, 6U, chartInstance->c3_sfEvent,
                          false);
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    break;
  }
}

static void outputs_c3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargout = 0.0;
  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c3_is_c3_con_ESTHeatingSystem) {
   case c3_IN_M2:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 1U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M236:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 2U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M262:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 3U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 3U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M263:
    CV_CHART_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[7U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 4U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M4:
    CV_CHART_EVAL(0, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[4U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 5U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_M5:
    CV_CHART_EVAL(0, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    chartInstance->c3_dataWrittenToVector[5U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out1 = *chartInstance->c3_x1;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out1, 12U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out2 = *chartInstance->c3_x2;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out2, 13U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 6U, chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_out3 = *chartInstance->c3_x3;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_out3, 14U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    break;
  }
}

static void initSimStructsc3_con_ESTHeatingSystem
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_ini_fcn_to_be_inlined_491
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_term_fcn_to_be_inlined_491
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
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

static const mxArray *c3_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const real_T c3_u)
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
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_emlrt_marshallOut(chartInstance, *(real_T
    *)c3_inData), false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
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

static real_T c3_b_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
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
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  *(real_T *)c3_outData = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const boolean_T c3_u)
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
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_b_emlrt_marshallOut(chartInstance,
    *(boolean_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
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

static boolean_T c3_d_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
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
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  *(boolean_T *)c3_outData = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_con_ESTHeatingSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const int32_T c3_u)
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
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_c_emlrt_marshallOut(chartInstance,
    *(int32_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
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

static int32_T c3_f_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i40;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i40, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i40;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c3_outData = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const uint8_T c3_u)
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
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_d_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_M2, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_M2), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_M2);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
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
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c3_outData = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const real_T c3_u[9])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  return c3_y;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_e_emlrt_marshallOut(chartInstance,
    *(real_T (*)[9])c3_inData), false);
  return c3_mxArrayOutData;
}

static void c3_i_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_A2, const char_T *c3_identifier, real_T
  c3_y[9])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_A2), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_A2);
}

static void c3_j_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[9])
{
  real_T c3_dv8[9];
  int32_T c3_i41;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv8, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c3_i41 = 0; c3_i41 < 9; c3_i41++) {
    c3_y[c3_i41] = c3_dv8[c3_i41];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  real_T c3_dv9[9];
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mxArrayInData), c3_varName,
                        c3_dv9);
  c3_i42 = 0;
  for (c3_i43 = 0; c3_i43 < 3; c3_i43++) {
    for (c3_i44 = 0; c3_i44 < 3; c3_i44++) {
      (*(real_T (*)[9])c3_outData)[c3_i44 + c3_i42] = c3_dv9[c3_i44 + c3_i42];
    }

    c3_i42 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const real_T c3_u[6])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 2), false);
  return c3_y;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_f_emlrt_marshallOut(chartInstance,
    *(real_T (*)[6])c3_inData), false);
  return c3_mxArrayOutData;
}

static void c3_k_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_B2, const char_T *c3_identifier, real_T
  c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_B2), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_B2);
}

static void c3_l_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[6])
{
  real_T c3_dv10[6];
  int32_T c3_i45;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv10, 1, 0, 0U, 1, 0U, 2, 3, 2);
  for (c3_i45 = 0; c3_i45 < 6; c3_i45++) {
    c3_y[c3_i45] = c3_dv10[c3_i45];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  real_T c3_dv11[6];
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)chartInstanceVoid;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mxArrayInData), c3_varName,
                        c3_dv11);
  c3_i46 = 0;
  for (c3_i47 = 0; c3_i47 < 2; c3_i47++) {
    for (c3_i48 = 0; c3_i48 < 3; c3_i48++) {
      (*(real_T (*)[6])c3_outData)[c3_i48 + c3_i46] = c3_dv11[c3_i48 + c3_i46];
    }

    c3_i46 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  const mxArray *c3_y;
  int32_T c3_i49;
  real_T c3_dv12[9];
  int32_T c3_i50;
  real_T c3_dv13[9];
  int32_T c3_i51;
  real_T c3_dv14[9];
  int32_T c3_i52;
  real_T c3_dv15[9];
  int32_T c3_i53;
  real_T c3_dv16[6];
  int32_T c3_i54;
  real_T c3_dv17[6];
  int32_T c3_i55;
  real_T c3_dv18[6];
  int32_T c3_i56;
  real_T c3_dv19[6];
  int32_T c3_i57;
  boolean_T c3_bv0[12];
  c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(17, 1), false);
  sf_mex_setcell(c3_y, 0, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_out1));
  sf_mex_setcell(c3_y, 1, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_out2));
  sf_mex_setcell(c3_y, 2, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_out3));
  for (c3_i49 = 0; c3_i49 < 9; c3_i49++) {
    c3_dv12[c3_i49] = chartInstance->c3_A1[c3_i49];
  }

  sf_mex_setcell(c3_y, 3, c3_e_emlrt_marshallOut(chartInstance, c3_dv12));
  for (c3_i50 = 0; c3_i50 < 9; c3_i50++) {
    c3_dv13[c3_i50] = chartInstance->c3_A2[c3_i50];
  }

  sf_mex_setcell(c3_y, 4, c3_e_emlrt_marshallOut(chartInstance, c3_dv13));
  for (c3_i51 = 0; c3_i51 < 9; c3_i51++) {
    c3_dv14[c3_i51] = chartInstance->c3_A3[c3_i51];
  }

  sf_mex_setcell(c3_y, 5, c3_e_emlrt_marshallOut(chartInstance, c3_dv14));
  for (c3_i52 = 0; c3_i52 < 9; c3_i52++) {
    c3_dv15[c3_i52] = chartInstance->c3_A4[c3_i52];
  }

  sf_mex_setcell(c3_y, 6, c3_e_emlrt_marshallOut(chartInstance, c3_dv15));
  for (c3_i53 = 0; c3_i53 < 6; c3_i53++) {
    c3_dv16[c3_i53] = chartInstance->c3_B1[c3_i53];
  }

  sf_mex_setcell(c3_y, 7, c3_f_emlrt_marshallOut(chartInstance, c3_dv16));
  for (c3_i54 = 0; c3_i54 < 6; c3_i54++) {
    c3_dv17[c3_i54] = chartInstance->c3_B2[c3_i54];
  }

  sf_mex_setcell(c3_y, 8, c3_f_emlrt_marshallOut(chartInstance, c3_dv17));
  for (c3_i55 = 0; c3_i55 < 6; c3_i55++) {
    c3_dv18[c3_i55] = chartInstance->c3_B3[c3_i55];
  }

  sf_mex_setcell(c3_y, 9, c3_f_emlrt_marshallOut(chartInstance, c3_dv18));
  for (c3_i56 = 0; c3_i56 < 6; c3_i56++) {
    c3_dv19[c3_i56] = chartInstance->c3_B4[c3_i56];
  }

  sf_mex_setcell(c3_y, 10, c3_f_emlrt_marshallOut(chartInstance, c3_dv19));
  sf_mex_setcell(c3_y, 11, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x1));
  sf_mex_setcell(c3_y, 12, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x2));
  sf_mex_setcell(c3_y, 13, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x3));
  sf_mex_setcell(c3_y, 14, c3_d_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_active_c3_con_ESTHeatingSystem));
  sf_mex_setcell(c3_y, 15, c3_d_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_c3_con_ESTHeatingSystem));
  for (c3_i57 = 0; c3_i57 < 12; c3_i57++) {
    c3_bv0[c3_i57] = chartInstance->c3_dataWrittenToVector[c3_i57];
  }

  sf_mex_setcell(c3_y, 16, c3_h_emlrt_marshallOut(chartInstance, c3_bv0));
  return c3_y;
}

static const mxArray *c3_h_emlrt_marshallOut
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const boolean_T c3_u
   [12])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 11, 0U, 1U, 0U, 1, 12), false);
  return c3_y;
}

static void c3_m_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u)
{
  real_T c3_dv20[9];
  int32_T c3_i58;
  real_T c3_dv21[9];
  int32_T c3_i59;
  real_T c3_dv22[9];
  int32_T c3_i60;
  real_T c3_dv23[9];
  int32_T c3_i61;
  real_T c3_dv24[6];
  int32_T c3_i62;
  real_T c3_dv25[6];
  int32_T c3_i63;
  real_T c3_dv26[6];
  int32_T c3_i64;
  real_T c3_dv27[6];
  int32_T c3_i65;
  boolean_T c3_bv1[12];
  int32_T c3_i66;
  *chartInstance->c3_out1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("out1", c3_u, 0)), "out1");
  *chartInstance->c3_out2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("out2", c3_u, 1)), "out2");
  *chartInstance->c3_out3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("out3", c3_u, 2)), "out3");
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A1", c3_u, 3)),
                        "A1", c3_dv20);
  for (c3_i58 = 0; c3_i58 < 9; c3_i58++) {
    chartInstance->c3_A1[c3_i58] = c3_dv20[c3_i58];
  }

  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A2", c3_u, 4)),
                        "A2", c3_dv21);
  for (c3_i59 = 0; c3_i59 < 9; c3_i59++) {
    chartInstance->c3_A2[c3_i59] = c3_dv21[c3_i59];
  }

  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A3", c3_u, 5)),
                        "A3", c3_dv22);
  for (c3_i60 = 0; c3_i60 < 9; c3_i60++) {
    chartInstance->c3_A3[c3_i60] = c3_dv22[c3_i60];
  }

  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A4", c3_u, 6)),
                        "A4", c3_dv23);
  for (c3_i61 = 0; c3_i61 < 9; c3_i61++) {
    chartInstance->c3_A4[c3_i61] = c3_dv23[c3_i61];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("B1", c3_u, 7)),
                        "B1", c3_dv24);
  for (c3_i62 = 0; c3_i62 < 6; c3_i62++) {
    chartInstance->c3_B1[c3_i62] = c3_dv24[c3_i62];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("B2", c3_u, 8)),
                        "B2", c3_dv25);
  for (c3_i63 = 0; c3_i63 < 6; c3_i63++) {
    chartInstance->c3_B2[c3_i63] = c3_dv25[c3_i63];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("B3", c3_u, 9)),
                        "B3", c3_dv26);
  for (c3_i64 = 0; c3_i64 < 6; c3_i64++) {
    chartInstance->c3_B3[c3_i64] = c3_dv26[c3_i64];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("B4", c3_u, 10)),
                        "B4", c3_dv27);
  for (c3_i65 = 0; c3_i65 < 6; c3_i65++) {
    chartInstance->c3_B4[c3_i65] = c3_dv27[c3_i65];
  }

  *chartInstance->c3_x1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x1", c3_u, 11)), "x1");
  *chartInstance->c3_x2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x2", c3_u, 12)), "x2");
  *chartInstance->c3_x3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x3", c3_u, 13)), "x3");
  chartInstance->c3_is_active_c3_con_ESTHeatingSystem = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c3_con_ESTHeatingSystem", c3_u, 14)),
     "is_active_c3_con_ESTHeatingSystem");
  chartInstance->c3_is_c3_con_ESTHeatingSystem = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_c3_con_ESTHeatingSystem", c3_u,
       15)), "is_c3_con_ESTHeatingSystem");
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 16)), "dataWrittenToVector", c3_bv1);
  for (c3_i66 = 0; c3_i66 < 12; c3_i66++) {
    chartInstance->c3_dataWrittenToVector[c3_i66] = c3_bv1[c3_i66];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 17)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c3_u);
}

static void c3_n_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[12])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_o_emlrt_marshallIn(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[12])
{
  boolean_T c3_bv2[12];
  int32_T c3_i67;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv2, 1, 11, 0U, 1, 0U, 1, 12);
  for (c3_i67 = 0; c3_i67 < 12; c3_i67++) {
    c3_y[c3_i67] = c3_bv2[c3_i67];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_p_emlrt_marshallIn
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
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

static const mxArray *c3_q_emlrt_marshallIn
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId)
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
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance, int32_T c3_ssid)
{
  const mxArray *c3_msgInfo;
  (void)chartInstance;
  (void)c3_ssid;
  c3_msgInfo = NULL;
  return NULL;
}

static void c3_init_sf_message_store_memory
  (SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_con_ESTHeatingSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_out1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_ud = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c3_x1 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    0);
  chartInstance->c3_x2 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    1);
  chartInstance->c3_x3 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    2);
  chartInstance->c3_out2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_out3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c3_con_ESTHeatingSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(250613842U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3890518405U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4205736899U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(954812757U);
}

mxArray* sf_c3_con_ESTHeatingSystem_get_post_codegen_info(void);
mxArray *sf_c3_con_ESTHeatingSystem_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IOXTPo15LWdbvz6a247QR");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(2);
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
      pr[0] = (double)(3);
      pr[1] = (double)(2);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(2);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c3_con_ESTHeatingSystem_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_con_ESTHeatingSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_con_ESTHeatingSystem_jit_fallback_info(void)
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

mxArray *sf_c3_con_ESTHeatingSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_con_ESTHeatingSystem_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_con_ESTHeatingSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[9],T\"out1\",},{M[1],M[36],T\"out2\",},{M[1],M[37],T\"out3\",},{M[3],M[12],T\"A1\",},{M[3],M[2],T\"A2\",},{M[3],M[13],T\"A3\",},{M[3],M[19],T\"A4\",},{M[3],M[14],T\"B1\",},{M[3],M[3],T\"B2\",},{M[3],M[15],T\"B3\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[3],M[20],T\"B4\",},{M[5],M[33],T\"x1\",},{M[5],M[34],T\"x2\",},{M[5],M[35],T\"x3\",},{M[8],M[0],T\"is_active_c3_con_ESTHeatingSystem\",},{M[9],M[0],T\"is_c3_con_ESTHeatingSystem\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 17, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_con_ESTHeatingSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_con_ESTHeatingSystemInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance =
      (SFc3_con_ESTHeatingSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _con_ESTHeatingSystemMachineNumber_,
           3,
           7,
           10,
           0,
           18,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_con_ESTHeatingSystemMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_con_ESTHeatingSystemMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _con_ESTHeatingSystemMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"A1");
          _SFD_SET_DATA_PROPS(1,0,0,0,"A2");
          _SFD_SET_DATA_PROPS(2,0,0,0,"A3");
          _SFD_SET_DATA_PROPS(3,0,0,0,"A4");
          _SFD_SET_DATA_PROPS(4,0,0,0,"B1");
          _SFD_SET_DATA_PROPS(5,0,0,0,"B2");
          _SFD_SET_DATA_PROPS(6,0,0,0,"B3");
          _SFD_SET_DATA_PROPS(7,0,0,0,"B4");
          _SFD_SET_DATA_PROPS(8,0,0,0,"x1");
          _SFD_SET_DATA_PROPS(9,0,0,0,"x2");
          _SFD_SET_DATA_PROPS(10,0,0,0,"x3");
          _SFD_SET_DATA_PROPS(11,1,1,0,"ud");
          _SFD_SET_DATA_PROPS(12,2,0,1,"out1");
          _SFD_SET_DATA_PROPS(13,2,0,1,"out2");
          _SFD_SET_DATA_PROPS(14,2,0,1,"out3");
          _SFD_SET_DATA_PROPS(15,8,0,0,"");
          _SFD_SET_DATA_PROPS(16,8,0,0,"");
          _SFD_SET_DATA_PROPS(17,9,0,0,"");
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(6);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_CH_SUBSTATE_INDEX(1,2);
          _SFD_CH_SUBSTATE_INDEX(2,3);
          _SFD_CH_SUBSTATE_INDEX(3,4);
          _SFD_CH_SUBSTATE_INDEX(4,5);
          _SFD_CH_SUBSTATE_INDEX(5,6);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(6,1,0,0);

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
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"FnM",0,-1,37);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,61,1,48);

        {
          static int condStart[] = { 2, 45 };

          static int condEnd[] = { 39, 60 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,1,61,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,2,39,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,1,45,60,-1,5);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,60,1,48);

        {
          static int condStart[] = { 2, 34 };

          static int condEnd[] = { 29, 59 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,60,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,2,29,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,1,34,59,-1,5);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,61,1,48);

        {
          static int condStart[] = { 2, 44 };

          static int condEnd[] = { 38, 60 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,61,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,2,38,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,1,44,60,-1,5);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,17,1,17);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,17,-1,5);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,17,1,17);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,17,-1,3);
        _SFD_CV_INIT_EML(7,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,17,1,17);
        _SFD_CV_INIT_EML_RELATIONAL(7,0,0,1,17,-1,5);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,17,1,17);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,17,-1,3);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,17,1,17);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,17,-1,5);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,17,1,17);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,17,-1,3);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _con_ESTHeatingSystemMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance =
      (SFc3_con_ESTHeatingSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c3_A2);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)&chartInstance->c3_B2);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c3_out1);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c3_A1);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c3_A3);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)&chartInstance->c3_B1);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)&chartInstance->c3_B3);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)&chartInstance->c3_A4);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)&chartInstance->c3_B4);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c3_ud);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c3_x1);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c3_x2);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c3_x3);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c3_out2);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)chartInstance->c3_out3);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ssZYo2FGVzAXvL6fTykGSWB";
}

static void sf_opaque_initialize_c3_con_ESTHeatingSystem(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_con_ESTHeatingSystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_con_ESTHeatingSystem
    ((SFc3_con_ESTHeatingSystemInstanceStruct*) chartInstanceVar);
  initialize_c3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_con_ESTHeatingSystem(void *chartInstanceVar)
{
  enable_c3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_con_ESTHeatingSystem(void *chartInstanceVar)
{
  disable_c3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c3_con_ESTHeatingSystem(void
  *chartInstanceVar)
{
  zeroCrossings_c3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_derivatives_c3_con_ESTHeatingSystem(void *chartInstanceVar)
{
  derivatives_c3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_outputs_c3_con_ESTHeatingSystem(void *chartInstanceVar)
{
  outputs_c3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_con_ESTHeatingSystem(void *chartInstanceVar)
{
  sf_gateway_c3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_con_ESTHeatingSystem(SimStruct*
  S)
{
  return get_sim_state_c3_con_ESTHeatingSystem
    ((SFc3_con_ESTHeatingSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_con_ESTHeatingSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_con_ESTHeatingSystem(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_con_ESTHeatingSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_con_ESTHeatingSystem_optimization_info();
    }

    finalize_c3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
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
  initSimStructsc3_con_ESTHeatingSystem((SFc3_con_ESTHeatingSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_con_ESTHeatingSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_con_ESTHeatingSystem
      ((SFc3_con_ESTHeatingSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_con_ESTHeatingSystem(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_con_ESTHeatingSystem_optimization_info
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
        infoStruct,3,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
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
  ssSetChecksum0(S,(780236518U));
  ssSetChecksum1(S,(3419849165U));
  ssSetChecksum2(S,(3422582019U));
  ssSetChecksum3(S,(189453334U));
  ssSetNumContStates(S,3);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_con_ESTHeatingSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_con_ESTHeatingSystem(SimStruct *S)
{
  SFc3_con_ESTHeatingSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_con_ESTHeatingSystemInstanceStruct *)utMalloc(sizeof
    (SFc3_con_ESTHeatingSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_con_ESTHeatingSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.zeroCrossings =
    sf_opaque_zeroCrossings_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.derivatives =
    sf_opaque_derivatives_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_con_ESTHeatingSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_con_ESTHeatingSystem;
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
  mdl_start_c3_con_ESTHeatingSystem(chartInstance);
}

void c3_con_ESTHeatingSystem_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_con_ESTHeatingSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_con_ESTHeatingSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_con_ESTHeatingSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_con_ESTHeatingSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
