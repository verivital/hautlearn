/* Include files */

#include "bouncing_ball_sfun.h"
#include "c3_bouncing_ball.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "bouncing_ball_sfun_debug_macros.h"
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
#define c3_IN_Falling                  ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

/* Function Declarations */
static void initialize_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void initialize_params_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct *
  chartInstance);
static void enable_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void disable_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_bouncing_ball
  (SFc3_bouncing_ballInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_bouncing_ball
  (SFc3_bouncing_ballInstanceStruct *chartInstance);
static void set_sim_state_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_bouncing_ball
  (SFc3_bouncing_ballInstanceStruct *chartInstance);
static void finalize_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void sf_gateway_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void mdl_start_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void zeroCrossings_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void derivatives_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void outputs_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void initSimStructsc3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void c3_eml_ini_fcn_to_be_inlined_440(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void c3_eml_term_fcn_to_be_inlined_440(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const real_T c3_u);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const boolean_T c3_u);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier);
static boolean_T c3_d_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const int32_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_b_sfEvent, const char_T *c3_identifier);
static int32_T c3_f_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const uint8_T c3_u);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_Falling, const char_T *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static const mxArray *c3_f_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const boolean_T c3_u[4]);
static void c3_i_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u);
static void c3_j_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[4]);
static void c3_k_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[4]);
static const mxArray *c3_l_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_m_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc3_bouncing_ballInstanceStruct
  *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc3_bouncing_ballInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_bouncing_ballInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_Falling = 0U;
  chartInstance->c3_is_active_c3_bouncing_ball = 0U;
  chartInstance->c3_is_c3_bouncing_ball = c3_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_bouncing_ball
  (SFc3_bouncing_ballInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_bouncing_ball == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_bouncing_ball == c3_IN_Falling) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_bouncing_ball
  (SFc3_bouncing_ballInstanceStruct *chartInstance)
{
  const mxArray *c3_st = NULL;
  c3_st = NULL;
  sf_mex_assign(&c3_st, c3_e_emlrt_marshallOut(chartInstance), false);
  return c3_st;
}

static void set_sim_state_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_st));
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_bouncing_ball(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_bouncing_ball
  (SFc3_bouncing_ballInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_tp_Falling = (uint8_T)
      (chartInstance->c3_is_c3_bouncing_ball == c3_IN_Falling);
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  c3_set_sim_state_side_effects_c3_bouncing_ball(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0U) {
    chartInstance->c3_lastMajorTime = _sfTime_;
    chartInstance->c3_stateChanged = (boolean_T)0;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_sfEvent = CALL_EVENT;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_is_active_c3_bouncing_ball == 0U) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_active_c3_bouncing_ball = 1U;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_p = 10.0;
      chartInstance->c3_dataWrittenToVector[0U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_p, 0U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
      *chartInstance->c3_v = 15.0;
      chartInstance->c3_dataWrittenToVector[1U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v, 1U, 5U, 0U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_c3_bouncing_ball = c3_IN_Falling;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Falling = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_c_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[0U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 1U, chartInstance->c3_sfEvent,
          false);
      }

      guard1 = false;
      if (CV_EML_COND(1, 0, 0, *chartInstance->c3_p <= 0.0)) {
        if (CV_EML_COND(1, 0, 1, *chartInstance->c3_v < 0.0)) {
          CV_EML_MCDC(1, 0, 0, true);
          CV_EML_IF(1, 0, 0, true);
          c3_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 5U, 1U,
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
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_p = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_p, 0U, 5U, 1U,
                              chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_v *= -0.8;
        chartInstance->c3_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v, 1U, 5U, 1U,
                              chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 5U, 1U,
            chartInstance->c3_sfEvent, false);
        }

        sf_mex_printf("%s =\\n", "v");
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_emlrt_marshallOut(chartInstance,
          *chartInstance->c3_v));
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_tp_Falling = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_stateChanged = true;
        chartInstance->c3_is_c3_bouncing_ball = c3_IN_Falling;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_Falling = 1U;
      } else {
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      }
    }

    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  *chartInstance->c3_p_out = *chartInstance->c3_p;
  chartInstance->c3_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_p_out, 2U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  *chartInstance->c3_v_out = *chartInstance->c3_v;
  chartInstance->c3_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_out, 3U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_bouncing_ballMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void zeroCrossings_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T *c3_zcVar;
  boolean_T guard1 = false;
  c3_zcVar = (real_T *)(ssGetNonsampledZCs_wrapper(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_lastMajorTime == _sfTime_) {
    *c3_zcVar = -1.0;
  } else {
    chartInstance->c3_stateChanged = (boolean_T)0;
    if (chartInstance->c3_is_active_c3_bouncing_ball == 0U) {
      chartInstance->c3_stateChanged = true;
    } else {
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_c_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[0U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 1U, chartInstance->c3_sfEvent,
          false);
      }

      guard1 = false;
      if (CV_EML_COND(1, 0, 0, *chartInstance->c3_p <= 0.0)) {
        if (CV_EML_COND(1, 0, 1, *chartInstance->c3_v < 0.0)) {
          CV_EML_MCDC(1, 0, 0, true);
          CV_EML_IF(1, 0, 0, true);
          c3_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 5U, 1U,
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
      }
    }

    if (chartInstance->c3_stateChanged) {
      *c3_zcVar = 1.0;
    } else {
      *c3_zcVar = -1.0;
    }
  }
}

static void derivatives_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T *c3_p_dot;
  real_T *c3_v_dot;
  c3_v_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 1);
  c3_p_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 0);
  *c3_p_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_p_dot, 0U, 1U, 0U, chartInstance->c3_sfEvent, false);
  *c3_v_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_v_dot, 1U, 1U, 0U, chartInstance->c3_sfEvent, false);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  *c3_p_dot = *chartInstance->c3_v + *chartInstance->c3_p;
  _SFD_DATA_RANGE_CHECK(*c3_p_dot, 0U, 4U, 0U, chartInstance->c3_sfEvent, false);
  *c3_v_dot = -9.81;
  _SFD_DATA_RANGE_CHECK(*c3_v_dot, 1U, 4U, 0U, chartInstance->c3_sfEvent, false);
  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  chartInstance->c3_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_p_out, 2U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  chartInstance->c3_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_out, 3U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void outputs_c3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  *chartInstance->c3_p_out = *chartInstance->c3_p;
  chartInstance->c3_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_p_out, 2U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c3_sfEvent,
      false);
  }

  *chartInstance->c3_v_out = *chartInstance->c3_v;
  chartInstance->c3_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_out, 3U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_bouncing_ball(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_ini_fcn_to_be_inlined_440(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_term_fcn_to_be_inlined_440(SFc3_bouncing_ballInstanceStruct
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

static const mxArray *c3_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const real_T c3_u)
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
  SFc3_bouncing_ballInstanceStruct *chartInstance;
  chartInstance = (SFc3_bouncing_ballInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_emlrt_marshallOut(chartInstance, *(real_T
    *)c3_inData), false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
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

static real_T c3_b_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
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
  SFc3_bouncing_ballInstanceStruct *chartInstance;
  chartInstance = (SFc3_bouncing_ballInstanceStruct *)chartInstanceVoid;
  *(real_T *)c3_outData = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const boolean_T c3_u)
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
  SFc3_bouncing_ballInstanceStruct *chartInstance;
  chartInstance = (SFc3_bouncing_ballInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_b_emlrt_marshallOut(chartInstance,
    *(boolean_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
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

static boolean_T c3_d_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
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
  SFc3_bouncing_ballInstanceStruct *chartInstance;
  chartInstance = (SFc3_bouncing_ballInstanceStruct *)chartInstanceVoid;
  *(boolean_T *)c3_outData = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_bouncing_ball_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const int32_T c3_u)
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
  SFc3_bouncing_ballInstanceStruct *chartInstance;
  chartInstance = (SFc3_bouncing_ballInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_c_emlrt_marshallOut(chartInstance,
    *(int32_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
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

static int32_T c3_f_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_bouncing_ballInstanceStruct *chartInstance;
  chartInstance = (SFc3_bouncing_ballInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c3_outData = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const uint8_T c3_u)
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
  SFc3_bouncing_ballInstanceStruct *chartInstance;
  chartInstance = (SFc3_bouncing_ballInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_d_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_Falling, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_Falling),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Falling);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
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
  SFc3_bouncing_ballInstanceStruct *chartInstance;
  chartInstance = (SFc3_bouncing_ballInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c3_outData = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  const mxArray *c3_y;
  int32_T c3_i1;
  boolean_T c3_bv0[4];
  c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(7, 1), false);
  sf_mex_setcell(c3_y, 0, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_p_out));
  sf_mex_setcell(c3_y, 1, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_v_out));
  sf_mex_setcell(c3_y, 2, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_p));
  sf_mex_setcell(c3_y, 3, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_v));
  sf_mex_setcell(c3_y, 4, c3_d_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_active_c3_bouncing_ball));
  sf_mex_setcell(c3_y, 5, c3_d_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_c3_bouncing_ball));
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_bv0[c3_i1] = chartInstance->c3_dataWrittenToVector[c3_i1];
  }

  sf_mex_setcell(c3_y, 6, c3_f_emlrt_marshallOut(chartInstance, c3_bv0));
  return c3_y;
}

static const mxArray *c3_f_emlrt_marshallOut(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const boolean_T c3_u[4])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 11, 0U, 1U, 0U, 1, 4), false);
  return c3_y;
}

static void c3_i_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u)
{
  boolean_T c3_bv1[4];
  int32_T c3_i2;
  *chartInstance->c3_p_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("p_out", c3_u, 0)), "p_out");
  *chartInstance->c3_v_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("v_out", c3_u, 1)), "v_out");
  *chartInstance->c3_p = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("p", c3_u, 2)), "p");
  *chartInstance->c3_v = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("v", c3_u, 3)), "v");
  chartInstance->c3_is_active_c3_bouncing_ball = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c3_bouncing_ball", c3_u,
       4)), "is_active_c3_bouncing_ball");
  chartInstance->c3_is_c3_bouncing_ball = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c3_bouncing_ball", c3_u, 5)),
    "is_c3_bouncing_ball");
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 6)), "dataWrittenToVector", c3_bv1);
  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    chartInstance->c3_dataWrittenToVector[c3_i2] = c3_bv1[c3_i2];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
}

static void c3_j_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_k_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[4])
{
  boolean_T c3_bv2[4];
  int32_T c3_i3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv2, 1, 11, 0U, 1, 0U, 1, 4);
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_y[c3_i3] = c3_bv2[c3_i3];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_l_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
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

static const mxArray *c3_m_emlrt_marshallIn(SFc3_bouncing_ballInstanceStruct
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

static const mxArray *sf_get_hover_data_for_msg(SFc3_bouncing_ballInstanceStruct
  *chartInstance, int32_T c3_ssid)
{
  const mxArray *c3_msgInfo;
  (void)chartInstance;
  (void)c3_ssid;
  c3_msgInfo = NULL;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_bouncing_ballInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_p = (real_T *)(ssGetContStates_wrapper(chartInstance->S) + 0);
  chartInstance->c3_v = (real_T *)(ssGetContStates_wrapper(chartInstance->S) + 1);
  chartInstance->c3_p_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_v_out = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c3_bouncing_ball_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3838586847U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3338294861U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1295544672U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1506393992U);
}

mxArray* sf_c3_bouncing_ball_get_post_codegen_info(void);
mxArray *sf_c3_bouncing_ball_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("eyysAcwXoN02iMg4W9r9OG");
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_bouncing_ball_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_bouncing_ball_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_bouncing_ball_jit_fallback_info(void)
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

mxArray *sf_c3_bouncing_ball_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_bouncing_ball_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_bouncing_ball(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"p_out\",},{M[1],M[6],T\"v_out\",},{M[5],M[3],T\"p\",},{M[5],M[4],T\"v\",},{M[8],M[0],T\"is_active_c3_bouncing_ball\",},{M[9],M[0],T\"is_c3_bouncing_ball\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_bouncing_ball_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_bouncing_ballInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_bouncing_ballInstanceStruct *chartInstance =
      (SFc3_bouncing_ballInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _bouncing_ballMachineNumber_,
           3,
           1,
           2,
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
        init_script_number_translation(_bouncing_ballMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_bouncing_ballMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _bouncing_ballMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"p");
          _SFD_SET_DATA_PROPS(1,0,0,0,"v");
          _SFD_SET_DATA_PROPS(2,2,0,1,"p_out");
          _SFD_SET_DATA_PROPS(3,2,0,1,"v_out");
          _SFD_STATE_INFO(0,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,12,1,12);

        {
          static int condStart[] = { 1, 9 };

          static int condEnd[] = { 5, 12 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,12,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _bouncing_ballMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_bouncing_ballInstanceStruct *chartInstance =
      (SFc3_bouncing_ballInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c3_p);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c3_v);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c3_p_out);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c3_v_out);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s7PiRm1YAqCynSrOyUS9VuF";
}

static void sf_opaque_initialize_c3_bouncing_ball(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_bouncing_ballInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*)
    chartInstanceVar);
  initialize_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_bouncing_ball(void *chartInstanceVar)
{
  enable_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_bouncing_ball(void *chartInstanceVar)
{
  disable_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c3_bouncing_ball(void *chartInstanceVar)
{
  zeroCrossings_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_derivatives_c3_bouncing_ball(void *chartInstanceVar)
{
  derivatives_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_outputs_c3_bouncing_ball(void *chartInstanceVar)
{
  outputs_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_bouncing_ball(void *chartInstanceVar)
{
  sf_gateway_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_bouncing_ball(SimStruct* S)
{
  return get_sim_state_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_bouncing_ball(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_bouncing_ball(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_bouncing_ballInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_bouncing_ball_optimization_info();
    }

    finalize_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*)
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
  initSimStructsc3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_bouncing_ball(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_bouncing_ball((SFc3_bouncing_ballInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_bouncing_ball(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_bouncing_ball_optimization_info
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
        infoStruct,3,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3769699327U));
  ssSetChecksum1(S,(2991486697U));
  ssSetChecksum2(S,(254940054U));
  ssSetChecksum3(S,(610003959U));
  ssSetNumContStates(S,2);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_bouncing_ball(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_bouncing_ball(SimStruct *S)
{
  SFc3_bouncing_ballInstanceStruct *chartInstance;
  chartInstance = (SFc3_bouncing_ballInstanceStruct *)utMalloc(sizeof
    (SFc3_bouncing_ballInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_bouncing_ballInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_bouncing_ball;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_bouncing_ball;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_bouncing_ball;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_bouncing_ball;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_bouncing_ball;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_bouncing_ball;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_bouncing_ball;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_bouncing_ball;
  chartInstance->chartInfo.zeroCrossings =
    sf_opaque_zeroCrossings_c3_bouncing_ball;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c3_bouncing_ball;
  chartInstance->chartInfo.derivatives = sf_opaque_derivatives_c3_bouncing_ball;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_bouncing_ball;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_bouncing_ball;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_bouncing_ball;
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
  mdl_start_c3_bouncing_ball(chartInstance);
}

void c3_bouncing_ball_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_bouncing_ball(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_bouncing_ball(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_bouncing_ball(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_bouncing_ball_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
