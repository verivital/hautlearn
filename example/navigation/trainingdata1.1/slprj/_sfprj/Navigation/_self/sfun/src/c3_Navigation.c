/* Include files */

#include "Navigation_sfun.h"
#include "c3_Navigation.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Navigation_sfun_debug_macros.h"
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
#define c3_IN_sys                      ((uint8_T)1U)
#define c3_IN_A                        ((uint8_T)1U)
#define c3_IN_S1                       ((uint8_T)2U)
#define c3_IN_S2                       ((uint8_T)3U)
#define c3_IN_S3                       ((uint8_T)4U)
#define c3_IN_S4                       ((uint8_T)5U)
#define c3_IN_S5                       ((uint8_T)6U)

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

static const char * c3_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

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
static void initialize_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance);
static void initialize_params_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance);
static void enable_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance);
static void disable_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_Navigation(SFc3_NavigationInstanceStruct *
  chartInstance);
static void set_sim_state_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_Navigation
  (SFc3_NavigationInstanceStruct *chartInstance);
static void finalize_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance);
static void sf_gateway_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance);
static void mdl_start_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance);
static void initSimStructsc3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_NavigationInstanceStruct *chartInstance,
  const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_NavigationInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier);
static boolean_T c3_d_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_sys, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_h_emlrt_marshallIn(SFc3_NavigationInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_b_y[2]);
static void c3_i_emlrt_marshallIn(SFc3_NavigationInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_b_y[2]);
static const mxArray *c3_j_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_k_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc3_NavigationInstanceStruct
  *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_NavigationInstanceStruct
  *chartInstance);
static void outputs_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc3_NavigationInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_NavigationInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_Navigation(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_sys = 0U;
  chartInstance->c3_is_active_Conditions = 0U;
  chartInstance->c3_tp_Conditions = 0U;
  chartInstance->c3_is_active_S1 = 0U;
  chartInstance->c3_is_S1 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_S1 = 0U;
  chartInstance->c3_tp_A = 0U;
  chartInstance->c3_b_tp_S1 = 0U;
  chartInstance->c3_tp_S2 = 0U;
  chartInstance->c3_tp_S3 = 0U;
  chartInstance->c3_tp_S4 = 0U;
  chartInstance->c3_tp_S5 = 0U;
  chartInstance->c3_is_active_c3_Navigation = 0U;
  chartInstance->c3_is_c3_Navigation = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_c1 = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c1, 0U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_c2 = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c2, 1U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_c3 = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c3, 2U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_c4 = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c4, 3U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_c5 = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c5, 4U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_label = 2.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_label, 5U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_active_c3_Navigation = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_c3_Navigation = c3_IN_sys;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_sys = 1U;
  chartInstance->c3_is_active_Conditions = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_Conditions = 1U;
  chartInstance->c3_is_active_S1 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_S1 = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_S1 = c3_IN_S1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  chartInstance->c3_b_tp_S1 = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_NavigationMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_Navigation == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_Navigation == c3_IN_sys) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_S1 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_S1 == c3_IN_S4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_S1 == c3_IN_S2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_S1 == c3_IN_S5) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_S1 == c3_IN_S1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_S1 == c3_IN_S3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_S1 == c3_IN_A) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_Conditions == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_Navigation(SFc3_NavigationInstanceStruct *
  chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_b_y = NULL;
  real_T c3_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  real_T c3_b_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  boolean_T c3_c_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  boolean_T c3_d_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  boolean_T c3_e_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  boolean_T c3_f_hoistedGlobal;
  const mxArray *c3_h_y = NULL;
  boolean_T c3_g_hoistedGlobal;
  const mxArray *c3_i_y = NULL;
  real_T c3_h_hoistedGlobal;
  const mxArray *c3_j_y = NULL;
  uint8_T c3_i_hoistedGlobal;
  const mxArray *c3_k_y = NULL;
  uint8_T c3_j_hoistedGlobal;
  const mxArray *c3_l_y = NULL;
  uint8_T c3_k_hoistedGlobal;
  const mxArray *c3_m_y = NULL;
  uint8_T c3_l_hoistedGlobal;
  const mxArray *c3_n_y = NULL;
  uint8_T c3_m_hoistedGlobal;
  const mxArray *c3_o_y = NULL;
  const mxArray *c3_p_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createcellmatrix(14, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_vdx;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_b_y, 0, c3_c_y);
  c3_b_hoistedGlobal = *chartInstance->c3_vdy;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 1, c3_d_y);
  c3_c_hoistedGlobal = chartInstance->c3_c1;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_c_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 2, c3_e_y);
  c3_d_hoistedGlobal = chartInstance->c3_c2;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_d_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 3, c3_f_y);
  c3_e_hoistedGlobal = chartInstance->c3_c3;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_e_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 4, c3_g_y);
  c3_f_hoistedGlobal = chartInstance->c3_c4;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_f_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 5, c3_h_y);
  c3_g_hoistedGlobal = chartInstance->c3_c5;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_g_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 6, c3_i_y);
  c3_h_hoistedGlobal = chartInstance->c3_label;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_h_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 7, c3_j_y);
  c3_i_hoistedGlobal = chartInstance->c3_is_active_c3_Navigation;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_i_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 8, c3_k_y);
  c3_j_hoistedGlobal = chartInstance->c3_is_active_S1;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_j_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 9, c3_l_y);
  c3_k_hoistedGlobal = chartInstance->c3_is_active_Conditions;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_k_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 10, c3_m_y);
  c3_l_hoistedGlobal = chartInstance->c3_is_c3_Navigation;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_l_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 11, c3_n_y);
  c3_m_hoistedGlobal = chartInstance->c3_is_S1;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_m_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 12, c3_o_y);
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c3_b_y, 13, c3_p_y);
  sf_mex_assign(&c3_st, c3_b_y, false);
  return c3_st;
}

static void set_sim_state_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  boolean_T c3_bv0[2];
  int32_T c3_i0;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_vdx = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("vdx", c3_u, 0)), "vdx");
  *chartInstance->c3_vdy = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("vdy", c3_u, 1)), "vdy");
  chartInstance->c3_c1 = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("c1", c3_u, 2)), "c1");
  chartInstance->c3_c2 = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("c2", c3_u, 3)), "c2");
  chartInstance->c3_c3 = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("c3", c3_u, 4)), "c3");
  chartInstance->c3_c4 = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("c4", c3_u, 5)), "c4");
  chartInstance->c3_c5 = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("c5", c3_u, 6)), "c5");
  chartInstance->c3_label = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("label", c3_u, 7)), "label");
  chartInstance->c3_is_active_c3_Navigation = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c3_Navigation", c3_u, 8)),
     "is_active_c3_Navigation");
  chartInstance->c3_is_active_S1 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_S1", c3_u, 9)), "is_active_S1");
  chartInstance->c3_is_active_Conditions = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_Conditions", c3_u, 10)),
    "is_active_Conditions");
  chartInstance->c3_is_c3_Navigation = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c3_Navigation", c3_u, 11)), "is_c3_Navigation");
  chartInstance->c3_is_S1 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_S1", c3_u, 12)), "is_S1");
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 13)), "dataWrittenToVector", c3_bv0);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    chartInstance->c3_dataWrittenToVector[c3_i0] = c3_bv0[c3_i0];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 14)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_Navigation(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_Navigation
  (SFc3_NavigationInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_tp_sys = (uint8_T)(chartInstance->c3_is_c3_Navigation ==
      c3_IN_sys);
    chartInstance->c3_tp_Conditions = (uint8_T)
      (chartInstance->c3_is_active_Conditions == 1U);
    chartInstance->c3_tp_S1 = (uint8_T)(chartInstance->c3_is_active_S1 == 1U);
    chartInstance->c3_tp_A = (uint8_T)(chartInstance->c3_is_S1 == c3_IN_A);
    chartInstance->c3_b_tp_S1 = (uint8_T)(chartInstance->c3_is_S1 == c3_IN_S1);
    chartInstance->c3_tp_S2 = (uint8_T)(chartInstance->c3_is_S1 == c3_IN_S2);
    chartInstance->c3_tp_S3 = (uint8_T)(chartInstance->c3_is_S1 == c3_IN_S3);
    chartInstance->c3_tp_S4 = (uint8_T)(chartInstance->c3_is_S1 == c3_IN_S4);
    chartInstance->c3_tp_S5 = (uint8_T)(chartInstance->c3_is_S1 == c3_IN_S5);
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  boolean_T c3_b_c1;
  boolean_T c3_b_c2;
  boolean_T c3_b_c3;
  boolean_T c3_b_c4;
  boolean_T c3_b_c5;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_A;
  real_T c3_b_A;
  real_T c3_c_A;
  real_T c3_d_A;
  real_T c3_e_A;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_b_y;
  real_T c3_c_y;
  real_T c3_d_y;
  real_T c3_e_y;
  real_T c3_f_y;
  real_T c3_l_x;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_p_x;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_g_nargin = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  real_T c3_h_nargout = 1.0;
  real_T c3_i_nargout = 1.0;
  real_T c3_j_nargout = 1.0;
  real_T c3_k_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  boolean_T c3_d_out;
  boolean_T c3_e_out;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_hoistedGlobal;
  real_T c3_i_hoistedGlobal;
  real_T c3_j_hoistedGlobal;
  real_T c3_f_A;
  real_T c3_g_A;
  real_T c3_h_A;
  real_T c3_i_A;
  real_T c3_j_A;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_w_x;
  real_T c3_x_x;
  real_T c3_y_x;
  real_T c3_ab_x;
  real_T c3_g_y;
  real_T c3_h_y;
  real_T c3_i_y;
  real_T c3_j_y;
  real_T c3_k_y;
  real_T c3_bb_x;
  real_T c3_cb_x;
  real_T c3_db_x;
  real_T c3_eb_x;
  real_T c3_fb_x;
  real_T c3_l_nargin = 0.0;
  real_T c3_m_nargin = 0.0;
  real_T c3_n_nargin = 0.0;
  real_T c3_o_nargin = 0.0;
  real_T c3_p_nargin = 0.0;
  real_T c3_l_nargout = 1.0;
  real_T c3_m_nargout = 1.0;
  real_T c3_n_nargout = 1.0;
  real_T c3_o_nargout = 1.0;
  real_T c3_p_nargout = 1.0;
  boolean_T c3_f_out;
  boolean_T c3_g_out;
  boolean_T c3_h_out;
  boolean_T c3_i_out;
  boolean_T c3_j_out;
  real_T c3_q_nargin = 0.0;
  real_T c3_r_nargin = 0.0;
  real_T c3_s_nargin = 0.0;
  real_T c3_t_nargin = 0.0;
  real_T c3_u_nargin = 0.0;
  real_T c3_q_nargout = 1.0;
  real_T c3_r_nargout = 1.0;
  real_T c3_s_nargout = 1.0;
  real_T c3_t_nargout = 1.0;
  real_T c3_u_nargout = 1.0;
  boolean_T c3_k_out;
  boolean_T c3_l_out;
  boolean_T c3_m_out;
  boolean_T c3_n_out;
  boolean_T c3_o_out;
  real_T c3_v_nargin = 0.0;
  real_T c3_v_nargout = 1.0;
  boolean_T c3_p_out;
  c3_set_sim_state_side_effects_c3_Navigation(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_y, 7U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x, 6U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  if ((*chartInstance->c3_x >= 0.0) && (*chartInstance->c3_x <= 2.0) &&
      (*chartInstance->c3_y >= 0.0) && (*chartInstance->c3_y <= 1.0)) {
    c3_b_c1 = true;
  } else {
    c3_b_c1 = false;
  }

  chartInstance->c3_c1 = c3_b_c1;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c1, 0U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  if ((*chartInstance->c3_x >= 0.0) && (*chartInstance->c3_x <= 1.0) &&
      (*chartInstance->c3_y > 1.0) && (*chartInstance->c3_y <= 2.0)) {
    c3_b_c2 = true;
  } else {
    c3_b_c2 = false;
  }

  chartInstance->c3_c2 = c3_b_c2;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c2, 1U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  if ((*chartInstance->c3_x > 1.0) && (*chartInstance->c3_x <= 2.0) &&
      (*chartInstance->c3_y > 1.0) && (*chartInstance->c3_y <= 2.0)) {
    c3_b_c3 = true;
  } else {
    c3_b_c3 = false;
  }

  chartInstance->c3_c3 = c3_b_c3;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c3, 2U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  if ((*chartInstance->c3_x > 1.0) && (*chartInstance->c3_x <= 2.0) &&
      (*chartInstance->c3_y > 2.0) && (*chartInstance->c3_y <= 3.0)) {
    c3_b_c4 = true;
  } else {
    c3_b_c4 = false;
  }

  chartInstance->c3_c4 = c3_b_c4;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c4, 3U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  if ((*chartInstance->c3_x > 2.0) && (*chartInstance->c3_x <= 3.0) &&
      (*chartInstance->c3_y > 1.0) && (*chartInstance->c3_y <= 3.0)) {
    c3_b_c5 = true;
  } else {
    c3_b_c5 = false;
  }

  chartInstance->c3_c5 = c3_b_c5;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_c5, 4U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_S1) {
   case c3_IN_A:
    CV_STATE_EVAL(2, 0, 1);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_S1:
    CV_STATE_EVAL(2, 0, 2);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_label = 2.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_label, 5U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    c3_hoistedGlobal = chartInstance->c3_label;
    c3_A = c3_hoistedGlobal * 3.1415926535897931;
    c3_b_x = c3_A;
    c3_g_x = c3_b_x;
    c3_b_y = c3_g_x / 4.0;
    c3_l_x = c3_b_y;
    *chartInstance->c3_vdx = c3_l_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdx, 8U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    c3_f_hoistedGlobal = chartInstance->c3_label;
    c3_f_A = c3_f_hoistedGlobal * 3.1415926535897931;
    c3_q_x = c3_f_A;
    c3_v_x = c3_q_x;
    c3_g_y = c3_v_x / 4.0;
    c3_bb_x = c3_g_y;
    *chartInstance->c3_vdy = c3_bb_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdy, 9U, 4U, 4U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_S2:
    CV_STATE_EVAL(2, 0, 3);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_label = 4.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_label, 5U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    c3_b_hoistedGlobal = chartInstance->c3_label;
    c3_b_A = c3_b_hoistedGlobal * 3.1415926535897931;
    c3_c_x = c3_b_A;
    c3_h_x = c3_c_x;
    c3_c_y = c3_h_x / 4.0;
    c3_m_x = c3_c_y;
    *chartInstance->c3_vdx = c3_m_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdx, 8U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    c3_g_hoistedGlobal = chartInstance->c3_label;
    c3_g_A = c3_g_hoistedGlobal * 3.1415926535897931;
    c3_r_x = c3_g_A;
    c3_w_x = c3_r_x;
    c3_h_y = c3_w_x / 4.0;
    c3_cb_x = c3_h_y;
    *chartInstance->c3_vdy = c3_cb_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdy, 9U, 4U, 5U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_S3:
    CV_STATE_EVAL(2, 0, 4);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_label = 3.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_label, 5U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    c3_c_hoistedGlobal = chartInstance->c3_label;
    c3_c_A = c3_c_hoistedGlobal * 3.1415926535897931;
    c3_d_x = c3_c_A;
    c3_i_x = c3_d_x;
    c3_d_y = c3_i_x / 4.0;
    c3_n_x = c3_d_y;
    *chartInstance->c3_vdx = c3_n_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdx, 8U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    c3_h_hoistedGlobal = chartInstance->c3_label;
    c3_h_A = c3_h_hoistedGlobal * 3.1415926535897931;
    c3_s_x = c3_h_A;
    c3_x_x = c3_s_x;
    c3_i_y = c3_x_x / 4.0;
    c3_db_x = c3_i_y;
    *chartInstance->c3_vdy = c3_db_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdy, 9U, 4U, 6U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_S4:
    CV_STATE_EVAL(2, 0, 5);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_label = 2.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_label, 5U, 4U, 7U,
                          chartInstance->c3_sfEvent, false);
    c3_d_hoistedGlobal = chartInstance->c3_label;
    c3_d_A = c3_d_hoistedGlobal * 3.1415926535897931;
    c3_e_x = c3_d_A;
    c3_j_x = c3_e_x;
    c3_e_y = c3_j_x / 4.0;
    c3_o_x = c3_e_y;
    *chartInstance->c3_vdx = c3_o_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdx, 8U, 4U, 7U,
                          chartInstance->c3_sfEvent, false);
    c3_i_hoistedGlobal = chartInstance->c3_label;
    c3_i_A = c3_i_hoistedGlobal * 3.1415926535897931;
    c3_t_x = c3_i_A;
    c3_y_x = c3_t_x;
    c3_j_y = c3_y_x / 4.0;
    c3_eb_x = c3_j_y;
    *chartInstance->c3_vdy = c3_eb_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdy, 9U, 4U, 7U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_S5:
    CV_STATE_EVAL(2, 0, 6);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_label = 4.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_label, 5U, 4U, 8U,
                          chartInstance->c3_sfEvent, false);
    c3_e_hoistedGlobal = chartInstance->c3_label;
    c3_e_A = c3_e_hoistedGlobal * 3.1415926535897931;
    c3_f_x = c3_e_A;
    c3_k_x = c3_f_x;
    c3_f_y = c3_k_x / 4.0;
    c3_p_x = c3_f_y;
    *chartInstance->c3_vdx = c3_p_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdx, 8U, 4U, 8U,
                          chartInstance->c3_sfEvent, false);
    c3_j_hoistedGlobal = chartInstance->c3_label;
    c3_j_A = c3_j_hoistedGlobal * 3.1415926535897931;
    c3_u_x = c3_j_A;
    c3_ab_x = c3_u_x;
    c3_k_y = c3_ab_x / 4.0;
    c3_fb_x = c3_k_y;
    *chartInstance->c3_vdy = c3_fb_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vdy, 9U, 4U, 8U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(2, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_S1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_S1) {
   case c3_IN_A:
    CV_STATE_EVAL(2, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_S1:
    CV_STATE_EVAL(2, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_h_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
      chartInstance->c3_c2, 1.0, -1, 0U, (int32_T)chartInstance->c3_c2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_b_tp_S1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_S1 = c3_IN_S2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_S2 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_f_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0, (real_T)
        chartInstance->c3_c3, 1.0, -1, 0U, (int32_T)chartInstance->c3_c3));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_b_tp_S1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_S1 = c3_IN_S3;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S3 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_q_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_q_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_k_out = CV_EML_IF(16, 0, 0, CV_RELATIONAL_EVAL(5U, 16U, 0,
          *chartInstance->c3_x, 2.0, -1, 4U, *chartInstance->c3_x > 2.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_k_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
          chartInstance->c3_b_tp_S1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_S1 = c3_IN_A;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_A = 1U;
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
        }
      }
    }
    break;

   case c3_IN_S2:
    CV_STATE_EVAL(2, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_k_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_b_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (real_T)
      chartInstance->c3_c1, 1.0, -1, 0U, (int32_T)chartInstance->c3_c1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_S2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_S1 = c3_IN_S1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_b_tp_S1 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_g_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)
        chartInstance->c3_c4, 1.0, -1, 0U, (int32_T)chartInstance->c3_c4));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_S1 = c3_IN_S4;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S4 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_l_out = CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0, (real_T)
          chartInstance->c3_c3, 1.0, -1, 0U, (int32_T)chartInstance->c3_c3));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_l_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_S2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_S1 = c3_IN_S3;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_S3 = 1U;
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
        }
      }
    }
    break;

   case c3_IN_S3:
    CV_STATE_EVAL(2, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_c_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, (real_T)
      chartInstance->c3_c1, 1.0, -1, 0U, (int32_T)chartInstance->c3_c1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_S3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_S1 = c3_IN_S1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_b_tp_S1 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_h_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, (real_T)
        chartInstance->c3_c5, 1.0, -1, 0U, (int32_T)chartInstance->c3_c5));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S3 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_S1 = c3_IN_S5;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S5 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_s_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_s_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_m_out = CV_EML_IF(12, 0, 0, CV_RELATIONAL_EVAL(5U, 12U, 0, (real_T)
          chartInstance->c3_c2, 1.0, -1, 0U, (int32_T)chartInstance->c3_c2));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_m_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_S3 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_S1 = c3_IN_S2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_S2 = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_n_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          c3_p_out = CV_EML_IF(14, 0, 0, CV_RELATIONAL_EVAL(5U, 14U, 0, (real_T)
            chartInstance->c3_c4, 1.0, -1, 0U, (int32_T)chartInstance->c3_c4));
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_p_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_S3 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
            chartInstance->c3_is_S1 = c3_IN_S4;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_S4 = 1U;
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
          }
        }
      }
    }
    break;

   case c3_IN_S4:
    CV_STATE_EVAL(2, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_d_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, (real_T)
      chartInstance->c3_c2, 1.0, -1, 0U, (int32_T)chartInstance->c3_c2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_S4 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_S1 = c3_IN_S2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_S2 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_i_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_i_out = CV_EML_IF(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0, (real_T)
        chartInstance->c3_c5, 1.0, -1, 0U, (int32_T)chartInstance->c3_c5));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_i_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S4 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_S1 = c3_IN_S5;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S5 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_t_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_t_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_n_out = CV_EML_IF(13, 0, 0, CV_RELATIONAL_EVAL(5U, 13U, 0, (real_T)
          chartInstance->c3_c3, 1.0, -1, 0U, (int32_T)chartInstance->c3_c3));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_n_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_S4 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_S1 = c3_IN_S3;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_S3 = 1U;
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
        }
      }
    }
    break;

   case c3_IN_S5:
    CV_STATE_EVAL(2, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_e_out = CV_EML_IF(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, (real_T)
      chartInstance->c3_c3, 1.0, -1, 0U, (int32_T)chartInstance->c3_c3));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_S5 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_S1 = c3_IN_S3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_S3 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_j_out = CV_EML_IF(10, 0, 0, CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)
        chartInstance->c3_c4, 1.0, -1, 0U, (int32_T)chartInstance->c3_c4));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_j_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S5 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_S1 = c3_IN_S4;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S4 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_v_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_u_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_u_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_o_out = CV_EML_IF(15, 0, 0, CV_RELATIONAL_EVAL(5U, 15U, 0,
          *chartInstance->c3_y, 1.0, -1, 3U, *chartInstance->c3_y <= 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_o_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_S5 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_S1 = c3_IN_A;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_A = 1U;
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
        }
      }
    }
    break;

   default:
    CV_STATE_EVAL(2, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_S1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_NavigationMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc3_Navigation(SFc3_NavigationInstanceStruct
  *chartInstance)
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

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_NavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_NavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_NavigationInstanceStruct *chartInstance,
  const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout),
    &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_b_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_NavigationInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_b_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_b_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y;
  SFc3_NavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_NavigationInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout),
    &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_NavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_NavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier)
{
  boolean_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  return c3_b_y;
}

static boolean_T c3_d_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_b_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_b_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_b_y;
  SFc3_NavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_NavigationInstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Navigation_get_eml_resolved_functions_info(void)
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
  const mxArray *c3_b_y = NULL;
  SFc3_NavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_NavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_b_y;
  int32_T c3_i1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i1, 1, 6, 0U, 0, 0U, 0);
  c3_b_y = c3_i1;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_b_y;
  SFc3_NavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_NavigationInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_NavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_NavigationInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_sys, const char_T *c3_identifier)
{
  uint8_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_sys),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_sys);
  return c3_b_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_b_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_sys;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_b_y;
  SFc3_NavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_NavigationInstanceStruct *)chartInstanceVoid;
  c3_b_tp_sys = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_sys),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_sys);
  *(uint8_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_h_emlrt_marshallIn(SFc3_NavigationInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_b_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_i_emlrt_marshallIn(SFc3_NavigationInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_b_y[2])
{
  boolean_T c3_bv1[2];
  int32_T c3_i2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 2);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    c3_b_y[c3_i2] = c3_bv1[c3_i2];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_j_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_b_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_b_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_b_y, c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_b_y;
}

static const mxArray *c3_k_emlrt_marshallIn(SFc3_NavigationInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc3_NavigationInstanceStruct
  *chartInstance, int32_T c3_ssid)
{
  const mxArray *c3_msgInfo;
  (void)chartInstance;
  (void)c3_ssid;
  c3_msgInfo = NULL;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_NavigationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void outputs_c3_Navigation(SFc3_NavigationInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_A;
  real_T c3_b_A;
  real_T c3_c_A;
  real_T c3_d_A;
  real_T c3_e_A;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_b_y;
  real_T c3_c_y;
  real_T c3_d_y;
  real_T c3_e_y;
  real_T c3_f_y;
  real_T c3_l_x;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_hoistedGlobal;
  real_T c3_i_hoistedGlobal;
  real_T c3_j_hoistedGlobal;
  real_T c3_f_A;
  real_T c3_g_A;
  real_T c3_h_A;
  real_T c3_i_A;
  real_T c3_j_A;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_w_x;
  real_T c3_x_x;
  real_T c3_y_x;
  real_T c3_ab_x;
  real_T c3_g_y;
  real_T c3_h_y;
  real_T c3_i_y;
  real_T c3_j_y;
  real_T c3_k_y;
  real_T c3_bb_x;
  real_T c3_cb_x;
  real_T c3_db_x;
  real_T c3_eb_x;
  real_T c3_fb_x;
  switch (chartInstance->c3_is_S1) {
   case c3_IN_A:
    break;

   case c3_IN_S1:
    chartInstance->c3_label = 2.0;
    c3_hoistedGlobal = chartInstance->c3_label;
    c3_A = c3_hoistedGlobal * 3.1415926535897931;
    c3_b_x = c3_A;
    c3_g_x = c3_b_x;
    c3_b_y = c3_g_x / 4.0;
    c3_l_x = c3_b_y;
    *chartInstance->c3_vdx = c3_l_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    c3_f_hoistedGlobal = chartInstance->c3_label;
    c3_f_A = c3_f_hoistedGlobal * 3.1415926535897931;
    c3_q_x = c3_f_A;
    c3_v_x = c3_q_x;
    c3_g_y = c3_v_x / 4.0;
    c3_bb_x = c3_g_y;
    *chartInstance->c3_vdy = c3_bb_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    break;

   case c3_IN_S2:
    chartInstance->c3_label = 4.0;
    c3_b_hoistedGlobal = chartInstance->c3_label;
    c3_b_A = c3_b_hoistedGlobal * 3.1415926535897931;
    c3_c_x = c3_b_A;
    c3_h_x = c3_c_x;
    c3_c_y = c3_h_x / 4.0;
    c3_m_x = c3_c_y;
    *chartInstance->c3_vdx = c3_m_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    c3_g_hoistedGlobal = chartInstance->c3_label;
    c3_g_A = c3_g_hoistedGlobal * 3.1415926535897931;
    c3_r_x = c3_g_A;
    c3_w_x = c3_r_x;
    c3_h_y = c3_w_x / 4.0;
    c3_cb_x = c3_h_y;
    *chartInstance->c3_vdy = c3_cb_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    break;

   case c3_IN_S3:
    chartInstance->c3_label = 3.0;
    c3_c_hoistedGlobal = chartInstance->c3_label;
    c3_c_A = c3_c_hoistedGlobal * 3.1415926535897931;
    c3_d_x = c3_c_A;
    c3_i_x = c3_d_x;
    c3_d_y = c3_i_x / 4.0;
    c3_n_x = c3_d_y;
    *chartInstance->c3_vdx = c3_n_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    c3_h_hoistedGlobal = chartInstance->c3_label;
    c3_h_A = c3_h_hoistedGlobal * 3.1415926535897931;
    c3_s_x = c3_h_A;
    c3_x_x = c3_s_x;
    c3_i_y = c3_x_x / 4.0;
    c3_db_x = c3_i_y;
    *chartInstance->c3_vdy = c3_db_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    break;

   case c3_IN_S4:
    chartInstance->c3_label = 2.0;
    c3_d_hoistedGlobal = chartInstance->c3_label;
    c3_d_A = c3_d_hoistedGlobal * 3.1415926535897931;
    c3_e_x = c3_d_A;
    c3_j_x = c3_e_x;
    c3_e_y = c3_j_x / 4.0;
    c3_o_x = c3_e_y;
    *chartInstance->c3_vdx = c3_o_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    c3_i_hoistedGlobal = chartInstance->c3_label;
    c3_i_A = c3_i_hoistedGlobal * 3.1415926535897931;
    c3_t_x = c3_i_A;
    c3_y_x = c3_t_x;
    c3_j_y = c3_y_x / 4.0;
    c3_eb_x = c3_j_y;
    *chartInstance->c3_vdy = c3_eb_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    break;

   case c3_IN_S5:
    chartInstance->c3_label = 4.0;
    c3_e_hoistedGlobal = chartInstance->c3_label;
    c3_e_A = c3_e_hoistedGlobal * 3.1415926535897931;
    c3_f_x = c3_e_A;
    c3_k_x = c3_f_x;
    c3_f_y = c3_k_x / 4.0;
    c3_p_x = c3_f_y;
    *chartInstance->c3_vdx = c3_p_x;
    *chartInstance->c3_vdx = muDoubleScalarSin(*chartInstance->c3_vdx);
    c3_j_hoistedGlobal = chartInstance->c3_label;
    c3_j_A = c3_j_hoistedGlobal * 3.1415926535897931;
    c3_u_x = c3_j_A;
    c3_ab_x = c3_u_x;
    c3_k_y = c3_ab_x / 4.0;
    c3_fb_x = c3_k_y;
    *chartInstance->c3_vdy = c3_fb_x;
    *chartInstance->c3_vdy = muDoubleScalarCos(*chartInstance->c3_vdy);
    break;

   default:
    /* Unreachable state, for coverage only */
    break;
  }
}

static void init_dsm_address_info(SFc3_NavigationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_NavigationInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_x = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c3_y = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c3_vdx = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_vdy = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c3_Navigation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3207053290U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2078888207U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1783301170U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3302081977U);
}

mxArray* sf_c3_Navigation_get_post_codegen_info(void);
mxArray *sf_c3_Navigation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("wvKd8inSolUQtBKkNZSXz");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_Navigation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Navigation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Navigation_jit_fallback_info(void)
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

mxArray *sf_c3_Navigation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Navigation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_Navigation(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[38],T\"vdx\",},{M[1],M[39],T\"vdy\",},{M[3],M[32],T\"c1\",},{M[3],M[33],T\"c2\",},{M[3],M[34],T\"c3\",},{M[3],M[35],T\"c4\",},{M[3],M[36],T\"c5\",},{M[3],M[37],T\"label\",},{M[8],M[0],T\"is_active_c3_Navigation\",},{M[8],M[1],T\"is_active_S1\",}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[8],M[27],T\"is_active_Conditions\",},{M[9],M[0],T\"is_c3_Navigation\",},{M[9],M[1],T\"is_S1\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Navigation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_NavigationInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_NavigationInstanceStruct *chartInstance =
      (SFc3_NavigationInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _NavigationMachineNumber_,
           3,
           9,
           18,
           0,
           10,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_NavigationMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_NavigationMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _NavigationMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"c1");
          _SFD_SET_DATA_PROPS(1,0,0,0,"c2");
          _SFD_SET_DATA_PROPS(2,0,0,0,"c3");
          _SFD_SET_DATA_PROPS(3,0,0,0,"c4");
          _SFD_SET_DATA_PROPS(4,0,0,0,"c5");
          _SFD_SET_DATA_PROPS(5,0,0,0,"label");
          _SFD_SET_DATA_PROPS(6,1,1,0,"x");
          _SFD_SET_DATA_PROPS(7,1,1,0,"y");
          _SFD_SET_DATA_PROPS(8,2,0,1,"vdx");
          _SFD_SET_DATA_PROPS(9,2,0,1,"vdy");
          _SFD_STATE_INFO(0,1,0);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(2,0,1);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,6);
          _SFD_ST_SUBSTATE_INDEX(2,0,3);
          _SFD_ST_SUBSTATE_INDEX(2,1,4);
          _SFD_ST_SUBSTATE_INDEX(2,2,5);
          _SFD_ST_SUBSTATE_INDEX(2,3,6);
          _SFD_ST_SUBSTATE_INDEX(2,4,7);
          _SFD_ST_SUBSTATE_INDEX(2,5,8);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,6,1,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(9,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(10,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(10,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(13,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(13,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(14,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(14,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(12,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(12,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(11,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(7,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(7,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,6,1,6);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,6,-1,0);
        _SFD_CV_INIT_EML(16,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,4,1,4);
        _SFD_CV_INIT_EML_RELATIONAL(16,0,0,1,4,-1,4);
        _SFD_CV_INIT_EML(15,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,5,1,5);
        _SFD_CV_INIT_EML_RELATIONAL(15,0,0,1,5,-1,3);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _NavigationMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_NavigationInstanceStruct *chartInstance =
      (SFc3_NavigationInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c3_x);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c3_y);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c3_c1);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c3_c2);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c3_c3);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)&chartInstance->c3_c4);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)&chartInstance->c3_c5);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)&chartInstance->c3_label);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c3_vdx);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c3_vdy);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "smd3PUvfnemEBYkdpnoTkCE";
}

static void sf_opaque_initialize_c3_Navigation(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_NavigationInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_Navigation((SFc3_NavigationInstanceStruct*)
    chartInstanceVar);
  initialize_c3_Navigation((SFc3_NavigationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Navigation(void *chartInstanceVar)
{
  enable_c3_Navigation((SFc3_NavigationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Navigation(void *chartInstanceVar)
{
  disable_c3_Navigation((SFc3_NavigationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_outputs_c3_Navigation(void *chartInstanceVar)
{
  outputs_c3_Navigation((SFc3_NavigationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Navigation(void *chartInstanceVar)
{
  sf_gateway_c3_Navigation((SFc3_NavigationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_Navigation(SimStruct* S)
{
  return get_sim_state_c3_Navigation((SFc3_NavigationInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Navigation(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c3_Navigation((SFc3_NavigationInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_Navigation(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_NavigationInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Navigation_optimization_info();
    }

    finalize_c3_Navigation((SFc3_NavigationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Navigation((SFc3_NavigationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Navigation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Navigation((SFc3_NavigationInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_Navigation(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 0);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Navigation_optimization_info(sim_mode_is_rtw_gen
      (S), sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
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
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1975319738U));
  ssSetChecksum1(S,(4134043251U));
  ssSetChecksum2(S,(1428420876U));
  ssSetChecksum3(S,(663310301U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Navigation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_Navigation(SimStruct *S)
{
  SFc3_NavigationInstanceStruct *chartInstance;
  chartInstance = (SFc3_NavigationInstanceStruct *)utMalloc(sizeof
    (SFc3_NavigationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_NavigationInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Navigation;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_Navigation;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Navigation;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Navigation;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Navigation;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Navigation;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Navigation;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_Navigation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c3_Navigation;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Navigation;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Navigation;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Navigation;
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
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 1);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_Navigation(chartInstance);
}

void c3_Navigation_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Navigation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Navigation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Navigation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Navigation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
