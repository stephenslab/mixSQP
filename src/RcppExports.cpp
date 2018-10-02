// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// mixSQP_rcpp
List mixSQP_rcpp(const arma::mat& L, const arma::vec& w, const arma::vec& x0, double convtolsqp, double zerothreshold, double eps, int maxitersqp, int maxiteractiveset, bool verbose);
RcppExport SEXP _mixSQP_mixSQP_rcpp(SEXP LSEXP, SEXP wSEXP, SEXP x0SEXP, SEXP convtolsqpSEXP, SEXP zerothresholdSEXP, SEXP epsSEXP, SEXP maxitersqpSEXP, SEXP maxiteractivesetSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type L(LSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type w(wSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type x0(x0SEXP);
    Rcpp::traits::input_parameter< double >::type convtolsqp(convtolsqpSEXP);
    Rcpp::traits::input_parameter< double >::type zerothreshold(zerothresholdSEXP);
    Rcpp::traits::input_parameter< double >::type eps(epsSEXP);
    Rcpp::traits::input_parameter< int >::type maxitersqp(maxitersqpSEXP);
    Rcpp::traits::input_parameter< int >::type maxiteractiveset(maxiteractivesetSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(mixSQP_rcpp(L, w, x0, convtolsqp, zerothreshold, eps, maxitersqp, maxiteractiveset, verbose));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_mixSQP_mixSQP_rcpp", (DL_FUNC) &_mixSQP_mixSQP_rcpp, 9},
    {NULL, NULL, 0}
};

RcppExport void R_init_mixSQP(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
