// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// bobyqa_rosen_x1
void bobyqa_rosen_x1();
RcppExport SEXP _rminqa_bobyqa_rosen_x1() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    bobyqa_rosen_x1();
    return R_NilValue;
END_RCPP
}
// bobyqa_rosen_x1e
void bobyqa_rosen_x1e();
RcppExport SEXP _rminqa_bobyqa_rosen_x1e() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    bobyqa_rosen_x1e();
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_rminqa_bobyqa_rosen_x1", (DL_FUNC) &_rminqa_bobyqa_rosen_x1, 0},
    {"_rminqa_bobyqa_rosen_x1e", (DL_FUNC) &_rminqa_bobyqa_rosen_x1e, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_rminqa(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
