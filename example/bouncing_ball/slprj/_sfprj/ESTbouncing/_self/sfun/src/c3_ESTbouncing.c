/* Include files */

#include "ESTbouncing_sfun.h"
#include "c3_ESTbouncing.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ESTbouncing_sfun_debug_macros.h"
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
#define c3_IN_S1                       ((uint8_T)1U)
#define c3_IN_S2                       ((uint8_T)2U)

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

static const char * c3_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance);
static void initialize_params_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance);
static void enable_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct *chartInstance);
static void disable_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_ESTbouncing
  (SFc3_ESTbouncingInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_ESTbouncing
  (SFc3_ESTbouncingInstanceStruct *chartInstance);
static void set_sim_state_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_ESTbouncing
  (SFc3_ESTbouncingInstanceStruct *chartInstance);
static void finalize_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance);
static void sf_gateway_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance);
static void mdl_start_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance);
static void initSimStructsc3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance);
static void c3_enter_atomic_S1(SFc3_ESTbouncingInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_b_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_y, const char_T *c3_identifier, real_T c3_b_y[2]);
static void c3_c_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u1, const char_T *c3_identifier, real_T c3_y[4]);
static void c3_e_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_f_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_FnM(SFc3_ESTbouncingInstanceStruct *chartInstance, real_T c3_u1[4],
                   real_T c3_u2[2], real_T c3_y[2]);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_g_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_h_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_S1, const char_T *c3_identifier);
static uint8_T c3_i_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_j_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[4]);
static void c3_k_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[4]);
static const mxArray *c3_l_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_m_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc3_ESTbouncingInstanceStruct
  *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_ESTbouncingInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc3_ESTbouncingInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_ESTbouncingInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_ESTbouncing(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_S1 = 0U;
  chartInstance->c3_tp_S2 = 0U;
  chartInstance->c3_is_active_c3_ESTbouncing = 0U;
  chartInstance->c3_is_c3_ESTbouncing = c3_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    (*chartInstance->c3_out)[0] = 10.0;
    for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_out)[c3_i0], 3U, 1U, 0U,
                            chartInstance->c3_sfEvent, false);
    }

    (*chartInstance->c3_out)[1] = 15.0;
    for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_out)[c3_i1], 3U, 1U, 0U,
                            chartInstance->c3_sfEvent, false);
    }
  }
}

static void initialize_params_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_ESTbouncing
  (SFc3_ESTbouncingInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_ESTbouncing == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ESTbouncing == c3_IN_S1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ESTbouncing == c3_IN_S2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_ESTbouncing
  (SFc3_ESTbouncingInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(7, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", *chartInstance->c3_out, 0, 0U, 1U,
    0U, 1, 2), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", chartInstance->c3_A1, 0, 0U, 1U, 0U,
    2, 2, 2), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", chartInstance->c3_Bc, 0, 0U, 1U, 0U,
    1, 2), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", chartInstance->c3_x, 0, 0U, 1U, 0U,
    1, 2), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_ESTbouncing;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_c3_ESTbouncing;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[2];
  int32_T c3_i2;
  real_T c3_dv1[4];
  int32_T c3_i3;
  real_T c3_dv2[2];
  int32_T c3_i4;
  real_T c3_dv3[2];
  int32_T c3_i5;
  boolean_T c3_bv0[4];
  int32_T c3_i6;
  c3_u = sf_mex_dup(c3_st);
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("out", c3_u, 0)),
                        "out", c3_dv0);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    (*chartInstance->c3_out)[c3_i2] = c3_dv0[c3_i2];
  }

  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("A1", c3_u, 1)),
                        "A1", c3_dv1);
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    chartInstance->c3_A1[c3_i3] = c3_dv1[c3_i3];
  }

  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("Bc", c3_u, 2)),
                        "Bc", c3_dv2);
  for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
    chartInstance->c3_Bc[c3_i4] = c3_dv2[c3_i4];
  }

  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("x", c3_u, 3)),
                        "x", c3_dv3);
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    chartInstance->c3_x[c3_i5] = c3_dv3[c3_i5];
  }

  chartInstance->c3_is_active_c3_ESTbouncing = c3_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c3_ESTbouncing", c3_u,
       4)), "is_active_c3_ESTbouncing");
  chartInstance->c3_is_c3_ESTbouncing = c3_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c3_ESTbouncing", c3_u, 5)),
    "is_c3_ESTbouncing");
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 6)), "dataWrittenToVector", c3_bv0);
  for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
    chartInstance->c3_dataWrittenToVector[c3_i6] = c3_bv0[c3_i6];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_ESTbouncing(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_ESTbouncing
  (SFc3_ESTbouncingInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_tp_S1 = (uint8_T)(chartInstance->c3_is_c3_ESTbouncing ==
      c3_IN_S1);
    chartInstance->c3_tp_S2 = (uint8_T)(chartInstance->c3_is_c3_ESTbouncing ==
      c3_IN_S2);
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargin = 0.0;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  real_T c3_c_nargout = 0.0;
  int32_T c3_i7;
  int32_T c3_i8;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  const mxArray *c3_y = NULL;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  static real_T c3_dv4[4] = { 0.0, 0.0, 0.0, -0.8 };

  int32_T c3_i12;
  real_T c3_dv5[4];
  int32_T c3_i13;
  int32_T c3_i14;
  real_T c3_dv6[4];
  real_T c3_dv7[2];
  real_T c3_dv8[2];
  int32_T c3_i15;
  real_T c3_dv9[2];
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  real_T c3_dv10[4];
  real_T c3_dv11[2];
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  c3_set_sim_state_side_effects_c3_ESTbouncing(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_ESTbouncing == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_ESTbouncing = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
      chartInstance->c3_x[c3_i7] = 10.0 + 5.0 * (real_T)c3_i7;
    }

    chartInstance->c3_dataWrittenToVector[2U] = true;
    for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i8], 2U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
    }

    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 5U, 0U, chartInstance->c3_sfEvent,
        false);
    }

    sf_mex_printf("%s =\\n", "x");
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", chartInstance->c3_x, 0, 0U, 1U, 0U,
      1, 2), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_is_c3_ESTbouncing = c3_IN_S1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_S1 = 1U;
    c3_enter_atomic_S1(chartInstance);
  } else {
    switch (chartInstance->c3_is_c3_ESTbouncing) {
     case c3_IN_S1:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_d_sf_marshallOut,
        c3_d_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[2U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 5U, 1U, chartInstance->c3_sfEvent,
          false);
      }

      c3_b_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
        chartInstance->c3_x[0], 0.0, -1, 3U, chartInstance->c3_x[0] <= 0.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ESTbouncing = c3_IN_S2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S2 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
          chartInstance->c3_A1[c3_i9] = c3_dv4[c3_i9];
        }

        chartInstance->c3_dataWrittenToVector[0U] = true;
        for (c3_i13 = 0; c3_i13 < 4; c3_i13++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_A1[c3_i13], 0U, 4U, 2U,
                                chartInstance->c3_sfEvent, false);
        }

        for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
          chartInstance->c3_Bc[c3_i15] = 0.7848 * (real_T)c3_i15;
        }

        chartInstance->c3_dataWrittenToVector[1U] = true;
        for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_Bc[c3_i18], 1U, 4U, 2U,
                                chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        for (c3_i24 = 0; c3_i24 < 4; c3_i24++) {
          c3_dv10[c3_i24] = chartInstance->c3_A1[c3_i24];
        }

        for (c3_i26 = 0; c3_i26 < 2; c3_i26++) {
          c3_dv11[c3_i26] = chartInstance->c3_x[c3_i26];
        }

        c3_FnM(chartInstance, c3_dv10, c3_dv11, c3_dv8);
        for (c3_i27 = 0; c3_i27 < 2; c3_i27++) {
          chartInstance->c3_x[c3_i27] = c3_dv8[c3_i27] + chartInstance->
            c3_Bc[c3_i27];
        }

        chartInstance->c3_dataWrittenToVector[2U] = true;
        for (c3_i28 = 0; c3_i28 < 2; c3_i28++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i28], 2U, 4U, 2U,
                                chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        for (c3_i29 = 0; c3_i29 < 2; c3_i29++) {
          (*chartInstance->c3_out)[c3_i29] = chartInstance->c3_x[c3_i29];
        }

        for (c3_i30 = 0; c3_i30 < 2; c3_i30++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_out)[c3_i30], 3U, 4U, 2U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        for (c3_i10 = 0; c3_i10 < 4; c3_i10++) {
          c3_dv5[c3_i10] = chartInstance->c3_A1[c3_i10];
        }

        for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
          c3_dv7[c3_i12] = chartInstance->c3_x[c3_i12];
        }

        c3_FnM(chartInstance, c3_dv5, c3_dv7, c3_dv8);
        for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
          chartInstance->c3_x[c3_i16] = c3_dv8[c3_i16] + chartInstance->
            c3_Bc[c3_i16];
        }

        chartInstance->c3_dataWrittenToVector[2U] = true;
        for (c3_i19 = 0; c3_i19 < 2; c3_i19++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i19], 2U, 4U, 1U,
                                chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
          (*chartInstance->c3_out)[c3_i21] = chartInstance->c3_x[c3_i21];
        }

        for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_out)[c3_i23], 3U, 4U, 1U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_S2:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_h_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_d_sf_marshallOut,
        c3_d_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[2U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 5U, 2U, chartInstance->c3_sfEvent,
          false);
      }

      c3_c_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0,
        chartInstance->c3_x[0], 0.0, -1, 3U, chartInstance->c3_x[0] <= 0.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ESTbouncing = c3_IN_S1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_S1 = 1U;
        c3_enter_atomic_S1(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        for (c3_i11 = 0; c3_i11 < 4; c3_i11++) {
          c3_dv6[c3_i11] = chartInstance->c3_A1[c3_i11];
        }

        for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
          c3_dv9[c3_i14] = chartInstance->c3_x[c3_i14];
        }

        c3_FnM(chartInstance, c3_dv6, c3_dv9, c3_dv8);
        for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
          chartInstance->c3_x[c3_i17] = c3_dv8[c3_i17] + chartInstance->
            c3_Bc[c3_i17];
        }

        chartInstance->c3_dataWrittenToVector[2U] = true;
        for (c3_i20 = 0; c3_i20 < 2; c3_i20++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i20], 2U, 4U, 2U,
                                chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U,
            chartInstance->c3_sfEvent, false);
        }

        for (c3_i22 = 0; c3_i22 < 2; c3_i22++) {
          (*chartInstance->c3_out)[c3_i22] = chartInstance->c3_x[c3_i22];
        }

        for (c3_i25 = 0; c3_i25 < 2; c3_i25++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_out)[c3_i25], 3U, 4U, 2U,
                                chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c3_is_c3_ESTbouncing = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ESTbouncingMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc3_ESTbouncing(SFc3_ESTbouncingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_enter_atomic_S1(SFc3_ESTbouncingInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i31;
  static real_T c3_dv12[4] = { 1.0, 0.0, 0.1, 1.0 };

  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  real_T c3_dv13[4];
  real_T c3_dv14[2];
  real_T c3_dv15[2];
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  for (c3_i31 = 0; c3_i31 < 4; c3_i31++) {
    chartInstance->c3_A1[c3_i31] = c3_dv12[c3_i31];
  }

  chartInstance->c3_dataWrittenToVector[0U] = true;
  for (c3_i32 = 0; c3_i32 < 4; c3_i32++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_A1[c3_i32], 0U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
  }

  for (c3_i33 = 0; c3_i33 < 2; c3_i33++) {
    chartInstance->c3_Bc[c3_i33] = -0.049 + -0.93199999999999994 * (real_T)
      c3_i33;
  }

  chartInstance->c3_dataWrittenToVector[1U] = true;
  for (c3_i34 = 0; c3_i34 < 2; c3_i34++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Bc[c3_i34], 1U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
  }

  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 1U, chartInstance->c3_sfEvent,
      false);
  }

  if (!chartInstance->c3_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 1U, chartInstance->c3_sfEvent,
      false);
  }

  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 1U, chartInstance->c3_sfEvent,
      false);
  }

  for (c3_i35 = 0; c3_i35 < 4; c3_i35++) {
    c3_dv13[c3_i35] = chartInstance->c3_A1[c3_i35];
  }

  for (c3_i36 = 0; c3_i36 < 2; c3_i36++) {
    c3_dv14[c3_i36] = chartInstance->c3_x[c3_i36];
  }

  c3_FnM(chartInstance, c3_dv13, c3_dv14, c3_dv15);
  for (c3_i37 = 0; c3_i37 < 2; c3_i37++) {
    chartInstance->c3_x[c3_i37] = c3_dv15[c3_i37] + chartInstance->c3_Bc[c3_i37];
  }

  chartInstance->c3_dataWrittenToVector[2U] = true;
  for (c3_i38 = 0; c3_i38 < 2; c3_i38++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_x[c3_i38], 2U, 4U, 1U,
                          chartInstance->c3_sfEvent, false);
  }

  if (!chartInstance->c3_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 1U, chartInstance->c3_sfEvent,
      false);
  }

  for (c3_i39 = 0; c3_i39 < 2; c3_i39++) {
    (*chartInstance->c3_out)[c3_i39] = chartInstance->c3_x[c3_i39];
  }

  for (c3_i40 = 0; c3_i40 < 2; c3_i40++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_out)[c3_i40], 3U, 4U, 1U,
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
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
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
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
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
  int32_T c3_i41;
  const mxArray *c3_y = NULL;
  real_T c3_u[2];
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i41 = 0; c3_i41 < 2; c3_i41++) {
    c3_u[c3_i41] = (*(real_T (*)[2])c3_inData)[c3_i41];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_b_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_y, const char_T *c3_identifier, real_T c3_b_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_y), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_y);
}

static void c3_c_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2])
{
  real_T c3_dv16[2];
  int32_T c3_i42;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv16, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i42 = 0; c3_i42 < 2; c3_i42++) {
    c3_y[c3_i42] = c3_dv16[c3_i42];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[2];
  int32_T c3_i43;
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
  c3_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_y), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_y);
  for (c3_i43 = 0; c3_i43 < 2; c3_i43++) {
    (*(real_T (*)[2])c3_outData)[c3_i43] = c3_b_y[c3_i43];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i44;
  int32_T c3_i45;
  const mxArray *c3_y = NULL;
  int32_T c3_i46;
  real_T c3_u[4];
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_i44 = 0;
  for (c3_i45 = 0; c3_i45 < 2; c3_i45++) {
    for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
      c3_u[c3_i46 + c3_i44] = (*(real_T (*)[4])c3_inData)[c3_i46 + c3_i44];
    }

    c3_i44 += 2;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u1, const char_T *c3_identifier, real_T c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_u1), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_u1);
}

static void c3_e_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4])
{
  real_T c3_dv17[4];
  int32_T c3_i47;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv17, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c3_i47 = 0; c3_i47 < 4; c3_i47++) {
    c3_y[c3_i47] = c3_dv17[c3_i47];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_u1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[4];
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
  c3_u1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_u1), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_u1);
  c3_i48 = 0;
  for (c3_i49 = 0; c3_i49 < 2; c3_i49++) {
    for (c3_i50 = 0; c3_i50 < 2; c3_i50++) {
      (*(real_T (*)[4])c3_outData)[c3_i50 + c3_i48] = c3_y[c3_i50 + c3_i48];
    }

    c3_i48 += 2;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_f_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
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
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
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

const mxArray *sf_c3_ESTbouncing_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_FnM(SFc3_ESTbouncingInstanceStruct *chartInstance, real_T c3_u1[4],
                   real_T c3_u2[2], real_T c3_y[2])
{
  uint32_T c3_debug_family_var_map[5];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i51;
  int32_T c3_i52;
  real_T c3_a[4];
  int32_T c3_i53;
  real_T c3_b[2];
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
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
  for (c3_i51 = 0; c3_i51 < 4; c3_i51++) {
    c3_a[c3_i51] = c3_u1[c3_i51];
  }

  for (c3_i52 = 0; c3_i52 < 2; c3_i52++) {
    c3_b[c3_i52] = c3_u2[c3_i52];
  }

  for (c3_i53 = 0; c3_i53 < 2; c3_i53++) {
    c3_y[c3_i53] = 0.0;
  }

  for (c3_i54 = 0; c3_i54 < 2; c3_i54++) {
    c3_y[c3_i54] = 0.0;
    c3_i55 = 0;
    for (c3_i56 = 0; c3_i56 < 2; c3_i56++) {
      c3_y[c3_i54] += c3_a[c3_i55 + c3_i54] * c3_b[c3_i56];
      c3_i55 += 2;
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
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_g_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i57;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i57, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i57;
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
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
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
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_S1, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_S1), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_S1);
  return c3_y;
}

static uint8_T c3_i_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
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
  const mxArray *c3_b_tp_S1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)chartInstanceVoid;
  c3_b_tp_S1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_S1), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_S1);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_j_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_k_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[4])
{
  boolean_T c3_bv1[4];
  int32_T c3_i58;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 4);
  for (c3_i58 = 0; c3_i58 < 4; c3_i58++) {
    c3_y[c3_i58] = c3_bv1[c3_i58];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_l_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_m_emlrt_marshallIn(SFc3_ESTbouncingInstanceStruct
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

static const mxArray *sf_get_hover_data_for_msg(SFc3_ESTbouncingInstanceStruct
  *chartInstance, int32_T c3_ssid)
{
  const mxArray *c3_msgInfo;
  (void)chartInstance;
  (void)c3_ssid;
  c3_msgInfo = NULL;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_ESTbouncingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc3_ESTbouncingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_ESTbouncingInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_out = (real_T (*)[2])ssGetOutputPortSignal_wrapper
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

void sf_c3_ESTbouncing_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3459621812U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4249449138U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3411815306U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(714930808U);
}

mxArray* sf_c3_ESTbouncing_get_post_codegen_info(void);
mxArray *sf_c3_ESTbouncing_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BqZMnXJAIdNFLAeJUrzf4F");
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
      pr[0] = (double)(2);
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_ESTbouncing_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_ESTbouncing_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_ESTbouncing_jit_fallback_info(void)
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

mxArray *sf_c3_ESTbouncing_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_ESTbouncing_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_ESTbouncing(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[10],T\"out\",},{M[3],M[11],T\"A1\",},{M[3],M[12],T\"Bc\",},{M[3],M[13],T\"x\",},{M[8],M[0],T\"is_active_c3_ESTbouncing\",},{M[9],M[0],T\"is_c3_ESTbouncing\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ESTbouncing_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_ESTbouncingInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ESTbouncingInstanceStruct *chartInstance =
      (SFc3_ESTbouncingInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ESTbouncingMachineNumber_,
           3,
           3,
           3,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_ESTbouncingMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ESTbouncingMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ESTbouncingMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"A1");
          _SFD_SET_DATA_PROPS(1,0,0,0,"Bc");
          _SFD_SET_DATA_PROPS(2,0,0,0,"x");
          _SFD_SET_DATA_PROPS(3,2,0,1,"out");
          _SFD_SET_DATA_PROPS(4,8,0,0,"");
          _SFD_SET_DATA_PROPS(5,8,0,0,"");
          _SFD_SET_DATA_PROPS(6,9,0,0,"");
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_CH_SUBSTATE_INDEX(1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"FnM",0,-1,36);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,8,-1,3);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,8,-1,3);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ESTbouncingMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ESTbouncingInstanceStruct *chartInstance =
      (SFc3_ESTbouncingInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c3_out);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c3_A1);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c3_Bc);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c3_x);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sHQMwcdXQbIOSViTsOc4bb";
}

static void sf_opaque_initialize_c3_ESTbouncing(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ESTbouncingInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_ESTbouncing((SFc3_ESTbouncingInstanceStruct*)
    chartInstanceVar);
  initialize_c3_ESTbouncing((SFc3_ESTbouncingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_ESTbouncing(void *chartInstanceVar)
{
  enable_c3_ESTbouncing((SFc3_ESTbouncingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_ESTbouncing(void *chartInstanceVar)
{
  disable_c3_ESTbouncing((SFc3_ESTbouncingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_ESTbouncing(void *chartInstanceVar)
{
  sf_gateway_c3_ESTbouncing((SFc3_ESTbouncingInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_ESTbouncing(SimStruct* S)
{
  return get_sim_state_c3_ESTbouncing((SFc3_ESTbouncingInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_ESTbouncing(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c3_ESTbouncing((SFc3_ESTbouncingInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_ESTbouncing(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ESTbouncingInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ESTbouncing_optimization_info();
    }

    finalize_c3_ESTbouncing((SFc3_ESTbouncingInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_ESTbouncing((SFc3_ESTbouncingInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ESTbouncing(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_ESTbouncing((SFc3_ESTbouncingInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_ESTbouncing(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ESTbouncing_optimization_info(sim_mode_is_rtw_gen
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
  ssSetChecksum0(S,(699103137U));
  ssSetChecksum1(S,(3561269538U));
  ssSetChecksum2(S,(1688561917U));
  ssSetChecksum3(S,(2144501818U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_ESTbouncing(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_ESTbouncing(SimStruct *S)
{
  SFc3_ESTbouncingInstanceStruct *chartInstance;
  chartInstance = (SFc3_ESTbouncingInstanceStruct *)utMalloc(sizeof
    (SFc3_ESTbouncingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_ESTbouncingInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_ESTbouncing;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_ESTbouncing;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_ESTbouncing;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_ESTbouncing;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_ESTbouncing;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_ESTbouncing;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_ESTbouncing;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_ESTbouncing;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ESTbouncing;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ESTbouncing;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_ESTbouncing;
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
  mdl_start_c3_ESTbouncing(chartInstance);
}

void c3_ESTbouncing_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ESTbouncing(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ESTbouncing(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ESTbouncing(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ESTbouncing_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
