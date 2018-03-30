/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

#ifdef CODEGEN_PREFIX
  #define NAMESPACE_CONCAT(NS, ID) _NAMESPACE_CONCAT(NS, ID)
  #define _NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else /* CODEGEN_PREFIX */
  #define CASADI_PREFIX(ID) expl_ode_jac_u_ ## ID
#endif /* CODEGEN_PREFIX */

#include <math.h>

#ifndef real_t
#define real_t double
#endif /* real_t */

#define to_double(x) (double) x
#define to_int(x) (int) x
#define CASADI_CAST(x,y) (x) y
/* Pre-c99 compatibility */
#if __STDC_VERSION__ < 199901L
real_t CASADI_PREFIX(fmin)(real_t x, real_t y) { return x<y ? x : y;}
#define fmin(x,y) CASADI_PREFIX(fmin)(x,y)
real_t CASADI_PREFIX(fmax)(real_t x, real_t y) { return x>y ? x : y;}
#define fmax(x,y) CASADI_PREFIX(fmax)(x,y)
#endif

#define PRINTF printf
#ifndef CASADI_SYMBOL_EXPORT
#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#if defined(STATIC_LINKED)
#define CASADI_SYMBOL_EXPORT
#else /* defined(STATIC_LINKED) */
#define CASADI_SYMBOL_EXPORT __declspec(dllexport)
#endif /* defined(STATIC_LINKED) */
#elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
#else /* defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__) */
#define CASADI_SYMBOL_EXPORT
#endif /* defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__) */
#endif /* CASADI_SYMBOL_EXPORT */
real_t CASADI_PREFIX(sq)(real_t x) { return x*x;}
#define sq(x) CASADI_PREFIX(sq)(x)

real_t CASADI_PREFIX(sign)(real_t x) { return x<0 ? -1 : x>0 ? 1 : x;}
#define sign(x) CASADI_PREFIX(sign)(x)

void CASADI_PREFIX(fill)(real_t* x, int n, real_t alpha) {
  int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = alpha;
  }
}
#define fill(x, n, alpha) CASADI_PREFIX(fill)(x, n, alpha)

void CASADI_PREFIX(trans)(const real_t* x, const int* sp_x, real_t* y, const int* sp_y, int* tmp) {
  int ncol_x = sp_x[1];
  int nnz_x = sp_x[2 + ncol_x];
  const int* row_x = sp_x + 2 + ncol_x+1;
  int ncol_y = sp_y[1];
  const int* colind_y = sp_y+2;
  int k;
  for (k=0; k<ncol_y; ++k) tmp[k] = colind_y[k];
  for (k=0; k<nnz_x; ++k) {
    y[tmp[row_x[k]]++] = x[k];
  }
}
#define trans(x, sp_x, y, sp_y, tmp) CASADI_PREFIX(trans)(x, sp_x, y, sp_y, tmp)

void CASADI_PREFIX(copy)(const real_t* x, int n, real_t* y) {
  int i;
  if (y) {
    if (x) {
      for (i=0; i<n; ++i) *y++ = *x++;
    } else {
      for (i=0; i<n; ++i) *y++ = 0.;
    }
  }
}
#define copy(x, n, y) CASADI_PREFIX(copy)(x, n, y)

static const int CASADI_PREFIX(s0)[7] = {6, 2, 0, 1, 2, 4, 5};
#define s0 CASADI_PREFIX(s0)
static const int CASADI_PREFIX(s1)[11] = {2, 6, 0, 0, 0, 0, 0, 1, 2, 0, 1};
#define s1 CASADI_PREFIX(s1)
static const int CASADI_PREFIX(s2)[10] = {6, 1, 0, 6, 0, 1, 2, 3, 4, 5};
#define s2 CASADI_PREFIX(s2)
static const int CASADI_PREFIX(s3)[6] = {2, 1, 0, 2, 0, 1};
#define s3 CASADI_PREFIX(s3)
static const int CASADI_PREFIX(s4)[5] = {1, 1, 0, 1, 0};
#define s4 CASADI_PREFIX(s4)
/* casadi_expl_ode_jac_u */
CASADI_SYMBOL_EXPORT int casadi_expl_ode_jac_u(const real_t** arg, real_t** res, int* iw, real_t* w, int mem) {
  real_t *rr, *ss;
  real_t w4, w5, *w6=w+2, *w7=w+4;
  /* #0: @0 = 00 */
  /* #1: @1 = 00 */
  /* #2: @2 = 00 */
  /* #3: @3 = 00 */
  /* #4: @4 = 2.5 */
  w4 = 2.5000000000000000e+00;
  /* #5: @5 = 50 */
  w5 = 50.;
  /* #6: @6 = vertcat(@0, @1, @2, @3, @4, @5) */
  rr=w6;
  *rr++ = w4;
  *rr++ = w5;
  /* #7: @7 = @6[:2] */
  for (rr=w7, ss=w6+0; ss!=w6+2; ss+=1) *rr++ = *ss;
  /* #8: @6 = zeros(2x6,2nz) */
  fill(w6, 2, 0.);
  /* #9: (@6[:2] = @7) */
  for (rr=w6+0, ss=w7; rr!=w6+2; rr+=1) *rr = *ss++;
  /* #10: @7 = @6' */
  trans(w6, s1, w7, s0, iw);
  /* #11: output[0][0] = @7 */
  copy(w7, 2, res[0]);
  return 0;
}

CASADI_SYMBOL_EXPORT void casadi_expl_ode_jac_u_incref(void) {
}

CASADI_SYMBOL_EXPORT void casadi_expl_ode_jac_u_decref(void) {
}

CASADI_SYMBOL_EXPORT int casadi_expl_ode_jac_u_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT int casadi_expl_ode_jac_u_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT const char* casadi_expl_ode_jac_u_name_in(int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* casadi_expl_ode_jac_u_name_out(int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const int* casadi_expl_ode_jac_u_sparsity_in(int i) {
  switch (i) {
    case 0: return s2;
    case 1: return s3;
    case 2: return s4;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const int* casadi_expl_ode_jac_u_sparsity_out(int i) {
  switch (i) {
    case 0: return s0;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int casadi_expl_ode_jac_u_work(int *sz_arg, int* sz_res, int *sz_iw, int *sz_w) {
  if (sz_arg) *sz_arg = 9;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 3;
  if (sz_w) *sz_w = 6;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
